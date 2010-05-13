#!/usr/bin/python

# http://www.pythonchallenge.com/pc/def/linkedlist.php

baseUrl = 'http://www.pythonchallenge.com/pc/def/linkedlist.php'

import string, re, urllib

startingNumberPattern = re.compile('linkedlist.php\?nothing=([0-9]*)')

url = urllib.urlopen(baseUrl)
number = re.search(startingNumberPattern,url.read()).group(1)
url.close()

linkingNumberPattern = re.compile('and the next nothing is ([0-9]*)')
baseLinkingUrl = baseUrl + "?%s"
count = 0
print number
while number and count < 400:
    count = count + 1
    params = urllib.urlencode({'nothing': number})    
    url = urllib.urlopen(baseLinkingUrl % params)
    page = url.read()
    numberMatch = re.search(linkingNumberPattern,page)
    url.close()
    if numberMatch:
        number = numberMatch.group(1)
        print number
    elif page == 'Yes. Divide by two and keep going.':
        number = str(int(number) / 2)
        print "halved: " + number
    else:
        number = None
        print page
