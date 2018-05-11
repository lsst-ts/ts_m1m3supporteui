#!/usr/bin/python3

import time
import sys
import numpy
import random
from datetime import datetime
from SALPY_m1m3 import *

def generateCount(i:int, counter:int):
  return i * counter * 50 + random.randint(0,99)

def generateBoolean():
  return 1 if (random.randint(0,99) < 5) else 0 

mgr = SAL_m1m3()
mgr.salTelemetryPub("m1m3_FPGAData")
mgr.salTelemetryPub("m1m3_OuterLoopData")

d = datetime.today()
timestamp = time.mktime(d.timetuple())

fpgaData = m1m3_FPGADataC()
fpgaData.Timestamp = timestamp

outerLoopData = m1m3_OuterLoopDataC()
outerLoopData.Timestamp = timestamp

counter=0
while counter < 10:
  for i in range(0,5):
    fpgaData.ModbusTxInternalFIFOOverflow[i] = generateBoolean()
  for i in range(0,5):
    fpgaData.ModbusInvalidInstruction[i] = generateBoolean()
  for i in range(0,5):
    fpgaData.ModbusWaitForRxFrameTimeout[i] = generateBoolean()
  for i in range(0,5):
    fpgaData.ModbusStartBitError[i] = generateBoolean()
  for i in range(0,5):
    fpgaData.ModbusStopBitError[i] = generateBoolean()
  for i in range(0,5):
    fpgaData.ModbusRxDataFIFOOverflow[i] = generateBoolean()
  for i in range(0,5):
    fpgaData.ModbusTxByteCount[i] = generateCount(i,counter)
  for i in range(0,5):
    fpgaData.ModbusTxFrameCount[i] = generateCount(i,counter)
  for i in range(0,5):
    fpgaData.ModbusRxByteCount[i] = generateCount(i,counter)
  for i in range(0,5):
    fpgaData.ModbusRxFrameCount[i] = generateCount(i,counter)
  fpgaData.FPGATime = counter
  retval = mgr.putSample_FPGAData(fpgaData)

  # Broadcast counter is an integer between 0 and 255)
  outerLoopData.BroadcastCounter = random.randint(0,255)
  outerLoopData.SlewFlag = generateBoolean()
  retval = mgr.putSample_OuterLoopData(outerLoopData)

  counter = counter + 1
  time.sleep(1)

mgr.salShutdown()
exit()

