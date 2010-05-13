#!/usr/bin/python

# http://www.pythonchallenge.com/pc/def/peak.html
import urllib, pickle

peakUrl = 'http://www.pythonchallenge.com/pc/def/banner.p'
url = urllib.urlopen(peakUrl)
data = pickle.load(url)
url.close()

for line in data:
    lineStr = ''
    for (str,count) in line:
        lineStr = lineStr + str*count
    print lineStr
