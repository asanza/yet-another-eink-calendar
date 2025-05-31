#!/usr/bin/env python

import requests
import datetime
import json
from pprint import pprint

def chunks(s, n):
    """Produce `n`-character chunks from `s`."""
    for start in range(0, len(s), n):
        yield s[start:start+n]

url  = "https://api.open-meteo.com/v1/forecast?latitude=49.4883&longitude=8.4647&timeformat=unixtime&current_weather=true&hourly=temperature_2m,weathercode,precipitation_probability,is_day&forecast_days=1"
url  = "https://api.open-meteo.com/v1/dwd-icon?"
url += "latitude=48.78&longitude=9.18"
url += "&daily=sunrise,sunset,weathercode&timezone=Europe/Berlin"
url += "&hourly=temperature_2m,precipitation,weathercode"
url += "&current_weather=true&timeformat=unixtime"
url += "&start_date=2025-05-30&end_date=2025-05-31"

url = "https://api.open-meteo.com"
url += "/v1/dwd-icon?latitude=48.78"
url += "&longitude=9.18"
url += "&hourly=temperature_2m,precipitation,weathercode"
url += "&daily=sunrise,sunset,weathercode&timezone=Europe/Berlin"
url += "&current_weather=true"
url += "&timeformat=unixtime"
url += "&start_date=2025-05-30"
url += "&end_date=2025-05-31"

r = requests.api.get(url)
# st = json.dumps(r.json()).replace('"', '\\"')

pprint(r.json())

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
