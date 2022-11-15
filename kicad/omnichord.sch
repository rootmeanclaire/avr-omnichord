EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_ATmega:ATmega328P-PU U1
U 1 1 5EE054F3
P 4200 4100
F 0 "U1" H 3556 4146 50  0000 R CNN
F 1 "ATmega328P-PU" H 3556 4055 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 4200 4100 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 4200 4100 50  0001 C CNN
	1    4200 4100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Mini-DIN-6 J1
U 1 1 5EE078D0
P 6250 4100
F 0 "J1" H 6250 4467 50  0000 C CNN
F 1 "Mini-DIN-6" H 6250 4376 50  0000 C CNN
F 2 "Misc_Custom:MINI-DIN-6" H 6250 4100 50  0001 C CNN
F 3 "http://service.powerdynamics.com/ec/Catalog17/Section%2011.pdf" H 6250 4100 50  0001 C CNN
	1    6250 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 4200 6650 4200
Wire Wire Line
	4200 1750 4200 1850
Wire Wire Line
	4200 5600 4200 5750
Wire Wire Line
	4800 5000 6850 5000
Wire Wire Line
	6850 5000 6850 4000
Wire Wire Line
	6850 4000 6550 4000
Wire Wire Line
	6550 4100 6750 4100
Wire Wire Line
	6750 4100 6750 5750
Wire Wire Line
	6750 5750 5000 5750
Connection ~ 4200 5750
Wire Wire Line
	5950 4100 5850 4100
Wire Wire Line
	5850 4100 5850 2300
Connection ~ 4200 2300
Wire Wire Line
	4200 2300 4200 2600
$Comp
L Connector:DIN-5_180degree J2
U 1 1 5EE14BEE
P 7650 4600
F 0 "J2" H 7650 4325 50  0000 C CNN
F 1 "DIN-5_180degree" H 7650 4234 50  0000 C CNN
F 2 "Misc_Custom:MIDI_DIN5" H 7650 4600 50  0001 C CNN
F 3 "" H 7650 4600 50  0001 C CNN
	1    7650 4600
	-1   0    0    1   
$EndComp
$Comp
L Device:R R1
U 1 1 5EE155D1
P 7100 4700
F 0 "R1" V 7307 4700 50  0000 C CNN
F 1 "220" V 7216 4700 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 7030 4700 50  0001 C CNN
F 3 "~" H 7100 4700 50  0001 C CNN
	1    7100 4700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4800 4700 6950 4700
Wire Wire Line
	7250 4700 7350 4700
$Comp
L Device:R R2
U 1 1 5EE20CAA
P 8050 4450
F 0 "R2" H 7980 4404 50  0000 R CNN
F 1 "220" H 7980 4495 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 7980 4450 50  0001 C CNN
F 3 "~" H 8050 4450 50  0001 C CNN
	1    8050 4450
	-1   0    0    1   
$EndComp
Wire Wire Line
	8050 4600 8050 4700
Wire Wire Line
	8050 4700 7950 4700
Wire Wire Line
	8050 4300 8050 2300
Connection ~ 5850 2300
Wire Wire Line
	5850 2300 8050 2300
Wire Wire Line
	6750 5750 7650 5750
Wire Wire Line
	7650 5750 7650 4900
Connection ~ 6750 5750
$Comp
L Device:C C1
U 1 1 5EE395BF
P 5000 4000
F 0 "C1" H 5115 4046 50  0000 L CNN
F 1 "20p" H 5115 3955 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D8.0mm_W2.5mm_P5.00mm" H 5038 3850 50  0001 C CNN
F 3 "~" H 5000 4000 50  0001 C CNN
	1    5000 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5EE48B66
P 5500 4000
F 0 "C2" H 5615 4046 50  0000 L CNN
F 1 "20p" H 5615 3955 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D8.0mm_W2.5mm_P5.00mm" H 5538 3850 50  0001 C CNN
F 3 "~" H 5500 4000 50  0001 C CNN
	1    5500 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 4150 5000 4250
Connection ~ 5000 5750
Wire Wire Line
	5000 5750 4200 5750
Wire Wire Line
	5500 4150 5500 4250
Wire Wire Line
	5500 4250 5000 4250
Connection ~ 5000 4250
Wire Wire Line
	5000 4250 5000 5750
$Comp
L Device:Crystal Y1
U 1 1 5EE4A56C
P 5250 3750
F 0 "Y1" H 5250 4018 50  0000 C CNN
F 1 "Crystal" H 5250 3927 50  0000 C CNN
F 2 "Crystal:Crystal_HC52-U_Vertical" H 5250 3750 50  0001 C CNN
F 3 "~" H 5250 3750 50  0001 C CNN
	1    5250 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 3600 5000 3600
Wire Wire Line
	5000 3600 5000 3750
Wire Wire Line
	5400 3750 5500 3750
Wire Wire Line
	5100 3750 5000 3750
Connection ~ 5000 3750
Wire Wire Line
	5000 3750 5000 3850
Wire Wire Line
	4800 3500 5500 3500
Wire Wire Line
	5500 3500 5500 3750
Connection ~ 5500 3750
Wire Wire Line
	5500 3750 5500 3850
Wire Wire Line
	6650 4900 4800 4900
Wire Wire Line
	6650 4200 6650 4900
$Comp
L Diode:1N4001 D1
U 1 1 5EFDE744
P 4200 2000
F 0 "D1" V 4246 1920 50  0000 R CNN
F 1 "1N4001" V 4155 1920 50  0000 R CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 4200 1825 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 4200 2000 50  0001 C CNN
	1    4200 2000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4200 2150 4200 2300
$Comp
L Device:Battery_Cell BT1
U 1 1 5EFEEC25
P 2550 3100
F 0 "BT1" H 2668 3196 50  0000 L CNN
F 1 "Battery_Cell" H 2668 3105 50  0000 L CNN
F 2 "Misc_Custom:Battery-Holder_CR2025-CR2032" V 2550 3160 50  0001 C CNN
F 3 "~" V 2550 3160 50  0001 C CNN
	1    2550 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery_Cell BT2
U 1 1 5EFF093B
P 2550 3600
F 0 "BT2" H 2668 3696 50  0000 L CNN
F 1 "Battery_Cell" H 2668 3605 50  0000 L CNN
F 2 "Misc_Custom:Battery-Holder_CR2025-CR2032" V 2550 3660 50  0001 C CNN
F 3 "~" V 2550 3660 50  0001 C CNN
	1    2550 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 3200 2550 3400
Wire Wire Line
	4200 5750 2550 5750
Wire Wire Line
	2550 5750 2550 3700
Wire Wire Line
	4200 1750 3550 1750
Wire Wire Line
	2550 1750 2550 2900
$Comp
L Switch:SW_SPST SW1
U 1 1 5EFF2E98
P 3350 1750
F 0 "SW1" H 3350 1985 50  0000 C CNN
F 1 "SW_SPST" H 3350 1894 50  0000 C CNN
F 2 "Misc_Custom:SW_AMZN_001" H 3350 1750 50  0001 C CNN
F 3 "~" H 3350 1750 50  0001 C CNN
	1    3350 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 1750 2550 1750
Wire Wire Line
	4200 2300 4300 2300
Wire Wire Line
	4300 2300 4300 2600
Connection ~ 4300 2300
Wire Wire Line
	4300 2300 5850 2300
NoConn ~ 5950 4200
NoConn ~ 5950 4000
NoConn ~ 7350 4600
NoConn ~ 7950 4600
Text Label 4200 2300 0    50   ~ 0
VCC
Text Label 4200 5750 0    50   ~ 0
GND
Text Label 4800 3500 0    50   ~ 0
XTAL1
Text Label 4800 3600 0    50   ~ 0
XTAL2
Text Label 4800 4700 0    50   ~ 0
TX
Text Label 4800 4900 0    50   ~ 0
PD3
Text Label 4800 5000 0    50   ~ 0
PD4
$EndSCHEMATC
