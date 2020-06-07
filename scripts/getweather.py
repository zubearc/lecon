import json
import urllib2
import time
import xmltodict

writebf = ''

def write(filename, txt):
    with open(filename, 'w') as f:
        f.write(txt)
    pass

def grab1():
    u = "https://stationdata.wunderground.com/cgi-bin/stationdata?maxlat=40.885096842604604&maxlon=-73.82881164550781&minlat=40.81497849824719&minlon=-73.91120910644531&maxstations=3&format=json"

    response = urllib2.urlopen(u)
    data = json.load(response)
    for e in data['conds']:
        x = data['conds'][e]
        if 'tempf' not in x:
            continue
        else:
            return x


def grab2():
    u = "https://www.nbcnewyork.com/i/dispatcher/?h=weather_home_widget&zipCode=10472&moduleType=JSON"

    response = urllib2.urlopen(u)
    data = json.load(response)   
    return data[0]

def grab3():
    u = 'https://wsidata.weather.com/200904-01/369362872/Weather/Report/10472?filter=1,3,4,9&format=JSON&moduleType=JSON&json'

    response = urllib2.urlopen(u)

    j = xmltodict.parse(response)

    f = j['Cities']['City']

    m = {
        'currentTemp': f['CurrentObservation']['@TempF'],
        'todaysConditions': f['CurrentObservation']['@Weather'],
        'hours': []
    }

    for hourly in f['HourlyForecast']['Hour']:
        temp = hourly['@TempF']
        tm = hourly['@ValidDateLocal']
        s = tm.split(' ')
        _hour = s[1].split(':')
        hour = _hour[0] + s[2]

        m['hours'].append({ 'temp': temp, 'time': hour })

    m['hours'] = m['hours'][:6]

    # print json.dumps(m)

    # print json.dumps(j)

    return m

# write('../data/weather.txt', "0\n?\nWeather Error")

# fw2 = grab3()


# cw = grab1()

# fw = grab2()
fw = grab3()

# print cw
# curr_temp = cw['tempf']
curr_temp = fw['currentTemp']

curr_conditions = fw['todaysConditions'].strip().upper().replace('SCATTERED', 'SCATTER')

# print cw
print fw
print "It's %sF right now, w/ %s." % (curr_temp, curr_conditions)

writebf += '%d\n' %int(time.time())
writebf += curr_temp + '`F\n'
writebf += curr_conditions + '\n'

for hour in fw['hours']:
    print hour['temp'] + 'F', 'at', hour['time']
    writebf += hour['temp'] + '` ' + hour['time'] + '\n'

print writebf
write('../data/weather.txt', writebf)