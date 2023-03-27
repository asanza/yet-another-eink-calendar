#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Copyright (c) 2023 Diego Asanza <f.asanza@gmail.com>
#
# SPDX-License-Identifier: Apache-2.0
#

from PIL import Image
from numpy import packbits
import argparse
from pathlib import Path

def chunks(l, n):
    # looping till length l
    for i in range(0, len(l), n):
        yield l[i:i + n]


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--threshold", default=200, type=int)
    parser.add_argument("--width", default=800, type=int)
    parser.add_argument("--height", default=480, type=int)
    parser.add_argument("infile")
    parser.add_argument("outfile")
    args = parser.parse_args()

    size = (args.width, args.height)

    with Image.open(args.infile) as im:
        if(im.mode != 'L'):
            r, g, b, a = im.split()
            im = Image.merge("RGB", (r, g, b))
            im = im.convert('L')
        im = im.resize(size)
        im = im.point( lambda p: 255 if p > args.threshold else 0 )
        im = im.convert('1')
        im = im.crop((0, 0) + size)
        
        data = packbits(im.getdata())
        width = im.width
        height = im.height
        name = Path(args.outfile).stem.replace('-', '_')

        with open(args.outfile, 'w') as f:
            f.write("#define {}_WIDTH {} \n".format(name.upper(), width))
            f.write("#define {}_HEIGHT {} \n".format(name.upper(), height))
            f.write("static const unsigned char {} [] = {{\n".format(name))

            for x in chunks(data, 12) :
                f.write('    ')
                for i in x:
                    f.write("0x{:02x}, ".format(i))
                f.write('\n')

            f.write("};\n")
