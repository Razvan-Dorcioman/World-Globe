#include <Wire.h>
#include "Adafruit_TCS34725.h"

/* Connect SCL    to analog 5
   Connect SDA    to analog 4
   Connect VDD    to 3.3V DC
   Connect GROUND to common ground */
   
 // Adafruit_TCS34725 tcs = Adafruit_TCS34725();

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);

void setup(void) {
  Serial.begin(9600);
  
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }
  
}

void loop(void) {
  uint16_t r, g, b, c, colorTemp, lux;
  
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature(r, g, b);
  lux = tcs.calculateLux(r, g, b);

// Pentru test!
//  Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" K - ");
//  Serial.print("Lux: "); Serial.print(lux, DEC); Serial.print(" - ");
//  Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
//  Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
//  Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
//  Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
//  Serial.println(" ");
//  delay(5000);


//Asia
if(colorTemp > 2500 && colorTemp < 3000 && lux > 900 && lux < 1700 && r > 1600 && r < 2700 && g > 1200 && g < 2200 && b > 600 && b < 1200 && c > 3000 && c < 6000)
   Serial.print("1");
//Europa
else if(colorTemp > 9000 && colorTemp < 14000 && lux > 100 && lux < 400 && r > 200 && r < 900 && g > 200 && g < 850 && b > 200 && b < 820 && c > 700 && c < 2500)
   Serial.print("2");
//Africa
else if(colorTemp > 7000 && colorTemp < 9000 && lux > 100 && lux < 500 && r > 200 && r < 800 && g > 200 && g < 800 && b > 200 && b < 800 && c > 600 && c < 2100)   
   Serial.print("3");
//Australia
else if(colorTemp > 13500 && colorTemp < 25100 && lux > 80 && lux < 270 && r > 200 && r < 700 && g > 200 && g < 700 && b > 200 && b < 600 && c > 600 && c < 2000) 
   Serial.print("4");
//America
else if(colorTemp > 10000 && colorTemp < 70000 && lux > 60000 && lux < 75100 && r > 600 && r < 1500 && g > 200 && g < 810 && b > 200 && b < 8300 && c > 300 && c < 3290)
   Serial.print("5");
//Antartica
else if(colorTemp > 9000 && colorTemp < 11600 && lux > 700 && lux < 1650 && r > 1000 && r < 1650 && g > 1200 && g < 2000 && b > 1150 && b < 2070 && c > 3500 && c < 6200)   
   Serial.print("6");
else
   Serial.print("0");
  
}
