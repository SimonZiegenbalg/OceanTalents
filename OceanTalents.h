#ifndef OCEANTALENTS_H
#define OCEANTALENTS_H

#include <Arduino.h>

void TSL_begin();
void BMP_begin();
void HDC_begin();
void RTC_begin();
double read_BMP_T();
double read_HDC_T();
double read_BMP_P();
double read_HDC_H();
double read_TSL();
String read_BMP_T2();
String read_HDC_T2();
String read_BMP_P2();
String read_HDC_H2();
String read_TSL2();
String RTC_year();
String RTC_month();
String RTC_day();
String RTC_hour();
String RTC_min();
String RTC_sec();

#endif