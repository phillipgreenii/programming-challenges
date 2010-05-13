#!/usr/bin/python

# http://www.pythonchallenge.com/pc/def/ocr.html

import string

letters = list(string.lowercase)
for line in open('input.file'):
    for letter in list(line.strip()):
        if letter in letters:
            print letter,
