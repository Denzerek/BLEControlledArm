# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Alen\GitHub_Denzerek\BLEControlledArm\BLE_ARM_Workspace\MainArmController.cydsn\MainArmController.cyprj
# Date: Thu, 14 Oct 2021 12:00:01 GMT
#set_units -time ns
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyClk_LF} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyFLL} -period 10 -waveform {0 5} [list [get_pins {ClockBlock/fll}]]
create_clock -name {CyClk_HF0} -period 10 -waveform {0 5} [list [get_pins {ClockBlock/hfclk_0}]]
create_clock -name {CyClk_Fast} -period 10 -waveform {0 5} [list [get_pins {ClockBlock/fastclk}]]
create_clock -name {CyClk_Peri} -period 20 -waveform {0 10} [list [get_pins {ClockBlock/periclk}]]
create_generated_clock -name {CyClk_Slow} -source [get_pins {ClockBlock/periclk}] -edges {1 2 3} [list [get_pins {ClockBlock/slowclk}]]
create_generated_clock -name {CapSense_ModClk} -source [get_pins {ClockBlock/periclk}] -edges {1 255 511} [list [get_pins {ClockBlock/ff_div_43}]]
create_generated_clock -name {Clock_2} -source [get_pins {ClockBlock/periclk}] -edges {1 50001 100001} [list [get_pins {ClockBlock/ff_div_11}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/periclk}] -edges {1 13 25} [list [get_pins {ClockBlock/ff_div_12}] [get_pins {ClockBlock/ff_div_13}] [get_pins {ClockBlock/ff_div_20}] [get_pins {ClockBlock/ff_div_29}]]
create_generated_clock -name {EZI2C_SCBCLK} -source [get_pins {ClockBlock/periclk}] -edges {1 5 9} [list [get_pins {ClockBlock/ff_div_3}]]
create_generated_clock -name {UART_SCBCLK} -source [get_pins {ClockBlock/periclk}] -edges {1 37 73} [list [get_pins {ClockBlock/ff_div_5}]]
create_clock -name {CyPeriClk_App} -period 20 -waveform {0 10} [list [get_pins {ClockBlock/periclk_App}]]
create_clock -name {CyIMO} -period 125 -waveform {0 62.5} [list [get_pins {ClockBlock/imo}]]


# Component constraints for C:\Alen\GitHub_Denzerek\BLEControlledArm\BLE_ARM_Workspace\MainArmController.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Alen\GitHub_Denzerek\BLEControlledArm\BLE_ARM_Workspace\MainArmController.cydsn\MainArmController.cyprj
# Date: Thu, 14 Oct 2021 11:59:42 GMT
