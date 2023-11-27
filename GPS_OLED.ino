#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_SH1106.h>
#include <PWMServo.h>

#define OLED_Address 0x3c
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SH1106 display(-1);
PWMServo myservo;

const int RX = 3, TX = 4;
int red = 1, green = 2;  // led lights
int pos = 0;
int target = 0;
float gear_ratio = 1.5;
TinyGPSPlus gps;
SoftwareSerial gpsSerial(RX, TX);

void setup() {
  gpsSerial.begin(9600);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  myservo.attach(9);
}

void loop() {
  while (gpsSerial.available() > 0)
    if (gps.encode(gpsSerial.read())) {
      display.setTextColor(WHITE);
      display.setTextSize(1);
      display.setCursor(0, 20);
      display.print(gps.date.year());
      display.print(F("-"));
      display.print(gps.date.month());
      display.print(F("-"));
      display.print(gps.date.day() - 1);
      display.print(F(" "));
      display.print(gps.time.hour() + 5);
      display.print(F(":"));
      display.print(gps.time.minute());
      display.print(F(":"));
      display.println(gps.time.second());
      display.println();

      /* GPS signal found */
      if (gps.speed.isValid()) {
        digitalWrite(green, HIGH);  // change led to green
        digitalWrite(red, LOW);
        display.setTextSize(2);
        display.print(gps.speed.mph());
        display.print(F(" MPH"));
        display.display();
        display.clearDisplay();

        /* 
        Actual MPH Reading (speed: volume)
        20: 20
        40: 25
        50: 28
        60: 30
        */
        /* Rotate servo N degree according to current GPS speed */
        if (gps.speed.mph() > 0 && gps.speed.mph() <= 40) {
          target = 60 * gear_ratio;
          rotate(target);
        } else if (gps.speed.mph() > 40 && gps.speed.mph() <= 50) {
          target = 30 * gear_ratio;     // +5 steps
          rotate(target);  
        } else if (gps.speed.mph() > 50 && gps.speed.mph() <= 60) {
          target = 18 * gear_ratio;     // +2 steps
          rotate(target); 
        } else {
          target = 0;                   // +3 steps
          rotate(target);
        }

        /* Idle Diagnostic (clockwise) */
        // if (gps.speed.mph() > 0 && gps.speed.mph() <= 0.25) {
        //   target = 0;
        //   rotate(target);
        // } else if (gps.speed.mph() > 0.25 && gps.speed.mph() <= 0.5) {
        //   target = 30 * gear_ratio;  // +5 steps
        //   rotate(target);
        // } else if (gps.speed.mph() > 0.5 && gps.speed.mph() <= 0.75) {
        //   target = 48 * gear_ratio;  // +2 steps
        //   rotate(target);
        // } else {
        //   target = 60 * gear_ratio;  // +3 steps
        //   rotate(target);
        // }

        /* Idle Diagnostic (anti-clockwise) */
        // if (gps.speed.mph() > 0 && gps.speed.mph() <= 0.25) {
        //   target = 60 * gear_ratio;
        //   rotate(target);
        // } else if (gps.speed.mph() > 0.25 && gps.speed.mph() <= 0.5) {
        //   target = 48 * gear_ratio;  // +2 steps
        //   rotate(target);
        // } else if (gps.speed.mph() > 0.5 && gps.speed.mph() <= 0.75) {
        //   target = 30 * gear_ratio;   // +3 steps
        //   rotate(target); 
        // } else {
        //   target = 0;                 // +5 steps
        //   rotate(target);
        // }

      } 
      /* GPS signal not found */
      else {
        digitalWrite(red, HIGH);  // change led to red
        digitalWrite(green, LOW);
        display.print("GPS signal not found!");
        display.display();
        display.clearDisplay();
      }
    }
}

/* Rotate servo motor incrementally for smoother volume adjustment */
void rotate(int target) {
  if (pos < target) {
    for (; pos < target; pos += 1) {
      myservo.write(pos);
      delay(50);
    }
  }

  else if (pos > target) {
    for (; pos > target; pos -= 1) {
      myservo.write(pos);
      delay(50);
    }
  }
}