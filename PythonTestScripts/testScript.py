#!/usr/bin/python3
'''
This is a just a script to help me test the M1M3 Support 
Engineering User Interface.
'''
import time
import sys
import math
from SALPY_m1m3 import *

# Register SAL components
mgr = SAL_m1m3()
mgr.salTelemetryPub("m1m3_InclinometerData")
mgr.salTelemetryPub("m1m3_IMSData")

# initialize variables
dataVariable = 1.0
timeStampCounter = 1.0
direction = 1

# Outside loop changes direction every time
# Inside loop goes the current direction a number of iterations
# neither variable is used.
for outsideLoopCounter in range(20):
    for indsideLoopCounter in range(10):
        # Inclinometer Data Publishing
        myInclinometerData = m1m3_InclinometerDataC()
        myInclinometerData.Timestamp = timeStampCounter
        myInclinometerData.InclinometerAngle = dataVariable
        retval = mgr.putSample_InclinometerData(myInclinometerData)

        # Displacement Data Publishing.
        myDisplacementData = m1m3_IMSDataC()
        myDisplacementData.Timestamp = timeStampCounter
        for rawSensorCounter in range(0,6):
            myDisplacementData.RawSensorData[rawSensorCounter] = (dataVariable / 2) + 0.2 ** rawSensorCounter 
        myDisplacementData.XPosition = dataVariable + 1.0
        myDisplacementData.YPosition = dataVariable + 2.0
        myDisplacementData.ZPosition = dataVariable - 1.0
        myDisplacementData.XRotation = math.sqrt(dataVariable) - 1.0
        myDisplacementData.YRotation = math.sqrt(dataVariable) + 2.0
        myDisplacementData.ZRotation = math.sqrt(dataVariable) + 1.0
        retval = mgr.putSample_IMSData(myDisplacementData)
        
        # changing direction, updating counters.
        dataVariable = dataVariable + direction
        timeStampCounter = timeStampCounter + 1
        time.sleep(1)
    direction = direction * -1

mgr.salShutdown()
exit()

