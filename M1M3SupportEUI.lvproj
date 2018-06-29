<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="16008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="ConfigFiles" Type="Folder" URL="../ConfigFiles">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="Configuration" Type="Folder">
			<Item Name="ConfigurationEditor.lvclass" Type="LVClass" URL="../common_configurationeditor/ConfigurationEditor.lvclass"/>
			<Item Name="ConfigurationReader.lvclass" Type="LVClass" URL="../common_configurationreader/ConfigurationReader.lvclass"/>
		</Item>
		<Item Name="Controller" Type="Folder">
			<Item Name="Controller.lvclass" Type="LVClass" URL="../Controller/Controller.lvclass"/>
		</Item>
		<Item Name="Model" Type="Folder">
			<Item Name="EUI Events" Type="Folder">
				<Item Name="EUI Events.lvclass" Type="LVClass" URL="../EUI Events/EUI Events.lvclass"/>
			</Item>
			<Item Name="Logging" Type="Folder">
				<Item Name="InterfaceLog.lvclass" Type="LVClass" URL="../Logging/InterfaceLog.lvclass"/>
				<Item Name="InterfaceLogFactory.lvclass" Type="LVClass" URL="../Logging/InterfaceLogFactory.lvclass"/>
			</Item>
			<Item Name="M1M3 Support Events" Type="Folder">
				<Item Name="M1M3 Support Events.lvclass" Type="LVClass" URL="../M1M3 Support Events/M1M3 Support Events.lvclass"/>
			</Item>
			<Item Name="Model.lvclass" Type="LVClass" URL="../Model/Model.lvclass"/>
		</Item>
		<Item Name="SAL" Type="Folder">
			<Item Name="SAL.lvclass" Type="LVClass" URL="../SAL/SAL.lvclass"/>
		</Item>
		<Item Name="Settings" Type="Folder">
			<Item Name="Settings.lvclass" Type="LVClass" URL="../Settings/Settings.lvclass"/>
		</Item>
		<Item Name="StartupScripts" Type="Folder" URL="../StartupScripts">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="User Events" Type="Folder">
			<Item Name="User Events.lvclass" Type="LVClass" URL="../User Events/User Events.lvclass"/>
		</Item>
		<Item Name="Utilities" Type="Folder">
			<Item Name="SAL" Type="Folder">
				<Item Name="GetAccelerometerDataField.vi" Type="VI" URL="../Utilities/SAL/GetAccelerometerDataField.vi"/>
				<Item Name="GetEventAppliedAberrationForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventAppliedAberrationForcesField.vi"/>
				<Item Name="GetEventAppliedAccelerationForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventAppliedAccelerationForcesField.vi"/>
				<Item Name="GetEventAppliedActiveOpticForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventAppliedActiveOpticForcesField.vi"/>
				<Item Name="GetEventAppliedAzimuthForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventAppliedAzimuthForcesField.vi"/>
				<Item Name="GetEventAppliedBalanceForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventAppliedBalanceForcesField.vi"/>
				<Item Name="GetEventAppliedCylinderForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventAppliedCylinderForcesField.vi"/>
				<Item Name="GetEventAppliedElevationForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventAppliedElevationForcesField.vi"/>
				<Item Name="GetEventAppliedForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventAppliedForcesField.vi"/>
				<Item Name="GetEventAppliedOffsetForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventAppliedOffsetForcesField.vi"/>
				<Item Name="GetEventAppliedStaticForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventAppliedStaticForcesField.vi"/>
				<Item Name="GetEventAppliedThermalForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventAppliedThermalForcesField.vi"/>
				<Item Name="GetEventAppliedVelocityForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventAppliedVelocityForcesField.vi"/>
				<Item Name="GetEventForceActuatorForceWarningField.vi" Type="VI" URL="../Utilities/SAL/GetEventForceActuatorForceWarningField.vi"/>
				<Item Name="GetEventForceActuatorInfoField.vi" Type="VI" URL="../Utilities/SAL/GetEventForceActuatorInfoField.vi"/>
				<Item Name="GetEventForceActuatorStateField.vi" Type="VI" URL="../Utilities/SAL/GetEventForceActuatorStateField.vi"/>
				<Item Name="GetEventForceActuatorWarningField.vi" Type="VI" URL="../Utilities/SAL/GetEventForceActuatorWarningField.vi"/>
				<Item Name="GetEventForceSetpointWarningField.vi" Type="VI" URL="../Utilities/SAL/GetEventForceSetpointWarningField.vi"/>
				<Item Name="GetEventHardpointActuatorInfoField.vi" Type="VI" URL="../Utilities/SAL/GetEventHardpointActuatorInfoField.vi"/>
				<Item Name="GetEventHardpointActuatorStateField.vi" Type="VI" URL="../Utilities/SAL/GetEventHardpointActuatorStateField.vi"/>
				<Item Name="GetEventHardpointActuatorWarningField.vi" Type="VI" URL="../Utilities/SAL/GetEventHardpointActuatorWarningField.vi"/>
				<Item Name="GetEventHardpointMonitorInfoField.vi" Type="VI" URL="../Utilities/SAL/GetEventHardpointMonitorInfoField.vi"/>
				<Item Name="GetEventHardpointMonitorStateField.vi" Type="VI" URL="../Utilities/SAL/GetEventHardpointMonitorStateField.vi"/>
				<Item Name="GetEventHardpointMonitorWarningField.vi" Type="VI" URL="../Utilities/SAL/GetEventHardpointMonitorWarningField.vi"/>
				<Item Name="GetEventRejectedAberrationForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventRejectedAberrationForcesField.vi"/>
				<Item Name="GetEventRejectedAccelerationForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventRejectedAccelerationForcesField.vi"/>
				<Item Name="GetEventRejectedActiveOpticForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventRejectedActiveOpticForcesField.vi"/>
				<Item Name="GetEventRejectedAzimuthForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventRejectedAzimuthForcesField.vi"/>
				<Item Name="GetEventRejectedBalanceForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventRejectedBalanceForcesField.vi"/>
				<Item Name="GetEventRejectedCylinderForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventRejectedCylinderForcesField.vi"/>
				<Item Name="GetEventRejectedElevationForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventRejectedElevationForcesField.vi"/>
				<Item Name="GetEventRejectedForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventRejectedForcesField.vi"/>
				<Item Name="GetEventRejectedOffsetForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventRejectedOffsetForcesField.vi"/>
				<Item Name="GetEventRejectedStaticForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventRejectedStaticForcesField.vi"/>
				<Item Name="GetEventRejectedThermalForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventRejectedThermalForcesField.vi"/>
				<Item Name="GetEventRejectedVelocityForcesField.vi" Type="VI" URL="../Utilities/SAL/GetEventRejectedVelocityForcesField.vi"/>
				<Item Name="GetForceActuatorDataField.vi" Type="VI" URL="../Utilities/SAL/GetForceActuatorDataField.vi"/>
				<Item Name="GetGyroDataField.vi" Type="VI" URL="../Utilities/SAL/GetGyroDataField.vi"/>
				<Item Name="GetHardpointActuatorDataField.vi" Type="VI" URL="../Utilities/SAL/GetHardpointActuatorDataField.vi"/>
				<Item Name="GetHardpointMonitorDataField.vi" Type="VI" URL="../Utilities/SAL/GetHardpointMonitorDataField.vi"/>
				<Item Name="GetIMSDataField.vi" Type="VI" URL="../Utilities/SAL/GetIMSDataField.vi"/>
				<Item Name="GetInclinometerDataField.vi" Type="VI" URL="../Utilities/SAL/GetInclinometerDataField.vi"/>
				<Item Name="GetOuterLoopDataField.vi" Type="VI" URL="../Utilities/SAL/GetOuterLoopDataField.vi"/>
				<Item Name="GetPIDDataField.vi" Type="VI" URL="../Utilities/SAL/GetPIDDataField.vi"/>
				<Item Name="GetPowerSupplyDataField.vi" Type="VI" URL="../Utilities/SAL/GetPowerSupplyDataField.vi"/>
				<Item Name="GetRejectedForcesField.vi" Type="VI" URL="../Utilities/SAL/GetRejectedForcesField.vi"/>
			</Item>
		</Item>
		<Item Name="M1M3SupportEUI_TypeDefs.lvlib" Type="Library" URL="../Typedefs/M1M3SupportEUI_TypeDefs.lvlib"/>
		<Item Name="M1M3SupportEUI_Views.lvlib" Type="Library" URL="../View/M1M3SupportEUI_Views.lvlib"/>
		<Item Name="SALLV_m1m3.lvlib" Type="Library" URL="../SALLV_m1m3/SALLV_m1m3.lvlib"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="3D Plot Datatype.lvclass" Type="LVClass" URL="/&lt;vilib&gt;/Math Plots/3D Math Plots/3D Plot/3D Plot Datatype/3D Plot Datatype.lvclass"/>
				<Item Name="3D Plot.lvclass" Type="LVClass" URL="/&lt;vilib&gt;/Math Plots/3D Math Plots/3D Plot/3D Plot/3D Plot.lvclass"/>
				<Item Name="3D Scatter Datatype.lvclass" Type="LVClass" URL="/&lt;vilib&gt;/Math Plots/3D Math Plots/3D Scatter/3D Scatter Datatype/3D Scatter Datatype.lvclass"/>
				<Item Name="3D Scatter.lvclass" Type="LVClass" URL="/&lt;vilib&gt;/Math Plots/3D Math Plots/3D Scatter/3D Scatter/3D Scatter.lvclass"/>
				<Item Name="3D Scatter.xctl" Type="XControl" URL="/&lt;vilib&gt;/Math Plots/3D Math Plots/3D Scatter/3D Scatter XCtrl/3D Scatter.xctl"/>
				<Item Name="3DMathPlot Action String.ctl" Type="VI" URL="/&lt;vilib&gt;/Math Plots/3D Math Plots/3D Plot/Action String/3DMathPlot Action String.ctl"/>
				<Item Name="3DMathPlot Action String.vi" Type="VI" URL="/&lt;vilib&gt;/Math Plots/3D Math Plots/3D Plot/Action String/3DMathPlot Action String.vi"/>
				<Item Name="3DMathPlot Ctrl Act Cluster.ctl" Type="VI" URL="/&lt;vilib&gt;/Math Plots/3D Math Plots/3D Plot/Action String/3DMathPlot Ctrl Act Cluster.ctl"/>
				<Item Name="3DMathPlot Ctrl Act Queue.ctl" Type="VI" URL="/&lt;vilib&gt;/Math Plots/3D Math Plots/3D Plot/Action String/3DMathPlot Ctrl Act Queue.ctl"/>
				<Item Name="3DMathPlot State Class.ctl" Type="VI" URL="/&lt;vilib&gt;/Math Plots/3D Math Plots/3D Plot/Action String/3DMathPlot State Class.ctl"/>
				<Item Name="BuildHelpPath.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/BuildHelpPath.vi"/>
				<Item Name="Check Special Tags.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Check Special Tags.vi"/>
				<Item Name="Check if File or Folder Exists.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/libraryn.llb/Check if File or Folder Exists.vi"/>
				<Item Name="Clear Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Clear Errors.vi"/>
				<Item Name="Close File+.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Close File+.vi"/>
				<Item Name="Color to RGB.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/colorconv.llb/Color to RGB.vi"/>
				<Item Name="Convert property node font to graphics font.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Convert property node font to graphics font.vi"/>
				<Item Name="Details Display Dialog.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Details Display Dialog.vi"/>
				<Item Name="DialogType.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/DialogType.ctl"/>
				<Item Name="DialogTypeEnum.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/DialogTypeEnum.ctl"/>
				<Item Name="Draw Flattened Pixmap.vi" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/Draw Flattened Pixmap.vi"/>
				<Item Name="ErrWarn.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/ErrWarn.ctl"/>
				<Item Name="Error Cluster From Error Code.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Cluster From Error Code.vi"/>
				<Item Name="Error Code Database.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Code Database.vi"/>
				<Item Name="Find First Error.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Find First Error.vi"/>
				<Item Name="Find Tag.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Find Tag.vi"/>
				<Item Name="FindCloseTagByName.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/xml.llb/FindCloseTagByName.vi"/>
				<Item Name="FindElement.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/xml.llb/FindElement.vi"/>
				<Item Name="FindElementStartByName.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/xml.llb/FindElementStartByName.vi"/>
				<Item Name="FindEmptyElement.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/xml.llb/FindEmptyElement.vi"/>
				<Item Name="FindFirstTag.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/xml.llb/FindFirstTag.vi"/>
				<Item Name="FindMatchingCloseTag.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/xml.llb/FindMatchingCloseTag.vi"/>
				<Item Name="FixBadRect.vi" Type="VI" URL="/&lt;vilib&gt;/picture/pictutil.llb/FixBadRect.vi"/>
				<Item Name="Format Message String.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Format Message String.vi"/>
				<Item Name="General Error Handler Core CORE.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/General Error Handler Core CORE.vi"/>
				<Item Name="General Error Handler.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/General Error Handler.vi"/>
				<Item Name="Get String Text Bounds.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Get String Text Bounds.vi"/>
				<Item Name="Get Text Rect.vi" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/Get Text Rect.vi"/>
				<Item Name="GetHelpDir.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/GetHelpDir.vi"/>
				<Item Name="GetRTHostConnectedProp.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/GetRTHostConnectedProp.vi"/>
				<Item Name="LV3DPointTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/miscctls.llb/LV3DPointTypeDef.ctl"/>
				<Item Name="LVBoundsTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/miscctls.llb/LVBoundsTypeDef.ctl"/>
				<Item Name="LVRectTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/miscctls.llb/LVRectTypeDef.ctl"/>
				<Item Name="LVRowAndColumnTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/miscctls.llb/LVRowAndColumnTypeDef.ctl"/>
				<Item Name="LVRowAndColumnUnsignedTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/miscctls.llb/LVRowAndColumnUnsignedTypeDef.ctl"/>
				<Item Name="Longest Line Length in Pixels.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Longest Line Length in Pixels.vi"/>
				<Item Name="NI_3D Picture Control.lvlib" Type="Library" URL="/&lt;vilib&gt;/picture/3D Picture Control/NI_3D Picture Control.lvlib"/>
				<Item Name="NI_Data Type.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/Data Type/NI_Data Type.lvlib"/>
				<Item Name="NI_FileType.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/lvfile.llb/NI_FileType.lvlib"/>
				<Item Name="NI_Math Plot Private Lib.lvlib" Type="Library" URL="/&lt;vilib&gt;/Math Plots/Plot Private Lib/NI_Math Plot Private Lib.lvlib"/>
				<Item Name="NI_PackedLibraryUtility.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/LVLibp/NI_PackedLibraryUtility.lvlib"/>
				<Item Name="Not Found Dialog.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Not Found Dialog.vi"/>
				<Item Name="Open File+.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Open File+.vi"/>
				<Item Name="Open_Create_Replace File.vi" Type="VI" URL="/&lt;vilib&gt;/_oldvers/_oldvers.llb/Open_Create_Replace File.vi"/>
				<Item Name="ParseXMLFragments.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/xml.llb/ParseXMLFragments.vi"/>
				<Item Name="Read Delimited Spreadsheet (DBL).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Read Delimited Spreadsheet (DBL).vi"/>
				<Item Name="Read Delimited Spreadsheet (I64).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Read Delimited Spreadsheet (I64).vi"/>
				<Item Name="Read Delimited Spreadsheet (string).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Read Delimited Spreadsheet (string).vi"/>
				<Item Name="Read Delimited Spreadsheet.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Read Delimited Spreadsheet.vi"/>
				<Item Name="Read File+ (string).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Read File+ (string).vi"/>
				<Item Name="Read From XML File(array).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/xml.llb/Read From XML File(array).vi"/>
				<Item Name="Read From XML File(string).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/xml.llb/Read From XML File(string).vi"/>
				<Item Name="Read From XML File.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/xml.llb/Read From XML File.vi"/>
				<Item Name="Read Lines From File (with error IO).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Read Lines From File (with error IO).vi"/>
				<Item Name="Search and Replace Pattern.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Search and Replace Pattern.vi"/>
				<Item Name="Set Bold Text.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Set Bold Text.vi"/>
				<Item Name="Set String Value.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Set String Value.vi"/>
				<Item Name="Simple Error Handler.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Simple Error Handler.vi"/>
				<Item Name="TagReturnType.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/TagReturnType.ctl"/>
				<Item Name="Three Button Dialog CORE.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Three Button Dialog CORE.vi"/>
				<Item Name="Three Button Dialog.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Three Button Dialog.vi"/>
				<Item Name="Trim Whitespace.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Trim Whitespace.vi"/>
				<Item Name="Version To Dotted String.vi" Type="VI" URL="/&lt;vilib&gt;/_xctls/Version To Dotted String.vi"/>
				<Item Name="Write to XML File(array).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/xml.llb/Write to XML File(array).vi"/>
				<Item Name="Write to XML File(string).vi" Type="VI" URL="/&lt;vilib&gt;/Utility/xml.llb/Write to XML File(string).vi"/>
				<Item Name="Write to XML File.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/xml.llb/Write to XML File.vi"/>
				<Item Name="XControlSupport.lvlib" Type="Library" URL="/&lt;vilib&gt;/_xctls/XControlSupport.lvlib"/>
				<Item Name="compatCalcOffset.vi" Type="VI" URL="/&lt;vilib&gt;/_oldvers/_oldvers.llb/compatCalcOffset.vi"/>
				<Item Name="compatFileDialog.vi" Type="VI" URL="/&lt;vilib&gt;/_oldvers/_oldvers.llb/compatFileDialog.vi"/>
				<Item Name="compatOpenFileOperation.vi" Type="VI" URL="/&lt;vilib&gt;/_oldvers/_oldvers.llb/compatOpenFileOperation.vi"/>
				<Item Name="compatReadText.vi" Type="VI" URL="/&lt;vilib&gt;/_oldvers/_oldvers.llb/compatReadText.vi"/>
				<Item Name="eventvkey.ctl" Type="VI" URL="/&lt;vilib&gt;/event_ctls.llb/eventvkey.ctl"/>
				<Item Name="imagedata.ctl" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/imagedata.ctl"/>
				<Item Name="whitespace.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/whitespace.ctl"/>
			</Item>
		</Item>
		<Item Name="Build Specifications" Type="Build">
			<Item Name="M1M3SupportEUIBuild" Type="EXE">
				<Property Name="App_INI_aliasGUID" Type="Str">{ED2F1D7A-DB7F-11E7-B351-509A4C4F3C9F}</Property>
				<Property Name="App_INI_GUID" Type="Str">{ED2F1CB3-DB7F-11E7-B351-509A4C4F3C9F}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{ED2F2A63-DB7F-11E7-B351-509A4C4F3C9F}</Property>
				<Property Name="Bld_buildSpecDescription" Type="Str">The M1M3 Support Engineering User Interface program</Property>
				<Property Name="Bld_buildSpecName" Type="Str">M1M3SupportEUIBuild</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds/NI_AB_PROJECTNAME</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{ED2F2A03-DB7F-11E7-B351-509A4C4F3C9F}</Property>
				<Property Name="Bld_supportedLanguageCount" Type="Int">1</Property>
				<Property Name="Bld_supportedLanguage[0]" Type="Str">English</Property>
				<Property Name="Bld_version.build" Type="Int">28</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="DestinationCount" Type="Int">4</Property>
				<Property Name="Destination[0].destName" Type="Str">M1M3SupportEUI</Property>
				<Property Name="Destination[0].path" Type="Path">../builds/NI_AB_PROJECTNAME/M1M3SupportEUI</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../builds/NI_AB_PROJECTNAME/data</Property>
				<Property Name="Destination[2].destName" Type="Str">ConfigFiles</Property>
				<Property Name="Destination[2].path" Type="Path">../builds/NI_AB_PROJECTNAME/ConfigFiles</Property>
				<Property Name="Destination[2].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[3].destName" Type="Str">StartupScripts</Property>
				<Property Name="Destination[3].path" Type="Path">../builds/NI_AB_PROJECTNAME</Property>
				<Property Name="Destination[3].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="SourceCount" Type="Int">19</Property>
				<Property Name="Source[0].itemID" Type="Str">{806F2576-309A-11E8-8669-509A4C4F3C9F}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[10].Container.applyInclusion" Type="Bool">true</Property>
				<Property Name="Source[10].Container.depDestIndex" Type="Int">0</Property>
				<Property Name="Source[10].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[10].itemID" Type="Ref">/My Computer/Controller</Property>
				<Property Name="Source[10].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[10].type" Type="Str">Container</Property>
				<Property Name="Source[11].Container.applyInclusion" Type="Bool">true</Property>
				<Property Name="Source[11].Container.depDestIndex" Type="Int">0</Property>
				<Property Name="Source[11].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[11].itemID" Type="Ref">/My Computer/Configuration</Property>
				<Property Name="Source[11].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[11].type" Type="Str">Container</Property>
				<Property Name="Source[12].Container.applyDestination" Type="Bool">true</Property>
				<Property Name="Source[12].Container.applyInclusion" Type="Bool">true</Property>
				<Property Name="Source[12].Container.depDestIndex" Type="Int">0</Property>
				<Property Name="Source[12].destinationIndex" Type="Int">2</Property>
				<Property Name="Source[12].itemID" Type="Ref">/My Computer/ConfigFiles</Property>
				<Property Name="Source[12].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[12].type" Type="Str">Container</Property>
				<Property Name="Source[13].Container.applyInclusion" Type="Bool">true</Property>
				<Property Name="Source[13].Container.depDestIndex" Type="Int">0</Property>
				<Property Name="Source[13].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[13].itemID" Type="Ref">/My Computer/Model</Property>
				<Property Name="Source[13].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[13].type" Type="Str">Container</Property>
				<Property Name="Source[14].Container.applyInclusion" Type="Bool">true</Property>
				<Property Name="Source[14].Container.depDestIndex" Type="Int">0</Property>
				<Property Name="Source[14].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[14].itemID" Type="Ref">/My Computer/SAL</Property>
				<Property Name="Source[14].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[14].type" Type="Str">Container</Property>
				<Property Name="Source[15].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[15].itemID" Type="Ref">/My Computer/M1M3SupportEUI_TypeDefs.lvlib</Property>
				<Property Name="Source[15].Library.allowMissingMembers" Type="Bool">true</Property>
				<Property Name="Source[15].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[15].type" Type="Str">Library</Property>
				<Property Name="Source[16].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[16].itemID" Type="Ref">/My Computer/M1M3SupportEUI_Views.lvlib</Property>
				<Property Name="Source[16].Library.allowMissingMembers" Type="Bool">true</Property>
				<Property Name="Source[16].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[16].type" Type="Str">Library</Property>
				<Property Name="Source[17].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[17].itemID" Type="Ref">/My Computer/SALLV_m1m3.lvlib</Property>
				<Property Name="Source[17].Library.allowMissingMembers" Type="Bool">true</Property>
				<Property Name="Source[17].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[17].type" Type="Str">Library</Property>
				<Property Name="Source[18].Container.applyDestination" Type="Bool">true</Property>
				<Property Name="Source[18].Container.applyInclusion" Type="Bool">true</Property>
				<Property Name="Source[18].Container.depDestIndex" Type="Int">0</Property>
				<Property Name="Source[18].destinationIndex" Type="Int">3</Property>
				<Property Name="Source[18].itemID" Type="Ref">/My Computer/StartupScripts</Property>
				<Property Name="Source[18].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[18].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/M1M3SupportEUI_Views.lvlib/M1M3SupportEUI_View.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="Source[2].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[2].itemID" Type="Ref">/My Computer/M1M3SupportEUI_Views.lvlib/Application Control View.vi</Property>
				<Property Name="Source[2].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[2].type" Type="Str">VI</Property>
				<Property Name="Source[3].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[3].itemID" Type="Ref">/My Computer/M1M3SupportEUI_Views.lvlib/Application Status View.vi</Property>
				<Property Name="Source[3].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[3].type" Type="Str">VI</Property>
				<Property Name="Source[4].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[4].itemID" Type="Ref">/My Computer/M1M3SupportEUI_Views.lvlib/Displacement Graph View.vi</Property>
				<Property Name="Source[4].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[4].type" Type="Str">VI</Property>
				<Property Name="Source[5].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[5].itemID" Type="Ref">/My Computer/M1M3SupportEUI_Views.lvlib/FA Values View.vi</Property>
				<Property Name="Source[5].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[5].type" Type="Str">VI</Property>
				<Property Name="Source[6].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[6].itemID" Type="Ref">/My Computer/M1M3SupportEUI_Views.lvlib/Inclinometer Graph View.vi</Property>
				<Property Name="Source[6].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[6].type" Type="Str">VI</Property>
				<Property Name="Source[7].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[7].itemID" Type="Ref">/My Computer/M1M3SupportEUI_Views.lvlib/Other Status.vi</Property>
				<Property Name="Source[7].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[7].type" Type="Str">VI</Property>
				<Property Name="Source[8].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[8].itemID" Type="Ref">/My Computer/M1M3SupportEUI_Views.lvlib/Scan Control View.vi</Property>
				<Property Name="Source[8].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[8].type" Type="Str">VI</Property>
				<Property Name="Source[9].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[9].itemID" Type="Ref">/My Computer/M1M3SupportEUI_Views.lvlib/Warning Fault Tree View.vi</Property>
				<Property Name="Source[9].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[9].type" Type="Str">VI</Property>
				<Property Name="TgtF_fileDescription" Type="Str">M1M3SupportEUIBuild</Property>
				<Property Name="TgtF_internalName" Type="Str">M1M3SupportEUIBuild</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright 2017 </Property>
				<Property Name="TgtF_productName" Type="Str">M1M3SupportEUIBuild</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{ED2F28BD-DB7F-11E7-B351-509A4C4F3C9F}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">M1M3SupportEUI</Property>
			</Item>
			<Item Name="TestGenerateEvents" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{C1386FA6-53A3-11E8-B351-68F728E1C553}</Property>
				<Property Name="App_INI_GUID" Type="Str">{C1386DCE-53A3-11E8-B351-68F728E1C553}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="App_waitDebugging" Type="Bool">true</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{C13891DB-53A3-11E8-B351-68F728E1C553}</Property>
				<Property Name="Bld_buildSpecDescription" Type="Str">a quicker build to figure out why the generate events is creating an Error 1 on build but not when we run from labview.</Property>
				<Property Name="Bld_buildSpecName" Type="Str">TestGenerateEvents</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds/NI_AB_PROJECTNAME/TestGenerateEvents</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{C1389117-53A3-11E8-B351-68F728E1C553}</Property>
				<Property Name="Bld_supportedLanguageCount" Type="Int">1</Property>
				<Property Name="Bld_supportedLanguage[0]" Type="Str">English</Property>
				<Property Name="Bld_version.build" Type="Int">2</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Destination[0].destName" Type="Str">TestGenerateEvents</Property>
				<Property Name="Destination[0].path" Type="Path">../builds/NI_AB_PROJECTNAME/TestGenerateEvents/TestGenerateEvents</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../builds/NI_AB_PROJECTNAME/TestGenerateEvents/data</Property>
				<Property Name="SourceCount" Type="Int">5</Property>
				<Property Name="Source[0].itemID" Type="Str">{0F121C96-53A0-11E8-8669-68F728E1C553}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref"></Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="Source[2].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[2].itemID" Type="Ref">/My Computer/M1M3SupportEUI_TypeDefs.lvlib</Property>
				<Property Name="Source[2].Library.allowMissingMembers" Type="Bool">true</Property>
				<Property Name="Source[2].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[2].type" Type="Str">Library</Property>
				<Property Name="Source[3].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[3].itemID" Type="Ref">/My Computer/SALLV_m1m3.lvlib</Property>
				<Property Name="Source[3].Library.allowMissingMembers" Type="Bool">true</Property>
				<Property Name="Source[3].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[3].type" Type="Str">Library</Property>
				<Property Name="Source[4].Container.applyInclusion" Type="Bool">true</Property>
				<Property Name="Source[4].Container.depDestIndex" Type="Int">0</Property>
				<Property Name="Source[4].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[4].itemID" Type="Ref">/My Computer/Model</Property>
				<Property Name="Source[4].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[4].type" Type="Str">Container</Property>
				<Property Name="TgtF_enableDebugging" Type="Bool">true</Property>
				<Property Name="TgtF_fileDescription" Type="Str">TestGenerateEvents</Property>
				<Property Name="TgtF_internalName" Type="Str">TestGenerateEvents</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright 2018 </Property>
				<Property Name="TgtF_productName" Type="Str">TestGenerateEvents</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{C1388DAE-53A3-11E8-B351-68F728E1C553}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">TestGenerateEvents</Property>
			</Item>
		</Item>
	</Item>
</Project>
