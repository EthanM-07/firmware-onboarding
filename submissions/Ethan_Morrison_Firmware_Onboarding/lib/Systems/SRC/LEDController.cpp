#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"
#include "BME280SPIInterface.h"
#include "BME280I2CInterface.h"

template <typename TInterfaceInstance>
class LEDController
{
public:
  LEDController() = default;

  float getblinkRate() { return TInterfaceInstance::instance().gettemp()*BMEConstants::frqModConst; }
};