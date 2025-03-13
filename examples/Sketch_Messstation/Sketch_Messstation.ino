#include <OceanTalents.h>
#include <SPI.h>
#include <SD.h>

File myFile;

String fileName;

void setup() {
  SD.begin(4);
  HDC_begin();
  BMP_begin();
  TSL_begin();
  RTC_begin();

  fileName = RTC_hour() + "-" + RTC_min() + "-" + RTC_sec() + ".csv";
  
  myFile = SD.open(fileName, FILE_WRITE);
  myFile.println("Datum;Zeit;Beleuchtungsstaerke(TSL25911) [lx];Temperatur(BMP280) [degC];Temperatur(HDC1080) [degC];Luftdruck(BMP280) [hPa];Luftfeuchtigkeit(HDC1080) [%]");
  myFile.close();
}

void loop() {
  myFile = SD.open(fileName, FILE_WRITE);
  
  myFile.print(RTC_year() + "-" + RTC_month() + "-" + RTC_day());
  myFile.print(";");
  myFile.print(RTC_hour() + ":" + RTC_min() + ":" + RTC_sec());
  myFile.print(";");
  myFile.print(read_TSL2());
  myFile.print(";");
  myFile.print(read_BMP_T2());
  myFile.print(";");
  myFile.print(read_HDC_T2());
  myFile.print(";");
  myFile.print(read_BMP_P2());
  myFile.print(";");
  myFile.println(read_HDC_H2());
  
  myFile.close();
  
  delay(1000);
}
