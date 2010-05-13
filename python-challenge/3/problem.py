#!/usr/bin/python

# http://www.pythonchallenge.com/pc/def/equality.html

import string, re


letters = list('abcdefghijklmnopqrstuvwxyz')
input  = open('input.file').read().translate(None,"\n")

pattern = re.compile('[^A-Z][A-Z]{3}([a-z])[A-Z]{3}[^A-Z]')

print "".join(re.findall(pattern,input))

