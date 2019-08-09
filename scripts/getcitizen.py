import urllib2
import json
import time

API_PATH = 'https://citizen.com/api/incident/trending?lowerLatitude=%s&lowerLongitude=%s&upperLatitude=%s&upperLongitude=%s&fullResponse=true&limit=10'

cache = { 'incidents': {} }

SECS_IN_1HR = 60 * 60 * 60

timenow = time.time()

with open('../data/_citizen_cache.json', 'r+') as fl:
    d = fl.read()
    print fl
    if d:
        cache = json.loads(d)

# exit()

def has_cached_incident(incidentId):
    # print incidentId,cache['incidents'] 
    if incidentId in cache['incidents']:
        return True
    else:
        return False

def write_cache():
    buf = cache
    # print 'cache',buf
    for incident_id in cache['incidents']:
        incident_time = cache['incidents'][incident_id]
        if incident_time > (timenow + SECS_IN_1HR):
            del buf[incident_id]

    with open('../data/_citizen_cache.json', 'w+') as f:
        f.write(json.dumps(buf))

new_events = []

def fetch_new_local(lowlat, lowlng, uplat, uplng):
    url = API_PATH % (lowlat, lowlng, uplat, uplng)

    response = urllib2.urlopen(url)
    data = json.load(response)

    for result in data['results']:
        incident_id = result['key']
        itime = round(result['cs'] / 1000)
        if (timenow - itime) > (SECS_IN_1HR / 2):
            continue
        if has_cached_incident(incident_id):
            # print 'Hash cached, ignoring'
            continue
        
        precinct = result['police']
        precinct = precinct.replace('NYPD', '') + ' PCT'

        new_events.append({
            'id': incident_id,
            'time': int(itime),
            'title': result['title'],
            'precinct': precinct,
            'location': result['location']
        })
        cache['incidents'][incident_id] = itime

def write_local():
    s = []
    for ne in new_events:
        s.append(str(ne['time']))
        s.append(ne['title'])
        s.append(ne['precinct'])
        s.append(ne['location'])

    print 'writing',s

    with open('../data/nearby_incidents.txt', 'w+') as f:
        f.write('\n'.join(s) + '\n')
    pass

fetch_new_local("40.8207", "-73.8760", "40.8454", "-73.8494")
write_local()
write_cache()