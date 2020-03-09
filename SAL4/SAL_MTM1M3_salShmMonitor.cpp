
#include <sys/ipc.h>
#include <sys/shm.h>
#include "SAL_MTM1M3.h"
#include "SAL_m1m3C.h"

#define BUILD_FOR_LV
#include "SAL_MTM1M3_shmem.h"
#include "SAL_actors.h"

#define SAL__MTM1M3_accelerometerData_ACTOR    0
#define SAL__MTM1M3_ackcmd_ACTOR    1
#define SAL__MTM1M3_command_abort_ACTOR    2
#define SAL__MTM1M3_command_abortProfile_ACTOR    3
#define SAL__MTM1M3_command_abortRaiseM1M3_ACTOR    4
#define SAL__MTM1M3_command_applyAberrationForces_ACTOR    5
#define SAL__MTM1M3_command_applyAberrationForcesByBendingModes_ACTOR    6
#define SAL__MTM1M3_command_applyActiveOpticForces_ACTOR    7
#define SAL__MTM1M3_command_applyActiveOpticForcesByBendingModes_ACTOR    8
#define SAL__MTM1M3_command_applyOffsetForces_ACTOR    9
#define SAL__MTM1M3_command_applyOffsetForcesByMirrorForce_ACTOR    10
#define SAL__MTM1M3_command_clearAberrationForces_ACTOR    11
#define SAL__MTM1M3_command_clearActiveOpticForces_ACTOR    12
#define SAL__MTM1M3_command_clearOffsetForces_ACTOR    13
#define SAL__MTM1M3_command_disable_ACTOR    14
#define SAL__MTM1M3_command_disableHardpointChase_ACTOR    15
#define SAL__MTM1M3_command_disableHardpointCorrections_ACTOR    16
#define SAL__MTM1M3_command_enable_ACTOR    17
#define SAL__MTM1M3_command_enableHardpointChase_ACTOR    18
#define SAL__MTM1M3_command_enableHardpointCorrections_ACTOR    19
#define SAL__MTM1M3_command_enterControl_ACTOR    20
#define SAL__MTM1M3_command_enterEngineering_ACTOR    21
#define SAL__MTM1M3_command_exitControl_ACTOR    22
#define SAL__MTM1M3_command_exitEngineering_ACTOR    23
#define SAL__MTM1M3_command_lowerM1M3_ACTOR    24
#define SAL__MTM1M3_command_modbusTransmit_ACTOR    25
#define SAL__MTM1M3_command_moveHardpointActuators_ACTOR    26
#define SAL__MTM1M3_command_positionM1M3_ACTOR    27
#define SAL__MTM1M3_command_programILC_ACTOR    28
#define SAL__MTM1M3_command_raiseM1M3_ACTOR    29
#define SAL__MTM1M3_command_resetPID_ACTOR    30
#define SAL__MTM1M3_command_runMirrorForceProfile_ACTOR    31
#define SAL__MTM1M3_command_setLogLevel_ACTOR    32
#define SAL__MTM1M3_command_setSimulationMode_ACTOR    33
#define SAL__MTM1M3_command_setThermalSetpoint_ACTOR    34
#define SAL__MTM1M3_command_setValue_ACTOR    35
#define SAL__MTM1M3_command_shutdown_ACTOR    36
#define SAL__MTM1M3_command_standby_ACTOR    37
#define SAL__MTM1M3_command_start_ACTOR    38
#define SAL__MTM1M3_command_stopHardpointMotion_ACTOR    39
#define SAL__MTM1M3_command_testAir_ACTOR    40
#define SAL__MTM1M3_command_testForceActuator_ACTOR    41
#define SAL__MTM1M3_command_testHardpoint_ACTOR    42
#define SAL__MTM1M3_command_translateM1M3_ACTOR    43
#define SAL__MTM1M3_command_turnAirOff_ACTOR    44
#define SAL__MTM1M3_command_turnAirOn_ACTOR    45
#define SAL__MTM1M3_command_turnLightsOff_ACTOR    46
#define SAL__MTM1M3_command_turnLightsOn_ACTOR    47
#define SAL__MTM1M3_command_turnPowerOff_ACTOR    48
#define SAL__MTM1M3_command_turnPowerOn_ACTOR    49
#define SAL__MTM1M3_command_updatePID_ACTOR    50
#define SAL__MTM1M3_forceActuatorData_ACTOR    51
#define SAL__MTM1M3_gyroData_ACTOR    52
#define SAL__MTM1M3_hardpointActuatorData_ACTOR    53
#define SAL__MTM1M3_hardpointMonitorData_ACTOR    54
#define SAL__MTM1M3_imsData_ACTOR    55
#define SAL__MTM1M3_inclinometerData_ACTOR    56
#define SAL__MTM1M3_logevent_accelerometerWarning_ACTOR    57
#define SAL__MTM1M3_logevent_airSupplyStatus_ACTOR    58
#define SAL__MTM1M3_logevent_airSupplyWarning_ACTOR    59
#define SAL__MTM1M3_logevent_appliedAberrationForces_ACTOR    60
#define SAL__MTM1M3_logevent_appliedAccelerationForces_ACTOR    61
#define SAL__MTM1M3_logevent_appliedActiveOpticForces_ACTOR    62
#define SAL__MTM1M3_logevent_appliedAzimuthForces_ACTOR    63
#define SAL__MTM1M3_logevent_appliedBalanceForces_ACTOR    64
#define SAL__MTM1M3_logevent_appliedCylinderForces_ACTOR    65
#define SAL__MTM1M3_logevent_appliedElevationForces_ACTOR    66
#define SAL__MTM1M3_logevent_appliedForces_ACTOR    67
#define SAL__MTM1M3_logevent_appliedOffsetForces_ACTOR    68
#define SAL__MTM1M3_logevent_appliedSettingsMatchStart_ACTOR    69
#define SAL__MTM1M3_logevent_appliedStaticForces_ACTOR    70
#define SAL__MTM1M3_logevent_appliedThermalForces_ACTOR    71
#define SAL__MTM1M3_logevent_appliedVelocityForces_ACTOR    72
#define SAL__MTM1M3_logevent_cellLightStatus_ACTOR    73
#define SAL__MTM1M3_logevent_cellLightWarning_ACTOR    74
#define SAL__MTM1M3_logevent_commandRejectionWarning_ACTOR    75
#define SAL__MTM1M3_logevent_detailedState_ACTOR    76
#define SAL__MTM1M3_logevent_displacementSensorWarning_ACTOR    77
#define SAL__MTM1M3_logevent_errorCode_ACTOR    78
#define SAL__MTM1M3_logevent_forceActuatorForceWarning_ACTOR    79
#define SAL__MTM1M3_logevent_forceActuatorInfo_ACTOR    80
#define SAL__MTM1M3_logevent_forceActuatorState_ACTOR    81
#define SAL__MTM1M3_logevent_forceActuatorWarning_ACTOR    82
#define SAL__MTM1M3_logevent_forceSetpointWarning_ACTOR    83
#define SAL__MTM1M3_logevent_gyroWarning_ACTOR    84
#define SAL__MTM1M3_logevent_hardpointActuatorInfo_ACTOR    85
#define SAL__MTM1M3_logevent_hardpointActuatorState_ACTOR    86
#define SAL__MTM1M3_logevent_hardpointActuatorWarning_ACTOR    87
#define SAL__MTM1M3_logevent_hardpointMonitorInfo_ACTOR    88
#define SAL__MTM1M3_logevent_hardpointMonitorState_ACTOR    89
#define SAL__MTM1M3_logevent_hardpointMonitorWarning_ACTOR    90
#define SAL__MTM1M3_logevent_heartbeat_ACTOR    91
#define SAL__MTM1M3_logevent_ilcWarning_ACTOR    92
#define SAL__MTM1M3_logevent_inclinometerSensorWarning_ACTOR    93
#define SAL__MTM1M3_logevent_interlockStatus_ACTOR    94
#define SAL__MTM1M3_logevent_interlockWarning_ACTOR    95
#define SAL__MTM1M3_logevent_logLevel_ACTOR    96
#define SAL__MTM1M3_logevent_logMessage_ACTOR    97
#define SAL__MTM1M3_logevent_modbusResponse_ACTOR    98
#define SAL__MTM1M3_logevent_pidInfo_ACTOR    99
#define SAL__MTM1M3_logevent_powerStatus_ACTOR    100
#define SAL__MTM1M3_logevent_powerSupplyStatus_ACTOR    101
#define SAL__MTM1M3_logevent_powerWarning_ACTOR    102
#define SAL__MTM1M3_logevent_rejectedAberrationForces_ACTOR    103
#define SAL__MTM1M3_logevent_rejectedAccelerationForces_ACTOR    104
#define SAL__MTM1M3_logevent_rejectedActiveOpticForces_ACTOR    105
#define SAL__MTM1M3_logevent_rejectedAzimuthForces_ACTOR    106
#define SAL__MTM1M3_logevent_rejectedBalanceForces_ACTOR    107
#define SAL__MTM1M3_logevent_rejectedCylinderForces_ACTOR    108
#define SAL__MTM1M3_logevent_rejectedElevationForces_ACTOR    109
#define SAL__MTM1M3_logevent_rejectedForces_ACTOR    110
#define SAL__MTM1M3_logevent_rejectedOffsetForces_ACTOR    111
#define SAL__MTM1M3_logevent_rejectedStaticForces_ACTOR    112
#define SAL__MTM1M3_logevent_rejectedThermalForces_ACTOR    113
#define SAL__MTM1M3_logevent_rejectedVelocityForces_ACTOR    114
#define SAL__MTM1M3_logevent_settingVersions_ACTOR    115
#define SAL__MTM1M3_logevent_settingsApplied_ACTOR    116
#define SAL__MTM1M3_logevent_simulationMode_ACTOR    117
#define SAL__MTM1M3_logevent_softwareVersions_ACTOR    118
#define SAL__MTM1M3_logevent_summaryState_ACTOR    119
#define SAL__MTM1M3_outerLoopData_ACTOR    120
#define SAL__MTM1M3_pidData_ACTOR    121
#define SAL__MTM1M3_powerSupplyData_ACTOR    122

using namespace MTM1M3;

struct MTM1M3_commandC
{
      std::string	device;
      std::string	property;
      std::string	action;
      std::string	value;
      std::string	modifiers;

};
struct MTM1M3_logeventC
{
      std::string	message;

};


    int main (int argc, char *argv[]) {
      int status = 0;
      int lpriority = 0;
      int m1m3ID = 0;
      int ipollusecs = 100;
      int LVClient = 0;

      if (argc > 1) {
         sscanf(argv[1], "%d", &m1m3ID);
      }
      if (getenv("LSST_M1M3_LVPOLL") != NULL) {
         sscanf(getenv("LSST_M1M3_LVPOLL"),"%d",&ipollusecs);
      }
      shutdown_shmem = false;
      int actorIdx = 0;
      m1m3_shmem *m1m3_memIO;
      lShmId = shmget(m1m3_shmid + m1m3ID, shmSize , IPC_CREAT|0666);
      m1m3_memIO  = (m1m3_shmem *) shmat(lShmId, NULL, 0);
      SAL_MTM1M3 mgr[20];

       MTM1M3_accelerometerDataC *Incoming_m1m3_AccelerometerData  = new MTM1M3_accelerometerDataC;
       MTM1M3_accelerometerDataC *Outgoing_m1m3_AccelerometerData  = new MTM1M3_accelerometerDataC;

       MTM1M3_forceActuatorDataC *Incoming_m1m3_ForceActuatorData  = new MTM1M3_forceActuatorDataC;
       MTM1M3_forceActuatorDataC *Outgoing_m1m3_ForceActuatorData  = new MTM1M3_forceActuatorDataC;

       MTM1M3_gyroDataC *Incoming_m1m3_GyroData  = new MTM1M3_gyroDataC;
       MTM1M3_gyroDataC *Outgoing_m1m3_GyroData  = new MTM1M3_gyroDataC;

       MTM1M3_hardpointActuatorDataC *Incoming_m1m3_HardpointActuatorData  = new MTM1M3_hardpointActuatorDataC;
       MTM1M3_hardpointActuatorDataC *Outgoing_m1m3_HardpointActuatorData  = new MTM1M3_hardpointActuatorDataC;

       MTM1M3_hardpointMonitorDataC *Incoming_m1m3_HardpointMonitorData  = new MTM1M3_hardpointMonitorDataC;
       MTM1M3_hardpointMonitorDataC *Outgoing_m1m3_HardpointMonitorData  = new MTM1M3_hardpointMonitorDataC;

       MTM1M3_imsDataC *Incoming_m1m3_IMSData  = new MTM1M3_imsDataC;
       MTM1M3_imsDataC *Outgoing_m1m3_IMSData  = new MTM1M3_imsDataC;

       MTM1M3_inclinometerDataC *Incoming_m1m3_InclinometerData  = new MTM1M3_inclinometerDataC;
       MTM1M3_inclinometerDataC *Outgoing_m1m3_InclinometerData  = new MTM1M3_inclinometerDataC;

       MTM1M3_outerLoopDataC *Incoming_m1m3_OuterLoopData  = new MTM1M3_outerLoopDataC;
       MTM1M3_outerLoopDataC *Outgoing_m1m3_OuterLoopData  = new MTM1M3_outerLoopDataC;

       MTM1M3_pidDataC *Incoming_m1m3_PIDData  = new MTM1M3_pidDataC;
       MTM1M3_pidDataC *Outgoing_m1m3_PIDData  = new MTM1M3_pidDataC;

       MTM1M3_powerSupplyDataC *Incoming_m1m3_PowerSupplyData  = new MTM1M3_powerSupplyDataC;
       MTM1M3_powerSupplyDataC *Outgoing_m1m3_PowerSupplyData  = new MTM1M3_powerSupplyDataC;

       MTM1M3_ackcmdC *Incoming_m1m3_ackcmd  = new MTM1M3_ackcmdC;
       MTM1M3_ackcmdC *Outgoing_m1m3_ackcmd  = new MTM1M3_ackcmdC;

       MTM1M3_commandC *Incoming_m1m3_command  = new MTM1M3_commandC;
       MTM1M3_commandC *Outgoing_m1m3_command  = new MTM1M3_commandC;

       MTM1M3_command_abortProfileC *Incoming_m1m3_command_AbortProfile  = new MTM1M3_command_abortProfileC;
       MTM1M3_command_abortProfileC *Outgoing_m1m3_command_AbortProfile  = new MTM1M3_command_abortProfileC;

       MTM1M3_command_abortRaiseM1M3C *Incoming_m1m3_command_AbortRaiseM1M3  = new MTM1M3_command_abortRaiseM1M3C;
       MTM1M3_command_abortRaiseM1M3C *Outgoing_m1m3_command_AbortRaiseM1M3  = new MTM1M3_command_abortRaiseM1M3C;

       MTM1M3_command_applyAberrationForcesC *Incoming_m1m3_command_ApplyAberrationForces  = new MTM1M3_command_applyAberrationForcesC;
       MTM1M3_command_applyAberrationForcesC *Outgoing_m1m3_command_ApplyAberrationForces  = new MTM1M3_command_applyAberrationForcesC;

       MTM1M3_command_applyAberrationForcesByBendingModesC *Incoming_m1m3_command_ApplyAberrationForcesByBendingModes  = new MTM1M3_command_applyAberrationForcesByBendingModesC;
       MTM1M3_command_applyAberrationForcesByBendingModesC *Outgoing_m1m3_command_ApplyAberrationForcesByBendingModes  = new MTM1M3_command_applyAberrationForcesByBendingModesC;

       MTM1M3_command_applyActiveOpticForcesC *Incoming_m1m3_command_ApplyActiveOpticForces  = new MTM1M3_command_applyActiveOpticForcesC;
       MTM1M3_command_applyActiveOpticForcesC *Outgoing_m1m3_command_ApplyActiveOpticForces  = new MTM1M3_command_applyActiveOpticForcesC;

       MTM1M3_command_applyActiveOpticForcesByBendingModesC *Incoming_m1m3_command_ApplyActiveOpticForcesByBendingModes  = new MTM1M3_command_applyActiveOpticForcesByBendingModesC;
       MTM1M3_command_applyActiveOpticForcesByBendingModesC *Outgoing_m1m3_command_ApplyActiveOpticForcesByBendingModes  = new MTM1M3_command_applyActiveOpticForcesByBendingModesC;

       MTM1M3_command_applyOffsetForcesC *Incoming_m1m3_command_ApplyOffsetForces  = new MTM1M3_command_applyOffsetForcesC;
       MTM1M3_command_applyOffsetForcesC *Outgoing_m1m3_command_ApplyOffsetForces  = new MTM1M3_command_applyOffsetForcesC;

       MTM1M3_command_applyOffsetForcesByMirrorForceC *Incoming_m1m3_command_ApplyOffsetForcesByMirrorForce  = new MTM1M3_command_applyOffsetForcesByMirrorForceC;
       MTM1M3_command_applyOffsetForcesByMirrorForceC *Outgoing_m1m3_command_ApplyOffsetForcesByMirrorForce  = new MTM1M3_command_applyOffsetForcesByMirrorForceC;

       MTM1M3_command_clearAberrationForcesC *Incoming_m1m3_command_ClearAberrationForces  = new MTM1M3_command_clearAberrationForcesC;
       MTM1M3_command_clearAberrationForcesC *Outgoing_m1m3_command_ClearAberrationForces  = new MTM1M3_command_clearAberrationForcesC;

       MTM1M3_command_clearActiveOpticForcesC *Incoming_m1m3_command_ClearActiveOpticForces  = new MTM1M3_command_clearActiveOpticForcesC;
       MTM1M3_command_clearActiveOpticForcesC *Outgoing_m1m3_command_ClearActiveOpticForces  = new MTM1M3_command_clearActiveOpticForcesC;

       MTM1M3_command_clearOffsetForcesC *Incoming_m1m3_command_ClearOffsetForces  = new MTM1M3_command_clearOffsetForcesC;
       MTM1M3_command_clearOffsetForcesC *Outgoing_m1m3_command_ClearOffsetForces  = new MTM1M3_command_clearOffsetForcesC;

       MTM1M3_command_disableC *Incoming_m1m3_command_Disable  = new MTM1M3_command_disableC;
       MTM1M3_command_disableC *Outgoing_m1m3_command_Disable  = new MTM1M3_command_disableC;

       MTM1M3_command_disableHardpointChaseC *Incoming_m1m3_command_DisableHardpointChase  = new MTM1M3_command_disableHardpointChaseC;
       MTM1M3_command_disableHardpointChaseC *Outgoing_m1m3_command_DisableHardpointChase  = new MTM1M3_command_disableHardpointChaseC;

       MTM1M3_command_disableHardpointCorrectionsC *Incoming_m1m3_command_DisableHardpointCorrections  = new MTM1M3_command_disableHardpointCorrectionsC;
       MTM1M3_command_disableHardpointCorrectionsC *Outgoing_m1m3_command_DisableHardpointCorrections  = new MTM1M3_command_disableHardpointCorrectionsC;

       MTM1M3_command_enableC *Incoming_m1m3_command_Enable  = new MTM1M3_command_enableC;
       MTM1M3_command_enableC *Outgoing_m1m3_command_Enable  = new MTM1M3_command_enableC;

       MTM1M3_command_enableHardpointChaseC *Incoming_m1m3_command_EnableHardpointChase  = new MTM1M3_command_enableHardpointChaseC;
       MTM1M3_command_enableHardpointChaseC *Outgoing_m1m3_command_EnableHardpointChase  = new MTM1M3_command_enableHardpointChaseC;

       MTM1M3_command_enableHardpointCorrectionsC *Incoming_m1m3_command_EnableHardpointCorrections  = new MTM1M3_command_enableHardpointCorrectionsC;
       MTM1M3_command_enableHardpointCorrectionsC *Outgoing_m1m3_command_EnableHardpointCorrections  = new MTM1M3_command_enableHardpointCorrectionsC;

       MTM1M3_command_enterEngineeringC *Incoming_m1m3_command_EnterEngineering  = new MTM1M3_command_enterEngineeringC;
       MTM1M3_command_enterEngineeringC *Outgoing_m1m3_command_EnterEngineering  = new MTM1M3_command_enterEngineeringC;

       MTM1M3_command_exitEngineeringC *Incoming_m1m3_command_ExitEngineering  = new MTM1M3_command_exitEngineeringC;
       MTM1M3_command_exitEngineeringC *Outgoing_m1m3_command_ExitEngineering  = new MTM1M3_command_exitEngineeringC;

       MTM1M3_command_lowerM1M3C *Incoming_m1m3_command_LowerM1M3  = new MTM1M3_command_lowerM1M3C;
       MTM1M3_command_lowerM1M3C *Outgoing_m1m3_command_LowerM1M3  = new MTM1M3_command_lowerM1M3C;

       MTM1M3_command_moveHardpointActuatorsC *Incoming_m1m3_command_MoveHardpointActuators  = new MTM1M3_command_moveHardpointActuatorsC;
       MTM1M3_command_moveHardpointActuatorsC *Outgoing_m1m3_command_MoveHardpointActuators  = new MTM1M3_command_moveHardpointActuatorsC;

       MTM1M3_command_positionM1M3C *Incoming_m1m3_command_PositionM1M3  = new MTM1M3_command_positionM1M3C;
       MTM1M3_command_positionM1M3C *Outgoing_m1m3_command_PositionM1M3  = new MTM1M3_command_positionM1M3C;

       MTM1M3_command_programILCC *Incoming_m1m3_command_ProgramILC  = new MTM1M3_command_programILCC;
       MTM1M3_command_programILCC *Outgoing_m1m3_command_ProgramILC  = new MTM1M3_command_programILCC;

       MTM1M3_command_raiseM1M3C *Incoming_m1m3_command_RaiseM1M3  = new MTM1M3_command_raiseM1M3C;
       MTM1M3_command_raiseM1M3C *Outgoing_m1m3_command_RaiseM1M3  = new MTM1M3_command_raiseM1M3C;

       MTM1M3_command_resetPIDC *Incoming_m1m3_command_ResetPID  = new MTM1M3_command_resetPIDC;
       MTM1M3_command_resetPIDC *Outgoing_m1m3_command_ResetPID  = new MTM1M3_command_resetPIDC;

       MTM1M3_command_runMirrorForceProfileC *Incoming_m1m3_command_RunMirrorForceProfile  = new MTM1M3_command_runMirrorForceProfileC;
       MTM1M3_command_runMirrorForceProfileC *Outgoing_m1m3_command_RunMirrorForceProfile  = new MTM1M3_command_runMirrorForceProfileC;

       MTM1M3_command_setThermalSetpointC *Incoming_m1m3_command_SetThermalSetpoint  = new MTM1M3_command_setThermalSetpointC;
       MTM1M3_command_setThermalSetpointC *Outgoing_m1m3_command_SetThermalSetpoint  = new MTM1M3_command_setThermalSetpointC;

       MTM1M3_command_shutdownC *Incoming_m1m3_command_Shutdown  = new MTM1M3_command_shutdownC;
       MTM1M3_command_shutdownC *Outgoing_m1m3_command_Shutdown  = new MTM1M3_command_shutdownC;

       MTM1M3_command_standbyC *Incoming_m1m3_command_Standby  = new MTM1M3_command_standbyC;
       MTM1M3_command_standbyC *Outgoing_m1m3_command_Standby  = new MTM1M3_command_standbyC;

       MTM1M3_command_startC *Incoming_m1m3_command_Start  = new MTM1M3_command_startC;
       MTM1M3_command_startC *Outgoing_m1m3_command_Start  = new MTM1M3_command_startC;

       MTM1M3_command_stopHardpointMotionC *Incoming_m1m3_command_StopHardpointMotion  = new MTM1M3_command_stopHardpointMotionC;
       MTM1M3_command_stopHardpointMotionC *Outgoing_m1m3_command_StopHardpointMotion  = new MTM1M3_command_stopHardpointMotionC;

       MTM1M3_command_testAirC *Incoming_m1m3_command_TestAir  = new MTM1M3_command_testAirC;
       MTM1M3_command_testAirC *Outgoing_m1m3_command_TestAir  = new MTM1M3_command_testAirC;

       MTM1M3_command_testForceActuatorC *Incoming_m1m3_command_TestForceActuator  = new MTM1M3_command_testForceActuatorC;
       MTM1M3_command_testForceActuatorC *Outgoing_m1m3_command_TestForceActuator  = new MTM1M3_command_testForceActuatorC;

       MTM1M3_command_testHardpointC *Incoming_m1m3_command_TestHardpoint  = new MTM1M3_command_testHardpointC;
       MTM1M3_command_testHardpointC *Outgoing_m1m3_command_TestHardpoint  = new MTM1M3_command_testHardpointC;

       MTM1M3_command_translateM1M3C *Incoming_m1m3_command_TranslateM1M3  = new MTM1M3_command_translateM1M3C;
       MTM1M3_command_translateM1M3C *Outgoing_m1m3_command_TranslateM1M3  = new MTM1M3_command_translateM1M3C;

       MTM1M3_command_turnAirOffC *Incoming_m1m3_command_TurnAirOff  = new MTM1M3_command_turnAirOffC;
       MTM1M3_command_turnAirOffC *Outgoing_m1m3_command_TurnAirOff  = new MTM1M3_command_turnAirOffC;

       MTM1M3_command_turnAirOnC *Incoming_m1m3_command_TurnAirOn  = new MTM1M3_command_turnAirOnC;
       MTM1M3_command_turnAirOnC *Outgoing_m1m3_command_TurnAirOn  = new MTM1M3_command_turnAirOnC;

       MTM1M3_command_turnLightsOffC *Incoming_m1m3_command_TurnLightsOff  = new MTM1M3_command_turnLightsOffC;
       MTM1M3_command_turnLightsOffC *Outgoing_m1m3_command_TurnLightsOff  = new MTM1M3_command_turnLightsOffC;

       MTM1M3_command_turnLightsOnC *Incoming_m1m3_command_TurnLightsOn  = new MTM1M3_command_turnLightsOnC;
       MTM1M3_command_turnLightsOnC *Outgoing_m1m3_command_TurnLightsOn  = new MTM1M3_command_turnLightsOnC;

       MTM1M3_command_turnPowerOffC *Incoming_m1m3_command_TurnPowerOff  = new MTM1M3_command_turnPowerOffC;
       MTM1M3_command_turnPowerOffC *Outgoing_m1m3_command_TurnPowerOff  = new MTM1M3_command_turnPowerOffC;

       MTM1M3_command_turnPowerOnC *Incoming_m1m3_command_TurnPowerOn  = new MTM1M3_command_turnPowerOnC;
       MTM1M3_command_turnPowerOnC *Outgoing_m1m3_command_TurnPowerOn  = new MTM1M3_command_turnPowerOnC;

       MTM1M3_command_updatePIDC *Incoming_m1m3_command_UpdatePID  = new MTM1M3_command_updatePIDC;
       MTM1M3_command_updatePIDC *Outgoing_m1m3_command_UpdatePID  = new MTM1M3_command_updatePIDC;

       MTM1M3_logeventC *Incoming_m1m3_logevent  = new MTM1M3_logeventC;
       MTM1M3_logeventC *Outgoing_m1m3_logevent  = new MTM1M3_logeventC;

       MTM1M3_logevent_accelerometerWarningC *Incoming_m1m3_logevent_AccelerometerWarning  = new MTM1M3_logevent_accelerometerWarningC;
       MTM1M3_logevent_accelerometerWarningC *Outgoing_m1m3_logevent_AccelerometerWarning  = new MTM1M3_logevent_accelerometerWarningC;

       MTM1M3_logevent_airSupplyStatusC *Incoming_m1m3_logevent_AirSupplyStatus  = new MTM1M3_logevent_airSupplyStatusC;
       MTM1M3_logevent_airSupplyStatusC *Outgoing_m1m3_logevent_AirSupplyStatus  = new MTM1M3_logevent_airSupplyStatusC;

       MTM1M3_logevent_airSupplyWarningC *Incoming_m1m3_logevent_AirSupplyWarning  = new MTM1M3_logevent_airSupplyWarningC;
       MTM1M3_logevent_airSupplyWarningC *Outgoing_m1m3_logevent_AirSupplyWarning  = new MTM1M3_logevent_airSupplyWarningC;

       MTM1M3_logevent_appliedAberrationForcesC *Incoming_m1m3_logevent_AppliedAberrationForces  = new MTM1M3_logevent_appliedAberrationForcesC;
       MTM1M3_logevent_appliedAberrationForcesC *Outgoing_m1m3_logevent_AppliedAberrationForces  = new MTM1M3_logevent_appliedAberrationForcesC;

       MTM1M3_logevent_appliedAccelerationForcesC *Incoming_m1m3_logevent_AppliedAccelerationForces  = new MTM1M3_logevent_appliedAccelerationForcesC;
       MTM1M3_logevent_appliedAccelerationForcesC *Outgoing_m1m3_logevent_AppliedAccelerationForces  = new MTM1M3_logevent_appliedAccelerationForcesC;

       MTM1M3_logevent_appliedActiveOpticForcesC *Incoming_m1m3_logevent_AppliedActiveOpticForces  = new MTM1M3_logevent_appliedActiveOpticForcesC;
       MTM1M3_logevent_appliedActiveOpticForcesC *Outgoing_m1m3_logevent_AppliedActiveOpticForces  = new MTM1M3_logevent_appliedActiveOpticForcesC;

       MTM1M3_logevent_appliedAzimuthForcesC *Incoming_m1m3_logevent_AppliedAzimuthForces  = new MTM1M3_logevent_appliedAzimuthForcesC;
       MTM1M3_logevent_appliedAzimuthForcesC *Outgoing_m1m3_logevent_AppliedAzimuthForces  = new MTM1M3_logevent_appliedAzimuthForcesC;

       MTM1M3_logevent_appliedBalanceForcesC *Incoming_m1m3_logevent_AppliedBalanceForces  = new MTM1M3_logevent_appliedBalanceForcesC;
       MTM1M3_logevent_appliedBalanceForcesC *Outgoing_m1m3_logevent_AppliedBalanceForces  = new MTM1M3_logevent_appliedBalanceForcesC;

       MTM1M3_logevent_appliedCylinderForcesC *Incoming_m1m3_logevent_AppliedCylinderForces  = new MTM1M3_logevent_appliedCylinderForcesC;
       MTM1M3_logevent_appliedCylinderForcesC *Outgoing_m1m3_logevent_AppliedCylinderForces  = new MTM1M3_logevent_appliedCylinderForcesC;

       MTM1M3_logevent_appliedElevationForcesC *Incoming_m1m3_logevent_AppliedElevationForces  = new MTM1M3_logevent_appliedElevationForcesC;
       MTM1M3_logevent_appliedElevationForcesC *Outgoing_m1m3_logevent_AppliedElevationForces  = new MTM1M3_logevent_appliedElevationForcesC;

       MTM1M3_logevent_appliedForcesC *Incoming_m1m3_logevent_AppliedForces  = new MTM1M3_logevent_appliedForcesC;
       MTM1M3_logevent_appliedForcesC *Outgoing_m1m3_logevent_AppliedForces  = new MTM1M3_logevent_appliedForcesC;

       MTM1M3_logevent_appliedOffsetForcesC *Incoming_m1m3_logevent_AppliedOffsetForces  = new MTM1M3_logevent_appliedOffsetForcesC;
       MTM1M3_logevent_appliedOffsetForcesC *Outgoing_m1m3_logevent_AppliedOffsetForces  = new MTM1M3_logevent_appliedOffsetForcesC;

       MTM1M3_logevent_appliedSettingsMatchStartC *Incoming_m1m3_logevent_AppliedSettingsMatchStart  = new MTM1M3_logevent_appliedSettingsMatchStartC;
       MTM1M3_logevent_appliedSettingsMatchStartC *Outgoing_m1m3_logevent_AppliedSettingsMatchStart  = new MTM1M3_logevent_appliedSettingsMatchStartC;

       MTM1M3_logevent_appliedStaticForcesC *Incoming_m1m3_logevent_AppliedStaticForces  = new MTM1M3_logevent_appliedStaticForcesC;
       MTM1M3_logevent_appliedStaticForcesC *Outgoing_m1m3_logevent_AppliedStaticForces  = new MTM1M3_logevent_appliedStaticForcesC;

       MTM1M3_logevent_appliedThermalForcesC *Incoming_m1m3_logevent_AppliedThermalForces  = new MTM1M3_logevent_appliedThermalForcesC;
       MTM1M3_logevent_appliedThermalForcesC *Outgoing_m1m3_logevent_AppliedThermalForces  = new MTM1M3_logevent_appliedThermalForcesC;

       MTM1M3_logevent_appliedVelocityForcesC *Incoming_m1m3_logevent_AppliedVelocityForces  = new MTM1M3_logevent_appliedVelocityForcesC;
       MTM1M3_logevent_appliedVelocityForcesC *Outgoing_m1m3_logevent_AppliedVelocityForces  = new MTM1M3_logevent_appliedVelocityForcesC;

       MTM1M3_logevent_cellLightStatusC *Incoming_m1m3_logevent_CellLightStatus  = new MTM1M3_logevent_cellLightStatusC;
       MTM1M3_logevent_cellLightStatusC *Outgoing_m1m3_logevent_CellLightStatus  = new MTM1M3_logevent_cellLightStatusC;

       MTM1M3_logevent_cellLightWarningC *Incoming_m1m3_logevent_CellLightWarning  = new MTM1M3_logevent_cellLightWarningC;
       MTM1M3_logevent_cellLightWarningC *Outgoing_m1m3_logevent_CellLightWarning  = new MTM1M3_logevent_cellLightWarningC;

       MTM1M3_logevent_commandRejectionWarningC *Incoming_m1m3_logevent_CommandRejectionWarning  = new MTM1M3_logevent_commandRejectionWarningC;
       MTM1M3_logevent_commandRejectionWarningC *Outgoing_m1m3_logevent_CommandRejectionWarning  = new MTM1M3_logevent_commandRejectionWarningC;

       MTM1M3_logevent_detailedStateC *Incoming_m1m3_logevent_DetailedState  = new MTM1M3_logevent_detailedStateC;
       MTM1M3_logevent_detailedStateC *Outgoing_m1m3_logevent_DetailedState  = new MTM1M3_logevent_detailedStateC;

       MTM1M3_logevent_displacementSensorWarningC *Incoming_m1m3_logevent_DisplacementSensorWarning  = new MTM1M3_logevent_displacementSensorWarningC;
       MTM1M3_logevent_displacementSensorWarningC *Outgoing_m1m3_logevent_DisplacementSensorWarning  = new MTM1M3_logevent_displacementSensorWarningC;

       MTM1M3_logevent_errorCodeC *Incoming_m1m3_logevent_ErrorCode  = new MTM1M3_logevent_errorCodeC;
       MTM1M3_logevent_errorCodeC *Outgoing_m1m3_logevent_ErrorCode  = new MTM1M3_logevent_errorCodeC;

       MTM1M3_logevent_forceActuatorForceWarningC *Incoming_m1m3_logevent_ForceActuatorForceWarning  = new MTM1M3_logevent_forceActuatorForceWarningC;
       MTM1M3_logevent_forceActuatorForceWarningC *Outgoing_m1m3_logevent_ForceActuatorForceWarning  = new MTM1M3_logevent_forceActuatorForceWarningC;

       MTM1M3_logevent_forceActuatorInfoC *Incoming_m1m3_logevent_ForceActuatorInfo  = new MTM1M3_logevent_forceActuatorInfoC;
       MTM1M3_logevent_forceActuatorInfoC *Outgoing_m1m3_logevent_ForceActuatorInfo  = new MTM1M3_logevent_forceActuatorInfoC;

       MTM1M3_logevent_forceActuatorStateC *Incoming_m1m3_logevent_ForceActuatorState  = new MTM1M3_logevent_forceActuatorStateC;
       MTM1M3_logevent_forceActuatorStateC *Outgoing_m1m3_logevent_ForceActuatorState  = new MTM1M3_logevent_forceActuatorStateC;

       MTM1M3_logevent_forceActuatorWarningC *Incoming_m1m3_logevent_ForceActuatorWarning  = new MTM1M3_logevent_forceActuatorWarningC;
       MTM1M3_logevent_forceActuatorWarningC *Outgoing_m1m3_logevent_ForceActuatorWarning  = new MTM1M3_logevent_forceActuatorWarningC;

       MTM1M3_logevent_forceSetpointWarningC *Incoming_m1m3_logevent_ForceSetpointWarning  = new MTM1M3_logevent_forceSetpointWarningC;
       MTM1M3_logevent_forceSetpointWarningC *Outgoing_m1m3_logevent_ForceSetpointWarning  = new MTM1M3_logevent_forceSetpointWarningC;

       MTM1M3_logevent_gyroWarningC *Incoming_m1m3_logevent_GyroWarning  = new MTM1M3_logevent_gyroWarningC;
       MTM1M3_logevent_gyroWarningC *Outgoing_m1m3_logevent_GyroWarning  = new MTM1M3_logevent_gyroWarningC;

       MTM1M3_logevent_hardpointActuatorInfoC *Incoming_m1m3_logevent_HardpointActuatorInfo  = new MTM1M3_logevent_hardpointActuatorInfoC;
       MTM1M3_logevent_hardpointActuatorInfoC *Outgoing_m1m3_logevent_HardpointActuatorInfo  = new MTM1M3_logevent_hardpointActuatorInfoC;

       MTM1M3_logevent_hardpointActuatorStateC *Incoming_m1m3_logevent_HardpointActuatorState  = new MTM1M3_logevent_hardpointActuatorStateC;
       MTM1M3_logevent_hardpointActuatorStateC *Outgoing_m1m3_logevent_HardpointActuatorState  = new MTM1M3_logevent_hardpointActuatorStateC;

       MTM1M3_logevent_hardpointActuatorWarningC *Incoming_m1m3_logevent_HardpointActuatorWarning  = new MTM1M3_logevent_hardpointActuatorWarningC;
       MTM1M3_logevent_hardpointActuatorWarningC *Outgoing_m1m3_logevent_HardpointActuatorWarning  = new MTM1M3_logevent_hardpointActuatorWarningC;

       MTM1M3_logevent_hardpointMonitorInfoC *Incoming_m1m3_logevent_HardpointMonitorInfo  = new MTM1M3_logevent_hardpointMonitorInfoC;
       MTM1M3_logevent_hardpointMonitorInfoC *Outgoing_m1m3_logevent_HardpointMonitorInfo  = new MTM1M3_logevent_hardpointMonitorInfoC;

       MTM1M3_logevent_hardpointMonitorStateC *Incoming_m1m3_logevent_HardpointMonitorState  = new MTM1M3_logevent_hardpointMonitorStateC;
       MTM1M3_logevent_hardpointMonitorStateC *Outgoing_m1m3_logevent_HardpointMonitorState  = new MTM1M3_logevent_hardpointMonitorStateC;

       MTM1M3_logevent_hardpointMonitorWarningC *Incoming_m1m3_logevent_HardpointMonitorWarning  = new MTM1M3_logevent_hardpointMonitorWarningC;
       MTM1M3_logevent_hardpointMonitorWarningC *Outgoing_m1m3_logevent_HardpointMonitorWarning  = new MTM1M3_logevent_hardpointMonitorWarningC;

       MTM1M3_logevent_ilcWarningC *Incoming_m1m3_logevent_ILCWarning  = new MTM1M3_logevent_ilcWarningC;
       MTM1M3_logevent_ilcWarningC *Outgoing_m1m3_logevent_ILCWarning  = new MTM1M3_logevent_ilcWarningC;

       MTM1M3_logevent_inclinometerSensorWarningC *Incoming_m1m3_logevent_InclinometerSensorWarning  = new MTM1M3_logevent_inclinometerSensorWarningC;
       MTM1M3_logevent_inclinometerSensorWarningC *Outgoing_m1m3_logevent_InclinometerSensorWarning  = new MTM1M3_logevent_inclinometerSensorWarningC;

       MTM1M3_logevent_interlockStatusC *Incoming_m1m3_logevent_InterlockStatus  = new MTM1M3_logevent_interlockStatusC;
       MTM1M3_logevent_interlockStatusC *Outgoing_m1m3_logevent_InterlockStatus  = new MTM1M3_logevent_interlockStatusC;

       MTM1M3_logevent_interlockWarningC *Incoming_m1m3_logevent_InterlockWarning  = new MTM1M3_logevent_interlockWarningC;
       MTM1M3_logevent_interlockWarningC *Outgoing_m1m3_logevent_InterlockWarning  = new MTM1M3_logevent_interlockWarningC;

       MTM1M3_logevent_pidInfoC *Incoming_m1m3_logevent_PIDInfo  = new MTM1M3_logevent_pidInfoC;
       MTM1M3_logevent_pidInfoC *Outgoing_m1m3_logevent_PIDInfo  = new MTM1M3_logevent_pidInfoC;

       MTM1M3_logevent_powerStatusC *Incoming_m1m3_logevent_PowerStatus  = new MTM1M3_logevent_powerStatusC;
       MTM1M3_logevent_powerStatusC *Outgoing_m1m3_logevent_PowerStatus  = new MTM1M3_logevent_powerStatusC;

       MTM1M3_logevent_powerSupplyStatusC *Incoming_m1m3_logevent_PowerSupplyStatus  = new MTM1M3_logevent_powerSupplyStatusC;
       MTM1M3_logevent_powerSupplyStatusC *Outgoing_m1m3_logevent_PowerSupplyStatus  = new MTM1M3_logevent_powerSupplyStatusC;

       MTM1M3_logevent_powerWarningC *Incoming_m1m3_logevent_PowerWarning  = new MTM1M3_logevent_powerWarningC;
       MTM1M3_logevent_powerWarningC *Outgoing_m1m3_logevent_PowerWarning  = new MTM1M3_logevent_powerWarningC;

       MTM1M3_logevent_rejectedAberrationForcesC *Incoming_m1m3_logevent_RejectedAberrationForces  = new MTM1M3_logevent_rejectedAberrationForcesC;
       MTM1M3_logevent_rejectedAberrationForcesC *Outgoing_m1m3_logevent_RejectedAberrationForces  = new MTM1M3_logevent_rejectedAberrationForcesC;

       MTM1M3_logevent_rejectedAccelerationForcesC *Incoming_m1m3_logevent_RejectedAccelerationForces  = new MTM1M3_logevent_rejectedAccelerationForcesC;
       MTM1M3_logevent_rejectedAccelerationForcesC *Outgoing_m1m3_logevent_RejectedAccelerationForces  = new MTM1M3_logevent_rejectedAccelerationForcesC;

       MTM1M3_logevent_rejectedActiveOpticForcesC *Incoming_m1m3_logevent_RejectedActiveOpticForces  = new MTM1M3_logevent_rejectedActiveOpticForcesC;
       MTM1M3_logevent_rejectedActiveOpticForcesC *Outgoing_m1m3_logevent_RejectedActiveOpticForces  = new MTM1M3_logevent_rejectedActiveOpticForcesC;

       MTM1M3_logevent_rejectedAzimuthForcesC *Incoming_m1m3_logevent_RejectedAzimuthForces  = new MTM1M3_logevent_rejectedAzimuthForcesC;
       MTM1M3_logevent_rejectedAzimuthForcesC *Outgoing_m1m3_logevent_RejectedAzimuthForces  = new MTM1M3_logevent_rejectedAzimuthForcesC;

       MTM1M3_logevent_rejectedBalanceForcesC *Incoming_m1m3_logevent_RejectedBalanceForces  = new MTM1M3_logevent_rejectedBalanceForcesC;
       MTM1M3_logevent_rejectedBalanceForcesC *Outgoing_m1m3_logevent_RejectedBalanceForces  = new MTM1M3_logevent_rejectedBalanceForcesC;

       MTM1M3_logevent_rejectedCylinderForcesC *Incoming_m1m3_logevent_RejectedCylinderForces  = new MTM1M3_logevent_rejectedCylinderForcesC;
       MTM1M3_logevent_rejectedCylinderForcesC *Outgoing_m1m3_logevent_RejectedCylinderForces  = new MTM1M3_logevent_rejectedCylinderForcesC;

       MTM1M3_logevent_rejectedElevationForcesC *Incoming_m1m3_logevent_RejectedElevationForces  = new MTM1M3_logevent_rejectedElevationForcesC;
       MTM1M3_logevent_rejectedElevationForcesC *Outgoing_m1m3_logevent_RejectedElevationForces  = new MTM1M3_logevent_rejectedElevationForcesC;

       MTM1M3_logevent_rejectedForcesC *Incoming_m1m3_logevent_RejectedForces  = new MTM1M3_logevent_rejectedForcesC;
       MTM1M3_logevent_rejectedForcesC *Outgoing_m1m3_logevent_RejectedForces  = new MTM1M3_logevent_rejectedForcesC;

       MTM1M3_logevent_rejectedOffsetForcesC *Incoming_m1m3_logevent_RejectedOffsetForces  = new MTM1M3_logevent_rejectedOffsetForcesC;
       MTM1M3_logevent_rejectedOffsetForcesC *Outgoing_m1m3_logevent_RejectedOffsetForces  = new MTM1M3_logevent_rejectedOffsetForcesC;

       MTM1M3_logevent_rejectedStaticForcesC *Incoming_m1m3_logevent_RejectedStaticForces  = new MTM1M3_logevent_rejectedStaticForcesC;
       MTM1M3_logevent_rejectedStaticForcesC *Outgoing_m1m3_logevent_RejectedStaticForces  = new MTM1M3_logevent_rejectedStaticForcesC;

       MTM1M3_logevent_rejectedThermalForcesC *Incoming_m1m3_logevent_RejectedThermalForces  = new MTM1M3_logevent_rejectedThermalForcesC;
       MTM1M3_logevent_rejectedThermalForcesC *Outgoing_m1m3_logevent_RejectedThermalForces  = new MTM1M3_logevent_rejectedThermalForcesC;

       MTM1M3_logevent_rejectedVelocityForcesC *Incoming_m1m3_logevent_RejectedVelocityForces  = new MTM1M3_logevent_rejectedVelocityForcesC;
       MTM1M3_logevent_rejectedVelocityForcesC *Outgoing_m1m3_logevent_RejectedVelocityForces  = new MTM1M3_logevent_rejectedVelocityForcesC;

       MTM1M3_logevent_settingVersionsC *Incoming_m1m3_logevent_SettingVersions  = new MTM1M3_logevent_settingVersionsC;
       MTM1M3_logevent_settingVersionsC *Outgoing_m1m3_logevent_SettingVersions  = new MTM1M3_logevent_settingVersionsC;

       MTM1M3_logevent_settingsAppliedC *Incoming_m1m3_logevent_SettingsApplied  = new MTM1M3_logevent_settingsAppliedC;
       MTM1M3_logevent_settingsAppliedC *Outgoing_m1m3_logevent_SettingsApplied  = new MTM1M3_logevent_settingsAppliedC;

       MTM1M3_logevent_summaryStateC *Incoming_m1m3_logevent_SummaryState  = new MTM1M3_logevent_summaryStateC;
       MTM1M3_logevent_summaryStateC *Outgoing_m1m3_logevent_SummaryState  = new MTM1M3_logevent_summaryStateC;
//       MTM1M3::ackcmdSeq MTM1M3_ackcmdSeq;
      while ( !shutdown_shmem ) {
                     for (LVClient=0;LVClient<20;LVClient++) {
                      if (m1m3_memIO->client[LVClient].inUse && m1m3_memIO->client[LVClient].initialized == false) {
                          mgr[LVClient] = SAL_MTM1M3();
                          m1m3_memIO->client[LVClient].initialized = true;
                      }
                      if (m1m3_memIO->client[LVClient].inUse) {


       if (m1m3_memIO->client[LVClient].syncI_m1m3_AccelerometerData) {
          actorIdx = SAL__MTM1M3_accelerometerData_ACTOR;
          if (mgr[LVClient].actorReader(actorIdx) == false) {
             mgr[LVClient].salTelemetrySub(actorIdx);
             m1m3_memIO->client[LVClient].hasReader_m1m3_AccelerometerData = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_AccelerometerData == false ) {
            if ( m1m3_memIO->client[LVClient].skipOld_m1m3_AccelerometerData == true ) {
                mgr[LVClient].setMaxSamples(actorIdx,-1);
                status = mgr[LVClient].getSample_accelerometerData(Incoming_m1m3_AccelerometerData);
             } else {
                status = mgr[LVClient].getNextSample_accelerometerData(Incoming_m1m3_AccelerometerData);
             }
             if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_AccelerometerData.Timestamp=Incoming_m1m3_AccelerometerData->timestamp;
    for (int i=0;i<8;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_AccelerometerData.RawAccelerometer[i]=Incoming_m1m3_AccelerometerData->rawAccelerometer[i];}
    for (int i=0;i<8;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_AccelerometerData.Accelerometer[i]=Incoming_m1m3_AccelerometerData->accelerometer[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_AccelerometerData.AngularAccelerationX=Incoming_m1m3_AccelerometerData->angularAccelerationX;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_AccelerometerData.AngularAccelerationY=Incoming_m1m3_AccelerometerData->angularAccelerationY;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_AccelerometerData.AngularAccelerationZ=Incoming_m1m3_AccelerometerData->angularAccelerationZ;

                m1m3_memIO->client[LVClient].hasIncoming_m1m3_AccelerometerData = true;
             }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_AccelerometerData) {
          actorIdx = SAL__MTM1M3_accelerometerData_ACTOR;
          if (mgr[LVClient].actorWriter(actorIdx) == false) {
             mgr[LVClient].salTelemetryPub(actorIdx);
             m1m3_memIO->client[LVClient].hasWriter_m1m3_AccelerometerData = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_AccelerometerData ) {
           Outgoing_m1m3_AccelerometerData->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_AccelerometerData.Timestamp;
    for (int i=0;i<8;i++) {Outgoing_m1m3_AccelerometerData->rawAccelerometer[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_AccelerometerData.RawAccelerometer[i];}
    for (int i=0;i<8;i++) {Outgoing_m1m3_AccelerometerData->accelerometer[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_AccelerometerData.Accelerometer[i];}
           Outgoing_m1m3_AccelerometerData->angularAccelerationX=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_AccelerometerData.AngularAccelerationX;
           Outgoing_m1m3_AccelerometerData->angularAccelerationY=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_AccelerometerData.AngularAccelerationY;
           Outgoing_m1m3_AccelerometerData->angularAccelerationZ=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_AccelerometerData.AngularAccelerationZ;

          status = mgr[LVClient].putSample_accelerometerData(Outgoing_m1m3_AccelerometerData);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_AccelerometerData = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_ForceActuatorData) {
          actorIdx = SAL__MTM1M3_forceActuatorData_ACTOR;
          if (mgr[LVClient].actorReader(actorIdx) == false) {
             mgr[LVClient].salTelemetrySub(actorIdx);
             m1m3_memIO->client[LVClient].hasReader_m1m3_ForceActuatorData = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_ForceActuatorData == false ) {
            if ( m1m3_memIO->client[LVClient].skipOld_m1m3_ForceActuatorData == true ) {
                mgr[LVClient].setMaxSamples(actorIdx,-1);
                status = mgr[LVClient].getSample_forceActuatorData(Incoming_m1m3_ForceActuatorData);
             } else {
                status = mgr[LVClient].getNextSample_forceActuatorData(Incoming_m1m3_ForceActuatorData);
             }
             if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_ForceActuatorData.Timestamp=Incoming_m1m3_ForceActuatorData->timestamp;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_ForceActuatorData.PrimaryCylinderForce[i]=Incoming_m1m3_ForceActuatorData->primaryCylinderForce[i];}
    for (int i=0;i<112;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_ForceActuatorData.SecondaryCylinderForce[i]=Incoming_m1m3_ForceActuatorData->secondaryCylinderForce[i];}
    for (int i=0;i<12;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_ForceActuatorData.XForce[i]=Incoming_m1m3_ForceActuatorData->xForce[i];}
    for (int i=0;i<100;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_ForceActuatorData.YForce[i]=Incoming_m1m3_ForceActuatorData->yForce[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_ForceActuatorData.ZForce[i]=Incoming_m1m3_ForceActuatorData->zForce[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_ForceActuatorData.Fx=Incoming_m1m3_ForceActuatorData->fx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_ForceActuatorData.Fy=Incoming_m1m3_ForceActuatorData->fy;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_ForceActuatorData.Fz=Incoming_m1m3_ForceActuatorData->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_ForceActuatorData.Mx=Incoming_m1m3_ForceActuatorData->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_ForceActuatorData.My=Incoming_m1m3_ForceActuatorData->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_ForceActuatorData.Mz=Incoming_m1m3_ForceActuatorData->mz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_ForceActuatorData.ForceMagnitude=Incoming_m1m3_ForceActuatorData->forceMagnitude;

                m1m3_memIO->client[LVClient].hasIncoming_m1m3_ForceActuatorData = true;
             }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_ForceActuatorData) {
          actorIdx = SAL__MTM1M3_forceActuatorData_ACTOR;
          if (mgr[LVClient].actorWriter(actorIdx) == false) {
             mgr[LVClient].salTelemetryPub(actorIdx);
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ForceActuatorData = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_ForceActuatorData ) {
           Outgoing_m1m3_ForceActuatorData->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_ForceActuatorData.Timestamp;
    for (int i=0;i<156;i++) {Outgoing_m1m3_ForceActuatorData->primaryCylinderForce[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_ForceActuatorData.PrimaryCylinderForce[i];}
    for (int i=0;i<112;i++) {Outgoing_m1m3_ForceActuatorData->secondaryCylinderForce[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_ForceActuatorData.SecondaryCylinderForce[i];}
    for (int i=0;i<12;i++) {Outgoing_m1m3_ForceActuatorData->xForce[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_ForceActuatorData.XForce[i];}
    for (int i=0;i<100;i++) {Outgoing_m1m3_ForceActuatorData->yForce[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_ForceActuatorData.YForce[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_ForceActuatorData->zForce[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_ForceActuatorData.ZForce[i];}
           Outgoing_m1m3_ForceActuatorData->fx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_ForceActuatorData.Fx;
           Outgoing_m1m3_ForceActuatorData->fy=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_ForceActuatorData.Fy;
           Outgoing_m1m3_ForceActuatorData->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_ForceActuatorData.Fz;
           Outgoing_m1m3_ForceActuatorData->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_ForceActuatorData.Mx;
           Outgoing_m1m3_ForceActuatorData->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_ForceActuatorData.My;
           Outgoing_m1m3_ForceActuatorData->mz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_ForceActuatorData.Mz;
           Outgoing_m1m3_ForceActuatorData->forceMagnitude=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_ForceActuatorData.ForceMagnitude;

          status = mgr[LVClient].putSample_forceActuatorData(Outgoing_m1m3_ForceActuatorData);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_ForceActuatorData = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_GyroData) {
          actorIdx = SAL__MTM1M3_gyroData_ACTOR;
          if (mgr[LVClient].actorReader(actorIdx) == false) {
             mgr[LVClient].salTelemetrySub(actorIdx);
             m1m3_memIO->client[LVClient].hasReader_m1m3_GyroData = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_GyroData == false ) {
            if ( m1m3_memIO->client[LVClient].skipOld_m1m3_GyroData == true ) {
                mgr[LVClient].setMaxSamples(actorIdx,-1);
                status = mgr[LVClient].getSample_gyroData(Incoming_m1m3_GyroData);
             } else {
                status = mgr[LVClient].getNextSample_gyroData(Incoming_m1m3_GyroData);
             }
             if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_GyroData.Timestamp=Incoming_m1m3_GyroData->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_GyroData.AngularVelocityX=Incoming_m1m3_GyroData->angularVelocityX;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_GyroData.AngularVelocityY=Incoming_m1m3_GyroData->angularVelocityY;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_GyroData.AngularVelocityZ=Incoming_m1m3_GyroData->angularVelocityZ;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_GyroData.SequenceNumber=Incoming_m1m3_GyroData->sequenceNumber;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_GyroData.Temperature=Incoming_m1m3_GyroData->temperature;

                m1m3_memIO->client[LVClient].hasIncoming_m1m3_GyroData = true;
             }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_GyroData) {
          actorIdx = SAL__MTM1M3_gyroData_ACTOR;
          if (mgr[LVClient].actorWriter(actorIdx) == false) {
             mgr[LVClient].salTelemetryPub(actorIdx);
             m1m3_memIO->client[LVClient].hasWriter_m1m3_GyroData = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_GyroData ) {
           Outgoing_m1m3_GyroData->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_GyroData.Timestamp;
           Outgoing_m1m3_GyroData->angularVelocityX=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_GyroData.AngularVelocityX;
           Outgoing_m1m3_GyroData->angularVelocityY=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_GyroData.AngularVelocityY;
           Outgoing_m1m3_GyroData->angularVelocityZ=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_GyroData.AngularVelocityZ;
           Outgoing_m1m3_GyroData->sequenceNumber=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_GyroData.SequenceNumber;
           Outgoing_m1m3_GyroData->temperature=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_GyroData.Temperature;

          status = mgr[LVClient].putSample_gyroData(Outgoing_m1m3_GyroData);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_GyroData = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_HardpointActuatorData) {
          actorIdx = SAL__MTM1M3_hardpointActuatorData_ACTOR;
          if (mgr[LVClient].actorReader(actorIdx) == false) {
             mgr[LVClient].salTelemetrySub(actorIdx);
             m1m3_memIO->client[LVClient].hasReader_m1m3_HardpointActuatorData = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_HardpointActuatorData == false ) {
            if ( m1m3_memIO->client[LVClient].skipOld_m1m3_HardpointActuatorData == true ) {
                mgr[LVClient].setMaxSamples(actorIdx,-1);
                status = mgr[LVClient].getSample_hardpointActuatorData(Incoming_m1m3_HardpointActuatorData);
             } else {
                status = mgr[LVClient].getNextSample_hardpointActuatorData(Incoming_m1m3_HardpointActuatorData);
             }
             if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointActuatorData.Timestamp=Incoming_m1m3_HardpointActuatorData->timestamp;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointActuatorData.StepsQueued[i]=Incoming_m1m3_HardpointActuatorData->stepsQueued[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointActuatorData.StepsCommanded[i]=Incoming_m1m3_HardpointActuatorData->stepsCommanded[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointActuatorData.MeasuredForce[i]=Incoming_m1m3_HardpointActuatorData->measuredForce[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointActuatorData.Encoder[i]=Incoming_m1m3_HardpointActuatorData->encoder[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointActuatorData.Displacement[i]=Incoming_m1m3_HardpointActuatorData->displacement[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointActuatorData.Fx=Incoming_m1m3_HardpointActuatorData->fx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointActuatorData.Fy=Incoming_m1m3_HardpointActuatorData->fy;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointActuatorData.Fz=Incoming_m1m3_HardpointActuatorData->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointActuatorData.Mx=Incoming_m1m3_HardpointActuatorData->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointActuatorData.My=Incoming_m1m3_HardpointActuatorData->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointActuatorData.Mz=Incoming_m1m3_HardpointActuatorData->mz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointActuatorData.ForceMagnitude=Incoming_m1m3_HardpointActuatorData->forceMagnitude;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointActuatorData.XPosition=Incoming_m1m3_HardpointActuatorData->xPosition;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointActuatorData.YPosition=Incoming_m1m3_HardpointActuatorData->yPosition;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointActuatorData.ZPosition=Incoming_m1m3_HardpointActuatorData->zPosition;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointActuatorData.XRotation=Incoming_m1m3_HardpointActuatorData->xRotation;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointActuatorData.YRotation=Incoming_m1m3_HardpointActuatorData->yRotation;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointActuatorData.ZRotation=Incoming_m1m3_HardpointActuatorData->zRotation;

                m1m3_memIO->client[LVClient].hasIncoming_m1m3_HardpointActuatorData = true;
             }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_HardpointActuatorData) {
          actorIdx = SAL__MTM1M3_hardpointActuatorData_ACTOR;
          if (mgr[LVClient].actorWriter(actorIdx) == false) {
             mgr[LVClient].salTelemetryPub(actorIdx);
             m1m3_memIO->client[LVClient].hasWriter_m1m3_HardpointActuatorData = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_HardpointActuatorData ) {
           Outgoing_m1m3_HardpointActuatorData->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointActuatorData.Timestamp;
    for (int i=0;i<6;i++) {Outgoing_m1m3_HardpointActuatorData->stepsQueued[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointActuatorData.StepsQueued[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_HardpointActuatorData->stepsCommanded[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointActuatorData.StepsCommanded[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_HardpointActuatorData->measuredForce[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointActuatorData.MeasuredForce[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_HardpointActuatorData->encoder[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointActuatorData.Encoder[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_HardpointActuatorData->displacement[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointActuatorData.Displacement[i];}
           Outgoing_m1m3_HardpointActuatorData->fx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointActuatorData.Fx;
           Outgoing_m1m3_HardpointActuatorData->fy=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointActuatorData.Fy;
           Outgoing_m1m3_HardpointActuatorData->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointActuatorData.Fz;
           Outgoing_m1m3_HardpointActuatorData->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointActuatorData.Mx;
           Outgoing_m1m3_HardpointActuatorData->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointActuatorData.My;
           Outgoing_m1m3_HardpointActuatorData->mz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointActuatorData.Mz;
           Outgoing_m1m3_HardpointActuatorData->forceMagnitude=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointActuatorData.ForceMagnitude;
           Outgoing_m1m3_HardpointActuatorData->xPosition=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointActuatorData.XPosition;
           Outgoing_m1m3_HardpointActuatorData->yPosition=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointActuatorData.YPosition;
           Outgoing_m1m3_HardpointActuatorData->zPosition=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointActuatorData.ZPosition;
           Outgoing_m1m3_HardpointActuatorData->xRotation=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointActuatorData.XRotation;
           Outgoing_m1m3_HardpointActuatorData->yRotation=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointActuatorData.YRotation;
           Outgoing_m1m3_HardpointActuatorData->zRotation=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointActuatorData.ZRotation;

          status = mgr[LVClient].putSample_hardpointActuatorData(Outgoing_m1m3_HardpointActuatorData);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_HardpointActuatorData = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_HardpointMonitorData) {
          actorIdx = SAL__MTM1M3_hardpointMonitorData_ACTOR;
          if (mgr[LVClient].actorReader(actorIdx) == false) {
             mgr[LVClient].salTelemetrySub(actorIdx);
             m1m3_memIO->client[LVClient].hasReader_m1m3_HardpointMonitorData = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_HardpointMonitorData == false ) {
            if ( m1m3_memIO->client[LVClient].skipOld_m1m3_HardpointMonitorData == true ) {
                mgr[LVClient].setMaxSamples(actorIdx,-1);
                status = mgr[LVClient].getSample_hardpointMonitorData(Incoming_m1m3_HardpointMonitorData);
             } else {
                status = mgr[LVClient].getNextSample_hardpointMonitorData(Incoming_m1m3_HardpointMonitorData);
             }
             if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointMonitorData.Timestamp=Incoming_m1m3_HardpointMonitorData->timestamp;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointMonitorData.BreakawayLVDT[i]=Incoming_m1m3_HardpointMonitorData->breakawayLVDT[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointMonitorData.DisplacementLVDT[i]=Incoming_m1m3_HardpointMonitorData->displacementLVDT[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointMonitorData.BreakawayPressure[i]=Incoming_m1m3_HardpointMonitorData->breakawayPressure[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointMonitorData.PressureSensor1[i]=Incoming_m1m3_HardpointMonitorData->pressureSensor1[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointMonitorData.PressureSensor2[i]=Incoming_m1m3_HardpointMonitorData->pressureSensor2[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_HardpointMonitorData.PressureSensor3[i]=Incoming_m1m3_HardpointMonitorData->pressureSensor3[i];}

                m1m3_memIO->client[LVClient].hasIncoming_m1m3_HardpointMonitorData = true;
             }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_HardpointMonitorData) {
          actorIdx = SAL__MTM1M3_hardpointMonitorData_ACTOR;
          if (mgr[LVClient].actorWriter(actorIdx) == false) {
             mgr[LVClient].salTelemetryPub(actorIdx);
             m1m3_memIO->client[LVClient].hasWriter_m1m3_HardpointMonitorData = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_HardpointMonitorData ) {
           Outgoing_m1m3_HardpointMonitorData->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointMonitorData.Timestamp;
    for (int i=0;i<6;i++) {Outgoing_m1m3_HardpointMonitorData->breakawayLVDT[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointMonitorData.BreakawayLVDT[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_HardpointMonitorData->displacementLVDT[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointMonitorData.DisplacementLVDT[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_HardpointMonitorData->breakawayPressure[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointMonitorData.BreakawayPressure[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_HardpointMonitorData->pressureSensor1[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointMonitorData.PressureSensor1[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_HardpointMonitorData->pressureSensor2[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointMonitorData.PressureSensor2[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_HardpointMonitorData->pressureSensor3[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_HardpointMonitorData.PressureSensor3[i];}

          status = mgr[LVClient].putSample_hardpointMonitorData(Outgoing_m1m3_HardpointMonitorData);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_HardpointMonitorData = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_IMSData) {
          actorIdx = SAL__MTM1M3_imsData_ACTOR;
          if (mgr[LVClient].actorReader(actorIdx) == false) {
             mgr[LVClient].salTelemetrySub(actorIdx);
             m1m3_memIO->client[LVClient].hasReader_m1m3_IMSData = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_IMSData == false ) {
            if ( m1m3_memIO->client[LVClient].skipOld_m1m3_IMSData == true ) {
                mgr[LVClient].setMaxSamples(actorIdx,-1);
                status = mgr[LVClient].getSample_imsData(Incoming_m1m3_IMSData);
             } else {
                status = mgr[LVClient].getNextSample_imsData(Incoming_m1m3_IMSData);
             }
             if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_IMSData.Timestamp=Incoming_m1m3_IMSData->timestamp;
    for (int i=0;i<8;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_IMSData.RawSensorData[i]=Incoming_m1m3_IMSData->rawSensorData[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_IMSData.XPosition=Incoming_m1m3_IMSData->xPosition;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_IMSData.YPosition=Incoming_m1m3_IMSData->yPosition;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_IMSData.ZPosition=Incoming_m1m3_IMSData->zPosition;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_IMSData.XRotation=Incoming_m1m3_IMSData->xRotation;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_IMSData.YRotation=Incoming_m1m3_IMSData->yRotation;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_IMSData.ZRotation=Incoming_m1m3_IMSData->zRotation;

                m1m3_memIO->client[LVClient].hasIncoming_m1m3_IMSData = true;
             }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_IMSData) {
          actorIdx = SAL__MTM1M3_imsData_ACTOR;
          if (mgr[LVClient].actorWriter(actorIdx) == false) {
             mgr[LVClient].salTelemetryPub(actorIdx);
             m1m3_memIO->client[LVClient].hasWriter_m1m3_IMSData = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_IMSData ) {
           Outgoing_m1m3_IMSData->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_IMSData.Timestamp;
    for (int i=0;i<8;i++) {Outgoing_m1m3_IMSData->rawSensorData[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_IMSData.RawSensorData[i];}
           Outgoing_m1m3_IMSData->xPosition=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_IMSData.XPosition;
           Outgoing_m1m3_IMSData->yPosition=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_IMSData.YPosition;
           Outgoing_m1m3_IMSData->zPosition=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_IMSData.ZPosition;
           Outgoing_m1m3_IMSData->xRotation=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_IMSData.XRotation;
           Outgoing_m1m3_IMSData->yRotation=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_IMSData.YRotation;
           Outgoing_m1m3_IMSData->zRotation=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_IMSData.ZRotation;

          status = mgr[LVClient].putSample_imsData(Outgoing_m1m3_IMSData);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_IMSData = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_InclinometerData) {
          actorIdx = SAL__MTM1M3_inclinometerData_ACTOR;
          if (mgr[LVClient].actorReader(actorIdx) == false) {
             mgr[LVClient].salTelemetrySub(actorIdx);
             m1m3_memIO->client[LVClient].hasReader_m1m3_InclinometerData = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_InclinometerData == false ) {
            if ( m1m3_memIO->client[LVClient].skipOld_m1m3_InclinometerData == true ) {
                mgr[LVClient].setMaxSamples(actorIdx,-1);
                status = mgr[LVClient].getSample_inclinometerData(Incoming_m1m3_InclinometerData);
             } else {
                status = mgr[LVClient].getNextSample_inclinometerData(Incoming_m1m3_InclinometerData);
             }
             if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_InclinometerData.Timestamp=Incoming_m1m3_InclinometerData->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_InclinometerData.InclinometerAngle=Incoming_m1m3_InclinometerData->inclinometerAngle;

                m1m3_memIO->client[LVClient].hasIncoming_m1m3_InclinometerData = true;
             }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_InclinometerData) {
          actorIdx = SAL__MTM1M3_inclinometerData_ACTOR;
          if (mgr[LVClient].actorWriter(actorIdx) == false) {
             mgr[LVClient].salTelemetryPub(actorIdx);
             m1m3_memIO->client[LVClient].hasWriter_m1m3_InclinometerData = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_InclinometerData ) {
           Outgoing_m1m3_InclinometerData->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_InclinometerData.Timestamp;
           Outgoing_m1m3_InclinometerData->inclinometerAngle=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_InclinometerData.InclinometerAngle;

          status = mgr[LVClient].putSample_inclinometerData(Outgoing_m1m3_InclinometerData);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_InclinometerData = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_OuterLoopData) {
          actorIdx = SAL__MTM1M3_outerLoopData_ACTOR;
          if (mgr[LVClient].actorReader(actorIdx) == false) {
             mgr[LVClient].salTelemetrySub(actorIdx);
             m1m3_memIO->client[LVClient].hasReader_m1m3_OuterLoopData = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_OuterLoopData == false ) {
            if ( m1m3_memIO->client[LVClient].skipOld_m1m3_OuterLoopData == true ) {
                mgr[LVClient].setMaxSamples(actorIdx,-1);
                status = mgr[LVClient].getSample_outerLoopData(Incoming_m1m3_OuterLoopData);
             } else {
                status = mgr[LVClient].getNextSample_outerLoopData(Incoming_m1m3_OuterLoopData);
             }
             if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_OuterLoopData.Timestamp=Incoming_m1m3_OuterLoopData->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_OuterLoopData.BroadcastCounter=Incoming_m1m3_OuterLoopData->broadcastCounter;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_OuterLoopData.SlewFlag=Incoming_m1m3_OuterLoopData->slewFlag;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_OuterLoopData.ExecutionTime=Incoming_m1m3_OuterLoopData->executionTime;

                m1m3_memIO->client[LVClient].hasIncoming_m1m3_OuterLoopData = true;
             }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_OuterLoopData) {
          actorIdx = SAL__MTM1M3_outerLoopData_ACTOR;
          if (mgr[LVClient].actorWriter(actorIdx) == false) {
             mgr[LVClient].salTelemetryPub(actorIdx);
             m1m3_memIO->client[LVClient].hasWriter_m1m3_OuterLoopData = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_OuterLoopData ) {
           Outgoing_m1m3_OuterLoopData->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_OuterLoopData.Timestamp;
           Outgoing_m1m3_OuterLoopData->broadcastCounter=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_OuterLoopData.BroadcastCounter;
           Outgoing_m1m3_OuterLoopData->slewFlag=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_OuterLoopData.SlewFlag;
           Outgoing_m1m3_OuterLoopData->executionTime=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_OuterLoopData.ExecutionTime;

          status = mgr[LVClient].putSample_outerLoopData(Outgoing_m1m3_OuterLoopData);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_OuterLoopData = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_PIDData) {
          actorIdx = SAL__MTM1M3_pidData_ACTOR;
          if (mgr[LVClient].actorReader(actorIdx) == false) {
             mgr[LVClient].salTelemetrySub(actorIdx);
             m1m3_memIO->client[LVClient].hasReader_m1m3_PIDData = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_PIDData == false ) {
            if ( m1m3_memIO->client[LVClient].skipOld_m1m3_PIDData == true ) {
                mgr[LVClient].setMaxSamples(actorIdx,-1);
                status = mgr[LVClient].getSample_pidData(Incoming_m1m3_PIDData);
             } else {
                status = mgr[LVClient].getNextSample_pidData(Incoming_m1m3_PIDData);
             }
             if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_PIDData.Timestamp=Incoming_m1m3_PIDData->timestamp;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_PIDData.Setpoint[i]=Incoming_m1m3_PIDData->setpoint[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_PIDData.Measurement[i]=Incoming_m1m3_PIDData->measuredPID[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_PIDData.Error[i]=Incoming_m1m3_PIDData->error[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_PIDData.ErrorT1[i]=Incoming_m1m3_PIDData->errorT1[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_PIDData.ErrorT2[i]=Incoming_m1m3_PIDData->errorT2[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_PIDData.Control[i]=Incoming_m1m3_PIDData->control[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_PIDData.ControlT1[i]=Incoming_m1m3_PIDData->controlT1[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_PIDData.ControlT2[i]=Incoming_m1m3_PIDData->controlT2[i];}

                m1m3_memIO->client[LVClient].hasIncoming_m1m3_PIDData = true;
             }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_PIDData) {
          actorIdx = SAL__MTM1M3_pidData_ACTOR;
          if (mgr[LVClient].actorWriter(actorIdx) == false) {
             mgr[LVClient].salTelemetryPub(actorIdx);
             m1m3_memIO->client[LVClient].hasWriter_m1m3_PIDData = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_PIDData ) {
           Outgoing_m1m3_PIDData->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_PIDData.Timestamp;
    for (int i=0;i<6;i++) {Outgoing_m1m3_PIDData->setpoint[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_PIDData.Setpoint[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_PIDData->measuredPID[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_PIDData.Measurement[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_PIDData->error[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_PIDData.Error[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_PIDData->errorT1[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_PIDData.ErrorT1[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_PIDData->errorT2[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_PIDData.ErrorT2[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_PIDData->control[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_PIDData.Control[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_PIDData->controlT1[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_PIDData.ControlT1[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_PIDData->controlT2[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_PIDData.ControlT2[i];}

          status = mgr[LVClient].putSample_pidData(Outgoing_m1m3_PIDData);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_PIDData = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_PowerSupplyData) {
          actorIdx = SAL__MTM1M3_powerSupplyData_ACTOR;
          if (mgr[LVClient].actorReader(actorIdx) == false) {
             mgr[LVClient].salTelemetrySub(actorIdx);
             m1m3_memIO->client[LVClient].hasReader_m1m3_PowerSupplyData = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_PowerSupplyData == false ) {
            if ( m1m3_memIO->client[LVClient].skipOld_m1m3_PowerSupplyData == true ) {
                mgr[LVClient].setMaxSamples(actorIdx,-1);
                status = mgr[LVClient].getSample_powerSupplyData(Incoming_m1m3_PowerSupplyData);
             } else {
                status = mgr[LVClient].getNextSample_powerSupplyData(Incoming_m1m3_PowerSupplyData);
             }
             if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_PowerSupplyData.Timestamp=Incoming_m1m3_PowerSupplyData->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_PowerSupplyData.PowerNetworkACurrent=Incoming_m1m3_PowerSupplyData->powerNetworkACurrent;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_PowerSupplyData.PowerNetworkBCurrent=Incoming_m1m3_PowerSupplyData->powerNetworkBCurrent;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_PowerSupplyData.PowerNetworkCCurrent=Incoming_m1m3_PowerSupplyData->powerNetworkCCurrent;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_PowerSupplyData.PowerNetworkDCurrent=Incoming_m1m3_PowerSupplyData->powerNetworkDCurrent;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_PowerSupplyData.LightPowerNetworkCurrent=Incoming_m1m3_PowerSupplyData->lightPowerNetworkCurrent;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_PowerSupplyData.ControlsPowerNetworkCurrent=Incoming_m1m3_PowerSupplyData->controlsPowerNetworkCurrent;

                m1m3_memIO->client[LVClient].hasIncoming_m1m3_PowerSupplyData = true;
             }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_PowerSupplyData) {
          actorIdx = SAL__MTM1M3_powerSupplyData_ACTOR;
          if (mgr[LVClient].actorWriter(actorIdx) == false) {
             mgr[LVClient].salTelemetryPub(actorIdx);
             m1m3_memIO->client[LVClient].hasWriter_m1m3_PowerSupplyData = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_PowerSupplyData ) {
           Outgoing_m1m3_PowerSupplyData->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_PowerSupplyData.Timestamp;
           Outgoing_m1m3_PowerSupplyData->powerNetworkACurrent=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_PowerSupplyData.PowerNetworkACurrent;
           Outgoing_m1m3_PowerSupplyData->powerNetworkBCurrent=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_PowerSupplyData.PowerNetworkBCurrent;
           Outgoing_m1m3_PowerSupplyData->powerNetworkCCurrent=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_PowerSupplyData.PowerNetworkCCurrent;
           Outgoing_m1m3_PowerSupplyData->powerNetworkDCurrent=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_PowerSupplyData.PowerNetworkDCurrent;
           Outgoing_m1m3_PowerSupplyData->lightPowerNetworkCurrent=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_PowerSupplyData.LightPowerNetworkCurrent;
           Outgoing_m1m3_PowerSupplyData->controlsPowerNetworkCurrent=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_PowerSupplyData.ControlsPowerNetworkCurrent;

          status = mgr[LVClient].putSample_powerSupplyData(Outgoing_m1m3_PowerSupplyData);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_PowerSupplyData = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_AbortProfile) {
          actorIdx = SAL__MTM1M3_command_abortProfile_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_abortProfile");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_AbortProfile = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_AbortProfile == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_AbortProfile ) {
               status = mgr[LVClient].acceptCommand_abortProfile(Incoming_m1m3_command_AbortProfile);
            } else {
               status = mgr[LVClient].getNextSample_command_abortProfile(Incoming_m1m3_command_AbortProfile);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_AbortProfile.AbortProfile=Incoming_m1m3_command_AbortProfile->abortProfile;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_AbortProfile = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_AbortProfile_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_AbortProfile_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_AbortProfile_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_AbortProfile_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_abortProfileC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_AbortProfile_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_AbortProfile_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_AbortProfile_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_AbortProfile_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_AbortProfile_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_AbortProfile_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_AbortProfile_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_AbortProfile) {
          actorIdx = SAL__MTM1M3_command_abortProfile_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_abortProfile");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_AbortProfile = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_AbortProfile ) {
           Outgoing_m1m3_command_AbortProfile->abortProfile=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_AbortProfile.AbortProfile;

          status = mgr[LVClient].issueCommand_abortProfile(Outgoing_m1m3_command_AbortProfile);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_AbortProfile_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_AbortProfile = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_AbortProfile = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_AbortProfile_ackcmd) {
            actorIdx = SAL__MTM1M3_command_abortProfile_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_abortProfile");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_AbortProfile = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_AbortProfile_ackcmd ) {
          status = mgr[LVClient].ackCommand_abortProfile(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_AbortProfile_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_AbortProfile_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_AbortProfile_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_AbortProfile_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_AbortProfile_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_AbortRaiseM1M3) {
          actorIdx = SAL__MTM1M3_command_abortRaiseM1M3_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_abortRaiseM1M3");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_AbortRaiseM1M3 = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_AbortRaiseM1M3 == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_AbortRaiseM1M3 ) {
               status = mgr[LVClient].acceptCommand_abortRaiseM1M3(Incoming_m1m3_command_AbortRaiseM1M3);
            } else {
               status = mgr[LVClient].getNextSample_command_abortRaiseM1M3(Incoming_m1m3_command_AbortRaiseM1M3);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_AbortRaiseM1M3.AbortRaiseM1M3=Incoming_m1m3_command_AbortRaiseM1M3->abortRaiseM1M3;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_AbortRaiseM1M3 = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_AbortRaiseM1M3_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_AbortRaiseM1M3_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_AbortRaiseM1M3_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_AbortRaiseM1M3_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_abortRaiseM1M3C(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_AbortRaiseM1M3_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_AbortRaiseM1M3_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_AbortRaiseM1M3_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_AbortRaiseM1M3_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_AbortRaiseM1M3_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_AbortRaiseM1M3_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_AbortRaiseM1M3_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_AbortRaiseM1M3) {
          actorIdx = SAL__MTM1M3_command_abortRaiseM1M3_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_abortRaiseM1M3");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_AbortRaiseM1M3 = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_AbortRaiseM1M3 ) {
           Outgoing_m1m3_command_AbortRaiseM1M3->abortRaiseM1M3=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_AbortRaiseM1M3.AbortRaiseM1M3;

          status = mgr[LVClient].issueCommand_abortRaiseM1M3(Outgoing_m1m3_command_AbortRaiseM1M3);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_AbortRaiseM1M3_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_AbortRaiseM1M3 = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_AbortRaiseM1M3 = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_AbortRaiseM1M3_ackcmd) {
            actorIdx = SAL__MTM1M3_command_abortRaiseM1M3_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_abortRaiseM1M3");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_AbortRaiseM1M3 = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_AbortRaiseM1M3_ackcmd ) {
          status = mgr[LVClient].ackCommand_abortRaiseM1M3(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_AbortRaiseM1M3_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_AbortRaiseM1M3_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_AbortRaiseM1M3_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_AbortRaiseM1M3_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_AbortRaiseM1M3_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ApplyAberrationForces) {
          actorIdx = SAL__MTM1M3_command_applyAberrationForces_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_applyAberrationForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_ApplyAberrationForces = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyAberrationForces == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_ApplyAberrationForces ) {
               status = mgr[LVClient].acceptCommand_applyAberrationForces(Incoming_m1m3_command_ApplyAberrationForces);
            } else {
               status = mgr[LVClient].getNextSample_command_applyAberrationForces(Incoming_m1m3_command_ApplyAberrationForces);
            }
            if (status > 0) {
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyAberrationForces.ZForces[i]=Incoming_m1m3_command_ApplyAberrationForces->zForces[i];}

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyAberrationForces = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyAberrationForces_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_ApplyAberrationForces_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ApplyAberrationForces_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyAberrationForces_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_applyAberrationForcesC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyAberrationForces_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_ApplyAberrationForces_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyAberrationForces_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_ApplyAberrationForces_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyAberrationForces_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_ApplyAberrationForces_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyAberrationForces_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ApplyAberrationForces) {
          actorIdx = SAL__MTM1M3_command_applyAberrationForces_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_applyAberrationForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ApplyAberrationForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyAberrationForces ) {
    for (int i=0;i<156;i++) {Outgoing_m1m3_command_ApplyAberrationForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyAberrationForces.ZForces[i];}

          status = mgr[LVClient].issueCommand_applyAberrationForces(Outgoing_m1m3_command_ApplyAberrationForces);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyAberrationForces_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyAberrationForces = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ApplyAberrationForces = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ApplyAberrationForces_ackcmd) {
            actorIdx = SAL__MTM1M3_command_applyAberrationForces_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_applyAberrationForces");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_ApplyAberrationForces = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyAberrationForces_ackcmd ) {
          status = mgr[LVClient].ackCommand_applyAberrationForces(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyAberrationForces_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyAberrationForces_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyAberrationForces_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyAberrationForces_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyAberrationForces_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ApplyAberrationForcesByBendingModes) {
          actorIdx = SAL__MTM1M3_command_applyAberrationForcesByBendingModes_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_applyAberrationForcesByBendingModes");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_ApplyAberrationForcesByBendingModes = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyAberrationForcesByBendingModes == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_ApplyAberrationForcesByBendingModes ) {
               status = mgr[LVClient].acceptCommand_applyAberrationForcesByBendingModes(Incoming_m1m3_command_ApplyAberrationForcesByBendingModes);
            } else {
               status = mgr[LVClient].getNextSample_command_applyAberrationForcesByBendingModes(Incoming_m1m3_command_ApplyAberrationForcesByBendingModes);
            }
            if (status > 0) {
    for (int i=0;i<22;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyAberrationForcesByBendingModes.Coefficients[i]=Incoming_m1m3_command_ApplyAberrationForcesByBendingModes->coefficients[i];}

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyAberrationForcesByBendingModes = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyAberrationForcesByBendingModes_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_ApplyAberrationForcesByBendingModes_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ApplyAberrationForcesByBendingModes_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyAberrationForcesByBendingModes_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_applyAberrationForcesByBendingModesC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyAberrationForcesByBendingModes_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_ApplyAberrationForcesByBendingModes_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyAberrationForcesByBendingModes_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_ApplyAberrationForcesByBendingModes_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyAberrationForcesByBendingModes_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_ApplyAberrationForcesByBendingModes_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyAberrationForcesByBendingModes_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ApplyAberrationForcesByBendingModes) {
          actorIdx = SAL__MTM1M3_command_applyAberrationForcesByBendingModes_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_applyAberrationForcesByBendingModes");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ApplyAberrationForcesByBendingModes = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyAberrationForcesByBendingModes ) {
    for (int i=0;i<22;i++) {Outgoing_m1m3_command_ApplyAberrationForcesByBendingModes->coefficients[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyAberrationForcesByBendingModes.Coefficients[i];}

          status = mgr[LVClient].issueCommand_applyAberrationForcesByBendingModes(Outgoing_m1m3_command_ApplyAberrationForcesByBendingModes);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyAberrationForcesByBendingModes_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyAberrationForcesByBendingModes = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ApplyAberrationForcesByBendingModes = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ApplyAberrationForcesByBendingModes_ackcmd) {
            actorIdx = SAL__MTM1M3_command_applyAberrationForcesByBendingModes_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_applyAberrationForcesByBendingModes");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_ApplyAberrationForcesByBendingModes = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyAberrationForcesByBendingModes_ackcmd ) {
          status = mgr[LVClient].ackCommand_applyAberrationForcesByBendingModes(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyAberrationForcesByBendingModes_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyAberrationForcesByBendingModes_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyAberrationForcesByBendingModes_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyAberrationForcesByBendingModes_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyAberrationForcesByBendingModes_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ApplyActiveOpticForces) {
          actorIdx = SAL__MTM1M3_command_applyActiveOpticForces_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_applyActiveOpticForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_ApplyActiveOpticForces = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyActiveOpticForces == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_ApplyActiveOpticForces ) {
               status = mgr[LVClient].acceptCommand_applyActiveOpticForces(Incoming_m1m3_command_ApplyActiveOpticForces);
            } else {
               status = mgr[LVClient].getNextSample_command_applyActiveOpticForces(Incoming_m1m3_command_ApplyActiveOpticForces);
            }
            if (status > 0) {
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyActiveOpticForces.ZForces[i]=Incoming_m1m3_command_ApplyActiveOpticForces->zForces[i];}

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyActiveOpticForces = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyActiveOpticForces_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_ApplyActiveOpticForces_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ApplyActiveOpticForces_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyActiveOpticForces_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_applyActiveOpticForcesC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyActiveOpticForces_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_ApplyActiveOpticForces_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyActiveOpticForces_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_ApplyActiveOpticForces_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyActiveOpticForces_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_ApplyActiveOpticForces_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyActiveOpticForces_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ApplyActiveOpticForces) {
          actorIdx = SAL__MTM1M3_command_applyActiveOpticForces_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_applyActiveOpticForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ApplyActiveOpticForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyActiveOpticForces ) {
    for (int i=0;i<156;i++) {Outgoing_m1m3_command_ApplyActiveOpticForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyActiveOpticForces.ZForces[i];}

          status = mgr[LVClient].issueCommand_applyActiveOpticForces(Outgoing_m1m3_command_ApplyActiveOpticForces);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyActiveOpticForces_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyActiveOpticForces = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ApplyActiveOpticForces = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ApplyActiveOpticForces_ackcmd) {
            actorIdx = SAL__MTM1M3_command_applyActiveOpticForces_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_applyActiveOpticForces");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_ApplyActiveOpticForces = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyActiveOpticForces_ackcmd ) {
          status = mgr[LVClient].ackCommand_applyActiveOpticForces(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyActiveOpticForces_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyActiveOpticForces_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyActiveOpticForces_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyActiveOpticForces_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyActiveOpticForces_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ApplyActiveOpticForcesByBendingModes) {
          actorIdx = SAL__MTM1M3_command_applyActiveOpticForcesByBendingModes_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_applyActiveOpticForcesByBendingModes");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_ApplyActiveOpticForcesByBendingModes = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyActiveOpticForcesByBendingModes == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_ApplyActiveOpticForcesByBendingModes ) {
               status = mgr[LVClient].acceptCommand_applyActiveOpticForcesByBendingModes(Incoming_m1m3_command_ApplyActiveOpticForcesByBendingModes);
            } else {
               status = mgr[LVClient].getNextSample_command_applyActiveOpticForcesByBendingModes(Incoming_m1m3_command_ApplyActiveOpticForcesByBendingModes);
            }
            if (status > 0) {
    for (int i=0;i<22;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyActiveOpticForcesByBendingModes.Coefficients[i]=Incoming_m1m3_command_ApplyActiveOpticForcesByBendingModes->coefficients[i];}

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyActiveOpticForcesByBendingModes = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyActiveOpticForcesByBendingModes_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_ApplyActiveOpticForcesByBendingModes_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ApplyActiveOpticForcesByBendingModes_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyActiveOpticForcesByBendingModes_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_applyActiveOpticForcesByBendingModesC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyActiveOpticForcesByBendingModes_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_ApplyActiveOpticForcesByBendingModes_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyActiveOpticForcesByBendingModes_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_ApplyActiveOpticForcesByBendingModes_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyActiveOpticForcesByBendingModes_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_ApplyActiveOpticForcesByBendingModes_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyActiveOpticForcesByBendingModes_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ApplyActiveOpticForcesByBendingModes) {
          actorIdx = SAL__MTM1M3_command_applyActiveOpticForcesByBendingModes_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_applyActiveOpticForcesByBendingModes");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ApplyActiveOpticForcesByBendingModes = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyActiveOpticForcesByBendingModes ) {
    for (int i=0;i<22;i++) {Outgoing_m1m3_command_ApplyActiveOpticForcesByBendingModes->coefficients[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyActiveOpticForcesByBendingModes.Coefficients[i];}

          status = mgr[LVClient].issueCommand_applyActiveOpticForcesByBendingModes(Outgoing_m1m3_command_ApplyActiveOpticForcesByBendingModes);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyActiveOpticForcesByBendingModes_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyActiveOpticForcesByBendingModes = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ApplyActiveOpticForcesByBendingModes = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ApplyActiveOpticForcesByBendingModes_ackcmd) {
            actorIdx = SAL__MTM1M3_command_applyActiveOpticForcesByBendingModes_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_applyActiveOpticForcesByBendingModes");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_ApplyActiveOpticForcesByBendingModes = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyActiveOpticForcesByBendingModes_ackcmd ) {
          status = mgr[LVClient].ackCommand_applyActiveOpticForcesByBendingModes(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyActiveOpticForcesByBendingModes_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyActiveOpticForcesByBendingModes_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyActiveOpticForcesByBendingModes_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyActiveOpticForcesByBendingModes_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyActiveOpticForcesByBendingModes_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ApplyOffsetForces) {
          actorIdx = SAL__MTM1M3_command_applyOffsetForces_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_applyOffsetForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_ApplyOffsetForces = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyOffsetForces == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_ApplyOffsetForces ) {
               status = mgr[LVClient].acceptCommand_applyOffsetForces(Incoming_m1m3_command_ApplyOffsetForces);
            } else {
               status = mgr[LVClient].getNextSample_command_applyOffsetForces(Incoming_m1m3_command_ApplyOffsetForces);
            }
            if (status > 0) {
    for (int i=0;i<12;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyOffsetForces.XForces[i]=Incoming_m1m3_command_ApplyOffsetForces->xForces[i];}
    for (int i=0;i<100;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyOffsetForces.YForces[i]=Incoming_m1m3_command_ApplyOffsetForces->yForces[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyOffsetForces.ZForces[i]=Incoming_m1m3_command_ApplyOffsetForces->zForces[i];}

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyOffsetForces = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyOffsetForces_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_ApplyOffsetForces_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ApplyOffsetForces_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyOffsetForces_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_applyOffsetForcesC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyOffsetForces_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_ApplyOffsetForces_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyOffsetForces_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_ApplyOffsetForces_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyOffsetForces_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_ApplyOffsetForces_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyOffsetForces_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ApplyOffsetForces) {
          actorIdx = SAL__MTM1M3_command_applyOffsetForces_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_applyOffsetForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ApplyOffsetForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyOffsetForces ) {
    for (int i=0;i<12;i++) {Outgoing_m1m3_command_ApplyOffsetForces->xForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyOffsetForces.XForces[i];}
    for (int i=0;i<100;i++) {Outgoing_m1m3_command_ApplyOffsetForces->yForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyOffsetForces.YForces[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_command_ApplyOffsetForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyOffsetForces.ZForces[i];}

          status = mgr[LVClient].issueCommand_applyOffsetForces(Outgoing_m1m3_command_ApplyOffsetForces);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyOffsetForces_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyOffsetForces = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ApplyOffsetForces = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ApplyOffsetForces_ackcmd) {
            actorIdx = SAL__MTM1M3_command_applyOffsetForces_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_applyOffsetForces");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_ApplyOffsetForces = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyOffsetForces_ackcmd ) {
          status = mgr[LVClient].ackCommand_applyOffsetForces(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyOffsetForces_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyOffsetForces_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyOffsetForces_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyOffsetForces_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyOffsetForces_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ApplyOffsetForcesByMirrorForce) {
          actorIdx = SAL__MTM1M3_command_applyOffsetForcesByMirrorForce_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_applyOffsetForcesByMirrorForce");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_ApplyOffsetForcesByMirrorForce = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyOffsetForcesByMirrorForce == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_ApplyOffsetForcesByMirrorForce ) {
               status = mgr[LVClient].acceptCommand_applyOffsetForcesByMirrorForce(Incoming_m1m3_command_ApplyOffsetForcesByMirrorForce);
            } else {
               status = mgr[LVClient].getNextSample_command_applyOffsetForcesByMirrorForce(Incoming_m1m3_command_ApplyOffsetForcesByMirrorForce);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyOffsetForcesByMirrorForce.XForce=Incoming_m1m3_command_ApplyOffsetForcesByMirrorForce->xForce;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyOffsetForcesByMirrorForce.YForce=Incoming_m1m3_command_ApplyOffsetForcesByMirrorForce->yForce;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyOffsetForcesByMirrorForce.ZForce=Incoming_m1m3_command_ApplyOffsetForcesByMirrorForce->zForce;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyOffsetForcesByMirrorForce.XMoment=Incoming_m1m3_command_ApplyOffsetForcesByMirrorForce->xMoment;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyOffsetForcesByMirrorForce.YMoment=Incoming_m1m3_command_ApplyOffsetForcesByMirrorForce->yMoment;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyOffsetForcesByMirrorForce.ZMoment=Incoming_m1m3_command_ApplyOffsetForcesByMirrorForce->zMoment;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyOffsetForcesByMirrorForce = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyOffsetForcesByMirrorForce_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_ApplyOffsetForcesByMirrorForce_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ApplyOffsetForcesByMirrorForce_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyOffsetForcesByMirrorForce_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_applyOffsetForcesByMirrorForceC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyOffsetForcesByMirrorForce_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_ApplyOffsetForcesByMirrorForce_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyOffsetForcesByMirrorForce_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_ApplyOffsetForcesByMirrorForce_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ApplyOffsetForcesByMirrorForce_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_ApplyOffsetForcesByMirrorForce_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ApplyOffsetForcesByMirrorForce_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ApplyOffsetForcesByMirrorForce) {
          actorIdx = SAL__MTM1M3_command_applyOffsetForcesByMirrorForce_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_applyOffsetForcesByMirrorForce");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ApplyOffsetForcesByMirrorForce = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyOffsetForcesByMirrorForce ) {
           Outgoing_m1m3_command_ApplyOffsetForcesByMirrorForce->xForce=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyOffsetForcesByMirrorForce.XForce;
           Outgoing_m1m3_command_ApplyOffsetForcesByMirrorForce->yForce=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyOffsetForcesByMirrorForce.YForce;
           Outgoing_m1m3_command_ApplyOffsetForcesByMirrorForce->zForce=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyOffsetForcesByMirrorForce.ZForce;
           Outgoing_m1m3_command_ApplyOffsetForcesByMirrorForce->xMoment=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyOffsetForcesByMirrorForce.XMoment;
           Outgoing_m1m3_command_ApplyOffsetForcesByMirrorForce->yMoment=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyOffsetForcesByMirrorForce.YMoment;
           Outgoing_m1m3_command_ApplyOffsetForcesByMirrorForce->zMoment=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyOffsetForcesByMirrorForce.ZMoment;

          status = mgr[LVClient].issueCommand_applyOffsetForcesByMirrorForce(Outgoing_m1m3_command_ApplyOffsetForcesByMirrorForce);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyOffsetForcesByMirrorForce_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyOffsetForcesByMirrorForce = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ApplyOffsetForcesByMirrorForce = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ApplyOffsetForcesByMirrorForce_ackcmd) {
            actorIdx = SAL__MTM1M3_command_applyOffsetForcesByMirrorForce_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_applyOffsetForcesByMirrorForce");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_ApplyOffsetForcesByMirrorForce = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyOffsetForcesByMirrorForce_ackcmd ) {
          status = mgr[LVClient].ackCommand_applyOffsetForcesByMirrorForce(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyOffsetForcesByMirrorForce_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyOffsetForcesByMirrorForce_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyOffsetForcesByMirrorForce_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ApplyOffsetForcesByMirrorForce_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ApplyOffsetForcesByMirrorForce_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ClearAberrationForces) {
          actorIdx = SAL__MTM1M3_command_clearAberrationForces_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_clearAberrationForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_ClearAberrationForces = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ClearAberrationForces == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_ClearAberrationForces ) {
               status = mgr[LVClient].acceptCommand_clearAberrationForces(Incoming_m1m3_command_ClearAberrationForces);
            } else {
               status = mgr[LVClient].getNextSample_command_clearAberrationForces(Incoming_m1m3_command_ClearAberrationForces);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ClearAberrationForces.ClearAberrationForces=Incoming_m1m3_command_ClearAberrationForces->clearAberrationForces;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ClearAberrationForces = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ClearAberrationForces_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_ClearAberrationForces_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ClearAberrationForces_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ClearAberrationForces_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_clearAberrationForcesC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ClearAberrationForces_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_ClearAberrationForces_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ClearAberrationForces_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_ClearAberrationForces_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ClearAberrationForces_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_ClearAberrationForces_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ClearAberrationForces_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ClearAberrationForces) {
          actorIdx = SAL__MTM1M3_command_clearAberrationForces_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_clearAberrationForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ClearAberrationForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ClearAberrationForces ) {
           Outgoing_m1m3_command_ClearAberrationForces->clearAberrationForces=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ClearAberrationForces.ClearAberrationForces;

          status = mgr[LVClient].issueCommand_clearAberrationForces(Outgoing_m1m3_command_ClearAberrationForces);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ClearAberrationForces_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ClearAberrationForces = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ClearAberrationForces = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ClearAberrationForces_ackcmd) {
            actorIdx = SAL__MTM1M3_command_clearAberrationForces_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_clearAberrationForces");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_ClearAberrationForces = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ClearAberrationForces_ackcmd ) {
          status = mgr[LVClient].ackCommand_clearAberrationForces(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ClearAberrationForces_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ClearAberrationForces_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ClearAberrationForces_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ClearAberrationForces_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ClearAberrationForces_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ClearActiveOpticForces) {
          actorIdx = SAL__MTM1M3_command_clearActiveOpticForces_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_clearActiveOpticForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_ClearActiveOpticForces = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ClearActiveOpticForces == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_ClearActiveOpticForces ) {
               status = mgr[LVClient].acceptCommand_clearActiveOpticForces(Incoming_m1m3_command_ClearActiveOpticForces);
            } else {
               status = mgr[LVClient].getNextSample_command_clearActiveOpticForces(Incoming_m1m3_command_ClearActiveOpticForces);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ClearActiveOpticForces.ClearActiveOpticForces=Incoming_m1m3_command_ClearActiveOpticForces->clearActiveOpticForces;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ClearActiveOpticForces = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ClearActiveOpticForces_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_ClearActiveOpticForces_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ClearActiveOpticForces_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ClearActiveOpticForces_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_clearActiveOpticForcesC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ClearActiveOpticForces_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_ClearActiveOpticForces_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ClearActiveOpticForces_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_ClearActiveOpticForces_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ClearActiveOpticForces_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_ClearActiveOpticForces_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ClearActiveOpticForces_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ClearActiveOpticForces) {
          actorIdx = SAL__MTM1M3_command_clearActiveOpticForces_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_clearActiveOpticForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ClearActiveOpticForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ClearActiveOpticForces ) {
           Outgoing_m1m3_command_ClearActiveOpticForces->clearActiveOpticForces=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ClearActiveOpticForces.ClearActiveOpticForces;

          status = mgr[LVClient].issueCommand_clearActiveOpticForces(Outgoing_m1m3_command_ClearActiveOpticForces);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ClearActiveOpticForces_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ClearActiveOpticForces = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ClearActiveOpticForces = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ClearActiveOpticForces_ackcmd) {
            actorIdx = SAL__MTM1M3_command_clearActiveOpticForces_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_clearActiveOpticForces");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_ClearActiveOpticForces = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ClearActiveOpticForces_ackcmd ) {
          status = mgr[LVClient].ackCommand_clearActiveOpticForces(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ClearActiveOpticForces_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ClearActiveOpticForces_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ClearActiveOpticForces_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ClearActiveOpticForces_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ClearActiveOpticForces_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ClearOffsetForces) {
          actorIdx = SAL__MTM1M3_command_clearOffsetForces_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_clearOffsetForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_ClearOffsetForces = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ClearOffsetForces == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_ClearOffsetForces ) {
               status = mgr[LVClient].acceptCommand_clearOffsetForces(Incoming_m1m3_command_ClearOffsetForces);
            } else {
               status = mgr[LVClient].getNextSample_command_clearOffsetForces(Incoming_m1m3_command_ClearOffsetForces);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ClearOffsetForces.ClearOffsetForces=Incoming_m1m3_command_ClearOffsetForces->clearOffsetForces;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ClearOffsetForces = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ClearOffsetForces_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_ClearOffsetForces_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ClearOffsetForces_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ClearOffsetForces_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_clearOffsetForcesC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ClearOffsetForces_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_ClearOffsetForces_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ClearOffsetForces_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_ClearOffsetForces_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ClearOffsetForces_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_ClearOffsetForces_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ClearOffsetForces_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ClearOffsetForces) {
          actorIdx = SAL__MTM1M3_command_clearOffsetForces_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_clearOffsetForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ClearOffsetForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ClearOffsetForces ) {
           Outgoing_m1m3_command_ClearOffsetForces->clearOffsetForces=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ClearOffsetForces.ClearOffsetForces;

          status = mgr[LVClient].issueCommand_clearOffsetForces(Outgoing_m1m3_command_ClearOffsetForces);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ClearOffsetForces_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ClearOffsetForces = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ClearOffsetForces = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ClearOffsetForces_ackcmd) {
            actorIdx = SAL__MTM1M3_command_clearOffsetForces_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_clearOffsetForces");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_ClearOffsetForces = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ClearOffsetForces_ackcmd ) {
          status = mgr[LVClient].ackCommand_clearOffsetForces(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ClearOffsetForces_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ClearOffsetForces_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ClearOffsetForces_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ClearOffsetForces_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ClearOffsetForces_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_Disable) {
          actorIdx = SAL__MTM1M3_command_disable_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_disable");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_Disable = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_Disable == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_Disable ) {
               status = mgr[LVClient].acceptCommand_disable(Incoming_m1m3_command_Disable);
            } else {
               status = mgr[LVClient].getNextSample_command_disable(Incoming_m1m3_command_Disable);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Disable.Disable=Incoming_m1m3_command_Disable->value;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_Disable = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Disable_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_Disable_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_Disable_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_Disable_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_disableC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Disable_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_Disable_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Disable_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_Disable_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Disable_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_Disable_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_Disable_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_Disable) {
          actorIdx = SAL__MTM1M3_command_disable_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_disable");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_Disable = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_Disable ) {
           Outgoing_m1m3_command_Disable->value=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Disable.Disable;

          status = mgr[LVClient].issueCommand_disable(Outgoing_m1m3_command_Disable);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Disable_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_Disable = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_Disable = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_Disable_ackcmd) {
            actorIdx = SAL__MTM1M3_command_disable_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_disable");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_Disable = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_Disable_ackcmd ) {
          status = mgr[LVClient].ackCommand_disable(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Disable_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Disable_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Disable_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Disable_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_Disable_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_DisableHardpointChase) {
          actorIdx = SAL__MTM1M3_command_disableHardpointChase_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_disableHardpointChase");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_DisableHardpointChase = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_DisableHardpointChase == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_DisableHardpointChase ) {
               status = mgr[LVClient].acceptCommand_disableHardpointChase(Incoming_m1m3_command_DisableHardpointChase);
            } else {
               status = mgr[LVClient].getNextSample_command_disableHardpointChase(Incoming_m1m3_command_DisableHardpointChase);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_DisableHardpointChase.HardpointActuator=Incoming_m1m3_command_DisableHardpointChase->hardpointActuator;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_DisableHardpointChase = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_DisableHardpointChase_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_DisableHardpointChase_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_DisableHardpointChase_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_DisableHardpointChase_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_disableHardpointChaseC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_DisableHardpointChase_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_DisableHardpointChase_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_DisableHardpointChase_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_DisableHardpointChase_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_DisableHardpointChase_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_DisableHardpointChase_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_DisableHardpointChase_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_DisableHardpointChase) {
          actorIdx = SAL__MTM1M3_command_disableHardpointChase_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_disableHardpointChase");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_DisableHardpointChase = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_DisableHardpointChase ) {
           Outgoing_m1m3_command_DisableHardpointChase->hardpointActuator=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_DisableHardpointChase.HardpointActuator;

          status = mgr[LVClient].issueCommand_disableHardpointChase(Outgoing_m1m3_command_DisableHardpointChase);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_DisableHardpointChase_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_DisableHardpointChase = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_DisableHardpointChase = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_DisableHardpointChase_ackcmd) {
            actorIdx = SAL__MTM1M3_command_disableHardpointChase_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_disableHardpointChase");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_DisableHardpointChase = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_DisableHardpointChase_ackcmd ) {
          status = mgr[LVClient].ackCommand_disableHardpointChase(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_DisableHardpointChase_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_DisableHardpointChase_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_DisableHardpointChase_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_DisableHardpointChase_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_DisableHardpointChase_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_DisableHardpointCorrections) {
          actorIdx = SAL__MTM1M3_command_disableHardpointCorrections_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_disableHardpointCorrections");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_DisableHardpointCorrections = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_DisableHardpointCorrections == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_DisableHardpointCorrections ) {
               status = mgr[LVClient].acceptCommand_disableHardpointCorrections(Incoming_m1m3_command_DisableHardpointCorrections);
            } else {
               status = mgr[LVClient].getNextSample_command_disableHardpointCorrections(Incoming_m1m3_command_DisableHardpointCorrections);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_DisableHardpointCorrections.DisableHardpointCorrections=Incoming_m1m3_command_DisableHardpointCorrections->disableHardpointCorrections;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_DisableHardpointCorrections = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_DisableHardpointCorrections_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_DisableHardpointCorrections_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_DisableHardpointCorrections_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_DisableHardpointCorrections_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_disableHardpointCorrectionsC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_DisableHardpointCorrections_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_DisableHardpointCorrections_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_DisableHardpointCorrections_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_DisableHardpointCorrections_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_DisableHardpointCorrections_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_DisableHardpointCorrections_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_DisableHardpointCorrections_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_DisableHardpointCorrections) {
          actorIdx = SAL__MTM1M3_command_disableHardpointCorrections_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_disableHardpointCorrections");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_DisableHardpointCorrections = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_DisableHardpointCorrections ) {
           Outgoing_m1m3_command_DisableHardpointCorrections->disableHardpointCorrections=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_DisableHardpointCorrections.DisableHardpointCorrections;

          status = mgr[LVClient].issueCommand_disableHardpointCorrections(Outgoing_m1m3_command_DisableHardpointCorrections);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_DisableHardpointCorrections_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_DisableHardpointCorrections = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_DisableHardpointCorrections = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_DisableHardpointCorrections_ackcmd) {
            actorIdx = SAL__MTM1M3_command_disableHardpointCorrections_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_disableHardpointCorrections");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_DisableHardpointCorrections = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_DisableHardpointCorrections_ackcmd ) {
          status = mgr[LVClient].ackCommand_disableHardpointCorrections(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_DisableHardpointCorrections_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_DisableHardpointCorrections_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_DisableHardpointCorrections_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_DisableHardpointCorrections_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_DisableHardpointCorrections_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_Enable) {
          actorIdx = SAL__MTM1M3_command_enable_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_enable");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_Enable = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_Enable == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_Enable ) {
               status = mgr[LVClient].acceptCommand_enable(Incoming_m1m3_command_Enable);
            } else {
               status = mgr[LVClient].getNextSample_command_enable(Incoming_m1m3_command_Enable);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Enable.Enable=Incoming_m1m3_command_Enable->value;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_Enable = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Enable_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_Enable_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_Enable_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_Enable_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_enableC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Enable_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_Enable_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Enable_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_Enable_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Enable_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_Enable_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_Enable_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_Enable) {
          actorIdx = SAL__MTM1M3_command_enable_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_enable");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_Enable = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_Enable ) {
           Outgoing_m1m3_command_Enable->value=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Enable.Enable;

          status = mgr[LVClient].issueCommand_enable(Outgoing_m1m3_command_Enable);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Enable_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_Enable = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_Enable = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_Enable_ackcmd) {
            actorIdx = SAL__MTM1M3_command_enable_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_enable");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_Enable = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_Enable_ackcmd ) {
          status = mgr[LVClient].ackCommand_enable(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Enable_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Enable_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Enable_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Enable_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_Enable_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_EnableHardpointChase) {
          actorIdx = SAL__MTM1M3_command_enableHardpointChase_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_enableHardpointChase");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_EnableHardpointChase = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_EnableHardpointChase == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_EnableHardpointChase ) {
               status = mgr[LVClient].acceptCommand_enableHardpointChase(Incoming_m1m3_command_EnableHardpointChase);
            } else {
               status = mgr[LVClient].getNextSample_command_enableHardpointChase(Incoming_m1m3_command_EnableHardpointChase);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_EnableHardpointChase.HardpointActuator=Incoming_m1m3_command_EnableHardpointChase->hardpointActuator;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_EnableHardpointChase = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_EnableHardpointChase_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_EnableHardpointChase_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_EnableHardpointChase_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_EnableHardpointChase_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_enableHardpointChaseC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_EnableHardpointChase_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_EnableHardpointChase_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_EnableHardpointChase_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_EnableHardpointChase_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_EnableHardpointChase_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_EnableHardpointChase_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_EnableHardpointChase_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_EnableHardpointChase) {
          actorIdx = SAL__MTM1M3_command_enableHardpointChase_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_enableHardpointChase");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_EnableHardpointChase = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_EnableHardpointChase ) {
           Outgoing_m1m3_command_EnableHardpointChase->hardpointActuator=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_EnableHardpointChase.HardpointActuator;

          status = mgr[LVClient].issueCommand_enableHardpointChase(Outgoing_m1m3_command_EnableHardpointChase);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_EnableHardpointChase_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_EnableHardpointChase = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_EnableHardpointChase = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_EnableHardpointChase_ackcmd) {
            actorIdx = SAL__MTM1M3_command_enableHardpointChase_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_enableHardpointChase");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_EnableHardpointChase = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_EnableHardpointChase_ackcmd ) {
          status = mgr[LVClient].ackCommand_enableHardpointChase(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_EnableHardpointChase_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_EnableHardpointChase_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_EnableHardpointChase_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_EnableHardpointChase_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_EnableHardpointChase_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_EnableHardpointCorrections) {
          actorIdx = SAL__MTM1M3_command_enableHardpointCorrections_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_enableHardpointCorrections");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_EnableHardpointCorrections = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_EnableHardpointCorrections == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_EnableHardpointCorrections ) {
               status = mgr[LVClient].acceptCommand_enableHardpointCorrections(Incoming_m1m3_command_EnableHardpointCorrections);
            } else {
               status = mgr[LVClient].getNextSample_command_enableHardpointCorrections(Incoming_m1m3_command_EnableHardpointCorrections);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_EnableHardpointCorrections.EnableHardpointCorrections=Incoming_m1m3_command_EnableHardpointCorrections->enableHardpointCorrections;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_EnableHardpointCorrections = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_EnableHardpointCorrections_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_EnableHardpointCorrections_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_EnableHardpointCorrections_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_EnableHardpointCorrections_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_enableHardpointCorrectionsC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_EnableHardpointCorrections_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_EnableHardpointCorrections_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_EnableHardpointCorrections_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_EnableHardpointCorrections_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_EnableHardpointCorrections_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_EnableHardpointCorrections_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_EnableHardpointCorrections_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_EnableHardpointCorrections) {
          actorIdx = SAL__MTM1M3_command_enableHardpointCorrections_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_enableHardpointCorrections");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_EnableHardpointCorrections = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_EnableHardpointCorrections ) {
           Outgoing_m1m3_command_EnableHardpointCorrections->enableHardpointCorrections=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_EnableHardpointCorrections.EnableHardpointCorrections;

          status = mgr[LVClient].issueCommand_enableHardpointCorrections(Outgoing_m1m3_command_EnableHardpointCorrections);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_EnableHardpointCorrections_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_EnableHardpointCorrections = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_EnableHardpointCorrections = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_EnableHardpointCorrections_ackcmd) {
            actorIdx = SAL__MTM1M3_command_enableHardpointCorrections_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_enableHardpointCorrections");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_EnableHardpointCorrections = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_EnableHardpointCorrections_ackcmd ) {
          status = mgr[LVClient].ackCommand_enableHardpointCorrections(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_EnableHardpointCorrections_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_EnableHardpointCorrections_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_EnableHardpointCorrections_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_EnableHardpointCorrections_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_EnableHardpointCorrections_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_EnterEngineering) {
          actorIdx = SAL__MTM1M3_command_enterEngineering_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_enterEngineering");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_EnterEngineering = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_EnterEngineering == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_EnterEngineering ) {
               status = mgr[LVClient].acceptCommand_enterEngineering(Incoming_m1m3_command_EnterEngineering);
            } else {
               status = mgr[LVClient].getNextSample_command_enterEngineering(Incoming_m1m3_command_EnterEngineering);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_EnterEngineering.EnterEngineering=Incoming_m1m3_command_EnterEngineering->enterEngineering;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_EnterEngineering = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_EnterEngineering_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_EnterEngineering_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_EnterEngineering_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_EnterEngineering_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_enterEngineeringC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_EnterEngineering_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_EnterEngineering_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_EnterEngineering_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_EnterEngineering_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_EnterEngineering_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_EnterEngineering_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_EnterEngineering_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_EnterEngineering) {
          actorIdx = SAL__MTM1M3_command_enterEngineering_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_enterEngineering");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_EnterEngineering = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_EnterEngineering ) {
           Outgoing_m1m3_command_EnterEngineering->enterEngineering=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_EnterEngineering.EnterEngineering;

          status = mgr[LVClient].issueCommand_enterEngineering(Outgoing_m1m3_command_EnterEngineering);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_EnterEngineering_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_EnterEngineering = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_EnterEngineering = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_EnterEngineering_ackcmd) {
            actorIdx = SAL__MTM1M3_command_enterEngineering_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_enterEngineering");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_EnterEngineering = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_EnterEngineering_ackcmd ) {
          status = mgr[LVClient].ackCommand_enterEngineering(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_EnterEngineering_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_EnterEngineering_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_EnterEngineering_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_EnterEngineering_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_EnterEngineering_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ExitEngineering) {
          actorIdx = SAL__MTM1M3_command_exitEngineering_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_exitEngineering");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_ExitEngineering = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ExitEngineering == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_ExitEngineering ) {
               status = mgr[LVClient].acceptCommand_exitEngineering(Incoming_m1m3_command_ExitEngineering);
            } else {
               status = mgr[LVClient].getNextSample_command_exitEngineering(Incoming_m1m3_command_ExitEngineering);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ExitEngineering.ExitEngineering=Incoming_m1m3_command_ExitEngineering->exitEngineering;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ExitEngineering = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ExitEngineering_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_ExitEngineering_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ExitEngineering_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ExitEngineering_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_exitEngineeringC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ExitEngineering_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_ExitEngineering_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ExitEngineering_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_ExitEngineering_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ExitEngineering_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_ExitEngineering_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ExitEngineering_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ExitEngineering) {
          actorIdx = SAL__MTM1M3_command_exitEngineering_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_exitEngineering");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ExitEngineering = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ExitEngineering ) {
           Outgoing_m1m3_command_ExitEngineering->exitEngineering=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ExitEngineering.ExitEngineering;

          status = mgr[LVClient].issueCommand_exitEngineering(Outgoing_m1m3_command_ExitEngineering);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ExitEngineering_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ExitEngineering = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ExitEngineering = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ExitEngineering_ackcmd) {
            actorIdx = SAL__MTM1M3_command_exitEngineering_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_exitEngineering");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_ExitEngineering = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ExitEngineering_ackcmd ) {
          status = mgr[LVClient].ackCommand_exitEngineering(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ExitEngineering_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ExitEngineering_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ExitEngineering_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ExitEngineering_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ExitEngineering_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_LowerM1M3) {
          actorIdx = SAL__MTM1M3_command_lowerM1M3_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_lowerM1M3");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_LowerM1M3 = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_LowerM1M3 == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_LowerM1M3 ) {
               status = mgr[LVClient].acceptCommand_lowerM1M3(Incoming_m1m3_command_LowerM1M3);
            } else {
               status = mgr[LVClient].getNextSample_command_lowerM1M3(Incoming_m1m3_command_LowerM1M3);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_LowerM1M3.LowerM1M3=Incoming_m1m3_command_LowerM1M3->lowerM1M3;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_LowerM1M3 = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_LowerM1M3_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_LowerM1M3_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_LowerM1M3_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_LowerM1M3_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_lowerM1M3C(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_LowerM1M3_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_LowerM1M3_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_LowerM1M3_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_LowerM1M3_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_LowerM1M3_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_LowerM1M3_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_LowerM1M3_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_LowerM1M3) {
          actorIdx = SAL__MTM1M3_command_lowerM1M3_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_lowerM1M3");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_LowerM1M3 = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_LowerM1M3 ) {
           Outgoing_m1m3_command_LowerM1M3->lowerM1M3=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_LowerM1M3.LowerM1M3;

          status = mgr[LVClient].issueCommand_lowerM1M3(Outgoing_m1m3_command_LowerM1M3);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_LowerM1M3_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_LowerM1M3 = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_LowerM1M3 = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_LowerM1M3_ackcmd) {
            actorIdx = SAL__MTM1M3_command_lowerM1M3_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_lowerM1M3");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_LowerM1M3 = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_LowerM1M3_ackcmd ) {
          status = mgr[LVClient].ackCommand_lowerM1M3(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_LowerM1M3_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_LowerM1M3_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_LowerM1M3_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_LowerM1M3_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_LowerM1M3_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_MoveHardpointActuators) {
          actorIdx = SAL__MTM1M3_command_moveHardpointActuators_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_moveHardpointActuators");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_MoveHardpointActuators = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_MoveHardpointActuators == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_MoveHardpointActuators ) {
               status = mgr[LVClient].acceptCommand_moveHardpointActuators(Incoming_m1m3_command_MoveHardpointActuators);
            } else {
               status = mgr[LVClient].getNextSample_command_moveHardpointActuators(Incoming_m1m3_command_MoveHardpointActuators);
            }
            if (status > 0) {
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_MoveHardpointActuators.Steps[i]=Incoming_m1m3_command_MoveHardpointActuators->steps[i];}

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_MoveHardpointActuators = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_MoveHardpointActuators_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_MoveHardpointActuators_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_MoveHardpointActuators_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_MoveHardpointActuators_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_moveHardpointActuatorsC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_MoveHardpointActuators_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_MoveHardpointActuators_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_MoveHardpointActuators_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_MoveHardpointActuators_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_MoveHardpointActuators_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_MoveHardpointActuators_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_MoveHardpointActuators_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_MoveHardpointActuators) {
          actorIdx = SAL__MTM1M3_command_moveHardpointActuators_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_moveHardpointActuators");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_MoveHardpointActuators = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_MoveHardpointActuators ) {
    for (int i=0;i<6;i++) {Outgoing_m1m3_command_MoveHardpointActuators->steps[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_MoveHardpointActuators.Steps[i];}

          status = mgr[LVClient].issueCommand_moveHardpointActuators(Outgoing_m1m3_command_MoveHardpointActuators);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_MoveHardpointActuators_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_MoveHardpointActuators = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_MoveHardpointActuators = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_MoveHardpointActuators_ackcmd) {
            actorIdx = SAL__MTM1M3_command_moveHardpointActuators_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_moveHardpointActuators");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_MoveHardpointActuators = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_MoveHardpointActuators_ackcmd ) {
          status = mgr[LVClient].ackCommand_moveHardpointActuators(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_MoveHardpointActuators_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_MoveHardpointActuators_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_MoveHardpointActuators_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_MoveHardpointActuators_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_MoveHardpointActuators_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_PositionM1M3) {
          actorIdx = SAL__MTM1M3_command_positionM1M3_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_positionM1M3");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_PositionM1M3 = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_PositionM1M3 == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_PositionM1M3 ) {
               status = mgr[LVClient].acceptCommand_positionM1M3(Incoming_m1m3_command_PositionM1M3);
            } else {
               status = mgr[LVClient].getNextSample_command_positionM1M3(Incoming_m1m3_command_PositionM1M3);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_PositionM1M3.XPosition=Incoming_m1m3_command_PositionM1M3->xPosition;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_PositionM1M3.YPosition=Incoming_m1m3_command_PositionM1M3->yPosition;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_PositionM1M3.ZPosition=Incoming_m1m3_command_PositionM1M3->zPosition;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_PositionM1M3.XRotation=Incoming_m1m3_command_PositionM1M3->xRotation;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_PositionM1M3.YRotation=Incoming_m1m3_command_PositionM1M3->yRotation;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_PositionM1M3.ZRotation=Incoming_m1m3_command_PositionM1M3->zRotation;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_PositionM1M3 = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_PositionM1M3_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_PositionM1M3_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_PositionM1M3_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_PositionM1M3_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_positionM1M3C(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_PositionM1M3_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_PositionM1M3_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_PositionM1M3_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_PositionM1M3_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_PositionM1M3_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_PositionM1M3_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_PositionM1M3_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_PositionM1M3) {
          actorIdx = SAL__MTM1M3_command_positionM1M3_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_positionM1M3");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_PositionM1M3 = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_PositionM1M3 ) {
           Outgoing_m1m3_command_PositionM1M3->xPosition=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_PositionM1M3.XPosition;
           Outgoing_m1m3_command_PositionM1M3->yPosition=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_PositionM1M3.YPosition;
           Outgoing_m1m3_command_PositionM1M3->zPosition=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_PositionM1M3.ZPosition;
           Outgoing_m1m3_command_PositionM1M3->xRotation=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_PositionM1M3.XRotation;
           Outgoing_m1m3_command_PositionM1M3->yRotation=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_PositionM1M3.YRotation;
           Outgoing_m1m3_command_PositionM1M3->zRotation=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_PositionM1M3.ZRotation;

          status = mgr[LVClient].issueCommand_positionM1M3(Outgoing_m1m3_command_PositionM1M3);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_PositionM1M3_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_PositionM1M3 = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_PositionM1M3 = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_PositionM1M3_ackcmd) {
            actorIdx = SAL__MTM1M3_command_positionM1M3_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_positionM1M3");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_PositionM1M3 = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_PositionM1M3_ackcmd ) {
          status = mgr[LVClient].ackCommand_positionM1M3(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_PositionM1M3_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_PositionM1M3_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_PositionM1M3_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_PositionM1M3_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_PositionM1M3_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ProgramILC) {
          actorIdx = SAL__MTM1M3_command_programILC_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_programILC");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_ProgramILC = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ProgramILC == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_ProgramILC ) {
               status = mgr[LVClient].acceptCommand_programILC(Incoming_m1m3_command_ProgramILC);
            } else {
               status = mgr[LVClient].getNextSample_command_programILC(Incoming_m1m3_command_ProgramILC);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ProgramILC.ActuatorId=Incoming_m1m3_command_ProgramILC->actuatorId;
             strcpy(m1m3_memIO->client[LVClient].m1m3_command_ProgramILCLV_FilePath_bufferIn,Incoming_m1m3_command_ProgramILC->filePath.c_str());

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ProgramILC = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ProgramILC_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_ProgramILC_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ProgramILC_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ProgramILC_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_programILCC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ProgramILC_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_ProgramILC_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ProgramILC_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_ProgramILC_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ProgramILC_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_ProgramILC_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ProgramILC_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ProgramILC) {
          actorIdx = SAL__MTM1M3_command_programILC_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_programILC");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ProgramILC = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ProgramILC ) {
           Outgoing_m1m3_command_ProgramILC->actuatorId=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ProgramILC.ActuatorId;
             Outgoing_m1m3_command_ProgramILC->filePath=m1m3_memIO->client[LVClient].m1m3_command_ProgramILCLV_FilePath_bufferOut;

          status = mgr[LVClient].issueCommand_programILC(Outgoing_m1m3_command_ProgramILC);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ProgramILC_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ProgramILC = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ProgramILC = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ProgramILC_ackcmd) {
            actorIdx = SAL__MTM1M3_command_programILC_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_programILC");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_ProgramILC = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ProgramILC_ackcmd ) {
          status = mgr[LVClient].ackCommand_programILC(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ProgramILC_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ProgramILC_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ProgramILC_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ProgramILC_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ProgramILC_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_RaiseM1M3) {
          actorIdx = SAL__MTM1M3_command_raiseM1M3_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_raiseM1M3");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_RaiseM1M3 = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_RaiseM1M3 == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_RaiseM1M3 ) {
               status = mgr[LVClient].acceptCommand_raiseM1M3(Incoming_m1m3_command_RaiseM1M3);
            } else {
               status = mgr[LVClient].getNextSample_command_raiseM1M3(Incoming_m1m3_command_RaiseM1M3);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_RaiseM1M3.RaiseM1M3=Incoming_m1m3_command_RaiseM1M3->raiseM1M3;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_RaiseM1M3.BypassReferencePosition=Incoming_m1m3_command_RaiseM1M3->bypassReferencePosition;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_RaiseM1M3 = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_RaiseM1M3_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_RaiseM1M3_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_RaiseM1M3_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_RaiseM1M3_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_raiseM1M3C(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_RaiseM1M3_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_RaiseM1M3_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_RaiseM1M3_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_RaiseM1M3_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_RaiseM1M3_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_RaiseM1M3_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_RaiseM1M3_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_RaiseM1M3) {
          actorIdx = SAL__MTM1M3_command_raiseM1M3_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_raiseM1M3");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_RaiseM1M3 = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_RaiseM1M3 ) {
           Outgoing_m1m3_command_RaiseM1M3->raiseM1M3=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_RaiseM1M3.RaiseM1M3;
           Outgoing_m1m3_command_RaiseM1M3->bypassReferencePosition=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_RaiseM1M3.BypassReferencePosition;

          status = mgr[LVClient].issueCommand_raiseM1M3(Outgoing_m1m3_command_RaiseM1M3);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_RaiseM1M3_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_RaiseM1M3 = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_RaiseM1M3 = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_RaiseM1M3_ackcmd) {
            actorIdx = SAL__MTM1M3_command_raiseM1M3_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_raiseM1M3");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_RaiseM1M3 = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_RaiseM1M3_ackcmd ) {
          status = mgr[LVClient].ackCommand_raiseM1M3(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_RaiseM1M3_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_RaiseM1M3_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_RaiseM1M3_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_RaiseM1M3_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_RaiseM1M3_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ResetPID) {
          actorIdx = SAL__MTM1M3_command_resetPID_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_resetPID");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_ResetPID = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ResetPID == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_ResetPID ) {
               status = mgr[LVClient].acceptCommand_resetPID(Incoming_m1m3_command_ResetPID);
            } else {
               status = mgr[LVClient].getNextSample_command_resetPID(Incoming_m1m3_command_ResetPID);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ResetPID.PID=Incoming_m1m3_command_ResetPID->pid;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ResetPID = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ResetPID_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_ResetPID_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_ResetPID_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ResetPID_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_resetPIDC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ResetPID_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_ResetPID_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ResetPID_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_ResetPID_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_ResetPID_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_ResetPID_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_ResetPID_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ResetPID) {
          actorIdx = SAL__MTM1M3_command_resetPID_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_resetPID");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ResetPID = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ResetPID ) {
           Outgoing_m1m3_command_ResetPID->pid=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ResetPID.PID;

          status = mgr[LVClient].issueCommand_resetPID(Outgoing_m1m3_command_ResetPID);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ResetPID_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ResetPID = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_ResetPID = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_ResetPID_ackcmd) {
            actorIdx = SAL__MTM1M3_command_resetPID_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_resetPID");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_ResetPID = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ResetPID_ackcmd ) {
          status = mgr[LVClient].ackCommand_resetPID(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ResetPID_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ResetPID_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ResetPID_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_ResetPID_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_ResetPID_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_RunMirrorForceProfile) {
          actorIdx = SAL__MTM1M3_command_runMirrorForceProfile_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_runMirrorForceProfile");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_RunMirrorForceProfile = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_RunMirrorForceProfile == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_RunMirrorForceProfile ) {
               status = mgr[LVClient].acceptCommand_runMirrorForceProfile(Incoming_m1m3_command_RunMirrorForceProfile);
            } else {
               status = mgr[LVClient].getNextSample_command_runMirrorForceProfile(Incoming_m1m3_command_RunMirrorForceProfile);
            }
            if (status > 0) {
    for (int i=0;i<1000;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_RunMirrorForceProfile.XForce[i]=Incoming_m1m3_command_RunMirrorForceProfile->xForce[i];}
    for (int i=0;i<1000;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_RunMirrorForceProfile.YForce[i]=Incoming_m1m3_command_RunMirrorForceProfile->yForce[i];}
    for (int i=0;i<1000;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_RunMirrorForceProfile.ZForce[i]=Incoming_m1m3_command_RunMirrorForceProfile->zForce[i];}
    for (int i=0;i<1000;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_RunMirrorForceProfile.XMoment[i]=Incoming_m1m3_command_RunMirrorForceProfile->xMoment[i];}
    for (int i=0;i<1000;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_RunMirrorForceProfile.YMoment[i]=Incoming_m1m3_command_RunMirrorForceProfile->yMoment[i];}
    for (int i=0;i<1000;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_RunMirrorForceProfile.ZMoment[i]=Incoming_m1m3_command_RunMirrorForceProfile->zMoment[i];}

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_RunMirrorForceProfile = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_RunMirrorForceProfile_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_RunMirrorForceProfile_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_RunMirrorForceProfile_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_RunMirrorForceProfile_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_runMirrorForceProfileC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_RunMirrorForceProfile_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_RunMirrorForceProfile_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_RunMirrorForceProfile_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_RunMirrorForceProfile_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_RunMirrorForceProfile_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_RunMirrorForceProfile_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_RunMirrorForceProfile_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_RunMirrorForceProfile) {
          actorIdx = SAL__MTM1M3_command_runMirrorForceProfile_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_runMirrorForceProfile");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_RunMirrorForceProfile = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_RunMirrorForceProfile ) {
    for (int i=0;i<1000;i++) {Outgoing_m1m3_command_RunMirrorForceProfile->xForce[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_RunMirrorForceProfile.XForce[i];}
    for (int i=0;i<1000;i++) {Outgoing_m1m3_command_RunMirrorForceProfile->yForce[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_RunMirrorForceProfile.YForce[i];}
    for (int i=0;i<1000;i++) {Outgoing_m1m3_command_RunMirrorForceProfile->zForce[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_RunMirrorForceProfile.ZForce[i];}
    for (int i=0;i<1000;i++) {Outgoing_m1m3_command_RunMirrorForceProfile->xMoment[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_RunMirrorForceProfile.XMoment[i];}
    for (int i=0;i<1000;i++) {Outgoing_m1m3_command_RunMirrorForceProfile->yMoment[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_RunMirrorForceProfile.YMoment[i];}
    for (int i=0;i<1000;i++) {Outgoing_m1m3_command_RunMirrorForceProfile->zMoment[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_RunMirrorForceProfile.ZMoment[i];}

          status = mgr[LVClient].issueCommand_runMirrorForceProfile(Outgoing_m1m3_command_RunMirrorForceProfile);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_RunMirrorForceProfile_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_RunMirrorForceProfile = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_RunMirrorForceProfile = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_RunMirrorForceProfile_ackcmd) {
            actorIdx = SAL__MTM1M3_command_runMirrorForceProfile_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_runMirrorForceProfile");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_RunMirrorForceProfile = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_RunMirrorForceProfile_ackcmd ) {
          status = mgr[LVClient].ackCommand_runMirrorForceProfile(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_RunMirrorForceProfile_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_RunMirrorForceProfile_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_RunMirrorForceProfile_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_RunMirrorForceProfile_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_RunMirrorForceProfile_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_SetThermalSetpoint) {
          actorIdx = SAL__MTM1M3_command_setThermalSetpoint_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_setThermalSetpoint");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_SetThermalSetpoint = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_SetThermalSetpoint == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_SetThermalSetpoint ) {
               status = mgr[LVClient].acceptCommand_setThermalSetpoint(Incoming_m1m3_command_SetThermalSetpoint);
            } else {
               status = mgr[LVClient].getNextSample_command_setThermalSetpoint(Incoming_m1m3_command_SetThermalSetpoint);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_SetThermalSetpoint.Setpoint=Incoming_m1m3_command_SetThermalSetpoint->setpoint;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_SetThermalSetpoint = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_SetThermalSetpoint_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_SetThermalSetpoint_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_SetThermalSetpoint_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_SetThermalSetpoint_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_setThermalSetpointC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_SetThermalSetpoint_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_SetThermalSetpoint_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_SetThermalSetpoint_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_SetThermalSetpoint_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_SetThermalSetpoint_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_SetThermalSetpoint_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_SetThermalSetpoint_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_SetThermalSetpoint) {
          actorIdx = SAL__MTM1M3_command_setThermalSetpoint_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_setThermalSetpoint");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_SetThermalSetpoint = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_SetThermalSetpoint ) {
           Outgoing_m1m3_command_SetThermalSetpoint->setpoint=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_SetThermalSetpoint.Setpoint;

          status = mgr[LVClient].issueCommand_setThermalSetpoint(Outgoing_m1m3_command_SetThermalSetpoint);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_SetThermalSetpoint_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_SetThermalSetpoint = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_SetThermalSetpoint = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_SetThermalSetpoint_ackcmd) {
            actorIdx = SAL__MTM1M3_command_setThermalSetpoint_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_setThermalSetpoint");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_SetThermalSetpoint = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_SetThermalSetpoint_ackcmd ) {
          status = mgr[LVClient].ackCommand_setThermalSetpoint(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_SetThermalSetpoint_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_SetThermalSetpoint_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_SetThermalSetpoint_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_SetThermalSetpoint_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_SetThermalSetpoint_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_Shutdown) {
          actorIdx = SAL__MTM1M3_command_shutdown_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_shutdown");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_Shutdown = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_Shutdown == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_Shutdown ) {
               status = mgr[LVClient].acceptCommand_shutdown(Incoming_m1m3_command_Shutdown);
            } else {
               status = mgr[LVClient].getNextSample_command_shutdown(Incoming_m1m3_command_Shutdown);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Shutdown.Shutdown=Incoming_m1m3_command_Shutdown->shutdown;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_Shutdown = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Shutdown_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_Shutdown_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_Shutdown_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_Shutdown_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_shutdownC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Shutdown_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_Shutdown_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Shutdown_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_Shutdown_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Shutdown_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_Shutdown_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_Shutdown_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_Shutdown) {
          actorIdx = SAL__MTM1M3_command_shutdown_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_shutdown");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_Shutdown = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_Shutdown ) {
           Outgoing_m1m3_command_Shutdown->shutdown=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Shutdown.Shutdown;

          status = mgr[LVClient].issueCommand_shutdown(Outgoing_m1m3_command_Shutdown);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Shutdown_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_Shutdown = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_Shutdown = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_Shutdown_ackcmd) {
            actorIdx = SAL__MTM1M3_command_shutdown_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_shutdown");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_Shutdown = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_Shutdown_ackcmd ) {
          status = mgr[LVClient].ackCommand_shutdown(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Shutdown_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Shutdown_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Shutdown_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Shutdown_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_Shutdown_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_Standby) {
          actorIdx = SAL__MTM1M3_command_standby_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_standby");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_Standby = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_Standby == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_Standby ) {
               status = mgr[LVClient].acceptCommand_standby(Incoming_m1m3_command_Standby);
            } else {
               status = mgr[LVClient].getNextSample_command_standby(Incoming_m1m3_command_Standby);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Standby.Standby=Incoming_m1m3_command_Standby->value;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_Standby = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Standby_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_Standby_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_Standby_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_Standby_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_standbyC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Standby_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_Standby_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Standby_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_Standby_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Standby_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_Standby_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_Standby_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_Standby) {
          actorIdx = SAL__MTM1M3_command_standby_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_standby");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_Standby = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_Standby ) {
           Outgoing_m1m3_command_Standby->value=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Standby.Standby;

          status = mgr[LVClient].issueCommand_standby(Outgoing_m1m3_command_Standby);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Standby_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_Standby = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_Standby = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_Standby_ackcmd) {
            actorIdx = SAL__MTM1M3_command_standby_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_standby");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_Standby = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_Standby_ackcmd ) {
          status = mgr[LVClient].ackCommand_standby(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Standby_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Standby_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Standby_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Standby_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_Standby_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_Start) {
          actorIdx = SAL__MTM1M3_command_start_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_start");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_Start = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_Start == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_Start ) {
               status = mgr[LVClient].acceptCommand_start(Incoming_m1m3_command_Start);
            } else {
               status = mgr[LVClient].getNextSample_command_start(Incoming_m1m3_command_Start);
            }
            if (status > 0) {
             strcpy(m1m3_memIO->client[LVClient].m1m3_command_StartLV_SettingsToApply_bufferIn,Incoming_m1m3_command_Start->settingsToApply.c_str());

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_Start = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Start_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_Start_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_Start_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_Start_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_startC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Start_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_Start_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Start_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_Start_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_Start_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_Start_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_Start_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_Start) {
          actorIdx = SAL__MTM1M3_command_start_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_start");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_Start = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_Start ) {
            Outgoing_m1m3_command_Start->settingsToApply=m1m3_memIO->client[LVClient].m1m3_command_StartLV_SettingsToApply_bufferOut;

          status = mgr[LVClient].issueCommand_start(Outgoing_m1m3_command_Start);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Start_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_Start = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_Start = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_Start_ackcmd) {
            actorIdx = SAL__MTM1M3_command_start_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_start");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_Start = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_Start_ackcmd ) {
          status = mgr[LVClient].ackCommand_start(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Start_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Start_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Start_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_Start_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_Start_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_StopHardpointMotion) {
          actorIdx = SAL__MTM1M3_command_stopHardpointMotion_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_stopHardpointMotion");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_StopHardpointMotion = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_StopHardpointMotion == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_StopHardpointMotion ) {
               status = mgr[LVClient].acceptCommand_stopHardpointMotion(Incoming_m1m3_command_StopHardpointMotion);
            } else {
               status = mgr[LVClient].getNextSample_command_stopHardpointMotion(Incoming_m1m3_command_StopHardpointMotion);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_StopHardpointMotion.StopHardpointMotion=Incoming_m1m3_command_StopHardpointMotion->stopHardpointMotion;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_StopHardpointMotion = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_StopHardpointMotion_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_StopHardpointMotion_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_StopHardpointMotion_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_StopHardpointMotion_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_stopHardpointMotionC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_StopHardpointMotion_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_StopHardpointMotion_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_StopHardpointMotion_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_StopHardpointMotion_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_StopHardpointMotion_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_StopHardpointMotion_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_StopHardpointMotion_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_StopHardpointMotion) {
          actorIdx = SAL__MTM1M3_command_stopHardpointMotion_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_stopHardpointMotion");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_StopHardpointMotion = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_StopHardpointMotion ) {
           Outgoing_m1m3_command_StopHardpointMotion->stopHardpointMotion=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_StopHardpointMotion.StopHardpointMotion;

          status = mgr[LVClient].issueCommand_stopHardpointMotion(Outgoing_m1m3_command_StopHardpointMotion);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_StopHardpointMotion_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_StopHardpointMotion = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_StopHardpointMotion = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_StopHardpointMotion_ackcmd) {
            actorIdx = SAL__MTM1M3_command_stopHardpointMotion_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_stopHardpointMotion");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_StopHardpointMotion = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_StopHardpointMotion_ackcmd ) {
          status = mgr[LVClient].ackCommand_stopHardpointMotion(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_StopHardpointMotion_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_StopHardpointMotion_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_StopHardpointMotion_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_StopHardpointMotion_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_StopHardpointMotion_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_TestAir) {
          actorIdx = SAL__MTM1M3_command_testAir_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_testAir");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_TestAir = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TestAir == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_TestAir ) {
               status = mgr[LVClient].acceptCommand_testAir(Incoming_m1m3_command_TestAir);
            } else {
               status = mgr[LVClient].getNextSample_command_testAir(Incoming_m1m3_command_TestAir);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TestAir.TestAir=Incoming_m1m3_command_TestAir->testAir;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TestAir = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TestAir_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_TestAir_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_TestAir_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TestAir_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_testAirC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TestAir_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_TestAir_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TestAir_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_TestAir_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TestAir_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_TestAir_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TestAir_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_TestAir) {
          actorIdx = SAL__MTM1M3_command_testAir_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_testAir");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_TestAir = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TestAir ) {
           Outgoing_m1m3_command_TestAir->testAir=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TestAir.TestAir;

          status = mgr[LVClient].issueCommand_testAir(Outgoing_m1m3_command_TestAir);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TestAir_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TestAir = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_TestAir = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_TestAir_ackcmd) {
            actorIdx = SAL__MTM1M3_command_testAir_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_testAir");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_TestAir = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TestAir_ackcmd ) {
          status = mgr[LVClient].ackCommand_testAir(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TestAir_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TestAir_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TestAir_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TestAir_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TestAir_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_TestForceActuator) {
          actorIdx = SAL__MTM1M3_command_testForceActuator_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_testForceActuator");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_TestForceActuator = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TestForceActuator == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_TestForceActuator ) {
               status = mgr[LVClient].acceptCommand_testForceActuator(Incoming_m1m3_command_TestForceActuator);
            } else {
               status = mgr[LVClient].getNextSample_command_testForceActuator(Incoming_m1m3_command_TestForceActuator);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TestForceActuator.ForceActuator=Incoming_m1m3_command_TestForceActuator->forceActuator;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TestForceActuator = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TestForceActuator_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_TestForceActuator_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_TestForceActuator_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TestForceActuator_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_testForceActuatorC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TestForceActuator_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_TestForceActuator_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TestForceActuator_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_TestForceActuator_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TestForceActuator_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_TestForceActuator_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TestForceActuator_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_TestForceActuator) {
          actorIdx = SAL__MTM1M3_command_testForceActuator_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_testForceActuator");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_TestForceActuator = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TestForceActuator ) {
           Outgoing_m1m3_command_TestForceActuator->forceActuator=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TestForceActuator.ForceActuator;

          status = mgr[LVClient].issueCommand_testForceActuator(Outgoing_m1m3_command_TestForceActuator);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TestForceActuator_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TestForceActuator = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_TestForceActuator = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_TestForceActuator_ackcmd) {
            actorIdx = SAL__MTM1M3_command_testForceActuator_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_testForceActuator");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_TestForceActuator = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TestForceActuator_ackcmd ) {
          status = mgr[LVClient].ackCommand_testForceActuator(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TestForceActuator_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TestForceActuator_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TestForceActuator_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TestForceActuator_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TestForceActuator_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_TestHardpoint) {
          actorIdx = SAL__MTM1M3_command_testHardpoint_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_testHardpoint");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_TestHardpoint = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TestHardpoint == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_TestHardpoint ) {
               status = mgr[LVClient].acceptCommand_testHardpoint(Incoming_m1m3_command_TestHardpoint);
            } else {
               status = mgr[LVClient].getNextSample_command_testHardpoint(Incoming_m1m3_command_TestHardpoint);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TestHardpoint.HardpointActuator=Incoming_m1m3_command_TestHardpoint->hardpointActuator;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TestHardpoint = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TestHardpoint_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_TestHardpoint_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_TestHardpoint_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TestHardpoint_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_testHardpointC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TestHardpoint_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_TestHardpoint_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TestHardpoint_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_TestHardpoint_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TestHardpoint_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_TestHardpoint_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TestHardpoint_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_TestHardpoint) {
          actorIdx = SAL__MTM1M3_command_testHardpoint_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_testHardpoint");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_TestHardpoint = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TestHardpoint ) {
           Outgoing_m1m3_command_TestHardpoint->hardpointActuator=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TestHardpoint.HardpointActuator;

          status = mgr[LVClient].issueCommand_testHardpoint(Outgoing_m1m3_command_TestHardpoint);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TestHardpoint_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TestHardpoint = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_TestHardpoint = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_TestHardpoint_ackcmd) {
            actorIdx = SAL__MTM1M3_command_testHardpoint_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_testHardpoint");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_TestHardpoint = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TestHardpoint_ackcmd ) {
          status = mgr[LVClient].ackCommand_testHardpoint(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TestHardpoint_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TestHardpoint_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TestHardpoint_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TestHardpoint_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TestHardpoint_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_TranslateM1M3) {
          actorIdx = SAL__MTM1M3_command_translateM1M3_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_translateM1M3");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_TranslateM1M3 = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TranslateM1M3 == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_TranslateM1M3 ) {
               status = mgr[LVClient].acceptCommand_translateM1M3(Incoming_m1m3_command_TranslateM1M3);
            } else {
               status = mgr[LVClient].getNextSample_command_translateM1M3(Incoming_m1m3_command_TranslateM1M3);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TranslateM1M3.XTranslation=Incoming_m1m3_command_TranslateM1M3->xTranslation;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TranslateM1M3.YTranslation=Incoming_m1m3_command_TranslateM1M3->yTranslation;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TranslateM1M3.ZTranslation=Incoming_m1m3_command_TranslateM1M3->zTranslation;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TranslateM1M3.XRotation=Incoming_m1m3_command_TranslateM1M3->xRotation;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TranslateM1M3.YRotation=Incoming_m1m3_command_TranslateM1M3->yRotation;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TranslateM1M3.ZRotation=Incoming_m1m3_command_TranslateM1M3->zRotation;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TranslateM1M3 = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TranslateM1M3_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_TranslateM1M3_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_TranslateM1M3_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TranslateM1M3_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_translateM1M3C(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TranslateM1M3_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_TranslateM1M3_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TranslateM1M3_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_TranslateM1M3_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TranslateM1M3_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_TranslateM1M3_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TranslateM1M3_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_TranslateM1M3) {
          actorIdx = SAL__MTM1M3_command_translateM1M3_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_translateM1M3");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_TranslateM1M3 = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TranslateM1M3 ) {
           Outgoing_m1m3_command_TranslateM1M3->xTranslation=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TranslateM1M3.XTranslation;
           Outgoing_m1m3_command_TranslateM1M3->yTranslation=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TranslateM1M3.YTranslation;
           Outgoing_m1m3_command_TranslateM1M3->zTranslation=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TranslateM1M3.ZTranslation;
           Outgoing_m1m3_command_TranslateM1M3->xRotation=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TranslateM1M3.XRotation;
           Outgoing_m1m3_command_TranslateM1M3->yRotation=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TranslateM1M3.YRotation;
           Outgoing_m1m3_command_TranslateM1M3->zRotation=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TranslateM1M3.ZRotation;

          status = mgr[LVClient].issueCommand_translateM1M3(Outgoing_m1m3_command_TranslateM1M3);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TranslateM1M3_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TranslateM1M3 = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_TranslateM1M3 = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_TranslateM1M3_ackcmd) {
            actorIdx = SAL__MTM1M3_command_translateM1M3_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_translateM1M3");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_TranslateM1M3 = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TranslateM1M3_ackcmd ) {
          status = mgr[LVClient].ackCommand_translateM1M3(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TranslateM1M3_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TranslateM1M3_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TranslateM1M3_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TranslateM1M3_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TranslateM1M3_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_TurnAirOff) {
          actorIdx = SAL__MTM1M3_command_turnAirOff_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_turnAirOff");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_TurnAirOff = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnAirOff == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_TurnAirOff ) {
               status = mgr[LVClient].acceptCommand_turnAirOff(Incoming_m1m3_command_TurnAirOff);
            } else {
               status = mgr[LVClient].getNextSample_command_turnAirOff(Incoming_m1m3_command_TurnAirOff);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnAirOff.TurnAirOff=Incoming_m1m3_command_TurnAirOff->turnAirOff;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnAirOff = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnAirOff_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_TurnAirOff_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_TurnAirOff_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnAirOff_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_turnAirOffC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnAirOff_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_TurnAirOff_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnAirOff_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_TurnAirOff_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnAirOff_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_TurnAirOff_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnAirOff_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_TurnAirOff) {
          actorIdx = SAL__MTM1M3_command_turnAirOff_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_turnAirOff");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_TurnAirOff = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnAirOff ) {
           Outgoing_m1m3_command_TurnAirOff->turnAirOff=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnAirOff.TurnAirOff;

          status = mgr[LVClient].issueCommand_turnAirOff(Outgoing_m1m3_command_TurnAirOff);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnAirOff_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnAirOff = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_TurnAirOff = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_TurnAirOff_ackcmd) {
            actorIdx = SAL__MTM1M3_command_turnAirOff_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_turnAirOff");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_TurnAirOff = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnAirOff_ackcmd ) {
          status = mgr[LVClient].ackCommand_turnAirOff(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnAirOff_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnAirOff_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnAirOff_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnAirOff_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnAirOff_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_TurnAirOn) {
          actorIdx = SAL__MTM1M3_command_turnAirOn_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_turnAirOn");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_TurnAirOn = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnAirOn == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_TurnAirOn ) {
               status = mgr[LVClient].acceptCommand_turnAirOn(Incoming_m1m3_command_TurnAirOn);
            } else {
               status = mgr[LVClient].getNextSample_command_turnAirOn(Incoming_m1m3_command_TurnAirOn);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnAirOn.TurnAirOn=Incoming_m1m3_command_TurnAirOn->turnAirOn;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnAirOn = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnAirOn_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_TurnAirOn_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_TurnAirOn_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnAirOn_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_turnAirOnC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnAirOn_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_TurnAirOn_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnAirOn_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_TurnAirOn_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnAirOn_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_TurnAirOn_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnAirOn_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_TurnAirOn) {
          actorIdx = SAL__MTM1M3_command_turnAirOn_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_turnAirOn");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_TurnAirOn = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnAirOn ) {
           Outgoing_m1m3_command_TurnAirOn->turnAirOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnAirOn.TurnAirOn;

          status = mgr[LVClient].issueCommand_turnAirOn(Outgoing_m1m3_command_TurnAirOn);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnAirOn_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnAirOn = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_TurnAirOn = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_TurnAirOn_ackcmd) {
            actorIdx = SAL__MTM1M3_command_turnAirOn_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_turnAirOn");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_TurnAirOn = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnAirOn_ackcmd ) {
          status = mgr[LVClient].ackCommand_turnAirOn(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnAirOn_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnAirOn_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnAirOn_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnAirOn_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnAirOn_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_TurnLightsOff) {
          actorIdx = SAL__MTM1M3_command_turnLightsOff_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_turnLightsOff");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_TurnLightsOff = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnLightsOff == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_TurnLightsOff ) {
               status = mgr[LVClient].acceptCommand_turnLightsOff(Incoming_m1m3_command_TurnLightsOff);
            } else {
               status = mgr[LVClient].getNextSample_command_turnLightsOff(Incoming_m1m3_command_TurnLightsOff);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnLightsOff.TurnLightsOff=Incoming_m1m3_command_TurnLightsOff->turnLightsOff;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnLightsOff = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnLightsOff_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_TurnLightsOff_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_TurnLightsOff_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnLightsOff_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_turnLightsOffC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnLightsOff_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_TurnLightsOff_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnLightsOff_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_TurnLightsOff_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnLightsOff_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_TurnLightsOff_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnLightsOff_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_TurnLightsOff) {
          actorIdx = SAL__MTM1M3_command_turnLightsOff_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_turnLightsOff");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_TurnLightsOff = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnLightsOff ) {
           Outgoing_m1m3_command_TurnLightsOff->turnLightsOff=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnLightsOff.TurnLightsOff;

          status = mgr[LVClient].issueCommand_turnLightsOff(Outgoing_m1m3_command_TurnLightsOff);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnLightsOff_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnLightsOff = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_TurnLightsOff = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_TurnLightsOff_ackcmd) {
            actorIdx = SAL__MTM1M3_command_turnLightsOff_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_turnLightsOff");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_TurnLightsOff = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnLightsOff_ackcmd ) {
          status = mgr[LVClient].ackCommand_turnLightsOff(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnLightsOff_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnLightsOff_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnLightsOff_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnLightsOff_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnLightsOff_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_TurnLightsOn) {
          actorIdx = SAL__MTM1M3_command_turnLightsOn_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_turnLightsOn");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_TurnLightsOn = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnLightsOn == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_TurnLightsOn ) {
               status = mgr[LVClient].acceptCommand_turnLightsOn(Incoming_m1m3_command_TurnLightsOn);
            } else {
               status = mgr[LVClient].getNextSample_command_turnLightsOn(Incoming_m1m3_command_TurnLightsOn);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnLightsOn.TurnLightsOn=Incoming_m1m3_command_TurnLightsOn->turnLightsOn;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnLightsOn = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnLightsOn_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_TurnLightsOn_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_TurnLightsOn_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnLightsOn_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_turnLightsOnC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnLightsOn_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_TurnLightsOn_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnLightsOn_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_TurnLightsOn_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnLightsOn_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_TurnLightsOn_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnLightsOn_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_TurnLightsOn) {
          actorIdx = SAL__MTM1M3_command_turnLightsOn_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_turnLightsOn");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_TurnLightsOn = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnLightsOn ) {
           Outgoing_m1m3_command_TurnLightsOn->turnLightsOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnLightsOn.TurnLightsOn;

          status = mgr[LVClient].issueCommand_turnLightsOn(Outgoing_m1m3_command_TurnLightsOn);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnLightsOn_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnLightsOn = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_TurnLightsOn = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_TurnLightsOn_ackcmd) {
            actorIdx = SAL__MTM1M3_command_turnLightsOn_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_turnLightsOn");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_TurnLightsOn = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnLightsOn_ackcmd ) {
          status = mgr[LVClient].ackCommand_turnLightsOn(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnLightsOn_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnLightsOn_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnLightsOn_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnLightsOn_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnLightsOn_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_TurnPowerOff) {
          actorIdx = SAL__MTM1M3_command_turnPowerOff_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_turnPowerOff");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_TurnPowerOff = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnPowerOff == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_TurnPowerOff ) {
               status = mgr[LVClient].acceptCommand_turnPowerOff(Incoming_m1m3_command_TurnPowerOff);
            } else {
               status = mgr[LVClient].getNextSample_command_turnPowerOff(Incoming_m1m3_command_TurnPowerOff);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOff.TurnPowerNetworkAOff=Incoming_m1m3_command_TurnPowerOff->turnPowerNetworkAOff;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOff.TurnPowerNetworkBOff=Incoming_m1m3_command_TurnPowerOff->turnPowerNetworkBOff;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOff.TurnPowerNetworkCOff=Incoming_m1m3_command_TurnPowerOff->turnPowerNetworkCOff;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOff.TurnPowerNetworkDOff=Incoming_m1m3_command_TurnPowerOff->turnPowerNetworkDOff;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOff.TurnAuxPowerNetworkAOff=Incoming_m1m3_command_TurnPowerOff->turnAuxPowerNetworkAOff;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOff.TurnAuxPowerNetworkBOff=Incoming_m1m3_command_TurnPowerOff->turnAuxPowerNetworkBOff;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOff.TurnAuxPowerNetworkCOff=Incoming_m1m3_command_TurnPowerOff->turnAuxPowerNetworkCOff;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOff.TurnAuxPowerNetworkDOff=Incoming_m1m3_command_TurnPowerOff->turnAuxPowerNetworkDOff;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnPowerOff = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOff_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_TurnPowerOff_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_TurnPowerOff_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnPowerOff_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_turnPowerOffC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOff_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_TurnPowerOff_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOff_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_TurnPowerOff_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOff_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_TurnPowerOff_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnPowerOff_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_TurnPowerOff) {
          actorIdx = SAL__MTM1M3_command_turnPowerOff_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_turnPowerOff");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_TurnPowerOff = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnPowerOff ) {
           Outgoing_m1m3_command_TurnPowerOff->turnPowerNetworkAOff=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOff.TurnPowerNetworkAOff;
           Outgoing_m1m3_command_TurnPowerOff->turnPowerNetworkBOff=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOff.TurnPowerNetworkBOff;
           Outgoing_m1m3_command_TurnPowerOff->turnPowerNetworkCOff=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOff.TurnPowerNetworkCOff;
           Outgoing_m1m3_command_TurnPowerOff->turnPowerNetworkDOff=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOff.TurnPowerNetworkDOff;
           Outgoing_m1m3_command_TurnPowerOff->turnAuxPowerNetworkAOff=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOff.TurnAuxPowerNetworkAOff;
           Outgoing_m1m3_command_TurnPowerOff->turnAuxPowerNetworkBOff=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOff.TurnAuxPowerNetworkBOff;
           Outgoing_m1m3_command_TurnPowerOff->turnAuxPowerNetworkCOff=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOff.TurnAuxPowerNetworkCOff;
           Outgoing_m1m3_command_TurnPowerOff->turnAuxPowerNetworkDOff=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOff.TurnAuxPowerNetworkDOff;

          status = mgr[LVClient].issueCommand_turnPowerOff(Outgoing_m1m3_command_TurnPowerOff);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOff_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnPowerOff = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_TurnPowerOff = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_TurnPowerOff_ackcmd) {
            actorIdx = SAL__MTM1M3_command_turnPowerOff_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_turnPowerOff");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_TurnPowerOff = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnPowerOff_ackcmd ) {
          status = mgr[LVClient].ackCommand_turnPowerOff(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOff_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOff_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOff_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOff_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnPowerOff_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_TurnPowerOn) {
          actorIdx = SAL__MTM1M3_command_turnPowerOn_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_turnPowerOn");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_TurnPowerOn = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnPowerOn == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_TurnPowerOn ) {
               status = mgr[LVClient].acceptCommand_turnPowerOn(Incoming_m1m3_command_TurnPowerOn);
            } else {
               status = mgr[LVClient].getNextSample_command_turnPowerOn(Incoming_m1m3_command_TurnPowerOn);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOn.TurnPowerNetworkAOn=Incoming_m1m3_command_TurnPowerOn->turnPowerNetworkAOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOn.TurnPowerNetworkBOn=Incoming_m1m3_command_TurnPowerOn->turnPowerNetworkBOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOn.TurnPowerNetworkCOn=Incoming_m1m3_command_TurnPowerOn->turnPowerNetworkCOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOn.TurnPowerNetworkDOn=Incoming_m1m3_command_TurnPowerOn->turnPowerNetworkDOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOn.TurnAuxPowerNetworkAOn=Incoming_m1m3_command_TurnPowerOn->turnAuxPowerNetworkAOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOn.TurnAuxPowerNetworkBOn=Incoming_m1m3_command_TurnPowerOn->turnAuxPowerNetworkBOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOn.TurnAuxPowerNetworkCOn=Incoming_m1m3_command_TurnPowerOn->turnAuxPowerNetworkCOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOn.TurnAuxPowerNetworkDOn=Incoming_m1m3_command_TurnPowerOn->turnAuxPowerNetworkDOn;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnPowerOn = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOn_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_TurnPowerOn_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_TurnPowerOn_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnPowerOn_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_turnPowerOnC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOn_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_TurnPowerOn_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOn_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_TurnPowerOn_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_TurnPowerOn_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_TurnPowerOn_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_TurnPowerOn_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_TurnPowerOn) {
          actorIdx = SAL__MTM1M3_command_turnPowerOn_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_turnPowerOn");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_TurnPowerOn = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnPowerOn ) {
           Outgoing_m1m3_command_TurnPowerOn->turnPowerNetworkAOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOn.TurnPowerNetworkAOn;
           Outgoing_m1m3_command_TurnPowerOn->turnPowerNetworkBOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOn.TurnPowerNetworkBOn;
           Outgoing_m1m3_command_TurnPowerOn->turnPowerNetworkCOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOn.TurnPowerNetworkCOn;
           Outgoing_m1m3_command_TurnPowerOn->turnPowerNetworkDOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOn.TurnPowerNetworkDOn;
           Outgoing_m1m3_command_TurnPowerOn->turnAuxPowerNetworkAOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOn.TurnAuxPowerNetworkAOn;
           Outgoing_m1m3_command_TurnPowerOn->turnAuxPowerNetworkBOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOn.TurnAuxPowerNetworkBOn;
           Outgoing_m1m3_command_TurnPowerOn->turnAuxPowerNetworkCOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOn.TurnAuxPowerNetworkCOn;
           Outgoing_m1m3_command_TurnPowerOn->turnAuxPowerNetworkDOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOn.TurnAuxPowerNetworkDOn;

          status = mgr[LVClient].issueCommand_turnPowerOn(Outgoing_m1m3_command_TurnPowerOn);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOn_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnPowerOn = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_TurnPowerOn = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_TurnPowerOn_ackcmd) {
            actorIdx = SAL__MTM1M3_command_turnPowerOn_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_turnPowerOn");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_TurnPowerOn = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnPowerOn_ackcmd ) {
          status = mgr[LVClient].ackCommand_turnPowerOn(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOn_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOn_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOn_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_TurnPowerOn_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_TurnPowerOn_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_UpdatePID) {
          actorIdx = SAL__MTM1M3_command_updatePID_ACTOR;
          if (mgr[LVClient].actorProcessor(actorIdx) == false) {
             mgr[LVClient].salProcessor("MTM1M3_command_updatePID");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasReader_m1m3_command_UpdatePID = true;
          }
          if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_UpdatePID == false) {
            if ( m1m3_memIO->client[LVClient].ackIt_m1m3_command_UpdatePID ) {
               status = mgr[LVClient].acceptCommand_updatePID(Incoming_m1m3_command_UpdatePID);
            } else {
               status = mgr[LVClient].getNextSample_command_updatePID(Incoming_m1m3_command_UpdatePID);
            }
            if (status > 0) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_UpdatePID.PID=Incoming_m1m3_command_UpdatePID->pid;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_UpdatePID.Timestep=Incoming_m1m3_command_UpdatePID->timestep;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_UpdatePID.P=Incoming_m1m3_command_UpdatePID->p;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_UpdatePID.I=Incoming_m1m3_command_UpdatePID->i;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_UpdatePID.D=Incoming_m1m3_command_UpdatePID->d;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_UpdatePID.N=Incoming_m1m3_command_UpdatePID->n;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_UpdatePID = true;
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_UpdatePID_rcvSeqNum = status;
            }
          }
       }
       if (m1m3_memIO->client[LVClient].activeCommand == SAL__m1m3_command_UpdatePID_ACTOR) {
       if (m1m3_memIO->client[LVClient].syncI_m1m3_command_UpdatePID_ackcmd) {
       if (m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_UpdatePID_ackcmd == false) {
          MTM1M3_ackcmdC response;
          actorIdx = SAL__MTM1M3_ackcmd_ACTOR;
          status = mgr[LVClient].getResponse_updatePIDC(&response);;
          m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
          if (status == SAL__CMD_COMPLETE) {
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_UpdatePID_rcvSeqNum = mgr[LVClient].getIntProperty(SAL__m1m3_command_UpdatePID_ACTOR , "rcvSeqNum");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_UpdatePID_cmdStatus = mgr[LVClient].getIntProperty(SAL__m1m3_command_UpdatePID_ACTOR , "ack");
             m1m3_memIO->client[LVClient].shmemIncoming_m1m3_command_UpdatePID_errorCode = mgr[LVClient].getIntProperty(SAL__m1m3_command_UpdatePID_ACTOR , "error");
             m1m3_memIO->client[LVClient].hasIncoming_m1m3_command_UpdatePID_ackcmd = true;
           }
        }
       }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_UpdatePID) {
          actorIdx = SAL__MTM1M3_command_updatePID_ACTOR;
          if (mgr[LVClient].actorCommand(actorIdx) == false) {
             mgr[LVClient].salCommand("MTM1M3_command_updatePID");
             m1m3_memIO->client[LVClient].hasReader_m1m3_ackcmd = true;
             m1m3_memIO->client[LVClient].hasWriter_m1m3_command_UpdatePID = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_UpdatePID ) {
           Outgoing_m1m3_command_UpdatePID->pid=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_UpdatePID.PID;
           Outgoing_m1m3_command_UpdatePID->timestep=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_UpdatePID.Timestep;
           Outgoing_m1m3_command_UpdatePID->p=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_UpdatePID.P;
           Outgoing_m1m3_command_UpdatePID->i=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_UpdatePID.I;
           Outgoing_m1m3_command_UpdatePID->d=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_UpdatePID.D;
           Outgoing_m1m3_command_UpdatePID->n=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_UpdatePID.N;

          status = mgr[LVClient].issueCommand_updatePID(Outgoing_m1m3_command_UpdatePID);
          m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_UpdatePID_cmdSeqNum = status;
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_UpdatePID = false;
          m1m3_memIO->client[LVClient].hasWriter_m1m3_command_UpdatePID = true;
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_command_UpdatePID_ackcmd) {
            actorIdx = SAL__MTM1M3_command_updatePID_ACTOR;
            if (mgr[LVClient].actorProcessor(actorIdx) == false) {
              mgr[LVClient].salProcessor("MTM1M3_command_updatePID");
              m1m3_memIO->client[LVClient].hasWriter_m1m3_ackcmd = true;
              m1m3_memIO->client[LVClient].hasReader_m1m3_command_UpdatePID = true;
            }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_UpdatePID_ackcmd ) {
          status = mgr[LVClient].ackCommand_updatePID(
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_UpdatePID_cmdSeqNum,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_UpdatePID_cmdStatus,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_UpdatePID_errorCode,
				m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_command_UpdatePID_resultCode
                                          );
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_command_UpdatePID_ackcmd = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_AccelerometerWarning) {
          actorIdx = SAL__MTM1M3_logevent_accelerometerWarning_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_accelerometerWarning");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_AccelerometerWarning = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AccelerometerWarning == false ) {
           status = mgr[LVClient].getEvent_accelerometerWarning(Incoming_m1m3_logevent_AccelerometerWarning);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AccelerometerWarning.Timestamp=Incoming_m1m3_logevent_AccelerometerWarning->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AccelerometerWarning.AnyWarning=Incoming_m1m3_logevent_AccelerometerWarning->anyWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AccelerometerWarning.ResponseTimeout=Incoming_m1m3_logevent_AccelerometerWarning->responseTimeout;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AccelerometerWarning.priority=Incoming_m1m3_logevent_AccelerometerWarning->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AccelerometerWarning = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_AccelerometerWarning) {
          actorIdx = SAL__MTM1M3_logevent_accelerometerWarning_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_accelerometerWarning");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_AccelerometerWarning = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AccelerometerWarning ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AccelerometerWarning.priority;
           Outgoing_m1m3_logevent_AccelerometerWarning->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AccelerometerWarning.Timestamp;
           Outgoing_m1m3_logevent_AccelerometerWarning->anyWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AccelerometerWarning.AnyWarning;
           Outgoing_m1m3_logevent_AccelerometerWarning->responseTimeout=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AccelerometerWarning.ResponseTimeout;
           Outgoing_m1m3_logevent_AccelerometerWarning->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AccelerometerWarning.priority;

          status = mgr[LVClient].logEvent_accelerometerWarning(Outgoing_m1m3_logevent_AccelerometerWarning,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AccelerometerWarning = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_AirSupplyStatus) {
          actorIdx = SAL__MTM1M3_logevent_airSupplyStatus_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_airSupplyStatus");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_AirSupplyStatus = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AirSupplyStatus == false ) {
           status = mgr[LVClient].getEvent_airSupplyStatus(Incoming_m1m3_logevent_AirSupplyStatus);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AirSupplyStatus.Timestamp=Incoming_m1m3_logevent_AirSupplyStatus->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AirSupplyStatus.AirCommandedOn=Incoming_m1m3_logevent_AirSupplyStatus->airCommandedOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AirSupplyStatus.AirCommandOutputOn=Incoming_m1m3_logevent_AirSupplyStatus->airCommandOutputOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AirSupplyStatus.AirValveOpened=Incoming_m1m3_logevent_AirSupplyStatus->airValveOpened;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AirSupplyStatus.AirValveClosed=Incoming_m1m3_logevent_AirSupplyStatus->airValveClosed;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AirSupplyStatus.priority=Incoming_m1m3_logevent_AirSupplyStatus->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AirSupplyStatus = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_AirSupplyStatus) {
          actorIdx = SAL__MTM1M3_logevent_airSupplyStatus_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_airSupplyStatus");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_AirSupplyStatus = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AirSupplyStatus ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AirSupplyStatus.priority;
           Outgoing_m1m3_logevent_AirSupplyStatus->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AirSupplyStatus.Timestamp;
           Outgoing_m1m3_logevent_AirSupplyStatus->airCommandedOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AirSupplyStatus.AirCommandedOn;
           Outgoing_m1m3_logevent_AirSupplyStatus->airCommandOutputOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AirSupplyStatus.AirCommandOutputOn;
           Outgoing_m1m3_logevent_AirSupplyStatus->airValveOpened=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AirSupplyStatus.AirValveOpened;
           Outgoing_m1m3_logevent_AirSupplyStatus->airValveClosed=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AirSupplyStatus.AirValveClosed;
           Outgoing_m1m3_logevent_AirSupplyStatus->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AirSupplyStatus.priority;

          status = mgr[LVClient].logEvent_airSupplyStatus(Outgoing_m1m3_logevent_AirSupplyStatus,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AirSupplyStatus = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_AirSupplyWarning) {
          actorIdx = SAL__MTM1M3_logevent_airSupplyWarning_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_airSupplyWarning");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_AirSupplyWarning = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AirSupplyWarning == false ) {
           status = mgr[LVClient].getEvent_airSupplyWarning(Incoming_m1m3_logevent_AirSupplyWarning);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AirSupplyWarning.Timestamp=Incoming_m1m3_logevent_AirSupplyWarning->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AirSupplyWarning.AnyWarning=Incoming_m1m3_logevent_AirSupplyWarning->anyWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AirSupplyWarning.CommandOutputMismatch=Incoming_m1m3_logevent_AirSupplyWarning->commandOutputMismatch;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AirSupplyWarning.CommandSensorMismatch=Incoming_m1m3_logevent_AirSupplyWarning->commandSensorMismatch;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AirSupplyWarning.priority=Incoming_m1m3_logevent_AirSupplyWarning->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AirSupplyWarning = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_AirSupplyWarning) {
          actorIdx = SAL__MTM1M3_logevent_airSupplyWarning_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_airSupplyWarning");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_AirSupplyWarning = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AirSupplyWarning ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AirSupplyWarning.priority;
           Outgoing_m1m3_logevent_AirSupplyWarning->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AirSupplyWarning.Timestamp;
           Outgoing_m1m3_logevent_AirSupplyWarning->anyWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AirSupplyWarning.AnyWarning;
           Outgoing_m1m3_logevent_AirSupplyWarning->commandOutputMismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AirSupplyWarning.CommandOutputMismatch;
           Outgoing_m1m3_logevent_AirSupplyWarning->commandSensorMismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AirSupplyWarning.CommandSensorMismatch;
           Outgoing_m1m3_logevent_AirSupplyWarning->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AirSupplyWarning.priority;

          status = mgr[LVClient].logEvent_airSupplyWarning(Outgoing_m1m3_logevent_AirSupplyWarning,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AirSupplyWarning = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_AppliedAberrationForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedAberrationForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_appliedAberrationForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_AppliedAberrationForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedAberrationForces == false ) {
           status = mgr[LVClient].getEvent_appliedAberrationForces(Incoming_m1m3_logevent_AppliedAberrationForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAberrationForces.Timestamp=Incoming_m1m3_logevent_AppliedAberrationForces->timestamp;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAberrationForces.ZForces[i]=Incoming_m1m3_logevent_AppliedAberrationForces->zForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAberrationForces.Fz=Incoming_m1m3_logevent_AppliedAberrationForces->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAberrationForces.Mx=Incoming_m1m3_logevent_AppliedAberrationForces->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAberrationForces.My=Incoming_m1m3_logevent_AppliedAberrationForces->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAberrationForces.priority=Incoming_m1m3_logevent_AppliedAberrationForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedAberrationForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_AppliedAberrationForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedAberrationForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_appliedAberrationForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_AppliedAberrationForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedAberrationForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAberrationForces.priority;
           Outgoing_m1m3_logevent_AppliedAberrationForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAberrationForces.Timestamp;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_AppliedAberrationForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAberrationForces.ZForces[i];}
           Outgoing_m1m3_logevent_AppliedAberrationForces->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAberrationForces.Fz;
           Outgoing_m1m3_logevent_AppliedAberrationForces->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAberrationForces.Mx;
           Outgoing_m1m3_logevent_AppliedAberrationForces->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAberrationForces.My;
           Outgoing_m1m3_logevent_AppliedAberrationForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAberrationForces.priority;

          status = mgr[LVClient].logEvent_appliedAberrationForces(Outgoing_m1m3_logevent_AppliedAberrationForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedAberrationForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_AppliedAccelerationForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedAccelerationForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_appliedAccelerationForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_AppliedAccelerationForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedAccelerationForces == false ) {
           status = mgr[LVClient].getEvent_appliedAccelerationForces(Incoming_m1m3_logevent_AppliedAccelerationForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAccelerationForces.Timestamp=Incoming_m1m3_logevent_AppliedAccelerationForces->timestamp;
    for (int i=0;i<12;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAccelerationForces.XForces[i]=Incoming_m1m3_logevent_AppliedAccelerationForces->xForces[i];}
    for (int i=0;i<100;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAccelerationForces.YForces[i]=Incoming_m1m3_logevent_AppliedAccelerationForces->yForces[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAccelerationForces.ZForces[i]=Incoming_m1m3_logevent_AppliedAccelerationForces->zForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAccelerationForces.Fx=Incoming_m1m3_logevent_AppliedAccelerationForces->fx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAccelerationForces.Fy=Incoming_m1m3_logevent_AppliedAccelerationForces->fy;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAccelerationForces.Fz=Incoming_m1m3_logevent_AppliedAccelerationForces->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAccelerationForces.Mx=Incoming_m1m3_logevent_AppliedAccelerationForces->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAccelerationForces.My=Incoming_m1m3_logevent_AppliedAccelerationForces->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAccelerationForces.Mz=Incoming_m1m3_logevent_AppliedAccelerationForces->mz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAccelerationForces.ForceMagnitude=Incoming_m1m3_logevent_AppliedAccelerationForces->forceMagnitude;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAccelerationForces.priority=Incoming_m1m3_logevent_AppliedAccelerationForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedAccelerationForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_AppliedAccelerationForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedAccelerationForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_appliedAccelerationForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_AppliedAccelerationForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedAccelerationForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAccelerationForces.priority;
           Outgoing_m1m3_logevent_AppliedAccelerationForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAccelerationForces.Timestamp;
    for (int i=0;i<12;i++) {Outgoing_m1m3_logevent_AppliedAccelerationForces->xForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAccelerationForces.XForces[i];}
    for (int i=0;i<100;i++) {Outgoing_m1m3_logevent_AppliedAccelerationForces->yForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAccelerationForces.YForces[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_AppliedAccelerationForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAccelerationForces.ZForces[i];}
           Outgoing_m1m3_logevent_AppliedAccelerationForces->fx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAccelerationForces.Fx;
           Outgoing_m1m3_logevent_AppliedAccelerationForces->fy=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAccelerationForces.Fy;
           Outgoing_m1m3_logevent_AppliedAccelerationForces->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAccelerationForces.Fz;
           Outgoing_m1m3_logevent_AppliedAccelerationForces->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAccelerationForces.Mx;
           Outgoing_m1m3_logevent_AppliedAccelerationForces->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAccelerationForces.My;
           Outgoing_m1m3_logevent_AppliedAccelerationForces->mz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAccelerationForces.Mz;
           Outgoing_m1m3_logevent_AppliedAccelerationForces->forceMagnitude=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAccelerationForces.ForceMagnitude;
           Outgoing_m1m3_logevent_AppliedAccelerationForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAccelerationForces.priority;

          status = mgr[LVClient].logEvent_appliedAccelerationForces(Outgoing_m1m3_logevent_AppliedAccelerationForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedAccelerationForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_AppliedActiveOpticForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedActiveOpticForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_appliedActiveOpticForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_AppliedActiveOpticForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedActiveOpticForces == false ) {
           status = mgr[LVClient].getEvent_appliedActiveOpticForces(Incoming_m1m3_logevent_AppliedActiveOpticForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedActiveOpticForces.Timestamp=Incoming_m1m3_logevent_AppliedActiveOpticForces->timestamp;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedActiveOpticForces.ZForces[i]=Incoming_m1m3_logevent_AppliedActiveOpticForces->zForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedActiveOpticForces.Fz=Incoming_m1m3_logevent_AppliedActiveOpticForces->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedActiveOpticForces.Mx=Incoming_m1m3_logevent_AppliedActiveOpticForces->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedActiveOpticForces.My=Incoming_m1m3_logevent_AppliedActiveOpticForces->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedActiveOpticForces.priority=Incoming_m1m3_logevent_AppliedActiveOpticForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedActiveOpticForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_AppliedActiveOpticForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedActiveOpticForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_appliedActiveOpticForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_AppliedActiveOpticForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedActiveOpticForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedActiveOpticForces.priority;
           Outgoing_m1m3_logevent_AppliedActiveOpticForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedActiveOpticForces.Timestamp;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_AppliedActiveOpticForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedActiveOpticForces.ZForces[i];}
           Outgoing_m1m3_logevent_AppliedActiveOpticForces->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedActiveOpticForces.Fz;
           Outgoing_m1m3_logevent_AppliedActiveOpticForces->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedActiveOpticForces.Mx;
           Outgoing_m1m3_logevent_AppliedActiveOpticForces->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedActiveOpticForces.My;
           Outgoing_m1m3_logevent_AppliedActiveOpticForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedActiveOpticForces.priority;

          status = mgr[LVClient].logEvent_appliedActiveOpticForces(Outgoing_m1m3_logevent_AppliedActiveOpticForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedActiveOpticForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_AppliedAzimuthForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedAzimuthForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_appliedAzimuthForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_AppliedAzimuthForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedAzimuthForces == false ) {
           status = mgr[LVClient].getEvent_appliedAzimuthForces(Incoming_m1m3_logevent_AppliedAzimuthForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAzimuthForces.Timestamp=Incoming_m1m3_logevent_AppliedAzimuthForces->timestamp;
    for (int i=0;i<12;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAzimuthForces.XForces[i]=Incoming_m1m3_logevent_AppliedAzimuthForces->xForces[i];}
    for (int i=0;i<100;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAzimuthForces.YForces[i]=Incoming_m1m3_logevent_AppliedAzimuthForces->yForces[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAzimuthForces.ZForces[i]=Incoming_m1m3_logevent_AppliedAzimuthForces->zForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAzimuthForces.Fx=Incoming_m1m3_logevent_AppliedAzimuthForces->fx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAzimuthForces.Fy=Incoming_m1m3_logevent_AppliedAzimuthForces->fy;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAzimuthForces.Fz=Incoming_m1m3_logevent_AppliedAzimuthForces->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAzimuthForces.Mx=Incoming_m1m3_logevent_AppliedAzimuthForces->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAzimuthForces.My=Incoming_m1m3_logevent_AppliedAzimuthForces->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAzimuthForces.Mz=Incoming_m1m3_logevent_AppliedAzimuthForces->mz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAzimuthForces.ForceMagnitude=Incoming_m1m3_logevent_AppliedAzimuthForces->forceMagnitude;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedAzimuthForces.priority=Incoming_m1m3_logevent_AppliedAzimuthForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedAzimuthForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_AppliedAzimuthForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedAzimuthForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_appliedAzimuthForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_AppliedAzimuthForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedAzimuthForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAzimuthForces.priority;
           Outgoing_m1m3_logevent_AppliedAzimuthForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAzimuthForces.Timestamp;
    for (int i=0;i<12;i++) {Outgoing_m1m3_logevent_AppliedAzimuthForces->xForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAzimuthForces.XForces[i];}
    for (int i=0;i<100;i++) {Outgoing_m1m3_logevent_AppliedAzimuthForces->yForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAzimuthForces.YForces[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_AppliedAzimuthForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAzimuthForces.ZForces[i];}
           Outgoing_m1m3_logevent_AppliedAzimuthForces->fx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAzimuthForces.Fx;
           Outgoing_m1m3_logevent_AppliedAzimuthForces->fy=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAzimuthForces.Fy;
           Outgoing_m1m3_logevent_AppliedAzimuthForces->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAzimuthForces.Fz;
           Outgoing_m1m3_logevent_AppliedAzimuthForces->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAzimuthForces.Mx;
           Outgoing_m1m3_logevent_AppliedAzimuthForces->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAzimuthForces.My;
           Outgoing_m1m3_logevent_AppliedAzimuthForces->mz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAzimuthForces.Mz;
           Outgoing_m1m3_logevent_AppliedAzimuthForces->forceMagnitude=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAzimuthForces.ForceMagnitude;
           Outgoing_m1m3_logevent_AppliedAzimuthForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedAzimuthForces.priority;

          status = mgr[LVClient].logEvent_appliedAzimuthForces(Outgoing_m1m3_logevent_AppliedAzimuthForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedAzimuthForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_AppliedBalanceForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedBalanceForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_appliedBalanceForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_AppliedBalanceForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedBalanceForces == false ) {
           status = mgr[LVClient].getEvent_appliedBalanceForces(Incoming_m1m3_logevent_AppliedBalanceForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedBalanceForces.Timestamp=Incoming_m1m3_logevent_AppliedBalanceForces->timestamp;
    for (int i=0;i<12;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedBalanceForces.XForces[i]=Incoming_m1m3_logevent_AppliedBalanceForces->xForces[i];}
    for (int i=0;i<100;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedBalanceForces.YForces[i]=Incoming_m1m3_logevent_AppliedBalanceForces->yForces[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedBalanceForces.ZForces[i]=Incoming_m1m3_logevent_AppliedBalanceForces->zForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedBalanceForces.Fx=Incoming_m1m3_logevent_AppliedBalanceForces->fx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedBalanceForces.Fy=Incoming_m1m3_logevent_AppliedBalanceForces->fy;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedBalanceForces.Fz=Incoming_m1m3_logevent_AppliedBalanceForces->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedBalanceForces.Mx=Incoming_m1m3_logevent_AppliedBalanceForces->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedBalanceForces.My=Incoming_m1m3_logevent_AppliedBalanceForces->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedBalanceForces.Mz=Incoming_m1m3_logevent_AppliedBalanceForces->mz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedBalanceForces.ForceMagnitude=Incoming_m1m3_logevent_AppliedBalanceForces->forceMagnitude;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedBalanceForces.priority=Incoming_m1m3_logevent_AppliedBalanceForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedBalanceForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_AppliedBalanceForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedBalanceForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_appliedBalanceForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_AppliedBalanceForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedBalanceForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedBalanceForces.priority;
           Outgoing_m1m3_logevent_AppliedBalanceForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedBalanceForces.Timestamp;
    for (int i=0;i<12;i++) {Outgoing_m1m3_logevent_AppliedBalanceForces->xForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedBalanceForces.XForces[i];}
    for (int i=0;i<100;i++) {Outgoing_m1m3_logevent_AppliedBalanceForces->yForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedBalanceForces.YForces[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_AppliedBalanceForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedBalanceForces.ZForces[i];}
           Outgoing_m1m3_logevent_AppliedBalanceForces->fx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedBalanceForces.Fx;
           Outgoing_m1m3_logevent_AppliedBalanceForces->fy=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedBalanceForces.Fy;
           Outgoing_m1m3_logevent_AppliedBalanceForces->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedBalanceForces.Fz;
           Outgoing_m1m3_logevent_AppliedBalanceForces->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedBalanceForces.Mx;
           Outgoing_m1m3_logevent_AppliedBalanceForces->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedBalanceForces.My;
           Outgoing_m1m3_logevent_AppliedBalanceForces->mz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedBalanceForces.Mz;
           Outgoing_m1m3_logevent_AppliedBalanceForces->forceMagnitude=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedBalanceForces.ForceMagnitude;
           Outgoing_m1m3_logevent_AppliedBalanceForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedBalanceForces.priority;

          status = mgr[LVClient].logEvent_appliedBalanceForces(Outgoing_m1m3_logevent_AppliedBalanceForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedBalanceForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_AppliedCylinderForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedCylinderForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_appliedCylinderForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_AppliedCylinderForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedCylinderForces == false ) {
           status = mgr[LVClient].getEvent_appliedCylinderForces(Incoming_m1m3_logevent_AppliedCylinderForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedCylinderForces.Timestamp=Incoming_m1m3_logevent_AppliedCylinderForces->timestamp;
    for (int i=0;i<112;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedCylinderForces.SecondaryCylinderForces[i]=Incoming_m1m3_logevent_AppliedCylinderForces->secondaryCylinderForces[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedCylinderForces.PrimaryCylinderForces[i]=Incoming_m1m3_logevent_AppliedCylinderForces->primaryCylinderForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedCylinderForces.priority=Incoming_m1m3_logevent_AppliedCylinderForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedCylinderForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_AppliedCylinderForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedCylinderForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_appliedCylinderForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_AppliedCylinderForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedCylinderForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedCylinderForces.priority;
           Outgoing_m1m3_logevent_AppliedCylinderForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedCylinderForces.Timestamp;
    for (int i=0;i<112;i++) {Outgoing_m1m3_logevent_AppliedCylinderForces->secondaryCylinderForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedCylinderForces.SecondaryCylinderForces[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_AppliedCylinderForces->primaryCylinderForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedCylinderForces.PrimaryCylinderForces[i];}
           Outgoing_m1m3_logevent_AppliedCylinderForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedCylinderForces.priority;

          status = mgr[LVClient].logEvent_appliedCylinderForces(Outgoing_m1m3_logevent_AppliedCylinderForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedCylinderForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_AppliedElevationForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedElevationForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_appliedElevationForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_AppliedElevationForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedElevationForces == false ) {
           status = mgr[LVClient].getEvent_appliedElevationForces(Incoming_m1m3_logevent_AppliedElevationForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedElevationForces.Timestamp=Incoming_m1m3_logevent_AppliedElevationForces->timestamp;
    for (int i=0;i<12;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedElevationForces.XForces[i]=Incoming_m1m3_logevent_AppliedElevationForces->xForces[i];}
    for (int i=0;i<100;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedElevationForces.YForces[i]=Incoming_m1m3_logevent_AppliedElevationForces->yForces[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedElevationForces.ZForces[i]=Incoming_m1m3_logevent_AppliedElevationForces->zForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedElevationForces.Fx=Incoming_m1m3_logevent_AppliedElevationForces->fx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedElevationForces.Fy=Incoming_m1m3_logevent_AppliedElevationForces->fy;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedElevationForces.Fz=Incoming_m1m3_logevent_AppliedElevationForces->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedElevationForces.Mx=Incoming_m1m3_logevent_AppliedElevationForces->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedElevationForces.My=Incoming_m1m3_logevent_AppliedElevationForces->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedElevationForces.Mz=Incoming_m1m3_logevent_AppliedElevationForces->mz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedElevationForces.ForceMagnitude=Incoming_m1m3_logevent_AppliedElevationForces->forceMagnitude;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedElevationForces.priority=Incoming_m1m3_logevent_AppliedElevationForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedElevationForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_AppliedElevationForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedElevationForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_appliedElevationForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_AppliedElevationForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedElevationForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedElevationForces.priority;
           Outgoing_m1m3_logevent_AppliedElevationForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedElevationForces.Timestamp;
    for (int i=0;i<12;i++) {Outgoing_m1m3_logevent_AppliedElevationForces->xForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedElevationForces.XForces[i];}
    for (int i=0;i<100;i++) {Outgoing_m1m3_logevent_AppliedElevationForces->yForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedElevationForces.YForces[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_AppliedElevationForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedElevationForces.ZForces[i];}
           Outgoing_m1m3_logevent_AppliedElevationForces->fx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedElevationForces.Fx;
           Outgoing_m1m3_logevent_AppliedElevationForces->fy=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedElevationForces.Fy;
           Outgoing_m1m3_logevent_AppliedElevationForces->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedElevationForces.Fz;
           Outgoing_m1m3_logevent_AppliedElevationForces->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedElevationForces.Mx;
           Outgoing_m1m3_logevent_AppliedElevationForces->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedElevationForces.My;
           Outgoing_m1m3_logevent_AppliedElevationForces->mz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedElevationForces.Mz;
           Outgoing_m1m3_logevent_AppliedElevationForces->forceMagnitude=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedElevationForces.ForceMagnitude;
           Outgoing_m1m3_logevent_AppliedElevationForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedElevationForces.priority;

          status = mgr[LVClient].logEvent_appliedElevationForces(Outgoing_m1m3_logevent_AppliedElevationForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedElevationForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_AppliedForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_appliedForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_AppliedForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedForces == false ) {
           status = mgr[LVClient].getEvent_appliedForces(Incoming_m1m3_logevent_AppliedForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedForces.Timestamp=Incoming_m1m3_logevent_AppliedForces->timestamp;
    for (int i=0;i<12;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedForces.XForces[i]=Incoming_m1m3_logevent_AppliedForces->xForces[i];}
    for (int i=0;i<100;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedForces.YForces[i]=Incoming_m1m3_logevent_AppliedForces->yForces[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedForces.ZForces[i]=Incoming_m1m3_logevent_AppliedForces->zForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedForces.Fx=Incoming_m1m3_logevent_AppliedForces->fx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedForces.Fy=Incoming_m1m3_logevent_AppliedForces->fy;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedForces.Fz=Incoming_m1m3_logevent_AppliedForces->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedForces.Mx=Incoming_m1m3_logevent_AppliedForces->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedForces.My=Incoming_m1m3_logevent_AppliedForces->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedForces.Mz=Incoming_m1m3_logevent_AppliedForces->mz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedForces.ForceMagnitude=Incoming_m1m3_logevent_AppliedForces->forceMagnitude;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedForces.priority=Incoming_m1m3_logevent_AppliedForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_AppliedForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_appliedForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_AppliedForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedForces.priority;
           Outgoing_m1m3_logevent_AppliedForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedForces.Timestamp;
    for (int i=0;i<12;i++) {Outgoing_m1m3_logevent_AppliedForces->xForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedForces.XForces[i];}
    for (int i=0;i<100;i++) {Outgoing_m1m3_logevent_AppliedForces->yForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedForces.YForces[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_AppliedForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedForces.ZForces[i];}
           Outgoing_m1m3_logevent_AppliedForces->fx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedForces.Fx;
           Outgoing_m1m3_logevent_AppliedForces->fy=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedForces.Fy;
           Outgoing_m1m3_logevent_AppliedForces->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedForces.Fz;
           Outgoing_m1m3_logevent_AppliedForces->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedForces.Mx;
           Outgoing_m1m3_logevent_AppliedForces->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedForces.My;
           Outgoing_m1m3_logevent_AppliedForces->mz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedForces.Mz;
           Outgoing_m1m3_logevent_AppliedForces->forceMagnitude=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedForces.ForceMagnitude;
           Outgoing_m1m3_logevent_AppliedForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedForces.priority;

          status = mgr[LVClient].logEvent_appliedForces(Outgoing_m1m3_logevent_AppliedForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_AppliedOffsetForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedOffsetForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_appliedOffsetForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_AppliedOffsetForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedOffsetForces == false ) {
           status = mgr[LVClient].getEvent_appliedOffsetForces(Incoming_m1m3_logevent_AppliedOffsetForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedOffsetForces.Timestamp=Incoming_m1m3_logevent_AppliedOffsetForces->timestamp;
    for (int i=0;i<12;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedOffsetForces.XForces[i]=Incoming_m1m3_logevent_AppliedOffsetForces->xForces[i];}
    for (int i=0;i<100;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedOffsetForces.YForces[i]=Incoming_m1m3_logevent_AppliedOffsetForces->yForces[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedOffsetForces.ZForces[i]=Incoming_m1m3_logevent_AppliedOffsetForces->zForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedOffsetForces.Fx=Incoming_m1m3_logevent_AppliedOffsetForces->fx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedOffsetForces.Fy=Incoming_m1m3_logevent_AppliedOffsetForces->fy;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedOffsetForces.Fz=Incoming_m1m3_logevent_AppliedOffsetForces->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedOffsetForces.Mx=Incoming_m1m3_logevent_AppliedOffsetForces->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedOffsetForces.My=Incoming_m1m3_logevent_AppliedOffsetForces->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedOffsetForces.Mz=Incoming_m1m3_logevent_AppliedOffsetForces->mz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedOffsetForces.ForceMagnitude=Incoming_m1m3_logevent_AppliedOffsetForces->forceMagnitude;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedOffsetForces.priority=Incoming_m1m3_logevent_AppliedOffsetForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedOffsetForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_AppliedOffsetForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedOffsetForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_appliedOffsetForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_AppliedOffsetForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedOffsetForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedOffsetForces.priority;
           Outgoing_m1m3_logevent_AppliedOffsetForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedOffsetForces.Timestamp;
    for (int i=0;i<12;i++) {Outgoing_m1m3_logevent_AppliedOffsetForces->xForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedOffsetForces.XForces[i];}
    for (int i=0;i<100;i++) {Outgoing_m1m3_logevent_AppliedOffsetForces->yForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedOffsetForces.YForces[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_AppliedOffsetForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedOffsetForces.ZForces[i];}
           Outgoing_m1m3_logevent_AppliedOffsetForces->fx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedOffsetForces.Fx;
           Outgoing_m1m3_logevent_AppliedOffsetForces->fy=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedOffsetForces.Fy;
           Outgoing_m1m3_logevent_AppliedOffsetForces->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedOffsetForces.Fz;
           Outgoing_m1m3_logevent_AppliedOffsetForces->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedOffsetForces.Mx;
           Outgoing_m1m3_logevent_AppliedOffsetForces->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedOffsetForces.My;
           Outgoing_m1m3_logevent_AppliedOffsetForces->mz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedOffsetForces.Mz;
           Outgoing_m1m3_logevent_AppliedOffsetForces->forceMagnitude=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedOffsetForces.ForceMagnitude;
           Outgoing_m1m3_logevent_AppliedOffsetForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedOffsetForces.priority;

          status = mgr[LVClient].logEvent_appliedOffsetForces(Outgoing_m1m3_logevent_AppliedOffsetForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedOffsetForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_AppliedSettingsMatchStart) {
          actorIdx = SAL__MTM1M3_logevent_appliedSettingsMatchStart_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_appliedSettingsMatchStart");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_AppliedSettingsMatchStart = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedSettingsMatchStart == false ) {
           status = mgr[LVClient].getEvent_appliedSettingsMatchStart(Incoming_m1m3_logevent_AppliedSettingsMatchStart);
           if (status == SAL__OK) {
//           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedSettingsMatchStart.Timestamp=Incoming_m1m3_logevent_AppliedSettingsMatchStart->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedSettingsMatchStart.AppliedSettingsMatchStart=Incoming_m1m3_logevent_AppliedSettingsMatchStart->appliedSettingsMatchStartIsTrue;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedSettingsMatchStart.priority=Incoming_m1m3_logevent_AppliedSettingsMatchStart->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedSettingsMatchStart = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_AppliedSettingsMatchStart) {
          actorIdx = SAL__MTM1M3_logevent_appliedSettingsMatchStart_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_appliedSettingsMatchStart");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_AppliedSettingsMatchStart = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedSettingsMatchStart ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedSettingsMatchStart.priority;
//           Outgoing_m1m3_logevent_AppliedSettingsMatchStart->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedSettingsMatchStart.Timestamp;
           Outgoing_m1m3_logevent_AppliedSettingsMatchStart->appliedSettingsMatchStartIsTrue=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedSettingsMatchStart.AppliedSettingsMatchStart;
           Outgoing_m1m3_logevent_AppliedSettingsMatchStart->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedSettingsMatchStart.priority;

          status = mgr[LVClient].logEvent_appliedSettingsMatchStart(Outgoing_m1m3_logevent_AppliedSettingsMatchStart,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedSettingsMatchStart = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_AppliedStaticForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedStaticForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_appliedStaticForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_AppliedStaticForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedStaticForces == false ) {
           status = mgr[LVClient].getEvent_appliedStaticForces(Incoming_m1m3_logevent_AppliedStaticForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedStaticForces.Timestamp=Incoming_m1m3_logevent_AppliedStaticForces->timestamp;
    for (int i=0;i<12;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedStaticForces.XForces[i]=Incoming_m1m3_logevent_AppliedStaticForces->xForces[i];}
    for (int i=0;i<100;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedStaticForces.YForces[i]=Incoming_m1m3_logevent_AppliedStaticForces->yForces[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedStaticForces.ZForces[i]=Incoming_m1m3_logevent_AppliedStaticForces->zForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedStaticForces.Fx=Incoming_m1m3_logevent_AppliedStaticForces->fx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedStaticForces.Fy=Incoming_m1m3_logevent_AppliedStaticForces->fy;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedStaticForces.Fz=Incoming_m1m3_logevent_AppliedStaticForces->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedStaticForces.Mx=Incoming_m1m3_logevent_AppliedStaticForces->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedStaticForces.My=Incoming_m1m3_logevent_AppliedStaticForces->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedStaticForces.Mz=Incoming_m1m3_logevent_AppliedStaticForces->mz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedStaticForces.ForceMagnitude=Incoming_m1m3_logevent_AppliedStaticForces->forceMagnitude;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedStaticForces.priority=Incoming_m1m3_logevent_AppliedStaticForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedStaticForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_AppliedStaticForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedStaticForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_appliedStaticForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_AppliedStaticForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedStaticForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedStaticForces.priority;
           Outgoing_m1m3_logevent_AppliedStaticForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedStaticForces.Timestamp;
    for (int i=0;i<12;i++) {Outgoing_m1m3_logevent_AppliedStaticForces->xForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedStaticForces.XForces[i];}
    for (int i=0;i<100;i++) {Outgoing_m1m3_logevent_AppliedStaticForces->yForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedStaticForces.YForces[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_AppliedStaticForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedStaticForces.ZForces[i];}
           Outgoing_m1m3_logevent_AppliedStaticForces->fx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedStaticForces.Fx;
           Outgoing_m1m3_logevent_AppliedStaticForces->fy=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedStaticForces.Fy;
           Outgoing_m1m3_logevent_AppliedStaticForces->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedStaticForces.Fz;
           Outgoing_m1m3_logevent_AppliedStaticForces->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedStaticForces.Mx;
           Outgoing_m1m3_logevent_AppliedStaticForces->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedStaticForces.My;
           Outgoing_m1m3_logevent_AppliedStaticForces->mz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedStaticForces.Mz;
           Outgoing_m1m3_logevent_AppliedStaticForces->forceMagnitude=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedStaticForces.ForceMagnitude;
           Outgoing_m1m3_logevent_AppliedStaticForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedStaticForces.priority;

          status = mgr[LVClient].logEvent_appliedStaticForces(Outgoing_m1m3_logevent_AppliedStaticForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedStaticForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_AppliedThermalForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedThermalForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_appliedThermalForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_AppliedThermalForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedThermalForces == false ) {
           status = mgr[LVClient].getEvent_appliedThermalForces(Incoming_m1m3_logevent_AppliedThermalForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedThermalForces.Timestamp=Incoming_m1m3_logevent_AppliedThermalForces->timestamp;
    for (int i=0;i<12;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedThermalForces.XForces[i]=Incoming_m1m3_logevent_AppliedThermalForces->xForces[i];}
    for (int i=0;i<100;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedThermalForces.YForces[i]=Incoming_m1m3_logevent_AppliedThermalForces->yForces[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedThermalForces.ZForces[i]=Incoming_m1m3_logevent_AppliedThermalForces->zForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedThermalForces.Fx=Incoming_m1m3_logevent_AppliedThermalForces->fx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedThermalForces.Fy=Incoming_m1m3_logevent_AppliedThermalForces->fy;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedThermalForces.Fz=Incoming_m1m3_logevent_AppliedThermalForces->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedThermalForces.Mx=Incoming_m1m3_logevent_AppliedThermalForces->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedThermalForces.My=Incoming_m1m3_logevent_AppliedThermalForces->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedThermalForces.Mz=Incoming_m1m3_logevent_AppliedThermalForces->mz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedThermalForces.ForceMagnitude=Incoming_m1m3_logevent_AppliedThermalForces->forceMagnitude;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedThermalForces.priority=Incoming_m1m3_logevent_AppliedThermalForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedThermalForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_AppliedThermalForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedThermalForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_appliedThermalForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_AppliedThermalForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedThermalForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedThermalForces.priority;
           Outgoing_m1m3_logevent_AppliedThermalForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedThermalForces.Timestamp;
    for (int i=0;i<12;i++) {Outgoing_m1m3_logevent_AppliedThermalForces->xForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedThermalForces.XForces[i];}
    for (int i=0;i<100;i++) {Outgoing_m1m3_logevent_AppliedThermalForces->yForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedThermalForces.YForces[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_AppliedThermalForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedThermalForces.ZForces[i];}
           Outgoing_m1m3_logevent_AppliedThermalForces->fx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedThermalForces.Fx;
           Outgoing_m1m3_logevent_AppliedThermalForces->fy=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedThermalForces.Fy;
           Outgoing_m1m3_logevent_AppliedThermalForces->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedThermalForces.Fz;
           Outgoing_m1m3_logevent_AppliedThermalForces->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedThermalForces.Mx;
           Outgoing_m1m3_logevent_AppliedThermalForces->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedThermalForces.My;
           Outgoing_m1m3_logevent_AppliedThermalForces->mz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedThermalForces.Mz;
           Outgoing_m1m3_logevent_AppliedThermalForces->forceMagnitude=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedThermalForces.ForceMagnitude;
           Outgoing_m1m3_logevent_AppliedThermalForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedThermalForces.priority;

          status = mgr[LVClient].logEvent_appliedThermalForces(Outgoing_m1m3_logevent_AppliedThermalForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedThermalForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_AppliedVelocityForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedVelocityForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_appliedVelocityForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_AppliedVelocityForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedVelocityForces == false ) {
           status = mgr[LVClient].getEvent_appliedVelocityForces(Incoming_m1m3_logevent_AppliedVelocityForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedVelocityForces.Timestamp=Incoming_m1m3_logevent_AppliedVelocityForces->timestamp;
    for (int i=0;i<12;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedVelocityForces.XForces[i]=Incoming_m1m3_logevent_AppliedVelocityForces->xForces[i];}
    for (int i=0;i<100;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedVelocityForces.YForces[i]=Incoming_m1m3_logevent_AppliedVelocityForces->yForces[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedVelocityForces.ZForces[i]=Incoming_m1m3_logevent_AppliedVelocityForces->zForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedVelocityForces.Fx=Incoming_m1m3_logevent_AppliedVelocityForces->fx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedVelocityForces.Fy=Incoming_m1m3_logevent_AppliedVelocityForces->fy;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedVelocityForces.Fz=Incoming_m1m3_logevent_AppliedVelocityForces->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedVelocityForces.Mx=Incoming_m1m3_logevent_AppliedVelocityForces->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedVelocityForces.My=Incoming_m1m3_logevent_AppliedVelocityForces->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedVelocityForces.Mz=Incoming_m1m3_logevent_AppliedVelocityForces->mz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedVelocityForces.ForceMagnitude=Incoming_m1m3_logevent_AppliedVelocityForces->forceMagnitude;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_AppliedVelocityForces.priority=Incoming_m1m3_logevent_AppliedVelocityForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_AppliedVelocityForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_AppliedVelocityForces) {
          actorIdx = SAL__MTM1M3_logevent_appliedVelocityForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_appliedVelocityForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_AppliedVelocityForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedVelocityForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedVelocityForces.priority;
           Outgoing_m1m3_logevent_AppliedVelocityForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedVelocityForces.Timestamp;
    for (int i=0;i<12;i++) {Outgoing_m1m3_logevent_AppliedVelocityForces->xForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedVelocityForces.XForces[i];}
    for (int i=0;i<100;i++) {Outgoing_m1m3_logevent_AppliedVelocityForces->yForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedVelocityForces.YForces[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_AppliedVelocityForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedVelocityForces.ZForces[i];}
           Outgoing_m1m3_logevent_AppliedVelocityForces->fx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedVelocityForces.Fx;
           Outgoing_m1m3_logevent_AppliedVelocityForces->fy=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedVelocityForces.Fy;
           Outgoing_m1m3_logevent_AppliedVelocityForces->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedVelocityForces.Fz;
           Outgoing_m1m3_logevent_AppliedVelocityForces->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedVelocityForces.Mx;
           Outgoing_m1m3_logevent_AppliedVelocityForces->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedVelocityForces.My;
           Outgoing_m1m3_logevent_AppliedVelocityForces->mz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedVelocityForces.Mz;
           Outgoing_m1m3_logevent_AppliedVelocityForces->forceMagnitude=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedVelocityForces.ForceMagnitude;
           Outgoing_m1m3_logevent_AppliedVelocityForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_AppliedVelocityForces.priority;

          status = mgr[LVClient].logEvent_appliedVelocityForces(Outgoing_m1m3_logevent_AppliedVelocityForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_AppliedVelocityForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_CellLightStatus) {
          actorIdx = SAL__MTM1M3_logevent_cellLightStatus_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_cellLightStatus");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_CellLightStatus = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_CellLightStatus == false ) {
           status = mgr[LVClient].getEvent_cellLightStatus(Incoming_m1m3_logevent_CellLightStatus);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_CellLightStatus.Timestamp=Incoming_m1m3_logevent_CellLightStatus->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_CellLightStatus.CellLightsCommandedOn=Incoming_m1m3_logevent_CellLightStatus->cellLightsCommandedOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_CellLightStatus.CellLightsOutputOn=Incoming_m1m3_logevent_CellLightStatus->cellLightsOutputOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_CellLightStatus.CellLightsOn=Incoming_m1m3_logevent_CellLightStatus->cellLightsOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_CellLightStatus.priority=Incoming_m1m3_logevent_CellLightStatus->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_CellLightStatus = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_CellLightStatus) {
          actorIdx = SAL__MTM1M3_logevent_cellLightStatus_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_cellLightStatus");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_CellLightStatus = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_CellLightStatus ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_CellLightStatus.priority;
           Outgoing_m1m3_logevent_CellLightStatus->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_CellLightStatus.Timestamp;
           Outgoing_m1m3_logevent_CellLightStatus->cellLightsCommandedOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_CellLightStatus.CellLightsCommandedOn;
           Outgoing_m1m3_logevent_CellLightStatus->cellLightsOutputOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_CellLightStatus.CellLightsOutputOn;
           Outgoing_m1m3_logevent_CellLightStatus->cellLightsOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_CellLightStatus.CellLightsOn;
           Outgoing_m1m3_logevent_CellLightStatus->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_CellLightStatus.priority;

          status = mgr[LVClient].logEvent_cellLightStatus(Outgoing_m1m3_logevent_CellLightStatus,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_CellLightStatus = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_CellLightWarning) {
          actorIdx = SAL__MTM1M3_logevent_cellLightWarning_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_cellLightWarning");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_CellLightWarning = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_CellLightWarning == false ) {
           status = mgr[LVClient].getEvent_cellLightWarning(Incoming_m1m3_logevent_CellLightWarning);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_CellLightWarning.Timestamp=Incoming_m1m3_logevent_CellLightWarning->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_CellLightWarning.AnyWarning=Incoming_m1m3_logevent_CellLightWarning->anyWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_CellLightWarning.CellLightsOutputMismatch=Incoming_m1m3_logevent_CellLightWarning->cellLightsOutputMismatch;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_CellLightWarning.CellLightsSensorMismatch=Incoming_m1m3_logevent_CellLightWarning->cellLightsSensorMismatch;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_CellLightWarning.priority=Incoming_m1m3_logevent_CellLightWarning->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_CellLightWarning = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_CellLightWarning) {
          actorIdx = SAL__MTM1M3_logevent_cellLightWarning_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_cellLightWarning");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_CellLightWarning = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_CellLightWarning ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_CellLightWarning.priority;
           Outgoing_m1m3_logevent_CellLightWarning->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_CellLightWarning.Timestamp;
           Outgoing_m1m3_logevent_CellLightWarning->anyWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_CellLightWarning.AnyWarning;
           Outgoing_m1m3_logevent_CellLightWarning->cellLightsOutputMismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_CellLightWarning.CellLightsOutputMismatch;
           Outgoing_m1m3_logevent_CellLightWarning->cellLightsSensorMismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_CellLightWarning.CellLightsSensorMismatch;
           Outgoing_m1m3_logevent_CellLightWarning->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_CellLightWarning.priority;

          status = mgr[LVClient].logEvent_cellLightWarning(Outgoing_m1m3_logevent_CellLightWarning,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_CellLightWarning = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_CommandRejectionWarning) {
          actorIdx = SAL__MTM1M3_logevent_commandRejectionWarning_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_commandRejectionWarning");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_CommandRejectionWarning = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_CommandRejectionWarning == false ) {
           status = mgr[LVClient].getEvent_commandRejectionWarning(Incoming_m1m3_logevent_CommandRejectionWarning);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_CommandRejectionWarning.Timestamp=Incoming_m1m3_logevent_CommandRejectionWarning->timestamp;
             strcpy(m1m3_memIO->client[LVClient].m1m3_logevent_CommandRejectionWarningLV_Command_bufferIn,Incoming_m1m3_logevent_CommandRejectionWarning->command.c_str());
             strcpy(m1m3_memIO->client[LVClient].m1m3_logevent_CommandRejectionWarningLV_Reason_bufferIn,Incoming_m1m3_logevent_CommandRejectionWarning->reason.c_str());
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_CommandRejectionWarning.priority=Incoming_m1m3_logevent_CommandRejectionWarning->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_CommandRejectionWarning = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_CommandRejectionWarning) {
          actorIdx = SAL__MTM1M3_logevent_commandRejectionWarning_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_commandRejectionWarning");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_CommandRejectionWarning = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_CommandRejectionWarning ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_CommandRejectionWarning.priority;
           Outgoing_m1m3_logevent_CommandRejectionWarning->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_CommandRejectionWarning.Timestamp;
             Outgoing_m1m3_logevent_CommandRejectionWarning->command=m1m3_memIO->client[LVClient].m1m3_logevent_CommandRejectionWarningLV_Command_bufferOut;
             Outgoing_m1m3_logevent_CommandRejectionWarning->reason=m1m3_memIO->client[LVClient].m1m3_logevent_CommandRejectionWarningLV_Reason_bufferOut;
           Outgoing_m1m3_logevent_CommandRejectionWarning->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_CommandRejectionWarning.priority;

          status = mgr[LVClient].logEvent_commandRejectionWarning(Outgoing_m1m3_logevent_CommandRejectionWarning,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_CommandRejectionWarning = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_DetailedState) {
          actorIdx = SAL__MTM1M3_logevent_detailedState_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_detailedState");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_DetailedState = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_DetailedState == false ) {
           status = mgr[LVClient].getEvent_detailedState(Incoming_m1m3_logevent_DetailedState);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_DetailedState.Timestamp=Incoming_m1m3_logevent_DetailedState->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_DetailedState.DetailedState=Incoming_m1m3_logevent_DetailedState->detailedState;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_DetailedState.priority=Incoming_m1m3_logevent_DetailedState->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_DetailedState = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_DetailedState) {
          actorIdx = SAL__MTM1M3_logevent_detailedState_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_detailedState");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_DetailedState = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_DetailedState ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_DetailedState.priority;
           Outgoing_m1m3_logevent_DetailedState->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_DetailedState.Timestamp;
           Outgoing_m1m3_logevent_DetailedState->detailedState=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_DetailedState.DetailedState;
           Outgoing_m1m3_logevent_DetailedState->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_DetailedState.priority;

          status = mgr[LVClient].logEvent_detailedState(Outgoing_m1m3_logevent_DetailedState,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_DetailedState = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_DisplacementSensorWarning) {
          actorIdx = SAL__MTM1M3_logevent_displacementSensorWarning_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_displacementSensorWarning");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_DisplacementSensorWarning = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_DisplacementSensorWarning == false ) {
           status = mgr[LVClient].getEvent_displacementSensorWarning(Incoming_m1m3_logevent_DisplacementSensorWarning);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_DisplacementSensorWarning.Timestamp=Incoming_m1m3_logevent_DisplacementSensorWarning->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_DisplacementSensorWarning.AnyWarning=Incoming_m1m3_logevent_DisplacementSensorWarning->anyWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_DisplacementSensorWarning.SensorReportsInvalidCommand=Incoming_m1m3_logevent_DisplacementSensorWarning->sensorReportsInvalidCommand;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_DisplacementSensorWarning.SensorReportsCommunicationTimeoutError=Incoming_m1m3_logevent_DisplacementSensorWarning->sensorReportsCommunicationTimeoutError;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_DisplacementSensorWarning.SensorReportsDataLengthError=Incoming_m1m3_logevent_DisplacementSensorWarning->sensorReportsDataLengthError;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_DisplacementSensorWarning.SensorReportsNumberOfParametersError=Incoming_m1m3_logevent_DisplacementSensorWarning->sensorReportsNumberOfParametersError;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_DisplacementSensorWarning.SensorReportsParameterError=Incoming_m1m3_logevent_DisplacementSensorWarning->sensorReportsParameterError;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_DisplacementSensorWarning.SensorReportsCommunicationError=Incoming_m1m3_logevent_DisplacementSensorWarning->sensorReportsCommunicationError;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_DisplacementSensorWarning.SensorReportsIDNumberError=Incoming_m1m3_logevent_DisplacementSensorWarning->sensorReportsIDNumberError;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_DisplacementSensorWarning.SensorReportsExpansionLineError=Incoming_m1m3_logevent_DisplacementSensorWarning->sensorReportsExpansionLineError;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_DisplacementSensorWarning.SensorReportsWriteControlError=Incoming_m1m3_logevent_DisplacementSensorWarning->sensorReportsWriteControlError;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_DisplacementSensorWarning.ResponseTimeout=Incoming_m1m3_logevent_DisplacementSensorWarning->responseTimeout;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_DisplacementSensorWarning.InvalidLength=Incoming_m1m3_logevent_DisplacementSensorWarning->invalidLength;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_DisplacementSensorWarning.InvalidResponse=Incoming_m1m3_logevent_DisplacementSensorWarning->invalidResponse;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_DisplacementSensorWarning.UnknownCommand=Incoming_m1m3_logevent_DisplacementSensorWarning->unknownCommand;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_DisplacementSensorWarning.UnknownProblem=Incoming_m1m3_logevent_DisplacementSensorWarning->unknownProblem;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_DisplacementSensorWarning.priority=Incoming_m1m3_logevent_DisplacementSensorWarning->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_DisplacementSensorWarning = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_DisplacementSensorWarning) {
          actorIdx = SAL__MTM1M3_logevent_displacementSensorWarning_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_displacementSensorWarning");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_DisplacementSensorWarning = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_DisplacementSensorWarning ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_DisplacementSensorWarning.priority;
           Outgoing_m1m3_logevent_DisplacementSensorWarning->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_DisplacementSensorWarning.Timestamp;
           Outgoing_m1m3_logevent_DisplacementSensorWarning->anyWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_DisplacementSensorWarning.AnyWarning;
           Outgoing_m1m3_logevent_DisplacementSensorWarning->sensorReportsInvalidCommand=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_DisplacementSensorWarning.SensorReportsInvalidCommand;
           Outgoing_m1m3_logevent_DisplacementSensorWarning->sensorReportsCommunicationTimeoutError=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_DisplacementSensorWarning.SensorReportsCommunicationTimeoutError;
           Outgoing_m1m3_logevent_DisplacementSensorWarning->sensorReportsDataLengthError=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_DisplacementSensorWarning.SensorReportsDataLengthError;
           Outgoing_m1m3_logevent_DisplacementSensorWarning->sensorReportsNumberOfParametersError=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_DisplacementSensorWarning.SensorReportsNumberOfParametersError;
           Outgoing_m1m3_logevent_DisplacementSensorWarning->sensorReportsParameterError=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_DisplacementSensorWarning.SensorReportsParameterError;
           Outgoing_m1m3_logevent_DisplacementSensorWarning->sensorReportsCommunicationError=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_DisplacementSensorWarning.SensorReportsCommunicationError;
           Outgoing_m1m3_logevent_DisplacementSensorWarning->sensorReportsIDNumberError=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_DisplacementSensorWarning.SensorReportsIDNumberError;
           Outgoing_m1m3_logevent_DisplacementSensorWarning->sensorReportsExpansionLineError=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_DisplacementSensorWarning.SensorReportsExpansionLineError;
           Outgoing_m1m3_logevent_DisplacementSensorWarning->sensorReportsWriteControlError=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_DisplacementSensorWarning.SensorReportsWriteControlError;
           Outgoing_m1m3_logevent_DisplacementSensorWarning->responseTimeout=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_DisplacementSensorWarning.ResponseTimeout;
           Outgoing_m1m3_logevent_DisplacementSensorWarning->invalidLength=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_DisplacementSensorWarning.InvalidLength;
           Outgoing_m1m3_logevent_DisplacementSensorWarning->invalidResponse=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_DisplacementSensorWarning.InvalidResponse;
           Outgoing_m1m3_logevent_DisplacementSensorWarning->unknownCommand=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_DisplacementSensorWarning.UnknownCommand;
           Outgoing_m1m3_logevent_DisplacementSensorWarning->unknownProblem=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_DisplacementSensorWarning.UnknownProblem;
           Outgoing_m1m3_logevent_DisplacementSensorWarning->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_DisplacementSensorWarning.priority;

          status = mgr[LVClient].logEvent_displacementSensorWarning(Outgoing_m1m3_logevent_DisplacementSensorWarning,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_DisplacementSensorWarning = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_ErrorCode) {
          actorIdx = SAL__MTM1M3_logevent_errorCode_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_errorCode");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_ErrorCode = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_ErrorCode == false ) {
           status = mgr[LVClient].getEvent_errorCode(Incoming_m1m3_logevent_ErrorCode);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ErrorCode.Timestamp=Incoming_m1m3_logevent_ErrorCode->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ErrorCode.ErrorCode=Incoming_m1m3_logevent_ErrorCode->errorCode;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ErrorCode.DetailedErrorCode=Incoming_m1m3_logevent_ErrorCode->detailedErrorCode;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ErrorCode.priority=Incoming_m1m3_logevent_ErrorCode->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_ErrorCode = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_ErrorCode) {
          actorIdx = SAL__MTM1M3_logevent_errorCode_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_errorCode");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_ErrorCode = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_ErrorCode ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ErrorCode.priority;
           Outgoing_m1m3_logevent_ErrorCode->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ErrorCode.Timestamp;
           Outgoing_m1m3_logevent_ErrorCode->errorCode=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ErrorCode.ErrorCode;
           Outgoing_m1m3_logevent_ErrorCode->detailedErrorCode=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ErrorCode.DetailedErrorCode;
           Outgoing_m1m3_logevent_ErrorCode->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ErrorCode.priority;

          status = mgr[LVClient].logEvent_errorCode(Outgoing_m1m3_logevent_ErrorCode,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_ErrorCode = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_ForceActuatorForceWarning) {
          actorIdx = SAL__MTM1M3_logevent_forceActuatorForceWarning_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_forceActuatorForceWarning");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_ForceActuatorForceWarning = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_ForceActuatorForceWarning == false ) {
           status = mgr[LVClient].getEvent_forceActuatorForceWarning(Incoming_m1m3_logevent_ForceActuatorForceWarning);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorForceWarning.Timestamp=Incoming_m1m3_logevent_ForceActuatorForceWarning->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorForceWarning.AnyWarning=Incoming_m1m3_logevent_ForceActuatorForceWarning->anyWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorForceWarning.AnyPrimaryAxisMeasuredForceWarning=Incoming_m1m3_logevent_ForceActuatorForceWarning->anyPrimaryAxisMeasuredForceWarning;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorForceWarning.PrimaryAxisMeasuredForceWarning[i]=Incoming_m1m3_logevent_ForceActuatorForceWarning->primaryAxisMeasuredForceWarning[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorForceWarning.AnySecondaryAxisMeasuredForceWarning=Incoming_m1m3_logevent_ForceActuatorForceWarning->anySecondaryAxisMeasuredForceWarning;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorForceWarning.SecondaryAxisMeasuredForceWarning[i]=Incoming_m1m3_logevent_ForceActuatorForceWarning->secondaryAxisMeasuredForceWarning[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorForceWarning.AnyPrimaryAxisFollowingErrorWarning=Incoming_m1m3_logevent_ForceActuatorForceWarning->anyPrimaryAxisFollowingErrorWarning;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorForceWarning.PrimaryAxisFollowingErrorWarning[i]=Incoming_m1m3_logevent_ForceActuatorForceWarning->primaryAxisFollowingErrorWarning[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorForceWarning.AnySecondaryAxisFollowingErrorWarning=Incoming_m1m3_logevent_ForceActuatorForceWarning->anySecondaryAxisFollowingErrorWarning;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorForceWarning.SecondaryAxisFollowingErrorWarning[i]=Incoming_m1m3_logevent_ForceActuatorForceWarning->secondaryAxisFollowingErrorWarning[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorForceWarning.priority=Incoming_m1m3_logevent_ForceActuatorForceWarning->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_ForceActuatorForceWarning = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_ForceActuatorForceWarning) {
          actorIdx = SAL__MTM1M3_logevent_forceActuatorForceWarning_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_forceActuatorForceWarning");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_ForceActuatorForceWarning = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_ForceActuatorForceWarning ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorForceWarning.priority;
           Outgoing_m1m3_logevent_ForceActuatorForceWarning->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorForceWarning.Timestamp;
           Outgoing_m1m3_logevent_ForceActuatorForceWarning->anyWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorForceWarning.AnyWarning;
           Outgoing_m1m3_logevent_ForceActuatorForceWarning->anyPrimaryAxisMeasuredForceWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorForceWarning.AnyPrimaryAxisMeasuredForceWarning;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorForceWarning->primaryAxisMeasuredForceWarning[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorForceWarning.PrimaryAxisMeasuredForceWarning[i];}
           Outgoing_m1m3_logevent_ForceActuatorForceWarning->anySecondaryAxisMeasuredForceWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorForceWarning.AnySecondaryAxisMeasuredForceWarning;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorForceWarning->secondaryAxisMeasuredForceWarning[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorForceWarning.SecondaryAxisMeasuredForceWarning[i];}
           Outgoing_m1m3_logevent_ForceActuatorForceWarning->anyPrimaryAxisFollowingErrorWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorForceWarning.AnyPrimaryAxisFollowingErrorWarning;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorForceWarning->primaryAxisFollowingErrorWarning[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorForceWarning.PrimaryAxisFollowingErrorWarning[i];}
           Outgoing_m1m3_logevent_ForceActuatorForceWarning->anySecondaryAxisFollowingErrorWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorForceWarning.AnySecondaryAxisFollowingErrorWarning;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorForceWarning->secondaryAxisFollowingErrorWarning[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorForceWarning.SecondaryAxisFollowingErrorWarning[i];}
           Outgoing_m1m3_logevent_ForceActuatorForceWarning->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorForceWarning.priority;

          status = mgr[LVClient].logEvent_forceActuatorForceWarning(Outgoing_m1m3_logevent_ForceActuatorForceWarning,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_ForceActuatorForceWarning = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_ForceActuatorInfo) {
          actorIdx = SAL__MTM1M3_logevent_forceActuatorInfo_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_forceActuatorInfo");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_ForceActuatorInfo = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_ForceActuatorInfo == false ) {
           status = mgr[LVClient].getEvent_forceActuatorInfo(Incoming_m1m3_logevent_ForceActuatorInfo);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.Timestamp=Incoming_m1m3_logevent_ForceActuatorInfo->timestamp;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.ReferenceId[i]=Incoming_m1m3_logevent_ForceActuatorInfo->referenceId[i];}
    for (int i=0;i<12;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.XDataReferenceId[i]=Incoming_m1m3_logevent_ForceActuatorInfo->xDataReferenceId[i];}
    for (int i=0;i<100;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.YDataReferenceId[i]=Incoming_m1m3_logevent_ForceActuatorInfo->yDataReferenceId[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.ZDataReferenceId[i]=Incoming_m1m3_logevent_ForceActuatorInfo->zDataReferenceId[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.ActuatorType[i]=Incoming_m1m3_logevent_ForceActuatorInfo->actuatorType[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.ActuatorOrientation[i]=Incoming_m1m3_logevent_ForceActuatorInfo->actuatorOrientation[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.ModbusSubnet[i]=Incoming_m1m3_logevent_ForceActuatorInfo->modbusSubnet[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.ModbusAddress[i]=Incoming_m1m3_logevent_ForceActuatorInfo->modbusAddress[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.XPosition[i]=Incoming_m1m3_logevent_ForceActuatorInfo->xPosition[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.YPosition[i]=Incoming_m1m3_logevent_ForceActuatorInfo->yPosition[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.ZPosition[i]=Incoming_m1m3_logevent_ForceActuatorInfo->zPosition[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.ILCUniqueId[i]=Incoming_m1m3_logevent_ForceActuatorInfo->ilcUniqueId[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.ILCApplicationType[i]=Incoming_m1m3_logevent_ForceActuatorInfo->ilcApplicationType[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.NetworkNodeType[i]=Incoming_m1m3_logevent_ForceActuatorInfo->networkNodeType[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.ILCSelectedOptions[i]=Incoming_m1m3_logevent_ForceActuatorInfo->ilcSelectedOptions[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.NetworkNodeOptions[i]=Incoming_m1m3_logevent_ForceActuatorInfo->networkNodeOptions[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.MajorRevision[i]=Incoming_m1m3_logevent_ForceActuatorInfo->majorRevision[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.MinorRevision[i]=Incoming_m1m3_logevent_ForceActuatorInfo->minorRevision[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.ADCScanRate[i]=Incoming_m1m3_logevent_ForceActuatorInfo->adcScanRate[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.MainPrimaryCylinderCoefficient[i]=Incoming_m1m3_logevent_ForceActuatorInfo->mainPrimaryCylinderCoefficient[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.MainSecondaryCylinderCoefficient[i]=Incoming_m1m3_logevent_ForceActuatorInfo->mainSecondaryCylinderCoefficient[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.MainPrimaryCylinderLoadCellOffset[i]=Incoming_m1m3_logevent_ForceActuatorInfo->mainPrimaryCylinderLoadCellOffset[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.MainSecondaryCylinderLoadCellOffset[i]=Incoming_m1m3_logevent_ForceActuatorInfo->mainSecondaryCylinderLoadCellOffset[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.MainPrimaryCylinderLoadCellSensitivity[i]=Incoming_m1m3_logevent_ForceActuatorInfo->mainPrimaryCylinderLoadCellSensitivity[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.MainSecondaryCylinderLoadCellSensitivity[i]=Incoming_m1m3_logevent_ForceActuatorInfo->mainSecondaryCylinderLoadCellSensitivity[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.BackupPrimaryCylinderCoefficient[i]=Incoming_m1m3_logevent_ForceActuatorInfo->backupPrimaryCylinderCoefficient[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.BackupSecondaryCylinderCoefficient[i]=Incoming_m1m3_logevent_ForceActuatorInfo->backupSecondaryCylinderCoefficient[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.BackupPrimaryCylinderLoadCellOffset[i]=Incoming_m1m3_logevent_ForceActuatorInfo->backupPrimaryCylinderLoadCellOffset[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.BackupSecondaryCylinderLoadCellOffset[i]=Incoming_m1m3_logevent_ForceActuatorInfo->backupSecondaryCylinderLoadCellOffset[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.BackupPrimaryCylinderLoadCellSensitivity[i]=Incoming_m1m3_logevent_ForceActuatorInfo->backupPrimaryCylinderLoadCellSensitivity[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.BackupSecondaryCylinderLoadCellSensitivity[i]=Incoming_m1m3_logevent_ForceActuatorInfo->backupSecondaryCylinderLoadCellSensitivity[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.MezzaninePrimaryCylinderGain[i]=Incoming_m1m3_logevent_ForceActuatorInfo->mezzaninePrimaryCylinderGain[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.MezzanineSecondaryCylinderGain[i]=Incoming_m1m3_logevent_ForceActuatorInfo->mezzanineSecondaryCylinderGain[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.MezzanineUniqueId[i]=Incoming_m1m3_logevent_ForceActuatorInfo->mezzanineUniqueId[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.MezzanineFirmwareType[i]=Incoming_m1m3_logevent_ForceActuatorInfo->mezzanineFirmwareType[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.MezzanineMajorRevision[i]=Incoming_m1m3_logevent_ForceActuatorInfo->mezzanineMajorRevision[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.MezzanineMinorRevision[i]=Incoming_m1m3_logevent_ForceActuatorInfo->mezzanineMinorRevision[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorInfo.priority=Incoming_m1m3_logevent_ForceActuatorInfo->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_ForceActuatorInfo = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_ForceActuatorInfo) {
          actorIdx = SAL__MTM1M3_logevent_forceActuatorInfo_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_forceActuatorInfo");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_ForceActuatorInfo = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_ForceActuatorInfo ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.priority;
           Outgoing_m1m3_logevent_ForceActuatorInfo->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.Timestamp;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->referenceId[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.ReferenceId[i];}
    for (int i=0;i<12;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->xDataReferenceId[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.XDataReferenceId[i];}
    for (int i=0;i<100;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->yDataReferenceId[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.YDataReferenceId[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->zDataReferenceId[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.ZDataReferenceId[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->actuatorType[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.ActuatorType[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->actuatorOrientation[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.ActuatorOrientation[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->modbusSubnet[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.ModbusSubnet[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->modbusAddress[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.ModbusAddress[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->xPosition[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.XPosition[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->yPosition[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.YPosition[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->zPosition[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.ZPosition[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->ilcUniqueId[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.ILCUniqueId[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->ilcApplicationType[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.ILCApplicationType[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->networkNodeType[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.NetworkNodeType[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->ilcSelectedOptions[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.ILCSelectedOptions[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->networkNodeOptions[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.NetworkNodeOptions[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->majorRevision[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.MajorRevision[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->minorRevision[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.MinorRevision[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->adcScanRate[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.ADCScanRate[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->mainPrimaryCylinderCoefficient[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.MainPrimaryCylinderCoefficient[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->mainSecondaryCylinderCoefficient[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.MainSecondaryCylinderCoefficient[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->mainPrimaryCylinderLoadCellOffset[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.MainPrimaryCylinderLoadCellOffset[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->mainSecondaryCylinderLoadCellOffset[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.MainSecondaryCylinderLoadCellOffset[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->mainPrimaryCylinderLoadCellSensitivity[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.MainPrimaryCylinderLoadCellSensitivity[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->mainSecondaryCylinderLoadCellSensitivity[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.MainSecondaryCylinderLoadCellSensitivity[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->backupPrimaryCylinderCoefficient[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.BackupPrimaryCylinderCoefficient[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->backupSecondaryCylinderCoefficient[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.BackupSecondaryCylinderCoefficient[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->backupPrimaryCylinderLoadCellOffset[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.BackupPrimaryCylinderLoadCellOffset[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->backupSecondaryCylinderLoadCellOffset[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.BackupSecondaryCylinderLoadCellOffset[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->backupPrimaryCylinderLoadCellSensitivity[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.BackupPrimaryCylinderLoadCellSensitivity[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->backupSecondaryCylinderLoadCellSensitivity[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.BackupSecondaryCylinderLoadCellSensitivity[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->mezzaninePrimaryCylinderGain[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.MezzaninePrimaryCylinderGain[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->mezzanineSecondaryCylinderGain[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.MezzanineSecondaryCylinderGain[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->mezzanineUniqueId[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.MezzanineUniqueId[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->mezzanineFirmwareType[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.MezzanineFirmwareType[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->mezzanineMajorRevision[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.MezzanineMajorRevision[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorInfo->mezzanineMinorRevision[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.MezzanineMinorRevision[i];}
           Outgoing_m1m3_logevent_ForceActuatorInfo->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorInfo.priority;

          status = mgr[LVClient].logEvent_forceActuatorInfo(Outgoing_m1m3_logevent_ForceActuatorInfo,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_ForceActuatorInfo = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_ForceActuatorState) {
          actorIdx = SAL__MTM1M3_logevent_forceActuatorState_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_forceActuatorState");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_ForceActuatorState = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_ForceActuatorState == false ) {
           status = mgr[LVClient].getEvent_forceActuatorState(Incoming_m1m3_logevent_ForceActuatorState);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorState.Timestamp=Incoming_m1m3_logevent_ForceActuatorState->timestamp;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorState.ILCState[i]=Incoming_m1m3_logevent_ForceActuatorState->ilcState[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorState.SlewFlag=Incoming_m1m3_logevent_ForceActuatorState->slewFlag;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorState.StaticForcesApplied=Incoming_m1m3_logevent_ForceActuatorState->staticForcesApplied;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorState.ElevationForcesApplied=Incoming_m1m3_logevent_ForceActuatorState->elevationForcesApplied;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorState.AzimuthForcesApplied=Incoming_m1m3_logevent_ForceActuatorState->azimuthForcesApplied;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorState.ThermalForcesApplied=Incoming_m1m3_logevent_ForceActuatorState->thermalForcesApplied;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorState.OffsetForcesApplied=Incoming_m1m3_logevent_ForceActuatorState->offsetForcesApplied;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorState.AccelerationForcesApplied=Incoming_m1m3_logevent_ForceActuatorState->accelerationForcesApplied;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorState.VelocityForcesApplied=Incoming_m1m3_logevent_ForceActuatorState->velocityForcesApplied;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorState.ActiveOpticForcesApplied=Incoming_m1m3_logevent_ForceActuatorState->activeOpticForcesApplied;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorState.AberrationForcesApplied=Incoming_m1m3_logevent_ForceActuatorState->aberrationForcesApplied;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorState.BalanceForcesApplied=Incoming_m1m3_logevent_ForceActuatorState->balanceForcesApplied;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorState.SupportPercentage=Incoming_m1m3_logevent_ForceActuatorState->supportPercentage;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorState.priority=Incoming_m1m3_logevent_ForceActuatorState->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_ForceActuatorState = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_ForceActuatorState) {
          actorIdx = SAL__MTM1M3_logevent_forceActuatorState_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_forceActuatorState");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_ForceActuatorState = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_ForceActuatorState ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorState.priority;
           Outgoing_m1m3_logevent_ForceActuatorState->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorState.Timestamp;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorState->ilcState[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorState.ILCState[i];}
           Outgoing_m1m3_logevent_ForceActuatorState->slewFlag=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorState.SlewFlag;
           Outgoing_m1m3_logevent_ForceActuatorState->staticForcesApplied=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorState.StaticForcesApplied;
           Outgoing_m1m3_logevent_ForceActuatorState->elevationForcesApplied=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorState.ElevationForcesApplied;
           Outgoing_m1m3_logevent_ForceActuatorState->azimuthForcesApplied=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorState.AzimuthForcesApplied;
           Outgoing_m1m3_logevent_ForceActuatorState->thermalForcesApplied=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorState.ThermalForcesApplied;
           Outgoing_m1m3_logevent_ForceActuatorState->offsetForcesApplied=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorState.OffsetForcesApplied;
           Outgoing_m1m3_logevent_ForceActuatorState->accelerationForcesApplied=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorState.AccelerationForcesApplied;
           Outgoing_m1m3_logevent_ForceActuatorState->velocityForcesApplied=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorState.VelocityForcesApplied;
           Outgoing_m1m3_logevent_ForceActuatorState->activeOpticForcesApplied=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorState.ActiveOpticForcesApplied;
           Outgoing_m1m3_logevent_ForceActuatorState->aberrationForcesApplied=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorState.AberrationForcesApplied;
           Outgoing_m1m3_logevent_ForceActuatorState->balanceForcesApplied=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorState.BalanceForcesApplied;
           Outgoing_m1m3_logevent_ForceActuatorState->supportPercentage=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorState.SupportPercentage;
           Outgoing_m1m3_logevent_ForceActuatorState->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorState.priority;

          status = mgr[LVClient].logEvent_forceActuatorState(Outgoing_m1m3_logevent_ForceActuatorState,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_ForceActuatorState = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_ForceActuatorWarning) {
          actorIdx = SAL__MTM1M3_logevent_forceActuatorWarning_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_forceActuatorWarning");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_ForceActuatorWarning = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_ForceActuatorWarning == false ) {
           status = mgr[LVClient].getEvent_forceActuatorWarning(Incoming_m1m3_logevent_ForceActuatorWarning);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.Timestamp=Incoming_m1m3_logevent_ForceActuatorWarning->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyWarning=Incoming_m1m3_logevent_ForceActuatorWarning->anyWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyMajorFault=Incoming_m1m3_logevent_ForceActuatorWarning->anyMajorFault;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.MajorFault[i]=Incoming_m1m3_logevent_ForceActuatorWarning->majorFault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyMinorFault=Incoming_m1m3_logevent_ForceActuatorWarning->anyMinorFault;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.MinorFault[i]=Incoming_m1m3_logevent_ForceActuatorWarning->minorFault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyFaultOverride=Incoming_m1m3_logevent_ForceActuatorWarning->anyFaultOverride;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.FaultOverride[i]=Incoming_m1m3_logevent_ForceActuatorWarning->faultOverride[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyMainCalibrationError=Incoming_m1m3_logevent_ForceActuatorWarning->anyMainCalibrationError;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.MainCalibrationError[i]=Incoming_m1m3_logevent_ForceActuatorWarning->mainCalibrationError[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyBackupCalibrationError=Incoming_m1m3_logevent_ForceActuatorWarning->anyBackupCalibrationError;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.BackupCalibrationError[i]=Incoming_m1m3_logevent_ForceActuatorWarning->backupCalibrationError[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyMezzanineError=Incoming_m1m3_logevent_ForceActuatorWarning->anyMezzanineError;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.MezzanineError[i]=Incoming_m1m3_logevent_ForceActuatorWarning->mezzanineError[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyMezzanineBootloaderActive=Incoming_m1m3_logevent_ForceActuatorWarning->anyMezzanineBootloaderActive;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.MezzanineBootloaderActive[i]=Incoming_m1m3_logevent_ForceActuatorWarning->mezzanineBootloaderActive[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyUniqueIdCRCError=Incoming_m1m3_logevent_ForceActuatorWarning->anyUniqueIdCRCError;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.UniqueIdCRCError[i]=Incoming_m1m3_logevent_ForceActuatorWarning->uniqueIdCRCError[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyApplicationTypeMismatch=Incoming_m1m3_logevent_ForceActuatorWarning->anyApplicationTypeMismatch;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.ApplicationTypeMismatch[i]=Incoming_m1m3_logevent_ForceActuatorWarning->applicationTypeMismatch[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyApplicationMissing=Incoming_m1m3_logevent_ForceActuatorWarning->anyApplicationMissing;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.ApplicationMissing[i]=Incoming_m1m3_logevent_ForceActuatorWarning->applicationMissing[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyApplicationCRCMismatch=Incoming_m1m3_logevent_ForceActuatorWarning->anyApplicationCRCMismatch;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.ApplicationCRCMismatch[i]=Incoming_m1m3_logevent_ForceActuatorWarning->applicationCRCMismatch[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyOneWireMissing=Incoming_m1m3_logevent_ForceActuatorWarning->anyOneWireMissing;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.OneWireMissing[i]=Incoming_m1m3_logevent_ForceActuatorWarning->oneWireMissing[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyOneWire1Mismatch=Incoming_m1m3_logevent_ForceActuatorWarning->anyOneWire1Mismatch;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.OneWire1Mismatch[i]=Incoming_m1m3_logevent_ForceActuatorWarning->oneWire1Mismatch[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyOneWire2Mismatch=Incoming_m1m3_logevent_ForceActuatorWarning->anyOneWire2Mismatch;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.OneWire2Mismatch[i]=Incoming_m1m3_logevent_ForceActuatorWarning->oneWire2Mismatch[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyWatchdogReset=Incoming_m1m3_logevent_ForceActuatorWarning->anyWatchdogReset;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.WatchdogReset[i]=Incoming_m1m3_logevent_ForceActuatorWarning->watchdogReset[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyBrownOut=Incoming_m1m3_logevent_ForceActuatorWarning->anyBrownOut;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.BrownOut[i]=Incoming_m1m3_logevent_ForceActuatorWarning->brownOut[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyEventTrapReset=Incoming_m1m3_logevent_ForceActuatorWarning->anyEventTrapReset;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.EventTrapReset[i]=Incoming_m1m3_logevent_ForceActuatorWarning->eventTrapReset[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnySSRPowerFault=Incoming_m1m3_logevent_ForceActuatorWarning->anySSRPowerFault;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.SSRPowerFault[i]=Incoming_m1m3_logevent_ForceActuatorWarning->ssrPowerFault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyAuxPowerFault=Incoming_m1m3_logevent_ForceActuatorWarning->anyAuxPowerFault;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AuxPowerFault[i]=Incoming_m1m3_logevent_ForceActuatorWarning->auxPowerFault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyMezzaninePowerFault=Incoming_m1m3_logevent_ForceActuatorWarning->anyMezzaninePowerFault;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.MezzaninePowerFault[i]=Incoming_m1m3_logevent_ForceActuatorWarning->mezzaninePowerFault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyMezzanineCurrentAmp1Fault=Incoming_m1m3_logevent_ForceActuatorWarning->anyMezzanineCurrentAmp1Fault;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.MezzanineCurrentAmp1Fault[i]=Incoming_m1m3_logevent_ForceActuatorWarning->mezzanineCurrentAmp1Fault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyMezzanineCurrentAmp2Fault=Incoming_m1m3_logevent_ForceActuatorWarning->anyMezzanineCurrentAmp2Fault;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.MezzanineCurrentAmp2Fault[i]=Incoming_m1m3_logevent_ForceActuatorWarning->mezzanineCurrentAmp2Fault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyMezzanineUniqueIdCRCError=Incoming_m1m3_logevent_ForceActuatorWarning->anyMezzanineUniqueIdCRCError;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.MezzanineUniqueIdCRCError[i]=Incoming_m1m3_logevent_ForceActuatorWarning->mezzanineUniqueIdCRCError[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyMezzanineMainCalibrationError=Incoming_m1m3_logevent_ForceActuatorWarning->anyMezzanineMainCalibrationError;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.MezzanineMainCalibrationError[i]=Incoming_m1m3_logevent_ForceActuatorWarning->mezzanineMainCalibrationError[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyMezzanineBackupCalibrationError=Incoming_m1m3_logevent_ForceActuatorWarning->anyMezzanineBackupCalibrationError;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.MezzanineBackupCalibrationError[i]=Incoming_m1m3_logevent_ForceActuatorWarning->mezzanineBackupCalibrationError[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyMezzanineEventTrapReset=Incoming_m1m3_logevent_ForceActuatorWarning->anyMezzanineEventTrapReset;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.MezzanineEventTrapReset[i]=Incoming_m1m3_logevent_ForceActuatorWarning->mezzanineEventTrapReset[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyMezzanineApplicationMissing=Incoming_m1m3_logevent_ForceActuatorWarning->anyMezzanineApplicationMissing;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.MezzanineApplicationMissing[i]=Incoming_m1m3_logevent_ForceActuatorWarning->mezzanineApplicationMissing[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyMezzanineApplicationCRCMismatch=Incoming_m1m3_logevent_ForceActuatorWarning->anyMezzanineApplicationCRCMismatch;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.MezzanineApplicationCRCMismatch[i]=Incoming_m1m3_logevent_ForceActuatorWarning->mezzanineApplicationCRCMismatch[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyILCFault=Incoming_m1m3_logevent_ForceActuatorWarning->anyILCFault;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.ILCFault[i]=Incoming_m1m3_logevent_ForceActuatorWarning->ilcFault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.AnyBroadcastCounterWarning=Incoming_m1m3_logevent_ForceActuatorWarning->anyBroadcastCounterWarning;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.BroadcastCounterWarning[i]=Incoming_m1m3_logevent_ForceActuatorWarning->broadcastCounterWarning[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceActuatorWarning.priority=Incoming_m1m3_logevent_ForceActuatorWarning->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_ForceActuatorWarning = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_ForceActuatorWarning) {
          actorIdx = SAL__MTM1M3_logevent_forceActuatorWarning_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_forceActuatorWarning");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_ForceActuatorWarning = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_ForceActuatorWarning ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.priority;
           Outgoing_m1m3_logevent_ForceActuatorWarning->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.Timestamp;
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyWarning;
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyMajorFault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyMajorFault;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->majorFault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.MajorFault[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyMinorFault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyMinorFault;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->minorFault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.MinorFault[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyFaultOverride=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyFaultOverride;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->faultOverride[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.FaultOverride[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyMainCalibrationError=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyMainCalibrationError;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->mainCalibrationError[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.MainCalibrationError[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyBackupCalibrationError=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyBackupCalibrationError;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->backupCalibrationError[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.BackupCalibrationError[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyMezzanineError=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyMezzanineError;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->mezzanineError[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.MezzanineError[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyMezzanineBootloaderActive=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyMezzanineBootloaderActive;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->mezzanineBootloaderActive[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.MezzanineBootloaderActive[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyUniqueIdCRCError=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyUniqueIdCRCError;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->uniqueIdCRCError[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.UniqueIdCRCError[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyApplicationTypeMismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyApplicationTypeMismatch;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->applicationTypeMismatch[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.ApplicationTypeMismatch[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyApplicationMissing=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyApplicationMissing;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->applicationMissing[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.ApplicationMissing[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyApplicationCRCMismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyApplicationCRCMismatch;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->applicationCRCMismatch[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.ApplicationCRCMismatch[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyOneWireMissing=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyOneWireMissing;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->oneWireMissing[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.OneWireMissing[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyOneWire1Mismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyOneWire1Mismatch;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->oneWire1Mismatch[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.OneWire1Mismatch[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyOneWire2Mismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyOneWire2Mismatch;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->oneWire2Mismatch[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.OneWire2Mismatch[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyWatchdogReset=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyWatchdogReset;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->watchdogReset[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.WatchdogReset[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyBrownOut=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyBrownOut;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->brownOut[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.BrownOut[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyEventTrapReset=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyEventTrapReset;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->eventTrapReset[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.EventTrapReset[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anySSRPowerFault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnySSRPowerFault;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->ssrPowerFault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.SSRPowerFault[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyAuxPowerFault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyAuxPowerFault;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->auxPowerFault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AuxPowerFault[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyMezzaninePowerFault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyMezzaninePowerFault;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->mezzaninePowerFault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.MezzaninePowerFault[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyMezzanineCurrentAmp1Fault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyMezzanineCurrentAmp1Fault;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->mezzanineCurrentAmp1Fault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.MezzanineCurrentAmp1Fault[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyMezzanineCurrentAmp2Fault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyMezzanineCurrentAmp2Fault;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->mezzanineCurrentAmp2Fault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.MezzanineCurrentAmp2Fault[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyMezzanineUniqueIdCRCError=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyMezzanineUniqueIdCRCError;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->mezzanineUniqueIdCRCError[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.MezzanineUniqueIdCRCError[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyMezzanineMainCalibrationError=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyMezzanineMainCalibrationError;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->mezzanineMainCalibrationError[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.MezzanineMainCalibrationError[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyMezzanineBackupCalibrationError=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyMezzanineBackupCalibrationError;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->mezzanineBackupCalibrationError[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.MezzanineBackupCalibrationError[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyMezzanineEventTrapReset=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyMezzanineEventTrapReset;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->mezzanineEventTrapReset[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.MezzanineEventTrapReset[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyMezzanineApplicationMissing=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyMezzanineApplicationMissing;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->mezzanineApplicationMissing[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.MezzanineApplicationMissing[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyMezzanineApplicationCRCMismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyMezzanineApplicationCRCMismatch;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->mezzanineApplicationCRCMismatch[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.MezzanineApplicationCRCMismatch[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyILCFault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyILCFault;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->ilcFault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.ILCFault[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->anyBroadcastCounterWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.AnyBroadcastCounterWarning;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceActuatorWarning->broadcastCounterWarning[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.BroadcastCounterWarning[i];}
           Outgoing_m1m3_logevent_ForceActuatorWarning->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceActuatorWarning.priority;

          status = mgr[LVClient].logEvent_forceActuatorWarning(Outgoing_m1m3_logevent_ForceActuatorWarning,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_ForceActuatorWarning = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_ForceSetpointWarning) {
          actorIdx = SAL__MTM1M3_logevent_forceSetpointWarning_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_forceSetpointWarning");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_ForceSetpointWarning = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_ForceSetpointWarning == false ) {
           status = mgr[LVClient].getEvent_forceSetpointWarning(Incoming_m1m3_logevent_ForceSetpointWarning);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.Timestamp=Incoming_m1m3_logevent_ForceSetpointWarning->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.AnyWarning=Incoming_m1m3_logevent_ForceSetpointWarning->anyWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.AnySafetyLimitWarning=Incoming_m1m3_logevent_ForceSetpointWarning->anySafetyLimitWarning;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.SafetyLimitWarning[i]=Incoming_m1m3_logevent_ForceSetpointWarning->safetyLimitWarning[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.XMomentWarning=Incoming_m1m3_logevent_ForceSetpointWarning->xMomentWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.YMomentWarning=Incoming_m1m3_logevent_ForceSetpointWarning->yMomentWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.ZMomentWarning=Incoming_m1m3_logevent_ForceSetpointWarning->zMomentWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.AnyNearNeighborWarning=Incoming_m1m3_logevent_ForceSetpointWarning->anyNearNeighborWarning;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.NearNeighborWarning[i]=Incoming_m1m3_logevent_ForceSetpointWarning->nearNeighborWarning[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.MagnitudeWarning=Incoming_m1m3_logevent_ForceSetpointWarning->magnitudeWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.AnyFarNeighborWarning=Incoming_m1m3_logevent_ForceSetpointWarning->anyFarNeighborWarning;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.FarNeighborWarning[i]=Incoming_m1m3_logevent_ForceSetpointWarning->farNeighborWarning[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.AnyElevationForceWarning=Incoming_m1m3_logevent_ForceSetpointWarning->anyElevationForceWarning;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.ElevationForceWarning[i]=Incoming_m1m3_logevent_ForceSetpointWarning->elevationForceWarning[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.AnyAzimuthForceWarning=Incoming_m1m3_logevent_ForceSetpointWarning->anyAzimuthForceWarning;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.AzimuthForceWarning[i]=Incoming_m1m3_logevent_ForceSetpointWarning->azimuthForceWarning[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.AnyThermalForceWarning=Incoming_m1m3_logevent_ForceSetpointWarning->anyThermalForceWarning;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.ThermalForceWarning[i]=Incoming_m1m3_logevent_ForceSetpointWarning->thermalForceWarning[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.AnyBalanceForceWarning=Incoming_m1m3_logevent_ForceSetpointWarning->anyBalanceForceWarning;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.BalanceForceWarning[i]=Incoming_m1m3_logevent_ForceSetpointWarning->balanceForceWarning[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.AnyAccelerationForceWarning=Incoming_m1m3_logevent_ForceSetpointWarning->anyAccelerationForceWarning;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.AccelerationForceWarning[i]=Incoming_m1m3_logevent_ForceSetpointWarning->accelerationForceWarning[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.ActiveOpticNetForceWarning=Incoming_m1m3_logevent_ForceSetpointWarning->activeOpticNetForceWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.AnyActiveOpticForceWarning=Incoming_m1m3_logevent_ForceSetpointWarning->anyActiveOpticForceWarning;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.ActiveOpticForceWarning[i]=Incoming_m1m3_logevent_ForceSetpointWarning->activeOpticForceWarning[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.AnyStaticForceWarning=Incoming_m1m3_logevent_ForceSetpointWarning->anyStaticForceWarning;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.StaticForceWarning[i]=Incoming_m1m3_logevent_ForceSetpointWarning->staticForceWarning[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.AberrationNetForceWarning=Incoming_m1m3_logevent_ForceSetpointWarning->aberrationNetForceWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.AnyAberrationForceWarning=Incoming_m1m3_logevent_ForceSetpointWarning->anyAberrationForceWarning;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.AberrationForceWarning[i]=Incoming_m1m3_logevent_ForceSetpointWarning->aberrationForceWarning[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.AnyOffsetForceWarning=Incoming_m1m3_logevent_ForceSetpointWarning->anyOffsetForceWarning;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.OffsetForceWarning[i]=Incoming_m1m3_logevent_ForceSetpointWarning->offsetForceWarning[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.AnyVelocityForceWarning=Incoming_m1m3_logevent_ForceSetpointWarning->anyVelocityForceWarning;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.VelocityForceWarning[i]=Incoming_m1m3_logevent_ForceSetpointWarning->velocityForceWarning[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.AnyForceWarning=Incoming_m1m3_logevent_ForceSetpointWarning->anyForceWarning;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.ForceWarning[i]=Incoming_m1m3_logevent_ForceSetpointWarning->forceWarning[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ForceSetpointWarning.priority=Incoming_m1m3_logevent_ForceSetpointWarning->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_ForceSetpointWarning = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_ForceSetpointWarning) {
          actorIdx = SAL__MTM1M3_logevent_forceSetpointWarning_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_forceSetpointWarning");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_ForceSetpointWarning = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_ForceSetpointWarning ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.priority;
           Outgoing_m1m3_logevent_ForceSetpointWarning->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.Timestamp;
           Outgoing_m1m3_logevent_ForceSetpointWarning->anyWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.AnyWarning;
           Outgoing_m1m3_logevent_ForceSetpointWarning->anySafetyLimitWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.AnySafetyLimitWarning;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceSetpointWarning->safetyLimitWarning[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.SafetyLimitWarning[i];}
           Outgoing_m1m3_logevent_ForceSetpointWarning->xMomentWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.XMomentWarning;
           Outgoing_m1m3_logevent_ForceSetpointWarning->yMomentWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.YMomentWarning;
           Outgoing_m1m3_logevent_ForceSetpointWarning->zMomentWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.ZMomentWarning;
           Outgoing_m1m3_logevent_ForceSetpointWarning->anyNearNeighborWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.AnyNearNeighborWarning;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceSetpointWarning->nearNeighborWarning[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.NearNeighborWarning[i];}
           Outgoing_m1m3_logevent_ForceSetpointWarning->magnitudeWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.MagnitudeWarning;
           Outgoing_m1m3_logevent_ForceSetpointWarning->anyFarNeighborWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.AnyFarNeighborWarning;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceSetpointWarning->farNeighborWarning[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.FarNeighborWarning[i];}
           Outgoing_m1m3_logevent_ForceSetpointWarning->anyElevationForceWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.AnyElevationForceWarning;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceSetpointWarning->elevationForceWarning[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.ElevationForceWarning[i];}
           Outgoing_m1m3_logevent_ForceSetpointWarning->anyAzimuthForceWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.AnyAzimuthForceWarning;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceSetpointWarning->azimuthForceWarning[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.AzimuthForceWarning[i];}
           Outgoing_m1m3_logevent_ForceSetpointWarning->anyThermalForceWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.AnyThermalForceWarning;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceSetpointWarning->thermalForceWarning[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.ThermalForceWarning[i];}
           Outgoing_m1m3_logevent_ForceSetpointWarning->anyBalanceForceWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.AnyBalanceForceWarning;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceSetpointWarning->balanceForceWarning[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.BalanceForceWarning[i];}
           Outgoing_m1m3_logevent_ForceSetpointWarning->anyAccelerationForceWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.AnyAccelerationForceWarning;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceSetpointWarning->accelerationForceWarning[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.AccelerationForceWarning[i];}
           Outgoing_m1m3_logevent_ForceSetpointWarning->activeOpticNetForceWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.ActiveOpticNetForceWarning;
           Outgoing_m1m3_logevent_ForceSetpointWarning->anyActiveOpticForceWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.AnyActiveOpticForceWarning;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceSetpointWarning->activeOpticForceWarning[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.ActiveOpticForceWarning[i];}
           Outgoing_m1m3_logevent_ForceSetpointWarning->anyStaticForceWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.AnyStaticForceWarning;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceSetpointWarning->staticForceWarning[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.StaticForceWarning[i];}
           Outgoing_m1m3_logevent_ForceSetpointWarning->aberrationNetForceWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.AberrationNetForceWarning;
           Outgoing_m1m3_logevent_ForceSetpointWarning->anyAberrationForceWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.AnyAberrationForceWarning;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceSetpointWarning->aberrationForceWarning[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.AberrationForceWarning[i];}
           Outgoing_m1m3_logevent_ForceSetpointWarning->anyOffsetForceWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.AnyOffsetForceWarning;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceSetpointWarning->offsetForceWarning[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.OffsetForceWarning[i];}
           Outgoing_m1m3_logevent_ForceSetpointWarning->anyVelocityForceWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.AnyVelocityForceWarning;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceSetpointWarning->velocityForceWarning[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.VelocityForceWarning[i];}
           Outgoing_m1m3_logevent_ForceSetpointWarning->anyForceWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.AnyForceWarning;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_ForceSetpointWarning->forceWarning[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.ForceWarning[i];}
           Outgoing_m1m3_logevent_ForceSetpointWarning->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ForceSetpointWarning.priority;

          status = mgr[LVClient].logEvent_forceSetpointWarning(Outgoing_m1m3_logevent_ForceSetpointWarning,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_ForceSetpointWarning = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_GyroWarning) {
          actorIdx = SAL__MTM1M3_logevent_gyroWarning_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_gyroWarning");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_GyroWarning = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_GyroWarning == false ) {
           status = mgr[LVClient].getEvent_gyroWarning(Incoming_m1m3_logevent_GyroWarning);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.Timestamp=Incoming_m1m3_logevent_GyroWarning->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.AnyWarning=Incoming_m1m3_logevent_GyroWarning->anyWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroXStatusWarning=Incoming_m1m3_logevent_GyroWarning->gyroXStatusWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroYStatusWarning=Incoming_m1m3_logevent_GyroWarning->gyroYStatusWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroZStatusWarning=Incoming_m1m3_logevent_GyroWarning->gyroZStatusWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.SequenceNumberWarning=Incoming_m1m3_logevent_GyroWarning->sequenceNumberWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.CRCMismatchWarning=Incoming_m1m3_logevent_GyroWarning->crcMismatchWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.InvalidLengthWarning=Incoming_m1m3_logevent_GyroWarning->invalidLengthWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.InvalidHeaderWarning=Incoming_m1m3_logevent_GyroWarning->invalidHeaderWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.IncompleteFrameWarning=Incoming_m1m3_logevent_GyroWarning->incompleteFrameWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroXSLDWarning=Incoming_m1m3_logevent_GyroWarning->gyroXSLDWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroXMODDACWarning=Incoming_m1m3_logevent_GyroWarning->gyroXMODDACWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroXPhaseWarning=Incoming_m1m3_logevent_GyroWarning->gyroXPhaseWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroXFlashWarning=Incoming_m1m3_logevent_GyroWarning->gyroXFlashWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroYSLDWarning=Incoming_m1m3_logevent_GyroWarning->gyroYSLDWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroYMODDACWarning=Incoming_m1m3_logevent_GyroWarning->gyroYMODDACWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroYPhaseWarning=Incoming_m1m3_logevent_GyroWarning->gyroYPhaseWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroYFlashWarning=Incoming_m1m3_logevent_GyroWarning->gyroYFlashWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroZSLDWarning=Incoming_m1m3_logevent_GyroWarning->gyroZSLDWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroZMODDACWarning=Incoming_m1m3_logevent_GyroWarning->gyroZMODDACWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroZPhaseWarning=Incoming_m1m3_logevent_GyroWarning->gyroZPhaseWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroZFlashWarning=Incoming_m1m3_logevent_GyroWarning->gyroZFlashWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroXSLDTemperatureStatusWarning=Incoming_m1m3_logevent_GyroWarning->gyroXSLDTemperatureStatusWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroYSLDTemperatureStatusWarning=Incoming_m1m3_logevent_GyroWarning->gyroYSLDTemperatureStatusWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroZSLDTemperatureStatusWarning=Incoming_m1m3_logevent_GyroWarning->gyroZSLDTemperatureStatusWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GCBTemperatureStatusWarning=Incoming_m1m3_logevent_GyroWarning->gcbTemperatureStatusWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.TemperatureStatusWarning=Incoming_m1m3_logevent_GyroWarning->temperatureStatusWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GCBDSPSPIFlashStatusWarning=Incoming_m1m3_logevent_GyroWarning->gcbDSPSPIFlashStatusWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GCBFPGASPIFlashStatusWarning=Incoming_m1m3_logevent_GyroWarning->gcbFPGASPIFlashStatusWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.DSPSPIFlashStatusWarning=Incoming_m1m3_logevent_GyroWarning->dspSPIFlashStatusWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.FPGASPIFlashStatusWarning=Incoming_m1m3_logevent_GyroWarning->fpgaSPIFlashStatusWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GCB1_2VStatusWarning=Incoming_m1m3_logevent_GyroWarning->gcb1_2VStatusWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GCB3_3VStatusWarning=Incoming_m1m3_logevent_GyroWarning->gcb3_3VStatusWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GCB5VStatusWarning=Incoming_m1m3_logevent_GyroWarning->gcb5VStatusWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.V1_2StatusWarning=Incoming_m1m3_logevent_GyroWarning->v1_2StatusWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.V3_3StatusWarning=Incoming_m1m3_logevent_GyroWarning->v3_3StatusWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.V5StatusWarning=Incoming_m1m3_logevent_GyroWarning->v5StatusWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GCBFPGAStatusWarning=Incoming_m1m3_logevent_GyroWarning->gcbFPGAStatusWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.FPGAStatusWarning=Incoming_m1m3_logevent_GyroWarning->fpgaStatusWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.HiSpeedSPORTStatusWarning=Incoming_m1m3_logevent_GyroWarning->hiSpeedSPORTStatusWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.AuxSPORTStatusWarning=Incoming_m1m3_logevent_GyroWarning->auxSPORTStatusWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.SufficientSoftwareResourcesWarning=Incoming_m1m3_logevent_GyroWarning->sufficientSoftwareResourcesWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroEOVoltsPositiveWarning=Incoming_m1m3_logevent_GyroWarning->gyroEOVoltsPositiveWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroEOVoltsNegativeWarning=Incoming_m1m3_logevent_GyroWarning->gyroEOVoltsNegativeWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroXVoltsWarning=Incoming_m1m3_logevent_GyroWarning->gyroXVoltsWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroYVoltsWarning=Incoming_m1m3_logevent_GyroWarning->gyroYVoltsWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GyroZVoltsWarning=Incoming_m1m3_logevent_GyroWarning->gyroZVoltsWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.GCBADCCommsWarning=Incoming_m1m3_logevent_GyroWarning->gcbADCCommsWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.MSYNCExternalTimingWarning=Incoming_m1m3_logevent_GyroWarning->mSYNCExternalTimingWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_GyroWarning.priority=Incoming_m1m3_logevent_GyroWarning->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_GyroWarning = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_GyroWarning) {
          actorIdx = SAL__MTM1M3_logevent_gyroWarning_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_gyroWarning");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_GyroWarning = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_GyroWarning ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.priority;
           Outgoing_m1m3_logevent_GyroWarning->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.Timestamp;
           Outgoing_m1m3_logevent_GyroWarning->anyWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.AnyWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroXStatusWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroXStatusWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroYStatusWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroYStatusWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroZStatusWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroZStatusWarning;
           Outgoing_m1m3_logevent_GyroWarning->sequenceNumberWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.SequenceNumberWarning;
           Outgoing_m1m3_logevent_GyroWarning->crcMismatchWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.CRCMismatchWarning;
           Outgoing_m1m3_logevent_GyroWarning->invalidLengthWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.InvalidLengthWarning;
           Outgoing_m1m3_logevent_GyroWarning->invalidHeaderWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.InvalidHeaderWarning;
           Outgoing_m1m3_logevent_GyroWarning->incompleteFrameWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.IncompleteFrameWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroXSLDWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroXSLDWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroXMODDACWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroXMODDACWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroXPhaseWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroXPhaseWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroXFlashWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroXFlashWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroYSLDWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroYSLDWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroYMODDACWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroYMODDACWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroYPhaseWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroYPhaseWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroYFlashWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroYFlashWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroZSLDWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroZSLDWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroZMODDACWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroZMODDACWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroZPhaseWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroZPhaseWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroZFlashWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroZFlashWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroXSLDTemperatureStatusWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroXSLDTemperatureStatusWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroYSLDTemperatureStatusWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroYSLDTemperatureStatusWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroZSLDTemperatureStatusWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroZSLDTemperatureStatusWarning;
           Outgoing_m1m3_logevent_GyroWarning->gcbTemperatureStatusWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GCBTemperatureStatusWarning;
           Outgoing_m1m3_logevent_GyroWarning->temperatureStatusWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.TemperatureStatusWarning;
           Outgoing_m1m3_logevent_GyroWarning->gcbDSPSPIFlashStatusWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GCBDSPSPIFlashStatusWarning;
           Outgoing_m1m3_logevent_GyroWarning->gcbFPGASPIFlashStatusWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GCBFPGASPIFlashStatusWarning;
           Outgoing_m1m3_logevent_GyroWarning->dspSPIFlashStatusWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.DSPSPIFlashStatusWarning;
           Outgoing_m1m3_logevent_GyroWarning->fpgaSPIFlashStatusWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.FPGASPIFlashStatusWarning;
           Outgoing_m1m3_logevent_GyroWarning->gcb1_2VStatusWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GCB1_2VStatusWarning;
           Outgoing_m1m3_logevent_GyroWarning->gcb3_3VStatusWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GCB3_3VStatusWarning;
           Outgoing_m1m3_logevent_GyroWarning->gcb5VStatusWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GCB5VStatusWarning;
           Outgoing_m1m3_logevent_GyroWarning->v1_2StatusWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.V1_2StatusWarning;
           Outgoing_m1m3_logevent_GyroWarning->v3_3StatusWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.V3_3StatusWarning;
           Outgoing_m1m3_logevent_GyroWarning->v5StatusWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.V5StatusWarning;
           Outgoing_m1m3_logevent_GyroWarning->gcbFPGAStatusWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GCBFPGAStatusWarning;
           Outgoing_m1m3_logevent_GyroWarning->fpgaStatusWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.FPGAStatusWarning;
           Outgoing_m1m3_logevent_GyroWarning->hiSpeedSPORTStatusWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.HiSpeedSPORTStatusWarning;
           Outgoing_m1m3_logevent_GyroWarning->auxSPORTStatusWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.AuxSPORTStatusWarning;
           Outgoing_m1m3_logevent_GyroWarning->sufficientSoftwareResourcesWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.SufficientSoftwareResourcesWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroEOVoltsPositiveWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroEOVoltsPositiveWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroEOVoltsNegativeWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroEOVoltsNegativeWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroXVoltsWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroXVoltsWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroYVoltsWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroYVoltsWarning;
           Outgoing_m1m3_logevent_GyroWarning->gyroZVoltsWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GyroZVoltsWarning;
           Outgoing_m1m3_logevent_GyroWarning->gcbADCCommsWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.GCBADCCommsWarning;
           Outgoing_m1m3_logevent_GyroWarning->mSYNCExternalTimingWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.MSYNCExternalTimingWarning;
           Outgoing_m1m3_logevent_GyroWarning->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_GyroWarning.priority;

          status = mgr[LVClient].logEvent_gyroWarning(Outgoing_m1m3_logevent_GyroWarning,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_GyroWarning = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_HardpointActuatorInfo) {
          actorIdx = SAL__MTM1M3_logevent_hardpointActuatorInfo_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_hardpointActuatorInfo");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_HardpointActuatorInfo = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_HardpointActuatorInfo == false ) {
           status = mgr[LVClient].getEvent_hardpointActuatorInfo(Incoming_m1m3_logevent_HardpointActuatorInfo);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.Timestamp=Incoming_m1m3_logevent_HardpointActuatorInfo->timestamp;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.ReferenceId[i]=Incoming_m1m3_logevent_HardpointActuatorInfo->referenceId[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.ReferencePosition[i]=Incoming_m1m3_logevent_HardpointActuatorInfo->referencePosition[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.ModbusSubnet[i]=Incoming_m1m3_logevent_HardpointActuatorInfo->modbusSubnet[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.ModbusAddress[i]=Incoming_m1m3_logevent_HardpointActuatorInfo->modbusAddress[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.XPosition[i]=Incoming_m1m3_logevent_HardpointActuatorInfo->xPosition[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.YPosition[i]=Incoming_m1m3_logevent_HardpointActuatorInfo->yPosition[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.ZPosition[i]=Incoming_m1m3_logevent_HardpointActuatorInfo->zPosition[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.ILCUniqueId[i]=Incoming_m1m3_logevent_HardpointActuatorInfo->ilcUniqueId[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.ILCApplicationType[i]=Incoming_m1m3_logevent_HardpointActuatorInfo->ilcApplicationType[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.NetworkNodeType[i]=Incoming_m1m3_logevent_HardpointActuatorInfo->networkNodeType[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.ILCSelectedOptions[i]=Incoming_m1m3_logevent_HardpointActuatorInfo->ilcSelectedOptions[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.NetworkNodeOptions[i]=Incoming_m1m3_logevent_HardpointActuatorInfo->networkNodeOptions[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.MajorRevision[i]=Incoming_m1m3_logevent_HardpointActuatorInfo->majorRevision[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.MinorRevision[i]=Incoming_m1m3_logevent_HardpointActuatorInfo->minorRevision[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.ADCScanRate[i]=Incoming_m1m3_logevent_HardpointActuatorInfo->adcScanRate[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.MainLoadCellCoefficient[i]=Incoming_m1m3_logevent_HardpointActuatorInfo->mainLoadCellCoefficient[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.MainLoadCellOffset[i]=Incoming_m1m3_logevent_HardpointActuatorInfo->mainLoadCellOffset[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.MainLoadCellSensitivity[i]=Incoming_m1m3_logevent_HardpointActuatorInfo->mainLoadCellSensitivity[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.BackupLoadCellCoefficient[i]=Incoming_m1m3_logevent_HardpointActuatorInfo->backupLoadCellCoefficient[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.BackupLoadCellOffset[i]=Incoming_m1m3_logevent_HardpointActuatorInfo->backupLoadCellOffset[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.BackupLoadCellSensitivity[i]=Incoming_m1m3_logevent_HardpointActuatorInfo->backupLoadCellSensitivity[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorInfo.priority=Incoming_m1m3_logevent_HardpointActuatorInfo->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_HardpointActuatorInfo = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_HardpointActuatorInfo) {
          actorIdx = SAL__MTM1M3_logevent_hardpointActuatorInfo_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_hardpointActuatorInfo");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_HardpointActuatorInfo = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_HardpointActuatorInfo ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.priority;
           Outgoing_m1m3_logevent_HardpointActuatorInfo->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.Timestamp;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorInfo->referenceId[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.ReferenceId[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorInfo->referencePosition[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.ReferencePosition[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorInfo->modbusSubnet[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.ModbusSubnet[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorInfo->modbusAddress[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.ModbusAddress[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorInfo->xPosition[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.XPosition[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorInfo->yPosition[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.YPosition[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorInfo->zPosition[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.ZPosition[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorInfo->ilcUniqueId[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.ILCUniqueId[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorInfo->ilcApplicationType[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.ILCApplicationType[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorInfo->networkNodeType[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.NetworkNodeType[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorInfo->ilcSelectedOptions[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.ILCSelectedOptions[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorInfo->networkNodeOptions[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.NetworkNodeOptions[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorInfo->majorRevision[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.MajorRevision[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorInfo->minorRevision[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.MinorRevision[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorInfo->adcScanRate[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.ADCScanRate[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorInfo->mainLoadCellCoefficient[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.MainLoadCellCoefficient[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorInfo->mainLoadCellOffset[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.MainLoadCellOffset[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorInfo->mainLoadCellSensitivity[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.MainLoadCellSensitivity[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorInfo->backupLoadCellCoefficient[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.BackupLoadCellCoefficient[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorInfo->backupLoadCellOffset[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.BackupLoadCellOffset[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorInfo->backupLoadCellSensitivity[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.BackupLoadCellSensitivity[i];}
           Outgoing_m1m3_logevent_HardpointActuatorInfo->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorInfo.priority;

          status = mgr[LVClient].logEvent_hardpointActuatorInfo(Outgoing_m1m3_logevent_HardpointActuatorInfo,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_HardpointActuatorInfo = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_HardpointActuatorState) {
          actorIdx = SAL__MTM1M3_logevent_hardpointActuatorState_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_hardpointActuatorState");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_HardpointActuatorState = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_HardpointActuatorState == false ) {
           status = mgr[LVClient].getEvent_hardpointActuatorState(Incoming_m1m3_logevent_HardpointActuatorState);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorState.Timestamp=Incoming_m1m3_logevent_HardpointActuatorState->timestamp;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorState.ILCState[i]=Incoming_m1m3_logevent_HardpointActuatorState->ilcState[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorState.MotionState[i]=Incoming_m1m3_logevent_HardpointActuatorState->motionState[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorState.priority=Incoming_m1m3_logevent_HardpointActuatorState->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_HardpointActuatorState = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_HardpointActuatorState) {
          actorIdx = SAL__MTM1M3_logevent_hardpointActuatorState_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_hardpointActuatorState");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_HardpointActuatorState = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_HardpointActuatorState ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorState.priority;
           Outgoing_m1m3_logevent_HardpointActuatorState->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorState.Timestamp;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorState->ilcState[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorState.ILCState[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorState->motionState[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorState.MotionState[i];}
           Outgoing_m1m3_logevent_HardpointActuatorState->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorState.priority;

          status = mgr[LVClient].logEvent_hardpointActuatorState(Outgoing_m1m3_logevent_HardpointActuatorState,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_HardpointActuatorState = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_HardpointActuatorWarning) {
          actorIdx = SAL__MTM1M3_logevent_hardpointActuatorWarning_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_hardpointActuatorWarning");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_HardpointActuatorWarning = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_HardpointActuatorWarning == false ) {
           status = mgr[LVClient].getEvent_hardpointActuatorWarning(Incoming_m1m3_logevent_HardpointActuatorWarning);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.Timestamp=Incoming_m1m3_logevent_HardpointActuatorWarning->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnyWarning=Incoming_m1m3_logevent_HardpointActuatorWarning->anyWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnyMajorFault=Incoming_m1m3_logevent_HardpointActuatorWarning->anyMajorFault;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.MajorFault[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->majorFault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnyMinorFault=Incoming_m1m3_logevent_HardpointActuatorWarning->anyMinorFault;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.MinorFault[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->minorFault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnyFaultOverride=Incoming_m1m3_logevent_HardpointActuatorWarning->anyFaultOverride;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.FaultOverride[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->faultOverride[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnyMainCalibrationError=Incoming_m1m3_logevent_HardpointActuatorWarning->anyMainCalibrationError;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.MainCalibrationError[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->mainCalibrationError[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnyBackupCalibrationError=Incoming_m1m3_logevent_HardpointActuatorWarning->anyBackupCalibrationError;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.BackupCalibrationError[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->backupCalibrationError[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnyLimitSwitch1Operated=Incoming_m1m3_logevent_HardpointActuatorWarning->anyLimitSwitch1Operated;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.LimitSwitch1Operated[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->limitSwitch1Operated[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnyLimitSwitch2Operated=Incoming_m1m3_logevent_HardpointActuatorWarning->anyLimitSwitch2Operated;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.LimitSwitch2Operated[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->limitSwitch2Operated[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnyUniqueIdCRCError=Incoming_m1m3_logevent_HardpointActuatorWarning->anyUniqueIdCRCError;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.UniqueIdCRCError[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->uniqueIdCRCError[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnyApplicationTypeMismatch=Incoming_m1m3_logevent_HardpointActuatorWarning->anyApplicationTypeMismatch;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.ApplicationTypeMismatch[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->applicationTypeMismatch[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnyApplicationMissing=Incoming_m1m3_logevent_HardpointActuatorWarning->anyApplicationMissing;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.ApplicationMissing[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->applicationMissing[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnyApplicationCRCMismatch=Incoming_m1m3_logevent_HardpointActuatorWarning->anyApplicationCRCMismatch;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.ApplicationCRCMismatch[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->applicationCRCMismatch[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnyOneWireMissing=Incoming_m1m3_logevent_HardpointActuatorWarning->anyOneWireMissing;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.OneWireMissing[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->oneWireMissing[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnyOneWire1Mismatch=Incoming_m1m3_logevent_HardpointActuatorWarning->anyOneWire1Mismatch;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.OneWire1Mismatch[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->oneWire1Mismatch[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnyOneWire2Mismatch=Incoming_m1m3_logevent_HardpointActuatorWarning->anyOneWire2Mismatch;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.OneWire2Mismatch[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->oneWire2Mismatch[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnyWatchdogReset=Incoming_m1m3_logevent_HardpointActuatorWarning->anyWatchdogReset;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.WatchdogReset[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->watchdogReset[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnyBrownOut=Incoming_m1m3_logevent_HardpointActuatorWarning->anyBrownOut;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.BrownOut[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->brownOut[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnyEventTrapReset=Incoming_m1m3_logevent_HardpointActuatorWarning->anyEventTrapReset;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.EventTrapReset[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->eventTrapReset[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnyMotorDriverFault=Incoming_m1m3_logevent_HardpointActuatorWarning->anyMotorDriverFault;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.MotorDriverFault[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->motorDriverFault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnySSRPowerFault=Incoming_m1m3_logevent_HardpointActuatorWarning->anySSRPowerFault;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.SSRPowerFault[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->ssrPowerFault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnyAuxPowerFault=Incoming_m1m3_logevent_HardpointActuatorWarning->anyAuxPowerFault;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AuxPowerFault[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->auxPowerFault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnySMCPowerFault=Incoming_m1m3_logevent_HardpointActuatorWarning->anySMCPowerFault;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.SMCPowerFault[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->smcPowerFault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnyILCFault=Incoming_m1m3_logevent_HardpointActuatorWarning->anyILCFault;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.ILCFault[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->ilcFault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.AnyBroadcastCounterWarning=Incoming_m1m3_logevent_HardpointActuatorWarning->anyBroadcastCounterWarning;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.BroadcastCounterWarning[i]=Incoming_m1m3_logevent_HardpointActuatorWarning->broadcastCounterWarning[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointActuatorWarning.priority=Incoming_m1m3_logevent_HardpointActuatorWarning->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_HardpointActuatorWarning = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_HardpointActuatorWarning) {
          actorIdx = SAL__MTM1M3_logevent_hardpointActuatorWarning_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_hardpointActuatorWarning");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_HardpointActuatorWarning = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_HardpointActuatorWarning ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.priority;
           Outgoing_m1m3_logevent_HardpointActuatorWarning->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.Timestamp;
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anyWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnyWarning;
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anyMajorFault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnyMajorFault;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->majorFault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.MajorFault[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anyMinorFault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnyMinorFault;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->minorFault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.MinorFault[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anyFaultOverride=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnyFaultOverride;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->faultOverride[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.FaultOverride[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anyMainCalibrationError=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnyMainCalibrationError;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->mainCalibrationError[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.MainCalibrationError[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anyBackupCalibrationError=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnyBackupCalibrationError;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->backupCalibrationError[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.BackupCalibrationError[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anyLimitSwitch1Operated=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnyLimitSwitch1Operated;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->limitSwitch1Operated[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.LimitSwitch1Operated[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anyLimitSwitch2Operated=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnyLimitSwitch2Operated;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->limitSwitch2Operated[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.LimitSwitch2Operated[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anyUniqueIdCRCError=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnyUniqueIdCRCError;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->uniqueIdCRCError[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.UniqueIdCRCError[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anyApplicationTypeMismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnyApplicationTypeMismatch;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->applicationTypeMismatch[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.ApplicationTypeMismatch[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anyApplicationMissing=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnyApplicationMissing;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->applicationMissing[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.ApplicationMissing[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anyApplicationCRCMismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnyApplicationCRCMismatch;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->applicationCRCMismatch[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.ApplicationCRCMismatch[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anyOneWireMissing=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnyOneWireMissing;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->oneWireMissing[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.OneWireMissing[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anyOneWire1Mismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnyOneWire1Mismatch;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->oneWire1Mismatch[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.OneWire1Mismatch[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anyOneWire2Mismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnyOneWire2Mismatch;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->oneWire2Mismatch[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.OneWire2Mismatch[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anyWatchdogReset=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnyWatchdogReset;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->watchdogReset[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.WatchdogReset[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anyBrownOut=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnyBrownOut;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->brownOut[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.BrownOut[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anyEventTrapReset=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnyEventTrapReset;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->eventTrapReset[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.EventTrapReset[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anyMotorDriverFault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnyMotorDriverFault;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->motorDriverFault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.MotorDriverFault[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anySSRPowerFault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnySSRPowerFault;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->ssrPowerFault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.SSRPowerFault[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anyAuxPowerFault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnyAuxPowerFault;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->auxPowerFault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AuxPowerFault[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anySMCPowerFault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnySMCPowerFault;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->smcPowerFault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.SMCPowerFault[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anyILCFault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnyILCFault;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->ilcFault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.ILCFault[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->anyBroadcastCounterWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.AnyBroadcastCounterWarning;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointActuatorWarning->broadcastCounterWarning[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.BroadcastCounterWarning[i];}
           Outgoing_m1m3_logevent_HardpointActuatorWarning->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointActuatorWarning.priority;

          status = mgr[LVClient].logEvent_hardpointActuatorWarning(Outgoing_m1m3_logevent_HardpointActuatorWarning,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_HardpointActuatorWarning = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_HardpointMonitorInfo) {
          actorIdx = SAL__MTM1M3_logevent_hardpointMonitorInfo_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_hardpointMonitorInfo");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_HardpointMonitorInfo = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_HardpointMonitorInfo == false ) {
           status = mgr[LVClient].getEvent_hardpointMonitorInfo(Incoming_m1m3_logevent_HardpointMonitorInfo);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorInfo.Timestamp=Incoming_m1m3_logevent_HardpointMonitorInfo->timestamp;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorInfo.ReferenceId[i]=Incoming_m1m3_logevent_HardpointMonitorInfo->referenceId[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorInfo.ModbusSubnet[i]=Incoming_m1m3_logevent_HardpointMonitorInfo->modbusSubnet[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorInfo.ModbusAddress[i]=Incoming_m1m3_logevent_HardpointMonitorInfo->modbusAddress[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorInfo.ILCUniqueId[i]=Incoming_m1m3_logevent_HardpointMonitorInfo->ilcUniqueId[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorInfo.ILCApplicationType[i]=Incoming_m1m3_logevent_HardpointMonitorInfo->ilcApplicationType[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorInfo.NetworkNodeType[i]=Incoming_m1m3_logevent_HardpointMonitorInfo->networkNodeType[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorInfo.MajorRevision[i]=Incoming_m1m3_logevent_HardpointMonitorInfo->majorRevision[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorInfo.MinorRevision[i]=Incoming_m1m3_logevent_HardpointMonitorInfo->minorRevision[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorInfo.MezzanineUniqueId[i]=Incoming_m1m3_logevent_HardpointMonitorInfo->mezzanineUniqueId[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorInfo.MezzanineFirmwareType[i]=Incoming_m1m3_logevent_HardpointMonitorInfo->mezzanineFirmwareType[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorInfo.MezzanineMajorRevision[i]=Incoming_m1m3_logevent_HardpointMonitorInfo->mezzanineMajorRevision[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorInfo.MezzanineMinorRevision[i]=Incoming_m1m3_logevent_HardpointMonitorInfo->mezzanineMinorRevision[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorInfo.priority=Incoming_m1m3_logevent_HardpointMonitorInfo->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_HardpointMonitorInfo = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_HardpointMonitorInfo) {
          actorIdx = SAL__MTM1M3_logevent_hardpointMonitorInfo_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_hardpointMonitorInfo");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_HardpointMonitorInfo = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_HardpointMonitorInfo ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorInfo.priority;
           Outgoing_m1m3_logevent_HardpointMonitorInfo->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorInfo.Timestamp;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorInfo->referenceId[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorInfo.ReferenceId[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorInfo->modbusSubnet[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorInfo.ModbusSubnet[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorInfo->modbusAddress[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorInfo.ModbusAddress[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorInfo->ilcUniqueId[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorInfo.ILCUniqueId[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorInfo->ilcApplicationType[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorInfo.ILCApplicationType[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorInfo->networkNodeType[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorInfo.NetworkNodeType[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorInfo->majorRevision[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorInfo.MajorRevision[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorInfo->minorRevision[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorInfo.MinorRevision[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorInfo->mezzanineUniqueId[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorInfo.MezzanineUniqueId[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorInfo->mezzanineFirmwareType[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorInfo.MezzanineFirmwareType[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorInfo->mezzanineMajorRevision[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorInfo.MezzanineMajorRevision[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorInfo->mezzanineMinorRevision[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorInfo.MezzanineMinorRevision[i];}
           Outgoing_m1m3_logevent_HardpointMonitorInfo->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorInfo.priority;

          status = mgr[LVClient].logEvent_hardpointMonitorInfo(Outgoing_m1m3_logevent_HardpointMonitorInfo,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_HardpointMonitorInfo = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_HardpointMonitorState) {
          actorIdx = SAL__MTM1M3_logevent_hardpointMonitorState_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_hardpointMonitorState");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_HardpointMonitorState = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_HardpointMonitorState == false ) {
           status = mgr[LVClient].getEvent_hardpointMonitorState(Incoming_m1m3_logevent_HardpointMonitorState);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorState.Timestamp=Incoming_m1m3_logevent_HardpointMonitorState->timestamp;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorState.ILCState[i]=Incoming_m1m3_logevent_HardpointMonitorState->ilcState[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorState.priority=Incoming_m1m3_logevent_HardpointMonitorState->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_HardpointMonitorState = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_HardpointMonitorState) {
          actorIdx = SAL__MTM1M3_logevent_hardpointMonitorState_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_hardpointMonitorState");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_HardpointMonitorState = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_HardpointMonitorState ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorState.priority;
           Outgoing_m1m3_logevent_HardpointMonitorState->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorState.Timestamp;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorState->ilcState[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorState.ILCState[i];}
           Outgoing_m1m3_logevent_HardpointMonitorState->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorState.priority;

          status = mgr[LVClient].logEvent_hardpointMonitorState(Outgoing_m1m3_logevent_HardpointMonitorState,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_HardpointMonitorState = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_HardpointMonitorWarning) {
          actorIdx = SAL__MTM1M3_logevent_hardpointMonitorWarning_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_hardpointMonitorWarning");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_HardpointMonitorWarning = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_HardpointMonitorWarning == false ) {
           status = mgr[LVClient].getEvent_hardpointMonitorWarning(Incoming_m1m3_logevent_HardpointMonitorWarning);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.Timestamp=Incoming_m1m3_logevent_HardpointMonitorWarning->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyWarning=Incoming_m1m3_logevent_HardpointMonitorWarning->anyWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyMajorFault=Incoming_m1m3_logevent_HardpointMonitorWarning->anyMajorFault;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.MajorFault[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->majorFault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyMinorFault=Incoming_m1m3_logevent_HardpointMonitorWarning->anyMinorFault;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.MinorFault[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->minorFault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyFaultOverride=Incoming_m1m3_logevent_HardpointMonitorWarning->anyFaultOverride;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.FaultOverride[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->faultOverride[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyInstrumentError=Incoming_m1m3_logevent_HardpointMonitorWarning->anyInstrumentError;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.InstrumentError[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->instrumentError[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyMezzanineError=Incoming_m1m3_logevent_HardpointMonitorWarning->anyMezzanineError;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.MezzanineError[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->mezzanineError[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyMezzanineBootloaderActive=Incoming_m1m3_logevent_HardpointMonitorWarning->anyMezzanineBootloaderActive;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.MezzanineBootloaderActive[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->mezzanineBootloaderActive[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyUniqueIdCRCError=Incoming_m1m3_logevent_HardpointMonitorWarning->anyUniqueIdCRCError;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.UniqueIdCRCError[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->uniqueIdCRCError[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyApplicationTypeMismatch=Incoming_m1m3_logevent_HardpointMonitorWarning->anyApplicationTypeMismatch;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.ApplicationTypeMismatch[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->applicationTypeMismatch[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyApplicationMissing=Incoming_m1m3_logevent_HardpointMonitorWarning->anyApplicationMissing;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.ApplicationMissing[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->applicationMissing[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyApplicationCRCMismatch=Incoming_m1m3_logevent_HardpointMonitorWarning->anyApplicationCRCMismatch;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.ApplicationCRCMismatch[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->applicationCRCMismatch[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyOneWireMissing=Incoming_m1m3_logevent_HardpointMonitorWarning->anyOneWireMissing;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.OneWireMissing[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->oneWireMissing[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyOneWire1Mismatch=Incoming_m1m3_logevent_HardpointMonitorWarning->anyOneWire1Mismatch;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.OneWire1Mismatch[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->oneWire1Mismatch[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyOneWire2Mismatch=Incoming_m1m3_logevent_HardpointMonitorWarning->anyOneWire2Mismatch;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.OneWire2Mismatch[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->oneWire2Mismatch[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyWatchdogReset=Incoming_m1m3_logevent_HardpointMonitorWarning->anyWatchdogReset;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.WatchdogReset[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->watchdogReset[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyBrownOut=Incoming_m1m3_logevent_HardpointMonitorWarning->anyBrownOut;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.BrownOut[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->brownOut[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyEventTrapReset=Incoming_m1m3_logevent_HardpointMonitorWarning->anyEventTrapReset;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.EventTrapReset[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->eventTrapReset[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnySSRPowerFault=Incoming_m1m3_logevent_HardpointMonitorWarning->anySSRPowerFault;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.SSRPowerFault[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->ssrPowerFault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyAuxPowerFault=Incoming_m1m3_logevent_HardpointMonitorWarning->anyAuxPowerFault;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AuxPowerFault[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->auxPowerFault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyMezzanineS1AInterface1Fault=Incoming_m1m3_logevent_HardpointMonitorWarning->anyMezzanineS1AInterface1Fault;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.MezzanineS1AInterface1Fault[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->mezzanineS1AInterface1Fault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyMezzanineS1ALVDT1Fault=Incoming_m1m3_logevent_HardpointMonitorWarning->anyMezzanineS1ALVDT1Fault;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.MezzanineS1ALVDT1Fault[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->mezzanineS1ALVDT1Fault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyMezzanineS1AInterface2Fault=Incoming_m1m3_logevent_HardpointMonitorWarning->anyMezzanineS1AInterface2Fault;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.MezzanineS1AInterface2Fault[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->mezzanineS1AInterface2Fault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyMezzanineS1ALVDT2Fault=Incoming_m1m3_logevent_HardpointMonitorWarning->anyMezzanineS1ALVDT2Fault;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.MezzanineS1ALVDT2Fault[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->mezzanineS1ALVDT2Fault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyMezzanineUniqueIdCRCError=Incoming_m1m3_logevent_HardpointMonitorWarning->anyMezzanineUniqueIdCRCError;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.MezzanineUniqueIdCRCError[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->mezzanineUniqueIdCRCError[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyMezzanineEventTrapReset=Incoming_m1m3_logevent_HardpointMonitorWarning->anyMezzanineEventTrapReset;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.MezzanineEventTrapReset[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->mezzanineEventTrapReset[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyMezzanineDCPRS422ChipFault=Incoming_m1m3_logevent_HardpointMonitorWarning->anyMezzanineDCPRS422ChipFault;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.MezzanineDCPRS422ChipFault[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->mezzanineDCPRS422ChipFault[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyMezzanineApplicationMissing=Incoming_m1m3_logevent_HardpointMonitorWarning->anyMezzanineApplicationMissing;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.MezzanineApplicationMissing[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->mezzanineApplicationMissing[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.AnyMezzanineApplicationCRCMismatch=Incoming_m1m3_logevent_HardpointMonitorWarning->anyMezzanineApplicationCRCMismatch;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.MezzanineApplicationCRCMismatch[i]=Incoming_m1m3_logevent_HardpointMonitorWarning->mezzanineApplicationCRCMismatch[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_HardpointMonitorWarning.priority=Incoming_m1m3_logevent_HardpointMonitorWarning->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_HardpointMonitorWarning = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_HardpointMonitorWarning) {
          actorIdx = SAL__MTM1M3_logevent_hardpointMonitorWarning_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_hardpointMonitorWarning");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_HardpointMonitorWarning = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_HardpointMonitorWarning ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.priority;
           Outgoing_m1m3_logevent_HardpointMonitorWarning->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.Timestamp;
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyWarning;
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyMajorFault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyMajorFault;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->majorFault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.MajorFault[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyMinorFault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyMinorFault;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->minorFault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.MinorFault[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyFaultOverride=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyFaultOverride;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->faultOverride[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.FaultOverride[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyInstrumentError=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyInstrumentError;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->instrumentError[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.InstrumentError[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyMezzanineError=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyMezzanineError;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->mezzanineError[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.MezzanineError[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyMezzanineBootloaderActive=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyMezzanineBootloaderActive;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->mezzanineBootloaderActive[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.MezzanineBootloaderActive[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyUniqueIdCRCError=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyUniqueIdCRCError;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->uniqueIdCRCError[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.UniqueIdCRCError[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyApplicationTypeMismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyApplicationTypeMismatch;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->applicationTypeMismatch[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.ApplicationTypeMismatch[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyApplicationMissing=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyApplicationMissing;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->applicationMissing[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.ApplicationMissing[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyApplicationCRCMismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyApplicationCRCMismatch;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->applicationCRCMismatch[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.ApplicationCRCMismatch[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyOneWireMissing=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyOneWireMissing;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->oneWireMissing[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.OneWireMissing[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyOneWire1Mismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyOneWire1Mismatch;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->oneWire1Mismatch[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.OneWire1Mismatch[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyOneWire2Mismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyOneWire2Mismatch;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->oneWire2Mismatch[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.OneWire2Mismatch[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyWatchdogReset=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyWatchdogReset;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->watchdogReset[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.WatchdogReset[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyBrownOut=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyBrownOut;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->brownOut[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.BrownOut[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyEventTrapReset=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyEventTrapReset;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->eventTrapReset[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.EventTrapReset[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anySSRPowerFault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnySSRPowerFault;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->ssrPowerFault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.SSRPowerFault[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyAuxPowerFault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyAuxPowerFault;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->auxPowerFault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AuxPowerFault[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyMezzanineS1AInterface1Fault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyMezzanineS1AInterface1Fault;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->mezzanineS1AInterface1Fault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.MezzanineS1AInterface1Fault[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyMezzanineS1ALVDT1Fault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyMezzanineS1ALVDT1Fault;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->mezzanineS1ALVDT1Fault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.MezzanineS1ALVDT1Fault[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyMezzanineS1AInterface2Fault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyMezzanineS1AInterface2Fault;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->mezzanineS1AInterface2Fault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.MezzanineS1AInterface2Fault[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyMezzanineS1ALVDT2Fault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyMezzanineS1ALVDT2Fault;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->mezzanineS1ALVDT2Fault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.MezzanineS1ALVDT2Fault[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyMezzanineUniqueIdCRCError=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyMezzanineUniqueIdCRCError;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->mezzanineUniqueIdCRCError[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.MezzanineUniqueIdCRCError[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyMezzanineEventTrapReset=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyMezzanineEventTrapReset;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->mezzanineEventTrapReset[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.MezzanineEventTrapReset[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyMezzanineDCPRS422ChipFault=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyMezzanineDCPRS422ChipFault;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->mezzanineDCPRS422ChipFault[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.MezzanineDCPRS422ChipFault[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyMezzanineApplicationMissing=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyMezzanineApplicationMissing;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->mezzanineApplicationMissing[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.MezzanineApplicationMissing[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->anyMezzanineApplicationCRCMismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.AnyMezzanineApplicationCRCMismatch;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_HardpointMonitorWarning->mezzanineApplicationCRCMismatch[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.MezzanineApplicationCRCMismatch[i];}
           Outgoing_m1m3_logevent_HardpointMonitorWarning->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_HardpointMonitorWarning.priority;

          status = mgr[LVClient].logEvent_hardpointMonitorWarning(Outgoing_m1m3_logevent_HardpointMonitorWarning,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_HardpointMonitorWarning = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_ILCWarning) {
          actorIdx = SAL__MTM1M3_logevent_ilcWarning_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_ilcWarning");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_ILCWarning = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_ILCWarning == false ) {
           status = mgr[LVClient].getEvent_ilcWarning(Incoming_m1m3_logevent_ILCWarning);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ILCWarning.Timestamp=Incoming_m1m3_logevent_ILCWarning->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ILCWarning.ActuatorId=Incoming_m1m3_logevent_ILCWarning->actuatorId;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ILCWarning.AnyWarning=Incoming_m1m3_logevent_ILCWarning->anyWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ILCWarning.ResponseTimeout=Incoming_m1m3_logevent_ILCWarning->responseTimeout;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ILCWarning.InvalidCRC=Incoming_m1m3_logevent_ILCWarning->invalidCRC;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ILCWarning.IllegalFunction=Incoming_m1m3_logevent_ILCWarning->illegalFunction;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ILCWarning.IllegalDataValue=Incoming_m1m3_logevent_ILCWarning->illegalDataValue;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ILCWarning.InvalidLength=Incoming_m1m3_logevent_ILCWarning->invalidLength;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ILCWarning.UnknownSubnet=Incoming_m1m3_logevent_ILCWarning->unknownSubnet;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ILCWarning.UnknownAddress=Incoming_m1m3_logevent_ILCWarning->unknownAddress;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ILCWarning.UnknownFunction=Incoming_m1m3_logevent_ILCWarning->unknownFunction;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ILCWarning.UnknownProblem=Incoming_m1m3_logevent_ILCWarning->unknownProblem;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_ILCWarning.priority=Incoming_m1m3_logevent_ILCWarning->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_ILCWarning = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_ILCWarning) {
          actorIdx = SAL__MTM1M3_logevent_ilcWarning_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_ilcWarning");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_ILCWarning = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_ILCWarning ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ILCWarning.priority;
           Outgoing_m1m3_logevent_ILCWarning->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ILCWarning.Timestamp;
           Outgoing_m1m3_logevent_ILCWarning->actuatorId=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ILCWarning.ActuatorId;
           Outgoing_m1m3_logevent_ILCWarning->anyWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ILCWarning.AnyWarning;
           Outgoing_m1m3_logevent_ILCWarning->responseTimeout=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ILCWarning.ResponseTimeout;
           Outgoing_m1m3_logevent_ILCWarning->invalidCRC=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ILCWarning.InvalidCRC;
           Outgoing_m1m3_logevent_ILCWarning->illegalFunction=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ILCWarning.IllegalFunction;
           Outgoing_m1m3_logevent_ILCWarning->illegalDataValue=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ILCWarning.IllegalDataValue;
           Outgoing_m1m3_logevent_ILCWarning->invalidLength=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ILCWarning.InvalidLength;
           Outgoing_m1m3_logevent_ILCWarning->unknownSubnet=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ILCWarning.UnknownSubnet;
           Outgoing_m1m3_logevent_ILCWarning->unknownAddress=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ILCWarning.UnknownAddress;
           Outgoing_m1m3_logevent_ILCWarning->unknownFunction=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ILCWarning.UnknownFunction;
           Outgoing_m1m3_logevent_ILCWarning->unknownProblem=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ILCWarning.UnknownProblem;
           Outgoing_m1m3_logevent_ILCWarning->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_ILCWarning.priority;

          status = mgr[LVClient].logEvent_ilcWarning(Outgoing_m1m3_logevent_ILCWarning,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_ILCWarning = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_InclinometerSensorWarning) {
          actorIdx = SAL__MTM1M3_logevent_inclinometerSensorWarning_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_inclinometerSensorWarning");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_InclinometerSensorWarning = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_InclinometerSensorWarning == false ) {
           status = mgr[LVClient].getEvent_inclinometerSensorWarning(Incoming_m1m3_logevent_InclinometerSensorWarning);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InclinometerSensorWarning.Timestamp=Incoming_m1m3_logevent_InclinometerSensorWarning->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InclinometerSensorWarning.AnyWarning=Incoming_m1m3_logevent_InclinometerSensorWarning->anyWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InclinometerSensorWarning.SensorReportsIllegalFunction=Incoming_m1m3_logevent_InclinometerSensorWarning->sensorReportsIllegalFunction;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InclinometerSensorWarning.SensorReportsIllegalDataAddress=Incoming_m1m3_logevent_InclinometerSensorWarning->sensorReportsIllegalDataAddress;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InclinometerSensorWarning.ResponseTimeout=Incoming_m1m3_logevent_InclinometerSensorWarning->responseTimeout;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InclinometerSensorWarning.InvalidCRC=Incoming_m1m3_logevent_InclinometerSensorWarning->invalidCRC;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InclinometerSensorWarning.InvalidLength=Incoming_m1m3_logevent_InclinometerSensorWarning->invalidLength;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InclinometerSensorWarning.UnknownAddress=Incoming_m1m3_logevent_InclinometerSensorWarning->unknownAddress;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InclinometerSensorWarning.UnknownFunction=Incoming_m1m3_logevent_InclinometerSensorWarning->unknownFunction;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InclinometerSensorWarning.UnknownProblem=Incoming_m1m3_logevent_InclinometerSensorWarning->unknownProblem;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InclinometerSensorWarning.priority=Incoming_m1m3_logevent_InclinometerSensorWarning->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_InclinometerSensorWarning = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_InclinometerSensorWarning) {
          actorIdx = SAL__MTM1M3_logevent_inclinometerSensorWarning_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_inclinometerSensorWarning");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_InclinometerSensorWarning = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_InclinometerSensorWarning ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InclinometerSensorWarning.priority;
           Outgoing_m1m3_logevent_InclinometerSensorWarning->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InclinometerSensorWarning.Timestamp;
           Outgoing_m1m3_logevent_InclinometerSensorWarning->anyWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InclinometerSensorWarning.AnyWarning;
           Outgoing_m1m3_logevent_InclinometerSensorWarning->sensorReportsIllegalFunction=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InclinometerSensorWarning.SensorReportsIllegalFunction;
           Outgoing_m1m3_logevent_InclinometerSensorWarning->sensorReportsIllegalDataAddress=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InclinometerSensorWarning.SensorReportsIllegalDataAddress;
           Outgoing_m1m3_logevent_InclinometerSensorWarning->responseTimeout=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InclinometerSensorWarning.ResponseTimeout;
           Outgoing_m1m3_logevent_InclinometerSensorWarning->invalidCRC=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InclinometerSensorWarning.InvalidCRC;
           Outgoing_m1m3_logevent_InclinometerSensorWarning->invalidLength=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InclinometerSensorWarning.InvalidLength;
           Outgoing_m1m3_logevent_InclinometerSensorWarning->unknownAddress=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InclinometerSensorWarning.UnknownAddress;
           Outgoing_m1m3_logevent_InclinometerSensorWarning->unknownFunction=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InclinometerSensorWarning.UnknownFunction;
           Outgoing_m1m3_logevent_InclinometerSensorWarning->unknownProblem=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InclinometerSensorWarning.UnknownProblem;
           Outgoing_m1m3_logevent_InclinometerSensorWarning->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InclinometerSensorWarning.priority;

          status = mgr[LVClient].logEvent_inclinometerSensorWarning(Outgoing_m1m3_logevent_InclinometerSensorWarning,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_InclinometerSensorWarning = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_InterlockStatus) {
          actorIdx = SAL__MTM1M3_logevent_interlockStatus_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_InterlockStatus");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_InterlockStatus = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_InterlockStatus == false ) {
           status = mgr[LVClient].getEvent_interlockStatus(Incoming_m1m3_logevent_InterlockStatus);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InterlockStatus.Timestamp=Incoming_m1m3_logevent_InterlockStatus->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InterlockStatus.HeartbeatCommandedState=Incoming_m1m3_logevent_InterlockStatus->heartbeatCommandedState;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InterlockStatus.HeartbeatOutputState=Incoming_m1m3_logevent_InterlockStatus->heartbeatOutputState;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InterlockStatus.priority=Incoming_m1m3_logevent_InterlockStatus->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_InterlockStatus = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_InterlockStatus) {
          actorIdx = SAL__MTM1M3_logevent_interlockStatus_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_interlockStatus");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_InterlockStatus = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_InterlockStatus ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InterlockStatus.priority;
           Outgoing_m1m3_logevent_InterlockStatus->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InterlockStatus.Timestamp;
           Outgoing_m1m3_logevent_InterlockStatus->heartbeatCommandedState=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InterlockStatus.HeartbeatCommandedState;
           Outgoing_m1m3_logevent_InterlockStatus->heartbeatOutputState=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InterlockStatus.HeartbeatOutputState;
           Outgoing_m1m3_logevent_InterlockStatus->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InterlockStatus.priority;

          status = mgr[LVClient].logEvent_interlockStatus(Outgoing_m1m3_logevent_InterlockStatus,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_InterlockStatus = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_InterlockWarning) {
          actorIdx = SAL__MTM1M3_logevent_interlockWarning_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_interlockWarning");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_InterlockWarning = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_InterlockWarning == false ) {
           status = mgr[LVClient].getEvent_interlockWarning(Incoming_m1m3_logevent_InterlockWarning);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InterlockWarning.Timestamp=Incoming_m1m3_logevent_InterlockWarning->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InterlockWarning.AnyWarning=Incoming_m1m3_logevent_InterlockWarning->anyWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InterlockWarning.HeartbeatStateOutputMismatch=Incoming_m1m3_logevent_InterlockWarning->heartbeatStateOutputMismatch;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InterlockWarning.AuxPowerNetworksOff=Incoming_m1m3_logevent_InterlockWarning->auxPowerNetworksOff;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InterlockWarning.ThermalEquipmentOff=Incoming_m1m3_logevent_InterlockWarning->thermalEquipmentOff;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InterlockWarning.AirSupplyOff=Incoming_m1m3_logevent_InterlockWarning->airSupplyOff;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InterlockWarning.TMAMotionStop=Incoming_m1m3_logevent_InterlockWarning->tmaMotionStop;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InterlockWarning.GISHeartbeatLost=Incoming_m1m3_logevent_InterlockWarning->gisHeartbeatLost;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InterlockWarning.CabinetDoorOpen=Incoming_m1m3_logevent_InterlockWarning->cabinetDoorOpen;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_InterlockWarning.priority=Incoming_m1m3_logevent_InterlockWarning->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_InterlockWarning = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_InterlockWarning) {
          actorIdx = SAL__MTM1M3_logevent_interlockWarning_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_interlockWarning");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_InterlockWarning = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_InterlockWarning ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InterlockWarning.priority;
           Outgoing_m1m3_logevent_InterlockWarning->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InterlockWarning.Timestamp;
           Outgoing_m1m3_logevent_InterlockWarning->anyWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InterlockWarning.AnyWarning;
           Outgoing_m1m3_logevent_InterlockWarning->heartbeatStateOutputMismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InterlockWarning.HeartbeatStateOutputMismatch;
           Outgoing_m1m3_logevent_InterlockWarning->auxPowerNetworksOff=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InterlockWarning.AuxPowerNetworksOff;
           Outgoing_m1m3_logevent_InterlockWarning->thermalEquipmentOff=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InterlockWarning.ThermalEquipmentOff;
           Outgoing_m1m3_logevent_InterlockWarning->airSupplyOff=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InterlockWarning.AirSupplyOff;
           Outgoing_m1m3_logevent_InterlockWarning->tmaMotionStop=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InterlockWarning.TMAMotionStop;
           Outgoing_m1m3_logevent_InterlockWarning->gisHeartbeatLost=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InterlockWarning.GISHeartbeatLost;
           Outgoing_m1m3_logevent_InterlockWarning->cabinetDoorOpen=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InterlockWarning.CabinetDoorOpen;
           Outgoing_m1m3_logevent_InterlockWarning->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_InterlockWarning.priority;

          status = mgr[LVClient].logEvent_interlockWarning(Outgoing_m1m3_logevent_InterlockWarning,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_InterlockWarning = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_PIDInfo) {
          actorIdx = SAL__MTM1M3_logevent_pidInfo_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_pidInfo");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_PIDInfo = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_PIDInfo == false ) {
           status = mgr[LVClient].getEvent_pidInfo(Incoming_m1m3_logevent_PIDInfo);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PIDInfo.Timestamp=Incoming_m1m3_logevent_PIDInfo->timestamp;
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PIDInfo.Timestep[i]=Incoming_m1m3_logevent_PIDInfo->timestep[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PIDInfo.P[i]=Incoming_m1m3_logevent_PIDInfo->p[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PIDInfo.I[i]=Incoming_m1m3_logevent_PIDInfo->i[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PIDInfo.D[i]=Incoming_m1m3_logevent_PIDInfo->d[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PIDInfo.N[i]=Incoming_m1m3_logevent_PIDInfo->n[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PIDInfo.CalculatedA[i]=Incoming_m1m3_logevent_PIDInfo->calculatedA[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PIDInfo.CalculatedB[i]=Incoming_m1m3_logevent_PIDInfo->calculatedB[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PIDInfo.CalculatedC[i]=Incoming_m1m3_logevent_PIDInfo->calculatedC[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PIDInfo.CalculatedD[i]=Incoming_m1m3_logevent_PIDInfo->calculatedD[i];}
    for (int i=0;i<6;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PIDInfo.CalculatedE[i]=Incoming_m1m3_logevent_PIDInfo->calculatedE[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PIDInfo.priority=Incoming_m1m3_logevent_PIDInfo->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_PIDInfo = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_PIDInfo) {
          actorIdx = SAL__MTM1M3_logevent_pidInfo_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_pidInfo");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_PIDInfo = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_PIDInfo ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PIDInfo.priority;
           Outgoing_m1m3_logevent_PIDInfo->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PIDInfo.Timestamp;
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_PIDInfo->timestep[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PIDInfo.Timestep[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_PIDInfo->p[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PIDInfo.P[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_PIDInfo->i[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PIDInfo.I[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_PIDInfo->d[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PIDInfo.D[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_PIDInfo->n[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PIDInfo.N[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_PIDInfo->calculatedA[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PIDInfo.CalculatedA[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_PIDInfo->calculatedB[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PIDInfo.CalculatedB[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_PIDInfo->calculatedC[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PIDInfo.CalculatedC[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_PIDInfo->calculatedD[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PIDInfo.CalculatedD[i];}
    for (int i=0;i<6;i++) {Outgoing_m1m3_logevent_PIDInfo->calculatedE[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PIDInfo.CalculatedE[i];}
           Outgoing_m1m3_logevent_PIDInfo->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PIDInfo.priority;

          status = mgr[LVClient].logEvent_pidInfo(Outgoing_m1m3_logevent_PIDInfo,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_PIDInfo = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_PowerStatus) {
          actorIdx = SAL__MTM1M3_logevent_powerStatus_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_powerStatus");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_PowerStatus = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_PowerStatus == false ) {
           status = mgr[LVClient].getEvent_powerStatus(Incoming_m1m3_logevent_PowerStatus);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerStatus.Timestamp=Incoming_m1m3_logevent_PowerStatus->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerStatus.PowerNetworkACommandedOn=Incoming_m1m3_logevent_PowerStatus->powerNetworkACommandedOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerStatus.PowerNetworkAOutputOn=Incoming_m1m3_logevent_PowerStatus->powerNetworkAOutputOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerStatus.PowerNetworkBCommandedOn=Incoming_m1m3_logevent_PowerStatus->powerNetworkBCommandedOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerStatus.PowerNetworkBOutputOn=Incoming_m1m3_logevent_PowerStatus->powerNetworkBOutputOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerStatus.PowerNetworkCCommandedOn=Incoming_m1m3_logevent_PowerStatus->powerNetworkCCommandedOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerStatus.PowerNetworkCOutputOn=Incoming_m1m3_logevent_PowerStatus->powerNetworkCOutputOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerStatus.PowerNetworkDCommandedOn=Incoming_m1m3_logevent_PowerStatus->powerNetworkDCommandedOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerStatus.PowerNetworkDOutputOn=Incoming_m1m3_logevent_PowerStatus->powerNetworkDOutputOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerStatus.AuxPowerNetworkACommandedOn=Incoming_m1m3_logevent_PowerStatus->auxPowerNetworkACommandedOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerStatus.AuxPowerNetworkAOutputOn=Incoming_m1m3_logevent_PowerStatus->auxPowerNetworkAOutputOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerStatus.AuxPowerNetworkBCommandedOn=Incoming_m1m3_logevent_PowerStatus->auxPowerNetworkBCommandedOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerStatus.AuxPowerNetworkBOutputOn=Incoming_m1m3_logevent_PowerStatus->auxPowerNetworkBOutputOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerStatus.AuxPowerNetworkCCommandedOn=Incoming_m1m3_logevent_PowerStatus->auxPowerNetworkCCommandedOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerStatus.AuxPowerNetworkCOutputOn=Incoming_m1m3_logevent_PowerStatus->auxPowerNetworkCOutputOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerStatus.AuxPowerNetworkDCommandedOn=Incoming_m1m3_logevent_PowerStatus->auxPowerNetworkDCommandedOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerStatus.AuxPowerNetworkDOutputOn=Incoming_m1m3_logevent_PowerStatus->auxPowerNetworkDOutputOn;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerStatus.priority=Incoming_m1m3_logevent_PowerStatus->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_PowerStatus = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_PowerStatus) {
          actorIdx = SAL__MTM1M3_logevent_powerStatus_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_powerStatus");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_PowerStatus = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_PowerStatus ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerStatus.priority;
           Outgoing_m1m3_logevent_PowerStatus->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerStatus.Timestamp;
           Outgoing_m1m3_logevent_PowerStatus->powerNetworkACommandedOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerStatus.PowerNetworkACommandedOn;
           Outgoing_m1m3_logevent_PowerStatus->powerNetworkAOutputOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerStatus.PowerNetworkAOutputOn;
           Outgoing_m1m3_logevent_PowerStatus->powerNetworkBCommandedOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerStatus.PowerNetworkBCommandedOn;
           Outgoing_m1m3_logevent_PowerStatus->powerNetworkBOutputOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerStatus.PowerNetworkBOutputOn;
           Outgoing_m1m3_logevent_PowerStatus->powerNetworkCCommandedOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerStatus.PowerNetworkCCommandedOn;
           Outgoing_m1m3_logevent_PowerStatus->powerNetworkCOutputOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerStatus.PowerNetworkCOutputOn;
           Outgoing_m1m3_logevent_PowerStatus->powerNetworkDCommandedOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerStatus.PowerNetworkDCommandedOn;
           Outgoing_m1m3_logevent_PowerStatus->powerNetworkDOutputOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerStatus.PowerNetworkDOutputOn;
           Outgoing_m1m3_logevent_PowerStatus->auxPowerNetworkACommandedOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerStatus.AuxPowerNetworkACommandedOn;
           Outgoing_m1m3_logevent_PowerStatus->auxPowerNetworkAOutputOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerStatus.AuxPowerNetworkAOutputOn;
           Outgoing_m1m3_logevent_PowerStatus->auxPowerNetworkBCommandedOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerStatus.AuxPowerNetworkBCommandedOn;
           Outgoing_m1m3_logevent_PowerStatus->auxPowerNetworkBOutputOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerStatus.AuxPowerNetworkBOutputOn;
           Outgoing_m1m3_logevent_PowerStatus->auxPowerNetworkCCommandedOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerStatus.AuxPowerNetworkCCommandedOn;
           Outgoing_m1m3_logevent_PowerStatus->auxPowerNetworkCOutputOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerStatus.AuxPowerNetworkCOutputOn;
           Outgoing_m1m3_logevent_PowerStatus->auxPowerNetworkDCommandedOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerStatus.AuxPowerNetworkDCommandedOn;
           Outgoing_m1m3_logevent_PowerStatus->auxPowerNetworkDOutputOn=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerStatus.AuxPowerNetworkDOutputOn;
           Outgoing_m1m3_logevent_PowerStatus->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerStatus.priority;

          status = mgr[LVClient].logEvent_powerStatus(Outgoing_m1m3_logevent_PowerStatus,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_PowerStatus = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_PowerSupplyStatus) {
          actorIdx = SAL__MTM1M3_logevent_powerSupplyStatus_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_powerSupplyStatus");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_PowerSupplyStatus = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_PowerSupplyStatus == false ) {
           status = mgr[LVClient].getEvent_powerSupplyStatus(Incoming_m1m3_logevent_PowerSupplyStatus);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.Timestamp=Incoming_m1m3_logevent_PowerSupplyStatus->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.RCPMirrorCellUtility220VAC1Status=Incoming_m1m3_logevent_PowerSupplyStatus->rcpMirrorCellUtility220VAC1Status;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.RCPCabinetUtility220VACStatus=Incoming_m1m3_logevent_PowerSupplyStatus->rcpCabinetUtility220VACStatus;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.RCPExternalEquipment220VACStatus=Incoming_m1m3_logevent_PowerSupplyStatus->rcpExternalEquipment220VACStatus;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.RCPMirrorCellUtility220VAC2Status=Incoming_m1m3_logevent_PowerSupplyStatus->rcpMirrorCellUtility220VAC2Status;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.RCPMirrorCellUtility220VAC3Status=Incoming_m1m3_logevent_PowerSupplyStatus->rcpMirrorCellUtility220VAC3Status;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.PowerNetworkARedundancyControlStatus=Incoming_m1m3_logevent_PowerSupplyStatus->powerNetworkARedundancyControlStatus;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.PowerNetworkBRedundancyControlStatus=Incoming_m1m3_logevent_PowerSupplyStatus->powerNetworkBRedundancyControlStatus;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.PowerNetworkCRedundancyControlStatus=Incoming_m1m3_logevent_PowerSupplyStatus->powerNetworkCRedundancyControlStatus;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.PowerNetworkDRedundancyControlStatus=Incoming_m1m3_logevent_PowerSupplyStatus->powerNetworkDRedundancyControlStatus;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.ControlsPowerNetworkRedundancyControlStatus=Incoming_m1m3_logevent_PowerSupplyStatus->controlsPowerNetworkRedundancyControlStatus;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.PowerNetworkAStatus=Incoming_m1m3_logevent_PowerSupplyStatus->powerNetworkAStatus;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.PowerNetworkARedundantStatus=Incoming_m1m3_logevent_PowerSupplyStatus->powerNetworkARedundantStatus;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.PowerNetworkBStatus=Incoming_m1m3_logevent_PowerSupplyStatus->powerNetworkBStatus;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.PowerNetworkBRedundantStatus=Incoming_m1m3_logevent_PowerSupplyStatus->powerNetworkBRedundantStatus;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.PowerNetworkCStatus=Incoming_m1m3_logevent_PowerSupplyStatus->powerNetworkCStatus;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.PowerNetworkCRedundantStatus=Incoming_m1m3_logevent_PowerSupplyStatus->powerNetworkCRedundantStatus;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.PowerNetworkDStatus=Incoming_m1m3_logevent_PowerSupplyStatus->powerNetworkDStatus;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.PowerNetworkDRedundantStatus=Incoming_m1m3_logevent_PowerSupplyStatus->powerNetworkDRedundantStatus;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.ControlsPowerNetworkStatus=Incoming_m1m3_logevent_PowerSupplyStatus->controlsPowerNetworkStatus;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.ControlsPowerNetworkRedundantStatus=Incoming_m1m3_logevent_PowerSupplyStatus->controlsPowerNetworkRedundantStatus;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.LightPowerNetworkStatus=Incoming_m1m3_logevent_PowerSupplyStatus->lightPowerNetworkStatus;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.ExternalEquipmentPowerNetworkStatus=Incoming_m1m3_logevent_PowerSupplyStatus->externalEquipmentPowerNetworkStatus;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.LaserTrackerPowerNetworkStatus=Incoming_m1m3_logevent_PowerSupplyStatus->laserTrackerPowerNetworkStatus;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerSupplyStatus.priority=Incoming_m1m3_logevent_PowerSupplyStatus->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_PowerSupplyStatus = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_PowerSupplyStatus) {
          actorIdx = SAL__MTM1M3_logevent_powerSupplyStatus_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_powerSupplyStatus");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_PowerSupplyStatus = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_PowerSupplyStatus ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.priority;
           Outgoing_m1m3_logevent_PowerSupplyStatus->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.Timestamp;
           Outgoing_m1m3_logevent_PowerSupplyStatus->rcpMirrorCellUtility220VAC1Status=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.RCPMirrorCellUtility220VAC1Status;
           Outgoing_m1m3_logevent_PowerSupplyStatus->rcpCabinetUtility220VACStatus=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.RCPCabinetUtility220VACStatus;
           Outgoing_m1m3_logevent_PowerSupplyStatus->rcpExternalEquipment220VACStatus=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.RCPExternalEquipment220VACStatus;
           Outgoing_m1m3_logevent_PowerSupplyStatus->rcpMirrorCellUtility220VAC2Status=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.RCPMirrorCellUtility220VAC2Status;
           Outgoing_m1m3_logevent_PowerSupplyStatus->rcpMirrorCellUtility220VAC3Status=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.RCPMirrorCellUtility220VAC3Status;
           Outgoing_m1m3_logevent_PowerSupplyStatus->powerNetworkARedundancyControlStatus=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.PowerNetworkARedundancyControlStatus;
           Outgoing_m1m3_logevent_PowerSupplyStatus->powerNetworkBRedundancyControlStatus=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.PowerNetworkBRedundancyControlStatus;
           Outgoing_m1m3_logevent_PowerSupplyStatus->powerNetworkCRedundancyControlStatus=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.PowerNetworkCRedundancyControlStatus;
           Outgoing_m1m3_logevent_PowerSupplyStatus->powerNetworkDRedundancyControlStatus=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.PowerNetworkDRedundancyControlStatus;
           Outgoing_m1m3_logevent_PowerSupplyStatus->controlsPowerNetworkRedundancyControlStatus=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.ControlsPowerNetworkRedundancyControlStatus;
           Outgoing_m1m3_logevent_PowerSupplyStatus->powerNetworkAStatus=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.PowerNetworkAStatus;
           Outgoing_m1m3_logevent_PowerSupplyStatus->powerNetworkARedundantStatus=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.PowerNetworkARedundantStatus;
           Outgoing_m1m3_logevent_PowerSupplyStatus->powerNetworkBStatus=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.PowerNetworkBStatus;
           Outgoing_m1m3_logevent_PowerSupplyStatus->powerNetworkBRedundantStatus=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.PowerNetworkBRedundantStatus;
           Outgoing_m1m3_logevent_PowerSupplyStatus->powerNetworkCStatus=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.PowerNetworkCStatus;
           Outgoing_m1m3_logevent_PowerSupplyStatus->powerNetworkCRedundantStatus=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.PowerNetworkCRedundantStatus;
           Outgoing_m1m3_logevent_PowerSupplyStatus->powerNetworkDStatus=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.PowerNetworkDStatus;
           Outgoing_m1m3_logevent_PowerSupplyStatus->powerNetworkDRedundantStatus=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.PowerNetworkDRedundantStatus;
           Outgoing_m1m3_logevent_PowerSupplyStatus->controlsPowerNetworkStatus=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.ControlsPowerNetworkStatus;
           Outgoing_m1m3_logevent_PowerSupplyStatus->controlsPowerNetworkRedundantStatus=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.ControlsPowerNetworkRedundantStatus;
           Outgoing_m1m3_logevent_PowerSupplyStatus->lightPowerNetworkStatus=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.LightPowerNetworkStatus;
           Outgoing_m1m3_logevent_PowerSupplyStatus->externalEquipmentPowerNetworkStatus=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.ExternalEquipmentPowerNetworkStatus;
           Outgoing_m1m3_logevent_PowerSupplyStatus->laserTrackerPowerNetworkStatus=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.LaserTrackerPowerNetworkStatus;
           Outgoing_m1m3_logevent_PowerSupplyStatus->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerSupplyStatus.priority;

          status = mgr[LVClient].logEvent_powerSupplyStatus(Outgoing_m1m3_logevent_PowerSupplyStatus,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_PowerSupplyStatus = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_PowerWarning) {
          actorIdx = SAL__MTM1M3_logevent_powerWarning_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_powerWarning");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_PowerWarning = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_PowerWarning == false ) {
           status = mgr[LVClient].getEvent_powerWarning(Incoming_m1m3_logevent_PowerWarning);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerWarning.Timestamp=Incoming_m1m3_logevent_PowerWarning->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerWarning.AnyWarning=Incoming_m1m3_logevent_PowerWarning->anyWarning;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerWarning.PowerNetworkAOutputMismatch=Incoming_m1m3_logevent_PowerWarning->powerNetworkAOutputMismatch;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerWarning.PowerNetworkBOutputMismatch=Incoming_m1m3_logevent_PowerWarning->powerNetworkBOutputMismatch;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerWarning.PowerNetworkCOutputMismatch=Incoming_m1m3_logevent_PowerWarning->powerNetworkCOutputMismatch;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerWarning.PowerNetworkDOutputMismatch=Incoming_m1m3_logevent_PowerWarning->powerNetworkDOutputMismatch;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerWarning.AuxPowerNetworkAOutputMismatch=Incoming_m1m3_logevent_PowerWarning->auxPowerNetworkAOutputMismatch;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerWarning.AuxPowerNetworkBOutputMismatch=Incoming_m1m3_logevent_PowerWarning->auxPowerNetworkBOutputMismatch;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerWarning.AuxPowerNetworkCOutputMismatch=Incoming_m1m3_logevent_PowerWarning->auxPowerNetworkCOutputMismatch;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerWarning.AuxPowerNetworkDOutputMismatch=Incoming_m1m3_logevent_PowerWarning->auxPowerNetworkDOutputMismatch;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_PowerWarning.priority=Incoming_m1m3_logevent_PowerWarning->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_PowerWarning = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_PowerWarning) {
          actorIdx = SAL__MTM1M3_logevent_powerWarning_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_powerWarning");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_PowerWarning = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_PowerWarning ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerWarning.priority;
           Outgoing_m1m3_logevent_PowerWarning->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerWarning.Timestamp;
           Outgoing_m1m3_logevent_PowerWarning->anyWarning=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerWarning.AnyWarning;
           Outgoing_m1m3_logevent_PowerWarning->powerNetworkAOutputMismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerWarning.PowerNetworkAOutputMismatch;
           Outgoing_m1m3_logevent_PowerWarning->powerNetworkBOutputMismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerWarning.PowerNetworkBOutputMismatch;
           Outgoing_m1m3_logevent_PowerWarning->powerNetworkCOutputMismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerWarning.PowerNetworkCOutputMismatch;
           Outgoing_m1m3_logevent_PowerWarning->powerNetworkDOutputMismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerWarning.PowerNetworkDOutputMismatch;
           Outgoing_m1m3_logevent_PowerWarning->auxPowerNetworkAOutputMismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerWarning.AuxPowerNetworkAOutputMismatch;
           Outgoing_m1m3_logevent_PowerWarning->auxPowerNetworkBOutputMismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerWarning.AuxPowerNetworkBOutputMismatch;
           Outgoing_m1m3_logevent_PowerWarning->auxPowerNetworkCOutputMismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerWarning.AuxPowerNetworkCOutputMismatch;
           Outgoing_m1m3_logevent_PowerWarning->auxPowerNetworkDOutputMismatch=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerWarning.AuxPowerNetworkDOutputMismatch;
           Outgoing_m1m3_logevent_PowerWarning->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_PowerWarning.priority;

          status = mgr[LVClient].logEvent_powerWarning(Outgoing_m1m3_logevent_PowerWarning,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_PowerWarning = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_RejectedAberrationForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedAberrationForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_rejectedAberrationForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_RejectedAberrationForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedAberrationForces == false ) {
           status = mgr[LVClient].getEvent_rejectedAberrationForces(Incoming_m1m3_logevent_RejectedAberrationForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAberrationForces.Timestamp=Incoming_m1m3_logevent_RejectedAberrationForces->timestamp;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAberrationForces.ZForces[i]=Incoming_m1m3_logevent_RejectedAberrationForces->zForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAberrationForces.Fz=Incoming_m1m3_logevent_RejectedAberrationForces->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAberrationForces.Mx=Incoming_m1m3_logevent_RejectedAberrationForces->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAberrationForces.My=Incoming_m1m3_logevent_RejectedAberrationForces->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAberrationForces.priority=Incoming_m1m3_logevent_RejectedAberrationForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedAberrationForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_RejectedAberrationForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedAberrationForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_rejectedAberrationForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_RejectedAberrationForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedAberrationForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAberrationForces.priority;
           Outgoing_m1m3_logevent_RejectedAberrationForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAberrationForces.Timestamp;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_RejectedAberrationForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAberrationForces.ZForces[i];}
           Outgoing_m1m3_logevent_RejectedAberrationForces->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAberrationForces.Fz;
           Outgoing_m1m3_logevent_RejectedAberrationForces->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAberrationForces.Mx;
           Outgoing_m1m3_logevent_RejectedAberrationForces->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAberrationForces.My;
           Outgoing_m1m3_logevent_RejectedAberrationForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAberrationForces.priority;

          status = mgr[LVClient].logEvent_rejectedAberrationForces(Outgoing_m1m3_logevent_RejectedAberrationForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedAberrationForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_RejectedAccelerationForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedAccelerationForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_rejectedAccelerationForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_RejectedAccelerationForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedAccelerationForces == false ) {
           status = mgr[LVClient].getEvent_rejectedAccelerationForces(Incoming_m1m3_logevent_RejectedAccelerationForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAccelerationForces.Timestamp=Incoming_m1m3_logevent_RejectedAccelerationForces->timestamp;
    for (int i=0;i<12;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAccelerationForces.XForces[i]=Incoming_m1m3_logevent_RejectedAccelerationForces->xForces[i];}
    for (int i=0;i<100;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAccelerationForces.YForces[i]=Incoming_m1m3_logevent_RejectedAccelerationForces->yForces[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAccelerationForces.ZForces[i]=Incoming_m1m3_logevent_RejectedAccelerationForces->xForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAccelerationForces.Fx=Incoming_m1m3_logevent_RejectedAccelerationForces->fx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAccelerationForces.Fy=Incoming_m1m3_logevent_RejectedAccelerationForces->fy;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAccelerationForces.Fz=Incoming_m1m3_logevent_RejectedAccelerationForces->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAccelerationForces.Mx=Incoming_m1m3_logevent_RejectedAccelerationForces->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAccelerationForces.My=Incoming_m1m3_logevent_RejectedAccelerationForces->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAccelerationForces.Mz=Incoming_m1m3_logevent_RejectedAccelerationForces->mz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAccelerationForces.ForceMagnitude=Incoming_m1m3_logevent_RejectedAccelerationForces->forceMagnitude;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAccelerationForces.priority=Incoming_m1m3_logevent_RejectedAccelerationForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedAccelerationForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_RejectedAccelerationForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedAccelerationForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_rejectedAccelerationForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_RejectedAccelerationForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedAccelerationForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAccelerationForces.priority;
           Outgoing_m1m3_logevent_RejectedAccelerationForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAccelerationForces.Timestamp;
    for (int i=0;i<12;i++) {Outgoing_m1m3_logevent_RejectedAccelerationForces->xForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAccelerationForces.XForces[i];}
    for (int i=0;i<100;i++) {Outgoing_m1m3_logevent_RejectedAccelerationForces->yForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAccelerationForces.YForces[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_RejectedAccelerationForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAccelerationForces.ZForces[i];}
           Outgoing_m1m3_logevent_RejectedAccelerationForces->fx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAccelerationForces.Fx;
           Outgoing_m1m3_logevent_RejectedAccelerationForces->fy=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAccelerationForces.Fy;
           Outgoing_m1m3_logevent_RejectedAccelerationForces->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAccelerationForces.Fz;
           Outgoing_m1m3_logevent_RejectedAccelerationForces->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAccelerationForces.Mx;
           Outgoing_m1m3_logevent_RejectedAccelerationForces->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAccelerationForces.My;
           Outgoing_m1m3_logevent_RejectedAccelerationForces->mz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAccelerationForces.Mz;
           Outgoing_m1m3_logevent_RejectedAccelerationForces->forceMagnitude=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAccelerationForces.ForceMagnitude;
           Outgoing_m1m3_logevent_RejectedAccelerationForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAccelerationForces.priority;

          status = mgr[LVClient].logEvent_rejectedAccelerationForces(Outgoing_m1m3_logevent_RejectedAccelerationForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedAccelerationForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_RejectedActiveOpticForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedActiveOpticForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_rejectedActiveOpticForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_RejectedActiveOpticForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedActiveOpticForces == false ) {
           status = mgr[LVClient].getEvent_rejectedActiveOpticForces(Incoming_m1m3_logevent_RejectedActiveOpticForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedActiveOpticForces.Timestamp=Incoming_m1m3_logevent_RejectedActiveOpticForces->timestamp;
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedActiveOpticForces.ZForces[i]=Incoming_m1m3_logevent_RejectedActiveOpticForces->zForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedActiveOpticForces.Fz=Incoming_m1m3_logevent_RejectedActiveOpticForces->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedActiveOpticForces.Mx=Incoming_m1m3_logevent_RejectedActiveOpticForces->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedActiveOpticForces.My=Incoming_m1m3_logevent_RejectedActiveOpticForces->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedActiveOpticForces.priority=Incoming_m1m3_logevent_RejectedActiveOpticForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedActiveOpticForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_RejectedActiveOpticForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedActiveOpticForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_rejectedActiveOpticForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_RejectedActiveOpticForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedActiveOpticForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedActiveOpticForces.priority;
           Outgoing_m1m3_logevent_RejectedActiveOpticForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedActiveOpticForces.Timestamp;
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_RejectedActiveOpticForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedActiveOpticForces.ZForces[i];}
           Outgoing_m1m3_logevent_RejectedActiveOpticForces->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedActiveOpticForces.Fz;
           Outgoing_m1m3_logevent_RejectedActiveOpticForces->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedActiveOpticForces.Mx;
           Outgoing_m1m3_logevent_RejectedActiveOpticForces->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedActiveOpticForces.My;
           Outgoing_m1m3_logevent_RejectedActiveOpticForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedActiveOpticForces.priority;

          status = mgr[LVClient].logEvent_rejectedActiveOpticForces(Outgoing_m1m3_logevent_RejectedActiveOpticForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedActiveOpticForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_RejectedAzimuthForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedAzimuthForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_rejectedAzimuthForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_RejectedAzimuthForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedAzimuthForces == false ) {
           status = mgr[LVClient].getEvent_rejectedAzimuthForces(Incoming_m1m3_logevent_RejectedAzimuthForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAzimuthForces.Timestamp=Incoming_m1m3_logevent_RejectedAzimuthForces->timestamp;
    for (int i=0;i<12;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAzimuthForces.XForces[i]=Incoming_m1m3_logevent_RejectedAzimuthForces->xForces[i];}
    for (int i=0;i<100;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAzimuthForces.YForces[i]=Incoming_m1m3_logevent_RejectedAzimuthForces->yForces[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAzimuthForces.ZForces[i]=Incoming_m1m3_logevent_RejectedAzimuthForces->zForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAzimuthForces.Fx=Incoming_m1m3_logevent_RejectedAzimuthForces->fx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAzimuthForces.Fy=Incoming_m1m3_logevent_RejectedAzimuthForces->fy;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAzimuthForces.Fz=Incoming_m1m3_logevent_RejectedAzimuthForces->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAzimuthForces.Mx=Incoming_m1m3_logevent_RejectedAzimuthForces->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAzimuthForces.My=Incoming_m1m3_logevent_RejectedAzimuthForces->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAzimuthForces.Mz=Incoming_m1m3_logevent_RejectedAzimuthForces->mz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAzimuthForces.ForceMagnitude=Incoming_m1m3_logevent_RejectedAzimuthForces->forceMagnitude;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedAzimuthForces.priority=Incoming_m1m3_logevent_RejectedAzimuthForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedAzimuthForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_RejectedAzimuthForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedAzimuthForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_rejectedAzimuthForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_RejectedAzimuthForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedAzimuthForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAzimuthForces.priority;
           Outgoing_m1m3_logevent_RejectedAzimuthForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAzimuthForces.Timestamp;
    for (int i=0;i<12;i++) {Outgoing_m1m3_logevent_RejectedAzimuthForces->xForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAzimuthForces.XForces[i];}
    for (int i=0;i<100;i++) {Outgoing_m1m3_logevent_RejectedAzimuthForces->yForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAzimuthForces.YForces[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_RejectedAzimuthForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAzimuthForces.ZForces[i];}
           Outgoing_m1m3_logevent_RejectedAzimuthForces->fx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAzimuthForces.Fx;
           Outgoing_m1m3_logevent_RejectedAzimuthForces->fy=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAzimuthForces.Fy;
           Outgoing_m1m3_logevent_RejectedAzimuthForces->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAzimuthForces.Fz;
           Outgoing_m1m3_logevent_RejectedAzimuthForces->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAzimuthForces.Mx;
           Outgoing_m1m3_logevent_RejectedAzimuthForces->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAzimuthForces.My;
           Outgoing_m1m3_logevent_RejectedAzimuthForces->mz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAzimuthForces.Mz;
           Outgoing_m1m3_logevent_RejectedAzimuthForces->forceMagnitude=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAzimuthForces.ForceMagnitude;
           Outgoing_m1m3_logevent_RejectedAzimuthForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedAzimuthForces.priority;

          status = mgr[LVClient].logEvent_rejectedAzimuthForces(Outgoing_m1m3_logevent_RejectedAzimuthForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedAzimuthForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_RejectedBalanceForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedBalanceForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_rejectedBalanceForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_RejectedBalanceForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedBalanceForces == false ) {
           status = mgr[LVClient].getEvent_rejectedBalanceForces(Incoming_m1m3_logevent_RejectedBalanceForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedBalanceForces.Timestamp=Incoming_m1m3_logevent_RejectedBalanceForces->timestamp;
    for (int i=0;i<12;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedBalanceForces.XForces[i]=Incoming_m1m3_logevent_RejectedBalanceForces->xForces[i];}
    for (int i=0;i<100;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedBalanceForces.YForces[i]=Incoming_m1m3_logevent_RejectedBalanceForces->yForces[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedBalanceForces.ZForces[i]=Incoming_m1m3_logevent_RejectedBalanceForces->zForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedBalanceForces.Fx=Incoming_m1m3_logevent_RejectedBalanceForces->fx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedBalanceForces.Fy=Incoming_m1m3_logevent_RejectedBalanceForces->fy;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedBalanceForces.Fz=Incoming_m1m3_logevent_RejectedBalanceForces->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedBalanceForces.Mx=Incoming_m1m3_logevent_RejectedBalanceForces->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedBalanceForces.My=Incoming_m1m3_logevent_RejectedBalanceForces->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedBalanceForces.Mz=Incoming_m1m3_logevent_RejectedBalanceForces->mz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedBalanceForces.ForceMagnitude=Incoming_m1m3_logevent_RejectedBalanceForces->forceMagnitude;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedBalanceForces.priority=Incoming_m1m3_logevent_RejectedBalanceForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedBalanceForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_RejectedBalanceForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedBalanceForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_rejectedBalanceForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_RejectedBalanceForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedBalanceForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedBalanceForces.priority;
           Outgoing_m1m3_logevent_RejectedBalanceForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedBalanceForces.Timestamp;
    for (int i=0;i<12;i++) {Outgoing_m1m3_logevent_RejectedBalanceForces->xForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedBalanceForces.XForces[i];}
    for (int i=0;i<100;i++) {Outgoing_m1m3_logevent_RejectedBalanceForces->yForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedBalanceForces.YForces[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_RejectedBalanceForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedBalanceForces.ZForces[i];}
           Outgoing_m1m3_logevent_RejectedBalanceForces->fx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedBalanceForces.Fx;
           Outgoing_m1m3_logevent_RejectedBalanceForces->fy=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedBalanceForces.Fy;
           Outgoing_m1m3_logevent_RejectedBalanceForces->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedBalanceForces.Fz;
           Outgoing_m1m3_logevent_RejectedBalanceForces->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedBalanceForces.Mx;
           Outgoing_m1m3_logevent_RejectedBalanceForces->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedBalanceForces.My;
           Outgoing_m1m3_logevent_RejectedBalanceForces->mz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedBalanceForces.Mz;
           Outgoing_m1m3_logevent_RejectedBalanceForces->forceMagnitude=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedBalanceForces.ForceMagnitude;
           Outgoing_m1m3_logevent_RejectedBalanceForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedBalanceForces.priority;

          status = mgr[LVClient].logEvent_rejectedBalanceForces(Outgoing_m1m3_logevent_RejectedBalanceForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedBalanceForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_RejectedCylinderForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedCylinderForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_rejectedCylinderForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_RejectedCylinderForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedCylinderForces == false ) {
           status = mgr[LVClient].getEvent_rejectedCylinderForces(Incoming_m1m3_logevent_RejectedCylinderForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedCylinderForces.Timestamp=Incoming_m1m3_logevent_RejectedCylinderForces->timestamp;
    for (int i=0;i<112;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedCylinderForces.SecondaryCylinderForces[i]=Incoming_m1m3_logevent_RejectedCylinderForces->secondaryCylinderForces[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedCylinderForces.PrimaryCylinderForces[i]=Incoming_m1m3_logevent_RejectedCylinderForces->primaryCylinderForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedCylinderForces.priority=Incoming_m1m3_logevent_RejectedCylinderForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedCylinderForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_RejectedCylinderForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedCylinderForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_rejectedCylinderForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_RejectedCylinderForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedCylinderForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedCylinderForces.priority;
           Outgoing_m1m3_logevent_RejectedCylinderForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedCylinderForces.Timestamp;
    for (int i=0;i<112;i++) {Outgoing_m1m3_logevent_RejectedCylinderForces->secondaryCylinderForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedCylinderForces.SecondaryCylinderForces[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_RejectedCylinderForces->primaryCylinderForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedCylinderForces.PrimaryCylinderForces[i];}
           Outgoing_m1m3_logevent_RejectedCylinderForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedCylinderForces.priority;

          status = mgr[LVClient].logEvent_rejectedCylinderForces(Outgoing_m1m3_logevent_RejectedCylinderForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedCylinderForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_RejectedElevationForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedElevationForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_rejectedElevationForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_RejectedElevationForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedElevationForces == false ) {
           status = mgr[LVClient].getEvent_rejectedElevationForces(Incoming_m1m3_logevent_RejectedElevationForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedElevationForces.Timestamp=Incoming_m1m3_logevent_RejectedElevationForces->timestamp;
    for (int i=0;i<12;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedElevationForces.XForces[i]=Incoming_m1m3_logevent_RejectedElevationForces->xForces[i];}
    for (int i=0;i<100;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedElevationForces.YForces[i]=Incoming_m1m3_logevent_RejectedElevationForces->yForces[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedElevationForces.ZForces[i]=Incoming_m1m3_logevent_RejectedElevationForces->zForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedElevationForces.Fx=Incoming_m1m3_logevent_RejectedElevationForces->fx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedElevationForces.Fy=Incoming_m1m3_logevent_RejectedElevationForces->fy;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedElevationForces.Fz=Incoming_m1m3_logevent_RejectedElevationForces->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedElevationForces.Mx=Incoming_m1m3_logevent_RejectedElevationForces->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedElevationForces.My=Incoming_m1m3_logevent_RejectedElevationForces->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedElevationForces.Mz=Incoming_m1m3_logevent_RejectedElevationForces->mz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedElevationForces.ForceMagnitude=Incoming_m1m3_logevent_RejectedElevationForces->forceMagnitude;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedElevationForces.priority=Incoming_m1m3_logevent_RejectedElevationForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedElevationForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_RejectedElevationForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedElevationForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_rejectedElevationForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_RejectedElevationForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedElevationForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedElevationForces.priority;
           Outgoing_m1m3_logevent_RejectedElevationForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedElevationForces.Timestamp;
    for (int i=0;i<12;i++) {Outgoing_m1m3_logevent_RejectedElevationForces->xForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedElevationForces.XForces[i];}
    for (int i=0;i<100;i++) {Outgoing_m1m3_logevent_RejectedElevationForces->yForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedElevationForces.YForces[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_RejectedElevationForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedElevationForces.ZForces[i];}
           Outgoing_m1m3_logevent_RejectedElevationForces->fx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedElevationForces.Fx;
           Outgoing_m1m3_logevent_RejectedElevationForces->fy=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedElevationForces.Fy;
           Outgoing_m1m3_logevent_RejectedElevationForces->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedElevationForces.Fz;
           Outgoing_m1m3_logevent_RejectedElevationForces->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedElevationForces.Mx;
           Outgoing_m1m3_logevent_RejectedElevationForces->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedElevationForces.My;
           Outgoing_m1m3_logevent_RejectedElevationForces->mz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedElevationForces.Mz;
           Outgoing_m1m3_logevent_RejectedElevationForces->forceMagnitude=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedElevationForces.ForceMagnitude;
           Outgoing_m1m3_logevent_RejectedElevationForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedElevationForces.priority;

          status = mgr[LVClient].logEvent_rejectedElevationForces(Outgoing_m1m3_logevent_RejectedElevationForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedElevationForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_RejectedForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_rejectedForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_RejectedForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedForces == false ) {
           status = mgr[LVClient].getEvent_rejectedForces(Incoming_m1m3_logevent_RejectedForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedForces.Timestamp=Incoming_m1m3_logevent_RejectedForces->timestamp;
    for (int i=0;i<12;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedForces.XForces[i]=Incoming_m1m3_logevent_RejectedForces->xForces[i];}
    for (int i=0;i<100;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedForces.YForces[i]=Incoming_m1m3_logevent_RejectedForces->yForces[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedForces.ZForces[i]=Incoming_m1m3_logevent_RejectedForces->zForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedForces.Fx=Incoming_m1m3_logevent_RejectedForces->fx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedForces.Fy=Incoming_m1m3_logevent_RejectedForces->fy;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedForces.Fz=Incoming_m1m3_logevent_RejectedForces->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedForces.Mx=Incoming_m1m3_logevent_RejectedForces->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedForces.My=Incoming_m1m3_logevent_RejectedForces->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedForces.Mz=Incoming_m1m3_logevent_RejectedForces->mz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedForces.ForceMagnitude=Incoming_m1m3_logevent_RejectedForces->forceMagnitude;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedForces.priority=Incoming_m1m3_logevent_RejectedForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_RejectedForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_rejectedForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_RejectedForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedForces.priority;
           Outgoing_m1m3_logevent_RejectedForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedForces.Timestamp;
    for (int i=0;i<12;i++) {Outgoing_m1m3_logevent_RejectedForces->xForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedForces.XForces[i];}
    for (int i=0;i<100;i++) {Outgoing_m1m3_logevent_RejectedForces->yForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedForces.YForces[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_RejectedForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedForces.ZForces[i];}
           Outgoing_m1m3_logevent_RejectedForces->fx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedForces.Fx;
           Outgoing_m1m3_logevent_RejectedForces->fy=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedForces.Fy;
           Outgoing_m1m3_logevent_RejectedForces->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedForces.Fz;
           Outgoing_m1m3_logevent_RejectedForces->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedForces.Mx;
           Outgoing_m1m3_logevent_RejectedForces->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedForces.My;
           Outgoing_m1m3_logevent_RejectedForces->mz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedForces.Mz;
           Outgoing_m1m3_logevent_RejectedForces->forceMagnitude=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedForces.ForceMagnitude;
           Outgoing_m1m3_logevent_RejectedForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedForces.priority;

          status = mgr[LVClient].logEvent_rejectedForces(Outgoing_m1m3_logevent_RejectedForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_RejectedOffsetForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedOffsetForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_rejectedOffsetForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_RejectedOffsetForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedOffsetForces == false ) {
           status = mgr[LVClient].getEvent_rejectedOffsetForces(Incoming_m1m3_logevent_RejectedOffsetForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedOffsetForces.Timestamp=Incoming_m1m3_logevent_RejectedOffsetForces->timestamp;
    for (int i=0;i<12;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedOffsetForces.XForces[i]=Incoming_m1m3_logevent_RejectedOffsetForces->xForces[i];}
    for (int i=0;i<100;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedOffsetForces.YForces[i]=Incoming_m1m3_logevent_RejectedOffsetForces->yForces[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedOffsetForces.ZForces[i]=Incoming_m1m3_logevent_RejectedOffsetForces->zForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedOffsetForces.Fx=Incoming_m1m3_logevent_RejectedOffsetForces->fx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedOffsetForces.Fy=Incoming_m1m3_logevent_RejectedOffsetForces->fy;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedOffsetForces.Fz=Incoming_m1m3_logevent_RejectedOffsetForces->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedOffsetForces.Mx=Incoming_m1m3_logevent_RejectedOffsetForces->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedOffsetForces.My=Incoming_m1m3_logevent_RejectedOffsetForces->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedOffsetForces.Mz=Incoming_m1m3_logevent_RejectedOffsetForces->mz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedOffsetForces.ForceMagnitude=Incoming_m1m3_logevent_RejectedOffsetForces->forceMagnitude;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedOffsetForces.priority=Incoming_m1m3_logevent_RejectedOffsetForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedOffsetForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_RejectedOffsetForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedOffsetForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_rejectedOffsetForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_RejectedOffsetForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedOffsetForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedOffsetForces.priority;
           Outgoing_m1m3_logevent_RejectedOffsetForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedOffsetForces.Timestamp;
    for (int i=0;i<12;i++) {Outgoing_m1m3_logevent_RejectedOffsetForces->xForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedOffsetForces.XForces[i];}
    for (int i=0;i<100;i++) {Outgoing_m1m3_logevent_RejectedOffsetForces->yForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedOffsetForces.YForces[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_RejectedOffsetForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedOffsetForces.ZForces[i];}
           Outgoing_m1m3_logevent_RejectedOffsetForces->fx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedOffsetForces.Fx;
           Outgoing_m1m3_logevent_RejectedOffsetForces->fy=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedOffsetForces.Fy;
           Outgoing_m1m3_logevent_RejectedOffsetForces->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedOffsetForces.Fz;
           Outgoing_m1m3_logevent_RejectedOffsetForces->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedOffsetForces.Mx;
           Outgoing_m1m3_logevent_RejectedOffsetForces->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedOffsetForces.My;
           Outgoing_m1m3_logevent_RejectedOffsetForces->mz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedOffsetForces.Mz;
           Outgoing_m1m3_logevent_RejectedOffsetForces->forceMagnitude=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedOffsetForces.ForceMagnitude;
           Outgoing_m1m3_logevent_RejectedOffsetForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedOffsetForces.priority;

          status = mgr[LVClient].logEvent_rejectedOffsetForces(Outgoing_m1m3_logevent_RejectedOffsetForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedOffsetForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_RejectedStaticForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedStaticForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_rejectedStaticForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_RejectedStaticForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedStaticForces == false ) {
           status = mgr[LVClient].getEvent_rejectedStaticForces(Incoming_m1m3_logevent_RejectedStaticForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedStaticForces.Timestamp=Incoming_m1m3_logevent_RejectedStaticForces->timestamp;
    for (int i=0;i<12;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedStaticForces.XForces[i]=Incoming_m1m3_logevent_RejectedStaticForces->xForces[i];}
    for (int i=0;i<100;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedStaticForces.YForces[i]=Incoming_m1m3_logevent_RejectedStaticForces->yForces[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedStaticForces.ZForces[i]=Incoming_m1m3_logevent_RejectedStaticForces->zForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedStaticForces.Fx=Incoming_m1m3_logevent_RejectedStaticForces->fx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedStaticForces.Fy=Incoming_m1m3_logevent_RejectedStaticForces->fy;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedStaticForces.Fz=Incoming_m1m3_logevent_RejectedStaticForces->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedStaticForces.Mx=Incoming_m1m3_logevent_RejectedStaticForces->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedStaticForces.My=Incoming_m1m3_logevent_RejectedStaticForces->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedStaticForces.Mz=Incoming_m1m3_logevent_RejectedStaticForces->mz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedStaticForces.ForceMagnitude=Incoming_m1m3_logevent_RejectedStaticForces->forceMagnitude;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedStaticForces.priority=Incoming_m1m3_logevent_RejectedStaticForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedStaticForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_RejectedStaticForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedStaticForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_rejectedStaticForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_RejectedStaticForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedStaticForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedStaticForces.priority;
           Outgoing_m1m3_logevent_RejectedStaticForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedStaticForces.Timestamp;
    for (int i=0;i<12;i++) {Outgoing_m1m3_logevent_RejectedStaticForces->xForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedStaticForces.XForces[i];}
    for (int i=0;i<100;i++) {Outgoing_m1m3_logevent_RejectedStaticForces->yForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedStaticForces.YForces[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_RejectedStaticForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedStaticForces.ZForces[i];}
           Outgoing_m1m3_logevent_RejectedStaticForces->fx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedStaticForces.Fx;
           Outgoing_m1m3_logevent_RejectedStaticForces->fy=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedStaticForces.Fy;
           Outgoing_m1m3_logevent_RejectedStaticForces->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedStaticForces.Fz;
           Outgoing_m1m3_logevent_RejectedStaticForces->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedStaticForces.Mx;
           Outgoing_m1m3_logevent_RejectedStaticForces->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedStaticForces.My;
           Outgoing_m1m3_logevent_RejectedStaticForces->mz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedStaticForces.Mz;
           Outgoing_m1m3_logevent_RejectedStaticForces->forceMagnitude=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedStaticForces.ForceMagnitude;
           Outgoing_m1m3_logevent_RejectedStaticForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedStaticForces.priority;

          status = mgr[LVClient].logEvent_rejectedStaticForces(Outgoing_m1m3_logevent_RejectedStaticForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedStaticForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_RejectedThermalForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedThermalForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_rejectedThermalForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_RejectedThermalForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedThermalForces == false ) {
           status = mgr[LVClient].getEvent_rejectedThermalForces(Incoming_m1m3_logevent_RejectedThermalForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedThermalForces.Timestamp=Incoming_m1m3_logevent_RejectedThermalForces->timestamp;
    for (int i=0;i<12;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedThermalForces.XForces[i]=Incoming_m1m3_logevent_RejectedThermalForces->xForces[i];}
    for (int i=0;i<100;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedThermalForces.YForces[i]=Incoming_m1m3_logevent_RejectedThermalForces->yForces[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedThermalForces.ZForces[i]=Incoming_m1m3_logevent_RejectedThermalForces->zForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedThermalForces.Fx=Incoming_m1m3_logevent_RejectedThermalForces->fx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedThermalForces.Fy=Incoming_m1m3_logevent_RejectedThermalForces->fy;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedThermalForces.Fz=Incoming_m1m3_logevent_RejectedThermalForces->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedThermalForces.Mx=Incoming_m1m3_logevent_RejectedThermalForces->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedThermalForces.My=Incoming_m1m3_logevent_RejectedThermalForces->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedThermalForces.Mz=Incoming_m1m3_logevent_RejectedThermalForces->mz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedThermalForces.ForceMagnitude=Incoming_m1m3_logevent_RejectedThermalForces->forceMagnitude;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedThermalForces.priority=Incoming_m1m3_logevent_RejectedThermalForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedThermalForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_RejectedThermalForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedThermalForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_rejectedThermalForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_RejectedThermalForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedThermalForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedThermalForces.priority;
           Outgoing_m1m3_logevent_RejectedThermalForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedThermalForces.Timestamp;
    for (int i=0;i<12;i++) {Outgoing_m1m3_logevent_RejectedThermalForces->xForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedThermalForces.XForces[i];}
    for (int i=0;i<100;i++) {Outgoing_m1m3_logevent_RejectedThermalForces->yForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedThermalForces.YForces[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_RejectedThermalForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedThermalForces.ZForces[i];}
           Outgoing_m1m3_logevent_RejectedThermalForces->fx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedThermalForces.Fx;
           Outgoing_m1m3_logevent_RejectedThermalForces->fy=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedThermalForces.Fy;
           Outgoing_m1m3_logevent_RejectedThermalForces->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedThermalForces.Fz;
           Outgoing_m1m3_logevent_RejectedThermalForces->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedThermalForces.Mx;
           Outgoing_m1m3_logevent_RejectedThermalForces->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedThermalForces.My;
           Outgoing_m1m3_logevent_RejectedThermalForces->mz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedThermalForces.Mz;
           Outgoing_m1m3_logevent_RejectedThermalForces->forceMagnitude=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedThermalForces.ForceMagnitude;
           Outgoing_m1m3_logevent_RejectedThermalForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedThermalForces.priority;

          status = mgr[LVClient].logEvent_rejectedThermalForces(Outgoing_m1m3_logevent_RejectedThermalForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedThermalForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_RejectedVelocityForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedVelocityForces_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_rejectedVelocityForces");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_RejectedVelocityForces = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedVelocityForces == false ) {
           status = mgr[LVClient].getEvent_rejectedVelocityForces(Incoming_m1m3_logevent_RejectedVelocityForces);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedVelocityForces.Timestamp=Incoming_m1m3_logevent_RejectedVelocityForces->timestamp;
    for (int i=0;i<12;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedVelocityForces.XForces[i]=Incoming_m1m3_logevent_RejectedVelocityForces->xForces[i];}
    for (int i=0;i<100;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedVelocityForces.YForces[i]=Incoming_m1m3_logevent_RejectedVelocityForces->yForces[i];}
    for (int i=0;i<156;i++) {m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedVelocityForces.ZForces[i]=Incoming_m1m3_logevent_RejectedVelocityForces->zForces[i];}
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedVelocityForces.Fx=Incoming_m1m3_logevent_RejectedVelocityForces->fx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedVelocityForces.Fy=Incoming_m1m3_logevent_RejectedVelocityForces->fy;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedVelocityForces.Fz=Incoming_m1m3_logevent_RejectedVelocityForces->fz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedVelocityForces.Mx=Incoming_m1m3_logevent_RejectedVelocityForces->mx;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedVelocityForces.My=Incoming_m1m3_logevent_RejectedVelocityForces->my;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedVelocityForces.Mz=Incoming_m1m3_logevent_RejectedVelocityForces->mz;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedVelocityForces.ForceMagnitude=Incoming_m1m3_logevent_RejectedVelocityForces->forceMagnitude;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_RejectedVelocityForces.priority=Incoming_m1m3_logevent_RejectedVelocityForces->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_RejectedVelocityForces = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_RejectedVelocityForces) {
          actorIdx = SAL__MTM1M3_logevent_rejectedVelocityForces_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_rejectedVelocityForces");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_RejectedVelocityForces = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedVelocityForces ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedVelocityForces.priority;
           Outgoing_m1m3_logevent_RejectedVelocityForces->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedVelocityForces.Timestamp;
    for (int i=0;i<12;i++) {Outgoing_m1m3_logevent_RejectedVelocityForces->xForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedVelocityForces.XForces[i];}
    for (int i=0;i<100;i++) {Outgoing_m1m3_logevent_RejectedVelocityForces->yForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedVelocityForces.YForces[i];}
    for (int i=0;i<156;i++) {Outgoing_m1m3_logevent_RejectedVelocityForces->zForces[i]=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedVelocityForces.ZForces[i];}
           Outgoing_m1m3_logevent_RejectedVelocityForces->fx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedVelocityForces.Fx;
           Outgoing_m1m3_logevent_RejectedVelocityForces->fy=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedVelocityForces.Fy;
           Outgoing_m1m3_logevent_RejectedVelocityForces->fz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedVelocityForces.Fz;
           Outgoing_m1m3_logevent_RejectedVelocityForces->mx=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedVelocityForces.Mx;
           Outgoing_m1m3_logevent_RejectedVelocityForces->my=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedVelocityForces.My;
           Outgoing_m1m3_logevent_RejectedVelocityForces->mz=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedVelocityForces.Mz;
           Outgoing_m1m3_logevent_RejectedVelocityForces->forceMagnitude=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedVelocityForces.ForceMagnitude;
           Outgoing_m1m3_logevent_RejectedVelocityForces->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_RejectedVelocityForces.priority;

          status = mgr[LVClient].logEvent_rejectedVelocityForces(Outgoing_m1m3_logevent_RejectedVelocityForces,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_RejectedVelocityForces = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_SettingVersions) {
          actorIdx = SAL__MTM1M3_logevent_settingVersions_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_settingVersions");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_SettingVersions = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_SettingVersions == false ) {
           status = mgr[LVClient].getEvent_settingVersions(Incoming_m1m3_logevent_SettingVersions);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_SettingVersions.Timestamp=Incoming_m1m3_logevent_SettingVersions->timestamp;
             strcpy(m1m3_memIO->client[LVClient].m1m3_logevent_SettingVersionsLV_RecommendedSettingsVersion_bufferIn,Incoming_m1m3_logevent_SettingVersions->recommendedSettingsVersion.c_str());
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_SettingVersions.priority=Incoming_m1m3_logevent_SettingVersions->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_SettingVersions = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_SettingVersions) {
          actorIdx = SAL__MTM1M3_logevent_settingVersions_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_settingVersions");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_SettingVersions = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_SettingVersions ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_SettingVersions.priority;
           Outgoing_m1m3_logevent_SettingVersions->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_SettingVersions.Timestamp;
             Outgoing_m1m3_logevent_SettingVersions->recommendedSettingsVersion=m1m3_memIO->client[LVClient].m1m3_logevent_SettingVersionsLV_RecommendedSettingsVersion_bufferOut;
           Outgoing_m1m3_logevent_SettingVersions->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_SettingVersions.priority;

          status = mgr[LVClient].logEvent_settingVersions(Outgoing_m1m3_logevent_SettingVersions,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_SettingVersions = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_SettingsApplied) {
          actorIdx = SAL__MTM1M3_logevent_settingsApplied_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_settingsApplied");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_SettingsApplied = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_SettingsApplied == false ) {
           status = mgr[LVClient].getEvent_settingsApplied(Incoming_m1m3_logevent_SettingsApplied);
           if (status == SAL__OK) {
//           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_SettingsApplied.Timestamp=Incoming_m1m3_logevent_SettingsApplied->timestamp;
             strcpy(m1m3_memIO->client[LVClient].m1m3_logevent_SettingsAppliedLV_Settings_bufferIn,Incoming_m1m3_logevent_SettingsApplied->settingsVersion.c_str());
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_SettingsApplied.priority=Incoming_m1m3_logevent_SettingsApplied->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_SettingsApplied = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_SettingsApplied) {
          actorIdx = SAL__MTM1M3_logevent_settingsApplied_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_settingsApplied");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_SettingsApplied = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_SettingsApplied ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_SettingsApplied.priority;
//           Outgoing_m1m3_logevent_SettingsApplied->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_SettingsApplied.Timestamp;
             Outgoing_m1m3_logevent_SettingsApplied->settingsVersion=m1m3_memIO->client[LVClient].m1m3_logevent_SettingsAppliedLV_Settings_bufferOut;
           Outgoing_m1m3_logevent_SettingsApplied->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_SettingsApplied.priority;

          status = mgr[LVClient].logEvent_settingsApplied(Outgoing_m1m3_logevent_SettingsApplied,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_SettingsApplied = false;
       }


       if (m1m3_memIO->client[LVClient].syncI_m1m3_logevent_SummaryState) {
          actorIdx = SAL__MTM1M3_logevent_summaryState_ACTOR;
          if (mgr[LVClient].actorEventReader(actorIdx) == false) {
             mgr[LVClient].salEventSub("MTM1M3_logevent_summaryState");
             m1m3_memIO->client[LVClient].hasReader_m1m3_logevent_SummaryState = true;
          }
          if ( m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_SummaryState == false ) {
           status = mgr[LVClient].getEvent_summaryState(Incoming_m1m3_logevent_SummaryState);
           if (status == SAL__OK) {
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_SummaryState.Timestamp=Incoming_m1m3_logevent_SummaryState->timestamp;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_SummaryState.SummaryState=Incoming_m1m3_logevent_SummaryState->summaryState;
           m1m3_memIO->client[LVClient].shmemIncoming_m1m3_logevent_SummaryState.priority=Incoming_m1m3_logevent_SummaryState->priority;

             m1m3_memIO->client[LVClient].hasIncoming_m1m3_logevent_SummaryState = true;
           }
          }
       }
       if (m1m3_memIO->client[LVClient].syncO_m1m3_logevent_SummaryState) {
          actorIdx = SAL__MTM1M3_logevent_summaryState_ACTOR;
          if (mgr[LVClient].actorEventWriter(actorIdx) == false) {
             mgr[LVClient].salEventPub("MTM1M3_logevent_summaryState");
             m1m3_memIO->client[LVClient].hasWriter_m1m3_logevent_SummaryState = true;
          }
       }
       if ( m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_SummaryState ) {
          lpriority = m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_SummaryState.priority;
           Outgoing_m1m3_logevent_SummaryState->timestamp=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_SummaryState.Timestamp;
           Outgoing_m1m3_logevent_SummaryState->summaryState=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_SummaryState.SummaryState;
           Outgoing_m1m3_logevent_SummaryState->priority=m1m3_memIO->client[LVClient].shmemOutgoing_m1m3_logevent_SummaryState.priority;

          status = mgr[LVClient].logEvent_summaryState(Outgoing_m1m3_logevent_SummaryState,lpriority);
          m1m3_memIO->client[LVClient].hasOutgoing_m1m3_logevent_SummaryState = false;
       }


        if (m1m3_memIO->client[LVClient].shutdown) {
            mgr[LVClient].salShutdown();
            m1m3_memIO->client[LVClient].inUse = false;
            m1m3_memIO->client[LVClient].initialized = false;
            m1m3_memIO->client[LVClient].shutdown = false;
        }
       }
      }
      usleep(ipollusecs);
      }
      shmdt(m1m3_memIO);
      exit(0);
    }

