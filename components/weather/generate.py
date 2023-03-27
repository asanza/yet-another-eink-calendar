#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Copyright (c) 2023 Diego Asanza <f.asanza@gmail.com>
#
# SPDX-License-Identifier: Apache-2.0
#

from PIL import Image, ImageOps
from numpy import packbits
import argparse
from pathlib import Path
import os

def chunks(l, n):
    # looping till length l
    for i in range(0, len(l), n):
        yield l[i:i + n]

wmo_weatercode_map = {
    "0" : ["clear","Clear Sky"],
    "1" : ["partlycloudy","Mainly Clear"],
    "2" : ["partlysunny","Partly Cloudy"],
    "3" : ["cloudy","Overcast"],
    "45": ["fog","Fog"],
    "48": ["fog","Fog"],
    "51": ["chancerain","Light Drizzle"],
    "53": ["rain","Drizzle"],
    "55": ["rain","Drizzle"],
    "56": ["sleet","Freezing Drizzle"],
    "57": ["sleet","Freezing Drizzle"],
    "61": ["chancerain","Slight Rain"],
    "63": ["rain","Rain"],
    "65": ["rain","Rain"],
    "66": ["chancerain","Light Rain"],
    "67": ["rain","Rain"],
    "71": ["chancesnow","Slight Snow"],
    "73": ["snow","Snow"],
    "75": ["snow","Snow"],
    "77": ["snow","Snow"],
    "80": ["chancerain","Slight Rain"],
    "81": ["rain","Rain"],
    "82": ["rain","Rain"],
    "85": ["chancesnow","Slight Snow"],
    "86": ["snow","Snow"],
    "99": ["tstorms","Thunderstorm"],
    "95": ["tstorms","Thunderstorm"],
    "96": ["tstorms","Thunderstorm"],
}


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--threshold", default=200, type=int)
    parser.add_argument("indir")
    parser.add_argument("outdir")
    args = parser.parse_args()

    icon_filenames = []
    icon_filepaths = []

    for root, dirs, files in os.walk(args.indir):
        for i in files:
            with Image.open(os.path.join(root, i), formats=['png']) as im:
                outfile = Path(i).stem
                outfile = outfile + '_' + Path(root).stem
                name = outfile.replace('-', '_')
                outfile = os.path.join(args.outdir, Path(root).stem, outfile + '.c')

                if(im.mode != 'L'):
                    r, g, b, a = im.split()
                    im = a.convert('L')
                    im = ImageOps.invert(im)
                im = im.point( lambda p: 255 if p > args.threshold else 0 )
                im = im.convert('1')
                
                data = packbits(im.getdata())
                width = im.width
                height = im.height
                
                with open(outfile, 'w') as f:
                    f.write('#include "weather.h"\n')
                    f.write("#define {}_WIDTH {} \n".format(name.upper(), width))
                    f.write("#define {}_HEIGHT {} \n".format(name.upper(), height))
                    f.write("const struct icon icon_{} = {{\n".format(name))
                    f.write("    .w = {}_WIDTH,\n".format(name.upper()))
                    f.write("    .h = {}_HEIGHT,\n".format(name.upper()))
                    f.write("    .data = {\n")
                    for x in chunks(data, 12) :
                        f.write('        ')
                        for i in x:
                            f.write("0x{:02x}, ".format(i))
                        f.write('\n')
                    f.write("    }\n};\n")
        
                    icon_filenames.append('icon_{}'.format(name))
                    icon_filepaths.append(outfile)
            
    outfile = os.path.join(args.outdir, "weather-icons.h")
    with open(outfile, 'w') as f:
        f.write('#include <stdint.h>\n')
        f.write('#include <weather.h>\n')

        f.write('struct open_weather_icon {\n')
        f.write('    const int code;\n')
        f.write('    const char* description;')
        f.write('    const struct icon* icon;\n')
        f.write('};\n')

        for i in icon_filenames:
            f.write("extern const struct icon {};\n".format(i))

        sizes = ['16x16', '32x32', '64x64', '128x128']

        for i in sizes:
            f.write("static const struct open_weather_icon day_weather_icons_{}[] = {{\n".format(i))
            for key in wmo_weatercode_map:
                f.write('    {{{}, "{}", &icon_{}_{}}},\n'.format(key, wmo_weatercode_map[key][1], wmo_weatercode_map[key][0], i))
            f.write('    {{100, "WMO Code: ", &icon_unknown_{}}},\n'.format(i))
            f.write("};\n")

            f.write("static const struct open_weather_icon night_weather_icons_{}[] = {{\n".format(i))
            for key in wmo_weatercode_map:
                f.write('    {{{}, "{}", &icon_nt_{}_{}}},\n'.format(key, wmo_weatercode_map[key][1], wmo_weatercode_map[key][0], i))
            f.write('    {{100, "WMO Code: ", &icon_nt_unknown_{}}},\n'.format(i))
            f.write("};\n")

    with open('CMakeLists.txt', 'w') as f:
        f.write('idf_component_register(SRCS\n')
        f.write('${CMAKE_CURRENT_LIST_DIR}/src/weather-icons.c\n')
        for i in icon_filepaths:
            f.write('${{CMAKE_CURRENT_LIST_DIR}}/{}\n'.format(i))

        f.write('INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/include)\n')