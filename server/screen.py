import pytest
import os
import tempfile
from html2image import Html2Image
from PIL import Image
import time

class EpaperScreen:
    def __init__(self, url, width, height, thresshold=200):
        self.url = url
        self.size = (width, height)
        self.threshold = thresshold
        self.hti = Html2Image(browser="chrome", size=self.size, custom_flags="--disable-gpu")

    def get_screenshoot(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = os.path.join(tmp, 'escreen')
            self.hti.output_path = path
            filename = str(time.time()) + '.png'
            self.hti.screenshot(url=self.url, save_as=filename, size=self.size)
            with Image.open(os.path.join(path, filename)) as im:
                r, g, b, a = im.split()
                im = Image.merge("RGB", (r, g, b))
                im = im.convert('L')
                im = im.point( lambda p: 255 if p > self.threshold else 0 )
                im = im.convert('1')
                im = im.crop((0, 0) + self.size)
                return im
        return None

if __name__ == "__main__":
    e = EpaperScreen("server/template/image.html", 800, 480)
    im = e.get_screenshoot()
    im.save('testo.bmp')



