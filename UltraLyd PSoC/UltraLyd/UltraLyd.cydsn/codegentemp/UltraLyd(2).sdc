# THIS FILE IS AUTOMATICALLY GENERATED
# Project: D:\Google Drive\Aarhus Universitet\Trejde Semester\E3PRJ3\Dokumenter\AndreasAHN\Software\UltraLyd\UltraLyd\UltraLyd.cydsn\UltraLyd.cyprj
# Date: Tue, 07 Nov 2017 14:46:50 GMT
#set_units -time ns
create_clock -name {Clock_2(routed)} -period 500 -waveform {0 250} [list [get_pins {ClockBlock/dclk_1}]]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/clk_sync}] -edges {1 7 13} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {Clock_2} -source [get_pins {ClockBlock/clk_sync}] -edges {1 13 25} [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {UART_1_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 313 627} [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {Clock_3} -source [get_pins {ClockBlock/clk_sync}] -edges {1 481 961} [list [get_pins {ClockBlock/dclk_glb_3}]]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for D:\Google Drive\Aarhus Universitet\Trejde Semester\E3PRJ3\Dokumenter\AndreasAHN\Software\UltraLyd\UltraLyd\UltraLyd.cydsn\TopDesign\TopDesign.cysch
# Project: D:\Google Drive\Aarhus Universitet\Trejde Semester\E3PRJ3\Dokumenter\AndreasAHN\Software\UltraLyd\UltraLyd\UltraLyd.cydsn\UltraLyd.cyprj
# Date: Tue, 07 Nov 2017 14:46:42 GMT
