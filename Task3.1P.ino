#include "thingProperties.h"   
#include <BH1750FVI.h>   // for sensor

// creating light sensor instance
BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);   

void setup() {

  Serial.begin(9600);
  LightSensor.begin();

  delay(1500);
  pinMode(LED_BUILTIN, OUTPUT);

  // predefined function in thingProperties.h
  initProperties();    

  // connects to Arduino Iot cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  // obtains information related to the state of network and IoT Cloud connection
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  lightIntensity = LightSensor.GetLightIntensity();   // storing values from light sesnor in lightIntensity variable
  
  Serial.print(lightIntensity);
  delay(1000);
}

void onLedChange()  {
  digitalWrite(LED_BUILTIN, led);
}
