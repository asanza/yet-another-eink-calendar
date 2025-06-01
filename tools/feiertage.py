#!/usr/bin/env python

import requests
from pprint import pprint

url = "https://feiertage-api.de/api/?jahr=2025&nur_land=BW"
r = requests.api.get(url)
print(r.json()['Allerheiligen'])
bw = list(r.json().keys())

url = "https://feiertage-api.de/api/?jahr=2025&nur_land=HE"
r = requests.api.get(url)
he = list(r.json().keys())

url = "https://feiertage-api.de/api/?jahr=2025&nur_land=RP"
r = requests.api.get(url)
rp = list(r.json().keys())

url = "https://feiertage-api.de/api/?jahr=2025&nur_land=BY"
r = requests.api.get(url)
by = list(r.json().keys())

print(list(set(bw) - set(he)))
print(list(set(bw) - set(rp)))
print(list(set(bw) - set(by)))


# st = json.dumps(r.json()).replace('"', '\\"')

# pprint(r.json())


# for i in chunks(st, 70):
#     print('"' + i + '"')

# print(r.json()['coord'])
# print(r.json()['main'])
# print(r.json()['main']['temp'])

# Convert UNIX time to datetime object
# for i in r.json()['list']:
#     dt_object = datetime.datetime.fromtimestamp(i['dt'])

#     # Convert datetime object to human-readable format
#     human_readable_time = dt_object.strftime('%Y-%m-%d %H:%M:%S')

#     print(human_readable_time)
