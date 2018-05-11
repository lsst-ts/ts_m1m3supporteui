#!/usr/bin/python3

import time
import sys
import numpy
from SALPY_m1m3 import *

mgr = SAL_m1m3()
mgr.salTelemetryPub("m1m3_HardpointData")
myData = m1m3_HardpointDataC()
mgr.salTelemetryPub("m1m3_HardpointMonitorStatus")
myMData = m1m3_HardpointMonitorStatusC()
mgr.salTelemetryPub("m1m3_HardpointStatus")
mySData = m1m3_HardpointStatusC()

myData.Timestamp = 1513287608.0
for i in range(0,6):
  myData.StepsQueued[i]=i
for i in range(0,6):
  myData.StepsCommanded[i]=i
for i in range(0,6):
  myData.Force[i]=i
for i in range(0,6):
  myData.Encoder[i]=i
for i in range(0,6):
  myData.ILCFault[i]=i
for i in range(0,6):
  myData.CWLimitOperated[i]=i
for i in range(0,6):
  myData.CCWLimitOperated[i]=i
for i in range(0,6):
  myData.BroadcastCounter[i]=i
for i in range(0,6):
  myData.Displacement[i]=i
for i in range(0,6):
  myData.BreakawayLVDT[i]=i
for i in range(0,6):
  myData.DisplacementLVDT[i]=i
for i in range(0,6):
  myData.BreakawayPressure[i]=i

myData.XPosition = 11.0
myData.YPosition = 12.0
myData.ZPosition = 13.0
myData.XRotation = 22.0
myData.YRotation = 23.0
myData.ZRotation = 24.0

myMData.Timestamp = 1513289608.0
for i in range(0,6):
  myMData.Mode[i]=i
for i in range(0,6):
  myMData.MajorFault[i]=i
for i in range(0,6):
  myMData.MinorFault[i]=i
for i in range(0,6):
  myMData.FaultOverridden[i]=i
for i in range(0,6):
  myMData.WatchdogReset[i]=i
for i in range(0,6):
  myMData.BrownoutDetected[i]=i
for i in range(0,6):
  myMData.EventTrapReset[i]=i
for i in range(0,6):
  myMData.MotorPowerFault[i]=i
for i in range(0,6):
  myMData.SSRPowerFault[i]=i
for i in range(0,6):
  myMData.AUXPowerFault[i]=i
for i in range(0,6):
  myMData.SMCPowerFault[i]=i
for i in range(0,6):
  myMData.MezzanineS1A1InterfaceFault[i]=i
for i in range(0,6):
  myMData.MezzanineS1A1LVDTFault[i]=i
for i in range(0,6):
  myMData.MezzanineS1A2InterfaceFault[i]=i
for i in range(0,6):
  myMData.MezzanineS1A2LVDTFault[i]=i
for i in range(0,6):
  myMData.MezzanineEventTrapReset[i]=i

mySData.Timestamp = 1513297608.0
for i in range(0,6):
  mySData.Mode[i]=i
for i in range(0,6):
  mySData.MajorFault[i]=i
for i in range(0,6):
  mySData.MinorFault[i]=i
for i in range(0,6):
  mySData.FaultOverridden[i]=i
for i in range(0,6):
  mySData.WatchdogReset[i]=i
for i in range(0,6):
  mySData.BrownoutDetected[i]=i
for i in range(0,6):
  mySData.EventTrapReset[i]=i
for i in range(0,6):
  mySData.MotorPowerFault[i]=i
for i in range(0,6):
  mySData.SSRPowerFault[i]=i
for i in range(0,6):
  mySData.AUXPowerFault[i]=i
for i in range(0,6):
  mySData.SMCPowerFault[i]=i

i=0
while i<10:
  retval = mgr.putSample_HardpointStatus(mySData)
  i=i+1
  time.sleep(1)

i=0
while i<10:
  retval = mgr.putSample_HardpointMonitorStatus(myMData)
  i=i+1
  time.sleep(1)

i=0
while i<10:
  retval = mgr.putSample_HardpointData(myData)
  i=i+1
  time.sleep(1)

mgr.salShutdown()
exit()

