#!/usr/bin/env python

import random
import string
import cherrypy
from screen import EpaperScreen
import io
from numpy import packbits, asarray
import matplotlib.pyplot as plt
import cbor2

from PIL import Image
from PIL.Image import FLOYDSTEINBERG

global_conf = {
        'server.socket_host' : '0.0.0.0',
        'server.socket_port' : 8080,
    }

def create_template():
    with open('template/image_template.html', 'r') as f:
        s = f.read().encode('utf-8')

    

    with open('template/image1.html', 'w') as f:
        f.write(s.decode('utf-8'))

class Root(object):
    @cherrypy.expose
    def index(self):
        return "Hello World!"

class Image(object):
    @cherrypy.expose
    def index(self):
        cherrypy.response.headers['Content-Type'] = 'image/bmp'
        create_template()
        e = EpaperScreen("template/image.html", 800, 480)
        self.im = e.get_screenshoot() 
        buf = io.BytesIO()
        self.im.save(buf, 'bmp')
        return buf.getvalue()

class ImageCbor(object):
    @cherrypy.expose
    def index(self):
        cherrypy.response.headers['Content-Type'] = 'application/cbor'
        e = EpaperScreen("template/image.html", 800, 480)
        self.im = e.get_screenshoot() 
        bim = bytearray(packbits(asarray(self.im.getdata())))
        data = cbor2.dumps(bim)
        return data

if __name__ == '__main__':    
    conf = {
        '/': {
            'tools.sessions.on': False,
            'tools.response_headers.on': True,
        }
    }

    cherrypy.config.update(global_conf)

    app = cherrypy.tree.mount(Root(), '/', config=conf)
    app = cherrypy.tree.mount(Image(), '/image', config=conf)
    app = cherrypy.tree.mount(ImageCbor(), '/cbor', config=conf)
    cherrypy.engine.start()
    cherrypy.engine.block()