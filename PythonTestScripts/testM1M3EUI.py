#!/usr/bin/python3.6
'''
a quick python script to test the EUI using threads.
'''

import math
import numpy
import random
import sys
import threading
import time
from datetime import datetime
from enum import Enum
from SALPY_m1m3 import *

# current detailed states used by M1M3 Support
class M1M3State(Enum):
  DISABLED = 1
  ENABLED = 2
  FAULT = 3
  OFFLINE = 4
  STANDBY = 5
  PARKED = 6
  RAISING = 7
  ACTIVE = 8
  LOWERING = 9
  ENGINEERING = 10
  PARKEDENGINEERING = 11
  RAISINGENGINEERING = 12
  ACTIVEENGINEERING = 13
  LOWERINGENGINEERING = 14
  LOWERINGFAULT = 15
  PROFILEHARDPOINTCORRECTION = 16

# constants used by SAL
SAL__CMD_COMPLETE=303
# Initializing SAL
mgr = SAL_m1m3()

def init(mgr):
  print("Initializing SAL Manager... (may take a while)")

  # turn off the debug messages 
  mgr.setDebugLevel(0)

  # State Commands
  stateCommands = []
  stateCommands.append("m1m3_command_Start")
  stateCommands.append("m1m3_command_Standby")
  stateCommands.append("m1m3_command_Shutdown")
  stateCommands.append("m1m3_command_Enable")
  stateCommands.append("m1m3_command_Disable")
  stateCommands.append("m1m3_command_RaiseM1M3")
  stateCommands.append("m1m3_command_AbortRaiseM1M3")
  stateCommands.append("m1m3_command_LowerM1M3")
  stateCommands.append("m1m3_command_EnterEngineering")
  stateCommands.append("m1m3_command_ExitEngineering")

  # Hardpoint Commands
  hardpointCommands = []
  hardpointCommands.append("m1m3_command_EnableHardpointChase")
  hardpointCommands.append("m1m3_command_DisableHardpointChase")
  hardpointCommands.append("m1m3_command_EnableHardpointCorrections")
  hardpointCommands.append("m1m3_command_DisableHardpointCorrections")
  hardpointCommands.append("m1m3_command_MoveHardpointActuators")
  hardpointCommands.append("m1m3_command_StopHardpointMotion")
  hardpointCommands.append("m1m3_command_PositionM1M3")
  hardpointCommands.append("m1m3_command_TranslateM1M3")

  # Air Commands
  airCommands = []
  airCommands.append("m1m3_command_TestAir")
  airCommands.append("m1m3_command_TurnAirOff")
  airCommands.append("m1m3_command_TurnAirOn")

  # Misc Commands
  miscCommands = []
  miscCommands.append("m1m3_command_ResetPID")
  miscCommands.append("m1m3_command_TurnPowerOn")
  miscCommands.append("m1m3_command_TurnPowerOff")
  miscCommands.append("m1m3_command_UpdatePID")

  # Events
  logEvents = []
  logEvents.append("m1m3_logevent_AirSupplyWarning")
  logEvents.append("m1m3_logevent_AirSupplyStatus")
  logEvents.append("m1m3_logevent_AppliedForces")
  logEvents.append("m1m3_logevent_CommandRejectionWarning")
  logEvents.append("m1m3_logevent_DetailedState")
  logEvents.append("m1m3_logevent_ErrorCode")
  logEvents.append("m1m3_logevent_ForceActuatorForceWarning")
  logEvents.append("m1m3_logevent_ForceActuatorInfo")
  logEvents.append("m1m3_logevent_ForceActuatorState")
  logEvents.append("m1m3_logevent_ForceActuatorWarning")
  logEvents.append("m1m3_logevent_HardpointActuatorInfo")
  logEvents.append("m1m3_logevent_HardpointActuatorState")
  logEvents.append("m1m3_logevent_HardpointActuatorWarning")
  logEvents.append("m1m3_logevent_HardpointMonitorInfo")
  logEvents.append("m1m3_logevent_HardpointMonitorState")
  logEvents.append("m1m3_logevent_HardpointMonitorWarning")
  logEvents.append("m1m3_logevent_InterlockStatus")
  logEvents.append("m1m3_logevent_InterlockWarning")
  logEvents.append("m1m3_logevent_PIDInfo")
  logEvents.append("m1m3_logevent_PowerStatus")
  logEvents.append("m1m3_logevent_PowerWarning")
  logEvents.append("m1m3_logevent_RejectedForces")
  logEvents.append("m1m3_logevent_SettingsApplied")
  logEvents.append("m1m3_logevent_SettingVersions")
  logEvents.append("m1m3_logevent_SummaryState")

  # Telemetry Publishers
  telemetryTopics= []
  telemetryTopics.append("m1m3_AccelerometerData")
  telemetryTopics.append("m1m3_ForceActuatorData")
  telemetryTopics.append("m1m3_GyroData")
  telemetryTopics.append("m1m3_HardpointActuatorData")
  telemetryTopics.append("m1m3_HardpointMonitorData")
  telemetryTopics.append("m1m3_InclinometerData")
  telemetryTopics.append("m1m3_IMSData")
  telemetryTopics.append("m1m3_OuterLoopData")
  telemetryTopics.append("m1m3_PIDData")
  telemetryTopics.append("m1m3_PowerSupplyData")

  # load all topics into the SAL manager
  for stateCommand in stateCommands:
    print("starting " + stateCommand)
    mgr.salProcessor(stateCommand)
  for hardpointCommand in hardpointCommands:
    print("starting " + hardpointCommand)
    mgr.salProcessor(hardpointCommand)
  for airCommand in airCommands:
    print("starting " + airCommand)
    mgr.salProcessor(airCommand)
  for miscCommand in miscCommands:
    print("starting " + miscCommand)
    mgr.salProcessor(miscCommand)
  for logEvent in logEvents:
    print("starting " + logEvent)
    mgr.salEvent(logEvent)
  for telemetryTopic in telemetryTopics:
    print("starting " + telemetryTopic)
    mgr.salTelemetryPub(telemetryTopic)

  print("Done Initializing")

############################################################
# returns 0 or 1 with a 5% chance of returning 1
def generateBoolean(percentChance:int = 5):
  return 1 if (random.randint(0, 100) < percentChance) else 0 

############################################################
# Generating Telemetry for the Accelerometers
def generateAccelTelemetry(event, waittime):
  while not event.isSet():
    d = datetime.today()
    timestamp = time.mktime(d.timetuple())

    accelData = m1m3_AccelerometerDataC()
    accelData.Timestamp = timestamp
    for i in range(0,8):
      accelData.RawAccelerometer[i] = random.randint(-100, 100)
    for i in range(0,8):
      accelData.Accelerometer[i] = random.randint(-100, 100)
    accelData.AngularAccelerationX = random.uniform(0.0, 360.0)
    accelData.AngularAccelerationY = random.uniform(0.0, 360.0)
    accelData.AngularAccelerationZ = random.uniform(0.0, 360.0)
    retval = mgr.putSample_AccelerometerData(accelData)

    time.sleep(1)
    event.wait(waittime)

############################################################
# Generating Events for the Air
def generateAirEvents(event, waittime):
  while not event.isSet():
    d = datetime.today()
    timestamp = time.mktime(d.timetuple())
    priority = 10

    airSupplyStatusData = m1m3_logevent_AirSupplyStatusC()
    airSupplyStatusData.Timestamp = timestamp
    airSupplyStatusData.AirCommandedOn = generateBoolean()
    airSupplyStatusData.AirCommandOutputOn = generateBoolean()
    airSupplyStatusData.AirValveOpened = generateBoolean()
    airSupplyStatusData.AirValveClosed = generateBoolean()
    airSupplyStatusData.priority = priority
    mgr.logEvent_AirSupplyStatus(airSupplyStatusData, priority)

    airSupplyWarningData = m1m3_logevent_AirSupplyWarningC()
    airSupplyWarningData.Timestamp = timestamp
    airSupplyWarningData.AnyWarning = generateBoolean()
    airSupplyWarningData.CommandOutputMismatch = generateBoolean()
    airSupplyWarningData.CommandSensorMismatch = generateBoolean()
    airSupplyWarningData.priority = priority
    mgr.logEvent_AirSupplyWarning(airSupplyWarningData, priority)

    time.sleep(random.randint(1, 20))
    event.wait(waittime)

############################################################
# check all commands and process them accordingly
# Since, control only processes one command at a time, this
# somewhat mimics it's functionality.
def processCommands(event, waittime):
  startCommandData = m1m3_command_StartC()
  standbyCommandData = m1m3_command_StandbyC()
  shutdownCommandData = m1m3_command_ShutdownC()
  enableCommandData = m1m3_command_EnableC()
  disableCommandData = m1m3_command_DisableC()
  raiseM1M3CommandData = m1m3_command_RaiseM1M3C()
  abortRaiseM1M3CommandData = m1m3_command_AbortRaiseM1M3C()
  lowerM1M3CommandData = m1m3_command_LowerM1M3C()
  enterEngineeringCommandData = m1m3_command_EnterEngineeringC()
  exitEngineeringCommandData = m1m3_command_ExitEngineeringC()
  summaryStateData = m1m3_logevent_SummaryStateC()
  detailedStateData = m1m3_logevent_DetailedStateC()

  enableHardpointChaseData = m1m3_command_EnableHardpointChaseC()
  disableHardpointChaseData = m1m3_command_DisableHardpointChaseC()
  enableHardpointCorrectionsData = m1m3_command_EnableHardpointCorrectionsC()
  disableHardpointCorrectionsData = m1m3_command_DisableHardpointCorrectionsC()
  moveHardpointActuatorsData = m1m3_command_MoveHardpointActuatorsC()
  stopHardpointMotionData = m1m3_command_StopHardpointMotionC()
  positionM1M3Data = m1m3_command_PositionM1M3C()
  translateM1M3Data = m1m3_command_TranslateM1M3C()

  turnAirOnData = m1m3_command_TurnAirOnC()
  turnAirOffData = m1m3_command_TurnAirOffC()
  testAirData = m1m3_command_TestAirC()

  turnPowerOnData = m1m3_command_TurnPowerOnC()
  turnPowerOffData = m1m3_command_TurnPowerOffC()
  updatePIDData = m1m3_command_UpdatePIDC()
  resetPIDData = m1m3_command_ResetPIDC()

  print("m1m3 test controller ready")

  currentState = M1M3State.STANDBY

  while not event.isSet():
  
    d = datetime.today()
    timestamp = time.mktime(d.timetuple())

    #########################
    # check for standby command
    cmdId = mgr.acceptCommand_Standby(standbyCommandData)
    if cmdId > 0:
      print("Standby = " + str(standbyCommandData.Standby))
      time.sleep(0.001)
      mgr.ackCommand_Standby(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");
      currentState=M1M3State.STANDBY
      detailedStateData.Timestamp = timestamp
      detailedStateData.DetailedState = int(M1M3State.STANDBY.value)
      detailedStateData.priority = int(1)
      priority = int(detailedStateData.priority)
      mgr.logEvent_DetailedState(detailedStateData, priority)
      summaryStateData.Timestamp = timestamp
      summaryStateData.SummaryState = int(M1M3State.STANDBY.value)
      summaryStateData.priority = int(1)
      mgr.logEvent_SummaryState(summaryStateData, priority)

    #########################
    # check for shutdown command
    cmdId = mgr.acceptCommand_Shutdown(shutdownCommandData)
    if cmdId > 0:
      print("Shutdown = " + str(shutdownCommandData.Shutdown))
      time.sleep(0.001)
      mgr.ackCommand_Shutdown(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");
      detailedStateData.Timestamp=timestamp
      detailedStateData.DetailedState=int(M1M3State.OFFLINE.value)
      detailedStateData.priority=int(1)
      priority=int(detailedStateData.priority)
      mgr.logEvent_DetailedState(detailedStateData, priority)
      summaryStateData.Timestamp = timestamp
      summaryStateData.SummaryState = int(M1M3State.OFFLINE.value)
      summaryStateData.priority = int(1)
      mgr.logEvent_SummaryState(summaryStateData, priority)

    #########################
    # check for start command
    cmdId = mgr.acceptCommand_Start(startCommandData)
    if cmdId > 0:
      print("Start = " + str(startCommandData.Start))
      print("SettingsToApply = " + str(startCommandData.SettingsToApply))
      time.sleep(0.001)
      mgr.ackCommand_Start(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");
      currentState=M1M3State.DISABLED
      detailedStateData.Timestamp=timestamp
      detailedStateData.DetailedState=int(M1M3State.DISABLED.value)
      detailedStateData.priority=int(1)
      priority=int(detailedStateData.priority)
      mgr.logEvent_DetailedState(detailedStateData, priority)
      summaryStateData.Timestamp = timestamp
      summaryStateData.SummaryState = int(M1M3State.DISABLED.value)
      summaryStateData.priority = int(1)
      mgr.logEvent_SummaryState(summaryStateData, priority)

    #########################
    # check for disable command
    cmdId = mgr.acceptCommand_Disable(disableCommandData)
    if cmdId > 0:
      print("Disable = " + str(disableCommandData.Disable))
      time.sleep(0.001)
      mgr.ackCommand_Disable(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");
      currentState=M1M3State.DISABLED
      detailedStateData.Timestamp=timestamp
      detailedStateData.DetailedState=int(M1M3State.DISABLED.value)
      detailedStateData.priority=int(1)
      priority=int(detailedStateData.priority)
      mgr.logEvent_DetailedState(detailedStateData, priority)
      summaryStateData.Timestamp = timestamp
      summaryStateData.SummaryState = int(M1M3State.DISABLED.value)
      summaryStateData.priority = int(1)
      mgr.logEvent_SummaryState(summaryStateData, priority)

    #########################
    # check for enable command
    cmdId = mgr.acceptCommand_Enable(enableCommandData)
    if cmdId > 0:
      print("Enable = " + str(enableCommandData.Enable))
      time.sleep(0.001)
      mgr.ackCommand_Enable(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");
      currentState=M1M3State.ENABLED
      detailedStateData.Timestamp=timestamp
      detailedStateData.DetailedState=int(M1M3State.ENABLED.value)
      detailedStateData.priority=int(1)
      priority=int(detailedStateData.priority)
      mgr.logEvent_DetailedState(detailedStateData, priority)
      summaryStateData.Timestamp = timestamp
      summaryStateData.SummaryState = int(M1M3State.ENABLED.value)
      summaryStateData.priority = int(1)
      mgr.logEvent_SummaryState(summaryStateData, priority)

      # when first entering ENABLED, the system goes directly to PARKED
      currentState=M1M3State.PARKED
      detailedStateData.Timestamp=timestamp
      detailedStateData.DetailedState=int(M1M3State.PARKED.value)
      detailedStateData.priority=int(1)
      priority=int(detailedStateData.priority)
      mgr.logEvent_DetailedState(detailedStateData, priority)
      
    #########################
    # check for enter engineering command
    cmdId = mgr.acceptCommand_EnterEngineering(enterEngineeringCommandData)
    if cmdId > 0:
      print("Enter Engineering = " + str(enterEngineeringCommandData.EnterEngineering))
      time.sleep(0.001)
      mgr.ackCommand_EnterEngineering(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");
      if (currentState == M1M3State.PARKED):
        currentState=M1M3State.PARKEDENGINEERING
        detailedStateData.Timestamp=timestamp
        detailedStateData.DetailedState=int(M1M3State.PARKEDENGINEERING.value)
        detailedStateData.priority=int(1)
        priority=int(detailedStateData.priority)
        mgr.logEvent_DetailedState(detailedStateData, priority)
      elif (currentState == M1M3State.ACTIVE):
        currentState=M1M3State.ACTIVEENGINEERING
        detailedStateData.Timestamp=timestamp
        detailedStateData.DetailedState=int(M1M3State.ACTIVEENGINEERING.value)
        detailedStateData.priority=int(1)
        priority=int(detailedStateData.priority)
        mgr.logEvent_DetailedState(detailedStateData, priority)

    #########################
    # check for exit engineering command
    cmdId = mgr.acceptCommand_ExitEngineering(exitEngineeringCommandData)
    if cmdId > 0:
      print("Exit Engineering = " + str(exitEngineeringCommandData.ExitEngineering))
      time.sleep(0.001)
      mgr.ackCommand_ExitEngineering(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");
      if (currentState == M1M3State.PARKEDENGINEERING):
        currentState=M1M3State.PARKED
        detailedStateData.Timestamp=timestamp
        detailedStateData.DetailedState=int(M1M3State.PARKED.value)
        detailedStateData.priority=int(1)
        priority=int(detailedStateData.priority)
        mgr.logEvent_DetailedState(detailedStateData, priority)
      elif (currentState == M1M3State.ACTIVEENGINEERING):
        currentState=M1M3State.ACTIVE
        detailedStateData.Timestamp=timestamp
        detailedStateData.DetailedState=int(M1M3State.ACTIVE.value)
        detailedStateData.priority=int(1)
        priority=int(detailedStateData.priority)
        mgr.logEvent_DetailedState(detailedStateData, priority)

    #########################
    # check for raise command
    cmdId = mgr.acceptCommand_RaiseM1M3(raiseM1M3CommandData)
    if cmdId > 0:
      print("Raise M1M3 = " + str(raiseM1M3CommandData.RaiseM1M3))
      time.sleep(0.001)
      mgr.ackCommand_RaiseM1M3(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");
      if (currentState == M1M3State.PARKED):
        currentState=M1M3State.RAISING
        detailedStateData.Timestamp=timestamp
        detailedStateData.DetailedState=int(M1M3State.RAISING.value)
        detailedStateData.priority=int(1)
        priority=int(detailedStateData.priority)
        mgr.logEvent_DetailedState(detailedStateData, priority)
        currentState=M1M3State.ACTIVE
        detailedStateData.Timestamp=timestamp
        detailedStateData.DetailedState=int(M1M3State.ACTIVE.value)
        detailedStateData.priority=int(1)
        priority=int(detailedStateData.priority)
        mgr.logEvent_DetailedState(detailedStateData, priority)
      elif (currentState == M1M3State.PARKEDENGINEERING):
        currentState=M1M3State.RAISINGENGINEERING
        detailedStateData.Timestamp=timestamp
        detailedStateData.DetailedState=int(M1M3State.RAISINGENGINEERING.value)
        detailedStateData.priority=int(1)
        priority=int(detailedStateData.priority)
        mgr.logEvent_DetailedState(detailedStateData, priority)
        currentState=M1M3State.ACTIVEENGINEERING
        detailedStateData.Timestamp=timestamp
        detailedStateData.DetailedState=int(M1M3State.ACTIVEENGINEERING.value)
        detailedStateData.priority=int(1)
        priority=int(detailedStateData.priority)
        mgr.logEvent_DetailedState(detailedStateData, priority)

    #########################
    # check for lower command
    cmdId = mgr.acceptCommand_LowerM1M3(lowerM1M3CommandData)
    if cmdId > 0:
      print("Lower M1M3 = " + str(lowerM1M3CommandData.LowerM1M3))
      time.sleep(0.001)
      mgr.ackCommand_LowerM1M3(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");
      if (currentState == M1M3State.ACTIVE):
        currentState=M1M3State.LOWERING
        detailedStateData.Timestamp=timestamp
        detailedStateData.DetailedState=int(M1M3State.LOWERING.value)
        detailedStateData.priority=int(1)
        priority=int(detailedStateData.priority)
        mgr.logEvent_DetailedState(detailedStateData, priority)
        currentState=M1M3State.PARKED
        detailedStateData.Timestamp=timestamp
        detailedStateData.DetailedState=int(M1M3State.PARKED.value)
        detailedStateData.priority=int(1)
        priority=int(detailedStateData.priority)
        mgr.logEvent_DetailedState(detailedStateData, priority)
      elif (currentState == M1M3State.ACTIVEENGINEERING):
        currentState=M1M3State.LOWERINGENGINEERING
        detailedStateData.Timestamp=timestamp
        detailedStateData.DetailedState=int(M1M3State.LOWERINGENGINEERING.value)
        detailedStateData.priority=int(1)
        priority=int(detailedStateData.priority)
        mgr.logEvent_DetailedState(detailedStateData, priority)
        currentState=M1M3State.PARKEDENGINEERING
        detailedStateData.Timestamp=timestamp
        detailedStateData.DetailedState=int(M1M3State.PARKEDENGINEERING.value)
        detailedStateData.priority=int(1)
        priority=int(detailedStateData.priority)
        mgr.logEvent_DetailedState(detailedStateData, priority)
        
    #########################
    # check for enable hardpoint chase command
    cmdId = mgr.acceptCommand_EnableHardpointChase(enableHardpointChaseData)
    if cmdId > 0:
      print("Enable Hardpoint Chase ActuatorId = " + str(enableHardpointChaseData.HardpointActuator))
      time.sleep(0.001)
      mgr.ackCommand_EnableHardpointChase(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");


    #########################
    # check for disable hardpoint chase command
    cmdId = mgr.acceptCommand_DisableHardpointChase(disableHardpointChaseData)
    if cmdId > 0:
      print("disable Hardpoint Chase ActuatorId = " + str(disableHardpointChaseData.HardpointActuator))
      time.sleep(0.001)
      mgr.ackCommand_DisableHardpointChase(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");

    #########################
    # check for enable hardpoint corrections command
    cmdId = mgr.acceptCommand_EnableHardpointCorrections(enableHardpointCorrectionsData)
    if cmdId > 0:
      print("Enable Hardpoint Corrections = " + str(enableHardpointCorrectionsData.EnableHardpointCorrections))
      time.sleep(0.001)
      mgr.ackCommand_EnableHardpointCorrections(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");

    #########################
    # check for disable hardpoint corrections command
    cmdId = mgr.acceptCommand_DisableHardpointCorrections(disableHardpointCorrectionsData)
    if cmdId > 0:
      print("Disable Hardpoint Corrections = " + str(disableHardpointCorrectionsData.DisableHardpointCorrections))
      time.sleep(0.001)
      mgr.ackCommand_DisableHardpointCorrections(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");

    #########################
    # check for Move Hardpoint Actuators
    cmdId = mgr.acceptCommand_MoveHardpointActuators(moveHardpointActuatorsData)
    if cmdId > 0:
      print("Move Hardpoint Actuators: Steps(6) = " + str(list(moveHardpointActuatorsData.Steps)))
      time.sleep(0.001)
      mgr.ackCommand_MoveHardpointActuators(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");

    #########################
    # check for Stop Hardpoint Motion
    cmdId = mgr.acceptCommand_StopHardpointMotion(stopHardpointMotionData)
    if cmdId > 0:
      print("StopHardpointMotion = " + str(stopHardpointMotionData.StopHardpointMotion))
      time.sleep(0.001)
      mgr.ackCommand_StopHardpointMotion(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");

    #########################
    # check for Position M1M3
    cmdId = mgr.acceptCommand_PositionM1M3(positionM1M3Data)
    if cmdId > 0:
      print("XPosition = " + str(positionM1M3Data.XPosition))
      print("YPosition = " + str(positionM1M3Data.YPosition))
      print("ZPosition = " + str(positionM1M3Data.ZPosition))
      print("XRotation = " + str(positionM1M3Data.XRotation))
      print("YRotation = " + str(positionM1M3Data.YRotation))
      print("ZRotation = " + str(positionM1M3Data.ZRotation))
      time.sleep(0.001)
      mgr.ackCommand_PositionM1M3(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");

    #########################
    # check for Translate M1M3
    cmdId = mgr.acceptCommand_TranslateM1M3(translateM1M3Data)
    if cmdId > 0:
      print("XTranslation = " + str(translateM1M3Data.XTranslation))
      print("YTranslation = " + str(translateM1M3Data.YTranslation))
      print("ZTranslation = " + str(translateM1M3Data.ZTranslation))
      print("XRotation = " + str(translateM1M3Data.XRotation))
      print("YRotation = " + str(translateM1M3Data.YRotation))
      print("ZRotation = " + str(translateM1M3Data.ZRotation))
      time.sleep(0.001)
      mgr.ackCommand_TranslateM1M3(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");

    #########################
    # check for TurnAirOn
    cmdId = mgr.acceptCommand_TurnAirOn(turnAirOnData)
    if cmdId > 0:
      print("TurnAirOn = " + str(turnAirOnData.TurnAirOn))
      time.sleep(0.001)
      mgr.ackCommand_TurnAirOn(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");

    #########################
    # check for TurnAirOff
    cmdId = mgr.acceptCommand_TurnAirOff(turnAirOffData)
    if cmdId > 0:
      print("TurnAirOff = " + str(turnAirOffData.TurnAirOff))
      time.sleep(0.001)
      mgr.ackCommand_TurnAirOff(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");

    #########################
    # check for TestAir
    cmdId = mgr.acceptCommand_TestAir(testAirData)
    if cmdId > 0:
      print("TestAir = " + str(testAirData.TestAir))
      time.sleep(0.001)
      mgr.ackCommand_TestAir(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");

    #########################
    # check for Turn Power On
    cmdId = mgr.acceptCommand_TurnPowerOn(turnPowerOnData)
    if cmdId > 0:
      print("TurnPowerNetworkAOn = " + str(turnPowerOnData.TurnPowerNetworkAOn))
      print("TurnPowerNetworkBOn = " + str(turnPowerOnData.TurnPowerNetworkBOn))
      print("TurnPowerNetworkCOn = " + str(turnPowerOnData.TurnPowerNetworkCOn))
      print("TurnPowerNetworkDOn = " + str(turnPowerOnData.TurnPowerNetworkDOn))
      print("TurnAuxPowerNetworkAOn = " + str(turnPowerOnData.TurnAuxPowerNetworkAOn))
      print("TurnAuxPowerNetworkBOn = " + str(turnPowerOnData.TurnAuxPowerNetworkBOn))
      print("TurnAuxPowerNetworkCOn = " + str(turnPowerOnData.TurnAuxPowerNetworkCOn))
      print("TurnAuxPowerNetworkDOn = " + str(turnPowerOnData.TurnAuxPowerNetworkDOn))
      time.sleep(0.001)
      mgr.ackCommand_TurnPowerOn(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");

    #########################
    # check for Turn Power Off
    cmdId = mgr.acceptCommand_TurnPowerOff(turnPowerOffData)
    if cmdId > 0:
      print("TurnPowerNetworkAOff = " + str(turnPowerOffData.TurnPowerNetworkAOff))
      print("TurnPowerNetworkBOff = " + str(turnPowerOffData.TurnPowerNetworkBOff))
      print("TurnPowerNetworkCOff = " + str(turnPowerOffData.TurnPowerNetworkCOff))
      print("TurnPowerNetworkDOff = " + str(turnPowerOffData.TurnPowerNetworkDOff))
      print("TurnAuxPowerNetworkAOff = " + str(turnPowerOffData.TurnAuxPowerNetworkAOff))
      print("TurnAuxPowerNetworkBOff = " + str(turnPowerOffData.TurnAuxPowerNetworkBOff))
      print("TurnAuxPowerNetworkCOff = " + str(turnPowerOffData.TurnAuxPowerNetworkCOff))
      print("TurnAuxPowerNetworkDOff = " + str(turnPowerOffData.TurnAuxPowerNetworkDOff))
      time.sleep(0.001)
      mgr.ackCommand_TurnPowerOff(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");

    #########################
    # check for Update PID
    cmdId = mgr.acceptCommand_UpdatePID(updatePIDData)
    if cmdId > 0:
      print("PID = " + str(updatePIDData.PID))
      print("Timestep = " + str(updatePIDData.Timestep))
      print("P = " + str(updatePIDData.P))
      print("I = " + str(updatePIDData.I))
      print("D = " + str(updatePIDData.D))
      print("N = " + str(updatePIDData.N))
      time.sleep(0.001)
      mgr.ackCommand_UpdatePID(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");

    #########################
    # check for Reset PID
    cmdId = mgr.acceptCommand_ResetPID(resetPIDData)
    if cmdId > 0:
      print("PID = " + str(resetPIDData.PID))
      time.sleep(0.001)
      mgr.ackCommand_ResetPID(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");

    event.wait(waittime)
  print("Command Thread shutdown complete.")

############################################################
# Generating Command Rejection Event
def generateCommandRejectionEvent(event, waittime):
  while not event.isSet():
    d = datetime.today()
    timestamp = time.mktime(d.timetuple())
    priority = 10
    
    commandRejectionData = m1m3_logevent_CommandRejectionWarningC()
    commandRejectionData.Timestamp = timestamp
    commandRejectionData.Command = "Exterminate!"
    commandRejectionData.Reason = "You are not a Dalek, you cannot exterminate."
    commandRejectionData.priority = priority
    mgr.logEvent_CommandRejectionWarning(commandRejectionData, priority)
    time.sleep(random.randint(30, 60))

    event.wait(waittime)
  print("Command Rejection Thread shutdown complete.")

############################################################
# Generating Error Code Event
def generateErrorCodeEvent(event, waittime):
  while not event.isSet():
    d = datetime.today()
    timestamp = time.mktime(d.timetuple())
    priority = 10

    #randomly choose an event to issue
    eventChoice = random.randint(1,4)

    if eventChoice == 1:
      errorCodeData = m1m3_logevent_ErrorCodeC()
      errorCodeData.Timestamp = timestamp
      errorCodeData.ErrorCode = random.randint(1,101)
      errorCodeData.DetailedErrorCode = random.randint(1000, 1999)
      errorCodeData.priority = priority
      mgr.logEvent_ErrorCode(errorCodeData, priority)

    elif eventChoice == 2:

      settingsAppliedData = m1m3_logevent_SettingsAppliedC()
      settingsAppliedData.Timestamp = timestamp
      settingsAppliedData.Settings = "Set of Settings that have not been set"
      settingsAppliedData.priority = priority
      mgr.logEvent_SettingsApplied(settingsAppliedData, priority)

    elif eventChoice == 3:
      
      settingVersionsData = m1m3_logevent_SettingVersionsC()
      settingVersionsData.Timestamp = timestamp
      settingVersionsData.RecommendedSettingsVersion = "Unrecommended Version of Settings"
      settingVersionsData.priority = priority
      mgr.logEvent_SettingVersions(settingVersionsData, priority)

    time.sleep(random.randint(30, 60))
    
    event.wait(waittime)
  print("Error Code Thread shutdown complete.")

############################################################
# Generating Events for the Force Actuators
def generateForceActuatorEvents(event, waittime):
  while not event.isSet():
    d = datetime.today()
    timestamp = time.mktime(d.timetuple())
    priority = 10

    #randomly choose an event to issue
    eventChoice = random.randint(1,7)

    if eventChoice == 1:
      forceActuatorForceWarningData = m1m3_logevent_ForceActuatorForceWarningC()
      forceActuatorForceWarningData.Timestamp = timestamp

      forceActuatorForceWarningData.AnyWarning = 1

      forceActuatorForceWarningData.AnyPrimaryAxisMeasuredForceWarning = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorForceWarningData.AnyPrimaryAxisMeasuredForceWarning = 1
          forceActuatorForceWarningData.PrimaryAxisMeasuredForceWarning[i] = 1
        else:
          forceActuatorForceWarningData.PrimaryAxisMeasuredForceWarning[i] = 0


      forceActuatorForceWarningData.AnySecondaryAxisMeasuredForceWarning = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorForceWarningData.AnySecondaryAxisMeasuredForceWarning = 1
          forceActuatorForceWarningData.SecondaryAxisMeasuredForceWarning[i] = 1
        else:
          forceActuatorForceWarningData.SecondaryAxisMeasuredForceWarning[i] = 0

      forceActuatorForceWarningData.AnyPrimaryAxisFollowingErrorWarning = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorForceWarningData.AnyPrimaryAxisFollowingErrorWarning = 1
          forceActuatorForceWarningData.PrimaryAxisFollowingErrorWarning[i] = 1
        else:
          forceActuatorForceWarningData.PrimaryAxisFollowingErrorWarning[i] = 0

      forceActuatorForceWarningData.AnySecondaryAxisFollowingErrorWarning = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorForceWarningData.AnySecondaryAxisFollowingErrorWarning = 1
          forceActuatorForceWarningData.SecondaryAxisFollowingErrorWarning[i] = 1
        else:
          forceActuatorForceWarningData.SecondaryAxisFollowingErrorWarning[i] = 0

      forceActuatorForceWarningData.priority = priority
      mgr.logEvent_ForceActuatorForceWarning(forceActuatorForceWarningData, priority)

    elif eventChoice == 2:

      forceActuatorInfoData = m1m3_logevent_ForceActuatorInfoC()
      forceActuatorInfoData.Timestamp = timestamp
      
      for i in range(0, 12):
        forceActuatorInfoData.XDataReferenceId[i] = random.randint(0, 256)

      for i in range(0, 100):
        forceActuatorInfoData.YDataReferenceId[i] = random.randint(0, 256)

      for i in range(0, 156):
        forceActuatorInfoData.ReferenceId[i] = random.randint(0, 256)
        forceActuatorInfoData.ZDataReferenceId[i] = random.randint(0, 256)
        forceActuatorInfoData.ActuatorType[i] = random.randint(0, 256)
        forceActuatorInfoData.ActuatorOrientation[i] = random.randint(0, 256)
        forceActuatorInfoData.ModbusSubnet[i] = random.randint(0, 256)
        forceActuatorInfoData.ModbusAddress[i] = random.randint(0, 256)
        forceActuatorInfoData.XPosition[i] = random.uniform(0.0, 10.0)
        forceActuatorInfoData.YPosition[i] = random.uniform(0.0, 10.0)
        forceActuatorInfoData.ZPosition[i] = random.uniform(0.0, 10.0)
        forceActuatorInfoData.ILCUniqueId[i] = random.randint(0, 9999)
        forceActuatorInfoData.ILCApplicationType[i] = random.randint(0, 3)
        forceActuatorInfoData.NetworkNodeType[i] = random.randint(0, 3)
        forceActuatorInfoData.ILCSelectedOptions[i] = random.randint(0, 3)
        forceActuatorInfoData.NetworkNodeOptions[i] = random.randint(0, 3)
        forceActuatorInfoData.MajorRevision[i] = random.randint(0, 3)
        forceActuatorInfoData.MinorRevision[i] = random.randint(0, 3)
        forceActuatorInfoData.ADCScanRate[i] = random.randint(0, 256)
        forceActuatorInfoData.MainPrimaryCylinderCoefficient[i] = random.uniform(0.0, 10.0)
        forceActuatorInfoData.MainSecondaryCylinderCoefficient[i] = random.uniform(0.0, 10.0)
        forceActuatorInfoData.MainPrimaryCylinderLoadCellOffset[i] = random.uniform(0.0, 10.0)
        forceActuatorInfoData.MainSecondaryCylinderLoadCellOffset[i] = random.uniform(0.0, 10.0)
        forceActuatorInfoData.MainPrimaryCylinderLoadCellSensitivity[i] = random.uniform(0.0, 10.0)
        forceActuatorInfoData.MainSecondaryCylinderLoadCellSensitivity[i] = random.uniform(0.0, 10.0)
        forceActuatorInfoData.BackupPrimaryCylinderCoefficient[i] = random.uniform(0.0, 10.0)
        forceActuatorInfoData.BackupSecondaryCylinderCoefficient[i] = random.uniform(0.0, 10.0)
        forceActuatorInfoData.BackupPrimaryCylinderLoadCellOffset[i] = random.uniform(0.0, 10.0)
        forceActuatorInfoData.BackupSecondaryCylinderLoadCellOffset[i] = random.uniform(0.0, 10.0)
        forceActuatorInfoData.BackupPrimaryCylinderLoadCellSensitivity[i] = random.uniform(0.0, 10.0)
        forceActuatorInfoData.BackupSecondaryCylinderLoadCellSensitivity[i] = random.uniform(0.0, 10.0)
        forceActuatorInfoData.MezzaninePrimaryCylinderGain[i] = random.uniform(0.0, 10.0)
        forceActuatorInfoData.MezzanineSecondaryCylinderGain[i] = random.uniform(0.0, 10.0)
        forceActuatorInfoData.MezzanineUniqueId[i] = random.randint(0, 9999)
        forceActuatorInfoData.MezzanineFirmwareType[i] = random.randint(0, 3)
        forceActuatorInfoData.MezzanineMajorRevision[i] = random.randint(0, 256)
        forceActuatorInfoData.MezzanineMinorRevision[i] = random.randint(0, 256)
        forceActuatorInfoData.priority = priority
        mgr.logEvent_ForceActuatorInfo(forceActuatorInfoData, priority)

    elif eventChoice == 3:

      forceActuatorStateData = m1m3_logevent_ForceActuatorStateC()
      forceActuatorStateData.Timestamp = timestamp
      for i in range(0, 156):
        forceActuatorStateData.ILCState[i] = random.randint(0, 12)
      forceActuatorStateData.SlewFlag = generateBoolean()
      forceActuatorStateData.StaticForcesApplied = generateBoolean()
      forceActuatorStateData.ElevationForcesApplied = generateBoolean()
      forceActuatorStateData.AzimuthForcesApplied = generateBoolean()
      forceActuatorStateData.ThermalForcesApplied = generateBoolean()
      forceActuatorStateData.OffsetForcesApplied = generateBoolean()
      forceActuatorStateData.AccelerationForcesApplied = generateBoolean()
      forceActuatorStateData.VelocityForcesApplied = generateBoolean()
      forceActuatorStateData.ActiveOpticForcesApplied = generateBoolean()
      forceActuatorStateData.AberrationForcesApplied = generateBoolean()
      forceActuatorStateData.BalanceForcesApplied = generateBoolean()
      forceActuatorStateData.SupportPercentage = random.uniform(0.0, 100.0)
      forceActuatorStateData.priority = priority
      mgr.logEvent_ForceActuatorState(forceActuatorStateData, priority)

    elif eventChoice == 4:
 
      forceActuatorWarningData = m1m3_logevent_ForceActuatorWarningC()
      forceActuatorWarningData.Timestamp = timestamp
      forceActuatorWarningData.AnyWarning = generateBoolean()

      forceActuatorWarningData.AnyMajorFault = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyMajorFault = 1
          forceActuatorWarningData.MajorFault[i] = 1
        else:
          forceActuatorWarningData.MajorFault[i] = 0

      forceActuatorWarningData.AnyMinorFault = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyMinorFault = 1
          forceActuatorWarningData.MinorFault[i] = 1
        else:
          forceActuatorWarningData.MinorFault[i] = 0

      forceActuatorWarningData.AnyFaultOverride = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyFaultOverride = 1
          forceActuatorWarningData.FaultOverride[i] = 1
        else:
          forceActuatorWarningData.FaultOverride[i] = 0

      forceActuatorWarningData.AnyMainCalibrationError = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyMainCalibrationError = 1
          forceActuatorWarningData.MainCalibrationError[i] = 1
        else:
          forceActuatorWarningData.MainCalibrationError[i] = 0

      forceActuatorWarningData.AnyBackupCalibrationError = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyBackupCalibrationError = 1
          forceActuatorWarningData.BackupCalibrationError[i] = 1
        else:
          forceActuatorWarningData.BackupCalibrationError[i] = 0

      forceActuatorWarningData.AnyMezzanineError = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyMezzanineError = 1
          forceActuatorWarningData.MezzanineError[i] = 1
        else:
          forceActuatorWarningData.MezzanineError[i] = 0

      forceActuatorWarningData.AnyMezzanineBootloaderActive= 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyMezzanineBootloaderActive = 1
          forceActuatorWarningData.MezzanineBootloaderActive[i] = 1
        else:
          forceActuatorWarningData.MezzanineBootloaderActive[i] = 0

      forceActuatorWarningData.AnyUniqueIdCRCError = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyUniqueIdCRCError = 1
          forceActuatorWarningData.UniqueIdCRCError[i] = 1
        else:
          forceActuatorWarningData.UniqueIdCRCError[i] = 0

      forceActuatorWarningData.AnyApplicationTypeMismatch= 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyApplicationTypeMismatch = 1
          forceActuatorWarningData.ApplicationTypeMismatch[i] = 1
        else:
          forceActuatorWarningData.ApplicationTypeMismatch[i] = 0

      forceActuatorWarningData.AnyApplicationMissing = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyApplicationMissing = 1
          forceActuatorWarningData.ApplicationMissing[i] = 1
        else:
          forceActuatorWarningData.ApplicationMissing[i] = 0

      forceActuatorWarningData.AnyApplicationCRCMismatch = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyApplicationCRCMismatch = 1
          forceActuatorWarningData.ApplicationCRCMismatch[i] = 1
        else:
          forceActuatorWarningData.ApplicationCRCMismatch[i] = 0

      forceActuatorWarningData.AnyOneWireMissing = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyOneWireMissing = 1
          forceActuatorWarningData.OneWireMissing[i] = 1
        else:
          forceActuatorWarningData.OneWireMissing[i] = 0

      forceActuatorWarningData.AnyOneWire1Mismatch = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyOneWire1Mismatch = 1
          forceActuatorWarningData.OneWire1Mismatch[i] = 1
        else:
          forceActuatorWarningData.OneWire1Mismatch[i] = 0

      forceActuatorWarningData.AnyOneWire2Mismatch = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyOneWire2Mismatch = 1
          forceActuatorWarningData.OneWire2Mismatch[i] = 1
        else:
          forceActuatorWarningData.OneWire2Mismatch[i] = 0

      forceActuatorWarningData.AnyWatchdogReset = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyWatchdogReset = 1
          forceActuatorWarningData.WatchdogReset[i] = 1
        else:
          forceActuatorWarningData.WatchdogReset[i] = 0

      forceActuatorWarningData.AnyBrownOut = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyBrownOut = 1
          forceActuatorWarningData.BrownOut[i] = 1
        else:
          forceActuatorWarningData.BrownOut[i] = 0

      forceActuatorWarningData.AnyEventTrapReset = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyEventTrapReset = 1
          forceActuatorWarningData.EventTrapReset[i] = 1
        else:
          forceActuatorWarningData.EventTrapReset[i] = 0

      forceActuatorWarningData.AnySSRPowerFault = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnySSRPowerFault = 1
          forceActuatorWarningData.SSRPowerFault[i] = 1
        else:
          forceActuatorWarningData.SSRPowerFault[i] = 0

      forceActuatorWarningData.AnyAuxPowerFault = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyAuxPowerFault = 1
          forceActuatorWarningData.AuxPowerFault[i] = 1
        else:
          forceActuatorWarningData.AuxPowerFault[i] = 0

      forceActuatorWarningData.AnyMezzaninePowerFault = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyMezzaninePowerFault = 1
          forceActuatorWarningData.MezzaninePowerFault[i] = 1
        else:
          forceActuatorWarningData.MezzaninePowerFault[i] = 0

      forceActuatorWarningData.AnyMezzanineCurrentAmp1Fault = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyMezzanineCurrentAmp1Fault = 1
          forceActuatorWarningData.MezzanineCurrentAmp1Fault[i] = 1
        else:
          forceActuatorWarningData.MezzanineCurrentAmp1Fault[i] = 0

      forceActuatorWarningData.AnyMezzanineCurrentAmp2Fault = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyMezzanineCurrentAmp2Fault = 1
          forceActuatorWarningData.MezzanineCurrentAmp2Fault[i] = 1
        else:
          forceActuatorWarningData.MezzanineCurrentAmp2Fault[i] = 0
          
      forceActuatorWarningData.AnyMezzanineUniqueIdCRCError = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyMezzanineUniqueIdCRCError = 1
          forceActuatorWarningData.MezzanineUniqueIdCRCError[i] = 1
        else:
          forceActuatorWarningData.MezzanineUniqueIdCRCError[i] = 0

      forceActuatorWarningData.AnyMezzanineMainCalibrationError = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyMezzanineMainCalibrationError = 1
          forceActuatorWarningData.MezzanineMainCalibrationError[i] = 1
        else:
          forceActuatorWarningData.MezzanineMainCalibrationError[i] = 0

      forceActuatorWarningData.AnyMezzanineBackupCalibrationError = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyMezzanineBackupCalibrationError = 1
          forceActuatorWarningData.MezzanineBackupCalibrationError[i] = 1
        else:
          forceActuatorWarningData.MezzanineBackupCalibrationError[i] = 0

      forceActuatorWarningData.AnyMezzanineEventTrapReset = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyMezzanineEventTrapReset = 1
          forceActuatorWarningData.MezzanineEventTrapReset[i] = 1
        else:
          forceActuatorWarningData.MezzanineEventTrapReset[i] = 0

      forceActuatorWarningData.AnyMezzanineApplicationMissing = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyMezzanineApplicationMissing = 1
          forceActuatorWarningData.MezzanineApplicationMissing[i] = 1
        else:
          forceActuatorWarningData.MezzanineApplicationMissing[i] = 0

      forceActuatorWarningData.AnyMezzanineApplicationCRCMismatch = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyMezzanineApplicationCRCMismatch = 1
          forceActuatorWarningData.MezzanineApplicationCRCMismatch[i] = 1
        else:
          forceActuatorWarningData.MezzanineApplicationCRCMismatch[i] = 0

      forceActuatorWarningData.AnyILCFault = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyILCFault = 1
          forceActuatorWarningData.ILCFault[i] = 1
        else:
          forceActuatorWarningData.ILCFault[i] = 0

      forceActuatorWarningData.AnyBroadcastCounterWarning = 0
      for i in range(0,156):
        if (generateBoolean() == 1):
          forceActuatorWarningData.AnyBroadcastCounterWarning = 1
          forceActuatorWarningData.BroadcastCounterWarning[i] = 1
        else:
          forceActuatorWarningData.BroadcastCounterWarning[i] = 0

        forceActuatorWarningData.priority = priority
        mgr.logEvent_ForceActuatorWarning(forceActuatorWarningData, priority)

    elif eventChoice == 5:
      pass

    elif eventChoice == 6:

      rejectedForcesData = m1m3_logevent_RejectedForcesC()
      rejectedForcesData.Timestamp = timestamp
      for i in range(0, 12):
        rejectedForcesData.XForces[i] = random.uniform(-1000.0, 1000.0)
        
      for i in range(0, 100):
        rejectedForcesData.YForces[i] = random.uniform(-1000.0, 1000.0)
        
      for i in range(0, 156):
        rejectedForcesData.ZForces[i] = random.uniform(-1000.0, 1000.0)

      rejectedForcesData.Fx = random.uniform(-1000.0, 1000.0)
      rejectedForcesData.Fy = random.uniform(-1000.0, 1000.0)
      rejectedForcesData.Fz = random.uniform(-1000.0, 1000.0)
      rejectedForcesData.Mx = random.uniform(-1000.0, 1000.0)
      rejectedForcesData.My = random.uniform(-1000.0, 1000.0)
      rejectedForcesData.Mz = random.uniform(-1000.0, 1000.0)
      rejectedForcesData.ForceMagnitude = random.uniform(-1000.0, 1000.0)
      rejectedForcesData.priority = priority
      mgr.logEvent_RejectedForces(rejectedForcesData, priority)

    time.sleep(random.randint(1, 20))
    event.wait(waittime)
  print("Force Actuator Events Thread shutdown complete.")

############################################################
# Generating Applied Forces Events for the Force Actuators
def generateAppliedForcesEvent(event, waittime):
  priority = 10
  while not event.isSet():
    d = datetime.today()
    timestamp = time.mktime(d.timetuple())

    appliedForcesData = m1m3_logevent_AppliedForcesC()
    appliedForcesData.Timestamp = timestamp
    for i in range(0, 12):
      appliedForcesData.XForces[i] = random.uniform(-1000.0, 1000.0)
        
    for i in range(0, 100):
      appliedForcesData.YForces[i] = random.uniform(-1000.0, 1000.0)
        
    for i in range(0, 156):
      appliedForcesData.ZForces[i] = random.uniform(-1000.0, 1000.0)

    appliedForcesData.Fx = random.uniform(-1000.0, 1000.0)
    appliedForcesData.Fy = random.uniform(-1000.0, 1000.0)
    appliedForcesData.Fz = random.uniform(-1000.0, 1000.0)
    appliedForcesData.Mx = random.uniform(-1000.0, 1000.0)
    appliedForcesData.My = random.uniform(-1000.0, 1000.0)
    appliedForcesData.Mz = random.uniform(-1000.0, 1000.0)
    appliedForcesData.ForceMagnitude = random.uniform(-1000.0, 1000.0)
    appliedForcesData.priority = priority
    mgr.logEvent_AppliedForces(appliedForcesData, priority)

    time.sleep(.02)
    event.wait(waittime)
  print("Applied Forces Events Thread shutdown complete.")

############################################################
# Generating Telemetry for the Force Actuators
def generateForceActuatorTelemetry(event, waittime):
  while not event.isSet():
    d = datetime.today()
    timestamp = time.mktime(d.timetuple())

    forceActuatorData = m1m3_ForceActuatorDataC()
    forceActuatorData.Timestamp = timestamp
    for i in range(0,156):
      forceActuatorData.PrimaryCylinderForce[i] = random.uniform(0.0, 99.0)
    for i in range(0,112):
      forceActuatorData.SecondaryCylinderForce[i] = random.uniform(0.0, 99.0)
    for i in range(0,12):
      forceActuatorData.XForce[i] = random.uniform(0.0, 99.0)
    for i in range(0,100):
      forceActuatorData.YForce[i] = random.uniform(0.0, 99.0)
    for i in range(0,156):
      forceActuatorData.ZForce[i] = random.uniform(0.0, 99.0)
    forceActuatorData.Fx = random.uniform(0.0, 99.0)
    forceActuatorData.Fy = random.uniform(0.0, 99.0)
    forceActuatorData.Fz = random.uniform(0.0, 99.0)
    forceActuatorData.Mx = random.uniform(0.0, 99.0)
    forceActuatorData.My = random.uniform(0.0, 99.0)
    forceActuatorData.Mz = random.uniform(0.0, 99.0)
    forceActuatorData.ForceMagnitude = random.uniform(0.0, 99.0)
    retval = mgr.putSample_ForceActuatorData(forceActuatorData)

    time.sleep(0.001)
    event.wait(waittime)

############################################################
# Generating Telemetry for the Gyro
def generateGyroTelemetry(event, waittime):

  sequenceNumber = 0
  while not event.isSet():
    d = datetime.today()
    timestamp = time.mktime(d.timetuple())
    if (sequenceNumber > 127):
      sequenceNumber = 0

    gyroData = m1m3_GyroDataC()
    gyroData.Timestamp = timestamp
    gyroData.AngularVelocityX = random.uniform(0.0, 360.0)
    gyroData.AngularVelocityY = random.uniform(0.0, 360.0)
    gyroData.AngularVelocityZ = random.uniform(0.0, 360.0)
    gyroData.SequenceNumber = sequenceNumber
    gyroData.Temperature = random.randint(-100, 100)
    retval = mgr.putSample_GyroData(gyroData)

    sequenceNumber = sequenceNumber + 1
    time.sleep(1)
    event.wait(waittime)

############################################################
# Generating Telemetery for the HardpointActuatorData topic
def generateHardpointActuatorDataTelemetry(event, waittime):
  while not event.isSet():
    d = datetime.today()
    timestamp = time.mktime(d.timetuple())

    hardpointActuatorData = m1m3_HardpointActuatorDataC()
    hardpointActuatorData.Timestamp = timestamp
    for i in range(0,6):
      hardpointActuatorData.StepsQueued[i]=i ** 2 + random.randint(0,99)
    for i in range(0,6):
      hardpointActuatorData.StepsCommanded[i]=i ** 2 + random.randint(0,99)
    for i in range(0,6):
      hardpointActuatorData.MeasuredForce[i]=i ** 2 + random.randint(0,99)
    for i in range(0,6):
      hardpointActuatorData.Encoder[i]=i ** 2 + random.randint(0,99)
    for i in range(0,6):
      hardpointActuatorData.Displacement[i]=i ** 2 + random.randint(0,99)
    hardpointActuatorData.Fx = random.uniform(0.0,99.0)
    hardpointActuatorData.Fy = random.uniform(0.0,99.0)
    hardpointActuatorData.Fz = random.uniform(0.0,99.0)
    hardpointActuatorData.Mx = random.uniform(0.0,99.0)
    hardpointActuatorData.My = random.uniform(0.0,99.0)
    hardpointActuatorData.Mz = random.uniform(0.0,99.0)
    hardpointActuatorData.ForceMagnitude = random.uniform(0.0,99.0)
    hardpointActuatorData.XPosition = random.uniform(0.0,99.0)
    hardpointActuatorData.YPosition = random.uniform(0.0,99.0)
    hardpointActuatorData.ZPosition = random.uniform(0.0,99.0)
    hardpointActuatorData.XRotation = random.uniform(0.0,99.0)
    hardpointActuatorData.YRotation = random.uniform(0.0,99.0)
    hardpointActuatorData.ZRotation = random.uniform(0.0,99.0)
    retval = mgr.putSample_HardpointActuatorData(hardpointActuatorData)
    time.sleep(0.1)
    event.wait(waittime)

############################################################
def generateHardpointEvents(event, waittime):
  while not event.isSet():
    d = datetime.today()
    timestamp = time.mktime(d.timetuple())
    priority = 10

    #randomly choose an event to issue
    eventChoice = random.randint(1,7)

    if eventChoice == 1:
      HardpointActuatorInfoData = m1m3_logevent_HardpointActuatorInfoC()
      HardpointActuatorInfoData.Timestamp = timestamp
      for i in range(0, 6):
        HardpointActuatorInfoData.ReferenceId[i] = random.randint(1, 99)
      for i in range(0, 6):
        HardpointActuatorInfoData.ReferencePosition[i] = random.randint(1, 99)
      for i in range(0, 6):
        HardpointActuatorInfoData.ModbusSubnet[i] = random.randint(1, 4)
      for i in range(0, 6):
        HardpointActuatorInfoData.ModbusAddress[i] = random.randint(0, 255)
      for i in range(0, 6):
        HardpointActuatorInfoData.XPosition[i] = random.uniform(0.0, 99.9)
      for i in range(0, 6):
        HardpointActuatorInfoData.YPosition[i] = random.uniform(0.0, 99.9)
      for i in range(0, 6):
        HardpointActuatorInfoData.ZPosition[i] = random.uniform(0.0, 99.9)
      for i in range(0, 6):
        HardpointActuatorInfoData.ILCUniqueId[i] = random.randint(1, 999999)
      for i in range(0, 6):
        HardpointActuatorInfoData.ILCApplicationType[i] = random.randint(1, 99)
      for i in range(0, 6):
        HardpointActuatorInfoData.NetworkNodeType[i] = random.randint(1, 99)
      for i in range(0, 6):
        HardpointActuatorInfoData.ILCSelectedOptions[i] = random.randint(1, 99)
      for i in range(0, 6):
        HardpointActuatorInfoData.NetworkNodeOptions[i] = random.randint(1, 99)
      for i in range(0, 6):
        HardpointActuatorInfoData.MajorRevision[i] = random.randint(1, 99)
      for i in range(0, 6):
        HardpointActuatorInfoData.MinorRevision[i] = random.randint(1, 99)
      for i in range(0, 6):
        HardpointActuatorInfoData.ADCScanRate[i] = random.randint(1, 99)
      for i in range(0, 6):
        HardpointActuatorInfoData.MainLoadCellCoefficient[i] = random.uniform(0.0, 99.9)
      for i in range(0, 6):
        HardpointActuatorInfoData.MainLoadCellOffset[i] = random.uniform(0.0, 99.9)
      for i in range(0, 6):
        HardpointActuatorInfoData.MainLoadCellSensitivity[i] = random.uniform(0.0, 99.9)
      for i in range(0, 6):
        HardpointActuatorInfoData.BackupLoadCellCoefficient[i] = random.uniform(0.0, 99.9)
      for i in range(0, 6):
        HardpointActuatorInfoData.BackupLoadCellOffset[i] = random.uniform(0.0, 99.9)
      for i in range(0, 6):
        HardpointActuatorInfoData.BackupLoadCellSensitivity[i] = random.uniform(0.0, 99.9)
      HardpointActuatorInfoData.priority = priority
      mgr.logEvent_HardpointActuatorInfo(HardpointActuatorInfoData, priority)

    elif eventChoice == 2:
      
      hardpointActuatorStateData = m1m3_logevent_HardpointActuatorStateC()
      hardpointActuatorStateData.Timestamp = timestamp
      for i in range(0, 6):
        hardpointActuatorStateData.ILCState[i] = random.randint(0,1)
      for i in range(0, 6):
        hardpointActuatorStateData.MotionState[i] = random.randint(0,1)
      hardpointActuatorStateData.priority = priority
      mgr.logEvent_HardpointActuatorState(hardpointActuatorStateData, priority)

    elif eventChoice == 3:

      hardpointActuatorWarningData = m1m3_logevent_HardpointActuatorWarningC()
      hardpointActuatorWarningData.Timestamp = timestamp

      hardpointActuatorWarningData.AnyWarning = 1

      hardpointActuatorWarningData.AnyMajorFault = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnyMajorFault = 1
          hardpointActuatorWarningData.MajorFault[i] = 1
        else:
          hardpointActuatorWarningData.MajorFault[i] = 0

      hardpointActuatorWarningData.AnyMinorFault = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnyMinorFault = 1
          hardpointActuatorWarningData.MinorFault[i] = 1
        else:
          hardpointActuatorWarningData.MinorFault[i] = 0

      hardpointActuatorWarningData.AnyFaultOverride = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnyFaultOverride = 1
          hardpointActuatorWarningData.FaultOverride[i] = 1
        else: 
          hardpointActuatorWarningData.FaultOverride[i] = 0

      hardpointActuatorWarningData.AnyMainCalibrationError = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnyMainCalibrationError = 1
          hardpointActuatorWarningData.MainCalibrationError[i] = 1
        else:
          hardpointActuatorWarningData.MainCalibrationError[i] = 0

      hardpointActuatorWarningData.AnyBackupCalibrationError = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnyBackupCalibrationError = 1
          hardpointActuatorWarningData.BackupCalibrationError[i] = 1
        else:
          hardpointActuatorWarningData.BackupCalibrationError[i] = 0

      hardpointActuatorWarningData.AnyLimitSwitch1Operated = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnyLimitSwitch1Operated = 1
          hardpointActuatorWarningData.LimitSwitch1Operated[i] = 1
        else:
          hardpointActuatorWarningData.LimitSwitch1Operated[i] = 0

      hardpointActuatorWarningData.AnyLimitSwitch2Operated = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnyLimitSwitch2Operated = 1
          hardpointActuatorWarningData.LimitSwitch2Operated[i] = 1
        else:
          hardpointActuatorWarningData.LimitSwitch2Operated[i] = 0

      hardpointActuatorWarningData.AnyUniqueIdCRCError = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnyUniqueIdCRCError = 1
          hardpointActuatorWarningData.UniqueIdCRCError[i] = 1
        else:
          hardpointActuatorWarningData.UniqueIdCRCError[i] = 0

      hardpointActuatorWarningData.AnyApplicationTypeMismatch = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnyApplicationTypeMismatch = 1
          hardpointActuatorWarningData.ApplicationTypeMismatch[i] = 1
        else:
          hardpointActuatorWarningData.ApplicationTypeMismatch[i] = 0

      hardpointActuatorWarningData.AnyApplicationMissing = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnyApplicationMissing = 1
          hardpointActuatorWarningData.ApplicationMissing[i] = 1
        else:
          hardpointActuatorWarningData.ApplicationMissing[i] = 0

      hardpointActuatorWarningData.AnyApplicationCRCMismatch = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnyApplicationCRCMismatch = 1
          hardpointActuatorWarningData.ApplicationCRCMismatch[i] = 1
        else:
          hardpointActuatorWarningData.ApplicationCRCMismatch[i] = 0

      hardpointActuatorWarningData.AnyOneWireMissing = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnyOneWireMissing = 1
          hardpointActuatorWarningData.OneWireMissing[i] = 1
        else:
          hardpointActuatorWarningData.OneWireMissing[i] = 0

      hardpointActuatorWarningData.AnyOneWire1Mismatch = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnyOneWire1Mismatch = 1
          hardpointActuatorWarningData.OneWire1Mismatch[i] = 1
        else:
          hardpointActuatorWarningData.OneWire1Mismatch[i] = 0

      hardpointActuatorWarningData.AnyOneWire2Mismatch = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnyOneWire2Mismatch = 1
          hardpointActuatorWarningData.OneWire2Mismatch[i] = 1
        else:
          hardpointActuatorWarningData.OneWire2Mismatch[i] = 0

      hardpointActuatorWarningData.AnyWatchdogReset = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnyWatchdogReset = 1
          hardpointActuatorWarningData.WatchdogReset[i] = 1
        else:
          hardpointActuatorWarningData.WatchdogReset[i] = 0

      hardpointActuatorWarningData.AnyBrownOut = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnyBrownOut = 1
          hardpointActuatorWarningData.BrownOut[i] = 1
        else:
          hardpointActuatorWarningData.BrownOut[i] = 0

      hardpointActuatorWarningData.AnyEventTrapReset = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnyEventTrapReset = 1
          hardpointActuatorWarningData.EventTrapReset[i] = 1
        else:
          hardpointActuatorWarningData.EventTrapReset[i] = 0

      hardpointActuatorWarningData.AnyMotorDriverFault = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnyMotorDriverFault = 1
          hardpointActuatorWarningData.MotorDriverFault[i] = 1
        else:
          hardpointActuatorWarningData.MotorDriverFault[i] = 0

      hardpointActuatorWarningData.AnySSRPowerFault = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnySSRPowerFault = 1
          hardpointActuatorWarningData.SSRPowerFault[i] = 1
        else:
          hardpointActuatorWarningData.SSRPowerFault[i] = 0

      hardpointActuatorWarningData.AnyAuxPowerFault = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnyAuxPowerFault = 1
          hardpointActuatorWarningData.AuxPowerFault[i] = 1
        else:
          hardpointActuatorWarningData.AuxPowerFault[i] = 0

      hardpointActuatorWarningData.AnySMCPowerFault = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnySMCPowerFault = 1
          hardpointActuatorWarningData.SMCPowerFault[i] = 1
        else:
          hardpointActuatorWarningData.SMCPowerFault[i] = 0

      hardpointActuatorWarningData.AnyILCFault = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnyILCFault = 1
          hardpointActuatorWarningData.ILCFault[i] = 1
        else:
          hardpointActuatorWarningData.ILCFault[i] = 0

      hardpointActuatorWarningData.AnyBroadcastCounterWarning = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointActuatorWarningData.AnyBroadcastCounterWarning = 1
          hardpointActuatorWarningData.BroadcastCounterWarning[i] = 1
        else:
          hardpointActuatorWarningData.BroadcastCounterWarning[i] = 0

      hardpointActuatorWarningData.priority = priority
      mgr.logEvent_HardpointActuatorWarning(hardpointActuatorWarningData, priority)

    elif eventChoice == 4:

      hardpointMonitorInfoData = m1m3_logevent_HardpointMonitorInfoC()
      hardpointMonitorInfoData.Timestamp = timestamp
      for i in range(0,6):
        hardpointMonitorInfoData.ReferenceId[i] = random.randint(1, 99)
      for i in range(0,6):
        hardpointMonitorInfoData.ModbusSubnet[i] = random.randint(1, 4)
      for i in range(0,6):
        hardpointMonitorInfoData.ModbusAddress[i] = random.randint(0, 255)
      for i in range(0,6):
        hardpointMonitorInfoData.ILCUniqueId[i] = random.randint(1, 99)
      for i in range(0,6):
        hardpointMonitorInfoData.ILCApplicationType[i] = random.randint(1, 99)
      for i in range(0,6):
        hardpointMonitorInfoData.NetworkNodeType[i] = random.randint(1, 99)
      for i in range(0,6):
        hardpointMonitorInfoData.MajorRevision[i] = random.randint(1, 99)
      for i in range(0,6):
        hardpointMonitorInfoData.MinorRevision[i] = random.randint(1, 99)
      for i in range(0,6):
        hardpointMonitorInfoData.MezzanineUniqueId[i] = random.randint(1, 99)
      for i in range(0,6):
        hardpointMonitorInfoData.MezzanineFirmwareType[i] = random.randint(1, 99)
      for i in range(0,6):
        hardpointMonitorInfoData.MezzanineMajorRevision[i] = random.randint(1, 99)
      for i in range(0,6):
        hardpointMonitorInfoData.MezzanineMinorRevision[i] = random.randint(1, 99)
      hardpointMonitorInfoData.priority = priority
      mgr.logEvent_HardpointMonitorInfo(hardpointMonitorInfoData, priority)

    elif eventChoice == 5:

      hardpointMonitorStateData = m1m3_logevent_HardpointMonitorStateC()
      hardpointMonitorStateData.Timestamp = timestamp
      for i in range(0,6):
        hardpointMonitorStateData.ILCState[i] = random.randint(1, 99)
      hardpointMonitorStateData.priority = priority
      mgr.logEvent_HardpointMonitorState(hardpointMonitorStateData, priority)

    else:

      mgr.salEvent("m1m3_logevent_HardpointMonitorWarning")
      hardpointMonitorWarninginData = m1m3_logevent_HardpointMonitorWarningC()
      hardpointMonitorWarninginData.Timestamp = timestamp
      hardpointMonitorWarninginData.AnyWarning = 1 

      hardpointMonitorWarninginData.AnyMajorFault = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyMajorFault = 1
          hardpointMonitorWarninginData.MajorFault[i] = 1
        else:
          hardpointMonitorWarninginData.MajorFault[i] = 0

      hardpointMonitorWarninginData.AnyMinorFault = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyMinorFault = 1
          hardpointMonitorWarninginData.MinorFault[i] =1
        else:
          hardpointMonitorWarninginData.MinorFault[i] = 0

      hardpointMonitorWarninginData.AnyFaultOverride = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyFaultOverride = 1
          hardpointMonitorWarninginData.FaultOverride[i] = 1
        else:
          hardpointMonitorWarninginData.FaultOverride[i] = 0

      hardpointMonitorWarninginData.AnyInstrumentError = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyInstrumentError = 1
          hardpointMonitorWarninginData.InstrumentError[i] = 1
        else:
          hardpointMonitorWarninginData.InstrumentError[i] = 0

      hardpointMonitorWarninginData.AnyMezzanineError = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyMezzanineError = 1
          hardpointMonitorWarninginData.MezzanineError[i] = 1
        else:
          hardpointMonitorWarninginData.MezzanineError[i] = 0

      hardpointMonitorWarninginData.AnyMezzanineBootloaderActive = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyMezzanineBootloaderActive = 1
          hardpointMonitorWarninginData.MezzanineBootloaderActive[i] = 1
        else:
          hardpointMonitorWarninginData.MezzanineBootloaderActive[i] = 0

      hardpointMonitorWarninginData.AnyUniqueIdCRCError = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyUniqueIdCRCError = 1
          hardpointMonitorWarninginData.UniqueIdCRCError[i] = 1
        else:
          hardpointMonitorWarninginData.UniqueIdCRCError[i] = 0

      hardpointMonitorWarninginData.AnyApplicationTypeMismatch = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyApplicationTypeMismatch = 1
          hardpointMonitorWarninginData.ApplicationTypeMismatch[i] = 1
        else:
          hardpointMonitorWarninginData.ApplicationTypeMismatch[i] = 0

      hardpointMonitorWarninginData.AnyApplicationMissing = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyApplicationMissing = 1
          hardpointMonitorWarninginData.ApplicationMissing[i] = 1
        else:
          hardpointMonitorWarninginData.ApplicationMissing[i] = 0

      hardpointMonitorWarninginData.AnyApplicationCRCMismatch = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyApplicationCRCMismatch = 1
          hardpointMonitorWarninginData.ApplicationCRCMismatch[i] = 1
        else:
          hardpointMonitorWarninginData.ApplicationCRCMismatch[i] = 0

      hardpointMonitorWarninginData.AnyOneWireMissing = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyOneWireMissing = 1
          hardpointMonitorWarninginData.OneWireMissing[i] = 1
        else:
          hardpointMonitorWarninginData.OneWireMissing[i] = 0

      hardpointMonitorWarninginData.AnyOneWire1Mismatch = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyOneWire1Mismatch = 1
          hardpointMonitorWarninginData.OneWire1Mismatch[i] = 1
        else:
          hardpointMonitorWarninginData.OneWire1Mismatch[i] = 0

      hardpointMonitorWarninginData.AnyOneWire2Mismatch = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyOneWire2Mismatch = 1
          hardpointMonitorWarninginData.OneWire2Mismatch[i] = 1

      hardpointMonitorWarninginData.AnyWatchdogReset = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyWatchdogReset = 1
          hardpointMonitorWarninginData.WatchdogReset[i] = 1
        else:
          hardpointMonitorWarninginData.WatchdogReset[i] = 0

      hardpointMonitorWarninginData.AnyBrownOut = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyBrownOut = 1
          hardpointMonitorWarninginData.BrownOut[i] = 1
        else:
          hardpointMonitorWarninginData.BrownOut[i] = 0

      hardpointMonitorWarninginData.AnyEventTrapReset = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyEventTrapReset = 1
          hardpointMonitorWarninginData.EventTrapReset[i] = 1
        else:
          hardpointMonitorWarninginData.EventTrapReset[i] = 0

      hardpointMonitorWarninginData.AnySSRPowerFault = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnySSRPowerFault = 1
          hardpointMonitorWarninginData.SSRPowerFault[i] = 1
        else:
          hardpointMonitorWarninginData.SSRPowerFault[i] = 0

      hardpointMonitorWarninginData.AnyAuxPowerFault = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyAuxPowerFault = 1
          hardpointMonitorWarninginData.AuxPowerFault[i] = 1
        else:
          hardpointMonitorWarninginData.AuxPowerFault[i] = 0

      hardpointMonitorWarninginData.AnyMezzanineS1AInterface1Fault = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyMezzanineS1AInterface1Fault = 1
          hardpointMonitorWarninginData.MezzanineS1AInterface1Fault[i] = 1
        else:
          hardpointMonitorWarninginData.MezzanineS1AInterface1Fault[i] = 0

      hardpointMonitorWarninginData.AnyMezzanineS1ALVDT1Fault = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyMezzanineS1ALVDT1Fault = 1
          hardpointMonitorWarninginData.MezzanineS1ALVDT1Fault[i] = 1
        else:
          hardpointMonitorWarninginData.MezzanineS1ALVDT1Fault[i] = 0

      hardpointMonitorWarninginData.AnyMezzanineS1AInterface2Fault = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyMezzanineS1AInterface2Fault = 1
          hardpointMonitorWarninginData.MezzanineS1AInterface2Fault[i] = 1
        else:
          hardpointMonitorWarninginData.MezzanineS1AInterface2Fault[i] = 0

      hardpointMonitorWarninginData.AnyMezzanineS1ALVDT2Fault = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyMezzanineS1ALVDT2Fault = 1
          hardpointMonitorWarninginData.MezzanineS1ALVDT2Fault[i] = 1
        else:
          hardpointMonitorWarninginData.MezzanineS1ALVDT2Fault[i] = 0
      
      hardpointMonitorWarninginData.AnyMezzanineUniqueIdCRCError = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyMezzanineUniqueIdCRCError = 1
          hardpointMonitorWarninginData.MezzanineUniqueIdCRCError[i] = 1
        else:
          hardpointMonitorWarninginData.MezzanineUniqueIdCRCError[i] = 0

      hardpointMonitorWarninginData.AnyMezzanineEventTrapReset = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyMezzanineEventTrapReset = 1
          hardpointMonitorWarninginData.MezzanineEventTrapReset[i] = 1
        else:
          hardpointMonitorWarninginData.MezzanineEventTrapReset[i] = 0

      hardpointMonitorWarninginData.AnyMezzanineDCPRS422ChipFault = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyMezzanineDCPRS422ChipFault = 1
          hardpointMonitorWarninginData.MezzanineDCPRS422ChipFault[i] = 1
        else:
          hardpointMonitorWarninginData.MezzanineDCPRS422ChipFault[i] = 0

      hardpointMonitorWarninginData.AnyMezzanineApplicationMissing = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyMezzanineApplicationMissing = 1
          hardpointMonitorWarninginData.MezzanineApplicationMissing[i] = 1
        else:
          hardpointMonitorWarninginData.MezzanineApplicationMissing[1] = 0

      hardpointMonitorWarninginData.AnyMezzanineApplicationCRCMismatch = 0
      for i in range(0,6):
        if (generateBoolean() == 1):
          hardpointMonitorWarninginData.AnyMezzanineApplicationCRCMismatch = 1
          hardpointMonitorWarninginData.MezzanineApplicationCRCMismatch[i] = 1
        else:
          hardpointMonitorWarninginData.MezzanineApplicationCRCMismatch[i] = 0

      hardpointMonitorWarninginData.priority = priority
      mgr.logEvent_HardpointMonitorWarning(hardpointMonitorWarninginData, priority)

    time.sleep(random.randint(1, 20))
    event.wait(waittime)

############################################################
def generateHardpointMonitorDataTelemetry(event, waittime):
  while not event.isSet():
    d = datetime.today()
    timestamp = time.mktime(d.timetuple())

    hardpointMonitorData = m1m3_HardpointMonitorDataC()
    hardpointMonitorData.Timestamp = timestamp
    for i in range(0,6):
      hardpointMonitorData.BreakawayLVDT[i] = i + random.uniform(0.0, 20.0)
    for i in range(0,6):
      hardpointMonitorData.DisplacementLVDT[i] = i + random.uniform(0.0, 20.0)
    for i in range(0,6):
      hardpointMonitorData.BreakawayPressure[i] = i + random.uniform(0.0, 20.0)
    for i in range(0,6):
      hardpointMonitorData.PressureSensor1[i] = i + random.uniform(0.0, 20.0)
    for i in range(0,6):
      hardpointMonitorData.PressureSensor2[i] = i + random.uniform(0.0, 20.0)
    for i in range(0,6):
      hardpointMonitorData.PressureSensor3[i] = i + random.uniform(0.0, 20.0)
    retval = mgr.putSample_HardpointMonitorData(hardpointMonitorData)

    time.sleep(0.1)
    event.wait(waittime)

############################################################
# Generating Inclinometer and IMS telemetry
def generateInclinometerAndIMSTelemetry(event, waittime) :
  # initialize variables
  dataVariable = 1.0
  direction = 1

  # Outside loop changes direction every time
  # Inside loop goes the current direction a number of iterations
  # neither variable is used.
  while not event.isSet():
    for indsideLoopCounter in range(10):
      d = datetime.today()
      timestamp = time.mktime(d.timetuple())

      # Inclinometer Data Publishing
      myInclinometerData = m1m3_InclinometerDataC()
      myInclinometerData.Timestamp = timestamp
      myInclinometerData.InclinometerAngle = dataVariable
      retval = mgr.putSample_InclinometerData(myInclinometerData)
      
      # Displacement Data Publishing.
      myDisplacementData = m1m3_IMSDataC()
      myDisplacementData.Timestamp = timestamp
      for rawSensorCounter in range(0,8):
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
      time.sleep(0.02)
    direction = direction * -1
    event.wait(waittime)
  print("IMS Thread shutdown complete.")

############################################################
# Generating the Interlock Status and Interlock Warning
# events.
def generateInterlockEvents(event, waittime):
  while not event.isSet():
    d = datetime.today()
    timestamp = time.mktime(d.timetuple())

    statusData = m1m3_logevent_InterlockStatusC()
    statusData.Timestamp=timestamp
    statusData.HeartbeatCommandedState=generateBoolean()
    statusData.HeartbeatOutputState=generateBoolean()
    statusData.priority=10
    priority=int(statusData.priority)
    mgr.logEvent_InterlockStatus(statusData, priority)

    warningData = m1m3_logevent_InterlockWarningC()
    warningData.Timestamp=timestamp
    warningData.AnyWarning=generateBoolean()
    warningData.HeartbeatStateOutputMismatch=generateBoolean()
    warningData.AuxPowerNetworksOff=generateBoolean()
    warningData.ThermalEquipmentOff=generateBoolean()
    warningData.AirSupplyOff=generateBoolean()
    warningData.TMAMotionStop=generateBoolean()
    warningData.GISHeartbeatLost=generateBoolean()
    warningData.CabinetDoorOpen=generateBoolean()
    warningData.priority=10
    priority=int(warningData.priority)
    mgr.logEvent_InterlockWarning(warningData, priority)

    time.sleep(0.5)
    event.wait(waittime)
  print("Interlock Thread shutdown complete.")

############################################################
# Power Telemetery
def generatePowerTelemetryEvents(event, waittime):
  priority = 10

  while not event.isSet():
    d = datetime.today()
    timestamp = time.mktime(d.timetuple())

    PIDData = m1m3_PIDDataC()
    PIDData.Timestamp = timestamp
    for i in range(0,6):
      PIDData.Setpoint[i] = i + random.uniform(0.0, 20.0)
    for i in range(0,6):
      PIDData.Measurement[i] = i + random.uniform(0.0, 20.0)
    for i in range(0,6):
      PIDData.Error[i] = i + random.uniform(0.0, 20.0)
    for i in range(0,6):
      PIDData.ErrorT1[i] = i + random.uniform(0.0, 20.0)
    for i in range(0,6):
      PIDData.ErrorT2[i] = i + random.uniform(0.0, 20.0)
    for i in range(0,6):
      PIDData.Control[i] = i + random.uniform(0.0, 20.0)
    for i in range(0,6):
      PIDData.ControlT1[i] = i + random.uniform(0.0, 20.0)
    for i in range(0,6):
      PIDData.ControlT2[i] = i + random.uniform(0.0, 20.0)
    retval = mgr.putSample_PIDData(PIDData)

    powerSupplyData = m1m3_PowerSupplyDataC()
    powerSupplyData.Timestamp = timestamp
    powerSupplyData.PowerNetworkACurrent = random.uniform(0.0, 20.0)
    powerSupplyData.PowerNetworkBCurrent = random.uniform(0.0, 20.0)
    powerSupplyData.PowerNetworkCCurrent = random.uniform(0.0, 20.0)
    powerSupplyData.PowerNetworkDCurrent = random.uniform(0.0, 20.0)
    powerSupplyData.LightPowerNetworkCurrent = random.uniform(0.0, 20.0)
    powerSupplyData.ControlsPowerNetworkCurrent = random.uniform(0.0, 20.0)
    retval = mgr.putSample_PowerSupplyData(powerSupplyData)

    PIDInfoData = m1m3_logevent_PIDInfoC()
    PIDInfoData.Timestamp = timestamp
    PIDInfoData.Timestep[0] = random.uniform(0.0, 20.0)
    PIDInfoData.Timestep[1] = random.uniform(0.0, 20.0)
    PIDInfoData.Timestep[2] = random.uniform(0.0, 20.0)
    PIDInfoData.Timestep[3] = random.uniform(0.0, 20.0)
    PIDInfoData.Timestep[4] = random.uniform(0.0, 20.0)
    PIDInfoData.Timestep[5] = random.uniform(0.0, 20.0)
    PIDInfoData.P[0] = random.uniform(0.0, 20.0)
    PIDInfoData.P[1] = random.uniform(0.0, 20.0)
    PIDInfoData.P[2] = random.uniform(0.0, 20.0)
    PIDInfoData.P[3] = random.uniform(0.0, 20.0)
    PIDInfoData.P[4] = random.uniform(0.0, 20.0)
    PIDInfoData.P[5] = random.uniform(0.0, 20.0)
    PIDInfoData.I[0] = random.uniform(0.0, 20.0)
    PIDInfoData.I[1] = random.uniform(0.0, 20.0)
    PIDInfoData.I[2] = random.uniform(0.0, 20.0)
    PIDInfoData.I[3] = random.uniform(0.0, 20.0)
    PIDInfoData.I[4] = random.uniform(0.0, 20.0)
    PIDInfoData.I[5] = random.uniform(0.0, 20.0)
    PIDInfoData.D[0] = random.uniform(0.0, 20.0)
    PIDInfoData.D[1] = random.uniform(0.0, 20.0)
    PIDInfoData.D[2] = random.uniform(0.0, 20.0)
    PIDInfoData.D[3] = random.uniform(0.0, 20.0)
    PIDInfoData.D[4] = random.uniform(0.0, 20.0)
    PIDInfoData.D[5] = random.uniform(0.0, 20.0)
    PIDInfoData.N[0] = random.uniform(0.0, 20.0)
    PIDInfoData.N[1] = random.uniform(0.0, 20.0)
    PIDInfoData.N[2] = random.uniform(0.0, 20.0)
    PIDInfoData.N[3] = random.uniform(0.0, 20.0)
    PIDInfoData.N[4] = random.uniform(0.0, 20.0)
    PIDInfoData.N[5] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedA[0] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedA[1] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedA[2] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedA[3] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedA[4] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedA[5] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedB[0] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedB[1] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedB[2] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedB[3] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedB[4] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedB[5] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedC[0] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedC[1] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedC[2] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedC[3] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedC[4] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedC[5] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedD[0] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedD[1] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedD[2] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedD[3] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedD[4] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedD[5] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedE[0] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedE[1] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedE[2] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedE[3] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedE[4] = random.uniform(0.0, 20.0)
    PIDInfoData.CalculatedE[5] = random.uniform(0.0, 20.0)
    PIDInfoData.priority = priority
    mgr.logEvent_PIDInfo(PIDInfoData, priority)

    powerStatusData = m1m3_logevent_PowerStatusC()
    powerStatusData.Timestamp = timestamp
    powerStatusData.PowerNetworkACommandedOn = generateBoolean()
    powerStatusData.PowerNetworkAOutputOn = generateBoolean()
    powerStatusData.PowerNetworkBCommandedOn = generateBoolean()
    powerStatusData.PowerNetworkBOutputOn = generateBoolean()
    powerStatusData.PowerNetworkCCommandedOn = generateBoolean()
    powerStatusData.PowerNetworkCOutputOn = generateBoolean()
    powerStatusData.PowerNetworkDCommandedOn = generateBoolean()
    powerStatusData.PowerNetworkDOutputOn = generateBoolean()
    powerStatusData.AuxPowerNetworkACommandedOn = generateBoolean()
    powerStatusData.AuxPowerNetworkAOutputOn = generateBoolean()
    powerStatusData.AuxPowerNetworkBCommandedOn = generateBoolean()
    powerStatusData.AuxPowerNetworkBOutputOn = generateBoolean()
    powerStatusData.AuxPowerNetworkCCommandedOn = generateBoolean()
    powerStatusData.AuxPowerNetworkCOutputOn = generateBoolean()
    powerStatusData.AuxPowerNetworkDCommandedOn = generateBoolean()
    powerStatusData.AuxPowerNetworkDOutputOn = generateBoolean()
    powerStatusData.priority = priority
    mgr.logEvent_PowerStatus(powerStatusData, priority)

    PowerWarningData = m1m3_logevent_PowerWarningC()
    PowerWarningData.Timestamp = timestamp
    PowerWarningData.AnyWarning = generateBoolean()
    PowerWarningData.PowerNetworkAOutputMismatch = generateBoolean()
    PowerWarningData.PowerNetworkBOutputMismatch = generateBoolean()
    PowerWarningData.PowerNetworkCOutputMismatch = generateBoolean()
    PowerWarningData.PowerNetworkDOutputMismatch = generateBoolean()
    PowerWarningData.AuxPowerNetworkAOutputMismatch = generateBoolean()
    PowerWarningData.AuxPowerNetworkBOutputMismatch = generateBoolean()
    PowerWarningData.AuxPowerNetworkCOutputMismatch = generateBoolean()
    PowerWarningData.AuxPowerNetworkDOutputMismatch = generateBoolean()
    PowerWarningData.priority = priority
    mgr.logEvent_PowerWarning(PowerWarningData, priority)

    time.sleep(random.randint(1, 5))
    event.wait(waittime)
  print("Power Thread shutdown complete.")

############################################################
# Outer Loop Telemetery
def generateOuterloopTelemetry(event, waittime):
  broadcastCounter = 0

  while not event.isSet():
    d = datetime.today()
    timestamp = time.mktime(d.timetuple())
    if (broadcastCounter > 255):
      broadcastCounter = 0

    outerloopData = m1m3_OuterLoopDataC()
    outerloopData.Timestamp = timestamp
    outerloopData.BroadcastCounter = broadcastCounter
    broadcastCounter = broadcastCounter + 1
    outerloopData.SlewFlag = generateBoolean()
    outerloopData.ExecutionTime = random.randint(0,99)

    retval = mgr.putSample_OuterLoopData(outerloopData)
    time.sleep(random.randint(1, 5))
    event.wait(waittime)

  print("Outerloop Thread shutdown complete.")

############################################################
# "Main Thread"
# Initialize Manager:
init(mgr)

# create and start all children
#########################
accelEvent = threading.Event()
accelThread = threading.Thread(name='AccelerometerTelemetry',
                             target=generateAccelTelemetry,
                             args=(accelEvent, 0.001))
accelThread.start()
#########################
airEvent = threading.Event()
airThread = threading.Thread(name='AirEvents',
                             target=generateAirEvents,
                             args=(airEvent, 0.001))
airThread.start()
#########################
commandEvent = threading.Event()
commandThread = threading.Thread(name='CommandProcessing',
                                 target=processCommands,
                                 args=(commandEvent, 0.001))
commandThread.start()
#########################
commandRejectionEvent = threading.Event()
commandRejectionThread = threading.Thread(name='CommandRejectionWarningEvent',
                                 target=generateCommandRejectionEvent,
                                 args=(commandRejectionEvent, 0.001))
commandRejectionThread.start()
#########################
errorCodeEvent = threading.Event()
errorCodeThread = threading.Thread(name='ErrorCodeEvent',
                             target=generateErrorCodeEvent,
                             args=(errorCodeEvent, 0.001))
errorCodeThread.start()
#########################
forceActuatorDataEvent = threading.Event()
forceActuatorDataThread = threading.Thread(name='ForceActuatorTelemetry',
                             target=generateForceActuatorTelemetry,
                             args=(forceActuatorDataEvent, 0.001))
forceActuatorDataThread.start()
#########################
appliedForcesEvent = threading.Event()
appliedForcesThread = threading.Thread(name='AppliedForcesEvent',
                             target=generateAppliedForcesEvent,
                             args=(appliedForcesEvent, 0.001))
appliedForcesThread.start()
#########################
forceActuatorEventsEvent = threading.Event()
forceActuatorEventsThread = threading.Thread(name='ForceActuatorEvents',
                             target=generateForceActuatorEvents,
                             args=(forceActuatorEventsEvent, 0.001))
forceActuatorEventsThread.start()
#########################
gyroEvent = threading.Event()
gyroThread = threading.Thread(name='GyroTelemetry',
                             target=generateGyroTelemetry,
                             args=(gyroEvent, 0.001))
gyroThread.start()
#########################
hardpointActEvent = threading.Event()
hardpointActThread = threading.Thread(name='HardpointActuatorTelemetry',
                                   target=generateHardpointActuatorDataTelemetry,
                                   args=(hardpointActEvent, 0.001))
hardpointActThread.start()
#########################
hardpointEventsEvent = threading.Event()
hardpointEventsThread = threading.Thread(name='HardpointEvents',
                                   target=generateHardpointEvents,
                                   args=(hardpointEventsEvent, 0.001))
hardpointEventsThread.start()
#########################
hardpointMonitorEvent = threading.Event()
hardpointMonitorThread = threading.Thread(name='HardpointMonitorTelemetry',
                                   target=generateHardpointMonitorDataTelemetry,
                                   args=(hardpointMonitorEvent, 0.001))
hardpointMonitorThread.start()
#########################
imsEvent = threading.Event()
imsThread = threading.Thread(name='InclinometerAndImsTelemetry',
                             target=generateInclinometerAndIMSTelemetry,
                             args=(imsEvent, 0.001))
imsThread.start()
#########################
interlockEvent = threading.Event()
interlockThread = threading.Thread(name='InterlockEvents',
                                   target=generateInterlockEvents,
                                   args=(interlockEvent, 0.001))
interlockThread.start()
#########################
powerEvent = threading.Event()
powerThread = threading.Thread(name='PowerTelemetryEvents',
                                   target=generatePowerTelemetryEvents,
                                   args=(powerEvent, 0.001))
powerThread.start()
#########################
outerloopEvent = threading.Event()
outerloopThread = threading.Thread(name='OuterloopTelemetry',
                                   target=generateOuterloopTelemetry,
                                   args=(outerloopEvent, 0.001))
outerloopThread.start()

# prompt user for stop, when 'stop' then stop.
while(True):
  stopEntry = input('Enter stop to stop: ')
  if (stopEntry == 'stop'):
    print("Shutting down threads.")
    accelEvent.set()
    airEvent.set()
    commandEvent.set()
    commandRejectionEvent.set()
    errorCodeEvent.set()
    forceActuatorDataEvent.set()
    appliedForcesEvent.set()
    forceActuatorEventsEvent.set()
    gyroEvent.set()
    hardpointActEvent.set()
    hardpointEventsEvent.set()
    hardpointMonitorEvent.set()
    imsEvent.set()
    interlockEvent.set()
    powerEvent.set()
    outerloopEvent.set()
    break
  else:
    print("I don't understand " + stopEntry)


print("All Threads told to shutdown.")
mgr.salShutdown()
print("SAL manager shutdown complete")
exit()



