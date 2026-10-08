#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include <BMEConstants.h>

class BMESPIInterface
{
public:
BMESPIInterface() : bme(BMEConstants::CSPin) {}
bool begin() {
return bme.begin();  
}
float gettemp() {return bme.readTemperature();}

private:
 Adafruit_BME280 bme;
};
using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;


