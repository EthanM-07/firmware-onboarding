#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterface 
{
public:
    BMEI2CInterface() = default;

    /**
     * @brief Initializes the BME280 sensor over I2C.
     * @param addr I2C address of the sensor (defaults to 0x77 or a constant from BMEConstants.h).
     * @return true if initialization succeeded, false otherwise.
     */
    bool begin(uint8_t address = 0x77) {
    return bme.begin(address);
  }
    /**
     * @brief Reads the ambient temperature from the sensor.
     * @return Temperature in degrees Celsius.
     */
    float gettemp() {return bme.readTemperature();}

private:
    Adafruit_BME280 bme;
};

// Singleton alias via Embedded Template Library (ETL)
using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;