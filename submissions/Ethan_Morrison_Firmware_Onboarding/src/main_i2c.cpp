#include <Arduino.h>
#include "BME280I2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;
using LEDControllerInstance = etl::singleton<LEDController<BMEI2CInterfaceInstance>>;


int LEDpin = BMEConstants::LEDpin;

BMEI2CInterface bmeHardwareDevice;
LEDController<BMEI2CInterfaceInstance> ledControllerDevice;

void setup() {

  BMEI2CInterfaceInstance::create(bmeHardwareDevice);
  LEDControllerInstance::create(ledControllerDevice);

  BMEI2CInterfaceInstance::instance().begin();
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