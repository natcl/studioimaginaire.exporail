#!/usr/bin/python

import serial
import time

ser = serial.Serial('/dev/tty.usbserial')
ser.setRTS(False)
f = open('DATALOG.TXT', 'r')

filedata = f.read()

filearray =  filedata.split('\r\n')
filedict = {}
for x in filearray:
    try:
        filedict[int(x.split(',')[0])] = int(x.split(',')[1][1])
    except IndexError:
        continue
#print filedict

counter = 0
while (counter < 22000):
    time.sleep(0.001)
    counter += 1
    #print counter
    if filedict.has_key(counter):
        if filedict[counter]:
            ser.setRTS(True)
        else:
            ser.setRTS(False)
    #print counter
