// BMESPIInterface.h
#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface 
{
public:
    /**
     * @brief Constructs the SPI interface using hardware SPI.
     * @param csPin Chip Select pin (defaults to BMEConstants::CSPin).
     */
    BMESPIInterface() : bme(BMEConstants::CSPin) {}

    /**
     * @brief Initializes the BME280 sensor over SPI.
     * @return true if initialization succeeded, false otherwise.
     */
    bool begin() {
    return bme.begin();  
    }

    /**
     * @brief Reads ambient temperature from the sensor.
     * @return Temperature in degrees Celsius.
     */
    float gettemp() {return bme.readTemperature();}

private:
    Adafruit_BME280 bme;
};

// Singleton alias via Embedded Template Library (ETL)
using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;