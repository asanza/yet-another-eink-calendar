#!/usr/bin/env bash

from screen import EpaperScreen
import matplotlib.pyplot as plt
import numpy as np

e = EpaperScreen("template/image.html", 800, 480)

im = e.get_screenshoot()

im.save('out.png')

# bim = bytearray(np.packbits(np.asarray(im.getdata())))
# bim = None
# with open('/home/diego/Downloads/download', 'rb') as f:
#     bim = f.read()

# bim = bim[3:]

# arr = []

# for i in bim:
#     if i & 0x80:
#         arr.append(255)
#     else:
#         arr.append(0)
#     if i & 0x40:
#         arr.append(255)
#     else:
#         arr.append(0)
#     if i & 0x20:
#         arr.append(255)
#     else:
#         arr.append(0)
#     if i & 0x10:
#         arr.append(255)
#     else:
#         arr.append(0)
#     if i & 0x08:
#         arr.append(255)
#     else:
#         arr.append(0)
#     if i & 0x04:
#         arr.append(255)
#     else:
#         arr.append(0)
#     if i & 0x02:
#         arr.append(255)
#     else:
#         arr.append(0)
#     if i & 0x01:
#         arr.append(255)
#     else:
#         arr.append(0)

# arr = np.asarray(arr)


# bim = np.reshape(arr, (480, 800))

# plt.imshow(bim)
# plt.show()

# im.save('out.png')