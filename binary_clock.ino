#include <Adafruit_NeoPixel.h>



// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(32, 6, NEO_GRB + NEO_KHZ800);
  
  int sec01=0;
  int sec10=0;
  int min01=0;
  int min10;
  int hr01=0;
  int hr10=0; //start the time on 00:00:00  
  int tick=0; //tick counter
  int mbtn=0;
  int hbtn=0;

void setup() {
  // Defining NeoPixel Matrix on Pin 6 by first defining strip then matrix.
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'      
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //Second counter
  if (millis() - tick >= 1000) {
  tick = millis();
  sec01++;
  }

  //Second tens place
  if (sec01 >= 10) {
  sec10++;
  sec01 = 0;
  }

  // move forward one minute every 60 seconds
  if (sec10 >= 6) {
  min01++;
  sec10 = 0; // reset seconds to zero
  }

  //Minute tens place
  if (min01 >= 10) {
  min10++;
  min01 = 0;
  }
  
  // move forward one hour every 60 minutes
  if (min10 >=6) {
  hr01++;
  min10 = 0; // reset minutes to zero
  }

  //Hour tens place
  if (hr01 >= 10) {
  hr10++;
  hr01 = 0;
  }

  if (hr10 >=2 && hr01 >= 4) {
  hr01=0;
  hr10=0; // reset minutes to zero
  }

  //Second Ones Place Display 
  if(sec01 == 1 || sec01 == 3 || sec01 == 5 || sec01 == 7 || sec01 == 9) {    strip.setPixelColor(24, 255, 55, 255, 255);} else {strip.setPixelColor(24, 0, 0, 0, 0);}
  if(sec01 == 2 || sec01 == 3 || sec01 == 6 || sec01 == 7) {strip.setPixelColor(16, 255, 55, 255, 255);} else {strip.setPixelColor(16, 0, 0, 0, 0);}
  if(sec01 == 4 || sec01 == 5 || sec01 == 6 || sec01 == 7) {strip.setPixelColor(8, 255, 55, 255, 255);} else {strip.setPixelColor(8, 0, 0, 0, 0);}
  if(sec01 == 8 || sec01 == 9) {strip.setPixelColor(0, 255, 55, 255, 255);} else {strip.setPixelColor(0, 0, 0, 0, 0);}

  //Second Tens Place Display
  if(sec10 == 1 || sec10 == 3 || sec10 == 5) {strip.setPixelColor(25, 255, 55, 255, 255);} else {strip.setPixelColor(25, 0, 0, 0, 0);}
  if(sec10 == 2 || sec10 == 3) {strip.setPixelColor(17, 255, 55, 255, 255);} else {strip.setPixelColor(17, 0, 0, 0, 0);}
  if(sec10 == 4 || sec10 == 5) {strip.setPixelColor(9, 255, 55, 255, 255);} else {strip.setPixelColor(9, 0, 0, 0, 0);}

  //Minute Ones Place Display
  if(min01 == 1 || min01 == 3 || min01 == 5 || min01 == 7 || min01 == 9) {strip.setPixelColor(26, 55, 255, 255, 255);} else {strip.setPixelColor(26, 0, 0, 0, 0);}
  if(min01 == 2 || min01 == 3 || min01 == 6 || min01 == 7) {strip.setPixelColor(18, 55, 255, 255, 255);} else {strip.setPixelColor(18, 0, 0, 0, 0);}
  if(min01 == 4 || min01 == 5 || min01 == 6 || min01 == 7) {strip.setPixelColor(10, 55, 255, 255, 255);} else {strip.setPixelColor(10, 0, 0, 0, 0);}
  if(min01 == 8 || min01 == 9) {strip.setPixelColor(2, 55, 255, 255, 255);} else {strip.setPixelColor(2, 0, 0, 0, 0);}

  //Minute Tens Place Display
  if(min10 == 1 || min10 == 3 || min10 == 5) {strip.setPixelColor(27, 55, 255, 255, 255);} else {strip.setPixelColor(27, 0, 0, 0, 0);}
  if(min10 == 2 || min10 == 3) {strip.setPixelColor(19, 55, 255, 255, 255);} else {strip.setPixelColor(19, 0, 0, 0, 0);}
  if(min10 == 4 || min10 == 5) {strip.setPixelColor(11, 55, 255, 255, 255);} else {strip.setPixelColor(11, 0, 0, 0, 0);}
  
  //Hour Ones Place Display
  if(hr01 == 1 || hr01 == 3 || hr01 == 5 || hr01 == 7 || hr01 == 9) {strip.setPixelColor(3, 255, 255, 55, 255);} else {strip.setPixelColor(3, 0, 0, 0, 0);}
  if(hr01 == 2 || hr01 == 3 || hr01 == 6 || hr01 == 7) {strip.setPixelColor(11, 255, 255, 55, 55);} else {strip.setPixelColor(11, 0, 0, 0, 0);}
  if(hr01 == 4 || hr01 == 5 || hr01 == 6 || hr01 == 7) {strip.setPixelColor(19, 255, 255, 55, 255);} else {strip.setPixelColor(19, 0, 0, 0, 0);}
  if(hr01 == 8 || hr01 == 9) {strip.setPixelColor(27, 255, 255, 55, 255);} else {strip.setPixelColor(27, 0, 0, 0, 0);}

  //Hour Tens Place Display
  if(hr01 == 1) {strip.setPixelColor(29, 255, 255, 55, 255);} else {strip.setPixelColor(29, 0, 0, 0, 0);}
  if(hr01 == 2) {strip.setPixelColor(21, 255, 255, 55, 55);} else {strip.setPixelColor(21, 0, 0, 0, 0);}

  mbtn = analogRead(0);    // add one minute when pressed
   if(mbtn<800) {
   min01++;
   sec01=0;
   sec10=0;
   delay(250);
  }
  
  hbtn = analogRead(5);    // add one hour when pressed
   if(hbtn<800) {
   hr01++;
   sec01=0;
   sec10=0;
   delay(250);
  }
  strip.show(); // Initialize set pixels to 'on'
}

