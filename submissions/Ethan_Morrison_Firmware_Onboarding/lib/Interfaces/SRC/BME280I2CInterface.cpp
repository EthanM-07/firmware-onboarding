#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterface
{
public:
 BMEI2CInterface() = default;
 bool begin(){
    return bme.begin(0x76);
 }
 float gettemp() {return bme.readTemperature();}

private:
 Adafruit_BME280 bme;
};
using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;
