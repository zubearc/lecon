import json
import urllib2
import time

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

cw = grab1()

fw = grab2()

curr_temp = cw['tempf']

curr_conditions = fw['todaysConditions'].strip().upper()

print cw
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