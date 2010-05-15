#!/usr/bin/python

# http://www.pythonchallenge.com/pc/def/channel.html
import urllib, zipfile, re

fileUrl = 'http://www.pythonchallenge.com/pc/def/channel.zip'

(filename,ignore) = urllib.urlretrieve(fileUrl)

zipfile = zipfile.ZipFile(filename)

startingPattern = re.compile('start from ([0-9]*)')
linkingNumberPattern = re.compile('Next nothing is ([0-9]*)')

number = startingPattern.search(zipfile.read('readme.txt')).group(1)
while number:
    filename = number + '.txt'
    fileContents = zipfile.read(filename)
    info = zipfile.getinfo(filename)
    print info.comment,
    numberMatch = linkingNumberPattern.search(fileContents)
    if numberMatch:
        number = numberMatch.group(1)
    else:
        number = None
zipfile.close()
