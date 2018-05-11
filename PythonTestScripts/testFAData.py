#!/usr/bin/python3

import time
import sys
import numpy
from SALPY_m1m3 import *

mgr = SAL_m1m3()
mgr.salTelemetryPub("m1m3_ForceActuatorData")
myData = m1m3_ForceActuatorDataC()
myData.Timestamp = 1.0


loopCounter=0
while loopCounter < 10:
  for i in range(0,156):
    myData.StaticXSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.StaticYSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.StaticZSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.ElevationXSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.ElevationYSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.ElevationZSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.AzimuthXSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.AzimuthYSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.AzimuthZSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.TemperatureXSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.TemperatureYSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.TemperatureZSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.ActiveOpticsZSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.AberrationZSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.HardpointOffloadXSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.HardpointOffloadYSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.HardpointOffloadZSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.DynamicXSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.DynamicYSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.DynamicZSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.OffsetXSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.OffsetYSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.OffsetZSetpoint[i]=i + loopCounter
    myData.ElevationSetpointPercentage = 1.0 + loopCounter
  for i in range(0,156):
    myData.XSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.YSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.ZSetpoint[i]=i + loopCounter
  for i in range(0,156):
    myData.PrimaryCylinderSetpointCommanded[i]=i + loopCounter
  for i in range(0,156):
    myData.SecondaryCylinderSetpointCommanded[i]=i + loopCounter
  for i in range(0,156):
    myData.BroadcastCounter[i]=i + loopCounter
  for i in range(0,156):
    myData.SlewFlagCommanded[i]=(i + loopCounter) % 2
  for i in range(0,156):
    myData.PrimaryCylinderForce[i]=i + loopCounter
  for i in range(0,156):
    myData.SecondaryCylinderForce[i]=i + loopCounter
  for i in range(0,156):
    myData.ILCFault[i]=(i + loopCounter) % 2
  for i in range(0,156):
    myData.DCAFault[i]=(i + loopCounter) % 2
  for i in range(0,156):
    myData.XForce[i]=i + loopCounter
  for i in range(0,156):
    myData.YForce[i]=i + loopCounter
  for i in range(0,156):
    myData.ZForce[i]=i + loopCounter

  retval = mgr.putSample_ForceActuatorData(myData)
  loopCounter = loopCounter + 1
  time.sleep(1)

mgr.salShutdown()
exit()

