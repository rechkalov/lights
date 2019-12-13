#include <Adafruit_NeoPixel.h>

// How many NeoPixels are attached to the Arduino?
#define LED_PIN 6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 10

// a String to hold incoming data
String commandText = "";         

// whether the string is complete
bool commandComplete = false;

int brightness = 50;
int speed = 25;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  
  strip.setBrightness(brightness);
  
  Serial.begin(9600);
  commandText.reserve(200);
  
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if(commandComplete) {
    processCommand();
    commandText = "";
    commandComplete = false;
  }
  processSerial();
  processRainbow();
}

void processSerial() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    commandText += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      commandComplete = true;
    }
  }
}

void processCommand() {
  if(commandText[0] == 'b' || commandText[0] == 'B') {
    brightness = 0;
    for(int i=1; commandText[i] != '\n'; i++)
      brightness = brightness*10 + (commandText[i]-'0');

    strip.setBrightness(brightness);
    return; 
  }

  if(commandText[0] == 's' || commandText[0] == 'S') {
    speed = 0;
    for(int i=1; commandText[i] != '\n'; i++)
      speed = speed*10 + (commandText[i]-'0');
    return; 
  }
}
