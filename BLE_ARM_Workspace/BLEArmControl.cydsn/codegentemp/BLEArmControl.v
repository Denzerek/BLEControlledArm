// ======================================================================
// BLEArmControl.v generated from TopDesign.cysch
// 10/19/2021 at 18:18
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_FAMILY_PSOC6 4
`define CYDEV_CHIP_FAMILY_FM0P 5
`define CYDEV_CHIP_FAMILY_FM3 6
`define CYDEV_CHIP_FAMILY_FM4 7
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_MEMBER_5B 2
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 3
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_4G 4
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 5
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 6
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0
`define CYDEV_CHIP_MEMBER_4X 7
`define CYDEV_CHIP_REVISION_4X_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4O 8
`define CYDEV_CHIP_REVISION_4O_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4R 9
`define CYDEV_CHIP_REVISION_4R_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4T 10
`define CYDEV_CHIP_REVISION_4T_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 11
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4S 12
`define CYDEV_CHIP_REVISION_4S_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4W 13
`define CYDEV_CHIP_REVISION_4W_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AC 14
`define CYDEV_CHIP_REVISION_4AC_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AD 15
`define CYDEV_CHIP_REVISION_4AD_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AE 16
`define CYDEV_CHIP_REVISION_4AE_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Q 17
`define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Y 18
`define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Z 19
`define CYDEV_CHIP_REVISION_4Z_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 20
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 21
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 22
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4V 23
`define CYDEV_CHIP_REVISION_4V_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 24
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AA 25
`define CYDEV_CHIP_REVISION_4AA_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 26
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 27
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4P 28
`define CYDEV_CHIP_REVISION_4P_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4M 29
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AB 30
`define CYDEV_CHIP_REVISION_4AB_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 31
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 32
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_6A 33
`define CYDEV_CHIP_REVISION_6A_ES 17
`define CYDEV_CHIP_REVISION_6A_PRODUCTION 33
`define CYDEV_CHIP_REVISION_6A_NO_UDB 33
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 34
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 35
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 36
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM3 37
`define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM4 38
`define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_USED 4
`define CYDEV_CHIP_MEMBER_USED 33
`define CYDEV_CHIP_REVISION_USED 33
// Component: mux_v1_10
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\mux_v1_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\mux_v1_10\mux_v1_10.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\mux_v1_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\mux_v1_10\mux_v1_10.v"
`endif

// Component: cy_constant_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`endif

// TCPWM_PWM_PDL_v1_0(ClockPrescaler=2, Compare0=0, Compare1=16384, CountInput=7, CountInputMasked=3, DeadClocks=0, EnableCompareSwap=false, EnablePeriodSwap=false, InterruptSource=0, InvertPwm=false, InvertPwm_n=false, KillInput=7, KillInputMasked=3, KillMode=2, Period0=100, Period1=32768, PwmAlignment=0, PwmMode=4, ReloadInput=7, ReloadInputMasked=3, Resolution=16, RunMode=0, StartInput=7, StartInputMasked=3, SwapInput=7, SwapInputMasked=3, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=TCPWM_PWM_PDL_v1_0, CY_CONFIG_TITLE=Dimmer, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Dimmer, CY_INSTANCE_SHORT_NAME=Dimmer, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=tcpwm, CY_PDL_DRIVER_REQ_VERSION=1.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=Dimmer, )
module TCPWM_PWM_PDL_v1_0_0 (
    clock,
    compare,
    count,
    interrupt,
    kill,
    ovrflw,
    pwm,
    pwm_n,
    reload,
    start,
    swap,
    undrflw);
    input       clock;
    output      compare;
    input       count;
    output      interrupt;
    input       kill;
    output      ovrflw;
    output      pwm;
    output      pwm_n;
    input       reload;
    input       start;
    input       swap;
    output      undrflw;



    cy_mxs40_tcpwm_v1_0 TCPWM (
        .capture(swap),
        .clock(clock),
        .count(count),
        .interrupt(interrupt),
        .line(pwm),
        .line_compl(pwm_n),
        .reload(reload),
        .start(start),
        .stop(kill),
        .tr_compare_match(compare),
        .tr_overflow(ovrflw),
        .tr_underflow(undrflw));
    defparam TCPWM.exact_width = 0;
    defparam TCPWM.width = 16;



endmodule

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// Component: cy_analog_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`endif

// Component: or_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0\or_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0\or_v1_0.v"
`endif

// CapSense_v3_0(AdcAmuxbInputEnable=false, AdcAnalogStartupDelayUs=23, AdcAzEnable=true, AdcAzTime=5, AdcDedicatedChannels=0, AdcEnable=false, AdcMeasureMode=0, AdcPinAlias=Ch0, AdcResolution=10, AdcSelectAmuxBusChannel=0, AdcTotalChannels=0, AdcVref=-1, BallisticMultiplierEnable=false, BaselineType=0, BlockOffAfterScanEnable=false, Centroid4PtsEnable=false, ClickEnable=true, Csd0IdacGainV1=4, Csd0IdacGainV2=2, Csd0PinAlias=LinearSlider0_Sns0,LinearSlider0_Sns1,LinearSlider0_Sns2,LinearSlider0_Sns3,LinearSlider0_Sns4, Csd0PinCount=5, Csd0ShieldDelayV1=0, Csd0ShieldDelayV2=0, Csd0ShieldEnable=false, Csd0ShieldPrechargeSource=0, Csd0ShieldTankEnable=false, Csd0TotalShieldCount=1, Csd1IdacGainV1=4, Csd1IdacGainV2=2, Csd1PinAlias=, Csd1PinCount=0, Csd1ShieldDelayV1=0, Csd1ShieldDelayV2=0, Csd1ShieldEnable=false, Csd1ShieldPrechargeSource=0, Csd1ShieldTankEnable=false, Csd1TotalShieldCount=1, Csd2xEnable=false, CsdAnalogStartupDelayUs=23, CsdAutoZeroEnable=false, CsdAutoZeroTime=15, CsdCommonSenseClockEnable=false, CsdDedicatedIdacCompEnable=true, CsdDualIdacLevel=50, CsdEnable=true, CsdF1PMSwitchResLowEmiInit=1, CsdF1PMSwitchResLowEmiScan=0, CsdF2PTSwitchResLowEmiInit=1, CsdF2PTSwitchResLowEmiScan=0, CsdFineInitCycles=10, CsdHCAGSwitchResLowEmiInit=1, CsdHCAGSwitchResLowEmiScan=3, CsdHCAVSwitchResLowEmiInit=1, CsdHCAVSwitchResLowEmiScan=0, CsdHCBGSwitchResLowEmiInit=1, CsdHCBGSwitchResLowEmiScan=3, CsdHCBVSwitchResLowEmiInit=1, CsdHCBVSwitchResLowEmiScan=3, CsdIdacAutoCalibrateEnable=true, CsdIdacCompEnable=true, CsdIdacConfig=0, CsdInactiveSensorConnection=0, CsdInitSwitchRes=1, CsdMFSDividerOffsetF1=1, CsdMFSDividerOffsetF2=2, CsdModClockFreq=50000, CsdNoiseMetricEnable=false, CsdNoiseMetricThreshold=1, CsdPrescanSettlingTime=5, CsdRawCountCalibrationLevel=85, CsdSenseClockFreq=3125, CsdSenseClockSource=1, CsdSenseWidthLowEmi=10, CsdSensingMethod=0, CsdShieldSwitchRes=1, CsdSnsClockConstantR=1000, CsdTuningMode=3, CsdV2AnalogWakeupDelayUs=0, CsdVrefV2=-1, Csx0IdacGainV1=4, Csx0IdacGainV2=1, Csx0PinAliasRx=, Csx0PinCountRx=0, Csx1IdacGainV1=4, Csx1IdacGainV2=1, Csx1PinAliasRx=, Csx1PinCountRx=0, Csx2xEnable=false, CsxAnalogStartupDelayUs=23, CsxAutoZeroEnable=false, CsxAutoZeroTime=15, CsxCommonTxClockEnable=false, CsxEnable=true, CsxFineInitCycles=4, CsxIdacAutoCalibrateEnable=true, CsxIdacBitsUsedV1=8, CsxIdacBitsUsedV2=7, CsxInitShieldSwitchRes=2, CsxInitSwitchRes=1, CsxMaxFingers=1, CsxMaxLocalPeaks=5, CsxMFSDividerOffsetF1=1, CsxMFSDividerOffsetF2=2, CsxModClockFreq=12500, CsxMultiphaseTxEnable=false, CsxNoiseMetricEnable=false, CsxNoiseMetricThreshold=1, CsxPinAliasMptx=, CsxPinAliasRx=Button0_Rx0,Button1_Rx0, CsxPinAliasTx=Button0_Tx, CsxPinCountMptx=0, CsxPinCountRx=2, CsxPinCountTx=1, CsxRawCountCalibrationLevel=40, CsxScanShieldSwitchRes=0, CsxScanSwitchRes=0, CsxSkipAndOversampleNodes=false, CsxTxClockFreq=300, CsxTxClockSource=1, CustomDataStructSize=0, DoxygenMode=false, GestureEnable=true, GestureGlobalEnable=true, IrefSel=0, IsAdcSupported=true, IsCapSenseSupported=true, IsGestureSupported=true, LowBaselineResetSize=8, LpModeEn=false, MultiFreqScanEnable=false, NumCentroids=1, OffDebounceEnable=false, OneFingerEdgeSwipeEnable=false, OneFingerEdgeSwipeTimeoutInterval=2000, OneFingerFlickEnable=true, OneFingerRotateEnable=false, OneFingerScrollEnable=false, PosIirFilterCoeff=128, ProxAlpFilterCoeff=2, ProxAlpFilterEnable=false, ProxAverageFilterEnable=false, ProxAverageFilterSampleSize=4, ProxCustomFilterEnable=false, ProxIirFilterBaselineN=1, ProxIirFilterBaselineType=2, ProxIirFilterEnable=false, ProxIirFilterRawCountN=128, ProxIirFilterRawCountType=1, ProxMedianFilterEnable=false, RadialSliderPosIirResetThr=35, RegisterMapSelfTest=false, RegularAlpFilterCoeff=2, RegularAlpFilterEnable=false, RegularAverageFilterEnable=false, RegularAverageFilterSampleSize=4, RegularCustomFilterEnable=false, RegularIirFilterBaselineN=1, RegularIirFilterBaselineType=2, RegularIirFilterEnable=false, RegularIirFilterRawCountN=128, RegularIirFilterRawCountType=1, RegularMedianFilterEnable=false, SecondFinger5x5FilterEnable=false, SelfTestAnalogStartupDelayUs=23, SelfTestBaselineDuplicationEnable=true, SelfTestBaselineRawCountRangeEnable=true, SelfTestEnable=false, SelfTestExtCapEnable=true, SelfTestFineInitCycles=1, SelfTestGlobalCrcEnable=true, SelfTestIntCapEnable=true, SelfTestShCapEnable=true, SelfTestSns2SnsEnable=true, SelfTestSnsCapEnable=true, SelfTestSnsShortEnable=true, SelfTestVddaEnable=true, SelfTestVddaVref=-1, SelfTestWidgetCrcEnable=true, SensorAutoResetEnable=false, SensorAutoResetMethod=0, SensorAutoResetSamplesCount=1000, SliderMultiplierMethod=0, ThresholdSize=16, TimestampInterval=1, TouchpadDisplaySettings=, TouchpadMultiplierMethod=0, TouchProxThresholdCoeff=300, TunerLayoutPreferences=, TunerOptionsPreferences=, TunerViewPreferences=, TunerWidgetData=, TwoFingerScrollEnable=false, TwoFingerSettlingTime=3, TwoFingerZoomEnable=false, VddaValue=3.3, VrefSel=0, WidgetBaselineCoeffEnable=false, WidgetData=<?xml version="1.0" encoding="utf-16"?> <WidgetData xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">   <Widget id="Button0" type="Button" mode="CSX" block="CSD0" slot="0">     <Angle>0</Angle>     <FlippedX>false</FlippedX>     <FlippedY>false</FlippedY>     <Flipped2D>false</Flipped2D>     <ScaleFactor>1</ScaleFactor>     <Properties>       <FingerCap>0.16</FingerCap>       <Diplexing>false</Diplexing>       <MaxPosition>100</MaxPosition>       <MaxXPosition>100</MaxXPosition>       <MaxYPosition>100</MaxYPosition>       <PositionFilter>None</PositionFilter>       <MultiphaseTx>false</MultiphaseTx>       <SenseClockFreq>3125</SenseClockFreq>       <RowSenseClockFreq>3125</RowSenseClockFreq>       <TxClockFreq>300</TxClockFreq>       <IsxTxClockFreq>1000</IsxTxClockFreq>       <ScanResolution>_12</ScanResolution>       <NumConversions>100</NumConversions>       <IdacMod>         <Idac0>32</Idac0>         <Idac1>32</Idac1>         <Idac2>32</Idac2>       </IdacMod>       <RowIdacMod>         <Idac0>32</Idac0>         <Idac1>32</Idac1>         <Idac2>32</Idac2>       </RowIdacMod>       <FingerThreshold>100</FingerThreshold>       <ProxTouchThreshold>200</ProxTouchThreshold>       <NoiseThreshold>40</NoiseThreshold>       <NegNoiseThreshold>40</NegNoiseThreshold>       <LowBaselineReset>30</LowBaselineReset>       <BaselineReset>1000</BaselineReset>       <BaselineUpdateThreshold>100</BaselineUpdateThreshold>       <Hysteresis>10</Hysteresis>       <OnDebounce>3</OnDebounce>       <OffDebounce>3</OffDebounce>       <AlpOnThreshold>60</AlpOnThreshold>       <AlpOFFThreshold>20</AlpOFFThreshold>       <Velocity>2500</Velocity>       <MedianFilter>false</MedianFilter>       <IirFilter>false</IirFilter>       <IirFilterCoeff>128</IirFilterCoeff>       <AIirFilter>false</AIirFilter>       <AverageFilter>false</AverageFilter>       <JitterFilter>false</JitterFilter>       <BallisticMultiplier>false</BallisticMultiplier>       <AIirPositionMoveTh>3</AIirPositionMoveTh>       <AIirPositionSlowMoveTh>7</AIirPositionSlowMoveTh>       <AIirPositionFastMoveTh>12</AIirPositionFastMoveTh>       <AIirCoeffMaxLimit>60</AIirCoeffMaxLimit>       <AIirCoeffMinLimit>1</AIirCoeffMinLimit>       <AIirCoeffDivisor>64</AIirCoeffDivisor>       <CentroidType>Csd3x3</CentroidType>       <CrossCouplingPosTh>5</CrossCouplingPosTh>       <EdgeCorrectionEnable>true</EdgeCorrectionEnable>       <EdgeVirtualSensorTh>100</EdgeVirtualSensorTh>       <EdgePenultimateTh>100</EdgePenultimateTh>       <TwoFingerDetection>false</TwoFingerDetection>       <FastMovementMult>9</FastMovementMult>       <SlowMovementMult>2</SlowMovementMult>       <DivisorValue>4</DivisorValue>       <SpeedThresholdX>3</SpeedThresholdX>       <SpeedThresholdY>4</SpeedThresholdY>     </Properties>     <Gestures>       <Click>         <Enabled>false</Enabled>         <XMaxPosDisplacement>30</XMaxPosDisplacement>         <YMaxPosDisplacement>30</YMaxPosDisplacement>         <MaxPosDisplacement>30</MaxPosDisplacement>         <MaxRadius>20</MaxRadius>         <MaxDisplacement>20</MaxDisplacement>         <MinTouchInterval>10</MinTouchInterval>         <MaxTouchInterval>1000</MaxTouchInterval>         <OneFingerMinTouchDuration>10</OneFingerMinTouchDuration>         <OneFingerMaxTouchDuration>1000</OneFingerMaxTouchDuration>         <TwoFingerMinTouchDuration>100</TwoFingerMinTouchDuration>         <TwoFingerMaxTouchDuration>1000</TwoFingerMaxTouchDuration>       </Click>       <OneFingerScroll>         <Enabled>false</Enabled>         <Debounce>3</Debounce>         <XPosThreshold1>20</XPosThreshold1>         <YPosThreshold1>20</YPosThreshold1>         <PosThreshold1>20</PosThreshold1>         <ScrollStep1>3</ScrollStep1>         <XPosThreshold2>24</XPosThreshold2>         <YPosThreshold2>24</YPosThreshold2>         <F1_Scroll_PosThreshold2>20</F1_Scroll_PosThreshold2>         <ScrollStep2>5</ScrollStep2>         <XPosThreshold3>30</XPosThreshold3>         <YPosThreshold3>30</YPosThreshold3>         <PosThreshold3>20</PosThreshold3>         <ScrollStep3>7</ScrollStep3>         <XPosThreshold4>40</XPosThreshold4>         <YPosThreshold4>40</YPosThreshold4>         <PosThreshold4>20</PosThreshold4>         <ScrollStep4>9</ScrollStep4>         <XPosThreshold>50</XPosThreshold>         <YPosThreshold>50</YPosThreshold>         <PosThreshold>50</PosThreshold>         <CountLevel>Inert_Low</CountLevel>       </OneFingerScroll>       <TwoFingerScroll>         <Enabled>false</Enabled>         <Debounce>3</Debounce>         <XPosThreshold1>20</XPosThreshold1>         <YPosThreshold1>20</YPosThreshold1>         <PosThreshold1>20</PosThreshold1>         <ScrollStep1>3</ScrollStep1>         <XPosThreshold2>24</XPosThreshold2>         <YPosThreshold2>24</YPosThreshold2>         <PosThreshold2>24</PosThreshold2>         <ScrollStep2>5</ScrollStep2>         <XPosThreshold3>30</XPosThreshold3>         <YPosThreshold3>30</YPosThreshold3>         <PosThreshold3>30</PosThreshold3>         <ScrollStep3>7</ScrollStep3>         <XPosThreshold4>40</XPosThreshold4>         <YPosThreshold4>40</YPosThreshold4>         <PosThreshold4>40</PosThreshold4>         <ScrollStep4>9</ScrollStep4>         <XPosThreshold>50</XPosThreshold>         <YPosThreshold>50</YPosThreshold>         <PosThreshold>50</PosThreshold>         <CountLevel>Inert_Low</CountLevel>       </TwoFingerScroll>       <OneFingerFlick>         <Enabled>false</Enabled>         <XPosThreshold>20</XPosThreshold>         <YPosThreshold>20</YPosThreshold>         <PosThreshold>20</PosThreshold>         <MaxSampleInterval>80</MaxSampleInterval>       </OneFingerFlick>       <OneFingerEdgeSwipe>         <Enabled>false</Enabled>         <PosThreshold>100</PosThreshold>         <DetectionTime>100</DetectionTime>         <TimeoutInterval>2000</TimeoutInterval>         <TopAngleThreshold>45</TopAngleThreshold>         <BottomAngleThreshold>45</BottomAngleThreshold>         <DisamRegionWidth>5</DisamRegionWidth>       </OneFingerEdgeSwipe>       <TwoFingerZoom>         <Enabled>false</Enabled>         <XPosThreshold>8</XPosThreshold>         <YPosThreshold>8</YPosThreshold>         <PosThreshold>8</PosThreshold>         <Debounce>3</Debounce>         <ScrollZoomDebounce>5</ScrollZoomDebounce>       </TwoFingerZoom>       <OneFingerRotate>         <Enabled>false</Enabled>         <RotateDebounce>0</RotateDebounce>         <PosThreshold>8</PosThreshold>       </OneFingerRotate>     </Gestures>     <Columns>       <Sensor id="Rx0">         <Properties>           <IdacComp>             <Idac0>32</Idac0>             <Idac1>32</Idac1>             <Idac2>32</Idac2>           </IdacComp>           <Idacs>             <Idac>               <Idac0>32</Idac0>               <Idac1>32</Idac1>               <Idac2>32</Idac2>             </Idac>           </Idacs>           <UseDedicatedPin>true</UseDedicatedPin>           <GangedPins />         </Properties>       </Sensor>     </Columns>     <Rows>       <Sensor id="Tx">         <Properties>           <IdacComp>             <Idac0>32</Idac0>             <Idac1>32</Idac1>             <Idac2>32</Idac2>           </IdacComp>           <Idacs />           <UseDedicatedPin>true</UseDedicatedPin>           <GangedPins />         </Properties>       </Sensor>     </Rows>   </Widget>   <Widget id="Button1" type="Button" mode="CSX" block="CSD0" slot="0">     <Angle>0</Angle>     <FlippedX>false</FlippedX>     <FlippedY>false</FlippedY>     <Flipped2D>false</Flipped2D>     <ScaleFactor>1</ScaleFactor>     <Properties>       <FingerCap>0.16</FingerCap>       <Diplexing>false</Diplexing>       <MaxPosition>100</MaxPosition>       <MaxXPosition>100</MaxXPosition>       <MaxYPosition>100</MaxYPosition>       <PositionFilter>None</PositionFilter>       <MultiphaseTx>false</MultiphaseTx>       <SenseClockFreq>3125</SenseClockFreq>       <RowSenseClockFreq>3125</RowSenseClockFreq>       <TxClockFreq>300</TxClockFreq>       <IsxTxClockFreq>1000</IsxTxClockFreq>       <ScanResolution>_12</ScanResolution>       <NumConversions>100</NumConversions>       <IdacMod>         <Idac0>32</Idac0>         <Idac1>32</Idac1>         <Idac2>32</Idac2>       </IdacMod>       <RowIdacMod>         <Idac0>32</Idac0>         <Idac1>32</Idac1>         <Idac2>32</Idac2>       </RowIdacMod>       <FingerThreshold>100</FingerThreshold>       <ProxTouchThreshold>200</ProxTouchThreshold>       <NoiseThreshold>40</NoiseThreshold>       <NegNoiseThreshold>40</NegNoiseThreshold>       <LowBaselineReset>30</LowBaselineReset>       <BaselineReset>1000</BaselineReset>       <BaselineUpdateThreshold>100</BaselineUpdateThreshold>       <Hysteresis>10</Hysteresis>       <OnDebounce>3</OnDebounce>       <OffDebounce>3</OffDebounce>       <AlpOnThreshold>60</AlpOnThreshold>       <AlpOFFThreshold>20</AlpOFFThreshold>       <Velocity>2500</Velocity>       <MedianFilter>false</MedianFilter>       <IirFilter>false</IirFilter>       <IirFilterCoeff>128</IirFilterCoeff>       <AIirFilter>false</AIirFilter>       <AverageFilter>false</AverageFilter>       <JitterFilter>false</JitterFilter>       <BallisticMultiplier>false</BallisticMultiplier>       <AIirPositionMoveTh>3</AIirPositionMoveTh>       <AIirPositionSlowMoveTh>7</AIirPositionSlowMoveTh>       <AIirPositionFastMoveTh>12</AIirPositionFastMoveTh>       <AIirCoeffMaxLimit>60</AIirCoeffMaxLimit>       <AIirCoeffMinLimit>1</AIirCoeffMinLimit>       <AIirCoeffDivisor>64</AIirCoeffDivisor>       <CentroidType>Csd3x3</CentroidType>       <CrossCouplingPosTh>5</CrossCouplingPosTh>       <EdgeCorrectionEnable>true</EdgeCorrectionEnable>       <EdgeVirtualSensorTh>100</EdgeVirtualSensorTh>       <EdgePenultimateTh>100</EdgePenultimateTh>       <TwoFingerDetection>false</TwoFingerDetection>       <FastMovementMult>9</FastMovementMult>       <SlowMovementMult>2</SlowMovementMult>       <DivisorValue>4</DivisorValue>       <SpeedThresholdX>3</SpeedThresholdX>       <SpeedThresholdY>4</SpeedThresholdY>     </Properties>     <Gestures>       <Click>         <Enabled>false</Enabled>         <XMaxPosDisplacement>30</XMaxPosDisplacement>         <YMaxPosDisplacement>30</YMaxPosDisplacement>         <MaxPosDisplacement>30</MaxPosDisplacement>         <MaxRadius>20</MaxRadius>         <MaxDisplacement>20</MaxDisplacement>         <MinTouchInterval>10</MinTouchInterval>         <MaxTouchInterval>1000</MaxTouchInterval>         <OneFingerMinTouchDuration>10</OneFingerMinTouchDuration>         <OneFingerMaxTouchDuration>1000</OneFingerMaxTouchDuration>         <TwoFingerMinTouchDuration>100</TwoFingerMinTouchDuration>         <TwoFingerMaxTouchDuration>1000</TwoFingerMaxTouchDuration>       </Click>       <OneFingerScroll>         <Enabled>false</Enabled>         <Debounce>3</Debounce>         <XPosThreshold1>20</XPosThreshold1>         <YPosThreshold1>20</YPosThreshold1>         <PosThreshold1>20</PosThreshold1>         <ScrollStep1>3</ScrollStep1>         <XPosThreshold2>24</XPosThreshold2>         <YPosThreshold2>24</YPosThreshold2>         <F1_Scroll_PosThreshold2>20</F1_Scroll_PosThreshold2>         <ScrollStep2>5</ScrollStep2>         <XPosThreshold3>30</XPosThreshold3>         <YPosThreshold3>30</YPosThreshold3>         <PosThreshold3>20</PosThreshold3>         <ScrollStep3>7</ScrollStep3>         <XPosThreshold4>40</XPosThreshold4>         <YPosThreshold4>40</YPosThreshold4>         <PosThreshold4>20</PosThreshold4>         <ScrollStep4>9</ScrollStep4>         <XPosThreshold>50</XPosThreshold>         <YPosThreshold>50</YPosThreshold>         <PosThreshold>50</PosThreshold>         <CountLevel>Inert_Low</CountLevel>       </OneFingerScroll>       <TwoFingerScroll>         <Enabled>false</Enabled>         <Debounce>3</Debounce>         <XPosThreshold1>20</XPosThreshold1>         <YPosThreshold1>20</YPosThreshold1>         <PosThreshold1>20</PosThreshold1>         <ScrollStep1>3</ScrollStep1>         <XPosThreshold2>24</XPosThreshold2>         <YPosThreshold2>24</YPosThreshold2>         <PosThreshold2>24</PosThreshold2>         <ScrollStep2>5</ScrollStep2>         <XPosThreshold3>30</XPosThreshold3>         <YPosThreshold3>30</YPosThreshold3>         <PosThreshold3>30</PosThreshold3>         <ScrollStep3>7</ScrollStep3>         <XPosThreshold4>40</XPosThreshold4>         <YPosThreshold4>40</YPosThreshold4>         <PosThreshold4>40</PosThreshold4>         <ScrollStep4>9</ScrollStep4>         <XPosThreshold>50</XPosThreshold>         <YPosThreshold>50</YPosThreshold>         <PosThreshold>50</PosThreshold>         <CountLevel>Inert_Low</CountLevel>       </TwoFingerScroll>       <OneFingerFlick>         <Enabled>false</Enabled>         <XPosThreshold>20</XPosThreshold>         <YPosThreshold>20</YPosThreshold>         <PosThreshold>20</PosThreshold>         <MaxSampleInterval>80</MaxSampleInterval>       </OneFingerFlick>       <OneFingerEdgeSwipe>         <Enabled>false</Enabled>         <PosThreshold>100</PosThreshold>         <DetectionTime>100</DetectionTime>         <TimeoutInterval>2000</TimeoutInterval>         <TopAngleThreshold>45</TopAngleThreshold>         <BottomAngleThreshold>45</BottomAngleThreshold>         <DisamRegionWidth>5</DisamRegionWidth>       </OneFingerEdgeSwipe>       <TwoFingerZoom>         <Enabled>false</Enabled>         <XPosThreshold>8</XPosThreshold>         <YPosThreshold>8</YPosThreshold>         <PosThreshold>8</PosThreshold>         <Debounce>3</Debounce>         <ScrollZoomDebounce>5</ScrollZoomDebounce>       </TwoFingerZoom>       <OneFingerRotate>         <Enabled>false</Enabled>         <RotateDebounce>0</RotateDebounce>         <PosThreshold>8</PosThreshold>       </OneFingerRotate>     </Gestures>     <Columns>       <Sensor id="Rx0">         <Properties>           <IdacComp>             <Idac0>32</Idac0>             <Idac1>32</Idac1>             <Idac2>32</Idac2>           </IdacComp>           <Idacs>             <Idac>               <Idac0>32</Idac0>               <Idac1>32</Idac1>               <Idac2>32</Idac2>             </Idac>           </Idacs>           <UseDedicatedPin>true</UseDedicatedPin>           <GangedPins />         </Properties>       </Sensor>     </Columns>     <Rows>       <Sensor id="Tx">         <Properties>           <IdacComp>             <Idac0>32</Idac0>             <Idac1>32</Idac1>             <Idac2>32</Idac2>           </IdacComp>           <Idacs />           <UseDedicatedPin>false</UseDedicatedPin>           <GangedPins>             <Pin>Button0_Tx</Pin>           </GangedPins>         </Properties>       </Sensor>     </Rows>   </Widget>   <Widget id="LinearSlider0" type="LinearSlider" mode="CSD" block="CSD0" slot="0">     <Angle>0</Angle>     <FlippedX>false</FlippedX>     <FlippedY>false</FlippedY>     <Flipped2D>false</Flipped2D>     <ScaleFactor>1</ScaleFactor>     <Properties>       <FingerCap>0.16</FingerCap>       <Diplexing>false</Diplexing>       <MaxPosition>100</MaxPosition>       <MaxXPosition>100</MaxXPosition>       <MaxYPosition>100</MaxYPosition>       <PositionFilter>None</PositionFilter>       <MultiphaseTx>false</MultiphaseTx>       <SenseClockFreq>3125</SenseClockFreq>       <RowSenseClockFreq>3125</RowSenseClockFreq>       <TxClockFreq>300</TxClockFreq>       <IsxTxClockFreq>1000</IsxTxClockFreq>       <ScanResolution>_12</ScanResolution>       <NumConversions>100</NumConversions>       <IdacMod>         <Idac0>32</Idac0>         <Idac1>32</Idac1>         <Idac2>32</Idac2>       </IdacMod>       <RowIdacMod>         <Idac0>32</Idac0>         <Idac1>32</Idac1>         <Idac2>32</Idac2>       </RowIdacMod>       <FingerThreshold>100</FingerThreshold>       <ProxTouchThreshold>200</ProxTouchThreshold>       <NoiseThreshold>40</NoiseThreshold>       <NegNoiseThreshold>40</NegNoiseThreshold>       <LowBaselineReset>30</LowBaselineReset>       <BaselineReset>1000</BaselineReset>       <BaselineUpdateThreshold>100</BaselineUpdateThreshold>       <Hysteresis>10</Hysteresis>       <OnDebounce>3</OnDebounce>       <OffDebounce>3</OffDebounce>       <AlpOnThreshold>60</AlpOnThreshold>       <AlpOFFThreshold>20</AlpOFFThreshold>       <Velocity>2500</Velocity>       <MedianFilter>false</MedianFilter>       <IirFilter>false</IirFilter>       <IirFilterCoeff>128</IirFilterCoeff>       <AIirFilter>false</AIirFilter>       <AverageFilter>false</AverageFilter>       <JitterFilter>false</JitterFilter>       <BallisticMultiplier>false</BallisticMultiplier>       <AIirPositionMoveTh>3</AIirPositionMoveTh>       <AIirPositionSlowMoveTh>7</AIirPositionSlowMoveTh>       <AIirPositionFastMoveTh>12</AIirPositionFastMoveTh>       <AIirCoeffMaxLimit>60</AIirCoeffMaxLimit>       <AIirCoeffMinLimit>1</AIirCoeffMinLimit>       <AIirCoeffDivisor>64</AIirCoeffDivisor>       <CentroidType>Csd3x3</CentroidType>       <CrossCouplingPosTh>5</CrossCouplingPosTh>       <EdgeCorrectionEnable>true</EdgeCorrectionEnable>       <EdgeVirtualSensorTh>100</EdgeVirtualSensorTh>       <EdgePenultimateTh>100</EdgePenultimateTh>       <TwoFingerDetection>false</TwoFingerDetection>       <FastMovementMult>9</FastMovementMult>       <SlowMovementMult>2</SlowMovementMult>       <DivisorValue>4</DivisorValue>       <SpeedThresholdX>3</SpeedThresholdX>       <SpeedThresholdY>4</SpeedThresholdY>     </Properties>     <Gestures>       <Click>         <Enabled>true</Enabled>         <XMaxPosDisplacement>30</XMaxPosDisplacement>         <YMaxPosDisplacement>30</YMaxPosDisplacement>         <MaxPosDisplacement>30</MaxPosDisplacement>         <MaxRadius>20</MaxRadius>         <MaxDisplacement>20</MaxDisplacement>         <MinTouchInterval>10</MinTouchInterval>         <MaxTouchInterval>1000</MaxTouchInterval>         <OneFingerMinTouchDuration>10</OneFingerMinTouchDuration>         <OneFingerMaxTouchDuration>1000</OneFingerMaxTouchDuration>         <TwoFingerMinTouchDuration>100</TwoFingerMinTouchDuration>         <TwoFingerMaxTouchDuration>1000</TwoFingerMaxTouchDuration>       </Click>       <OneFingerScroll>         <Enabled>false</Enabled>         <Debounce>3</Debounce>         <XPosThreshold1>20</XPosThreshold1>         <YPosThreshold1>20</YPosThreshold1>         <PosThreshold1>20</PosThreshold1>         <ScrollStep1>3</ScrollStep1>         <XPosThreshold2>24</XPosThreshold2>         <YPosThreshold2>24</YPosThreshold2>         <F1_Scroll_PosThreshold2>20</F1_Scroll_PosThreshold2>         <ScrollStep2>5</ScrollStep2>         <XPosThreshold3>30</XPosThreshold3>         <YPosThreshold3>30</YPosThreshold3>         <PosThreshold3>20</PosThreshold3>         <ScrollStep3>7</ScrollStep3>         <XPosThreshold4>40</XPosThreshold4>         <YPosThreshold4>40</YPosThreshold4>         <PosThreshold4>20</PosThreshold4>         <ScrollStep4>9</ScrollStep4>         <XPosThreshold>50</XPosThreshold>         <YPosThreshold>50</YPosThreshold>         <PosThreshold>50</PosThreshold>         <CountLevel>Inert_Low</CountLevel>       </OneFingerScroll>       <TwoFingerScroll>         <Enabled>false</Enabled>         <Debounce>3</Debounce>         <XPosThreshold1>20</XPosThreshold1>         <YPosThreshold1>20</YPosThreshold1>         <PosThreshold1>20</PosThreshold1>         <ScrollStep1>3</ScrollStep1>         <XPosThreshold2>24</XPosThreshold2>         <YPosThreshold2>24</YPosThreshold2>         <PosThreshold2>24</PosThreshold2>         <ScrollStep2>5</ScrollStep2>         <XPosThreshold3>30</XPosThreshold3>         <YPosThreshold3>30</YPosThreshold3>         <PosThreshold3>30</PosThreshold3>         <ScrollStep3>7</ScrollStep3>         <XPosThreshold4>40</XPosThreshold4>         <YPosThreshold4>40</YPosThreshold4>         <PosThreshold4>40</PosThreshold4>         <ScrollStep4>9</ScrollStep4>         <XPosThreshold>50</XPosThreshold>         <YPosThreshold>50</YPosThreshold>         <PosThreshold>50</PosThreshold>         <CountLevel>Inert_Low</CountLevel>       </TwoFingerScroll>       <OneFingerFlick>         <Enabled>true</Enabled>         <XPosThreshold>20</XPosThreshold>         <YPosThreshold>20</YPosThreshold>         <PosThreshold>20</PosThreshold>         <MaxSampleInterval>80</MaxSampleInterval>       </OneFingerFlick>       <OneFingerEdgeSwipe>         <Enabled>false</Enabled>         <PosThreshold>100</PosThreshold>         <DetectionTime>100</DetectionTime>         <TimeoutInterval>2000</TimeoutInterval>         <TopAngleThreshold>45</TopAngleThreshold>         <BottomAngleThreshold>45</BottomAngleThreshold>         <DisamRegionWidth>5</DisamRegionWidth>       </OneFingerEdgeSwipe>       <TwoFingerZoom>         <Enabled>false</Enabled>         <XPosThreshold>8</XPosThreshold>         <YPosThreshold>8</YPosThreshold>         <PosThreshold>8</PosThreshold>         <Debounce>3</Debounce>         <ScrollZoomDebounce>5</ScrollZoomDebounce>       </TwoFingerZoom>       <OneFingerRotate>         <Enabled>false</Enabled>         <RotateDebounce>0</RotateDebounce>         <PosThreshold>8</PosThreshold>       </OneFingerRotate>     </Gestures>     <Sensors>       <Sensor id="Sns0">         <Properties>           <IdacComp>             <Idac0>32</Idac0>             <Idac1>32</Idac1>             <Idac2>32</Idac2>           </IdacComp>           <Idacs />           <UseDedicatedPin>true</UseDedicatedPin>           <GangedPins />         </Properties>       </Sensor>       <Sensor id="Sns1">         <Properties>           <IdacComp>             <Idac0>32</Idac0>             <Idac1>32</Idac1>             <Idac2>32</Idac2>           </IdacComp>           <Idacs />           <UseDedicatedPin>true</UseDedicatedPin>           <GangedPins />         </Properties>       </Sensor>       <Sensor id="Sns2">         <Properties>           <IdacComp>             <Idac0>32</Idac0>             <Idac1>32</Idac1>             <Idac2>32</Idac2>           </IdacComp>           <Idacs />           <UseDedicatedPin>true</UseDedicatedPin>           <GangedPins />         </Properties>       </Sensor>       <Sensor id="Sns3">         <Properties>           <IdacComp>             <Idac0>32</Idac0>             <Idac1>32</Idac1>             <Idac2>32</Idac2>           </IdacComp>           <Idacs />           <UseDedicatedPin>true</UseDedicatedPin>           <GangedPins />         </Properties>       </Sensor>       <Sensor id="Sns4">         <Properties>           <IdacComp>             <Idac0>32</Idac0>             <Idac1>32</Idac1>             <Idac2>32</Idac2>           </IdacComp>           <Idacs />           <UseDedicatedPin>true</UseDedicatedPin>           <GangedPins />         </Properties>       </Sensor>     </Sensors>   </Widget> </WidgetData>, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=CapSense_v3_0, CY_CONFIG_TITLE=CapSense, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=CapSense, CY_INSTANCE_SHORT_NAME=CapSense, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=CapSense, )
module CapSense_v3_0_1 ;


          wire  Net_609;
    electrical  Net_850;
          wire  Net_849;
          wire  Net_813;
          wire  Net_818;
          wire  Net_814;
          wire  Net_817;
          wire  Net_815;
          wire  Net_851;
          wire [15:0] Net_828;
          wire  Net_845;
          wire  Net_819;
          wire  Net_822;
          wire  Net_821;
          wire  Net_610;
          wire  Net_608;
          wire  Net_44;
    electrical  Net_34;
          wire  Net_1423;
          wire  Net_639;
          wire  Net_638;
          wire  Net_637;
          wire  Net_636;
          wire  Net_48;
          wire  Net_47;
          wire  Net_46;
          wire  Net_45;
          wire  Net_589;
    electrical  Net_314;
    electrical  Net_866;
    electrical [1:0] dedicated_io_bus;
    electrical  Net_846;
    electrical  Net_616;
    electrical  Net_82;
    electrical  Net_615;
    electrical  Net_324;
    electrical  Net_273;
    electrical  Net_848;
    electrical [1:0] Net_13;
    electrical [4:0] Net_847;
    electrical  Net_606;
          wire  Net_611;

	wire [0:0] tmpFB_0__Cmod_net;
	wire [0:0] tmpIO_0__Cmod_net;
	electrical [0:0] tmpSIOVREF__Cmod_net;

	cy_mxs40_gpio_v1_0
		#(.id("9bc618f9-fc12-4653-bffc-b48d30a6bbf5/4db2e9d3-9f70-4f4e-a919-7eefada41863"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("0"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases("Cmod"),
		  .pin_mode("A"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		Cmod
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__Cmod_net[0:0]}),
		  .analog({Net_314}),
		  .io({tmpIO_0__Cmod_net[0:0]}),
		  .siovref(tmpSIOVREF__Cmod_net));


	wire [1:0] tmpFB_1__Rx_net;
	wire [1:0] tmpIO_1__Rx_net;
	electrical [0:0] tmpSIOVREF__Rx_net;

	cy_mxs40_gpio_v1_0
		#(.id("9bc618f9-fc12-4653-bffc-b48d30a6bbf5/77fd7f86-2082-41fa-a471-914d5f07502d"),
		  .width(2),
		  .sio_grp_cnt(0),
		  .drive_mode("0,0"),
		  .ibuf_enabled("0,0"),
		  .init_dr_st("1,1"),
		  .input_sync("0,0"),
		  .intr_mode("0,0"),
		  .io_voltage(","),
		  .output_conn("0,0"),
		  .oe_conn("0,0"),
		  .output_sync("0,0"),
		  .oe_sync("0,0"),
		  .drive_strength("0,0"),
		  .max_frequency("100,100"),
		  .i2c_mode("0,0"),
		  .output_current_cap("8,8"),
		  .pin_aliases("Button0_Rx0,Button1_Rx0"),
		  .pin_mode("A,A"),
		  .slew_rate("0,0"),
		  .vtrip("0,0"),
		  .use_annotation("0,0"),
		  .hotswap_needed("0,0"))
		Rx
		 (.oe({2'b11}),
		  .y({2'b0}),
		  .fb({tmpFB_1__Rx_net[1:0]}),
		  .analog({Net_13[1:0]}),
		  .io({tmpIO_1__Rx_net[1:0]}),
		  .siovref(tmpSIOVREF__Rx_net));


    ZeroTerminal ZeroTerminal_15 (
        .z(Net_589));

	wire [0:0] tmpFB_0__CintB_net;
	wire [0:0] tmpIO_0__CintB_net;
	electrical [0:0] tmpSIOVREF__CintB_net;

	cy_mxs40_gpio_v1_0
		#(.id("9bc618f9-fc12-4653-bffc-b48d30a6bbf5/dbc12ae1-a607-4701-99cc-6261716a9147"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("0"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		CintB
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__CintB_net[0:0]}),
		  .analog({Net_615}),
		  .io({tmpIO_0__CintB_net[0:0]}),
		  .siovref(tmpSIOVREF__CintB_net));


	wire [0:0] tmpFB_0__CintA_net;
	wire [0:0] tmpIO_0__CintA_net;
	electrical [0:0] tmpSIOVREF__CintA_net;

	cy_mxs40_gpio_v1_0
		#(.id("9bc618f9-fc12-4653-bffc-b48d30a6bbf5/2605f567-73b7-435d-b3b9-174766b96934"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("0"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		CintA
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__CintA_net[0:0]}),
		  .analog({Net_82}),
		  .io({tmpIO_0__CintA_net[0:0]}),
		  .siovref(tmpSIOVREF__CintA_net));


    cy_mxs40_csidac_v1_0 IDACMod (
        .dsi_idac_leg1_en(Net_45),
        .dsi_idac_leg2_en(Net_46),
        .dsi_idac_leg3_en(Net_47),
        .dsi_idac_pol(Net_48),
        .iout(Net_606));
    defparam IDACMod.leg3_needed = 0;

    cy_mxs40_csidac_v1_0 IDACComp (
        .dsi_idac_leg1_en(Net_636),
        .dsi_idac_leg2_en(Net_637),
        .dsi_idac_leg3_en(Net_638),
        .dsi_idac_pol(Net_639),
        .iout(Net_866));
    defparam IDACComp.leg3_needed = 1;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_45));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_46));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_47));

    ZeroTerminal ZeroTerminal_4 (
        .z(Net_48));

    ZeroTerminal ZeroTerminal_5 (
        .z(Net_636));

    ZeroTerminal ZeroTerminal_6 (
        .z(Net_637));

    ZeroTerminal ZeroTerminal_7 (
        .z(Net_638));

    ZeroTerminal ZeroTerminal_8 (
        .z(Net_639));

    ZeroTerminal ZeroTerminal_14 (
        .z(Net_1423));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_34));

    ZeroTerminal ZeroTerminal_12 (
        .z(Net_44));

	// cy_analog_virtualmux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_1_connect(Net_314, Net_616);
	defparam cy_analog_virtualmux_1_connect.sig_width = 1;

    ZeroTerminal ZeroTerminal_13 (
        .z(Net_608));


    assign Net_610 = Net_608 | Net_611;

    cy_mxs40_csd_v1_0 CSD (
        .adc_channel(Net_324),
        .amuxa(Net_606),
        .amuxb(Net_846),
        .clock(Net_611),
        .cmod(Net_82),
        .csd_tx(Net_821),
        .csd_tx_n(Net_822),
        .csh(Net_615),
        .dedicated_io(dedicated_io_bus[1:0]),
        .dsi_adc_on(Net_819),
        .dsi_cmod(Net_845),
        .dsi_count(Net_828[15:0]),
        .dsi_count_val_sel(Net_851),
        .dsi_csh_tank(Net_815),
        .dsi_hscmp(Net_817),
        .dsi_sample_in(Net_1423),
        .dsi_sample_out(Net_814),
        .dsi_sampling(Net_818),
        .dsi_sense_in(Net_44),
        .dsi_sense_out(Net_813),
        .dsi_start(Net_589),
        .interrupt(Net_849),
        .rx(Net_13[1:0]),
        .sense(Net_847[4:0]),
        .shield(Net_273),
        .shield_pad(Net_616),
        .tx(Net_848),
        .vref_ext(Net_34),
        .vref_pass(Net_850));
    defparam CSD.adc_channel_count = 1;
    defparam CSD.dedicated_io_count = 2;
    defparam CSD.is_capsense = 1;
    defparam CSD.is_cmod_charge = 1;
    defparam CSD.rx_count = 2;
    defparam CSD.sense_as_shield = 0;
    defparam CSD.sensors_count = 5;
    defparam CSD.shield_as_sense = 0;
    defparam CSD.shield_count = 1;
    defparam CSD.tx_count = 1;


	cy_clock_v1_0
		#(.id("9bc618f9-fc12-4653-bffc-b48d30a6bbf5/8273f0d6-caef-4cc7-ad3c-09656b78e2cb"),
		  .source_clock_id("2FB4EC85-8328-4C5A-9ED9-8B63060178EB"),
		  .divisor(255),
		  .period("0"),
		  .is_direct(0),
		  .is_digital(0))
		ModClk
		 (.clock_out(Net_611));


	wire [4:0] tmpFB_4__Sns_net;
	wire [4:0] tmpIO_4__Sns_net;
	electrical [0:0] tmpSIOVREF__Sns_net;

	cy_mxs40_gpio_v1_0
		#(.id("9bc618f9-fc12-4653-bffc-b48d30a6bbf5/0113321b-4a37-46f6-8407-2f8646c68756"),
		  .width(5),
		  .sio_grp_cnt(0),
		  .drive_mode("0,0,0,0,0"),
		  .ibuf_enabled("0,0,0,0,0"),
		  .init_dr_st("1,1,1,1,1"),
		  .input_sync("0,0,0,0,0"),
		  .intr_mode("0,0,0,0,0"),
		  .io_voltage(",,,,"),
		  .output_conn("0,0,0,0,0"),
		  .oe_conn("0,0,0,0,0"),
		  .output_sync("0,0,0,0,0"),
		  .oe_sync("0,0,0,0,0"),
		  .drive_strength("0,0,0,0,0"),
		  .max_frequency("100,100,100,100,100"),
		  .i2c_mode("0,0,0,0,0"),
		  .output_current_cap("8,8,8,8,8"),
		  .pin_aliases("LinearSlider0_Sns0,LinearSlider0_Sns1,LinearSlider0_Sns2,LinearSlider0_Sns3,LinearSlider0_Sns4"),
		  .pin_mode("A,A,A,A,A"),
		  .slew_rate("0,0,0,0,0"),
		  .vtrip("0,0,0,0,0"),
		  .use_annotation("0,0,0,0,0"),
		  .hotswap_needed("0,0,0,0,0"))
		Sns
		 (.oe({5'b11111}),
		  .y({5'b0}),
		  .fb({tmpFB_4__Sns_net[4:0]}),
		  .analog({Net_847[4:0]}),
		  .io({tmpIO_4__Sns_net[4:0]}),
		  .siovref(tmpSIOVREF__Sns_net));


	wire [0:0] tmpFB_0__Tx_net;
	wire [0:0] tmpIO_0__Tx_net;
	electrical [0:0] tmpSIOVREF__Tx_net;

	cy_mxs40_gpio_v1_0
		#(.id("9bc618f9-fc12-4653-bffc-b48d30a6bbf5/8ed50244-d239-4c9b-9207-b8e71ce193dc"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("0"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases("Button0_Tx"),
		  .pin_mode("A"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		Tx
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__Tx_net[0:0]}),
		  .analog({Net_848}),
		  .io({tmpIO_0__Tx_net[0:0]}),
		  .siovref(tmpSIOVREF__Tx_net));



	cy_mxs40_isr_v1_0
		#(.deepsleep_required(0),
		  .int_type(2'b10))
		ISR
		 (.int_signal(Net_849));


    cy_analog_noconnect_v1_0 cy_analog_noconnect_3 (
        .noconnect(Net_850));

    ZeroTerminal ZeroTerminal_9 (
        .z(Net_851));

	// cy_analog_virtualmux_2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_2_connect(Net_866, Net_606);
	defparam cy_analog_virtualmux_2_connect.sig_width = 1;



endmodule

// TCPWM_PWM_PDL_v1_0(ClockPrescaler=2, Compare0=1000, Compare1=16384, CountInput=7, CountInputMasked=3, DeadClocks=0, EnableCompareSwap=false, EnablePeriodSwap=false, InterruptSource=0, InvertPwm=false, InvertPwm_n=false, KillInput=1, KillInputMasked=1, KillMode=2, Period0=20000, Period1=32768, PwmAlignment=0, PwmMode=4, ReloadInput=7, ReloadInputMasked=3, Resolution=16, RunMode=0, StartInput=0, StartInputMasked=0, SwapInput=7, SwapInputMasked=3, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=TCPWM_PWM_PDL_v1_0, CY_CONFIG_TITLE=PWM_2, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=PWM_2, CY_INSTANCE_SHORT_NAME=PWM_2, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=tcpwm, CY_PDL_DRIVER_REQ_VERSION=1.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=PWM_2, )
module TCPWM_PWM_PDL_v1_0_2 (
    clock,
    compare,
    count,
    interrupt,
    kill,
    ovrflw,
    pwm,
    pwm_n,
    reload,
    start,
    swap,
    undrflw);
    input       clock;
    output      compare;
    input       count;
    output      interrupt;
    input       kill;
    output      ovrflw;
    output      pwm;
    output      pwm_n;
    input       reload;
    input       start;
    input       swap;
    output      undrflw;



    cy_mxs40_tcpwm_v1_0 TCPWM (
        .capture(swap),
        .clock(clock),
        .count(count),
        .interrupt(interrupt),
        .line(pwm),
        .line_compl(pwm_n),
        .reload(reload),
        .start(start),
        .stop(kill),
        .tr_compare_match(compare),
        .tr_overflow(ovrflw),
        .tr_underflow(undrflw));
    defparam TCPWM.exact_width = 0;
    defparam TCPWM.width = 16;



endmodule

// Component: cy_tff_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_tff_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_tff_v1_0\cy_tff_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_tff_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_tff_v1_0\cy_tff_v1_0.v"
`endif

// TCPWM_PWM_PDL_v1_0(ClockPrescaler=0, Compare0=500, Compare1=16384, CountInput=7, CountInputMasked=3, DeadClocks=0, EnableCompareSwap=false, EnablePeriodSwap=false, InterruptSource=0, InvertPwm=false, InvertPwm_n=false, KillInput=7, KillInputMasked=3, KillMode=2, Period0=999, Period1=32768, PwmAlignment=0, PwmMode=4, ReloadInput=7, ReloadInputMasked=3, Resolution=16, RunMode=0, StartInput=7, StartInputMasked=3, SwapInput=7, SwapInputMasked=3, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=TCPWM_PWM_PDL_v1_0, CY_CONFIG_TITLE=LEDBlink, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=LEDBlink, CY_INSTANCE_SHORT_NAME=LEDBlink, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=tcpwm, CY_PDL_DRIVER_REQ_VERSION=1.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=LEDBlink, )
module TCPWM_PWM_PDL_v1_0_3 (
    clock,
    compare,
    count,
    interrupt,
    kill,
    ovrflw,
    pwm,
    pwm_n,
    reload,
    start,
    swap,
    undrflw);
    input       clock;
    output      compare;
    input       count;
    output      interrupt;
    input       kill;
    output      ovrflw;
    output      pwm;
    output      pwm_n;
    input       reload;
    input       start;
    input       swap;
    output      undrflw;



    cy_mxs40_tcpwm_v1_0 TCPWM (
        .capture(swap),
        .clock(clock),
        .count(count),
        .interrupt(interrupt),
        .line(pwm),
        .line_compl(pwm_n),
        .reload(reload),
        .start(start),
        .stop(kill),
        .tr_compare_match(compare),
        .tr_overflow(ovrflw),
        .tr_underflow(undrflw));
    defparam TCPWM.exact_width = 0;
    defparam TCPWM.width = 16;



endmodule

// Component: not_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\not_v1_0\not_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\not_v1_0\not_v1_0.v"
`endif

// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// SCB_EZI2C_PDL_v2_0(ClkDesFrequency=12800, ClkMinusTolerance=87.890625, ClkPlusTolerance=5, ClockFromTerm=false, DataRate=100, EnableWakeup=false, I2cMode=0, NumOfAddr=0, ShowTerminals=false, SlaveAddress1=8, SlaveAddress2=9, SubAddrSize=0, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=SCB_EZI2C_PDL_v2_0, CY_CONFIG_TITLE=EZI2C, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=EZI2C, CY_INSTANCE_SHORT_NAME=EZI2C, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=scb, CY_PDL_DRIVER_REQ_VERSION=2.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=EZI2C, )
module SCB_EZI2C_PDL_v2_0_4 (
    clock,
    scl_b,
    sda_b);
    input       clock;
    inout       scl_b;
    inout       sda_b;


          wire  clock_wire;
          wire  Net_222;
          wire  Net_223;
          wire  Net_224;
          wire  Net_277;
          wire  Net_1062;
          wire  Net_283;
          wire  Net_1053;
          wire  Net_282;
          wire  Net_162;
          wire  intr_wire;
          wire  Net_163;
          wire  Net_264;
          wire  Net_280;
          wire [3:0] Net_87;
          wire  Net_278;
          wire  Net_1061;
          wire  Net_1055;
          wire  Net_279;
          wire  Net_281;
          wire  Net_1059;
          wire  Net_847;

    cy_mxs40_scb_v1_10 SCB (
        .clock(clock_wire),
        .i2c_scl(scl_b),
        .i2c_sda(sda_b),
        .interrupt(intr_wire),
        .spi_clk_m(Net_1059),
        .spi_clk_s(Net_281),
        .spi_miso_m(Net_279),
        .spi_miso_s(Net_1055),
        .spi_mosi_m(Net_1061),
        .spi_mosi_s(Net_278),
        .spi_select_m(Net_87[3:0]),
        .spi_select_s(Net_280),
        .tr_i2c_scl_filtered(Net_264),
        .tr_rx_req(Net_163),
        .tr_tx_req(Net_162),
        .uart_cts(Net_282),
        .uart_rts(Net_1053),
        .uart_rx(Net_283),
        .uart_tx(Net_1062),
        .uart_tx_en(Net_277));
    defparam SCB.master = 0;
    defparam SCB.mode = 0;
    defparam SCB.requires_io_preconfigure = 1;


    assign Net_224 = Net_223 | Net_847;

    ZeroTerminal ZeroTerminal_7 (
        .z(Net_223));

	// clock_VM (cy_virtualmux_v1_0)
	assign clock_wire = Net_847;

    ZeroTerminal ZeroTerminal_6 (
        .z(Net_278));

    ZeroTerminal ZeroTerminal_5 (
        .z(Net_279));

    ZeroTerminal ZeroTerminal_4 (
        .z(Net_280));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_281));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_282));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_283));


	cy_mxs40_isr_v1_0
		#(.deepsleep_required(0),
		  .int_type(2'b10))
		SCB_IRQ
		 (.int_signal(intr_wire));



	cy_clock_v1_0
		#(.id("7ced46af-7f8c-409b-95be-54f36ac9b577/b68e5b9d-7828-482d-a282-930f990e3b3e"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("78125000"),
		  .is_direct(0),
		  .is_digital(0))
		SCBCLK
		 (.clock_out(Net_847));


	wire [0:0] tmpFB_0__scl_net;
	electrical [0:0] tmpSIOVREF__scl_net;

	cy_mxs40_gpio_v1_0
		#(.id("7ced46af-7f8c-409b-95be-54f36ac9b577/69c3b5e8-b094-4d65-b96b-9f4f3a9a8641"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("4"),
		  .ibuf_enabled("1"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("B"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		scl
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__scl_net[0:0]}),
		  .io({scl_b}),
		  .siovref(tmpSIOVREF__scl_net));


	wire [0:0] tmpFB_0__sda_net;
	electrical [0:0] tmpSIOVREF__sda_net;

	cy_mxs40_gpio_v1_0
		#(.id("7ced46af-7f8c-409b-95be-54f36ac9b577/2aab8a93-e7dd-4bd4-8210-42652cd079c5"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("4"),
		  .ibuf_enabled("1"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("B"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		sda
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__sda_net[0:0]}),
		  .io({sda_b}),
		  .siovref(tmpSIOVREF__sda_net));




endmodule

// TCPWM_PWM_PDL_v1_0(ClockPrescaler=2, Compare0=0, Compare1=16384, CountInput=7, CountInputMasked=3, DeadClocks=0, EnableCompareSwap=false, EnablePeriodSwap=false, InterruptSource=0, InvertPwm=false, InvertPwm_n=false, KillInput=7, KillInputMasked=3, KillMode=2, Period0=100, Period1=32768, PwmAlignment=0, PwmMode=4, ReloadInput=7, ReloadInputMasked=3, Resolution=16, RunMode=0, StartInput=7, StartInputMasked=3, SwapInput=7, SwapInputMasked=3, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=TCPWM_PWM_PDL_v1_0, CY_CONFIG_TITLE=PWM_RED, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=PWM_RED, CY_INSTANCE_SHORT_NAME=PWM_RED, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=tcpwm, CY_PDL_DRIVER_REQ_VERSION=1.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=PWM_RED, )
module TCPWM_PWM_PDL_v1_0_5 (
    clock,
    compare,
    count,
    interrupt,
    kill,
    ovrflw,
    pwm,
    pwm_n,
    reload,
    start,
    swap,
    undrflw);
    input       clock;
    output      compare;
    input       count;
    output      interrupt;
    input       kill;
    output      ovrflw;
    output      pwm;
    output      pwm_n;
    input       reload;
    input       start;
    input       swap;
    output      undrflw;



    cy_mxs40_tcpwm_v1_0 TCPWM (
        .capture(swap),
        .clock(clock),
        .count(count),
        .interrupt(interrupt),
        .line(pwm),
        .line_compl(pwm_n),
        .reload(reload),
        .start(start),
        .stop(kill),
        .tr_compare_match(compare),
        .tr_overflow(ovrflw),
        .tr_underflow(undrflw));
    defparam TCPWM.exact_width = 0;
    defparam TCPWM.width = 16;



endmodule

// TCPWM_PWM_PDL_v1_0(ClockPrescaler=2, Compare0=1000, Compare1=16384, CountInput=7, CountInputMasked=3, DeadClocks=0, EnableCompareSwap=false, EnablePeriodSwap=false, InterruptSource=0, InvertPwm=false, InvertPwm_n=false, KillInput=1, KillInputMasked=1, KillMode=2, Period0=20000, Period1=32768, PwmAlignment=0, PwmMode=4, ReloadInput=7, ReloadInputMasked=3, Resolution=16, RunMode=0, StartInput=0, StartInputMasked=0, SwapInput=7, SwapInputMasked=3, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=TCPWM_PWM_PDL_v1_0, CY_CONFIG_TITLE=PWM_1, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=PWM_1, CY_INSTANCE_SHORT_NAME=PWM_1, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=tcpwm, CY_PDL_DRIVER_REQ_VERSION=1.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=PWM_1, )
module TCPWM_PWM_PDL_v1_0_6 (
    clock,
    compare,
    count,
    interrupt,
    kill,
    ovrflw,
    pwm,
    pwm_n,
    reload,
    start,
    swap,
    undrflw);
    input       clock;
    output      compare;
    input       count;
    output      interrupt;
    input       kill;
    output      ovrflw;
    output      pwm;
    output      pwm_n;
    input       reload;
    input       start;
    input       swap;
    output      undrflw;



    cy_mxs40_tcpwm_v1_0 TCPWM (
        .capture(swap),
        .clock(clock),
        .count(count),
        .interrupt(interrupt),
        .line(pwm),
        .line_compl(pwm_n),
        .reload(reload),
        .start(start),
        .stop(kill),
        .tr_compare_match(compare),
        .tr_overflow(ovrflw),
        .tr_underflow(undrflw));
    defparam TCPWM.exact_width = 0;
    defparam TCPWM.width = 16;



endmodule

// SCB_UART_PDL_v2_0(BaudRate=115200, BitsOrder=0, BreakSignalBits=11, BufferMinSize=64, ByteMode=true, ClkFreqDes=1382.4, ClkMinusTolerance=5, ClkPlusTolerance=5, ClockFromTerm=false, ComMode=0, CtsPolarity=0, CtsTermEnable=false, DataWidth=8, Direction=3, DropOnFrameErr=false, DropOnParityErr=false, EnableCts=false, EnableInputFilter=false, EnableMultiProc=false, EnableRts=false, EnableRxOutput=false, EnableTxEn=false, EnableTxOutput=false, InterruptMode=1, InterruptTermEnable=false, IntrRxBreakDetected=false, IntrRxFrameErr=false, IntrRxFull=false, IntrRxNotEmpty=false, IntrRxOverflow=false, IntrRxParityErr=false, IntrRxTrigger=false, IntrRxUnderflow=false, IntrTxEmpty=false, IntrTxNotFull=false, IntrTxOverflow=false, IntrTxTrigger=false, IntrTxUartDone=false, IntrTxUartLostArb=false, IntrTxUartNack=false, IntrTxUnderflow=false, IrdaLowPower=false, IrdaPolarity=0, IsCtsPinAllowed=true, IsDmaCapable=true, IsEnableInputFilterVisible=true, IsMultiprocessorModeAvailable=false, IsRtsPinAllowed=true, IsRtsTriggerLevelVisible=false, IsRxIntrSourcesVisible=false, IsRxTriggerLevelVisible=false, IsTxIntrSourcesVisible=false, IsTxTriggerLevelVisible=false, MaxFifoLevel=127, MpRxAcceptAddress=false, MpRxAddress=0, MpRxAddressMask=255, OvsFactor=12, ParityType=0, PreconfigureIO=false, RemoveCtsPin=true, RemoveIntr=false, RemoveRtsPin=true, RemoveRxPin=false, RemoveRxTxPin=true, RemoveTxEnPin=true, RemoveTxPin=false, RtsPolarity=0, RtsTermEnable=false, RtsTriggerLevel=63, RxIntrMask=0, RxTermEnable=false, RxTriggerLevel=63, RxTxTermEnable=false, ShowTerminals=false, SmCardRetryOnNack=false, StopBits=2, SymbolShape=0, TriggerOutputEnable=false, TxEnTermEnable=false, TxIntrMask=0, TxTermEnable=false, TxTriggerLevel=63, UartMode=2, UseIntr=true, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=SCB_UART_PDL_v2_0, CY_CONFIG_TITLE=UART, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=UART, CY_INSTANCE_SHORT_NAME=UART, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=scb, CY_PDL_DRIVER_REQ_VERSION=2.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=UART, )
module SCB_UART_PDL_v2_0_7 (
    clock,
    cts_in,
    interrupt,
    rts_out,
    rx_dma,
    rx_in,
    rx_tx_out,
    tx_dma,
    tx_en_out,
    tx_out);
    input       clock;
    input       cts_in;
    output      interrupt;
    output      rts_out;
    output      rx_dma;
    input       rx_in;
    output      rx_tx_out;
    output      tx_dma;
    output      tx_en_out;
    output      tx_out;


          wire  rx_wire;
          wire  tx_wire;
          wire  rts_wire;
          wire  cts_wire;
          wire  intr_wire;
          wire  clock_wire;
          wire  Net_161;
          wire  Net_148;
          wire [3:0] Net_155;
          wire  Net_150;
          wire  Net_156;
          wire  Net_157;
          wire  Net_149;
          wire  Net_147;
          wire  Net_154;
          wire  Net_146;
          wire  Net_145;
          wire  Net_1172;
          wire  Net_23;
          wire  tx_en_wire;
          wire  Net_47;
          wire  Net_22;
          wire  Net_24;
          wire  Net_847;


	cy_clock_v1_0
		#(.id("ff784b52-1bdf-4594-9024-695cb9a611c5/b68e5b9d-7828-482d-a282-930f990e3b3e"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("723379629.62963"),
		  .is_direct(0),
		  .is_digital(0))
		SCBCLK
		 (.clock_out(Net_847));


	// clock_VM (cy_virtualmux_v1_0)
	assign clock_wire = Net_847;

    ZeroTerminal ZeroTerminal_7 (
        .z(Net_22));


    assign Net_23 = Net_22 | Net_847;

	wire [0:0] tmpFB_0__tx_net;
	wire [0:0] tmpIO_0__tx_net;
	electrical [0:0] tmpSIOVREF__tx_net;

	cy_mxs40_gpio_v1_0
		#(.id("ff784b52-1bdf-4594-9024-695cb9a611c5/65f3af6c-759b-4ccb-8c66-5c95ba1f5f4f"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("1"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		tx
		 (.oe({1'b1}),
		  .y({tx_wire}),
		  .fb({tmpFB_0__tx_net[0:0]}),
		  .io({tmpIO_0__tx_net[0:0]}),
		  .siovref(tmpSIOVREF__tx_net));


	wire [0:0] tmpIO_0__rx_net;
	electrical [0:0] tmpSIOVREF__rx_net;

	cy_mxs40_gpio_v1_0
		#(.id("ff784b52-1bdf-4594-9024-695cb9a611c5/b7e8018e-1ef7-49c0-b5a5-61641a03e31c"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("0"),
		  .ibuf_enabled("1"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		rx
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({Net_1172}),
		  .io({tmpIO_0__rx_net[0:0]}),
		  .siovref(tmpSIOVREF__rx_net));


	// rx_VM (cy_virtualmux_v1_0)
	assign rx_wire = Net_1172;

	// cts_VM (cy_virtualmux_v1_0)
	assign cts_wire = cts_in;


	cy_mxs40_isr_v1_0
		#(.deepsleep_required(0),
		  .int_type(2'b10))
		SCB_IRQ
		 (.int_signal(intr_wire));


    cy_mxs40_scb_v1_10 SCB (
        .clock(clock_wire),
        .i2c_scl(Net_145),
        .i2c_sda(Net_146),
        .interrupt(intr_wire),
        .spi_clk_m(Net_154),
        .spi_clk_s(1'b0),
        .spi_miso_m(1'b0),
        .spi_miso_s(Net_157),
        .spi_mosi_m(Net_156),
        .spi_mosi_s(1'b0),
        .spi_select_m(Net_155[3:0]),
        .spi_select_s(1'b0),
        .tr_i2c_scl_filtered(Net_161),
        .tr_rx_req(rx_dma),
        .tr_tx_req(tx_dma),
        .uart_cts(cts_wire),
        .uart_rts(rts_wire),
        .uart_rx(rx_wire),
        .uart_tx(tx_wire),
        .uart_tx_en(tx_en_wire));
    defparam SCB.master = 0;
    defparam SCB.mode = 2;
    defparam SCB.requires_io_preconfigure = 0;


    assign interrupt = intr_wire;

    assign rts_out = rts_wire;

    assign rx_tx_out = tx_wire;

    assign tx_en_out = tx_en_wire;

    assign tx_out = tx_wire;


endmodule

// SCB_I2C_PDL_v2_0(AcceptAddress=false, AcceptGeneralCall=false, ClkDesFrequency=7820, ClkMinusTolerance=5, ClkPlusTolerance=127.877237851662, ClockFromTerm=false, DataRate=400, DeepSleepCapable=false, EnableManualSclControl=false, EnableRxFifo=false, EnableSclAccess=false, EnableTxFifo=false, EnableWakeup=false, HighPhaseDutyCycle=10, I2cMode=0, IsEnableRxFifoVisible=true, IsMasterEnabled=true, IsSlaveVisible=false, LowPhaseDutyCycle=10, Mode=2, ShowTerminals=false, SlaveAddress=8, SlaveAddressMask=254, SymbolShape=0, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=SCB_I2C_PDL_v2_0, CY_CONFIG_TITLE=I2C_ARD, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=I2C_ARD, CY_INSTANCE_SHORT_NAME=I2C_ARD, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=scb, CY_PDL_DRIVER_REQ_VERSION=2.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=I2C_ARD, )
module SCB_I2C_PDL_v2_0_8 (
    clock,
    scl_b,
    scl_trig,
    sda_b);
    input       clock;
    inout       scl_b;
    output      scl_trig;
    inout       sda_b;


          wire  clock_wire;
          wire  Net_222;
          wire  Net_223;
          wire  Net_224;
          wire  Net_277;
          wire  Net_1062;
          wire  Net_283;
          wire  Net_1053;
          wire  Net_282;
          wire  Net_162;
          wire  intr_wire;
          wire  Net_163;
          wire  Net_280;
          wire [3:0] Net_87;
          wire  Net_278;
          wire  Net_1061;
          wire  Net_1055;
          wire  Net_279;
          wire  Net_281;
          wire  Net_1059;
          wire  Net_847;

    cy_mxs40_scb_v1_10 SCB (
        .clock(clock_wire),
        .i2c_scl(scl_b),
        .i2c_sda(sda_b),
        .interrupt(intr_wire),
        .spi_clk_m(Net_1059),
        .spi_clk_s(Net_281),
        .spi_miso_m(Net_279),
        .spi_miso_s(Net_1055),
        .spi_mosi_m(Net_1061),
        .spi_mosi_s(Net_278),
        .spi_select_m(Net_87[3:0]),
        .spi_select_s(Net_280),
        .tr_i2c_scl_filtered(scl_trig),
        .tr_rx_req(Net_163),
        .tr_tx_req(Net_162),
        .uart_cts(Net_282),
        .uart_rts(Net_1053),
        .uart_rx(Net_283),
        .uart_tx(Net_1062),
        .uart_tx_en(Net_277));
    defparam SCB.master = 1;
    defparam SCB.mode = 0;
    defparam SCB.requires_io_preconfigure = 1;


    assign Net_224 = Net_223 | Net_847;

    ZeroTerminal ZeroTerminal_7 (
        .z(Net_223));

	// clock_VM (cy_virtualmux_v1_0)
	assign clock_wire = Net_847;

    ZeroTerminal ZeroTerminal_6 (
        .z(Net_278));

    ZeroTerminal ZeroTerminal_5 (
        .z(Net_279));

    ZeroTerminal ZeroTerminal_4 (
        .z(Net_280));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_281));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_282));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_283));


	cy_mxs40_isr_v1_0
		#(.deepsleep_required(0),
		  .int_type(2'b10))
		SCB_IRQ
		 (.int_signal(intr_wire));



	cy_clock_v1_0
		#(.id("57eab874-e2a1-429d-95bb-7bdb2d0dab82/b68e5b9d-7828-482d-a282-930f990e3b3e"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("127877237.851662"),
		  .is_direct(0),
		  .is_digital(0))
		SCBCLK
		 (.clock_out(Net_847));


	wire [0:0] tmpFB_0__scl_net;
	electrical [0:0] tmpSIOVREF__scl_net;

	cy_mxs40_gpio_v1_0
		#(.id("57eab874-e2a1-429d-95bb-7bdb2d0dab82/69c3b5e8-b094-4d65-b96b-9f4f3a9a8641"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("4"),
		  .ibuf_enabled("1"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("B"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		scl
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__scl_net[0:0]}),
		  .io({scl_b}),
		  .siovref(tmpSIOVREF__scl_net));


	wire [0:0] tmpFB_0__sda_net;
	electrical [0:0] tmpSIOVREF__sda_net;

	cy_mxs40_gpio_v1_0
		#(.id("57eab874-e2a1-429d-95bb-7bdb2d0dab82/2aab8a93-e7dd-4bd4-8210-42652cd079c5"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("4"),
		  .ibuf_enabled("1"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("B"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		sda
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__sda_net[0:0]}),
		  .io({sda_b}),
		  .siovref(tmpSIOVREF__sda_net));




endmodule

// top
module top ;

          wire  Net_162;
          wire  Net_161;
          wire  Net_160;
          wire  Net_159;
          wire  Net_92;
          wire  Net_91;
          wire  Net_90;
          wire  Net_89;
          wire  Net_88;
          wire  Net_87;
          wire  Net_86;
          wire  Net_85;
          wire  Net_84;
          wire  Net_83;
          wire  Net_196;
          wire  Net_102;
          wire  Net_101;
          wire  Net_100;
          wire  Net_99;
          wire  Net_93;
          wire  Net_98;
          wire  Net_97;
          wire  Net_96;
          wire  Net_95;
          wire  Net_113;
          wire  Net_112;
          wire  Net_111;
          wire  Net_110;
          wire  Net_109;
          wire  Net_103;
          wire  Net_108;
          wire  Net_107;
          wire  Net_106;
          wire  Net_105;
          wire  Net_104;
          wire  Net_116;
          wire  Net_115;
          wire  Net_114;
          wire  Net_117;
          wire  Net_130;
          wire  Net_129;
          wire  Net_128;
          wire  Net_127;
          wire  Net_126;
          wire  Net_125;
          wire  Net_124;
          wire  Net_123;
          wire  Net_122;
          wire  Net_121;
          wire  Net_195;
          wire  Net_120;
          wire  Net_119;
          wire  Net_118;
          wire  Net_133;
          wire  Net_141;
          wire  Net_140;
          wire  Net_139;
          wire  Net_138;
          wire  Net_137;
          wire  Net_136;
          wire  Net_135;
          wire  Net_134;
          wire  Net_153;
          wire  Net_152;
          wire  Net_151;
          wire  Net_150;
          wire  Net_149;
          wire  Net_147;
          wire  Net_146;
          wire  Net_144;
          wire  Net_143;
          wire  Net_142;
          wire  Net_155;
          wire  Net_156;
          wire  Net_158;
          wire  Net_157;
          wire  Net_148;
          wire  Net_132;
          wire  Net_329;
          wire  Net_294;
          wire  Net_145;
          wire  Net_154;

    // -- Mux start --
    if (1)
    begin : mux_3
        reg  tmp__mux_3_reg;
        always @(Net_158 or Net_148 or Net_294)
        begin
            case (Net_294)
                1'b0 :  tmp__mux_3_reg = Net_158;
                1'b1 :  tmp__mux_3_reg = Net_148;
            endcase
        end
        assign Net_157 = tmp__mux_3_reg;
    end
    // -- Mux end --

    assign Net_156 = 1'h1;

	wire [0:0] tmpFB_0__RED_net;
	wire [0:0] tmpIO_0__RED_net;
	electrical [0:0] tmpSIOVREF__RED_net;

	cy_mxs40_gpio_v1_0
		#(.id("b1910b63-e553-44eb-8fac-cc894c12cb4f"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("1"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		RED
		 (.oe({1'b1}),
		  .y({Net_155}),
		  .fb({tmpFB_0__RED_net[0:0]}),
		  .io({tmpIO_0__RED_net[0:0]}),
		  .siovref(tmpSIOVREF__RED_net));


    // -- Mux start --
    if (1)
    begin : mux_2
        reg  tmp__mux_2_reg;
        always @(Net_148 or Net_156 or Net_132)
        begin
            case (Net_132)
                1'b0 :  tmp__mux_2_reg = Net_148;
                1'b1 :  tmp__mux_2_reg = Net_156;
            endcase
        end
        assign Net_155 = tmp__mux_2_reg;
    end
    // -- Mux end --

    TCPWM_PWM_PDL_v1_0_0 Dimmer (
        .clock(Net_154),
        .compare(Net_142),
        .count(1'b1),
        .interrupt(Net_144),
        .kill(1'b0),
        .ovrflw(Net_147),
        .pwm(Net_148),
        .pwm_n(Net_149),
        .reload(1'b0),
        .start(1'b0),
        .swap(1'b0),
        .undrflw(Net_153));

    CapSense_v3_0_1 CapSense ();

    TCPWM_PWM_PDL_v1_0_2 PWM_2 (
        .clock(Net_154),
        .compare(Net_134),
        .count(1'b1),
        .interrupt(Net_136),
        .kill(Net_294),
        .ovrflw(Net_137),
        .pwm(Net_329),
        .pwm_n(Net_138),
        .reload(1'b0),
        .start(Net_294),
        .swap(1'b0),
        .undrflw(Net_141));

	wire [0:0] tmpFB_0__M2_net;
	wire [0:0] tmpIO_0__M2_net;
	electrical [0:0] tmpSIOVREF__M2_net;

	cy_mxs40_gpio_v1_0
		#(.id("bbca26b1-5a22-4149-918a-ac530d0183cf"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("1"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		M2
		 (.oe({1'b1}),
		  .y({Net_329}),
		  .fb({tmpFB_0__M2_net[0:0]}),
		  .io({tmpIO_0__M2_net[0:0]}),
		  .siovref(tmpSIOVREF__M2_net));


    assign Net_133 = 1'h1;

    // -- Mux start --
    if (1)
    begin : mux_1
        reg  tmp__mux_1_reg;
        always @(Net_145 or Net_133 or Net_294)
        begin
            case (Net_294)
                1'b0 :  tmp__mux_1_reg = Net_145;
                1'b1 :  tmp__mux_1_reg = Net_133;
            endcase
        end
        assign Net_132 = tmp__mux_1_reg;
    end
    // -- Mux end --

    // -- TFF Start --
    reg  cy_tff_1;
    always @(posedge Net_118)
    begin
        cy_tff_1 <= Net_119^Net_294;
    end
    assign Net_294 = cy_tff_1;
    // -- TFF End --


	cy_clock_v1_0
		#(.id("07b66cce-491b-4ec2-a6e4-26cbe7412674"),
		  .source_clock_id("2FB4EC85-8328-4C5A-9ED9-8B63060178EB"),
		  .divisor(0),
		  .period("1000000000000"),
		  .is_direct(0),
		  .is_digital(0))
		Clock_2
		 (.clock_out(Net_120));


    TCPWM_PWM_PDL_v1_0_3 LEDBlink (
        .clock(Net_120),
        .compare(Net_121),
        .count(1'b1),
        .interrupt(Net_123),
        .kill(1'b0),
        .ovrflw(Net_125),
        .pwm(Net_145),
        .pwm_n(Net_126),
        .reload(1'b0),
        .start(1'b0),
        .swap(1'b0),
        .undrflw(Net_130));

    assign Net_119 = 1'h1;


    assign Net_118 = ~Net_117;

	wire [0:0] tmpIO_0__SW_net;
	electrical [0:0] tmpSIOVREF__SW_net;

	cy_mxs40_gpio_v1_0
		#(.id("4cca878b-77b5-471d-8aeb-ad6925202455"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("2"),
		  .ibuf_enabled("1"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		SW
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({Net_117}),
		  .io({tmpIO_0__SW_net[0:0]}),
		  .siovref(tmpSIOVREF__SW_net));


    SCB_EZI2C_PDL_v2_0_4 EZI2C (
        .clock(1'b0),
        .scl_b(Net_115),
        .sda_b(Net_116));

    TCPWM_PWM_PDL_v1_0_5 PWM_RED (
        .clock(Net_154),
        .compare(Net_104),
        .count(1'b1),
        .interrupt(Net_106),
        .kill(1'b0),
        .ovrflw(Net_108),
        .pwm(Net_103),
        .pwm_n(Net_109),
        .reload(1'b0),
        .start(1'b0),
        .swap(1'b0),
        .undrflw(Net_113));

	wire [0:0] tmpFB_0__RED_USER_LED2_net;
	wire [0:0] tmpIO_0__RED_USER_LED2_net;
	electrical [0:0] tmpSIOVREF__RED_USER_LED2_net;

	cy_mxs40_gpio_v1_0
		#(.id("77d0bcfd-471e-4909-8532-7997252adc13"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("1"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		RED_USER_LED2
		 (.oe({1'b1}),
		  .y({Net_103}),
		  .fb({tmpFB_0__RED_USER_LED2_net[0:0]}),
		  .io({tmpIO_0__RED_USER_LED2_net[0:0]}),
		  .siovref(tmpSIOVREF__RED_USER_LED2_net));


    TCPWM_PWM_PDL_v1_0_6 PWM_1 (
        .clock(Net_154),
        .compare(Net_95),
        .count(1'b1),
        .interrupt(Net_97),
        .kill(Net_294),
        .ovrflw(Net_98),
        .pwm(Net_93),
        .pwm_n(Net_99),
        .reload(1'b0),
        .start(Net_294),
        .swap(1'b0),
        .undrflw(Net_102));


	cy_clock_v1_0
		#(.id("28ca4f1a-f6f9-4526-bb63-d8e6c1e94cd2"),
		  .source_clock_id("2FB4EC85-8328-4C5A-9ED9-8B63060178EB"),
		  .divisor(0),
		  .period("250000000"),
		  .is_direct(0),
		  .is_digital(0))
		Clock_1
		 (.clock_out(Net_154));


	wire [0:0] tmpFB_0__M1_net;
	wire [0:0] tmpIO_0__M1_net;
	electrical [0:0] tmpSIOVREF__M1_net;

	cy_mxs40_gpio_v1_0
		#(.id("a61270bc-07ec-447d-ac9e-34cfe85c30e9"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("1"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		M1
		 (.oe({1'b1}),
		  .y({Net_93}),
		  .fb({tmpFB_0__M1_net[0:0]}),
		  .io({tmpIO_0__M1_net[0:0]}),
		  .siovref(tmpSIOVREF__M1_net));


    SCB_UART_PDL_v2_0_7 UART (
        .clock(1'b0),
        .cts_in(1'b0),
        .interrupt(Net_85),
        .rts_out(Net_86),
        .rx_dma(Net_87),
        .rx_in(1'b0),
        .rx_tx_out(Net_89),
        .tx_dma(Net_90),
        .tx_en_out(Net_91),
        .tx_out(Net_92));

	wire [0:0] tmpFB_0__GREEN_net;
	wire [0:0] tmpIO_0__GREEN_net;
	electrical [0:0] tmpSIOVREF__GREEN_net;

	cy_mxs40_gpio_v1_0
		#(.id("cb816176-9068-42bc-8dd8-10a06f374e15"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("1"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		GREEN
		 (.oe({1'b1}),
		  .y({Net_157}),
		  .fb({tmpFB_0__GREEN_net[0:0]}),
		  .io({tmpIO_0__GREEN_net[0:0]}),
		  .siovref(tmpSIOVREF__GREEN_net));


    assign Net_158 = 1'h1;

    SCB_I2C_PDL_v2_0_8 I2C_ARD (
        .clock(1'b0),
        .scl_b(Net_160),
        .scl_trig(Net_161),
        .sda_b(Net_162));



endmodule

