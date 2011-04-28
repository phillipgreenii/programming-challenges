#!/usr/bin/python

# http://www.pythonchallenge.com/pc/def/oxygen.html
import urllib, zipfile, re

pngUrl = 'http://www.pythonchallenge.com/pc/def/oxygen.png'
url = urllib.urlopen(pngUrl)
print url.read()
url.close()
