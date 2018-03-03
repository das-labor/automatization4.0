EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:PCA9685-TSSOP
LIBS:LabnodeIO-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 7
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
L PCF8574 U7
U 1 1 5A96057F
P 4400 2700
AR Path="/5A960B2A/5A96057F" Ref="U7"  Part="1" 
AR Path="/5A960359/5A96057F" Ref="U1"  Part="1" 
F 0 "U7" H 4050 3300 50  0000 L CNN
F 1 "PCF8574" H 4500 3300 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-16W_7.5x12.8mm_Pitch1.27mm" H 4400 2700 50  0001 C CNN
F 3 "" H 4400 2700 50  0001 C CNN
	1    4400 2700
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR89
U 1 1 5A960586
P 4400 1800
AR Path="/5A960B2A/5A960586" Ref="#PWR89"  Part="1" 
AR Path="/5A960359/5A960586" Ref="#PWR54"  Part="1" 
F 0 "#PWR89" H 4400 1650 50  0001 C CNN
F 1 "+5V" H 4400 1940 50  0000 C CNN
F 2 "" H 4400 1800 50  0001 C CNN
F 3 "" H 4400 1800 50  0001 C CNN
	1    4400 1800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR90
U 1 1 5A96058C
P 4400 3550
AR Path="/5A960B2A/5A96058C" Ref="#PWR90"  Part="1" 
AR Path="/5A960359/5A96058C" Ref="#PWR55"  Part="1" 
F 0 "#PWR90" H 4400 3300 50  0001 C CNN
F 1 "GND" H 4400 3400 50  0000 C CNN
F 2 "" H 4400 3550 50  0001 C CNN
F 3 "" H 4400 3550 50  0001 C CNN
	1    4400 3550
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR53
U 1 1 5A960598
P 3200 3000
AR Path="/5A960359/5A960598" Ref="#PWR53"  Part="1" 
AR Path="/5A960B2A/5A960598" Ref="#PWR88"  Part="1" 
F 0 "#PWR88" H 3200 2850 50  0001 C CNN
F 1 "+5V" H 3200 3140 50  0000 C CNN
F 2 "" H 3200 3000 50  0001 C CNN
F 3 "" H 3200 3000 50  0001 C CNN
	1    3200 3000
	1    0    0    -1  
$EndComp
Text GLabel 3750 2300 0    60   Input ~ 0
SCL
Text GLabel 3750 2400 0    60   Input ~ 0
SDA
$Comp
L R_Small R50
U 1 1 5A9605AD
P 3650 3100
AR Path="/5A960B2A/5A9605AD" Ref="R50"  Part="1" 
AR Path="/5A960359/5A9605AD" Ref="R5"  Part="1" 
F 0 "R50" H 3680 3120 50  0000 L CNN
F 1 "1k5" H 3680 3060 50  0000 L CNN
F 2 "Resistors_SMD:R_0603" H 3650 3100 50  0001 C CNN
F 3 "" H 3650 3100 50  0001 C CNN
	1    3650 3100
	0    1    1    0   
$EndComp
Wire Wire Line
	4400 1800 4400 2000
Wire Wire Line
	4400 3550 4400 3400
Wire Wire Line
	5450 2300 4900 2300
Wire Wire Line
	4900 2400 5450 2400
Wire Wire Line
	5450 2500 4900 2500
Wire Wire Line
	4900 2600 5450 2600
Wire Wire Line
	5450 2700 4900 2700
Wire Wire Line
	4900 2800 5450 2800
Wire Wire Line
	4900 2900 5450 2900
Wire Wire Line
	5450 3000 4900 3000
Wire Wire Line
	3750 2300 3900 2300
Wire Wire Line
	3750 2400 3900 2400
Wire Wire Line
	3750 3100 3900 3100
Wire Wire Line
	3550 3100 3200 3100
Wire Wire Line
	3200 3100 3200 3000
Text HLabel 5450 2300 2    60   Input ~ 0
digital1
Text HLabel 5450 2400 2    60   Input ~ 0
digital2
Text HLabel 5450 2500 2    60   Input ~ 0
digital3
Text HLabel 5450 2600 2    60   Input ~ 0
digital4
Text HLabel 5450 2700 2    60   Input ~ 0
digital5
Text HLabel 5450 2800 2    60   Input ~ 0
digital6
Text HLabel 5450 2900 2    60   Input ~ 0
digital7
Text HLabel 5450 3000 2    60   Input ~ 0
digital8
Text HLabel 3750 2600 0    60   Input ~ 0
A0
Text HLabel 3750 2700 0    60   Input ~ 0
A1
Text HLabel 3750 2800 0    60   Input ~ 0
A2
Wire Wire Line
	3750 2600 3900 2600
Wire Wire Line
	3900 2700 3750 2700
Wire Wire Line
	3750 2800 3900 2800
$EndSCHEMATC
