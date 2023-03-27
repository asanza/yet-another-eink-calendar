#!/usr/bin/env python

import requests
import datetime

url="http://api.openweathermap.org/data/2.5/{type}?q={location}&appid={apikey}&units=metric"

url = url.replace('{location}', "Mannheim,DE")
url = url.replace('{apikey}','a61e7d34591d8be524721f97def4fb41')
# url = url.replace('{type}', 'forecast')
url = url.replace('{type}', 'weather')

#url = "https://api.open-meteo.com/v1/forecast?latitude=49.4883&longitude=8.4647&timeformat=unixtime&current_weather=true"
url = "https://api.open-meteo.com/v1/forecast?latitude=49.4883&longitude=8.4647&timeformat=unixtime&current_weather=true&hourly=temperature_2m,weathercode,precipitation_probability,is_day&forecast_days=1"
url = "https://api.open-meteo.com/v1/dwd-icon?latitude=48.78&longitude=9.18&hourly=temperature_2m&current_weather=true"

r = requests.api.get(url)
print(r.json())

# print(r.json()['coord'])
# print(r.json()['main'])
# print(r.json()['main']['temp'])

# Convert UNIX time to datetime object
# for i in r.json()['list']:
#     dt_object = datetime.datetime.fromtimestamp(i['dt'])

#     # Convert datetime object to human-readable format
#     human_readable_time = dt_object.strftime('%Y-%m-%d %H:%M:%S')

#     print(human_readable_time)
