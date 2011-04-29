#!/usr/bin/python

def sumMultiplesOf3Or5(topNumber):
'''Sums all values below topNumber that are a multiple of 3 or 5
'''
    return sum(filter(lambda x: x%3==0 or x%5==0,range(topNumber)))

expectedValue = 23
testValue = sumMultiplesOf3Or5(10)
if testValue != expectedValue:
    raise Exception('test fails: %d != %d' % (expectedValue,testValue) )

print sumMultiplesOf3Or5(1000)
