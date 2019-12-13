short* phases = 0;
short* speeds = 0;
short* derivatives = 0;
short* derivativeTtls = 0;

void processRandom() {
  byte numPixels = strip.numPixels();
  
  if(phases == 0)
    initializeRandom(numPixels);
  
  for(int i=0; i<numPixels; i++) {
    if(derivativeTtls[i] == 0) {
      derivatives[i] = random(0, 101)-50;
      derivativeTtls[i] = random(1, 100);
    }

    speeds[i] += derivatives[i];
    phases[i] += speeds[i];
    
    strip.setPixelColor(i, Adafruit_NeoPixel::ColorHSV(phases[i], 255, 255));
  }
  
  strip.show(); // Update strip with new contents
  delay(1);  // Pause for a moment
}

void initializeRandom(byte numPixels) {
  phases = new short[numPixels];
  speeds = new short[numPixels];
  derivatives = new short[numPixels];
  derivativeTtls = new short[numPixels];
  for(byte i=0; i<numPixels; i++) {
    phases[i] = 0;
    speeds[i] = 0;
    derivatives[i] = 0;
    derivativeTtls[i] = 0;
  }
}
