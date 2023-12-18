# Dynamic-Road-Noise-Equalizer

## Overview
* A system that utilized the Arduino UNO microcontroller with a GPS module to automatically equalize speaker volume according to vehicle speed. 
* The Arduino script will translate location data and map it to a specific degree that the servo motor turns for volume control. 
* Diagnostics via OLED display to display real-time GPS information and green/red LEDs to show GPS connectivity. 
* Custom 3D printed components to integrate equalizer system to vehicle dashboard.

## Goal
Enhances driving safety by eliminating the need for taking the eyes off the road to manually adjust audio volume to compensate for road noise during driving, which is particularly useful for retrofitting on older vehicles with limited noise isolation. 

## Parts Used
* Arduino UNO R3
* 1.3" 128x64 SPI I2C SH1106 OLED Display Module
* Neo-6M V2 GPS Module
* SM-S2309S Servo motor
* 220-ohm resistors x2
* green/red LEDs

## Files
* GPS_OLED.ino - Arduino driver program
* Servo Bevel Wheel Gear.stl / Servo Bevel Pinon Gear.stl - 3D models for gears
* Enclosure Assembly.3mf - 3D model for servo motor enclosure

Assemble Guide
![Installation Isometric](https://github.com/anson-poon/Dynamic-Road-Noise-Equalizer/assets/75619539/ad5bdb2a-4c47-4796-9582-ef9677e20962)

&nbsp;
&nbsp;
Wiring Schematic (w/breadboard)
![Breadboard Wiring Schematic](https://github.com/anson-poon/Dynamic-Road-Noise-Equalizer/assets/75619539/46167d5c-4750-48a5-a66e-4267710476cf)

&nbsp;
&nbsp;
Wiring Schematic (net)
![Net Wiring Schematic](https://github.com/anson-poon/Dynamic-Road-Noise-Equalizer/assets/75619539/4cc4920d-4ce5-4468-8241-81d79541acd3)

