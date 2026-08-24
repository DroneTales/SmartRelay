# Умное реле для Apple Home

Здесь вы найдете прошивку и схему для умного реле, совместимого с Apple Home. По любым вопросам вы можете смело обращаться в мой [телеграм канале](t.me/drone_tales).  

**Используемые компоненты**

- Модуль Arduino реле - 1 шт.
- ESP32C3FN4 Super Mini - 1 шт.
- Блок питания 5V 1A - 1 шт.
- Конденсатор 3000mF x 6.3V - 1 шт.
- Транзистор 2N2904 - 1 шт.
- Резистор 1K - 1 шт.
- Резистор 220 Ohm - 1 шт.
 
**Используемые библиотеки Arduino**

- esp32 by Espressif Systems (board) 3.3.7
- HomeSpan 2.1.7
 
**Настройки Arduino IDE**

- Board: ESP32C3 Dev BModule
- ESP CDC On Boot: Enabled
- CPU Frequency: 80MHz (WiFi)
- Core Debug Level: None
- Erase All Flash Before Sketch Upload: Disabled
- Flash frequency: 80Mhz
- Flash Mode: QIO
- Flash Size: 4MB (32Mb)
- JTAG Adapter: Disabled
- Partition Scheme: Huge APP (3MB No OTA/1MB SPIFFS)
- Upload Speed: 921600
- Zigbee Mode: Disabled
- Programmer: Esptool
