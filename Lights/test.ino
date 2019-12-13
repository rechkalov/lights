struct {
  short rSpeed;
  short gSpeed;
  short bSpeed;
  short rPos;
  short gPos;
  short bPos;
  
} LightsSettings = {
  .rSpeed = 50,
  .gSpeed = 25,
  .bSpeed = 75,
  .rPos = 0,
  .gPos = 0,
  .bPos = 0,
};

void processLights() {
  LightsSettings.rPos += LightsSettings.rSpeed;
  LightsSettings.gPos += LightsSettings.gSpeed;
  LightsSettings.bPos += LightsSettings.bSpeed;
  
  byte numPixels = strip.numPixels();
  for(int i=0; i<numPixels; i++) {
    short rPhase = i * (65535 / numPixels) + LightsSettings.rPos;
    short gPhase = i * (65535 / numPixels) + LightsSettings.gPos;
    short bPhase = i * (65535 / numPixels) + LightsSettings.bPos;

    float rValue = sin(2 * 3.1415f * rPhase / 65535);
    float gValue = sin(2 * 3.1415f * gPhase / 65535);
    float bValue = sin(2 * 3.1415f * bPhase / 65535);
    
    byte r = rValue > 0 ? (byte)(rValue * 255) : 0;
    byte g = gValue > 0 ? (byte)(gValue * 255) : 0;
    byte b = bValue > 0 ? (byte)(bValue * 255) : 0;
    
    strip.setPixelColor(i, r, g, b);
  }
  
  strip.show(); // Update strip with new contents
  delay(1);  // Pause for a moment
}
