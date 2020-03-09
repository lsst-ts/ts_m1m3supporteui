
#ifndef _SAL_m1m3C_
#define _SAL_m1m3C_

#include <string>

using namespace std;

struct m1m3_AccelerometerDataC
{
  double Timestamp;
   float RawAccelerometer[8];
   float Accelerometer[8];
  float AngularAccelerationX;
  float AngularAccelerationY;
  float AngularAccelerationZ;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_AccelerometerDataC()  { std::cout << "m1m3_AccelerometerDataC()"  << std::endl; }
  ~m1m3_AccelerometerDataC() { std::cout << "~m1m3_AccelerometerDataC()"  << std::endl; }
#endif
};

struct m1m3_ForceActuatorDataC
{
  double Timestamp;
   float PrimaryCylinderForce[156];
   float SecondaryCylinderForce[112];
   float XForce[12];
   float YForce[100];
   float ZForce[156];
  float Fx;
  float Fy;
  float Fz;
  float Mx;
  float My;
  float Mz;
  float ForceMagnitude;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_ForceActuatorDataC()  { std::cout << "m1m3_ForceActuatorDataC()"  << std::endl; }
  ~m1m3_ForceActuatorDataC() { std::cout << "~m1m3_ForceActuatorDataC()"  << std::endl; }
#endif
};

struct m1m3_GyroDataC
{
  double Timestamp;
  float AngularVelocityX;
  float AngularVelocityY;
  float AngularVelocityZ;
  short SequenceNumber;
  short Temperature;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_GyroDataC()  { std::cout << "m1m3_GyroDataC()"  << std::endl; }
  ~m1m3_GyroDataC() { std::cout << "~m1m3_GyroDataC()"  << std::endl; }
#endif
};

struct m1m3_HardpointActuatorDataC
{
  double Timestamp;
   int StepsQueued[6];
   short StepsCommanded[6];
   float MeasuredForce[6];
   int Encoder[6];
   float Displacement[6];
  float Fx;
  float Fy;
  float Fz;
  float Mx;
  float My;
  float Mz;
  float ForceMagnitude;
  float XPosition;
  float YPosition;
  float ZPosition;
  float XRotation;
  float YRotation;
  float ZRotation;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_HardpointActuatorDataC()  { std::cout << "m1m3_HardpointActuatorDataC()"  << std::endl; }
  ~m1m3_HardpointActuatorDataC() { std::cout << "~m1m3_HardpointActuatorDataC()"  << std::endl; }
#endif
};

struct m1m3_HardpointMonitorDataC
{
  double Timestamp;
   float BreakawayLVDT[6];
   float DisplacementLVDT[6];
   float BreakawayPressure[6];
   float PressureSensor1[6];
   float PressureSensor2[6];
   float PressureSensor3[6];

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_HardpointMonitorDataC()  { std::cout << "m1m3_HardpointMonitorDataC()"  << std::endl; }
  ~m1m3_HardpointMonitorDataC() { std::cout << "~m1m3_HardpointMonitorDataC()"  << std::endl; }
#endif
};

struct m1m3_IMSDataC
{
  double Timestamp;
   float RawSensorData[8];
  float XPosition;
  float YPosition;
  float ZPosition;
  float XRotation;
  float YRotation;
  float ZRotation;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_IMSDataC()  { std::cout << "m1m3_IMSDataC()"  << std::endl; }
  ~m1m3_IMSDataC() { std::cout << "~m1m3_IMSDataC()"  << std::endl; }
#endif
};

struct m1m3_InclinometerDataC
{
  double Timestamp;
  float InclinometerAngle;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_InclinometerDataC()  { std::cout << "m1m3_InclinometerDataC()"  << std::endl; }
  ~m1m3_InclinometerDataC() { std::cout << "~m1m3_InclinometerDataC()"  << std::endl; }
#endif
};

struct m1m3_OuterLoopDataC
{
  double Timestamp;
  short BroadcastCounter;
  int SlewFlag;
  double ExecutionTime;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_OuterLoopDataC()  { std::cout << "m1m3_OuterLoopDataC()"  << std::endl; }
  ~m1m3_OuterLoopDataC() { std::cout << "~m1m3_OuterLoopDataC()"  << std::endl; }
#endif
};

struct m1m3_PIDDataC
{
  double Timestamp;
   double Setpoint[6];
   double Measurement[6];
   double Error[6];
   double ErrorT1[6];
   double ErrorT2[6];
   double Control[6];
   double ControlT1[6];
   double ControlT2[6];

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_PIDDataC()  { std::cout << "m1m3_PIDDataC()"  << std::endl; }
  ~m1m3_PIDDataC() { std::cout << "~m1m3_PIDDataC()"  << std::endl; }
#endif
};

struct m1m3_PowerSupplyDataC
{
  double Timestamp;
  float PowerNetworkACurrent;
  float PowerNetworkBCurrent;
  float PowerNetworkCCurrent;
  float PowerNetworkDCurrent;
  float LightPowerNetworkCurrent;
  float ControlsPowerNetworkCurrent;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_PowerSupplyDataC()  { std::cout << "m1m3_PowerSupplyDataC()"  << std::endl; }
  ~m1m3_PowerSupplyDataC() { std::cout << "~m1m3_PowerSupplyDataC()"  << std::endl; }
#endif
};

struct m1m3_command_AbortProfileC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int AbortProfile;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_AbortProfileC()  { std::cout << "m1m3_command_AbortProfileC()"  << std::endl; }
  ~m1m3_command_AbortProfileC() { std::cout << "~m1m3_command_AbortProfileC()"  << std::endl; }
#endif
};

struct m1m3_command_AbortRaiseM1M3C
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int AbortRaiseM1M3;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_AbortRaiseM1M3C()  { std::cout << "m1m3_command_AbortRaiseM1M3C()"  << std::endl; }
  ~m1m3_command_AbortRaiseM1M3C() { std::cout << "~m1m3_command_AbortRaiseM1M3C()"  << std::endl; }
#endif
};

struct m1m3_command_ApplyAberrationForcesC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
   float ZForces[156];

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_ApplyAberrationForcesC()  { std::cout << "m1m3_command_ApplyAberrationForcesC()"  << std::endl; }
  ~m1m3_command_ApplyAberrationForcesC() { std::cout << "~m1m3_command_ApplyAberrationForcesC()"  << std::endl; }
#endif
};

struct m1m3_command_ApplyAberrationForcesByBendingModesC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
   float Coefficients[22];

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_ApplyAberrationForcesByBendingModesC()  { std::cout << "m1m3_command_ApplyAberrationForcesByBendingModesC()"  << std::endl; }
  ~m1m3_command_ApplyAberrationForcesByBendingModesC() { std::cout << "~m1m3_command_ApplyAberrationForcesByBendingModesC()"  << std::endl; }
#endif
};

struct m1m3_command_ApplyActiveOpticForcesC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
   float ZForces[156];

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_ApplyActiveOpticForcesC()  { std::cout << "m1m3_command_ApplyActiveOpticForcesC()"  << std::endl; }
  ~m1m3_command_ApplyActiveOpticForcesC() { std::cout << "~m1m3_command_ApplyActiveOpticForcesC()"  << std::endl; }
#endif
};

struct m1m3_command_ApplyActiveOpticForcesByBendingModesC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
   float Coefficients[22];

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_ApplyActiveOpticForcesByBendingModesC()  { std::cout << "m1m3_command_ApplyActiveOpticForcesByBendingModesC()"  << std::endl; }
  ~m1m3_command_ApplyActiveOpticForcesByBendingModesC() { std::cout << "~m1m3_command_ApplyActiveOpticForcesByBendingModesC()"  << std::endl; }
#endif
};

struct m1m3_command_ApplyOffsetForcesC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
   float XForces[12];
   float YForces[100];
   float ZForces[156];

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_ApplyOffsetForcesC()  { std::cout << "m1m3_command_ApplyOffsetForcesC()"  << std::endl; }
  ~m1m3_command_ApplyOffsetForcesC() { std::cout << "~m1m3_command_ApplyOffsetForcesC()"  << std::endl; }
#endif
};

struct m1m3_command_ApplyOffsetForcesByMirrorForceC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  float XForce;
  float YForce;
  float ZForce;
  float XMoment;
  float YMoment;
  float ZMoment;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_ApplyOffsetForcesByMirrorForceC()  { std::cout << "m1m3_command_ApplyOffsetForcesByMirrorForceC()"  << std::endl; }
  ~m1m3_command_ApplyOffsetForcesByMirrorForceC() { std::cout << "~m1m3_command_ApplyOffsetForcesByMirrorForceC()"  << std::endl; }
#endif
};

struct m1m3_command_ClearAberrationForcesC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int ClearAberrationForces;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_ClearAberrationForcesC()  { std::cout << "m1m3_command_ClearAberrationForcesC()"  << std::endl; }
  ~m1m3_command_ClearAberrationForcesC() { std::cout << "~m1m3_command_ClearAberrationForcesC()"  << std::endl; }
#endif
};

struct m1m3_command_ClearActiveOpticForcesC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int ClearActiveOpticForces;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_ClearActiveOpticForcesC()  { std::cout << "m1m3_command_ClearActiveOpticForcesC()"  << std::endl; }
  ~m1m3_command_ClearActiveOpticForcesC() { std::cout << "~m1m3_command_ClearActiveOpticForcesC()"  << std::endl; }
#endif
};

struct m1m3_command_ClearOffsetForcesC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int ClearOffsetForces;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_ClearOffsetForcesC()  { std::cout << "m1m3_command_ClearOffsetForcesC()"  << std::endl; }
  ~m1m3_command_ClearOffsetForcesC() { std::cout << "~m1m3_command_ClearOffsetForcesC()"  << std::endl; }
#endif
};

struct m1m3_command_DisableC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int Disable;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_DisableC()  { std::cout << "m1m3_command_DisableC()"  << std::endl; }
  ~m1m3_command_DisableC() { std::cout << "~m1m3_command_DisableC()"  << std::endl; }
#endif
};

struct m1m3_command_DisableHardpointChaseC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  short HardpointActuator;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_DisableHardpointChaseC()  { std::cout << "m1m3_command_DisableHardpointChaseC()"  << std::endl; }
  ~m1m3_command_DisableHardpointChaseC() { std::cout << "~m1m3_command_DisableHardpointChaseC()"  << std::endl; }
#endif
};

struct m1m3_command_DisableHardpointCorrectionsC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int DisableHardpointCorrections;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_DisableHardpointCorrectionsC()  { std::cout << "m1m3_command_DisableHardpointCorrectionsC()"  << std::endl; }
  ~m1m3_command_DisableHardpointCorrectionsC() { std::cout << "~m1m3_command_DisableHardpointCorrectionsC()"  << std::endl; }
#endif
};

struct m1m3_command_EnableC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int Enable;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_EnableC()  { std::cout << "m1m3_command_EnableC()"  << std::endl; }
  ~m1m3_command_EnableC() { std::cout << "~m1m3_command_EnableC()"  << std::endl; }
#endif
};

struct m1m3_command_EnableHardpointChaseC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  short HardpointActuator;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_EnableHardpointChaseC()  { std::cout << "m1m3_command_EnableHardpointChaseC()"  << std::endl; }
  ~m1m3_command_EnableHardpointChaseC() { std::cout << "~m1m3_command_EnableHardpointChaseC()"  << std::endl; }
#endif
};

struct m1m3_command_EnableHardpointCorrectionsC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int EnableHardpointCorrections;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_EnableHardpointCorrectionsC()  { std::cout << "m1m3_command_EnableHardpointCorrectionsC()"  << std::endl; }
  ~m1m3_command_EnableHardpointCorrectionsC() { std::cout << "~m1m3_command_EnableHardpointCorrectionsC()"  << std::endl; }
#endif
};

struct m1m3_command_EnterEngineeringC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int EnterEngineering;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_EnterEngineeringC()  { std::cout << "m1m3_command_EnterEngineeringC()"  << std::endl; }
  ~m1m3_command_EnterEngineeringC() { std::cout << "~m1m3_command_EnterEngineeringC()"  << std::endl; }
#endif
};

struct m1m3_command_ExitEngineeringC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int ExitEngineering;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_ExitEngineeringC()  { std::cout << "m1m3_command_ExitEngineeringC()"  << std::endl; }
  ~m1m3_command_ExitEngineeringC() { std::cout << "~m1m3_command_ExitEngineeringC()"  << std::endl; }
#endif
};

struct m1m3_command_LowerM1M3C
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int LowerM1M3;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_LowerM1M3C()  { std::cout << "m1m3_command_LowerM1M3C()"  << std::endl; }
  ~m1m3_command_LowerM1M3C() { std::cout << "~m1m3_command_LowerM1M3C()"  << std::endl; }
#endif
};

struct m1m3_command_ModbusTransmitC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int ActuatorId;
  short FunctionCode;
   short Data[252];
  short DataLength;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_ModbusTransmitC()  { std::cout << "m1m3_command_ModbusTransmitC()"  << std::endl; }
  ~m1m3_command_ModbusTransmitC() { std::cout << "~m1m3_command_ModbusTransmitC()"  << std::endl; }
#endif
};

struct m1m3_command_MoveHardpointActuatorsC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
   int Steps[6];

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_MoveHardpointActuatorsC()  { std::cout << "m1m3_command_MoveHardpointActuatorsC()"  << std::endl; }
  ~m1m3_command_MoveHardpointActuatorsC() { std::cout << "~m1m3_command_MoveHardpointActuatorsC()"  << std::endl; }
#endif
};

struct m1m3_command_PositionM1M3C
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  float XPosition;
  float YPosition;
  float ZPosition;
  float XRotation;
  float YRotation;
  float ZRotation;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_PositionM1M3C()  { std::cout << "m1m3_command_PositionM1M3C()"  << std::endl; }
  ~m1m3_command_PositionM1M3C() { std::cout << "~m1m3_command_PositionM1M3C()"  << std::endl; }
#endif
};

struct m1m3_command_ProgramILCC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int ActuatorId;
  std::string	FilePath;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_ProgramILCC()  { std::cout << "m1m3_command_ProgramILCC()"  << std::endl; }
  ~m1m3_command_ProgramILCC() { std::cout << "~m1m3_command_ProgramILCC()"  << std::endl; }
#endif
};

struct m1m3_command_RaiseM1M3C
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int RaiseM1M3;
  int BypassReferencePosition;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_RaiseM1M3C()  { std::cout << "m1m3_command_RaiseM1M3C()"  << std::endl; }
  ~m1m3_command_RaiseM1M3C() { std::cout << "~m1m3_command_RaiseM1M3C()"  << std::endl; }
#endif
};

struct m1m3_command_ResetPIDC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  short PID;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_ResetPIDC()  { std::cout << "m1m3_command_ResetPIDC()"  << std::endl; }
  ~m1m3_command_ResetPIDC() { std::cout << "~m1m3_command_ResetPIDC()"  << std::endl; }
#endif
};

struct m1m3_command_RunMirrorForceProfileC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
   float XForce[1000];
   float YForce[1000];
   float ZForce[1000];
   float XMoment[1000];
   float YMoment[1000];
   float ZMoment[1000];

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_RunMirrorForceProfileC()  { std::cout << "m1m3_command_RunMirrorForceProfileC()"  << std::endl; }
  ~m1m3_command_RunMirrorForceProfileC() { std::cout << "~m1m3_command_RunMirrorForceProfileC()"  << std::endl; }
#endif
};

struct m1m3_command_SetThermalSetpointC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  float Setpoint;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_SetThermalSetpointC()  { std::cout << "m1m3_command_SetThermalSetpointC()"  << std::endl; }
  ~m1m3_command_SetThermalSetpointC() { std::cout << "~m1m3_command_SetThermalSetpointC()"  << std::endl; }
#endif
};

struct m1m3_command_ShutdownC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int Shutdown;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_ShutdownC()  { std::cout << "m1m3_command_ShutdownC()"  << std::endl; }
  ~m1m3_command_ShutdownC() { std::cout << "~m1m3_command_ShutdownC()"  << std::endl; }
#endif
};

struct m1m3_command_StandbyC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int Standby;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_StandbyC()  { std::cout << "m1m3_command_StandbyC()"  << std::endl; }
  ~m1m3_command_StandbyC() { std::cout << "~m1m3_command_StandbyC()"  << std::endl; }
#endif
};

struct m1m3_command_StartC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int Start;
  std::string	SettingsToApply;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_StartC()  { std::cout << "m1m3_command_StartC()"  << std::endl; }
  ~m1m3_command_StartC() { std::cout << "~m1m3_command_StartC()"  << std::endl; }
#endif
};

struct m1m3_command_StopHardpointMotionC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int StopHardpointMotion;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_StopHardpointMotionC()  { std::cout << "m1m3_command_StopHardpointMotionC()"  << std::endl; }
  ~m1m3_command_StopHardpointMotionC() { std::cout << "~m1m3_command_StopHardpointMotionC()"  << std::endl; }
#endif
};

struct m1m3_command_TestAirC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int TestAir;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_TestAirC()  { std::cout << "m1m3_command_TestAirC()"  << std::endl; }
  ~m1m3_command_TestAirC() { std::cout << "~m1m3_command_TestAirC()"  << std::endl; }
#endif
};

struct m1m3_command_TestForceActuatorC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  short ForceActuator;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_TestForceActuatorC()  { std::cout << "m1m3_command_TestForceActuatorC()"  << std::endl; }
  ~m1m3_command_TestForceActuatorC() { std::cout << "~m1m3_command_TestForceActuatorC()"  << std::endl; }
#endif
};

struct m1m3_command_TestHardpointC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  short HardpointActuator;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_TestHardpointC()  { std::cout << "m1m3_command_TestHardpointC()"  << std::endl; }
  ~m1m3_command_TestHardpointC() { std::cout << "~m1m3_command_TestHardpointC()"  << std::endl; }
#endif
};

struct m1m3_command_TranslateM1M3C
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  float XTranslation;
  float YTranslation;
  float ZTranslation;
  float XRotation;
  float YRotation;
  float ZRotation;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_TranslateM1M3C()  { std::cout << "m1m3_command_TranslateM1M3C()"  << std::endl; }
  ~m1m3_command_TranslateM1M3C() { std::cout << "~m1m3_command_TranslateM1M3C()"  << std::endl; }
#endif
};

struct m1m3_command_TurnAirOffC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int TurnAirOff;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_TurnAirOffC()  { std::cout << "m1m3_command_TurnAirOffC()"  << std::endl; }
  ~m1m3_command_TurnAirOffC() { std::cout << "~m1m3_command_TurnAirOffC()"  << std::endl; }
#endif
};

struct m1m3_command_TurnAirOnC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int TurnAirOn;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_TurnAirOnC()  { std::cout << "m1m3_command_TurnAirOnC()"  << std::endl; }
  ~m1m3_command_TurnAirOnC() { std::cout << "~m1m3_command_TurnAirOnC()"  << std::endl; }
#endif
};

struct m1m3_command_TurnLightsOffC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int TurnLightsOff;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_TurnLightsOffC()  { std::cout << "m1m3_command_TurnLightsOffC()"  << std::endl; }
  ~m1m3_command_TurnLightsOffC() { std::cout << "~m1m3_command_TurnLightsOffC()"  << std::endl; }
#endif
};

struct m1m3_command_TurnLightsOnC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int TurnLightsOn;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_TurnLightsOnC()  { std::cout << "m1m3_command_TurnLightsOnC()"  << std::endl; }
  ~m1m3_command_TurnLightsOnC() { std::cout << "~m1m3_command_TurnLightsOnC()"  << std::endl; }
#endif
};

struct m1m3_command_TurnPowerOffC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int TurnPowerNetworkAOff;
  int TurnPowerNetworkBOff;
  int TurnPowerNetworkCOff;
  int TurnPowerNetworkDOff;
  int TurnAuxPowerNetworkAOff;
  int TurnAuxPowerNetworkBOff;
  int TurnAuxPowerNetworkCOff;
  int TurnAuxPowerNetworkDOff;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_TurnPowerOffC()  { std::cout << "m1m3_command_TurnPowerOffC()"  << std::endl; }
  ~m1m3_command_TurnPowerOffC() { std::cout << "~m1m3_command_TurnPowerOffC()"  << std::endl; }
#endif
};

struct m1m3_command_TurnPowerOnC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  int TurnPowerNetworkAOn;
  int TurnPowerNetworkBOn;
  int TurnPowerNetworkCOn;
  int TurnPowerNetworkDOn;
  int TurnAuxPowerNetworkAOn;
  int TurnAuxPowerNetworkBOn;
  int TurnAuxPowerNetworkCOn;
  int TurnAuxPowerNetworkDOn;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_TurnPowerOnC()  { std::cout << "m1m3_command_TurnPowerOnC()"  << std::endl; }
  ~m1m3_command_TurnPowerOnC() { std::cout << "~m1m3_command_TurnPowerOnC()"  << std::endl; }
#endif
};

struct m1m3_command_UpdatePIDC
{
  std::string	device;
  std::string	property;
  std::string	action;
  std::string	value;
  short PID;
  double Timestep;
  double P;
  double I;
  double D;
  double N;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_command_UpdatePIDC()  { std::cout << "m1m3_command_UpdatePIDC()"  << std::endl; }
  ~m1m3_command_UpdatePIDC() { std::cout << "~m1m3_command_UpdatePIDC()"  << std::endl; }
#endif
};

struct m1m3_logevent_AccelerometerWarningC
{
  double Timestamp;
  int AnyWarning;
  int ResponseTimeout;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_AccelerometerWarningC()  { std::cout << "m1m3_logevent_AccelerometerWarningC()"  << std::endl; }
  ~m1m3_logevent_AccelerometerWarningC() { std::cout << "~m1m3_logevent_AccelerometerWarningC()"  << std::endl; }
#endif
};

struct m1m3_logevent_AirSupplyStatusC
{
  double Timestamp;
  int AirCommandedOn;
  int AirCommandOutputOn;
  int AirValveOpened;
  int AirValveClosed;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_AirSupplyStatusC()  { std::cout << "m1m3_logevent_AirSupplyStatusC()"  << std::endl; }
  ~m1m3_logevent_AirSupplyStatusC() { std::cout << "~m1m3_logevent_AirSupplyStatusC()"  << std::endl; }
#endif
};

struct m1m3_logevent_AirSupplyWarningC
{
  double Timestamp;
  int AnyWarning;
  int CommandOutputMismatch;
  int CommandSensorMismatch;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_AirSupplyWarningC()  { std::cout << "m1m3_logevent_AirSupplyWarningC()"  << std::endl; }
  ~m1m3_logevent_AirSupplyWarningC() { std::cout << "~m1m3_logevent_AirSupplyWarningC()"  << std::endl; }
#endif
};

struct m1m3_logevent_AppliedAberrationForcesC
{
  double Timestamp;
   float ZForces[156];
  float Fz;
  float Mx;
  float My;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_AppliedAberrationForcesC()  { std::cout << "m1m3_logevent_AppliedAberrationForcesC()"  << std::endl; }
  ~m1m3_logevent_AppliedAberrationForcesC() { std::cout << "~m1m3_logevent_AppliedAberrationForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_AppliedAccelerationForcesC
{
  double Timestamp;
   float XForces[12];
   float YForces[100];
   float ZForces[156];
  float Fx;
  float Fy;
  float Fz;
  float Mx;
  float My;
  float Mz;
  float ForceMagnitude;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_AppliedAccelerationForcesC()  { std::cout << "m1m3_logevent_AppliedAccelerationForcesC()"  << std::endl; }
  ~m1m3_logevent_AppliedAccelerationForcesC() { std::cout << "~m1m3_logevent_AppliedAccelerationForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_AppliedActiveOpticForcesC
{
  double Timestamp;
   float ZForces[156];
  float Fz;
  float Mx;
  float My;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_AppliedActiveOpticForcesC()  { std::cout << "m1m3_logevent_AppliedActiveOpticForcesC()"  << std::endl; }
  ~m1m3_logevent_AppliedActiveOpticForcesC() { std::cout << "~m1m3_logevent_AppliedActiveOpticForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_AppliedAzimuthForcesC
{
  double Timestamp;
   float XForces[12];
   float YForces[100];
   float ZForces[156];
  float Fx;
  float Fy;
  float Fz;
  float Mx;
  float My;
  float Mz;
  float ForceMagnitude;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_AppliedAzimuthForcesC()  { std::cout << "m1m3_logevent_AppliedAzimuthForcesC()"  << std::endl; }
  ~m1m3_logevent_AppliedAzimuthForcesC() { std::cout << "~m1m3_logevent_AppliedAzimuthForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_AppliedBalanceForcesC
{
  double Timestamp;
   float XForces[12];
   float YForces[100];
   float ZForces[156];
  float Fx;
  float Fy;
  float Fz;
  float Mx;
  float My;
  float Mz;
  float ForceMagnitude;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_AppliedBalanceForcesC()  { std::cout << "m1m3_logevent_AppliedBalanceForcesC()"  << std::endl; }
  ~m1m3_logevent_AppliedBalanceForcesC() { std::cout << "~m1m3_logevent_AppliedBalanceForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_AppliedCylinderForcesC
{
  double Timestamp;
   int SecondaryCylinderForces[112];
   int PrimaryCylinderForces[156];
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_AppliedCylinderForcesC()  { std::cout << "m1m3_logevent_AppliedCylinderForcesC()"  << std::endl; }
  ~m1m3_logevent_AppliedCylinderForcesC() { std::cout << "~m1m3_logevent_AppliedCylinderForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_AppliedElevationForcesC
{
  double Timestamp;
   float XForces[12];
   float YForces[100];
   float ZForces[156];
  float Fx;
  float Fy;
  float Fz;
  float Mx;
  float My;
  float Mz;
  float ForceMagnitude;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_AppliedElevationForcesC()  { std::cout << "m1m3_logevent_AppliedElevationForcesC()"  << std::endl; }
  ~m1m3_logevent_AppliedElevationForcesC() { std::cout << "~m1m3_logevent_AppliedElevationForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_AppliedForcesC
{
  double Timestamp;
   float XForces[12];
   float YForces[100];
   float ZForces[156];
  float Fx;
  float Fy;
  float Fz;
  float Mx;
  float My;
  float Mz;
  float ForceMagnitude;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_AppliedForcesC()  { std::cout << "m1m3_logevent_AppliedForcesC()"  << std::endl; }
  ~m1m3_logevent_AppliedForcesC() { std::cout << "~m1m3_logevent_AppliedForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_AppliedOffsetForcesC
{
  double Timestamp;
   float XForces[12];
   float YForces[100];
   float ZForces[156];
  float Fx;
  float Fy;
  float Fz;
  float Mx;
  float My;
  float Mz;
  float ForceMagnitude;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_AppliedOffsetForcesC()  { std::cout << "m1m3_logevent_AppliedOffsetForcesC()"  << std::endl; }
  ~m1m3_logevent_AppliedOffsetForcesC() { std::cout << "~m1m3_logevent_AppliedOffsetForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_AppliedSettingsMatchStartC
{
  double Timestamp;
  int AppliedSettingsMatchStart;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_AppliedSettingsMatchStartC()  { std::cout << "m1m3_logevent_AppliedSettingsMatchStartC()"  << std::endl; }
  ~m1m3_logevent_AppliedSettingsMatchStartC() { std::cout << "~m1m3_logevent_AppliedSettingsMatchStartC()"  << std::endl; }
#endif
};

struct m1m3_logevent_AppliedStaticForcesC
{
  double Timestamp;
   float XForces[12];
   float YForces[100];
   float ZForces[156];
  float Fx;
  float Fy;
  float Fz;
  float Mx;
  float My;
  float Mz;
  float ForceMagnitude;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_AppliedStaticForcesC()  { std::cout << "m1m3_logevent_AppliedStaticForcesC()"  << std::endl; }
  ~m1m3_logevent_AppliedStaticForcesC() { std::cout << "~m1m3_logevent_AppliedStaticForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_AppliedThermalForcesC
{
  double Timestamp;
   float XForces[12];
   float YForces[100];
   float ZForces[156];
  float Fx;
  float Fy;
  float Fz;
  float Mx;
  float My;
  float Mz;
  float ForceMagnitude;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_AppliedThermalForcesC()  { std::cout << "m1m3_logevent_AppliedThermalForcesC()"  << std::endl; }
  ~m1m3_logevent_AppliedThermalForcesC() { std::cout << "~m1m3_logevent_AppliedThermalForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_AppliedVelocityForcesC
{
  double Timestamp;
   float XForces[12];
   float YForces[100];
   float ZForces[156];
  float Fx;
  float Fy;
  float Fz;
  float Mx;
  float My;
  float Mz;
  float ForceMagnitude;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_AppliedVelocityForcesC()  { std::cout << "m1m3_logevent_AppliedVelocityForcesC()"  << std::endl; }
  ~m1m3_logevent_AppliedVelocityForcesC() { std::cout << "~m1m3_logevent_AppliedVelocityForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_CellLightStatusC
{
  double Timestamp;
  int CellLightsCommandedOn;
  int CellLightsOutputOn;
  int CellLightsOn;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_CellLightStatusC()  { std::cout << "m1m3_logevent_CellLightStatusC()"  << std::endl; }
  ~m1m3_logevent_CellLightStatusC() { std::cout << "~m1m3_logevent_CellLightStatusC()"  << std::endl; }
#endif
};

struct m1m3_logevent_CellLightWarningC
{
  double Timestamp;
  int AnyWarning;
  int CellLightsOutputMismatch;
  int CellLightsSensorMismatch;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_CellLightWarningC()  { std::cout << "m1m3_logevent_CellLightWarningC()"  << std::endl; }
  ~m1m3_logevent_CellLightWarningC() { std::cout << "~m1m3_logevent_CellLightWarningC()"  << std::endl; }
#endif
};

struct m1m3_logevent_CommandRejectionWarningC
{
  double Timestamp;
  std::string	Command;
  std::string	Reason;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_CommandRejectionWarningC()  { std::cout << "m1m3_logevent_CommandRejectionWarningC()"  << std::endl; }
  ~m1m3_logevent_CommandRejectionWarningC() { std::cout << "~m1m3_logevent_CommandRejectionWarningC()"  << std::endl; }
#endif
};

struct m1m3_logevent_DetailedStateC
{
  double Timestamp;
  int DetailedState;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_DetailedStateC()  { std::cout << "m1m3_logevent_DetailedStateC()"  << std::endl; }
  ~m1m3_logevent_DetailedStateC() { std::cout << "~m1m3_logevent_DetailedStateC()"  << std::endl; }
#endif
};

struct m1m3_logevent_DisplacementSensorWarningC
{
  double Timestamp;
  int AnyWarning;
  int SensorReportsInvalidCommand;
  int SensorReportsCommunicationTimeoutError;
  int SensorReportsDataLengthError;
  int SensorReportsNumberOfParametersError;
  int SensorReportsParameterError;
  int SensorReportsCommunicationError;
  int SensorReportsIDNumberError;
  int SensorReportsExpansionLineError;
  int SensorReportsWriteControlError;
  int ResponseTimeout;
  int InvalidLength;
  int InvalidResponse;
  int UnknownCommand;
  int UnknownProblem;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_DisplacementSensorWarningC()  { std::cout << "m1m3_logevent_DisplacementSensorWarningC()"  << std::endl; }
  ~m1m3_logevent_DisplacementSensorWarningC() { std::cout << "~m1m3_logevent_DisplacementSensorWarningC()"  << std::endl; }
#endif
};

struct m1m3_logevent_ErrorCodeC
{
  double Timestamp;
  int ErrorCode;
  int DetailedErrorCode;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_ErrorCodeC()  { std::cout << "m1m3_logevent_ErrorCodeC()"  << std::endl; }
  ~m1m3_logevent_ErrorCodeC() { std::cout << "~m1m3_logevent_ErrorCodeC()"  << std::endl; }
#endif
};

struct m1m3_logevent_ForceActuatorForceWarningC
{
  double Timestamp;
  int AnyWarning;
  int AnyPrimaryAxisMeasuredForceWarning;
   int PrimaryAxisMeasuredForceWarning[156];
  int AnySecondaryAxisMeasuredForceWarning;
   int SecondaryAxisMeasuredForceWarning[156];
  int AnyPrimaryAxisFollowingErrorWarning;
   int PrimaryAxisFollowingErrorWarning[156];
  int AnySecondaryAxisFollowingErrorWarning;
   int SecondaryAxisFollowingErrorWarning[156];
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_ForceActuatorForceWarningC()  { std::cout << "m1m3_logevent_ForceActuatorForceWarningC()"  << std::endl; }
  ~m1m3_logevent_ForceActuatorForceWarningC() { std::cout << "~m1m3_logevent_ForceActuatorForceWarningC()"  << std::endl; }
#endif
};

struct m1m3_logevent_ForceActuatorInfoC
{
  double Timestamp;
   short ReferenceId[156];
   short XDataReferenceId[12];
   short YDataReferenceId[100];
   short ZDataReferenceId[156];
   short ActuatorType[156];
   short ActuatorOrientation[156];
   short ModbusSubnet[156];
   short ModbusAddress[156];
   float XPosition[156];
   float YPosition[156];
   float ZPosition[156];
   long long ILCUniqueId[156];
   short ILCApplicationType[156];
   short NetworkNodeType[156];
   short ILCSelectedOptions[156];
   short NetworkNodeOptions[156];
   short MajorRevision[156];
   short MinorRevision[156];
   short ADCScanRate[156];
   float MainPrimaryCylinderCoefficient[156];
   float MainSecondaryCylinderCoefficient[156];
   float MainPrimaryCylinderLoadCellOffset[156];
   float MainSecondaryCylinderLoadCellOffset[156];
   float MainPrimaryCylinderLoadCellSensitivity[156];
   float MainSecondaryCylinderLoadCellSensitivity[156];
   float BackupPrimaryCylinderCoefficient[156];
   float BackupSecondaryCylinderCoefficient[156];
   float BackupPrimaryCylinderLoadCellOffset[156];
   float BackupSecondaryCylinderLoadCellOffset[156];
   float BackupPrimaryCylinderLoadCellSensitivity[156];
   float BackupSecondaryCylinderLoadCellSensitivity[156];
   float MezzaninePrimaryCylinderGain[156];
   float MezzanineSecondaryCylinderGain[156];
   long long MezzanineUniqueId[156];
   short MezzanineFirmwareType[156];
   short MezzanineMajorRevision[156];
   short MezzanineMinorRevision[156];
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_ForceActuatorInfoC()  { std::cout << "m1m3_logevent_ForceActuatorInfoC()"  << std::endl; }
  ~m1m3_logevent_ForceActuatorInfoC() { std::cout << "~m1m3_logevent_ForceActuatorInfoC()"  << std::endl; }
#endif
};

struct m1m3_logevent_ForceActuatorStateC
{
  double Timestamp;
   short ILCState[156];
  int SlewFlag;
  int StaticForcesApplied;
  int ElevationForcesApplied;
  int AzimuthForcesApplied;
  int ThermalForcesApplied;
  int OffsetForcesApplied;
  int AccelerationForcesApplied;
  int VelocityForcesApplied;
  int ActiveOpticForcesApplied;
  int AberrationForcesApplied;
  int BalanceForcesApplied;
  float SupportPercentage;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_ForceActuatorStateC()  { std::cout << "m1m3_logevent_ForceActuatorStateC()"  << std::endl; }
  ~m1m3_logevent_ForceActuatorStateC() { std::cout << "~m1m3_logevent_ForceActuatorStateC()"  << std::endl; }
#endif
};

struct m1m3_logevent_ForceActuatorWarningC
{
  double Timestamp;
  int AnyWarning;
  int AnyMajorFault;
   int MajorFault[156];
  int AnyMinorFault;
   int MinorFault[156];
  int AnyFaultOverride;
   int FaultOverride[156];
  int AnyMainCalibrationError;
   int MainCalibrationError[156];
  int AnyBackupCalibrationError;
   int BackupCalibrationError[156];
  int AnyMezzanineError;
   int MezzanineError[156];
  int AnyMezzanineBootloaderActive;
   int MezzanineBootloaderActive[156];
  int AnyUniqueIdCRCError;
   int UniqueIdCRCError[156];
  int AnyApplicationTypeMismatch;
   int ApplicationTypeMismatch[156];
  int AnyApplicationMissing;
   int ApplicationMissing[156];
  int AnyApplicationCRCMismatch;
   int ApplicationCRCMismatch[156];
  int AnyOneWireMissing;
   int OneWireMissing[156];
  int AnyOneWire1Mismatch;
   int OneWire1Mismatch[156];
  int AnyOneWire2Mismatch;
   int OneWire2Mismatch[156];
  int AnyWatchdogReset;
   int WatchdogReset[156];
  int AnyBrownOut;
   int BrownOut[156];
  int AnyEventTrapReset;
   int EventTrapReset[156];
  int AnySSRPowerFault;
   int SSRPowerFault[156];
  int AnyAuxPowerFault;
   int AuxPowerFault[156];
  int AnyMezzaninePowerFault;
   int MezzaninePowerFault[156];
  int AnyMezzanineCurrentAmp1Fault;
   int MezzanineCurrentAmp1Fault[156];
  int AnyMezzanineCurrentAmp2Fault;
   int MezzanineCurrentAmp2Fault[156];
  int AnyMezzanineUniqueIdCRCError;
   int MezzanineUniqueIdCRCError[156];
  int AnyMezzanineMainCalibrationError;
   int MezzanineMainCalibrationError[156];
  int AnyMezzanineBackupCalibrationError;
   int MezzanineBackupCalibrationError[156];
  int AnyMezzanineEventTrapReset;
   int MezzanineEventTrapReset[156];
  int AnyMezzanineApplicationMissing;
   int MezzanineApplicationMissing[156];
  int AnyMezzanineApplicationCRCMismatch;
   int MezzanineApplicationCRCMismatch[156];
  int AnyILCFault;
   int ILCFault[156];
  int AnyBroadcastCounterWarning;
   int BroadcastCounterWarning[156];
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_ForceActuatorWarningC()  { std::cout << "m1m3_logevent_ForceActuatorWarningC()"  << std::endl; }
  ~m1m3_logevent_ForceActuatorWarningC() { std::cout << "~m1m3_logevent_ForceActuatorWarningC()"  << std::endl; }
#endif
};

struct m1m3_logevent_ForceSetpointWarningC
{
  double Timestamp;
  int AnyWarning;
  int AnySafetyLimitWarning;
   int SafetyLimitWarning[156];
  int XMomentWarning;
  int YMomentWarning;
  int ZMomentWarning;
  int AnyNearNeighborWarning;
   int NearNeighborWarning[156];
  int MagnitudeWarning;
  int AnyFarNeighborWarning;
   int FarNeighborWarning[156];
  int AnyElevationForceWarning;
   int ElevationForceWarning[156];
  int AnyAzimuthForceWarning;
   int AzimuthForceWarning[156];
  int AnyThermalForceWarning;
   int ThermalForceWarning[156];
  int AnyBalanceForceWarning;
   int BalanceForceWarning[156];
  int AnyAccelerationForceWarning;
   int AccelerationForceWarning[156];
  int ActiveOpticNetForceWarning;
  int AnyActiveOpticForceWarning;
   int ActiveOpticForceWarning[156];
  int AnyStaticForceWarning;
   int StaticForceWarning[156];
  int AberrationNetForceWarning;
  int AnyAberrationForceWarning;
   int AberrationForceWarning[156];
  int AnyOffsetForceWarning;
   int OffsetForceWarning[156];
  int AnyVelocityForceWarning;
   int VelocityForceWarning[156];
  int AnyForceWarning;
   int ForceWarning[156];
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_ForceSetpointWarningC()  { std::cout << "m1m3_logevent_ForceSetpointWarningC()"  << std::endl; }
  ~m1m3_logevent_ForceSetpointWarningC() { std::cout << "~m1m3_logevent_ForceSetpointWarningC()"  << std::endl; }
#endif
};

struct m1m3_logevent_GyroWarningC
{
  double Timestamp;
  int AnyWarning;
  int GyroXStatusWarning;
  int GyroYStatusWarning;
  int GyroZStatusWarning;
  int SequenceNumberWarning;
  int CRCMismatchWarning;
  int InvalidLengthWarning;
  int InvalidHeaderWarning;
  int IncompleteFrameWarning;
  int GyroXSLDWarning;
  int GyroXMODDACWarning;
  int GyroXPhaseWarning;
  int GyroXFlashWarning;
  int GyroYSLDWarning;
  int GyroYMODDACWarning;
  int GyroYPhaseWarning;
  int GyroYFlashWarning;
  int GyroZSLDWarning;
  int GyroZMODDACWarning;
  int GyroZPhaseWarning;
  int GyroZFlashWarning;
  int GyroXSLDTemperatureStatusWarning;
  int GyroYSLDTemperatureStatusWarning;
  int GyroZSLDTemperatureStatusWarning;
  int GCBTemperatureStatusWarning;
  int TemperatureStatusWarning;
  int GCBDSPSPIFlashStatusWarning;
  int GCBFPGASPIFlashStatusWarning;
  int DSPSPIFlashStatusWarning;
  int FPGASPIFlashStatusWarning;
  int GCB1_2VStatusWarning;
  int GCB3_3VStatusWarning;
  int GCB5VStatusWarning;
  int V1_2StatusWarning;
  int V3_3StatusWarning;
  int V5StatusWarning;
  int GCBFPGAStatusWarning;
  int FPGAStatusWarning;
  int HiSpeedSPORTStatusWarning;
  int AuxSPORTStatusWarning;
  int SufficientSoftwareResourcesWarning;
  int GyroEOVoltsPositiveWarning;
  int GyroEOVoltsNegativeWarning;
  int GyroXVoltsWarning;
  int GyroYVoltsWarning;
  int GyroZVoltsWarning;
  int GCBADCCommsWarning;
  int MSYNCExternalTimingWarning;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_GyroWarningC()  { std::cout << "m1m3_logevent_GyroWarningC()"  << std::endl; }
  ~m1m3_logevent_GyroWarningC() { std::cout << "~m1m3_logevent_GyroWarningC()"  << std::endl; }
#endif
};

struct m1m3_logevent_HardpointActuatorInfoC
{
  double Timestamp;
   short ReferenceId[6];
   int ReferencePosition[6];
   short ModbusSubnet[6];
   short ModbusAddress[6];
   float XPosition[6];
   float YPosition[6];
   float ZPosition[6];
   long long ILCUniqueId[6];
   short ILCApplicationType[6];
   short NetworkNodeType[6];
   short ILCSelectedOptions[6];
   short NetworkNodeOptions[6];
   short MajorRevision[6];
   short MinorRevision[6];
   short ADCScanRate[6];
   float MainLoadCellCoefficient[6];
   float MainLoadCellOffset[6];
   float MainLoadCellSensitivity[6];
   float BackupLoadCellCoefficient[6];
   float BackupLoadCellOffset[6];
   float BackupLoadCellSensitivity[6];
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_HardpointActuatorInfoC()  { std::cout << "m1m3_logevent_HardpointActuatorInfoC()"  << std::endl; }
  ~m1m3_logevent_HardpointActuatorInfoC() { std::cout << "~m1m3_logevent_HardpointActuatorInfoC()"  << std::endl; }
#endif
};

struct m1m3_logevent_HardpointActuatorStateC
{
  double Timestamp;
   short ILCState[6];
   short MotionState[6];
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_HardpointActuatorStateC()  { std::cout << "m1m3_logevent_HardpointActuatorStateC()"  << std::endl; }
  ~m1m3_logevent_HardpointActuatorStateC() { std::cout << "~m1m3_logevent_HardpointActuatorStateC()"  << std::endl; }
#endif
};

struct m1m3_logevent_HardpointActuatorWarningC
{
  double Timestamp;
  int AnyWarning;
  int AnyMajorFault;
   int MajorFault[6];
  int AnyMinorFault;
   int MinorFault[6];
  int AnyFaultOverride;
   int FaultOverride[6];
  int AnyMainCalibrationError;
   int MainCalibrationError[6];
  int AnyBackupCalibrationError;
   int BackupCalibrationError[6];
  int AnyLimitSwitch1Operated;
   int LimitSwitch1Operated[6];
  int AnyLimitSwitch2Operated;
   int LimitSwitch2Operated[6];
  int AnyUniqueIdCRCError;
   int UniqueIdCRCError[6];
  int AnyApplicationTypeMismatch;
   int ApplicationTypeMismatch[6];
  int AnyApplicationMissing;
   int ApplicationMissing[6];
  int AnyApplicationCRCMismatch;
   int ApplicationCRCMismatch[6];
  int AnyOneWireMissing;
   int OneWireMissing[6];
  int AnyOneWire1Mismatch;
   int OneWire1Mismatch[6];
  int AnyOneWire2Mismatch;
   int OneWire2Mismatch[6];
  int AnyWatchdogReset;
   int WatchdogReset[6];
  int AnyBrownOut;
   int BrownOut[6];
  int AnyEventTrapReset;
   int EventTrapReset[6];
  int AnyMotorDriverFault;
   int MotorDriverFault[6];
  int AnySSRPowerFault;
   int SSRPowerFault[6];
  int AnyAuxPowerFault;
   int AuxPowerFault[6];
  int AnySMCPowerFault;
   int SMCPowerFault[6];
  int AnyILCFault;
   int ILCFault[6];
  int AnyBroadcastCounterWarning;
   int BroadcastCounterWarning[6];
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_HardpointActuatorWarningC()  { std::cout << "m1m3_logevent_HardpointActuatorWarningC()"  << std::endl; }
  ~m1m3_logevent_HardpointActuatorWarningC() { std::cout << "~m1m3_logevent_HardpointActuatorWarningC()"  << std::endl; }
#endif
};

struct m1m3_logevent_HardpointMonitorInfoC
{
  double Timestamp;
   short ReferenceId[6];
   short ModbusSubnet[6];
   short ModbusAddress[6];
   long long ILCUniqueId[6];
   short ILCApplicationType[6];
   short NetworkNodeType[6];
   short MajorRevision[6];
   short MinorRevision[6];
   long long MezzanineUniqueId[6];
   short MezzanineFirmwareType[6];
   short MezzanineMajorRevision[6];
   short MezzanineMinorRevision[6];
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_HardpointMonitorInfoC()  { std::cout << "m1m3_logevent_HardpointMonitorInfoC()"  << std::endl; }
  ~m1m3_logevent_HardpointMonitorInfoC() { std::cout << "~m1m3_logevent_HardpointMonitorInfoC()"  << std::endl; }
#endif
};

struct m1m3_logevent_HardpointMonitorStateC
{
  double Timestamp;
   short ILCState[6];
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_HardpointMonitorStateC()  { std::cout << "m1m3_logevent_HardpointMonitorStateC()"  << std::endl; }
  ~m1m3_logevent_HardpointMonitorStateC() { std::cout << "~m1m3_logevent_HardpointMonitorStateC()"  << std::endl; }
#endif
};

struct m1m3_logevent_HardpointMonitorWarningC
{
  double Timestamp;
  int AnyWarning;
  int AnyMajorFault;
   int MajorFault[6];
  int AnyMinorFault;
   int MinorFault[6];
  int AnyFaultOverride;
   int FaultOverride[6];
  int AnyInstrumentError;
   int InstrumentError[6];
  int AnyMezzanineError;
   int MezzanineError[6];
  int AnyMezzanineBootloaderActive;
   int MezzanineBootloaderActive[6];
  int AnyUniqueIdCRCError;
   int UniqueIdCRCError[6];
  int AnyApplicationTypeMismatch;
   int ApplicationTypeMismatch[6];
  int AnyApplicationMissing;
   int ApplicationMissing[6];
  int AnyApplicationCRCMismatch;
   int ApplicationCRCMismatch[6];
  int AnyOneWireMissing;
   int OneWireMissing[6];
  int AnyOneWire1Mismatch;
   int OneWire1Mismatch[6];
  int AnyOneWire2Mismatch;
   int OneWire2Mismatch[6];
  int AnyWatchdogReset;
   int WatchdogReset[6];
  int AnyBrownOut;
   int BrownOut[6];
  int AnyEventTrapReset;
   int EventTrapReset[6];
  int AnySSRPowerFault;
   int SSRPowerFault[6];
  int AnyAuxPowerFault;
   int AuxPowerFault[6];
  int AnyMezzanineS1AInterface1Fault;
   int MezzanineS1AInterface1Fault[6];
  int AnyMezzanineS1ALVDT1Fault;
   int MezzanineS1ALVDT1Fault[6];
  int AnyMezzanineS1AInterface2Fault;
   int MezzanineS1AInterface2Fault[6];
  int AnyMezzanineS1ALVDT2Fault;
   int MezzanineS1ALVDT2Fault[6];
  int AnyMezzanineUniqueIdCRCError;
   int MezzanineUniqueIdCRCError[6];
  int AnyMezzanineEventTrapReset;
   int MezzanineEventTrapReset[6];
  int AnyMezzanineDCPRS422ChipFault;
   int MezzanineDCPRS422ChipFault[6];
  int AnyMezzanineApplicationMissing;
   int MezzanineApplicationMissing[6];
  int AnyMezzanineApplicationCRCMismatch;
   int MezzanineApplicationCRCMismatch[6];
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_HardpointMonitorWarningC()  { std::cout << "m1m3_logevent_HardpointMonitorWarningC()"  << std::endl; }
  ~m1m3_logevent_HardpointMonitorWarningC() { std::cout << "~m1m3_logevent_HardpointMonitorWarningC()"  << std::endl; }
#endif
};

struct m1m3_logevent_ILCWarningC
{
  double Timestamp;
  int ActuatorId;
  int AnyWarning;
  int ResponseTimeout;
  int InvalidCRC;
  int IllegalFunction;
  int IllegalDataValue;
  int InvalidLength;
  int UnknownSubnet;
  int UnknownAddress;
  int UnknownFunction;
  int UnknownProblem;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_ILCWarningC()  { std::cout << "m1m3_logevent_ILCWarningC()"  << std::endl; }
  ~m1m3_logevent_ILCWarningC() { std::cout << "~m1m3_logevent_ILCWarningC()"  << std::endl; }
#endif
};

struct m1m3_logevent_InclinometerSensorWarningC
{
  double Timestamp;
  int AnyWarning;
  int SensorReportsIllegalFunction;
  int SensorReportsIllegalDataAddress;
  int ResponseTimeout;
  int InvalidCRC;
  int InvalidLength;
  int UnknownAddress;
  int UnknownFunction;
  int UnknownProblem;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_InclinometerSensorWarningC()  { std::cout << "m1m3_logevent_InclinometerSensorWarningC()"  << std::endl; }
  ~m1m3_logevent_InclinometerSensorWarningC() { std::cout << "~m1m3_logevent_InclinometerSensorWarningC()"  << std::endl; }
#endif
};

struct m1m3_logevent_InterlockStatusC
{
  double Timestamp;
  int HeartbeatCommandedState;
  int HeartbeatOutputState;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_InterlockStatusC()  { std::cout << "m1m3_logevent_InterlockStatusC()"  << std::endl; }
  ~m1m3_logevent_InterlockStatusC() { std::cout << "~m1m3_logevent_InterlockStatusC()"  << std::endl; }
#endif
};

struct m1m3_logevent_InterlockWarningC
{
  double Timestamp;
  int AnyWarning;
  int HeartbeatStateOutputMismatch;
  int AuxPowerNetworksOff;
  int ThermalEquipmentOff;
  int AirSupplyOff;
  int TMAMotionStop;
  int GISHeartbeatLost;
  int CabinetDoorOpen;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_InterlockWarningC()  { std::cout << "m1m3_logevent_InterlockWarningC()"  << std::endl; }
  ~m1m3_logevent_InterlockWarningC() { std::cout << "~m1m3_logevent_InterlockWarningC()"  << std::endl; }
#endif
};

struct m1m3_logevent_ModbusResponseC
{
  double Timestamp;
  int ResponseValid;
  short Address;
  short FunctionCode;
  short DataLength;
   short Data[252];
 unsigned short CRC;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_ModbusResponseC()  { std::cout << "m1m3_logevent_ModbusResponseC()"  << std::endl; }
  ~m1m3_logevent_ModbusResponseC() { std::cout << "~m1m3_logevent_ModbusResponseC()"  << std::endl; }
#endif
};

struct m1m3_logevent_PIDInfoC
{
  double Timestamp;
   double Timestep[6];
   double P[6];
   double I[6];
   double D[6];
   double N[6];
   double CalculatedA[6];
   double CalculatedB[6];
   double CalculatedC[6];
   double CalculatedD[6];
   double CalculatedE[6];
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_PIDInfoC()  { std::cout << "m1m3_logevent_PIDInfoC()"  << std::endl; }
  ~m1m3_logevent_PIDInfoC() { std::cout << "~m1m3_logevent_PIDInfoC()"  << std::endl; }
#endif
};

struct m1m3_logevent_PowerStatusC
{
  double Timestamp;
  int PowerNetworkACommandedOn;
  int PowerNetworkAOutputOn;
  int PowerNetworkBCommandedOn;
  int PowerNetworkBOutputOn;
  int PowerNetworkCCommandedOn;
  int PowerNetworkCOutputOn;
  int PowerNetworkDCommandedOn;
  int PowerNetworkDOutputOn;
  int AuxPowerNetworkACommandedOn;
  int AuxPowerNetworkAOutputOn;
  int AuxPowerNetworkBCommandedOn;
  int AuxPowerNetworkBOutputOn;
  int AuxPowerNetworkCCommandedOn;
  int AuxPowerNetworkCOutputOn;
  int AuxPowerNetworkDCommandedOn;
  int AuxPowerNetworkDOutputOn;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_PowerStatusC()  { std::cout << "m1m3_logevent_PowerStatusC()"  << std::endl; }
  ~m1m3_logevent_PowerStatusC() { std::cout << "~m1m3_logevent_PowerStatusC()"  << std::endl; }
#endif
};

struct m1m3_logevent_PowerSupplyStatusC
{
  double Timestamp;
  int RCPMirrorCellUtility220VAC1Status;
  int RCPCabinetUtility220VACStatus;
  int RCPExternalEquipment220VACStatus;
  int RCPMirrorCellUtility220VAC2Status;
  int RCPMirrorCellUtility220VAC3Status;
  int PowerNetworkARedundancyControlStatus;
  int PowerNetworkBRedundancyControlStatus;
  int PowerNetworkCRedundancyControlStatus;
  int PowerNetworkDRedundancyControlStatus;
  int ControlsPowerNetworkRedundancyControlStatus;
  int PowerNetworkAStatus;
  int PowerNetworkARedundantStatus;
  int PowerNetworkBStatus;
  int PowerNetworkBRedundantStatus;
  int PowerNetworkCStatus;
  int PowerNetworkCRedundantStatus;
  int PowerNetworkDStatus;
  int PowerNetworkDRedundantStatus;
  int ControlsPowerNetworkStatus;
  int ControlsPowerNetworkRedundantStatus;
  int LightPowerNetworkStatus;
  int ExternalEquipmentPowerNetworkStatus;
  int LaserTrackerPowerNetworkStatus;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_PowerSupplyStatusC()  { std::cout << "m1m3_logevent_PowerSupplyStatusC()"  << std::endl; }
  ~m1m3_logevent_PowerSupplyStatusC() { std::cout << "~m1m3_logevent_PowerSupplyStatusC()"  << std::endl; }
#endif
};

struct m1m3_logevent_PowerWarningC
{
  double Timestamp;
  int AnyWarning;
  int PowerNetworkAOutputMismatch;
  int PowerNetworkBOutputMismatch;
  int PowerNetworkCOutputMismatch;
  int PowerNetworkDOutputMismatch;
  int AuxPowerNetworkAOutputMismatch;
  int AuxPowerNetworkBOutputMismatch;
  int AuxPowerNetworkCOutputMismatch;
  int AuxPowerNetworkDOutputMismatch;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_PowerWarningC()  { std::cout << "m1m3_logevent_PowerWarningC()"  << std::endl; }
  ~m1m3_logevent_PowerWarningC() { std::cout << "~m1m3_logevent_PowerWarningC()"  << std::endl; }
#endif
};

struct m1m3_logevent_RejectedAberrationForcesC
{
  double Timestamp;
   float ZForces[156];
  float Fz;
  float Mx;
  float My;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_RejectedAberrationForcesC()  { std::cout << "m1m3_logevent_RejectedAberrationForcesC()"  << std::endl; }
  ~m1m3_logevent_RejectedAberrationForcesC() { std::cout << "~m1m3_logevent_RejectedAberrationForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_RejectedAccelerationForcesC
{
  double Timestamp;
   float XForces[12];
   float YForces[100];
   float ZForces[156];
  float Fx;
  float Fy;
  float Fz;
  float Mx;
  float My;
  float Mz;
  float ForceMagnitude;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_RejectedAccelerationForcesC()  { std::cout << "m1m3_logevent_RejectedAccelerationForcesC()"  << std::endl; }
  ~m1m3_logevent_RejectedAccelerationForcesC() { std::cout << "~m1m3_logevent_RejectedAccelerationForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_RejectedActiveOpticForcesC
{
  double Timestamp;
   float ZForces[156];
  float Fz;
  float Mx;
  float My;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_RejectedActiveOpticForcesC()  { std::cout << "m1m3_logevent_RejectedActiveOpticForcesC()"  << std::endl; }
  ~m1m3_logevent_RejectedActiveOpticForcesC() { std::cout << "~m1m3_logevent_RejectedActiveOpticForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_RejectedAzimuthForcesC
{
  double Timestamp;
   float XForces[12];
   float YForces[100];
   float ZForces[156];
  float Fx;
  float Fy;
  float Fz;
  float Mx;
  float My;
  float Mz;
  float ForceMagnitude;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_RejectedAzimuthForcesC()  { std::cout << "m1m3_logevent_RejectedAzimuthForcesC()"  << std::endl; }
  ~m1m3_logevent_RejectedAzimuthForcesC() { std::cout << "~m1m3_logevent_RejectedAzimuthForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_RejectedBalanceForcesC
{
  double Timestamp;
   float XForces[12];
   float YForces[100];
   float ZForces[156];
  float Fx;
  float Fy;
  float Fz;
  float Mx;
  float My;
  float Mz;
  float ForceMagnitude;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_RejectedBalanceForcesC()  { std::cout << "m1m3_logevent_RejectedBalanceForcesC()"  << std::endl; }
  ~m1m3_logevent_RejectedBalanceForcesC() { std::cout << "~m1m3_logevent_RejectedBalanceForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_RejectedCylinderForcesC
{
  double Timestamp;
   int SecondaryCylinderForces[112];
   int PrimaryCylinderForces[156];
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_RejectedCylinderForcesC()  { std::cout << "m1m3_logevent_RejectedCylinderForcesC()"  << std::endl; }
  ~m1m3_logevent_RejectedCylinderForcesC() { std::cout << "~m1m3_logevent_RejectedCylinderForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_RejectedElevationForcesC
{
  double Timestamp;
   float XForces[12];
   float YForces[100];
   float ZForces[156];
  float Fx;
  float Fy;
  float Fz;
  float Mx;
  float My;
  float Mz;
  float ForceMagnitude;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_RejectedElevationForcesC()  { std::cout << "m1m3_logevent_RejectedElevationForcesC()"  << std::endl; }
  ~m1m3_logevent_RejectedElevationForcesC() { std::cout << "~m1m3_logevent_RejectedElevationForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_RejectedForcesC
{
  double Timestamp;
   float XForces[12];
   float YForces[100];
   float ZForces[156];
  float Fx;
  float Fy;
  float Fz;
  float Mx;
  float My;
  float Mz;
  float ForceMagnitude;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_RejectedForcesC()  { std::cout << "m1m3_logevent_RejectedForcesC()"  << std::endl; }
  ~m1m3_logevent_RejectedForcesC() { std::cout << "~m1m3_logevent_RejectedForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_RejectedOffsetForcesC
{
  double Timestamp;
   float XForces[12];
   float YForces[100];
   float ZForces[156];
  float Fx;
  float Fy;
  float Fz;
  float Mx;
  float My;
  float Mz;
  float ForceMagnitude;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_RejectedOffsetForcesC()  { std::cout << "m1m3_logevent_RejectedOffsetForcesC()"  << std::endl; }
  ~m1m3_logevent_RejectedOffsetForcesC() { std::cout << "~m1m3_logevent_RejectedOffsetForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_RejectedStaticForcesC
{
  double Timestamp;
   float XForces[12];
   float YForces[100];
   float ZForces[156];
  float Fx;
  float Fy;
  float Fz;
  float Mx;
  float My;
  float Mz;
  float ForceMagnitude;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_RejectedStaticForcesC()  { std::cout << "m1m3_logevent_RejectedStaticForcesC()"  << std::endl; }
  ~m1m3_logevent_RejectedStaticForcesC() { std::cout << "~m1m3_logevent_RejectedStaticForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_RejectedThermalForcesC
{
  double Timestamp;
   float XForces[12];
   float YForces[100];
   float ZForces[156];
  float Fx;
  float Fy;
  float Fz;
  float Mx;
  float My;
  float Mz;
  float ForceMagnitude;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_RejectedThermalForcesC()  { std::cout << "m1m3_logevent_RejectedThermalForcesC()"  << std::endl; }
  ~m1m3_logevent_RejectedThermalForcesC() { std::cout << "~m1m3_logevent_RejectedThermalForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_RejectedVelocityForcesC
{
  double Timestamp;
   float XForces[12];
   float YForces[100];
   float ZForces[156];
  float Fx;
  float Fy;
  float Fz;
  float Mx;
  float My;
  float Mz;
  float ForceMagnitude;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_RejectedVelocityForcesC()  { std::cout << "m1m3_logevent_RejectedVelocityForcesC()"  << std::endl; }
  ~m1m3_logevent_RejectedVelocityForcesC() { std::cout << "~m1m3_logevent_RejectedVelocityForcesC()"  << std::endl; }
#endif
};

struct m1m3_logevent_SettingVersionsC
{
  double Timestamp;
  std::string	RecommendedSettingsVersion;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_SettingVersionsC()  { std::cout << "m1m3_logevent_SettingVersionsC()"  << std::endl; }
  ~m1m3_logevent_SettingVersionsC() { std::cout << "~m1m3_logevent_SettingVersionsC()"  << std::endl; }
#endif
};

struct m1m3_logevent_SettingsAppliedC
{
  double Timestamp;
  std::string	Settings;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_SettingsAppliedC()  { std::cout << "m1m3_logevent_SettingsAppliedC()"  << std::endl; }
  ~m1m3_logevent_SettingsAppliedC() { std::cout << "~m1m3_logevent_SettingsAppliedC()"  << std::endl; }
#endif
};

struct m1m3_logevent_SummaryStateC
{
  double Timestamp;
  int SummaryState;
  int priority;

#ifdef SAL_DEBUG_CSTRUCTS
  m1m3_logevent_SummaryStateC()  { std::cout << "m1m3_logevent_SummaryStateC()"  << std::endl; }
  ~m1m3_logevent_SummaryStateC() { std::cout << "~m1m3_logevent_SummaryStateC()"  << std::endl; }
#endif
};


struct m1m3_commandC
{
      std::string	device;
      std::string	property;
      std::string	action;
      std::string	value;
      std::string	modifiers;

};
struct m1m3_ackcmdC
{
      int 	ack;
      int 	error;
      std::string	result;

};
struct m1m3_logeventC
{
      std::string	message;

};

#endif

