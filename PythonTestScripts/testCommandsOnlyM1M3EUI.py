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

# current states used by M1M3 Support
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

  # Events
  logEvents = []
  logEvents.append("m1m3_logevent_SummaryState")
  logEvents.append("m1m3_logevent_DetailedState")

  # load all topics into the SAL manager
  for stateCommand in stateCommands:
    print("starting " + stateCommand)
    mgr.salProcessor(stateCommand)
  for hardpointCommand in hardpointCommands:
    print("starting " + hardpointCommand)
    mgr.salProcessor(hardpointCommand)
  for logEvent in logEvents:
    print("starting " + logEvent)
    mgr.salEvent(logEvent)

  print("Done Initializing")

############################################################
# returns 0 or 1 with a 5% chance of returning 1
def generateBoolean():
  return 1 if (random.randint(0,99) < 5) else 0 

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
    event.wait(waittime)
  print("Command Thread shutdown complete.")
        
def processHPEnableChaseCommand(event, waittime):

  enableHardpointChaseData = m1m3_command_EnableHardpointChaseC()
  print("m1m3 process HP Commands ready")

  while not event.isSet():

    #########################
    # check for enable hardpoint chase command
    cmdId = mgr.acceptCommand_EnableHardpointChase(enableHardpointChaseData)
    if cmdId > 0:
      print("Enable Hardpoint Chase ActuatorId = " + str(enableHardpointChaseData.HardpointActuator))
      time.sleep(0.001)
      mgr.ackCommand_EnableHardpointChase(cmdId, SAL__CMD_COMPLETE, 0, "Done : OK");

    event.wait(waittime)
  print("HP Enable Chase Command Thread shutdown complete.")

def processHPCommands(event, waittime):

  disableHardpointChaseData = m1m3_command_DisableHardpointChaseC()
  enableHardpointCorrectionsData = m1m3_command_EnableHardpointCorrectionsC()
  disableHardpointCorrectionsData = m1m3_command_DisableHardpointCorrectionsC()
  moveHardpointActuatorsData = m1m3_command_MoveHardpointActuatorsC()
  stopHardpointMotionData = m1m3_command_StopHardpointMotionC()
  positionM1M3Data = m1m3_command_PositionM1M3C()
  translateM1M3Data = m1m3_command_TranslateM1M3C()

  print("m1m3 process HP Commands ready")

  while not event.isSet():
  
    d = datetime.today()
    timestamp = time.mktime(d.timetuple())

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

    event.wait(waittime)
  print("Command Thread shutdown complete.")

############################################################
# "Main Thread"
# Initialize Manager:
init(mgr)

# create and start all children
#########################
commandEvent = threading.Event()
commandThread = threading.Thread(name='CommandProcessing',
                                 target=processCommands,
                                 args=(commandEvent, 0.001))
commandThread.start()
#########################
hpCommandEvent = threading.Event()
hpCommandThread = threading.Thread(name='HPCommandProcessing',
                                   target=processHPCommands,
                                   args=(hpCommandEvent, 0.001))
hpCommandThread.start()
#########################
hpEnableChaseCommandEvent = threading.Event()
hpEnableChaseCommandThread = threading.Thread(name='HPEnableChaseCommandProcessing',
                                              target=processHPEnableChaseCommand,
                                              args=(hpEnableChaseCommandEvent, 0.001))
hpEnableChaseCommandThread.start()

# prompt user for stop, when 'stop' then stop.
while(True):
  stopEntry = input('Enter stop to stop: ')
  if (stopEntry == 'stop'):
    print("Shutting down threads.")
    commandEvent.set()
    hpCommandEvent.set()
    hpEnableChaseCommandEvent.set()
    break
  else:
    print("I don't understand " + stopEntry)


print("All Threads told to shutdown.")
mgr.salShutdown()
print("SAL manager shutdown complete")
exit()



