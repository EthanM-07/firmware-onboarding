// LEDController.h
#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include <BMEConstants.h>

/**
 * @brief Controls LED behavior driven by sensor interface data.
 * 
 * @tparam TInterfaceInstance A singleton type providing an `instance()` method 
 *                            whose target object implements `getTemp()` (or `gettemp()`).
 */
template <typename TInterfaceInstance>
class LEDController 
{
public:
    LEDController() = default;

    /**
     * @brief Computes the LED blink rate based on current sensor temperature.
     * @return Blink rate frequency as a float.
     */
    float getblinkRate() const 
    {
        return TInterfaceInstance::instance().gettemp() * BMEConstants::frqModConst;
    }
};