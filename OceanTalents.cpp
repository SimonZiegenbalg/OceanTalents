#include <Arduino.h>
#include "OceanTalents.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2591.h>
#include <ClosedCube_HDC1080.h>
#include <Adafruit_BMP280.h>
#include <RV8523.h>

ClosedCube_HDC1080 hdc1080;
Adafruit_BMP280 bmp;
Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591);
RV8523 rtc;

String BMP_T = "Fehler";
String HDC_T = "Fehler";
String BMP_P = "Fehler";
String HDC_H = "Fehler";
String TSL = "Fehler";


void TSL_begin(){
  tsl.begin();
}

void BMP_begin(){
  bmp.begin();
}

void HDC_begin(){
  hdc1080.begin(0x40);
}

void RTC_begin(){
  rtc.begin();
}

double read_BMP_T(){
  return bmp.readTemperature();
}

double read_HDC_T(){
  return hdc1080.readTemperature();
}

double read_BMP_P(){
  return (bmp.readPressure() / 100);
}

double read_HDC_H(){
  return hdc1080.readHumidity();
}

double read_TSL(){
  uint32_t lum = tsl.getFullLuminosity();
  uint16_t ir, full;
  ir = lum >> 16;
  full = lum & 0xFFFF;
  return tsl.calculateLux(full, ir);
}

String read_BMP_T2(){
  BMP_T = String(bmp.readTemperature());
  BMP_T.replace(".", ",");
  return BMP_T;
}

String read_HDC_T2(){
  HDC_T = String(hdc1080.readTemperature());
  HDC_T.replace(".", ",");
  return HDC_T;
}

String read_BMP_P2(){
  BMP_P = String((bmp.readPressure()/100));
  BMP_P.replace(".", ",");
  return BMP_P;
}

String read_HDC_H2(){
  HDC_H = String(hdc1080.readHumidity());
  HDC_H.replace(".", ",");
  return HDC_H;
}

String read_TSL2(){
  uint32_t lum = tsl.getFullLuminosity();
  uint16_t ir, full;
  ir = lum >> 16;
  full = lum & 0xFFFF;
  TSL = String(tsl.calculateLux(full, ir));
  TSL.replace(".", ",");
  return TSL;
}

String RTC_year(){
  uint8_t sec, min, hour, day, month;
  uint16_t year;
  rtc.get(&sec, &min, &hour, &day, &month, &year);
  return (String(year));
}

String RTC_month(){
  uint8_t sec, min, hour, day, month;
  uint16_t year;
  rtc.get(&sec, &min, &hour, &day, &month, &year);
  return (String(month));
}

String RTC_day(){
  uint8_t sec, min, hour, day, month;
  uint16_t year;
  rtc.get(&sec, &min, &hour, &day, &month, &year);
  return (String(day));
}

String RTC_hour (){
  uint8_t sec, min, hour, day, month;
  uint16_t year;
  rtc.get(&sec, &min, &hour, &day, &month, &year);
  return (String(hour));
}

String RTC_min (){
  uint8_t sec, min, hour, day, month;
  uint16_t year;
  rtc.get(&sec, &min, &hour, &day, &month, &year);
  return (String(min));
}

String RTC_sec (){
  uint8_t sec, min, hour, day, month;
  uint16_t year;
  rtc.get(&sec, &min, &hour, &day, &month, &year);
  return (String(sec));
}