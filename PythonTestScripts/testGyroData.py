#!/usr/bin/python3

import time
import sys
import numpy
from SALPY_m1m3 import *

mgr = SAL_m1m3()
mgr.salTelemetryPub("m1m3_GyroData")
myData = m1m3_GyroDataC()

i=0
while i < 10:
  myData.Timestamp = 1613287608.0 + i
  myData.AngularVelocityX = 1.1 + i
  myData.AngularVelocityY = 2.2 + i
  myData.AngularVelocityZ = 3.3 + i
  myData.SequenceNumber = i
  myData.Temperature = 14 - i
  retval = mgr.putSample_GyroData(myData)
  i=i+1
  time.sleep(1)

mgr.salShutdown()
exit()

