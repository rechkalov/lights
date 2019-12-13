short phase = 0;

void processRainbow() {
  phase = phase + speed;
  byte numPixels = strip.numPixels();
  for(int i=0; i<numPixels; i++) {
    short pixelHue = phase + (i * 65535 / numPixels);
    strip.setPixelColor(i, Adafruit_NeoPixel::ColorHSV(pixelHue, 255, 255));
  }
  strip.show(); // Update strip with new contents
  delay(1);  // Pause for a moment
}
