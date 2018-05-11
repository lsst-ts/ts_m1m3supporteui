#!/usr/bin/python3

import time
import sys
import numpy
from datetime import datetime

from SALPY_m1m3 import *

mgr = SAL_m1m3()
mgr.salEvent("m1m3_logevent_InterlockStatus")
mgr.salEvent("m1m3_logevent_InterlockWarning")

d = datetime.today()
timestamp = time.mktime(d.timetuple())

statusData = m1m3_logevent_InterlockStatusC()
statusData.Timestamp=timestamp
statusData.HeartbeatCommandedState=1
statusData.HeartbeatOutputState=1
statusData.CriticalFaultCommandedState=0
statusData.CriticalFaultOutputState=0
statusData.MirrorLoweringRaisingCommandedState=0
statusData.MirrorLoweringRaisingOutputState=0
statusData.MirrorParkedCommandedState=0
statusData.MirrorParkedOutputState=0
statusData.priority=10
priority=int(statusData.priority)
mgr.logEvent_InterlockStatus(statusData, priority)

warningData = m1m3_logevent_InterlockWarningC()
warningData.Timestamp=timestamp
warningData.AnyWarning=0
warningData.HeartbeatStateOutputMismatch=0
warningData.CriticalFaultStateOutputMismatch=0
warningData.MirrorLoweringRaisingStateOutputMismatch=0
warningData.MirrorParkedStateOutputMismatch=0
warningData.PowerNetworksOff=0
warningData.ThermalEquipmentOff=0
warningData.LaserTrackerOff=0
warningData.AirSupplyOff=0
warningData.GISEarthquake=0
warningData.GISEStop=0
warningData.TMAMotionStop=0
warningData.GISHeartbeatLost=0
warningData.priority=10
priority=int(warningData.priority)
mgr.logEvent_InterlockWarning(warningData, priority)

time.sleep(1)
mgr.salShutdown()

exit()

