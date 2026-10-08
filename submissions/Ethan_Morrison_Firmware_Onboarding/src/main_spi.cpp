#include <Arduino.h>
#include "BME280SPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;
using LEDControllerInstance = etl::singleton<LEDController<BMESPIInterfaceInstance>>;


int LEDpin = BMEConstants::LEDpin;

BMESPIInterface bmeHardwareDevice;
LEDController<BMESPIInterfaceInstance> ledControllerDevice;

void setup() {

  BMESPIInterfaceInstance::create(bmeHardwareDevice);
  LEDControllerInstance::create(ledControllerDevice);

  BMESPIInterfaceInstance::instance().begin();
  pinMode(LEDpin, OUTPUT);
}

void loop() {
  float blinkRate = LEDControllerInstance::instance().getblinkRate();
  float blink_period = 1000.0f/blinkRate;

  digitalWrite(LEDpin, HIGH);
  delay(.5f*blink_period);

  digitalWrite(LEDpin, LOW);
  delay(.5f*blink_period);
}