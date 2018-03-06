void initialize(Adafruit_NeoPixel strip) {
  strip.begin();
  strip.show();
}

void LEDsetup() {
  initialize(strip);
}

//












void colorChange(uint32_t c) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
  }
  strip.show();
}





void colorBlink(uint32_t c, uint32_t delaytime) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
  }
  strip.show();
  delay(delaytime);
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0));
  }
  strip.show();
  delay(delaytime);
}





void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}



void colorDim(uint32_t wait) {
  for(uint16_t i=strip.getBrightness(); i>0; i--) {
    strip.setBrightness(i);
    strip.show();
    delay(wait/256);
  }
}




void colorUndim(uint32_t wait) {
  for(uint16_t i=strip.getBrightness()+1; i<255; i++) {
    strip.setBrightness(i+1);
    strip.show();
    delay(wait/256);
  }
}
s
