// ESP32C3 Dev Kit
// ===============================================================
// Arduino IDE settings:
//   - Board: ESP32C3 Dev Module
//   - ESP CDC On Boot: Enabled
//   - CPU Frequency: 80MHz (WiFi)
//   - Core Debug Level: None
//   - Erase All Flash Before Sketch Upload: Disabled
//   - Flash frequency: 80Mhz
//   - Flash Mode: QIO
//   - Flash Size: 4MB (32Mb)
//   - JTAG Adapter: Disabled
//   - Partition Scheme: Huge APP (3MB No OTA/1MB SPIFFS)
//   - Upload Speed: 921600
//   - Zigbee Mode: Disabled
//   - Programmer: Esptool
// ===============================================================

#include <HomeSpan.h>


/**************************************************************************************/
/*                                        Pins                                        */

#define STATUS_LED_PIN  GPIO_NUM_5
#define CONTROL_PIN     GPIO_NUM_9
#define RELAY_PIN       GPIO_NUM_10

/**************************************************************************************/


/**************************************************************************************/
/*                                  HomeSpan sensors                                  */

// Lamp relay record.
struct LampRelay : Service::LightBulb
{
    SpanCharacteristic* FPower;
    
    LampRelay() : Service::LightBulb()
    {
        FPower = new Characteristic::On();
    }
    
    bool update()
    {
        digitalWrite(RELAY_PIN, FPower->getNewVal());
        return true;
    }
};

/**************************************************************************************/


/**************************************************************************************/
/*                                 Arduino  rountines                                 */

// Arduino initialization routine.
void setup()
{
    // Initialize debug serial port.
    Serial.begin(115200);

    // Initialize pins.
    pinMode(STATUS_LED_PIN, OUTPUT);
    pinMode(CONTROL_PIN, INPUT);
    pinMode(RELAY_PIN, OUTPUT);

    // Turn all output pins off.
    digitalWrite(STATUS_LED_PIN, HIGH);
    digitalWrite(RELAY_PIN, LOW);

    // Initialize HomeSpan.
    homeSpan.setControlPin(CONTROL_PIN);
    homeSpan.setStatusPin(STATUS_LED_PIN);
    homeSpan.setPairingCode("63005322");
    homeSpan.begin(Category::Lighting, "DroneTales Lamp Switch");

    // Build device's serial number.
    char Sn[24];
    snprintf(Sn, 24, "DRONETALES-%llX", ESP.getEfuseMac());

    // Configure device.
    new SpanAccessory();
    new Service::AccessoryInformation();
    new Characteristic::Identify();
    new Characteristic::Manufacturer("DroneTales");
    new Characteristic::SerialNumber(Sn);
    new Characteristic::Model("DroneTales Lamp Switch");
    new Characteristic::FirmwareRevision("1.0.0.0");
    new LampRelay(); 
}

// Arduino main loop.
void loop()
{
    homeSpan.poll();
}

/**************************************************************************************/