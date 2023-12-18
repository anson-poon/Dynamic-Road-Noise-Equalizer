# Dynamic-Road-Noise-Equalizer

## Overview
* A system that utilized the Arduino UNO microcontroller with a GPS module to automatically equalize speaker volume according to vehicle speed. 
* The Arduino script will translate location data and map it to a specific degree that the servo motor turns for volume control. 
* Diagnostics via OLED display to display real-time GPS information and green/red LEDs to show GPS connectivity. 
* Custom 3D printed components to integrate equalizer system to vehicle dashboard.

## Goal
Enhances driving safety by eliminating the need for taking eyes off the road to manually adjust volume to compensate for road noise during driving, particularly useful for retrofitting on older vehicles with limited noise isolation. 

## Parts
* Arduino UNO
* 1.3" 128x64 SPI I2C SH1106 OLED Display Module
* Neo-6M V2 GPS Module
* 220-ohm resistors x2
* green/red LEDs
* SM-S2309S Servo motor

## Files
* GPS_OLED.ino - Arduino driver program
* Servo Bevel Wheel Gear.stl / Servo Bevel Pinon Gear.stl - 3D models for gears
* Enclosure Assembly.3mf - 3D model for servo motor enclosure
