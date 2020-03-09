
#ifndef _SAL_MTM1M3MGR_
  #define _SAL_MTM1M3MGR_

  #include <string>
  #include <cassert>
  #include <string>
  #include <iostream>
  #include <fstream>
  #include <vector>
  #include <string.h>
  #include <stdlib.h>
  #include <stdio.h>
  #include <string.h>
  #include <time.h>
  #include <sys/time.h>
  #include <sys/timex.h>
  #include <signal.h>
  #include <unistd.h>
  #include "SAL_defines.h"
  #include "ccpp_dds_dcps.h"
  #include "QosProvider.h"
// INSERT TYPE INCLUDES
  #include "ccpp_sal_MTM1M3.h"
#ifdef SAL_BUILD_FOR_PYTHON
#include "Python.h"
#endif

  #include "SAL_MTM1M3C.h"

  using namespace std;
  using namespace DDS;

#ifndef _SAL_SALActorMGR_
  #define _SAL_SALActorMGR_
  #define SAL__ACTORS_MAXCOUNT	256
  #define SAL__ACTORS_NAMESIZE	128

/* Array to hold the names for all ReturnCodes. */
  static string RetCodeName[13] = 
  {
	    "DDS_RETCODE_OK", "DDS_RETCODE_ERROR", "DDS_RETCODE_UNSUPPORTED", 
	    "DDS_RETCODE_BAD_PARAMETER", "DDS_RETCODE_PRECONDITION_NOT_MET", 
	    "DDS_RETCODE_OUT_OF_RESOURCES", "DDS_RETCODE_NOT_ENABLED", 
	    "DDS_RETCODE_IMMUTABLE_POLICY", "DDS_RETCODE_INCONSISTENT_POLICY", 
	    "DDS_RETCODE_ALREADY_DELETED", "DDS_RETCODE_TIMEOUT", "DDS_RETCODE_NO_DATA",
	    "DDS_RETCODE_ILLEGAL_OPERATION"
  };


  struct salActor {
      char 			baseName[SAL__ACTORS_NAMESIZE];
      char 			topicName[SAL__ACTORS_NAMESIZE];
      char 			topicHandle[SAL__ACTORS_NAMESIZE];
      DDS::String_var 		sFilter;
      DDS::String_var 		typeName;
      DDS::String_var 		typeName2;
      Topic_var 		topic;
      Topic_var 		topic2;
      DataReader_var 		reader;
      DataReader_var 		reader2;
      ContentFilteredTopic_var  filteredtopic;
      ContentFilteredTopic_var  filteredtopic2;
      DataWriter_var 		writer;
      DataWriter_var 		writer2;
      Publisher_var 		publisher;
      Subscriber_var 		subscriber;
 
      /* QosPolicy holders */
      TopicQos 			reliable_topic_qos;
      TopicQos 			reliable_topic_qos2;
      PublisherQos 		pub_qos;
      SubscriberQos 		sub_qos;
      DataReaderQos 		dr_qos;
      DataWriterQos 		dw_qos;
      bool			isActive;
      bool 			isReader;
      bool 			isWriter;
      bool 			isCommand;
      bool 			isEventReader;
      bool 			isEventWriter;
      bool 			isProcessor;
      int 			debugLevel;
      int 			sndSeqNum;
      int                       cmdSeqNum;
      int 			rcvSeqNum;
      int 			rcvOrigin;
      int			maxSamples;
      int			error;
      int			ack;
      int			activehost;
      int			activeorigin;
      int			activecmdid;
      double			timeout;
      char			result[256];
      double	 		sndStamp;
      double			rcvStamp;
      double			sampleAge;
      int                       historyDepth;
      int                       tuneableQos;
      DDS::DurabilityQosPolicyKind durability;
  };
#endif

  class SAL_MTM1M3
  {
      /* Generic DDS entities */
      DomainParticipantFactory_var dpf;
      DomainParticipant_var participant;
      Topic_var topic;
      Topic_var topic2;
      ContentFilteredTopic_var filteredtopic;
      ContentFilteredTopic_var filteredtopic2;
      Publisher_var publisher;
      Subscriber_var subscriber;
      DataWriter_var writer;
      DataWriter_var writer2;
      DataReader_var reader;
      DataReader_var reader2;

      /* QosPolicy holders */
      TopicQos reliable_topic_qos;
      TopicQos reliable_topic_qos2;
      PublisherQos pub_qos;
      DataWriterQos dw_qos;
      SubscriberQos sub_qos;

      DomainId_t domain;
      ReturnCode_t status;

      DDS::String_var partition;
      DDS::String_var typeName;
      DDS::String_var typeName2;
      DDS::String_var sFilter;
      bool hasReader;
      bool hasWriter;
      bool hasCommand;
      bool hasEventReader;
      bool hasEventWriter;
      bool hasProcessor;
      int subsystemID;
      int debugLevel;
      int cmdSeqNum;
      int sndSeqNum;
      int rcvSeqNum;
      int rcvOrigin;
      int historySync;
      double rcvdTime;
      salU64  origin;
      long ddsIPaddress;
      char   domainName[128];
      salActor sal[SAL__ACTORS_MAXCOUNT];
      int lastActor_telemetry;
      int lastActor_command;
      int lastActor_event;

    public:

     SAL_MTM1M3(int aKey);
     SAL_MTM1M3();

// INSERT TYPE SUPPORT      

      salReturn putSample(MTM1M3::accelerometerData_9537e860 data);
      salReturn getSample(MTM1M3::accelerometerData_9537e860Seq data);
      salReturn putSample_accelerometerData(MTM1M3_accelerometerDataC *data);
      salReturn getSample_accelerometerData(MTM1M3_accelerometerDataC *data);
      salReturn getNextSample_accelerometerData(MTM1M3_accelerometerDataC *data);
      salReturn flushSamples_accelerometerData(MTM1M3_accelerometerDataC *data);
      salReturn getLastSample_accelerometerData(MTM1M3_accelerometerDataC *data);
      MTM1M3_accelerometerDataC lastSample_MTM1M3_accelerometerData;


      salReturn putSample(MTM1M3::command_abort_62d3a8d0 data);
      salReturn getSample(MTM1M3::command_abort_62d3a8d0Seq data);
      salReturn putSample_command_abort(MTM1M3_command_abortC *data);
      salReturn getSample_command_abort(MTM1M3_command_abortC *data);
      salReturn getNextSample_command_abort(MTM1M3_command_abortC *data);
      salReturn flushSamples_command_abort(MTM1M3_command_abortC *data);
      salReturn getLastSample_command_abort(MTM1M3_command_abortC *data);
      MTM1M3_command_abortC lastSample_MTM1M3_command_abort;


      salReturn putSample(MTM1M3::command_abortProfile_88b2fb6a data);
      salReturn getSample(MTM1M3::command_abortProfile_88b2fb6aSeq data);
      salReturn putSample_command_abortProfile(MTM1M3_command_abortProfileC *data);
      salReturn getSample_command_abortProfile(MTM1M3_command_abortProfileC *data);
      salReturn getNextSample_command_abortProfile(MTM1M3_command_abortProfileC *data);
      salReturn flushSamples_command_abortProfile(MTM1M3_command_abortProfileC *data);
      salReturn getLastSample_command_abortProfile(MTM1M3_command_abortProfileC *data);
      MTM1M3_command_abortProfileC lastSample_MTM1M3_command_abortProfile;


      salReturn putSample(MTM1M3::command_abortRaiseM1M3_7afaba9d data);
      salReturn getSample(MTM1M3::command_abortRaiseM1M3_7afaba9dSeq data);
      salReturn putSample_command_abortRaiseM1M3(MTM1M3_command_abortRaiseM1M3C *data);
      salReturn getSample_command_abortRaiseM1M3(MTM1M3_command_abortRaiseM1M3C *data);
      salReturn getNextSample_command_abortRaiseM1M3(MTM1M3_command_abortRaiseM1M3C *data);
      salReturn flushSamples_command_abortRaiseM1M3(MTM1M3_command_abortRaiseM1M3C *data);
      salReturn getLastSample_command_abortRaiseM1M3(MTM1M3_command_abortRaiseM1M3C *data);
      MTM1M3_command_abortRaiseM1M3C lastSample_MTM1M3_command_abortRaiseM1M3;


      salReturn putSample(MTM1M3::command_applyAberrationForces_4f7ead34 data);
      salReturn getSample(MTM1M3::command_applyAberrationForces_4f7ead34Seq data);
      salReturn putSample_command_applyAberrationForces(MTM1M3_command_applyAberrationForcesC *data);
      salReturn getSample_command_applyAberrationForces(MTM1M3_command_applyAberrationForcesC *data);
      salReturn getNextSample_command_applyAberrationForces(MTM1M3_command_applyAberrationForcesC *data);
      salReturn flushSamples_command_applyAberrationForces(MTM1M3_command_applyAberrationForcesC *data);
      salReturn getLastSample_command_applyAberrationForces(MTM1M3_command_applyAberrationForcesC *data);
      MTM1M3_command_applyAberrationForcesC lastSample_MTM1M3_command_applyAberrationForces;


      salReturn putSample(MTM1M3::command_applyAberrationForcesByBendingModes_ef2ea53d data);
      salReturn getSample(MTM1M3::command_applyAberrationForcesByBendingModes_ef2ea53dSeq data);
      salReturn putSample_command_applyAberrationForcesByBendingModes(MTM1M3_command_applyAberrationForcesByBendingModesC *data);
      salReturn getSample_command_applyAberrationForcesByBendingModes(MTM1M3_command_applyAberrationForcesByBendingModesC *data);
      salReturn getNextSample_command_applyAberrationForcesByBendingModes(MTM1M3_command_applyAberrationForcesByBendingModesC *data);
      salReturn flushSamples_command_applyAberrationForcesByBendingModes(MTM1M3_command_applyAberrationForcesByBendingModesC *data);
      salReturn getLastSample_command_applyAberrationForcesByBendingModes(MTM1M3_command_applyAberrationForcesByBendingModesC *data);
      MTM1M3_command_applyAberrationForcesByBendingModesC lastSample_MTM1M3_command_applyAberrationForcesByBendingModes;


      salReturn putSample(MTM1M3::command_applyActiveOpticForces_c79b863f data);
      salReturn getSample(MTM1M3::command_applyActiveOpticForces_c79b863fSeq data);
      salReturn putSample_command_applyActiveOpticForces(MTM1M3_command_applyActiveOpticForcesC *data);
      salReturn getSample_command_applyActiveOpticForces(MTM1M3_command_applyActiveOpticForcesC *data);
      salReturn getNextSample_command_applyActiveOpticForces(MTM1M3_command_applyActiveOpticForcesC *data);
      salReturn flushSamples_command_applyActiveOpticForces(MTM1M3_command_applyActiveOpticForcesC *data);
      salReturn getLastSample_command_applyActiveOpticForces(MTM1M3_command_applyActiveOpticForcesC *data);
      MTM1M3_command_applyActiveOpticForcesC lastSample_MTM1M3_command_applyActiveOpticForces;


      salReturn putSample(MTM1M3::command_applyActiveOpticForcesByBendingModes_3b76ff5b data);
      salReturn getSample(MTM1M3::command_applyActiveOpticForcesByBendingModes_3b76ff5bSeq data);
      salReturn putSample_command_applyActiveOpticForcesByBendingModes(MTM1M3_command_applyActiveOpticForcesByBendingModesC *data);
      salReturn getSample_command_applyActiveOpticForcesByBendingModes(MTM1M3_command_applyActiveOpticForcesByBendingModesC *data);
      salReturn getNextSample_command_applyActiveOpticForcesByBendingModes(MTM1M3_command_applyActiveOpticForcesByBendingModesC *data);
      salReturn flushSamples_command_applyActiveOpticForcesByBendingModes(MTM1M3_command_applyActiveOpticForcesByBendingModesC *data);
      salReturn getLastSample_command_applyActiveOpticForcesByBendingModes(MTM1M3_command_applyActiveOpticForcesByBendingModesC *data);
      MTM1M3_command_applyActiveOpticForcesByBendingModesC lastSample_MTM1M3_command_applyActiveOpticForcesByBendingModes;


      salReturn putSample(MTM1M3::command_applyOffsetForces_c715c535 data);
      salReturn getSample(MTM1M3::command_applyOffsetForces_c715c535Seq data);
      salReturn putSample_command_applyOffsetForces(MTM1M3_command_applyOffsetForcesC *data);
      salReturn getSample_command_applyOffsetForces(MTM1M3_command_applyOffsetForcesC *data);
      salReturn getNextSample_command_applyOffsetForces(MTM1M3_command_applyOffsetForcesC *data);
      salReturn flushSamples_command_applyOffsetForces(MTM1M3_command_applyOffsetForcesC *data);
      salReturn getLastSample_command_applyOffsetForces(MTM1M3_command_applyOffsetForcesC *data);
      MTM1M3_command_applyOffsetForcesC lastSample_MTM1M3_command_applyOffsetForces;


      salReturn putSample(MTM1M3::command_applyOffsetForcesByMirrorForce_4d09c953 data);
      salReturn getSample(MTM1M3::command_applyOffsetForcesByMirrorForce_4d09c953Seq data);
      salReturn putSample_command_applyOffsetForcesByMirrorForce(MTM1M3_command_applyOffsetForcesByMirrorForceC *data);
      salReturn getSample_command_applyOffsetForcesByMirrorForce(MTM1M3_command_applyOffsetForcesByMirrorForceC *data);
      salReturn getNextSample_command_applyOffsetForcesByMirrorForce(MTM1M3_command_applyOffsetForcesByMirrorForceC *data);
      salReturn flushSamples_command_applyOffsetForcesByMirrorForce(MTM1M3_command_applyOffsetForcesByMirrorForceC *data);
      salReturn getLastSample_command_applyOffsetForcesByMirrorForce(MTM1M3_command_applyOffsetForcesByMirrorForceC *data);
      MTM1M3_command_applyOffsetForcesByMirrorForceC lastSample_MTM1M3_command_applyOffsetForcesByMirrorForce;


      salReturn putSample(MTM1M3::command_clearAberrationForces_58d2b112 data);
      salReturn getSample(MTM1M3::command_clearAberrationForces_58d2b112Seq data);
      salReturn putSample_command_clearAberrationForces(MTM1M3_command_clearAberrationForcesC *data);
      salReturn getSample_command_clearAberrationForces(MTM1M3_command_clearAberrationForcesC *data);
      salReturn getNextSample_command_clearAberrationForces(MTM1M3_command_clearAberrationForcesC *data);
      salReturn flushSamples_command_clearAberrationForces(MTM1M3_command_clearAberrationForcesC *data);
      salReturn getLastSample_command_clearAberrationForces(MTM1M3_command_clearAberrationForcesC *data);
      MTM1M3_command_clearAberrationForcesC lastSample_MTM1M3_command_clearAberrationForces;


      salReturn putSample(MTM1M3::command_clearActiveOpticForces_d4ffa42c data);
      salReturn getSample(MTM1M3::command_clearActiveOpticForces_d4ffa42cSeq data);
      salReturn putSample_command_clearActiveOpticForces(MTM1M3_command_clearActiveOpticForcesC *data);
      salReturn getSample_command_clearActiveOpticForces(MTM1M3_command_clearActiveOpticForcesC *data);
      salReturn getNextSample_command_clearActiveOpticForces(MTM1M3_command_clearActiveOpticForcesC *data);
      salReturn flushSamples_command_clearActiveOpticForces(MTM1M3_command_clearActiveOpticForcesC *data);
      salReturn getLastSample_command_clearActiveOpticForces(MTM1M3_command_clearActiveOpticForcesC *data);
      MTM1M3_command_clearActiveOpticForcesC lastSample_MTM1M3_command_clearActiveOpticForces;


      salReturn putSample(MTM1M3::command_clearOffsetForces_0d7f285d data);
      salReturn getSample(MTM1M3::command_clearOffsetForces_0d7f285dSeq data);
      salReturn putSample_command_clearOffsetForces(MTM1M3_command_clearOffsetForcesC *data);
      salReturn getSample_command_clearOffsetForces(MTM1M3_command_clearOffsetForcesC *data);
      salReturn getNextSample_command_clearOffsetForces(MTM1M3_command_clearOffsetForcesC *data);
      salReturn flushSamples_command_clearOffsetForces(MTM1M3_command_clearOffsetForcesC *data);
      salReturn getLastSample_command_clearOffsetForces(MTM1M3_command_clearOffsetForcesC *data);
      MTM1M3_command_clearOffsetForcesC lastSample_MTM1M3_command_clearOffsetForces;


      salReturn putSample(MTM1M3::command_disable_04faa884 data);
      salReturn getSample(MTM1M3::command_disable_04faa884Seq data);
      salReturn putSample_command_disable(MTM1M3_command_disableC *data);
      salReturn getSample_command_disable(MTM1M3_command_disableC *data);
      salReturn getNextSample_command_disable(MTM1M3_command_disableC *data);
      salReturn flushSamples_command_disable(MTM1M3_command_disableC *data);
      salReturn getLastSample_command_disable(MTM1M3_command_disableC *data);
      MTM1M3_command_disableC lastSample_MTM1M3_command_disable;


      salReturn putSample(MTM1M3::command_disableHardpointChase_dbe9a16b data);
      salReturn getSample(MTM1M3::command_disableHardpointChase_dbe9a16bSeq data);
      salReturn putSample_command_disableHardpointChase(MTM1M3_command_disableHardpointChaseC *data);
      salReturn getSample_command_disableHardpointChase(MTM1M3_command_disableHardpointChaseC *data);
      salReturn getNextSample_command_disableHardpointChase(MTM1M3_command_disableHardpointChaseC *data);
      salReturn flushSamples_command_disableHardpointChase(MTM1M3_command_disableHardpointChaseC *data);
      salReturn getLastSample_command_disableHardpointChase(MTM1M3_command_disableHardpointChaseC *data);
      MTM1M3_command_disableHardpointChaseC lastSample_MTM1M3_command_disableHardpointChase;


      salReturn putSample(MTM1M3::command_disableHardpointCorrections_07d1f2ea data);
      salReturn getSample(MTM1M3::command_disableHardpointCorrections_07d1f2eaSeq data);
      salReturn putSample_command_disableHardpointCorrections(MTM1M3_command_disableHardpointCorrectionsC *data);
      salReturn getSample_command_disableHardpointCorrections(MTM1M3_command_disableHardpointCorrectionsC *data);
      salReturn getNextSample_command_disableHardpointCorrections(MTM1M3_command_disableHardpointCorrectionsC *data);
      salReturn flushSamples_command_disableHardpointCorrections(MTM1M3_command_disableHardpointCorrectionsC *data);
      salReturn getLastSample_command_disableHardpointCorrections(MTM1M3_command_disableHardpointCorrectionsC *data);
      MTM1M3_command_disableHardpointCorrectionsC lastSample_MTM1M3_command_disableHardpointCorrections;


      salReturn putSample(MTM1M3::command_enable_c128bf47 data);
      salReturn getSample(MTM1M3::command_enable_c128bf47Seq data);
      salReturn putSample_command_enable(MTM1M3_command_enableC *data);
      salReturn getSample_command_enable(MTM1M3_command_enableC *data);
      salReturn getNextSample_command_enable(MTM1M3_command_enableC *data);
      salReturn flushSamples_command_enable(MTM1M3_command_enableC *data);
      salReturn getLastSample_command_enable(MTM1M3_command_enableC *data);
      MTM1M3_command_enableC lastSample_MTM1M3_command_enable;


      salReturn putSample(MTM1M3::command_enableHardpointChase_49c0d4e1 data);
      salReturn getSample(MTM1M3::command_enableHardpointChase_49c0d4e1Seq data);
      salReturn putSample_command_enableHardpointChase(MTM1M3_command_enableHardpointChaseC *data);
      salReturn getSample_command_enableHardpointChase(MTM1M3_command_enableHardpointChaseC *data);
      salReturn getNextSample_command_enableHardpointChase(MTM1M3_command_enableHardpointChaseC *data);
      salReturn flushSamples_command_enableHardpointChase(MTM1M3_command_enableHardpointChaseC *data);
      salReturn getLastSample_command_enableHardpointChase(MTM1M3_command_enableHardpointChaseC *data);
      MTM1M3_command_enableHardpointChaseC lastSample_MTM1M3_command_enableHardpointChase;


      salReturn putSample(MTM1M3::command_enableHardpointCorrections_dae9c1ec data);
      salReturn getSample(MTM1M3::command_enableHardpointCorrections_dae9c1ecSeq data);
      salReturn putSample_command_enableHardpointCorrections(MTM1M3_command_enableHardpointCorrectionsC *data);
      salReturn getSample_command_enableHardpointCorrections(MTM1M3_command_enableHardpointCorrectionsC *data);
      salReturn getNextSample_command_enableHardpointCorrections(MTM1M3_command_enableHardpointCorrectionsC *data);
      salReturn flushSamples_command_enableHardpointCorrections(MTM1M3_command_enableHardpointCorrectionsC *data);
      salReturn getLastSample_command_enableHardpointCorrections(MTM1M3_command_enableHardpointCorrectionsC *data);
      MTM1M3_command_enableHardpointCorrectionsC lastSample_MTM1M3_command_enableHardpointCorrections;


      salReturn putSample(MTM1M3::command_enterControl_417c941a data);
      salReturn getSample(MTM1M3::command_enterControl_417c941aSeq data);
      salReturn putSample_command_enterControl(MTM1M3_command_enterControlC *data);
      salReturn getSample_command_enterControl(MTM1M3_command_enterControlC *data);
      salReturn getNextSample_command_enterControl(MTM1M3_command_enterControlC *data);
      salReturn flushSamples_command_enterControl(MTM1M3_command_enterControlC *data);
      salReturn getLastSample_command_enterControl(MTM1M3_command_enterControlC *data);
      MTM1M3_command_enterControlC lastSample_MTM1M3_command_enterControl;


      salReturn putSample(MTM1M3::command_enterEngineering_89e1ff1c data);
      salReturn getSample(MTM1M3::command_enterEngineering_89e1ff1cSeq data);
      salReturn putSample_command_enterEngineering(MTM1M3_command_enterEngineeringC *data);
      salReturn getSample_command_enterEngineering(MTM1M3_command_enterEngineeringC *data);
      salReturn getNextSample_command_enterEngineering(MTM1M3_command_enterEngineeringC *data);
      salReturn flushSamples_command_enterEngineering(MTM1M3_command_enterEngineeringC *data);
      salReturn getLastSample_command_enterEngineering(MTM1M3_command_enterEngineeringC *data);
      MTM1M3_command_enterEngineeringC lastSample_MTM1M3_command_enterEngineering;


      salReturn putSample(MTM1M3::command_exitControl_e2ea247d data);
      salReturn getSample(MTM1M3::command_exitControl_e2ea247dSeq data);
      salReturn putSample_command_exitControl(MTM1M3_command_exitControlC *data);
      salReturn getSample_command_exitControl(MTM1M3_command_exitControlC *data);
      salReturn getNextSample_command_exitControl(MTM1M3_command_exitControlC *data);
      salReturn flushSamples_command_exitControl(MTM1M3_command_exitControlC *data);
      salReturn getLastSample_command_exitControl(MTM1M3_command_exitControlC *data);
      MTM1M3_command_exitControlC lastSample_MTM1M3_command_exitControl;


      salReturn putSample(MTM1M3::command_exitEngineering_01073d21 data);
      salReturn getSample(MTM1M3::command_exitEngineering_01073d21Seq data);
      salReturn putSample_command_exitEngineering(MTM1M3_command_exitEngineeringC *data);
      salReturn getSample_command_exitEngineering(MTM1M3_command_exitEngineeringC *data);
      salReturn getNextSample_command_exitEngineering(MTM1M3_command_exitEngineeringC *data);
      salReturn flushSamples_command_exitEngineering(MTM1M3_command_exitEngineeringC *data);
      salReturn getLastSample_command_exitEngineering(MTM1M3_command_exitEngineeringC *data);
      MTM1M3_command_exitEngineeringC lastSample_MTM1M3_command_exitEngineering;


      salReturn putSample(MTM1M3::command_lowerM1M3_69afda69 data);
      salReturn getSample(MTM1M3::command_lowerM1M3_69afda69Seq data);
      salReturn putSample_command_lowerM1M3(MTM1M3_command_lowerM1M3C *data);
      salReturn getSample_command_lowerM1M3(MTM1M3_command_lowerM1M3C *data);
      salReturn getNextSample_command_lowerM1M3(MTM1M3_command_lowerM1M3C *data);
      salReturn flushSamples_command_lowerM1M3(MTM1M3_command_lowerM1M3C *data);
      salReturn getLastSample_command_lowerM1M3(MTM1M3_command_lowerM1M3C *data);
      MTM1M3_command_lowerM1M3C lastSample_MTM1M3_command_lowerM1M3;


      salReturn putSample(MTM1M3::command_modbusTransmit_a3c81bde data);
      salReturn getSample(MTM1M3::command_modbusTransmit_a3c81bdeSeq data);
      salReturn putSample_command_modbusTransmit(MTM1M3_command_modbusTransmitC *data);
      salReturn getSample_command_modbusTransmit(MTM1M3_command_modbusTransmitC *data);
      salReturn getNextSample_command_modbusTransmit(MTM1M3_command_modbusTransmitC *data);
      salReturn flushSamples_command_modbusTransmit(MTM1M3_command_modbusTransmitC *data);
      salReturn getLastSample_command_modbusTransmit(MTM1M3_command_modbusTransmitC *data);
      MTM1M3_command_modbusTransmitC lastSample_MTM1M3_command_modbusTransmit;


      salReturn putSample(MTM1M3::command_moveHardpointActuators_4d114fab data);
      salReturn getSample(MTM1M3::command_moveHardpointActuators_4d114fabSeq data);
      salReturn putSample_command_moveHardpointActuators(MTM1M3_command_moveHardpointActuatorsC *data);
      salReturn getSample_command_moveHardpointActuators(MTM1M3_command_moveHardpointActuatorsC *data);
      salReturn getNextSample_command_moveHardpointActuators(MTM1M3_command_moveHardpointActuatorsC *data);
      salReturn flushSamples_command_moveHardpointActuators(MTM1M3_command_moveHardpointActuatorsC *data);
      salReturn getLastSample_command_moveHardpointActuators(MTM1M3_command_moveHardpointActuatorsC *data);
      MTM1M3_command_moveHardpointActuatorsC lastSample_MTM1M3_command_moveHardpointActuators;


      salReturn putSample(MTM1M3::command_positionM1M3_fa7ca786 data);
      salReturn getSample(MTM1M3::command_positionM1M3_fa7ca786Seq data);
      salReturn putSample_command_positionM1M3(MTM1M3_command_positionM1M3C *data);
      salReturn getSample_command_positionM1M3(MTM1M3_command_positionM1M3C *data);
      salReturn getNextSample_command_positionM1M3(MTM1M3_command_positionM1M3C *data);
      salReturn flushSamples_command_positionM1M3(MTM1M3_command_positionM1M3C *data);
      salReturn getLastSample_command_positionM1M3(MTM1M3_command_positionM1M3C *data);
      MTM1M3_command_positionM1M3C lastSample_MTM1M3_command_positionM1M3;


      salReturn putSample(MTM1M3::command_programILC_7dde50ee data);
      salReturn getSample(MTM1M3::command_programILC_7dde50eeSeq data);
      salReturn putSample_command_programILC(MTM1M3_command_programILCC *data);
      salReturn getSample_command_programILC(MTM1M3_command_programILCC *data);
      salReturn getNextSample_command_programILC(MTM1M3_command_programILCC *data);
      salReturn flushSamples_command_programILC(MTM1M3_command_programILCC *data);
      salReturn getLastSample_command_programILC(MTM1M3_command_programILCC *data);
      MTM1M3_command_programILCC lastSample_MTM1M3_command_programILC;


      salReturn putSample(MTM1M3::command_raiseM1M3_f0a54745 data);
      salReturn getSample(MTM1M3::command_raiseM1M3_f0a54745Seq data);
      salReturn putSample_command_raiseM1M3(MTM1M3_command_raiseM1M3C *data);
      salReturn getSample_command_raiseM1M3(MTM1M3_command_raiseM1M3C *data);
      salReturn getNextSample_command_raiseM1M3(MTM1M3_command_raiseM1M3C *data);
      salReturn flushSamples_command_raiseM1M3(MTM1M3_command_raiseM1M3C *data);
      salReturn getLastSample_command_raiseM1M3(MTM1M3_command_raiseM1M3C *data);
      MTM1M3_command_raiseM1M3C lastSample_MTM1M3_command_raiseM1M3;


      salReturn putSample(MTM1M3::command_resetPID_bc5508ce data);
      salReturn getSample(MTM1M3::command_resetPID_bc5508ceSeq data);
      salReturn putSample_command_resetPID(MTM1M3_command_resetPIDC *data);
      salReturn getSample_command_resetPID(MTM1M3_command_resetPIDC *data);
      salReturn getNextSample_command_resetPID(MTM1M3_command_resetPIDC *data);
      salReturn flushSamples_command_resetPID(MTM1M3_command_resetPIDC *data);
      salReturn getLastSample_command_resetPID(MTM1M3_command_resetPIDC *data);
      MTM1M3_command_resetPIDC lastSample_MTM1M3_command_resetPID;


      salReturn putSample(MTM1M3::command_runMirrorForceProfile_33f2be6c data);
      salReturn getSample(MTM1M3::command_runMirrorForceProfile_33f2be6cSeq data);
      salReturn putSample_command_runMirrorForceProfile(MTM1M3_command_runMirrorForceProfileC *data);
      salReturn getSample_command_runMirrorForceProfile(MTM1M3_command_runMirrorForceProfileC *data);
      salReturn getNextSample_command_runMirrorForceProfile(MTM1M3_command_runMirrorForceProfileC *data);
      salReturn flushSamples_command_runMirrorForceProfile(MTM1M3_command_runMirrorForceProfileC *data);
      salReturn getLastSample_command_runMirrorForceProfile(MTM1M3_command_runMirrorForceProfileC *data);
      MTM1M3_command_runMirrorForceProfileC lastSample_MTM1M3_command_runMirrorForceProfile;


      salReturn putSample(MTM1M3::command_setLogLevel_346fd770 data);
      salReturn getSample(MTM1M3::command_setLogLevel_346fd770Seq data);
      salReturn putSample_command_setLogLevel(MTM1M3_command_setLogLevelC *data);
      salReturn getSample_command_setLogLevel(MTM1M3_command_setLogLevelC *data);
      salReturn getNextSample_command_setLogLevel(MTM1M3_command_setLogLevelC *data);
      salReturn flushSamples_command_setLogLevel(MTM1M3_command_setLogLevelC *data);
      salReturn getLastSample_command_setLogLevel(MTM1M3_command_setLogLevelC *data);
      MTM1M3_command_setLogLevelC lastSample_MTM1M3_command_setLogLevel;


      salReturn putSample(MTM1M3::command_setSimulationMode_dccc3b3c data);
      salReturn getSample(MTM1M3::command_setSimulationMode_dccc3b3cSeq data);
      salReturn putSample_command_setSimulationMode(MTM1M3_command_setSimulationModeC *data);
      salReturn getSample_command_setSimulationMode(MTM1M3_command_setSimulationModeC *data);
      salReturn getNextSample_command_setSimulationMode(MTM1M3_command_setSimulationModeC *data);
      salReturn flushSamples_command_setSimulationMode(MTM1M3_command_setSimulationModeC *data);
      salReturn getLastSample_command_setSimulationMode(MTM1M3_command_setSimulationModeC *data);
      MTM1M3_command_setSimulationModeC lastSample_MTM1M3_command_setSimulationMode;


      salReturn putSample(MTM1M3::command_setThermalSetpoint_ca5041e8 data);
      salReturn getSample(MTM1M3::command_setThermalSetpoint_ca5041e8Seq data);
      salReturn putSample_command_setThermalSetpoint(MTM1M3_command_setThermalSetpointC *data);
      salReturn getSample_command_setThermalSetpoint(MTM1M3_command_setThermalSetpointC *data);
      salReturn getNextSample_command_setThermalSetpoint(MTM1M3_command_setThermalSetpointC *data);
      salReturn flushSamples_command_setThermalSetpoint(MTM1M3_command_setThermalSetpointC *data);
      salReturn getLastSample_command_setThermalSetpoint(MTM1M3_command_setThermalSetpointC *data);
      MTM1M3_command_setThermalSetpointC lastSample_MTM1M3_command_setThermalSetpoint;


      salReturn putSample(MTM1M3::command_setValue_56638307 data);
      salReturn getSample(MTM1M3::command_setValue_56638307Seq data);
      salReturn putSample_command_setValue(MTM1M3_command_setValueC *data);
      salReturn getSample_command_setValue(MTM1M3_command_setValueC *data);
      salReturn getNextSample_command_setValue(MTM1M3_command_setValueC *data);
      salReturn flushSamples_command_setValue(MTM1M3_command_setValueC *data);
      salReturn getLastSample_command_setValue(MTM1M3_command_setValueC *data);
      MTM1M3_command_setValueC lastSample_MTM1M3_command_setValue;


      salReturn putSample(MTM1M3::command_shutdown_46d06e01 data);
      salReturn getSample(MTM1M3::command_shutdown_46d06e01Seq data);
      salReturn putSample_command_shutdown(MTM1M3_command_shutdownC *data);
      salReturn getSample_command_shutdown(MTM1M3_command_shutdownC *data);
      salReturn getNextSample_command_shutdown(MTM1M3_command_shutdownC *data);
      salReturn flushSamples_command_shutdown(MTM1M3_command_shutdownC *data);
      salReturn getLastSample_command_shutdown(MTM1M3_command_shutdownC *data);
      MTM1M3_command_shutdownC lastSample_MTM1M3_command_shutdown;


      salReturn putSample(MTM1M3::command_standby_9b43256c data);
      salReturn getSample(MTM1M3::command_standby_9b43256cSeq data);
      salReturn putSample_command_standby(MTM1M3_command_standbyC *data);
      salReturn getSample_command_standby(MTM1M3_command_standbyC *data);
      salReturn getNextSample_command_standby(MTM1M3_command_standbyC *data);
      salReturn flushSamples_command_standby(MTM1M3_command_standbyC *data);
      salReturn getLastSample_command_standby(MTM1M3_command_standbyC *data);
      MTM1M3_command_standbyC lastSample_MTM1M3_command_standby;


      salReturn putSample(MTM1M3::command_start_63435b30 data);
      salReturn getSample(MTM1M3::command_start_63435b30Seq data);
      salReturn putSample_command_start(MTM1M3_command_startC *data);
      salReturn getSample_command_start(MTM1M3_command_startC *data);
      salReturn getNextSample_command_start(MTM1M3_command_startC *data);
      salReturn flushSamples_command_start(MTM1M3_command_startC *data);
      salReturn getLastSample_command_start(MTM1M3_command_startC *data);
      MTM1M3_command_startC lastSample_MTM1M3_command_start;


      salReturn putSample(MTM1M3::command_stopHardpointMotion_727b2152 data);
      salReturn getSample(MTM1M3::command_stopHardpointMotion_727b2152Seq data);
      salReturn putSample_command_stopHardpointMotion(MTM1M3_command_stopHardpointMotionC *data);
      salReturn getSample_command_stopHardpointMotion(MTM1M3_command_stopHardpointMotionC *data);
      salReturn getNextSample_command_stopHardpointMotion(MTM1M3_command_stopHardpointMotionC *data);
      salReturn flushSamples_command_stopHardpointMotion(MTM1M3_command_stopHardpointMotionC *data);
      salReturn getLastSample_command_stopHardpointMotion(MTM1M3_command_stopHardpointMotionC *data);
      MTM1M3_command_stopHardpointMotionC lastSample_MTM1M3_command_stopHardpointMotion;


      salReturn putSample(MTM1M3::command_testAir_37cd327c data);
      salReturn getSample(MTM1M3::command_testAir_37cd327cSeq data);
      salReturn putSample_command_testAir(MTM1M3_command_testAirC *data);
      salReturn getSample_command_testAir(MTM1M3_command_testAirC *data);
      salReturn getNextSample_command_testAir(MTM1M3_command_testAirC *data);
      salReturn flushSamples_command_testAir(MTM1M3_command_testAirC *data);
      salReturn getLastSample_command_testAir(MTM1M3_command_testAirC *data);
      MTM1M3_command_testAirC lastSample_MTM1M3_command_testAir;


      salReturn putSample(MTM1M3::command_testForceActuator_f1a37131 data);
      salReturn getSample(MTM1M3::command_testForceActuator_f1a37131Seq data);
      salReturn putSample_command_testForceActuator(MTM1M3_command_testForceActuatorC *data);
      salReturn getSample_command_testForceActuator(MTM1M3_command_testForceActuatorC *data);
      salReturn getNextSample_command_testForceActuator(MTM1M3_command_testForceActuatorC *data);
      salReturn flushSamples_command_testForceActuator(MTM1M3_command_testForceActuatorC *data);
      salReturn getLastSample_command_testForceActuator(MTM1M3_command_testForceActuatorC *data);
      MTM1M3_command_testForceActuatorC lastSample_MTM1M3_command_testForceActuator;


      salReturn putSample(MTM1M3::command_testHardpoint_3736f433 data);
      salReturn getSample(MTM1M3::command_testHardpoint_3736f433Seq data);
      salReturn putSample_command_testHardpoint(MTM1M3_command_testHardpointC *data);
      salReturn getSample_command_testHardpoint(MTM1M3_command_testHardpointC *data);
      salReturn getNextSample_command_testHardpoint(MTM1M3_command_testHardpointC *data);
      salReturn flushSamples_command_testHardpoint(MTM1M3_command_testHardpointC *data);
      salReturn getLastSample_command_testHardpoint(MTM1M3_command_testHardpointC *data);
      MTM1M3_command_testHardpointC lastSample_MTM1M3_command_testHardpoint;


      salReturn putSample(MTM1M3::command_translateM1M3_4d0dfbfe data);
      salReturn getSample(MTM1M3::command_translateM1M3_4d0dfbfeSeq data);
      salReturn putSample_command_translateM1M3(MTM1M3_command_translateM1M3C *data);
      salReturn getSample_command_translateM1M3(MTM1M3_command_translateM1M3C *data);
      salReturn getNextSample_command_translateM1M3(MTM1M3_command_translateM1M3C *data);
      salReturn flushSamples_command_translateM1M3(MTM1M3_command_translateM1M3C *data);
      salReturn getLastSample_command_translateM1M3(MTM1M3_command_translateM1M3C *data);
      MTM1M3_command_translateM1M3C lastSample_MTM1M3_command_translateM1M3;


      salReturn putSample(MTM1M3::command_turnAirOff_1054819e data);
      salReturn getSample(MTM1M3::command_turnAirOff_1054819eSeq data);
      salReturn putSample_command_turnAirOff(MTM1M3_command_turnAirOffC *data);
      salReturn getSample_command_turnAirOff(MTM1M3_command_turnAirOffC *data);
      salReturn getNextSample_command_turnAirOff(MTM1M3_command_turnAirOffC *data);
      salReturn flushSamples_command_turnAirOff(MTM1M3_command_turnAirOffC *data);
      salReturn getLastSample_command_turnAirOff(MTM1M3_command_turnAirOffC *data);
      MTM1M3_command_turnAirOffC lastSample_MTM1M3_command_turnAirOff;


      salReturn putSample(MTM1M3::command_turnAirOn_acc6807c data);
      salReturn getSample(MTM1M3::command_turnAirOn_acc6807cSeq data);
      salReturn putSample_command_turnAirOn(MTM1M3_command_turnAirOnC *data);
      salReturn getSample_command_turnAirOn(MTM1M3_command_turnAirOnC *data);
      salReturn getNextSample_command_turnAirOn(MTM1M3_command_turnAirOnC *data);
      salReturn flushSamples_command_turnAirOn(MTM1M3_command_turnAirOnC *data);
      salReturn getLastSample_command_turnAirOn(MTM1M3_command_turnAirOnC *data);
      MTM1M3_command_turnAirOnC lastSample_MTM1M3_command_turnAirOn;


      salReturn putSample(MTM1M3::command_turnLightsOff_08b6e5a2 data);
      salReturn getSample(MTM1M3::command_turnLightsOff_08b6e5a2Seq data);
      salReturn putSample_command_turnLightsOff(MTM1M3_command_turnLightsOffC *data);
      salReturn getSample_command_turnLightsOff(MTM1M3_command_turnLightsOffC *data);
      salReturn getNextSample_command_turnLightsOff(MTM1M3_command_turnLightsOffC *data);
      salReturn flushSamples_command_turnLightsOff(MTM1M3_command_turnLightsOffC *data);
      salReturn getLastSample_command_turnLightsOff(MTM1M3_command_turnLightsOffC *data);
      MTM1M3_command_turnLightsOffC lastSample_MTM1M3_command_turnLightsOff;


      salReturn putSample(MTM1M3::command_turnLightsOn_89e80426 data);
      salReturn getSample(MTM1M3::command_turnLightsOn_89e80426Seq data);
      salReturn putSample_command_turnLightsOn(MTM1M3_command_turnLightsOnC *data);
      salReturn getSample_command_turnLightsOn(MTM1M3_command_turnLightsOnC *data);
      salReturn getNextSample_command_turnLightsOn(MTM1M3_command_turnLightsOnC *data);
      salReturn flushSamples_command_turnLightsOn(MTM1M3_command_turnLightsOnC *data);
      salReturn getLastSample_command_turnLightsOn(MTM1M3_command_turnLightsOnC *data);
      MTM1M3_command_turnLightsOnC lastSample_MTM1M3_command_turnLightsOn;


      salReturn putSample(MTM1M3::command_turnPowerOff_41dde1fd data);
      salReturn getSample(MTM1M3::command_turnPowerOff_41dde1fdSeq data);
      salReturn putSample_command_turnPowerOff(MTM1M3_command_turnPowerOffC *data);
      salReturn getSample_command_turnPowerOff(MTM1M3_command_turnPowerOffC *data);
      salReturn getNextSample_command_turnPowerOff(MTM1M3_command_turnPowerOffC *data);
      salReturn flushSamples_command_turnPowerOff(MTM1M3_command_turnPowerOffC *data);
      salReturn getLastSample_command_turnPowerOff(MTM1M3_command_turnPowerOffC *data);
      MTM1M3_command_turnPowerOffC lastSample_MTM1M3_command_turnPowerOff;


      salReturn putSample(MTM1M3::command_turnPowerOn_7c3fbe06 data);
      salReturn getSample(MTM1M3::command_turnPowerOn_7c3fbe06Seq data);
      salReturn putSample_command_turnPowerOn(MTM1M3_command_turnPowerOnC *data);
      salReturn getSample_command_turnPowerOn(MTM1M3_command_turnPowerOnC *data);
      salReturn getNextSample_command_turnPowerOn(MTM1M3_command_turnPowerOnC *data);
      salReturn flushSamples_command_turnPowerOn(MTM1M3_command_turnPowerOnC *data);
      salReturn getLastSample_command_turnPowerOn(MTM1M3_command_turnPowerOnC *data);
      MTM1M3_command_turnPowerOnC lastSample_MTM1M3_command_turnPowerOn;


      salReturn putSample(MTM1M3::command_updatePID_6e2af9f8 data);
      salReturn getSample(MTM1M3::command_updatePID_6e2af9f8Seq data);
      salReturn putSample_command_updatePID(MTM1M3_command_updatePIDC *data);
      salReturn getSample_command_updatePID(MTM1M3_command_updatePIDC *data);
      salReturn getNextSample_command_updatePID(MTM1M3_command_updatePIDC *data);
      salReturn flushSamples_command_updatePID(MTM1M3_command_updatePIDC *data);
      salReturn getLastSample_command_updatePID(MTM1M3_command_updatePIDC *data);
      MTM1M3_command_updatePIDC lastSample_MTM1M3_command_updatePID;


      salReturn putSample(MTM1M3::forceActuatorData_5d276d43 data);
      salReturn getSample(MTM1M3::forceActuatorData_5d276d43Seq data);
      salReturn putSample_forceActuatorData(MTM1M3_forceActuatorDataC *data);
      salReturn getSample_forceActuatorData(MTM1M3_forceActuatorDataC *data);
      salReturn getNextSample_forceActuatorData(MTM1M3_forceActuatorDataC *data);
      salReturn flushSamples_forceActuatorData(MTM1M3_forceActuatorDataC *data);
      salReturn getLastSample_forceActuatorData(MTM1M3_forceActuatorDataC *data);
      MTM1M3_forceActuatorDataC lastSample_MTM1M3_forceActuatorData;


      salReturn putSample(MTM1M3::gyroData_52effcca data);
      salReturn getSample(MTM1M3::gyroData_52effccaSeq data);
      salReturn putSample_gyroData(MTM1M3_gyroDataC *data);
      salReturn getSample_gyroData(MTM1M3_gyroDataC *data);
      salReturn getNextSample_gyroData(MTM1M3_gyroDataC *data);
      salReturn flushSamples_gyroData(MTM1M3_gyroDataC *data);
      salReturn getLastSample_gyroData(MTM1M3_gyroDataC *data);
      MTM1M3_gyroDataC lastSample_MTM1M3_gyroData;


      salReturn putSample(MTM1M3::hardpointActuatorData_e4c2857f data);
      salReturn getSample(MTM1M3::hardpointActuatorData_e4c2857fSeq data);
      salReturn putSample_hardpointActuatorData(MTM1M3_hardpointActuatorDataC *data);
      salReturn getSample_hardpointActuatorData(MTM1M3_hardpointActuatorDataC *data);
      salReturn getNextSample_hardpointActuatorData(MTM1M3_hardpointActuatorDataC *data);
      salReturn flushSamples_hardpointActuatorData(MTM1M3_hardpointActuatorDataC *data);
      salReturn getLastSample_hardpointActuatorData(MTM1M3_hardpointActuatorDataC *data);
      MTM1M3_hardpointActuatorDataC lastSample_MTM1M3_hardpointActuatorData;


      salReturn putSample(MTM1M3::hardpointMonitorData_8caedbd0 data);
      salReturn getSample(MTM1M3::hardpointMonitorData_8caedbd0Seq data);
      salReturn putSample_hardpointMonitorData(MTM1M3_hardpointMonitorDataC *data);
      salReturn getSample_hardpointMonitorData(MTM1M3_hardpointMonitorDataC *data);
      salReturn getNextSample_hardpointMonitorData(MTM1M3_hardpointMonitorDataC *data);
      salReturn flushSamples_hardpointMonitorData(MTM1M3_hardpointMonitorDataC *data);
      salReturn getLastSample_hardpointMonitorData(MTM1M3_hardpointMonitorDataC *data);
      MTM1M3_hardpointMonitorDataC lastSample_MTM1M3_hardpointMonitorData;


      salReturn putSample(MTM1M3::imsData_dd412900 data);
      salReturn getSample(MTM1M3::imsData_dd412900Seq data);
      salReturn putSample_imsData(MTM1M3_imsDataC *data);
      salReturn getSample_imsData(MTM1M3_imsDataC *data);
      salReturn getNextSample_imsData(MTM1M3_imsDataC *data);
      salReturn flushSamples_imsData(MTM1M3_imsDataC *data);
      salReturn getLastSample_imsData(MTM1M3_imsDataC *data);
      MTM1M3_imsDataC lastSample_MTM1M3_imsData;


      salReturn putSample(MTM1M3::inclinometerData_6233a3d3 data);
      salReturn getSample(MTM1M3::inclinometerData_6233a3d3Seq data);
      salReturn putSample_inclinometerData(MTM1M3_inclinometerDataC *data);
      salReturn getSample_inclinometerData(MTM1M3_inclinometerDataC *data);
      salReturn getNextSample_inclinometerData(MTM1M3_inclinometerDataC *data);
      salReturn flushSamples_inclinometerData(MTM1M3_inclinometerDataC *data);
      salReturn getLastSample_inclinometerData(MTM1M3_inclinometerDataC *data);
      MTM1M3_inclinometerDataC lastSample_MTM1M3_inclinometerData;


      salReturn putSample(MTM1M3::logevent_accelerometerWarning_aa15b0aa data);
      salReturn getSample(MTM1M3::logevent_accelerometerWarning_aa15b0aaSeq data);
      salReturn putSample_logevent_accelerometerWarning(MTM1M3_logevent_accelerometerWarningC *data);
      salReturn getSample_logevent_accelerometerWarning(MTM1M3_logevent_accelerometerWarningC *data);
      salReturn getNextSample_logevent_accelerometerWarning(MTM1M3_logevent_accelerometerWarningC *data);
      salReturn flushSamples_logevent_accelerometerWarning(MTM1M3_logevent_accelerometerWarningC *data);
      salReturn getLastSample_logevent_accelerometerWarning(MTM1M3_logevent_accelerometerWarningC *data);
      MTM1M3_logevent_accelerometerWarningC lastSample_MTM1M3_logevent_accelerometerWarning;


      salReturn putSample(MTM1M3::logevent_airSupplyStatus_da397eb1 data);
      salReturn getSample(MTM1M3::logevent_airSupplyStatus_da397eb1Seq data);
      salReturn putSample_logevent_airSupplyStatus(MTM1M3_logevent_airSupplyStatusC *data);
      salReturn getSample_logevent_airSupplyStatus(MTM1M3_logevent_airSupplyStatusC *data);
      salReturn getNextSample_logevent_airSupplyStatus(MTM1M3_logevent_airSupplyStatusC *data);
      salReturn flushSamples_logevent_airSupplyStatus(MTM1M3_logevent_airSupplyStatusC *data);
      salReturn getLastSample_logevent_airSupplyStatus(MTM1M3_logevent_airSupplyStatusC *data);
      MTM1M3_logevent_airSupplyStatusC lastSample_MTM1M3_logevent_airSupplyStatus;


      salReturn putSample(MTM1M3::logevent_airSupplyWarning_52167fbe data);
      salReturn getSample(MTM1M3::logevent_airSupplyWarning_52167fbeSeq data);
      salReturn putSample_logevent_airSupplyWarning(MTM1M3_logevent_airSupplyWarningC *data);
      salReturn getSample_logevent_airSupplyWarning(MTM1M3_logevent_airSupplyWarningC *data);
      salReturn getNextSample_logevent_airSupplyWarning(MTM1M3_logevent_airSupplyWarningC *data);
      salReturn flushSamples_logevent_airSupplyWarning(MTM1M3_logevent_airSupplyWarningC *data);
      salReturn getLastSample_logevent_airSupplyWarning(MTM1M3_logevent_airSupplyWarningC *data);
      MTM1M3_logevent_airSupplyWarningC lastSample_MTM1M3_logevent_airSupplyWarning;


      salReturn putSample(MTM1M3::logevent_appliedAberrationForces_d72ce7af data);
      salReturn getSample(MTM1M3::logevent_appliedAberrationForces_d72ce7afSeq data);
      salReturn putSample_logevent_appliedAberrationForces(MTM1M3_logevent_appliedAberrationForcesC *data);
      salReturn getSample_logevent_appliedAberrationForces(MTM1M3_logevent_appliedAberrationForcesC *data);
      salReturn getNextSample_logevent_appliedAberrationForces(MTM1M3_logevent_appliedAberrationForcesC *data);
      salReturn flushSamples_logevent_appliedAberrationForces(MTM1M3_logevent_appliedAberrationForcesC *data);
      salReturn getLastSample_logevent_appliedAberrationForces(MTM1M3_logevent_appliedAberrationForcesC *data);
      MTM1M3_logevent_appliedAberrationForcesC lastSample_MTM1M3_logevent_appliedAberrationForces;


      salReturn putSample(MTM1M3::logevent_appliedAccelerationForces_e2698a2b data);
      salReturn getSample(MTM1M3::logevent_appliedAccelerationForces_e2698a2bSeq data);
      salReturn putSample_logevent_appliedAccelerationForces(MTM1M3_logevent_appliedAccelerationForcesC *data);
      salReturn getSample_logevent_appliedAccelerationForces(MTM1M3_logevent_appliedAccelerationForcesC *data);
      salReturn getNextSample_logevent_appliedAccelerationForces(MTM1M3_logevent_appliedAccelerationForcesC *data);
      salReturn flushSamples_logevent_appliedAccelerationForces(MTM1M3_logevent_appliedAccelerationForcesC *data);
      salReturn getLastSample_logevent_appliedAccelerationForces(MTM1M3_logevent_appliedAccelerationForcesC *data);
      MTM1M3_logevent_appliedAccelerationForcesC lastSample_MTM1M3_logevent_appliedAccelerationForces;


      salReturn putSample(MTM1M3::logevent_appliedActiveOpticForces_4f827b4b data);
      salReturn getSample(MTM1M3::logevent_appliedActiveOpticForces_4f827b4bSeq data);
      salReturn putSample_logevent_appliedActiveOpticForces(MTM1M3_logevent_appliedActiveOpticForcesC *data);
      salReturn getSample_logevent_appliedActiveOpticForces(MTM1M3_logevent_appliedActiveOpticForcesC *data);
      salReturn getNextSample_logevent_appliedActiveOpticForces(MTM1M3_logevent_appliedActiveOpticForcesC *data);
      salReturn flushSamples_logevent_appliedActiveOpticForces(MTM1M3_logevent_appliedActiveOpticForcesC *data);
      salReturn getLastSample_logevent_appliedActiveOpticForces(MTM1M3_logevent_appliedActiveOpticForcesC *data);
      MTM1M3_logevent_appliedActiveOpticForcesC lastSample_MTM1M3_logevent_appliedActiveOpticForces;


      salReturn putSample(MTM1M3::logevent_appliedAzimuthForces_7357e272 data);
      salReturn getSample(MTM1M3::logevent_appliedAzimuthForces_7357e272Seq data);
      salReturn putSample_logevent_appliedAzimuthForces(MTM1M3_logevent_appliedAzimuthForcesC *data);
      salReturn getSample_logevent_appliedAzimuthForces(MTM1M3_logevent_appliedAzimuthForcesC *data);
      salReturn getNextSample_logevent_appliedAzimuthForces(MTM1M3_logevent_appliedAzimuthForcesC *data);
      salReturn flushSamples_logevent_appliedAzimuthForces(MTM1M3_logevent_appliedAzimuthForcesC *data);
      salReturn getLastSample_logevent_appliedAzimuthForces(MTM1M3_logevent_appliedAzimuthForcesC *data);
      MTM1M3_logevent_appliedAzimuthForcesC lastSample_MTM1M3_logevent_appliedAzimuthForces;


      salReturn putSample(MTM1M3::logevent_appliedBalanceForces_3f4cca0a data);
      salReturn getSample(MTM1M3::logevent_appliedBalanceForces_3f4cca0aSeq data);
      salReturn putSample_logevent_appliedBalanceForces(MTM1M3_logevent_appliedBalanceForcesC *data);
      salReturn getSample_logevent_appliedBalanceForces(MTM1M3_logevent_appliedBalanceForcesC *data);
      salReturn getNextSample_logevent_appliedBalanceForces(MTM1M3_logevent_appliedBalanceForcesC *data);
      salReturn flushSamples_logevent_appliedBalanceForces(MTM1M3_logevent_appliedBalanceForcesC *data);
      salReturn getLastSample_logevent_appliedBalanceForces(MTM1M3_logevent_appliedBalanceForcesC *data);
      MTM1M3_logevent_appliedBalanceForcesC lastSample_MTM1M3_logevent_appliedBalanceForces;


      salReturn putSample(MTM1M3::logevent_appliedCylinderForces_b0d7e6d8 data);
      salReturn getSample(MTM1M3::logevent_appliedCylinderForces_b0d7e6d8Seq data);
      salReturn putSample_logevent_appliedCylinderForces(MTM1M3_logevent_appliedCylinderForcesC *data);
      salReturn getSample_logevent_appliedCylinderForces(MTM1M3_logevent_appliedCylinderForcesC *data);
      salReturn getNextSample_logevent_appliedCylinderForces(MTM1M3_logevent_appliedCylinderForcesC *data);
      salReturn flushSamples_logevent_appliedCylinderForces(MTM1M3_logevent_appliedCylinderForcesC *data);
      salReturn getLastSample_logevent_appliedCylinderForces(MTM1M3_logevent_appliedCylinderForcesC *data);
      MTM1M3_logevent_appliedCylinderForcesC lastSample_MTM1M3_logevent_appliedCylinderForces;


      salReturn putSample(MTM1M3::logevent_appliedElevationForces_fa715255 data);
      salReturn getSample(MTM1M3::logevent_appliedElevationForces_fa715255Seq data);
      salReturn putSample_logevent_appliedElevationForces(MTM1M3_logevent_appliedElevationForcesC *data);
      salReturn getSample_logevent_appliedElevationForces(MTM1M3_logevent_appliedElevationForcesC *data);
      salReturn getNextSample_logevent_appliedElevationForces(MTM1M3_logevent_appliedElevationForcesC *data);
      salReturn flushSamples_logevent_appliedElevationForces(MTM1M3_logevent_appliedElevationForcesC *data);
      salReturn getLastSample_logevent_appliedElevationForces(MTM1M3_logevent_appliedElevationForcesC *data);
      MTM1M3_logevent_appliedElevationForcesC lastSample_MTM1M3_logevent_appliedElevationForces;


      salReturn putSample(MTM1M3::logevent_appliedForces_1d16999d data);
      salReturn getSample(MTM1M3::logevent_appliedForces_1d16999dSeq data);
      salReturn putSample_logevent_appliedForces(MTM1M3_logevent_appliedForcesC *data);
      salReturn getSample_logevent_appliedForces(MTM1M3_logevent_appliedForcesC *data);
      salReturn getNextSample_logevent_appliedForces(MTM1M3_logevent_appliedForcesC *data);
      salReturn flushSamples_logevent_appliedForces(MTM1M3_logevent_appliedForcesC *data);
      salReturn getLastSample_logevent_appliedForces(MTM1M3_logevent_appliedForcesC *data);
      MTM1M3_logevent_appliedForcesC lastSample_MTM1M3_logevent_appliedForces;


      salReturn putSample(MTM1M3::logevent_appliedOffsetForces_f19befd6 data);
      salReturn getSample(MTM1M3::logevent_appliedOffsetForces_f19befd6Seq data);
      salReturn putSample_logevent_appliedOffsetForces(MTM1M3_logevent_appliedOffsetForcesC *data);
      salReturn getSample_logevent_appliedOffsetForces(MTM1M3_logevent_appliedOffsetForcesC *data);
      salReturn getNextSample_logevent_appliedOffsetForces(MTM1M3_logevent_appliedOffsetForcesC *data);
      salReturn flushSamples_logevent_appliedOffsetForces(MTM1M3_logevent_appliedOffsetForcesC *data);
      salReturn getLastSample_logevent_appliedOffsetForces(MTM1M3_logevent_appliedOffsetForcesC *data);
      MTM1M3_logevent_appliedOffsetForcesC lastSample_MTM1M3_logevent_appliedOffsetForces;


      salReturn putSample(MTM1M3::logevent_appliedSettingsMatchStart_30ba5c59 data);
      salReturn getSample(MTM1M3::logevent_appliedSettingsMatchStart_30ba5c59Seq data);
      salReturn putSample_logevent_appliedSettingsMatchStart(MTM1M3_logevent_appliedSettingsMatchStartC *data);
      salReturn getSample_logevent_appliedSettingsMatchStart(MTM1M3_logevent_appliedSettingsMatchStartC *data);
      salReturn getNextSample_logevent_appliedSettingsMatchStart(MTM1M3_logevent_appliedSettingsMatchStartC *data);
      salReturn flushSamples_logevent_appliedSettingsMatchStart(MTM1M3_logevent_appliedSettingsMatchStartC *data);
      salReturn getLastSample_logevent_appliedSettingsMatchStart(MTM1M3_logevent_appliedSettingsMatchStartC *data);
      MTM1M3_logevent_appliedSettingsMatchStartC lastSample_MTM1M3_logevent_appliedSettingsMatchStart;


      salReturn putSample(MTM1M3::logevent_appliedStaticForces_b210fd2d data);
      salReturn getSample(MTM1M3::logevent_appliedStaticForces_b210fd2dSeq data);
      salReturn putSample_logevent_appliedStaticForces(MTM1M3_logevent_appliedStaticForcesC *data);
      salReturn getSample_logevent_appliedStaticForces(MTM1M3_logevent_appliedStaticForcesC *data);
      salReturn getNextSample_logevent_appliedStaticForces(MTM1M3_logevent_appliedStaticForcesC *data);
      salReturn flushSamples_logevent_appliedStaticForces(MTM1M3_logevent_appliedStaticForcesC *data);
      salReturn getLastSample_logevent_appliedStaticForces(MTM1M3_logevent_appliedStaticForcesC *data);
      MTM1M3_logevent_appliedStaticForcesC lastSample_MTM1M3_logevent_appliedStaticForces;


      salReturn putSample(MTM1M3::logevent_appliedThermalForces_ee191da4 data);
      salReturn getSample(MTM1M3::logevent_appliedThermalForces_ee191da4Seq data);
      salReturn putSample_logevent_appliedThermalForces(MTM1M3_logevent_appliedThermalForcesC *data);
      salReturn getSample_logevent_appliedThermalForces(MTM1M3_logevent_appliedThermalForcesC *data);
      salReturn getNextSample_logevent_appliedThermalForces(MTM1M3_logevent_appliedThermalForcesC *data);
      salReturn flushSamples_logevent_appliedThermalForces(MTM1M3_logevent_appliedThermalForcesC *data);
      salReturn getLastSample_logevent_appliedThermalForces(MTM1M3_logevent_appliedThermalForcesC *data);
      MTM1M3_logevent_appliedThermalForcesC lastSample_MTM1M3_logevent_appliedThermalForces;


      salReturn putSample(MTM1M3::logevent_appliedVelocityForces_88f33d5e data);
      salReturn getSample(MTM1M3::logevent_appliedVelocityForces_88f33d5eSeq data);
      salReturn putSample_logevent_appliedVelocityForces(MTM1M3_logevent_appliedVelocityForcesC *data);
      salReturn getSample_logevent_appliedVelocityForces(MTM1M3_logevent_appliedVelocityForcesC *data);
      salReturn getNextSample_logevent_appliedVelocityForces(MTM1M3_logevent_appliedVelocityForcesC *data);
      salReturn flushSamples_logevent_appliedVelocityForces(MTM1M3_logevent_appliedVelocityForcesC *data);
      salReturn getLastSample_logevent_appliedVelocityForces(MTM1M3_logevent_appliedVelocityForcesC *data);
      MTM1M3_logevent_appliedVelocityForcesC lastSample_MTM1M3_logevent_appliedVelocityForces;


      salReturn putSample(MTM1M3::logevent_cellLightStatus_2a963d17 data);
      salReturn getSample(MTM1M3::logevent_cellLightStatus_2a963d17Seq data);
      salReturn putSample_logevent_cellLightStatus(MTM1M3_logevent_cellLightStatusC *data);
      salReturn getSample_logevent_cellLightStatus(MTM1M3_logevent_cellLightStatusC *data);
      salReturn getNextSample_logevent_cellLightStatus(MTM1M3_logevent_cellLightStatusC *data);
      salReturn flushSamples_logevent_cellLightStatus(MTM1M3_logevent_cellLightStatusC *data);
      salReturn getLastSample_logevent_cellLightStatus(MTM1M3_logevent_cellLightStatusC *data);
      MTM1M3_logevent_cellLightStatusC lastSample_MTM1M3_logevent_cellLightStatus;


      salReturn putSample(MTM1M3::logevent_cellLightWarning_0610a3a7 data);
      salReturn getSample(MTM1M3::logevent_cellLightWarning_0610a3a7Seq data);
      salReturn putSample_logevent_cellLightWarning(MTM1M3_logevent_cellLightWarningC *data);
      salReturn getSample_logevent_cellLightWarning(MTM1M3_logevent_cellLightWarningC *data);
      salReturn getNextSample_logevent_cellLightWarning(MTM1M3_logevent_cellLightWarningC *data);
      salReturn flushSamples_logevent_cellLightWarning(MTM1M3_logevent_cellLightWarningC *data);
      salReturn getLastSample_logevent_cellLightWarning(MTM1M3_logevent_cellLightWarningC *data);
      MTM1M3_logevent_cellLightWarningC lastSample_MTM1M3_logevent_cellLightWarning;


      salReturn putSample(MTM1M3::logevent_commandRejectionWarning_2445d185 data);
      salReturn getSample(MTM1M3::logevent_commandRejectionWarning_2445d185Seq data);
      salReturn putSample_logevent_commandRejectionWarning(MTM1M3_logevent_commandRejectionWarningC *data);
      salReturn getSample_logevent_commandRejectionWarning(MTM1M3_logevent_commandRejectionWarningC *data);
      salReturn getNextSample_logevent_commandRejectionWarning(MTM1M3_logevent_commandRejectionWarningC *data);
      salReturn flushSamples_logevent_commandRejectionWarning(MTM1M3_logevent_commandRejectionWarningC *data);
      salReturn getLastSample_logevent_commandRejectionWarning(MTM1M3_logevent_commandRejectionWarningC *data);
      MTM1M3_logevent_commandRejectionWarningC lastSample_MTM1M3_logevent_commandRejectionWarning;


      salReturn putSample(MTM1M3::logevent_detailedState_72060c57 data);
      salReturn getSample(MTM1M3::logevent_detailedState_72060c57Seq data);
      salReturn putSample_logevent_detailedState(MTM1M3_logevent_detailedStateC *data);
      salReturn getSample_logevent_detailedState(MTM1M3_logevent_detailedStateC *data);
      salReturn getNextSample_logevent_detailedState(MTM1M3_logevent_detailedStateC *data);
      salReturn flushSamples_logevent_detailedState(MTM1M3_logevent_detailedStateC *data);
      salReturn getLastSample_logevent_detailedState(MTM1M3_logevent_detailedStateC *data);
      MTM1M3_logevent_detailedStateC lastSample_MTM1M3_logevent_detailedState;


      salReturn putSample(MTM1M3::logevent_displacementSensorWarning_1035d8b2 data);
      salReturn getSample(MTM1M3::logevent_displacementSensorWarning_1035d8b2Seq data);
      salReturn putSample_logevent_displacementSensorWarning(MTM1M3_logevent_displacementSensorWarningC *data);
      salReturn getSample_logevent_displacementSensorWarning(MTM1M3_logevent_displacementSensorWarningC *data);
      salReturn getNextSample_logevent_displacementSensorWarning(MTM1M3_logevent_displacementSensorWarningC *data);
      salReturn flushSamples_logevent_displacementSensorWarning(MTM1M3_logevent_displacementSensorWarningC *data);
      salReturn getLastSample_logevent_displacementSensorWarning(MTM1M3_logevent_displacementSensorWarningC *data);
      MTM1M3_logevent_displacementSensorWarningC lastSample_MTM1M3_logevent_displacementSensorWarning;


      salReturn putSample(MTM1M3::logevent_errorCode_8bce170e data);
      salReturn getSample(MTM1M3::logevent_errorCode_8bce170eSeq data);
      salReturn putSample_logevent_errorCode(MTM1M3_logevent_errorCodeC *data);
      salReturn getSample_logevent_errorCode(MTM1M3_logevent_errorCodeC *data);
      salReturn getNextSample_logevent_errorCode(MTM1M3_logevent_errorCodeC *data);
      salReturn flushSamples_logevent_errorCode(MTM1M3_logevent_errorCodeC *data);
      salReturn getLastSample_logevent_errorCode(MTM1M3_logevent_errorCodeC *data);
      MTM1M3_logevent_errorCodeC lastSample_MTM1M3_logevent_errorCode;


      salReturn putSample(MTM1M3::logevent_forceActuatorForceWarning_3a01ad1f data);
      salReturn getSample(MTM1M3::logevent_forceActuatorForceWarning_3a01ad1fSeq data);
      salReturn putSample_logevent_forceActuatorForceWarning(MTM1M3_logevent_forceActuatorForceWarningC *data);
      salReturn getSample_logevent_forceActuatorForceWarning(MTM1M3_logevent_forceActuatorForceWarningC *data);
      salReturn getNextSample_logevent_forceActuatorForceWarning(MTM1M3_logevent_forceActuatorForceWarningC *data);
      salReturn flushSamples_logevent_forceActuatorForceWarning(MTM1M3_logevent_forceActuatorForceWarningC *data);
      salReturn getLastSample_logevent_forceActuatorForceWarning(MTM1M3_logevent_forceActuatorForceWarningC *data);
      MTM1M3_logevent_forceActuatorForceWarningC lastSample_MTM1M3_logevent_forceActuatorForceWarning;


      salReturn putSample(MTM1M3::logevent_forceActuatorInfo_d0ebe0c5 data);
      salReturn getSample(MTM1M3::logevent_forceActuatorInfo_d0ebe0c5Seq data);
      salReturn putSample_logevent_forceActuatorInfo(MTM1M3_logevent_forceActuatorInfoC *data);
      salReturn getSample_logevent_forceActuatorInfo(MTM1M3_logevent_forceActuatorInfoC *data);
      salReturn getNextSample_logevent_forceActuatorInfo(MTM1M3_logevent_forceActuatorInfoC *data);
      salReturn flushSamples_logevent_forceActuatorInfo(MTM1M3_logevent_forceActuatorInfoC *data);
      salReturn getLastSample_logevent_forceActuatorInfo(MTM1M3_logevent_forceActuatorInfoC *data);
      MTM1M3_logevent_forceActuatorInfoC lastSample_MTM1M3_logevent_forceActuatorInfo;


      salReturn putSample(MTM1M3::logevent_forceActuatorState_028222bb data);
      salReturn getSample(MTM1M3::logevent_forceActuatorState_028222bbSeq data);
      salReturn putSample_logevent_forceActuatorState(MTM1M3_logevent_forceActuatorStateC *data);
      salReturn getSample_logevent_forceActuatorState(MTM1M3_logevent_forceActuatorStateC *data);
      salReturn getNextSample_logevent_forceActuatorState(MTM1M3_logevent_forceActuatorStateC *data);
      salReturn flushSamples_logevent_forceActuatorState(MTM1M3_logevent_forceActuatorStateC *data);
      salReturn getLastSample_logevent_forceActuatorState(MTM1M3_logevent_forceActuatorStateC *data);
      MTM1M3_logevent_forceActuatorStateC lastSample_MTM1M3_logevent_forceActuatorState;


      salReturn putSample(MTM1M3::logevent_forceActuatorWarning_34b69bc9 data);
      salReturn getSample(MTM1M3::logevent_forceActuatorWarning_34b69bc9Seq data);
      salReturn putSample_logevent_forceActuatorWarning(MTM1M3_logevent_forceActuatorWarningC *data);
      salReturn getSample_logevent_forceActuatorWarning(MTM1M3_logevent_forceActuatorWarningC *data);
      salReturn getNextSample_logevent_forceActuatorWarning(MTM1M3_logevent_forceActuatorWarningC *data);
      salReturn flushSamples_logevent_forceActuatorWarning(MTM1M3_logevent_forceActuatorWarningC *data);
      salReturn getLastSample_logevent_forceActuatorWarning(MTM1M3_logevent_forceActuatorWarningC *data);
      MTM1M3_logevent_forceActuatorWarningC lastSample_MTM1M3_logevent_forceActuatorWarning;


      salReturn putSample(MTM1M3::logevent_forceSetpointWarning_34a43cf6 data);
      salReturn getSample(MTM1M3::logevent_forceSetpointWarning_34a43cf6Seq data);
      salReturn putSample_logevent_forceSetpointWarning(MTM1M3_logevent_forceSetpointWarningC *data);
      salReturn getSample_logevent_forceSetpointWarning(MTM1M3_logevent_forceSetpointWarningC *data);
      salReturn getNextSample_logevent_forceSetpointWarning(MTM1M3_logevent_forceSetpointWarningC *data);
      salReturn flushSamples_logevent_forceSetpointWarning(MTM1M3_logevent_forceSetpointWarningC *data);
      salReturn getLastSample_logevent_forceSetpointWarning(MTM1M3_logevent_forceSetpointWarningC *data);
      MTM1M3_logevent_forceSetpointWarningC lastSample_MTM1M3_logevent_forceSetpointWarning;


      salReturn putSample(MTM1M3::logevent_gyroWarning_07c44e13 data);
      salReturn getSample(MTM1M3::logevent_gyroWarning_07c44e13Seq data);
      salReturn putSample_logevent_gyroWarning(MTM1M3_logevent_gyroWarningC *data);
      salReturn getSample_logevent_gyroWarning(MTM1M3_logevent_gyroWarningC *data);
      salReturn getNextSample_logevent_gyroWarning(MTM1M3_logevent_gyroWarningC *data);
      salReturn flushSamples_logevent_gyroWarning(MTM1M3_logevent_gyroWarningC *data);
      salReturn getLastSample_logevent_gyroWarning(MTM1M3_logevent_gyroWarningC *data);
      MTM1M3_logevent_gyroWarningC lastSample_MTM1M3_logevent_gyroWarning;


      salReturn putSample(MTM1M3::logevent_hardpointActuatorInfo_d713e706 data);
      salReturn getSample(MTM1M3::logevent_hardpointActuatorInfo_d713e706Seq data);
      salReturn putSample_logevent_hardpointActuatorInfo(MTM1M3_logevent_hardpointActuatorInfoC *data);
      salReturn getSample_logevent_hardpointActuatorInfo(MTM1M3_logevent_hardpointActuatorInfoC *data);
      salReturn getNextSample_logevent_hardpointActuatorInfo(MTM1M3_logevent_hardpointActuatorInfoC *data);
      salReturn flushSamples_logevent_hardpointActuatorInfo(MTM1M3_logevent_hardpointActuatorInfoC *data);
      salReturn getLastSample_logevent_hardpointActuatorInfo(MTM1M3_logevent_hardpointActuatorInfoC *data);
      MTM1M3_logevent_hardpointActuatorInfoC lastSample_MTM1M3_logevent_hardpointActuatorInfo;


      salReturn putSample(MTM1M3::logevent_hardpointActuatorState_dfd8f788 data);
      salReturn getSample(MTM1M3::logevent_hardpointActuatorState_dfd8f788Seq data);
      salReturn putSample_logevent_hardpointActuatorState(MTM1M3_logevent_hardpointActuatorStateC *data);
      salReturn getSample_logevent_hardpointActuatorState(MTM1M3_logevent_hardpointActuatorStateC *data);
      salReturn getNextSample_logevent_hardpointActuatorState(MTM1M3_logevent_hardpointActuatorStateC *data);
      salReturn flushSamples_logevent_hardpointActuatorState(MTM1M3_logevent_hardpointActuatorStateC *data);
      salReturn getLastSample_logevent_hardpointActuatorState(MTM1M3_logevent_hardpointActuatorStateC *data);
      MTM1M3_logevent_hardpointActuatorStateC lastSample_MTM1M3_logevent_hardpointActuatorState;


      salReturn putSample(MTM1M3::logevent_hardpointActuatorWarning_dcc7d946 data);
      salReturn getSample(MTM1M3::logevent_hardpointActuatorWarning_dcc7d946Seq data);
      salReturn putSample_logevent_hardpointActuatorWarning(MTM1M3_logevent_hardpointActuatorWarningC *data);
      salReturn getSample_logevent_hardpointActuatorWarning(MTM1M3_logevent_hardpointActuatorWarningC *data);
      salReturn getNextSample_logevent_hardpointActuatorWarning(MTM1M3_logevent_hardpointActuatorWarningC *data);
      salReturn flushSamples_logevent_hardpointActuatorWarning(MTM1M3_logevent_hardpointActuatorWarningC *data);
      salReturn getLastSample_logevent_hardpointActuatorWarning(MTM1M3_logevent_hardpointActuatorWarningC *data);
      MTM1M3_logevent_hardpointActuatorWarningC lastSample_MTM1M3_logevent_hardpointActuatorWarning;


      salReturn putSample(MTM1M3::logevent_hardpointMonitorInfo_5dc92c27 data);
      salReturn getSample(MTM1M3::logevent_hardpointMonitorInfo_5dc92c27Seq data);
      salReturn putSample_logevent_hardpointMonitorInfo(MTM1M3_logevent_hardpointMonitorInfoC *data);
      salReturn getSample_logevent_hardpointMonitorInfo(MTM1M3_logevent_hardpointMonitorInfoC *data);
      salReturn getNextSample_logevent_hardpointMonitorInfo(MTM1M3_logevent_hardpointMonitorInfoC *data);
      salReturn flushSamples_logevent_hardpointMonitorInfo(MTM1M3_logevent_hardpointMonitorInfoC *data);
      salReturn getLastSample_logevent_hardpointMonitorInfo(MTM1M3_logevent_hardpointMonitorInfoC *data);
      MTM1M3_logevent_hardpointMonitorInfoC lastSample_MTM1M3_logevent_hardpointMonitorInfo;


      salReturn putSample(MTM1M3::logevent_hardpointMonitorState_0dad41d1 data);
      salReturn getSample(MTM1M3::logevent_hardpointMonitorState_0dad41d1Seq data);
      salReturn putSample_logevent_hardpointMonitorState(MTM1M3_logevent_hardpointMonitorStateC *data);
      salReturn getSample_logevent_hardpointMonitorState(MTM1M3_logevent_hardpointMonitorStateC *data);
      salReturn getNextSample_logevent_hardpointMonitorState(MTM1M3_logevent_hardpointMonitorStateC *data);
      salReturn flushSamples_logevent_hardpointMonitorState(MTM1M3_logevent_hardpointMonitorStateC *data);
      salReturn getLastSample_logevent_hardpointMonitorState(MTM1M3_logevent_hardpointMonitorStateC *data);
      MTM1M3_logevent_hardpointMonitorStateC lastSample_MTM1M3_logevent_hardpointMonitorState;


      salReturn putSample(MTM1M3::logevent_hardpointMonitorWarning_d5ab85e8 data);
      salReturn getSample(MTM1M3::logevent_hardpointMonitorWarning_d5ab85e8Seq data);
      salReturn putSample_logevent_hardpointMonitorWarning(MTM1M3_logevent_hardpointMonitorWarningC *data);
      salReturn getSample_logevent_hardpointMonitorWarning(MTM1M3_logevent_hardpointMonitorWarningC *data);
      salReturn getNextSample_logevent_hardpointMonitorWarning(MTM1M3_logevent_hardpointMonitorWarningC *data);
      salReturn flushSamples_logevent_hardpointMonitorWarning(MTM1M3_logevent_hardpointMonitorWarningC *data);
      salReturn getLastSample_logevent_hardpointMonitorWarning(MTM1M3_logevent_hardpointMonitorWarningC *data);
      MTM1M3_logevent_hardpointMonitorWarningC lastSample_MTM1M3_logevent_hardpointMonitorWarning;


      salReturn putSample(MTM1M3::logevent_heartbeat_85347670 data);
      salReturn getSample(MTM1M3::logevent_heartbeat_85347670Seq data);
      salReturn putSample_logevent_heartbeat(MTM1M3_logevent_heartbeatC *data);
      salReturn getSample_logevent_heartbeat(MTM1M3_logevent_heartbeatC *data);
      salReturn getNextSample_logevent_heartbeat(MTM1M3_logevent_heartbeatC *data);
      salReturn flushSamples_logevent_heartbeat(MTM1M3_logevent_heartbeatC *data);
      salReturn getLastSample_logevent_heartbeat(MTM1M3_logevent_heartbeatC *data);
      MTM1M3_logevent_heartbeatC lastSample_MTM1M3_logevent_heartbeat;


      salReturn putSample(MTM1M3::logevent_ilcWarning_22b9286f data);
      salReturn getSample(MTM1M3::logevent_ilcWarning_22b9286fSeq data);
      salReturn putSample_logevent_ilcWarning(MTM1M3_logevent_ilcWarningC *data);
      salReturn getSample_logevent_ilcWarning(MTM1M3_logevent_ilcWarningC *data);
      salReturn getNextSample_logevent_ilcWarning(MTM1M3_logevent_ilcWarningC *data);
      salReturn flushSamples_logevent_ilcWarning(MTM1M3_logevent_ilcWarningC *data);
      salReturn getLastSample_logevent_ilcWarning(MTM1M3_logevent_ilcWarningC *data);
      MTM1M3_logevent_ilcWarningC lastSample_MTM1M3_logevent_ilcWarning;


      salReturn putSample(MTM1M3::logevent_inclinometerSensorWarning_4d115eb8 data);
      salReturn getSample(MTM1M3::logevent_inclinometerSensorWarning_4d115eb8Seq data);
      salReturn putSample_logevent_inclinometerSensorWarning(MTM1M3_logevent_inclinometerSensorWarningC *data);
      salReturn getSample_logevent_inclinometerSensorWarning(MTM1M3_logevent_inclinometerSensorWarningC *data);
      salReturn getNextSample_logevent_inclinometerSensorWarning(MTM1M3_logevent_inclinometerSensorWarningC *data);
      salReturn flushSamples_logevent_inclinometerSensorWarning(MTM1M3_logevent_inclinometerSensorWarningC *data);
      salReturn getLastSample_logevent_inclinometerSensorWarning(MTM1M3_logevent_inclinometerSensorWarningC *data);
      MTM1M3_logevent_inclinometerSensorWarningC lastSample_MTM1M3_logevent_inclinometerSensorWarning;


      salReturn putSample(MTM1M3::logevent_interlockStatus_5c0ae7f7 data);
      salReturn getSample(MTM1M3::logevent_interlockStatus_5c0ae7f7Seq data);
      salReturn putSample_logevent_interlockStatus(MTM1M3_logevent_interlockStatusC *data);
      salReturn getSample_logevent_interlockStatus(MTM1M3_logevent_interlockStatusC *data);
      salReturn getNextSample_logevent_interlockStatus(MTM1M3_logevent_interlockStatusC *data);
      salReturn flushSamples_logevent_interlockStatus(MTM1M3_logevent_interlockStatusC *data);
      salReturn getLastSample_logevent_interlockStatus(MTM1M3_logevent_interlockStatusC *data);
      MTM1M3_logevent_interlockStatusC lastSample_MTM1M3_logevent_interlockStatus;


      salReturn putSample(MTM1M3::logevent_interlockWarning_bc69e2ea data);
      salReturn getSample(MTM1M3::logevent_interlockWarning_bc69e2eaSeq data);
      salReturn putSample_logevent_interlockWarning(MTM1M3_logevent_interlockWarningC *data);
      salReturn getSample_logevent_interlockWarning(MTM1M3_logevent_interlockWarningC *data);
      salReturn getNextSample_logevent_interlockWarning(MTM1M3_logevent_interlockWarningC *data);
      salReturn flushSamples_logevent_interlockWarning(MTM1M3_logevent_interlockWarningC *data);
      salReturn getLastSample_logevent_interlockWarning(MTM1M3_logevent_interlockWarningC *data);
      MTM1M3_logevent_interlockWarningC lastSample_MTM1M3_logevent_interlockWarning;


      salReturn putSample(MTM1M3::logevent_logLevel_83d14d18 data);
      salReturn getSample(MTM1M3::logevent_logLevel_83d14d18Seq data);
      salReturn putSample_logevent_logLevel(MTM1M3_logevent_logLevelC *data);
      salReturn getSample_logevent_logLevel(MTM1M3_logevent_logLevelC *data);
      salReturn getNextSample_logevent_logLevel(MTM1M3_logevent_logLevelC *data);
      salReturn flushSamples_logevent_logLevel(MTM1M3_logevent_logLevelC *data);
      salReturn getLastSample_logevent_logLevel(MTM1M3_logevent_logLevelC *data);
      MTM1M3_logevent_logLevelC lastSample_MTM1M3_logevent_logLevel;


      salReturn putSample(MTM1M3::logevent_logMessage_60a1ee35 data);
      salReturn getSample(MTM1M3::logevent_logMessage_60a1ee35Seq data);
      salReturn putSample_logevent_logMessage(MTM1M3_logevent_logMessageC *data);
      salReturn getSample_logevent_logMessage(MTM1M3_logevent_logMessageC *data);
      salReturn getNextSample_logevent_logMessage(MTM1M3_logevent_logMessageC *data);
      salReturn flushSamples_logevent_logMessage(MTM1M3_logevent_logMessageC *data);
      salReturn getLastSample_logevent_logMessage(MTM1M3_logevent_logMessageC *data);
      MTM1M3_logevent_logMessageC lastSample_MTM1M3_logevent_logMessage;


      salReturn putSample(MTM1M3::logevent_modbusResponse_9c022b06 data);
      salReturn getSample(MTM1M3::logevent_modbusResponse_9c022b06Seq data);
      salReturn putSample_logevent_modbusResponse(MTM1M3_logevent_modbusResponseC *data);
      salReturn getSample_logevent_modbusResponse(MTM1M3_logevent_modbusResponseC *data);
      salReturn getNextSample_logevent_modbusResponse(MTM1M3_logevent_modbusResponseC *data);
      salReturn flushSamples_logevent_modbusResponse(MTM1M3_logevent_modbusResponseC *data);
      salReturn getLastSample_logevent_modbusResponse(MTM1M3_logevent_modbusResponseC *data);
      MTM1M3_logevent_modbusResponseC lastSample_MTM1M3_logevent_modbusResponse;


      salReturn putSample(MTM1M3::logevent_pidInfo_858eca99 data);
      salReturn getSample(MTM1M3::logevent_pidInfo_858eca99Seq data);
      salReturn putSample_logevent_pidInfo(MTM1M3_logevent_pidInfoC *data);
      salReturn getSample_logevent_pidInfo(MTM1M3_logevent_pidInfoC *data);
      salReturn getNextSample_logevent_pidInfo(MTM1M3_logevent_pidInfoC *data);
      salReturn flushSamples_logevent_pidInfo(MTM1M3_logevent_pidInfoC *data);
      salReturn getLastSample_logevent_pidInfo(MTM1M3_logevent_pidInfoC *data);
      MTM1M3_logevent_pidInfoC lastSample_MTM1M3_logevent_pidInfo;


      salReturn putSample(MTM1M3::logevent_powerStatus_846d5845 data);
      salReturn getSample(MTM1M3::logevent_powerStatus_846d5845Seq data);
      salReturn putSample_logevent_powerStatus(MTM1M3_logevent_powerStatusC *data);
      salReturn getSample_logevent_powerStatus(MTM1M3_logevent_powerStatusC *data);
      salReturn getNextSample_logevent_powerStatus(MTM1M3_logevent_powerStatusC *data);
      salReturn flushSamples_logevent_powerStatus(MTM1M3_logevent_powerStatusC *data);
      salReturn getLastSample_logevent_powerStatus(MTM1M3_logevent_powerStatusC *data);
      MTM1M3_logevent_powerStatusC lastSample_MTM1M3_logevent_powerStatus;


      salReturn putSample(MTM1M3::logevent_powerSupplyStatus_9f37ac09 data);
      salReturn getSample(MTM1M3::logevent_powerSupplyStatus_9f37ac09Seq data);
      salReturn putSample_logevent_powerSupplyStatus(MTM1M3_logevent_powerSupplyStatusC *data);
      salReturn getSample_logevent_powerSupplyStatus(MTM1M3_logevent_powerSupplyStatusC *data);
      salReturn getNextSample_logevent_powerSupplyStatus(MTM1M3_logevent_powerSupplyStatusC *data);
      salReturn flushSamples_logevent_powerSupplyStatus(MTM1M3_logevent_powerSupplyStatusC *data);
      salReturn getLastSample_logevent_powerSupplyStatus(MTM1M3_logevent_powerSupplyStatusC *data);
      MTM1M3_logevent_powerSupplyStatusC lastSample_MTM1M3_logevent_powerSupplyStatus;


      salReturn putSample(MTM1M3::logevent_powerWarning_cedc8628 data);
      salReturn getSample(MTM1M3::logevent_powerWarning_cedc8628Seq data);
      salReturn putSample_logevent_powerWarning(MTM1M3_logevent_powerWarningC *data);
      salReturn getSample_logevent_powerWarning(MTM1M3_logevent_powerWarningC *data);
      salReturn getNextSample_logevent_powerWarning(MTM1M3_logevent_powerWarningC *data);
      salReturn flushSamples_logevent_powerWarning(MTM1M3_logevent_powerWarningC *data);
      salReturn getLastSample_logevent_powerWarning(MTM1M3_logevent_powerWarningC *data);
      MTM1M3_logevent_powerWarningC lastSample_MTM1M3_logevent_powerWarning;


      salReturn putSample(MTM1M3::logevent_rejectedAberrationForces_07bb7050 data);
      salReturn getSample(MTM1M3::logevent_rejectedAberrationForces_07bb7050Seq data);
      salReturn putSample_logevent_rejectedAberrationForces(MTM1M3_logevent_rejectedAberrationForcesC *data);
      salReturn getSample_logevent_rejectedAberrationForces(MTM1M3_logevent_rejectedAberrationForcesC *data);
      salReturn getNextSample_logevent_rejectedAberrationForces(MTM1M3_logevent_rejectedAberrationForcesC *data);
      salReturn flushSamples_logevent_rejectedAberrationForces(MTM1M3_logevent_rejectedAberrationForcesC *data);
      salReturn getLastSample_logevent_rejectedAberrationForces(MTM1M3_logevent_rejectedAberrationForcesC *data);
      MTM1M3_logevent_rejectedAberrationForcesC lastSample_MTM1M3_logevent_rejectedAberrationForces;


      salReturn putSample(MTM1M3::logevent_rejectedAccelerationForces_b8520238 data);
      salReturn getSample(MTM1M3::logevent_rejectedAccelerationForces_b8520238Seq data);
      salReturn putSample_logevent_rejectedAccelerationForces(MTM1M3_logevent_rejectedAccelerationForcesC *data);
      salReturn getSample_logevent_rejectedAccelerationForces(MTM1M3_logevent_rejectedAccelerationForcesC *data);
      salReturn getNextSample_logevent_rejectedAccelerationForces(MTM1M3_logevent_rejectedAccelerationForcesC *data);
      salReturn flushSamples_logevent_rejectedAccelerationForces(MTM1M3_logevent_rejectedAccelerationForcesC *data);
      salReturn getLastSample_logevent_rejectedAccelerationForces(MTM1M3_logevent_rejectedAccelerationForcesC *data);
      MTM1M3_logevent_rejectedAccelerationForcesC lastSample_MTM1M3_logevent_rejectedAccelerationForces;


      salReturn putSample(MTM1M3::logevent_rejectedActiveOpticForces_b308b353 data);
      salReturn getSample(MTM1M3::logevent_rejectedActiveOpticForces_b308b353Seq data);
      salReturn putSample_logevent_rejectedActiveOpticForces(MTM1M3_logevent_rejectedActiveOpticForcesC *data);
      salReturn getSample_logevent_rejectedActiveOpticForces(MTM1M3_logevent_rejectedActiveOpticForcesC *data);
      salReturn getNextSample_logevent_rejectedActiveOpticForces(MTM1M3_logevent_rejectedActiveOpticForcesC *data);
      salReturn flushSamples_logevent_rejectedActiveOpticForces(MTM1M3_logevent_rejectedActiveOpticForcesC *data);
      salReturn getLastSample_logevent_rejectedActiveOpticForces(MTM1M3_logevent_rejectedActiveOpticForcesC *data);
      MTM1M3_logevent_rejectedActiveOpticForcesC lastSample_MTM1M3_logevent_rejectedActiveOpticForces;


      salReturn putSample(MTM1M3::logevent_rejectedAzimuthForces_e69b5c03 data);
      salReturn getSample(MTM1M3::logevent_rejectedAzimuthForces_e69b5c03Seq data);
      salReturn putSample_logevent_rejectedAzimuthForces(MTM1M3_logevent_rejectedAzimuthForcesC *data);
      salReturn getSample_logevent_rejectedAzimuthForces(MTM1M3_logevent_rejectedAzimuthForcesC *data);
      salReturn getNextSample_logevent_rejectedAzimuthForces(MTM1M3_logevent_rejectedAzimuthForcesC *data);
      salReturn flushSamples_logevent_rejectedAzimuthForces(MTM1M3_logevent_rejectedAzimuthForcesC *data);
      salReturn getLastSample_logevent_rejectedAzimuthForces(MTM1M3_logevent_rejectedAzimuthForcesC *data);
      MTM1M3_logevent_rejectedAzimuthForcesC lastSample_MTM1M3_logevent_rejectedAzimuthForces;


      salReturn putSample(MTM1M3::logevent_rejectedBalanceForces_3d81e3db data);
      salReturn getSample(MTM1M3::logevent_rejectedBalanceForces_3d81e3dbSeq data);
      salReturn putSample_logevent_rejectedBalanceForces(MTM1M3_logevent_rejectedBalanceForcesC *data);
      salReturn getSample_logevent_rejectedBalanceForces(MTM1M3_logevent_rejectedBalanceForcesC *data);
      salReturn getNextSample_logevent_rejectedBalanceForces(MTM1M3_logevent_rejectedBalanceForcesC *data);
      salReturn flushSamples_logevent_rejectedBalanceForces(MTM1M3_logevent_rejectedBalanceForcesC *data);
      salReturn getLastSample_logevent_rejectedBalanceForces(MTM1M3_logevent_rejectedBalanceForcesC *data);
      MTM1M3_logevent_rejectedBalanceForcesC lastSample_MTM1M3_logevent_rejectedBalanceForces;


      salReturn putSample(MTM1M3::logevent_rejectedCylinderForces_f4002407 data);
      salReturn getSample(MTM1M3::logevent_rejectedCylinderForces_f4002407Seq data);
      salReturn putSample_logevent_rejectedCylinderForces(MTM1M3_logevent_rejectedCylinderForcesC *data);
      salReturn getSample_logevent_rejectedCylinderForces(MTM1M3_logevent_rejectedCylinderForcesC *data);
      salReturn getNextSample_logevent_rejectedCylinderForces(MTM1M3_logevent_rejectedCylinderForcesC *data);
      salReturn flushSamples_logevent_rejectedCylinderForces(MTM1M3_logevent_rejectedCylinderForcesC *data);
      salReturn getLastSample_logevent_rejectedCylinderForces(MTM1M3_logevent_rejectedCylinderForcesC *data);
      MTM1M3_logevent_rejectedCylinderForcesC lastSample_MTM1M3_logevent_rejectedCylinderForces;


      salReturn putSample(MTM1M3::logevent_rejectedElevationForces_bf1221a9 data);
      salReturn getSample(MTM1M3::logevent_rejectedElevationForces_bf1221a9Seq data);
      salReturn putSample_logevent_rejectedElevationForces(MTM1M3_logevent_rejectedElevationForcesC *data);
      salReturn getSample_logevent_rejectedElevationForces(MTM1M3_logevent_rejectedElevationForcesC *data);
      salReturn getNextSample_logevent_rejectedElevationForces(MTM1M3_logevent_rejectedElevationForcesC *data);
      salReturn flushSamples_logevent_rejectedElevationForces(MTM1M3_logevent_rejectedElevationForcesC *data);
      salReturn getLastSample_logevent_rejectedElevationForces(MTM1M3_logevent_rejectedElevationForcesC *data);
      MTM1M3_logevent_rejectedElevationForcesC lastSample_MTM1M3_logevent_rejectedElevationForces;


      salReturn putSample(MTM1M3::logevent_rejectedForces_7969f67b data);
      salReturn getSample(MTM1M3::logevent_rejectedForces_7969f67bSeq data);
      salReturn putSample_logevent_rejectedForces(MTM1M3_logevent_rejectedForcesC *data);
      salReturn getSample_logevent_rejectedForces(MTM1M3_logevent_rejectedForcesC *data);
      salReturn getNextSample_logevent_rejectedForces(MTM1M3_logevent_rejectedForcesC *data);
      salReturn flushSamples_logevent_rejectedForces(MTM1M3_logevent_rejectedForcesC *data);
      salReturn getLastSample_logevent_rejectedForces(MTM1M3_logevent_rejectedForcesC *data);
      MTM1M3_logevent_rejectedForcesC lastSample_MTM1M3_logevent_rejectedForces;


      salReturn putSample(MTM1M3::logevent_rejectedOffsetForces_9ae34670 data);
      salReturn getSample(MTM1M3::logevent_rejectedOffsetForces_9ae34670Seq data);
      salReturn putSample_logevent_rejectedOffsetForces(MTM1M3_logevent_rejectedOffsetForcesC *data);
      salReturn getSample_logevent_rejectedOffsetForces(MTM1M3_logevent_rejectedOffsetForcesC *data);
      salReturn getNextSample_logevent_rejectedOffsetForces(MTM1M3_logevent_rejectedOffsetForcesC *data);
      salReturn flushSamples_logevent_rejectedOffsetForces(MTM1M3_logevent_rejectedOffsetForcesC *data);
      salReturn getLastSample_logevent_rejectedOffsetForces(MTM1M3_logevent_rejectedOffsetForcesC *data);
      MTM1M3_logevent_rejectedOffsetForcesC lastSample_MTM1M3_logevent_rejectedOffsetForces;


      salReturn putSample(MTM1M3::logevent_rejectedStaticForces_95f4fc51 data);
      salReturn getSample(MTM1M3::logevent_rejectedStaticForces_95f4fc51Seq data);
      salReturn putSample_logevent_rejectedStaticForces(MTM1M3_logevent_rejectedStaticForcesC *data);
      salReturn getSample_logevent_rejectedStaticForces(MTM1M3_logevent_rejectedStaticForcesC *data);
      salReturn getNextSample_logevent_rejectedStaticForces(MTM1M3_logevent_rejectedStaticForcesC *data);
      salReturn flushSamples_logevent_rejectedStaticForces(MTM1M3_logevent_rejectedStaticForcesC *data);
      salReturn getLastSample_logevent_rejectedStaticForces(MTM1M3_logevent_rejectedStaticForcesC *data);
      MTM1M3_logevent_rejectedStaticForcesC lastSample_MTM1M3_logevent_rejectedStaticForces;


      salReturn putSample(MTM1M3::logevent_rejectedThermalForces_bda7bbdd data);
      salReturn getSample(MTM1M3::logevent_rejectedThermalForces_bda7bbddSeq data);
      salReturn putSample_logevent_rejectedThermalForces(MTM1M3_logevent_rejectedThermalForcesC *data);
      salReturn getSample_logevent_rejectedThermalForces(MTM1M3_logevent_rejectedThermalForcesC *data);
      salReturn getNextSample_logevent_rejectedThermalForces(MTM1M3_logevent_rejectedThermalForcesC *data);
      salReturn flushSamples_logevent_rejectedThermalForces(MTM1M3_logevent_rejectedThermalForcesC *data);
      salReturn getLastSample_logevent_rejectedThermalForces(MTM1M3_logevent_rejectedThermalForcesC *data);
      MTM1M3_logevent_rejectedThermalForcesC lastSample_MTM1M3_logevent_rejectedThermalForces;


      salReturn putSample(MTM1M3::logevent_rejectedVelocityForces_9e4d8b9f data);
      salReturn getSample(MTM1M3::logevent_rejectedVelocityForces_9e4d8b9fSeq data);
      salReturn putSample_logevent_rejectedVelocityForces(MTM1M3_logevent_rejectedVelocityForcesC *data);
      salReturn getSample_logevent_rejectedVelocityForces(MTM1M3_logevent_rejectedVelocityForcesC *data);
      salReturn getNextSample_logevent_rejectedVelocityForces(MTM1M3_logevent_rejectedVelocityForcesC *data);
      salReturn flushSamples_logevent_rejectedVelocityForces(MTM1M3_logevent_rejectedVelocityForcesC *data);
      salReturn getLastSample_logevent_rejectedVelocityForces(MTM1M3_logevent_rejectedVelocityForcesC *data);
      MTM1M3_logevent_rejectedVelocityForcesC lastSample_MTM1M3_logevent_rejectedVelocityForces;


      salReturn putSample(MTM1M3::logevent_settingVersions_679fb179 data);
      salReturn getSample(MTM1M3::logevent_settingVersions_679fb179Seq data);
      salReturn putSample_logevent_settingVersions(MTM1M3_logevent_settingVersionsC *data);
      salReturn getSample_logevent_settingVersions(MTM1M3_logevent_settingVersionsC *data);
      salReturn getNextSample_logevent_settingVersions(MTM1M3_logevent_settingVersionsC *data);
      salReturn flushSamples_logevent_settingVersions(MTM1M3_logevent_settingVersionsC *data);
      salReturn getLastSample_logevent_settingVersions(MTM1M3_logevent_settingVersionsC *data);
      MTM1M3_logevent_settingVersionsC lastSample_MTM1M3_logevent_settingVersions;


      salReturn putSample(MTM1M3::logevent_settingsApplied_61b4dd6e data);
      salReturn getSample(MTM1M3::logevent_settingsApplied_61b4dd6eSeq data);
      salReturn putSample_logevent_settingsApplied(MTM1M3_logevent_settingsAppliedC *data);
      salReturn getSample_logevent_settingsApplied(MTM1M3_logevent_settingsAppliedC *data);
      salReturn getNextSample_logevent_settingsApplied(MTM1M3_logevent_settingsAppliedC *data);
      salReturn flushSamples_logevent_settingsApplied(MTM1M3_logevent_settingsAppliedC *data);
      salReturn getLastSample_logevent_settingsApplied(MTM1M3_logevent_settingsAppliedC *data);
      MTM1M3_logevent_settingsAppliedC lastSample_MTM1M3_logevent_settingsApplied;


      salReturn putSample(MTM1M3::logevent_simulationMode_a613ee19 data);
      salReturn getSample(MTM1M3::logevent_simulationMode_a613ee19Seq data);
      salReturn putSample_logevent_simulationMode(MTM1M3_logevent_simulationModeC *data);
      salReturn getSample_logevent_simulationMode(MTM1M3_logevent_simulationModeC *data);
      salReturn getNextSample_logevent_simulationMode(MTM1M3_logevent_simulationModeC *data);
      salReturn flushSamples_logevent_simulationMode(MTM1M3_logevent_simulationModeC *data);
      salReturn getLastSample_logevent_simulationMode(MTM1M3_logevent_simulationModeC *data);
      MTM1M3_logevent_simulationModeC lastSample_MTM1M3_logevent_simulationMode;


      salReturn putSample(MTM1M3::logevent_softwareVersions_ed013250 data);
      salReturn getSample(MTM1M3::logevent_softwareVersions_ed013250Seq data);
      salReturn putSample_logevent_softwareVersions(MTM1M3_logevent_softwareVersionsC *data);
      salReturn getSample_logevent_softwareVersions(MTM1M3_logevent_softwareVersionsC *data);
      salReturn getNextSample_logevent_softwareVersions(MTM1M3_logevent_softwareVersionsC *data);
      salReturn flushSamples_logevent_softwareVersions(MTM1M3_logevent_softwareVersionsC *data);
      salReturn getLastSample_logevent_softwareVersions(MTM1M3_logevent_softwareVersionsC *data);
      MTM1M3_logevent_softwareVersionsC lastSample_MTM1M3_logevent_softwareVersions;


      salReturn putSample(MTM1M3::logevent_summaryState_f936f3fc data);
      salReturn getSample(MTM1M3::logevent_summaryState_f936f3fcSeq data);
      salReturn putSample_logevent_summaryState(MTM1M3_logevent_summaryStateC *data);
      salReturn getSample_logevent_summaryState(MTM1M3_logevent_summaryStateC *data);
      salReturn getNextSample_logevent_summaryState(MTM1M3_logevent_summaryStateC *data);
      salReturn flushSamples_logevent_summaryState(MTM1M3_logevent_summaryStateC *data);
      salReturn getLastSample_logevent_summaryState(MTM1M3_logevent_summaryStateC *data);
      MTM1M3_logevent_summaryStateC lastSample_MTM1M3_logevent_summaryState;


      salReturn putSample(MTM1M3::outerLoopData_0cb4c7ed data);
      salReturn getSample(MTM1M3::outerLoopData_0cb4c7edSeq data);
      salReturn putSample_outerLoopData(MTM1M3_outerLoopDataC *data);
      salReturn getSample_outerLoopData(MTM1M3_outerLoopDataC *data);
      salReturn getNextSample_outerLoopData(MTM1M3_outerLoopDataC *data);
      salReturn flushSamples_outerLoopData(MTM1M3_outerLoopDataC *data);
      salReturn getLastSample_outerLoopData(MTM1M3_outerLoopDataC *data);
      MTM1M3_outerLoopDataC lastSample_MTM1M3_outerLoopData;


      salReturn putSample(MTM1M3::pidData_0bd588ed data);
      salReturn getSample(MTM1M3::pidData_0bd588edSeq data);
      salReturn putSample_pidData(MTM1M3_pidDataC *data);
      salReturn getSample_pidData(MTM1M3_pidDataC *data);
      salReturn getNextSample_pidData(MTM1M3_pidDataC *data);
      salReturn flushSamples_pidData(MTM1M3_pidDataC *data);
      salReturn getLastSample_pidData(MTM1M3_pidDataC *data);
      MTM1M3_pidDataC lastSample_MTM1M3_pidData;


      salReturn putSample(MTM1M3::powerSupplyData_daf67bc2 data);
      salReturn getSample(MTM1M3::powerSupplyData_daf67bc2Seq data);
      salReturn putSample_powerSupplyData(MTM1M3_powerSupplyDataC *data);
      salReturn getSample_powerSupplyData(MTM1M3_powerSupplyDataC *data);
      salReturn getNextSample_powerSupplyData(MTM1M3_powerSupplyDataC *data);
      salReturn flushSamples_powerSupplyData(MTM1M3_powerSupplyDataC *data);
      salReturn getLastSample_powerSupplyData(MTM1M3_powerSupplyDataC *data);
      MTM1M3_powerSupplyDataC lastSample_MTM1M3_powerSupplyData;


      salReturn putSample(MTM1M3::ackcmd_004df1cb data);
      salReturn getSample(MTM1M3::ackcmd_004df1cbSeq data);
      salReturn putSample_ackcmd(MTM1M3_ackcmdC *data);
      salReturn getSample_ackcmd(MTM1M3_ackcmdC *data);
      salReturn getNextSample_ackcmd(MTM1M3_ackcmdC *data);
      salReturn flushSamples_ackcmd(MTM1M3_ackcmdC *data);
      salReturn getLastSample_ackcmd(MTM1M3_ackcmdC *data);
      MTM1M3_ackcmdC lastSample_MTM1M3_ackcmd;


      int issueCommand_raiseM1M3( MTM1M3_command_raiseM1M3C *data );
      int acceptCommand_raiseM1M3( MTM1M3_command_raiseM1M3C *data );
      salReturn waitForCompletion_raiseM1M3( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_raiseM1M3( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_raiseM1M3C( MTM1M3_ackcmdC *data );
      salReturn getResponse_raiseM1M3( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_raiseM1M3C (MTM1M3_ackcmdC *data );

      int issueCommand_abortRaiseM1M3( MTM1M3_command_abortRaiseM1M3C *data );
      int acceptCommand_abortRaiseM1M3( MTM1M3_command_abortRaiseM1M3C *data );
      salReturn waitForCompletion_abortRaiseM1M3( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_abortRaiseM1M3( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_abortRaiseM1M3C( MTM1M3_ackcmdC *data );
      salReturn getResponse_abortRaiseM1M3( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_abortRaiseM1M3C (MTM1M3_ackcmdC *data );

      int issueCommand_lowerM1M3( MTM1M3_command_lowerM1M3C *data );
      int acceptCommand_lowerM1M3( MTM1M3_command_lowerM1M3C *data );
      salReturn waitForCompletion_lowerM1M3( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_lowerM1M3( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_lowerM1M3C( MTM1M3_ackcmdC *data );
      salReturn getResponse_lowerM1M3( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_lowerM1M3C (MTM1M3_ackcmdC *data );

      int issueCommand_enterEngineering( MTM1M3_command_enterEngineeringC *data );
      int acceptCommand_enterEngineering( MTM1M3_command_enterEngineeringC *data );
      salReturn waitForCompletion_enterEngineering( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_enterEngineering( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_enterEngineeringC( MTM1M3_ackcmdC *data );
      salReturn getResponse_enterEngineering( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_enterEngineeringC (MTM1M3_ackcmdC *data );

      int issueCommand_exitEngineering( MTM1M3_command_exitEngineeringC *data );
      int acceptCommand_exitEngineering( MTM1M3_command_exitEngineeringC *data );
      salReturn waitForCompletion_exitEngineering( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_exitEngineering( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_exitEngineeringC( MTM1M3_ackcmdC *data );
      salReturn getResponse_exitEngineering( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_exitEngineeringC (MTM1M3_ackcmdC *data );

      int issueCommand_turnAirOn( MTM1M3_command_turnAirOnC *data );
      int acceptCommand_turnAirOn( MTM1M3_command_turnAirOnC *data );
      salReturn waitForCompletion_turnAirOn( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_turnAirOn( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_turnAirOnC( MTM1M3_ackcmdC *data );
      salReturn getResponse_turnAirOn( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_turnAirOnC (MTM1M3_ackcmdC *data );

      int issueCommand_turnAirOff( MTM1M3_command_turnAirOffC *data );
      int acceptCommand_turnAirOff( MTM1M3_command_turnAirOffC *data );
      salReturn waitForCompletion_turnAirOff( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_turnAirOff( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_turnAirOffC( MTM1M3_ackcmdC *data );
      salReturn getResponse_turnAirOff( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_turnAirOffC (MTM1M3_ackcmdC *data );

      int issueCommand_testAir( MTM1M3_command_testAirC *data );
      int acceptCommand_testAir( MTM1M3_command_testAirC *data );
      salReturn waitForCompletion_testAir( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_testAir( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_testAirC( MTM1M3_ackcmdC *data );
      salReturn getResponse_testAir( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_testAirC (MTM1M3_ackcmdC *data );

      int issueCommand_moveHardpointActuators( MTM1M3_command_moveHardpointActuatorsC *data );
      int acceptCommand_moveHardpointActuators( MTM1M3_command_moveHardpointActuatorsC *data );
      salReturn waitForCompletion_moveHardpointActuators( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_moveHardpointActuators( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_moveHardpointActuatorsC( MTM1M3_ackcmdC *data );
      salReturn getResponse_moveHardpointActuators( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_moveHardpointActuatorsC (MTM1M3_ackcmdC *data );

      int issueCommand_stopHardpointMotion( MTM1M3_command_stopHardpointMotionC *data );
      int acceptCommand_stopHardpointMotion( MTM1M3_command_stopHardpointMotionC *data );
      salReturn waitForCompletion_stopHardpointMotion( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_stopHardpointMotion( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_stopHardpointMotionC( MTM1M3_ackcmdC *data );
      salReturn getResponse_stopHardpointMotion( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_stopHardpointMotionC (MTM1M3_ackcmdC *data );

      int issueCommand_testHardpoint( MTM1M3_command_testHardpointC *data );
      int acceptCommand_testHardpoint( MTM1M3_command_testHardpointC *data );
      salReturn waitForCompletion_testHardpoint( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_testHardpoint( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_testHardpointC( MTM1M3_ackcmdC *data );
      salReturn getResponse_testHardpoint( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_testHardpointC (MTM1M3_ackcmdC *data );

      int issueCommand_enableHardpointChase( MTM1M3_command_enableHardpointChaseC *data );
      int acceptCommand_enableHardpointChase( MTM1M3_command_enableHardpointChaseC *data );
      salReturn waitForCompletion_enableHardpointChase( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_enableHardpointChase( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_enableHardpointChaseC( MTM1M3_ackcmdC *data );
      salReturn getResponse_enableHardpointChase( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_enableHardpointChaseC (MTM1M3_ackcmdC *data );

      int issueCommand_disableHardpointChase( MTM1M3_command_disableHardpointChaseC *data );
      int acceptCommand_disableHardpointChase( MTM1M3_command_disableHardpointChaseC *data );
      salReturn waitForCompletion_disableHardpointChase( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_disableHardpointChase( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_disableHardpointChaseC( MTM1M3_ackcmdC *data );
      salReturn getResponse_disableHardpointChase( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_disableHardpointChaseC (MTM1M3_ackcmdC *data );

      int issueCommand_testForceActuator( MTM1M3_command_testForceActuatorC *data );
      int acceptCommand_testForceActuator( MTM1M3_command_testForceActuatorC *data );
      salReturn waitForCompletion_testForceActuator( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_testForceActuator( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_testForceActuatorC( MTM1M3_ackcmdC *data );
      salReturn getResponse_testForceActuator( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_testForceActuatorC (MTM1M3_ackcmdC *data );

      int issueCommand_applyOffsetForces( MTM1M3_command_applyOffsetForcesC *data );
      int acceptCommand_applyOffsetForces( MTM1M3_command_applyOffsetForcesC *data );
      salReturn waitForCompletion_applyOffsetForces( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_applyOffsetForces( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_applyOffsetForcesC( MTM1M3_ackcmdC *data );
      salReturn getResponse_applyOffsetForces( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_applyOffsetForcesC (MTM1M3_ackcmdC *data );

      int issueCommand_shutdown( MTM1M3_command_shutdownC *data );
      int acceptCommand_shutdown( MTM1M3_command_shutdownC *data );
      salReturn waitForCompletion_shutdown( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_shutdown( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_shutdownC( MTM1M3_ackcmdC *data );
      salReturn getResponse_shutdown( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_shutdownC (MTM1M3_ackcmdC *data );

      int issueCommand_translateM1M3( MTM1M3_command_translateM1M3C *data );
      int acceptCommand_translateM1M3( MTM1M3_command_translateM1M3C *data );
      salReturn waitForCompletion_translateM1M3( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_translateM1M3( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_translateM1M3C( MTM1M3_ackcmdC *data );
      salReturn getResponse_translateM1M3( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_translateM1M3C (MTM1M3_ackcmdC *data );

      int issueCommand_clearOffsetForces( MTM1M3_command_clearOffsetForcesC *data );
      int acceptCommand_clearOffsetForces( MTM1M3_command_clearOffsetForcesC *data );
      salReturn waitForCompletion_clearOffsetForces( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_clearOffsetForces( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_clearOffsetForcesC( MTM1M3_ackcmdC *data );
      salReturn getResponse_clearOffsetForces( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_clearOffsetForcesC (MTM1M3_ackcmdC *data );

      int issueCommand_applyAberrationForcesByBendingModes( MTM1M3_command_applyAberrationForcesByBendingModesC *data );
      int acceptCommand_applyAberrationForcesByBendingModes( MTM1M3_command_applyAberrationForcesByBendingModesC *data );
      salReturn waitForCompletion_applyAberrationForcesByBendingModes( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_applyAberrationForcesByBendingModes( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_applyAberrationForcesByBendingModesC( MTM1M3_ackcmdC *data );
      salReturn getResponse_applyAberrationForcesByBendingModes( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_applyAberrationForcesByBendingModesC (MTM1M3_ackcmdC *data );

      int issueCommand_applyAberrationForces( MTM1M3_command_applyAberrationForcesC *data );
      int acceptCommand_applyAberrationForces( MTM1M3_command_applyAberrationForcesC *data );
      salReturn waitForCompletion_applyAberrationForces( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_applyAberrationForces( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_applyAberrationForcesC( MTM1M3_ackcmdC *data );
      salReturn getResponse_applyAberrationForces( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_applyAberrationForcesC (MTM1M3_ackcmdC *data );

      int issueCommand_clearAberrationForces( MTM1M3_command_clearAberrationForcesC *data );
      int acceptCommand_clearAberrationForces( MTM1M3_command_clearAberrationForcesC *data );
      salReturn waitForCompletion_clearAberrationForces( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_clearAberrationForces( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_clearAberrationForcesC( MTM1M3_ackcmdC *data );
      salReturn getResponse_clearAberrationForces( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_clearAberrationForcesC (MTM1M3_ackcmdC *data );

      int issueCommand_applyActiveOpticForcesByBendingModes( MTM1M3_command_applyActiveOpticForcesByBendingModesC *data );
      int acceptCommand_applyActiveOpticForcesByBendingModes( MTM1M3_command_applyActiveOpticForcesByBendingModesC *data );
      salReturn waitForCompletion_applyActiveOpticForcesByBendingModes( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_applyActiveOpticForcesByBendingModes( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_applyActiveOpticForcesByBendingModesC( MTM1M3_ackcmdC *data );
      salReturn getResponse_applyActiveOpticForcesByBendingModes( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_applyActiveOpticForcesByBendingModesC (MTM1M3_ackcmdC *data );

      int issueCommand_applyActiveOpticForces( MTM1M3_command_applyActiveOpticForcesC *data );
      int acceptCommand_applyActiveOpticForces( MTM1M3_command_applyActiveOpticForcesC *data );
      salReturn waitForCompletion_applyActiveOpticForces( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_applyActiveOpticForces( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_applyActiveOpticForcesC( MTM1M3_ackcmdC *data );
      salReturn getResponse_applyActiveOpticForces( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_applyActiveOpticForcesC (MTM1M3_ackcmdC *data );

      int issueCommand_clearActiveOpticForces( MTM1M3_command_clearActiveOpticForcesC *data );
      int acceptCommand_clearActiveOpticForces( MTM1M3_command_clearActiveOpticForcesC *data );
      salReturn waitForCompletion_clearActiveOpticForces( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_clearActiveOpticForces( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_clearActiveOpticForcesC( MTM1M3_ackcmdC *data );
      salReturn getResponse_clearActiveOpticForces( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_clearActiveOpticForcesC (MTM1M3_ackcmdC *data );

      int issueCommand_positionM1M3( MTM1M3_command_positionM1M3C *data );
      int acceptCommand_positionM1M3( MTM1M3_command_positionM1M3C *data );
      salReturn waitForCompletion_positionM1M3( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_positionM1M3( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_positionM1M3C( MTM1M3_ackcmdC *data );
      salReturn getResponse_positionM1M3( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_positionM1M3C (MTM1M3_ackcmdC *data );

      int issueCommand_turnLightsOn( MTM1M3_command_turnLightsOnC *data );
      int acceptCommand_turnLightsOn( MTM1M3_command_turnLightsOnC *data );
      salReturn waitForCompletion_turnLightsOn( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_turnLightsOn( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_turnLightsOnC( MTM1M3_ackcmdC *data );
      salReturn getResponse_turnLightsOn( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_turnLightsOnC (MTM1M3_ackcmdC *data );

      int issueCommand_turnLightsOff( MTM1M3_command_turnLightsOffC *data );
      int acceptCommand_turnLightsOff( MTM1M3_command_turnLightsOffC *data );
      salReturn waitForCompletion_turnLightsOff( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_turnLightsOff( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_turnLightsOffC( MTM1M3_ackcmdC *data );
      salReturn getResponse_turnLightsOff( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_turnLightsOffC (MTM1M3_ackcmdC *data );

      int issueCommand_turnPowerOn( MTM1M3_command_turnPowerOnC *data );
      int acceptCommand_turnPowerOn( MTM1M3_command_turnPowerOnC *data );
      salReturn waitForCompletion_turnPowerOn( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_turnPowerOn( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_turnPowerOnC( MTM1M3_ackcmdC *data );
      salReturn getResponse_turnPowerOn( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_turnPowerOnC (MTM1M3_ackcmdC *data );

      int issueCommand_turnPowerOff( MTM1M3_command_turnPowerOffC *data );
      int acceptCommand_turnPowerOff( MTM1M3_command_turnPowerOffC *data );
      salReturn waitForCompletion_turnPowerOff( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_turnPowerOff( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_turnPowerOffC( MTM1M3_ackcmdC *data );
      salReturn getResponse_turnPowerOff( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_turnPowerOffC (MTM1M3_ackcmdC *data );

      int issueCommand_enableHardpointCorrections( MTM1M3_command_enableHardpointCorrectionsC *data );
      int acceptCommand_enableHardpointCorrections( MTM1M3_command_enableHardpointCorrectionsC *data );
      salReturn waitForCompletion_enableHardpointCorrections( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_enableHardpointCorrections( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_enableHardpointCorrectionsC( MTM1M3_ackcmdC *data );
      salReturn getResponse_enableHardpointCorrections( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_enableHardpointCorrectionsC (MTM1M3_ackcmdC *data );

      int issueCommand_disableHardpointCorrections( MTM1M3_command_disableHardpointCorrectionsC *data );
      int acceptCommand_disableHardpointCorrections( MTM1M3_command_disableHardpointCorrectionsC *data );
      salReturn waitForCompletion_disableHardpointCorrections( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_disableHardpointCorrections( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_disableHardpointCorrectionsC( MTM1M3_ackcmdC *data );
      salReturn getResponse_disableHardpointCorrections( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_disableHardpointCorrectionsC (MTM1M3_ackcmdC *data );

      int issueCommand_runMirrorForceProfile( MTM1M3_command_runMirrorForceProfileC *data );
      int acceptCommand_runMirrorForceProfile( MTM1M3_command_runMirrorForceProfileC *data );
      salReturn waitForCompletion_runMirrorForceProfile( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_runMirrorForceProfile( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_runMirrorForceProfileC( MTM1M3_ackcmdC *data );
      salReturn getResponse_runMirrorForceProfile( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_runMirrorForceProfileC (MTM1M3_ackcmdC *data );

      int issueCommand_abortProfile( MTM1M3_command_abortProfileC *data );
      int acceptCommand_abortProfile( MTM1M3_command_abortProfileC *data );
      salReturn waitForCompletion_abortProfile( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_abortProfile( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_abortProfileC( MTM1M3_ackcmdC *data );
      salReturn getResponse_abortProfile( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_abortProfileC (MTM1M3_ackcmdC *data );

      int issueCommand_applyOffsetForcesByMirrorForce( MTM1M3_command_applyOffsetForcesByMirrorForceC *data );
      int acceptCommand_applyOffsetForcesByMirrorForce( MTM1M3_command_applyOffsetForcesByMirrorForceC *data );
      salReturn waitForCompletion_applyOffsetForcesByMirrorForce( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_applyOffsetForcesByMirrorForce( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_applyOffsetForcesByMirrorForceC( MTM1M3_ackcmdC *data );
      salReturn getResponse_applyOffsetForcesByMirrorForce( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_applyOffsetForcesByMirrorForceC (MTM1M3_ackcmdC *data );

      int issueCommand_updatePID( MTM1M3_command_updatePIDC *data );
      int acceptCommand_updatePID( MTM1M3_command_updatePIDC *data );
      salReturn waitForCompletion_updatePID( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_updatePID( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_updatePIDC( MTM1M3_ackcmdC *data );
      salReturn getResponse_updatePID( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_updatePIDC (MTM1M3_ackcmdC *data );

      int issueCommand_resetPID( MTM1M3_command_resetPIDC *data );
      int acceptCommand_resetPID( MTM1M3_command_resetPIDC *data );
      salReturn waitForCompletion_resetPID( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_resetPID( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_resetPIDC( MTM1M3_ackcmdC *data );
      salReturn getResponse_resetPID( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_resetPIDC (MTM1M3_ackcmdC *data );

      int issueCommand_setThermalSetpoint( MTM1M3_command_setThermalSetpointC *data );
      int acceptCommand_setThermalSetpoint( MTM1M3_command_setThermalSetpointC *data );
      salReturn waitForCompletion_setThermalSetpoint( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_setThermalSetpoint( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_setThermalSetpointC( MTM1M3_ackcmdC *data );
      salReturn getResponse_setThermalSetpoint( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_setThermalSetpointC (MTM1M3_ackcmdC *data );

      int issueCommand_programILC( MTM1M3_command_programILCC *data );
      int acceptCommand_programILC( MTM1M3_command_programILCC *data );
      salReturn waitForCompletion_programILC( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_programILC( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_programILCC( MTM1M3_ackcmdC *data );
      salReturn getResponse_programILC( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_programILCC (MTM1M3_ackcmdC *data );

      int issueCommand_modbusTransmit( MTM1M3_command_modbusTransmitC *data );
      int acceptCommand_modbusTransmit( MTM1M3_command_modbusTransmitC *data );
      salReturn waitForCompletion_modbusTransmit( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_modbusTransmit( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_modbusTransmitC( MTM1M3_ackcmdC *data );
      salReturn getResponse_modbusTransmit( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_modbusTransmitC (MTM1M3_ackcmdC *data );

      int issueCommand_abort( MTM1M3_command_abortC *data );
      int acceptCommand_abort( MTM1M3_command_abortC *data );
      salReturn waitForCompletion_abort( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_abort( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_abortC( MTM1M3_ackcmdC *data );
      salReturn getResponse_abort( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_abortC (MTM1M3_ackcmdC *data );

      int issueCommand_enable( MTM1M3_command_enableC *data );
      int acceptCommand_enable( MTM1M3_command_enableC *data );
      salReturn waitForCompletion_enable( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_enable( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_enableC( MTM1M3_ackcmdC *data );
      salReturn getResponse_enable( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_enableC (MTM1M3_ackcmdC *data );

      int issueCommand_disable( MTM1M3_command_disableC *data );
      int acceptCommand_disable( MTM1M3_command_disableC *data );
      salReturn waitForCompletion_disable( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_disable( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_disableC( MTM1M3_ackcmdC *data );
      salReturn getResponse_disable( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_disableC (MTM1M3_ackcmdC *data );

      int issueCommand_standby( MTM1M3_command_standbyC *data );
      int acceptCommand_standby( MTM1M3_command_standbyC *data );
      salReturn waitForCompletion_standby( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_standby( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_standbyC( MTM1M3_ackcmdC *data );
      salReturn getResponse_standby( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_standbyC (MTM1M3_ackcmdC *data );

      int issueCommand_exitControl( MTM1M3_command_exitControlC *data );
      int acceptCommand_exitControl( MTM1M3_command_exitControlC *data );
      salReturn waitForCompletion_exitControl( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_exitControl( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_exitControlC( MTM1M3_ackcmdC *data );
      salReturn getResponse_exitControl( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_exitControlC (MTM1M3_ackcmdC *data );

      int issueCommand_start( MTM1M3_command_startC *data );
      int acceptCommand_start( MTM1M3_command_startC *data );
      salReturn waitForCompletion_start( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_start( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_startC( MTM1M3_ackcmdC *data );
      salReturn getResponse_start( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_startC (MTM1M3_ackcmdC *data );

      int issueCommand_enterControl( MTM1M3_command_enterControlC *data );
      int acceptCommand_enterControl( MTM1M3_command_enterControlC *data );
      salReturn waitForCompletion_enterControl( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_enterControl( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_enterControlC( MTM1M3_ackcmdC *data );
      salReturn getResponse_enterControl( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_enterControlC (MTM1M3_ackcmdC *data );

      int issueCommand_setLogLevel( MTM1M3_command_setLogLevelC *data );
      int acceptCommand_setLogLevel( MTM1M3_command_setLogLevelC *data );
      salReturn waitForCompletion_setLogLevel( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_setLogLevel( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_setLogLevelC( MTM1M3_ackcmdC *data );
      salReturn getResponse_setLogLevel( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_setLogLevelC (MTM1M3_ackcmdC *data );

      int issueCommand_setSimulationMode( MTM1M3_command_setSimulationModeC *data );
      int acceptCommand_setSimulationMode( MTM1M3_command_setSimulationModeC *data );
      salReturn waitForCompletion_setSimulationMode( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_setSimulationMode( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_setSimulationModeC( MTM1M3_ackcmdC *data );
      salReturn getResponse_setSimulationMode( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_setSimulationModeC (MTM1M3_ackcmdC *data );

      int issueCommand_setValue( MTM1M3_command_setValueC *data );
      int acceptCommand_setValue( MTM1M3_command_setValueC *data );
      salReturn waitForCompletion_setValue( int cmdSeqNum , unsigned int timeout );
      salReturn ackCommand_setValue( int cmdSeqNum, salLONG  ack, salLONG error, char *result );
      salReturn ackCommand_setValueC( MTM1M3_ackcmdC *data );
      salReturn getResponse_setValue( MTM1M3::ackcmd_004df1cbSeq data );
      salReturn getResponse_setValueC (MTM1M3_ackcmdC *data );

      salReturn logEvent_detailedState( MTM1M3_logevent_detailedStateC *data, int priority );      
      int getEvent_detailedState( MTM1M3_logevent_detailedStateC *data );

      salReturn logEvent_hardpointActuatorInfo( MTM1M3_logevent_hardpointActuatorInfoC *data, int priority );      
      int getEvent_hardpointActuatorInfo( MTM1M3_logevent_hardpointActuatorInfoC *data );

      salReturn logEvent_forceActuatorInfo( MTM1M3_logevent_forceActuatorInfoC *data, int priority );      
      int getEvent_forceActuatorInfo( MTM1M3_logevent_forceActuatorInfoC *data );

      salReturn logEvent_ilcWarning( MTM1M3_logevent_ilcWarningC *data, int priority );      
      int getEvent_ilcWarning( MTM1M3_logevent_ilcWarningC *data );

      salReturn logEvent_interlockWarning( MTM1M3_logevent_interlockWarningC *data, int priority );      
      int getEvent_interlockWarning( MTM1M3_logevent_interlockWarningC *data );

      salReturn logEvent_airSupplyStatus( MTM1M3_logevent_airSupplyStatusC *data, int priority );      
      int getEvent_airSupplyStatus( MTM1M3_logevent_airSupplyStatusC *data );

      salReturn logEvent_airSupplyWarning( MTM1M3_logevent_airSupplyWarningC *data, int priority );      
      int getEvent_airSupplyWarning( MTM1M3_logevent_airSupplyWarningC *data );

      salReturn logEvent_interlockStatus( MTM1M3_logevent_interlockStatusC *data, int priority );      
      int getEvent_interlockStatus( MTM1M3_logevent_interlockStatusC *data );

      salReturn logEvent_displacementSensorWarning( MTM1M3_logevent_displacementSensorWarningC *data, int priority );      
      int getEvent_displacementSensorWarning( MTM1M3_logevent_displacementSensorWarningC *data );

      salReturn logEvent_inclinometerSensorWarning( MTM1M3_logevent_inclinometerSensorWarningC *data, int priority );      
      int getEvent_inclinometerSensorWarning( MTM1M3_logevent_inclinometerSensorWarningC *data );

      salReturn logEvent_accelerometerWarning( MTM1M3_logevent_accelerometerWarningC *data, int priority );      
      int getEvent_accelerometerWarning( MTM1M3_logevent_accelerometerWarningC *data );

      salReturn logEvent_forceSetpointWarning( MTM1M3_logevent_forceSetpointWarningC *data, int priority );      
      int getEvent_forceSetpointWarning( MTM1M3_logevent_forceSetpointWarningC *data );

      salReturn logEvent_forceActuatorState( MTM1M3_logevent_forceActuatorStateC *data, int priority );      
      int getEvent_forceActuatorState( MTM1M3_logevent_forceActuatorStateC *data );

      salReturn logEvent_hardpointMonitorInfo( MTM1M3_logevent_hardpointMonitorInfoC *data, int priority );      
      int getEvent_hardpointMonitorInfo( MTM1M3_logevent_hardpointMonitorInfoC *data );

      salReturn logEvent_cellLightStatus( MTM1M3_logevent_cellLightStatusC *data, int priority );      
      int getEvent_cellLightStatus( MTM1M3_logevent_cellLightStatusC *data );

      salReturn logEvent_cellLightWarning( MTM1M3_logevent_cellLightWarningC *data, int priority );      
      int getEvent_cellLightWarning( MTM1M3_logevent_cellLightWarningC *data );

      salReturn logEvent_powerStatus( MTM1M3_logevent_powerStatusC *data, int priority );      
      int getEvent_powerStatus( MTM1M3_logevent_powerStatusC *data );

      salReturn logEvent_powerWarning( MTM1M3_logevent_powerWarningC *data, int priority );      
      int getEvent_powerWarning( MTM1M3_logevent_powerWarningC *data );

      salReturn logEvent_forceActuatorForceWarning( MTM1M3_logevent_forceActuatorForceWarningC *data, int priority );      
      int getEvent_forceActuatorForceWarning( MTM1M3_logevent_forceActuatorForceWarningC *data );

      salReturn logEvent_gyroWarning( MTM1M3_logevent_gyroWarningC *data, int priority );      
      int getEvent_gyroWarning( MTM1M3_logevent_gyroWarningC *data );

      salReturn logEvent_powerSupplyStatus( MTM1M3_logevent_powerSupplyStatusC *data, int priority );      
      int getEvent_powerSupplyStatus( MTM1M3_logevent_powerSupplyStatusC *data );

      salReturn logEvent_appliedOffsetForces( MTM1M3_logevent_appliedOffsetForcesC *data, int priority );      
      int getEvent_appliedOffsetForces( MTM1M3_logevent_appliedOffsetForcesC *data );

      salReturn logEvent_appliedStaticForces( MTM1M3_logevent_appliedStaticForcesC *data, int priority );      
      int getEvent_appliedStaticForces( MTM1M3_logevent_appliedStaticForcesC *data );

      salReturn logEvent_appliedActiveOpticForces( MTM1M3_logevent_appliedActiveOpticForcesC *data, int priority );      
      int getEvent_appliedActiveOpticForces( MTM1M3_logevent_appliedActiveOpticForcesC *data );

      salReturn logEvent_appliedAberrationForces( MTM1M3_logevent_appliedAberrationForcesC *data, int priority );      
      int getEvent_appliedAberrationForces( MTM1M3_logevent_appliedAberrationForcesC *data );

      salReturn logEvent_appliedAzimuthForces( MTM1M3_logevent_appliedAzimuthForcesC *data, int priority );      
      int getEvent_appliedAzimuthForces( MTM1M3_logevent_appliedAzimuthForcesC *data );

      salReturn logEvent_commandRejectionWarning( MTM1M3_logevent_commandRejectionWarningC *data, int priority );      
      int getEvent_commandRejectionWarning( MTM1M3_logevent_commandRejectionWarningC *data );

      salReturn logEvent_pidInfo( MTM1M3_logevent_pidInfoC *data, int priority );      
      int getEvent_pidInfo( MTM1M3_logevent_pidInfoC *data );

      salReturn logEvent_hardpointActuatorWarning( MTM1M3_logevent_hardpointActuatorWarningC *data, int priority );      
      int getEvent_hardpointActuatorWarning( MTM1M3_logevent_hardpointActuatorWarningC *data );

      salReturn logEvent_hardpointMonitorWarning( MTM1M3_logevent_hardpointMonitorWarningC *data, int priority );      
      int getEvent_hardpointMonitorWarning( MTM1M3_logevent_hardpointMonitorWarningC *data );

      salReturn logEvent_hardpointActuatorState( MTM1M3_logevent_hardpointActuatorStateC *data, int priority );      
      int getEvent_hardpointActuatorState( MTM1M3_logevent_hardpointActuatorStateC *data );

      salReturn logEvent_hardpointMonitorState( MTM1M3_logevent_hardpointMonitorStateC *data, int priority );      
      int getEvent_hardpointMonitorState( MTM1M3_logevent_hardpointMonitorStateC *data );

      salReturn logEvent_forceActuatorWarning( MTM1M3_logevent_forceActuatorWarningC *data, int priority );      
      int getEvent_forceActuatorWarning( MTM1M3_logevent_forceActuatorWarningC *data );

      salReturn logEvent_rejectedStaticForces( MTM1M3_logevent_rejectedStaticForcesC *data, int priority );      
      int getEvent_rejectedStaticForces( MTM1M3_logevent_rejectedStaticForcesC *data );

      salReturn logEvent_rejectedElevationForces( MTM1M3_logevent_rejectedElevationForcesC *data, int priority );      
      int getEvent_rejectedElevationForces( MTM1M3_logevent_rejectedElevationForcesC *data );

      salReturn logEvent_rejectedAzimuthForces( MTM1M3_logevent_rejectedAzimuthForcesC *data, int priority );      
      int getEvent_rejectedAzimuthForces( MTM1M3_logevent_rejectedAzimuthForcesC *data );

      salReturn logEvent_rejectedThermalForces( MTM1M3_logevent_rejectedThermalForcesC *data, int priority );      
      int getEvent_rejectedThermalForces( MTM1M3_logevent_rejectedThermalForcesC *data );

      salReturn logEvent_rejectedActiveOpticForces( MTM1M3_logevent_rejectedActiveOpticForcesC *data, int priority );      
      int getEvent_rejectedActiveOpticForces( MTM1M3_logevent_rejectedActiveOpticForcesC *data );

      salReturn logEvent_rejectedAberrationForces( MTM1M3_logevent_rejectedAberrationForcesC *data, int priority );      
      int getEvent_rejectedAberrationForces( MTM1M3_logevent_rejectedAberrationForcesC *data );

      salReturn logEvent_rejectedBalanceForces( MTM1M3_logevent_rejectedBalanceForcesC *data, int priority );      
      int getEvent_rejectedBalanceForces( MTM1M3_logevent_rejectedBalanceForcesC *data );

      salReturn logEvent_rejectedVelocityForces( MTM1M3_logevent_rejectedVelocityForcesC *data, int priority );      
      int getEvent_rejectedVelocityForces( MTM1M3_logevent_rejectedVelocityForcesC *data );

      salReturn logEvent_rejectedAccelerationForces( MTM1M3_logevent_rejectedAccelerationForcesC *data, int priority );      
      int getEvent_rejectedAccelerationForces( MTM1M3_logevent_rejectedAccelerationForcesC *data );

      salReturn logEvent_rejectedOffsetForces( MTM1M3_logevent_rejectedOffsetForcesC *data, int priority );      
      int getEvent_rejectedOffsetForces( MTM1M3_logevent_rejectedOffsetForcesC *data );

      salReturn logEvent_rejectedForces( MTM1M3_logevent_rejectedForcesC *data, int priority );      
      int getEvent_rejectedForces( MTM1M3_logevent_rejectedForcesC *data );

      salReturn logEvent_appliedElevationForces( MTM1M3_logevent_appliedElevationForcesC *data, int priority );      
      int getEvent_appliedElevationForces( MTM1M3_logevent_appliedElevationForcesC *data );

      salReturn logEvent_appliedAccelerationForces( MTM1M3_logevent_appliedAccelerationForcesC *data, int priority );      
      int getEvent_appliedAccelerationForces( MTM1M3_logevent_appliedAccelerationForcesC *data );

      salReturn logEvent_appliedThermalForces( MTM1M3_logevent_appliedThermalForcesC *data, int priority );      
      int getEvent_appliedThermalForces( MTM1M3_logevent_appliedThermalForcesC *data );

      salReturn logEvent_appliedVelocityForces( MTM1M3_logevent_appliedVelocityForcesC *data, int priority );      
      int getEvent_appliedVelocityForces( MTM1M3_logevent_appliedVelocityForcesC *data );

      salReturn logEvent_appliedBalanceForces( MTM1M3_logevent_appliedBalanceForcesC *data, int priority );      
      int getEvent_appliedBalanceForces( MTM1M3_logevent_appliedBalanceForcesC *data );

      salReturn logEvent_appliedForces( MTM1M3_logevent_appliedForcesC *data, int priority );      
      int getEvent_appliedForces( MTM1M3_logevent_appliedForcesC *data );

      salReturn logEvent_rejectedCylinderForces( MTM1M3_logevent_rejectedCylinderForcesC *data, int priority );      
      int getEvent_rejectedCylinderForces( MTM1M3_logevent_rejectedCylinderForcesC *data );

      salReturn logEvent_appliedCylinderForces( MTM1M3_logevent_appliedCylinderForcesC *data, int priority );      
      int getEvent_appliedCylinderForces( MTM1M3_logevent_appliedCylinderForcesC *data );

      salReturn logEvent_modbusResponse( MTM1M3_logevent_modbusResponseC *data, int priority );      
      int getEvent_modbusResponse( MTM1M3_logevent_modbusResponseC *data );

      salReturn logEvent_settingVersions( MTM1M3_logevent_settingVersionsC *data, int priority );      
      int getEvent_settingVersions( MTM1M3_logevent_settingVersionsC *data );

      salReturn logEvent_errorCode( MTM1M3_logevent_errorCodeC *data, int priority );      
      int getEvent_errorCode( MTM1M3_logevent_errorCodeC *data );

      salReturn logEvent_summaryState( MTM1M3_logevent_summaryStateC *data, int priority );      
      int getEvent_summaryState( MTM1M3_logevent_summaryStateC *data );

      salReturn logEvent_appliedSettingsMatchStart( MTM1M3_logevent_appliedSettingsMatchStartC *data, int priority );      
      int getEvent_appliedSettingsMatchStart( MTM1M3_logevent_appliedSettingsMatchStartC *data );

      salReturn logEvent_logLevel( MTM1M3_logevent_logLevelC *data, int priority );      
      int getEvent_logLevel( MTM1M3_logevent_logLevelC *data );

      salReturn logEvent_logMessage( MTM1M3_logevent_logMessageC *data, int priority );      
      int getEvent_logMessage( MTM1M3_logevent_logMessageC *data );

      salReturn logEvent_settingsApplied( MTM1M3_logevent_settingsAppliedC *data, int priority );      
      int getEvent_settingsApplied( MTM1M3_logevent_settingsAppliedC *data );

      salReturn logEvent_simulationMode( MTM1M3_logevent_simulationModeC *data, int priority );      
      int getEvent_simulationMode( MTM1M3_logevent_simulationModeC *data );

      salReturn logEvent_softwareVersions( MTM1M3_logevent_softwareVersionsC *data, int priority );      
      int getEvent_softwareVersions( MTM1M3_logevent_softwareVersionsC *data );

      salReturn logEvent_heartbeat( MTM1M3_logevent_heartbeatC *data, int priority );      
      int getEvent_heartbeat( MTM1M3_logevent_heartbeatC *data );
      salReturn salTypeSupport(char *topicName);
      salReturn salTelemetryPub(char *topicName);
      salReturn salTelemetrySub(char *topicName);

      string getErrorName(DDS::ReturnCode_t status);
      void checkStatus(DDS::ReturnCode_t status, const char *info);
      void checkHandle(void *handle, string info);


      double getCurrentTime();
      double getRcvdTime(char *topicName);
      double getSentTime(char *topicName);
      std::string getSALVersion();
      std::string getXMLVersion();
      int getLeapSeconds();
      void setTuneableQos(char *topicName);
      void setDefaultQos(char *topicName);
      std::vector<std::string> getTelemetryNames();
      std::vector<std::string> getCommandNames();
      std::vector<std::string> getEventNames();

      void salShutdown();
// INSERT CMDALIAS SUPPORT  for issueCommandC and acceptCommandC, acceptAnyCommand   
      salReturn cancelCommand( int cmdSeqNum );
      salReturn abortCommand( int cmdSeqNum );
      salReturn setDebugLevel( int level );
      int getDebugLevel( int level );
      int getOrigin();
      int getProperty(salCHAR *property, salCHAR *value);
      int setProperty(salCHAR *property, salCHAR *value);
      int getIntProperty(int actorIdx,salCHAR *property);
      double getDblProperty(int actorIdx,salCHAR *property);
      bool getBoolProperty(int actorIdx,salCHAR *property);
      void setMaxSamples(int actorIdx, int n);
      void logError(salReturn status);

// INSERT EVENTALIAS SUPPORT for getEventC and logEventC , getAnyEvent

      void createParticipant(const char *partitiontName);
      void deleteParticipant();
      void registerType(TypeSupport *ts);
      void registerType2(TypeSupport *ts);
      void createTopic(char *topicName);
      void createTopic2(char *topicName);
      void createContentFilteredTopic(const char *topicName, const char *filter,
                                      const StringSeq &expr);
      void createContentFilteredTopic2(const char *topicName, const char *filter,
                                       const StringSeq &expr);
      void createPublisher();
      void deletePublisher();
      void deleteTopics();
      void createWriter();
      void createWriter2();
      void createWriter(bool autodispose_unregistered_instances);
      void createWriter2(bool autodispose_unregistered_instances);
      void deleteWriter();
      void createSubscriber();
      void deleteSubscriber();
      void createReader(bool filtered);
      void createReader2(bool filtered);
      void deleteReader();
      DataReader_ptr getReader();
      DataReader_ptr getReader2();
      DataWriter_ptr getWriter();
      DataWriter_ptr getWriter2();
      Publisher_ptr getPublisher();
      Subscriber_ptr getSubscriber();
      Topic_ptr getTopic();
      DomainParticipant_ptr getParticipant();

      void initSalActors(int qos);
      salReturn salTelemetryPub(int actorIdx);
      salReturn salTelemetrySub(int actorIdx);
      salReturn salEventSub(char *topicName);
      salReturn salEventPub(char *topicName);
      int getActorIndex(char *topic);
      salReturn salTypeSupport(int actorIdx);
      salReturn salCommand(char *cmdAlias);
      salReturn salProcessor(char *cmdAlias);
      void registerType(int actorIdx,TypeSupport *ts);
      void registerType2(int actorIdx,TypeSupport *ts);
      void createTopic(int actorIdx);
      void createTopic2(int actorIdx);
      void createTopic(int actorIdx, char *topicName);
      void createTopic2(int actorIdx, char *topicName);
      void createContentFilteredTopic(int actorIdx,const char *topicName, const char *filter,const StringSeq &expr);
      void createContentFilteredTopic2(int actorIdx,const char *topicName, const char *filter,const StringSeq &expr);
      void createPublisher(int actorIdx);
      void createWriter(int actorIdx);
      void createWriter(int actorIdx,bool autodispose_unregistered_instances);
      void createWriter2(int actorIdx);
      void createWriter2(int actorIdx,bool autodispose_unregistered_instances);
      void createSubscriber(int actorIdx);
      void createReader(int actorIdx,bool filtered);
      void createReader2(int actorIdx,bool filtered);
      DataReader_ptr getReader(int actorIdx);
      DataWriter_ptr getWriter(int actorIdx);
      DataReader_ptr getReader2(int actorIdx);
      DataWriter_ptr getWriter2(int actorIdx);
      Publisher_ptr  getPublisher(int actorIdx);
      Subscriber_ptr getSubscriber(int actorIdx);
      Topic_ptr      getTopic(int actorIdx);
      Topic_ptr      getTopic2(int actorIdx);
      bool actorActive(int actorIdx);
      bool actorReader(int actorIdx);
      bool actorWriter(int actorIdx);
      bool actorCommand(int actorIdx);
      bool actorEventReader(int actorIdx);
      bool actorEventWriter(int actorIdx);
      bool actorProcessor(int actorIdx);


      ~SAL_MTM1M3();
  };

#endif
