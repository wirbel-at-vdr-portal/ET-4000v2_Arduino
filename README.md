# ET-4000v2_Arduino
Re-use an 3D printer mainboard as Arduino IDE compatible dev board. No soldering is necessary, only a programmer once to upload the Arduino style bootloader.
As soon as the bootloader is programmed, the board behaves like an Uno or similar.

# Project Page
https://github.com/wirbel-at-vdr-portal/ET-4000v2_Arduino

# ET-4000 v2 features
This board has a lot of interesting features, once usable. As not schematics is known, any connection needs to be found.
* ATmega1284p, 128k flash, 16MHz clock
* 12V/2.5A input socket
* USB connector, connected via CH340 to UART0
* 4 HR4988 stepper motor drivers
* 3 end switch inputs
* 2 temperature inputs (analog pin with 4.7k pullup, second pin is GND)
* 1 fan connector output with PWM
* 2 strong heater outputs (low-side switch)
* 1 12-pol display connector with UART1, SPI, I2C and four analog/digital inputs
* 1 mini sdcard slot
* 1 6-pol ISP programming header

NOTE: this is 5V logic. Do not connect 3.3V logic to the outputs of the ATmega1284p. Connecting 3.3V outputs to the inputs of the ATmega1284p might work.

# Getting the board programmable in the Arduino IDE
To access the board in the Arduino IDE, a new bootloader needs to be programmed to the board.
A tiny programmer is needed:
* usbasp or clone
* another Arduino-compat board, configured as programmer.
* ..
A small howto is given in [bootloader.md](bootloader.md).

# Using the board in a project.
To include this board in your project, include the file ET4000v2_pins.h.
Also, enshure that the MCUdude/MightyCore hardware package is installed and you choose the correct board settings.

All pins are known. If you find some pins to be wrong, do a pull request or open a bug.

# Pin definitions
In the following table, pin is the number in Arduino IDE, the function table should be self explaining.

| ATmega1284p               |Pin | Function          |
|---------------------------|----|-------------------|
| PA0 (ADC0/PCINT0)         | A0 | SD_ENABLE         |
| PA1 (ADC1/PCINT1)         | A1 | J1_A1             |
| PA2 (ADC2/PCINT2)         | A2 | J1_A2             |
| PA3 (ADC3/PCINT3)         | A3 | J1_A3             |
| PA4 (ADC4/PCINT4)         | A4 | J1_A4             |
| PA5 (ADC5/PCINT5)         | A5 | ZENABLE           |
| PA6 (ADC6/PCINT6)         | A6 | TBED (input)      |
| PA7 (ADC7/PCINT7)         | A7 | THOTEND  (input)  |
|---------------------------|----|-------------------|
| PB0 (XCK0/T0/PCINT8)      | 0  | EDIR              |
| PB1 (T1/CLKO/PCINT9)      | 1  | ESTEP             |
| PB2 (AIN0/INT2/PCINT10)   | 2  | ZDIR              |
| PB3 (AIN1/OC0A/PCINT11)   | 3  | ZSTEP             |
| PB4 (SS/OC0B/PCINT12)     | 4  | FAN, LED          |
| PB5 (PCINT13/MOSI)        | 5  | J1_MOSI, SD_MOSI  |
| PB6 (PCINT14/OC3A/MISO)   | 6  | SD_MISO           |
| PB7 (PCINT15/OC3B/SCK)    | 7  | J1_SCK            |
|---------------------------|----|-------------------|
| PC0 (PCINT16/SCL)         | 16 | J1_SCL            |
| PC1 (PCINT17/SDA)         | 17 | J1_SDA            |
| PC2 (PCINT18/TCK)         | 18 | XMIN (input)      |
| PC3 (PCINT19/TMS)         | 19 | YMIN (input)      |
| PC4 (TDO/PCINT20)         | 20 | ZMIN (input)      |
| PC5 (TDI/PCINT21)         | 21 | XDIR              |
| PC6 (TOSC1/PCINT22)       | 22 | YSTEP             |
| PC7 (TOSC2/PCINT23)       | 23 | YDIR              |
|---------------------------|----|-------------------|
| PD0 (PCINT24/RXD0/T3)     | 8  | SERIAL_RX         |
| PD1 (PCINT25/TXD0)        | 9  | SERIAL_TX         |
| PD2 (PCINT26/RXD1/INT0)   | 10 | J1_RX1            |
| PD3 (PCINT27/TXD1/INT1)   | 11 | J1_TX1            |
| PD4 (PCINT28/XCK1/OC1B)   | 12 | HOTEND (output)   |
| PD5 (PCINT29/OC1A)        | 13 | BEDHEATER (output)|
| PD6 (PCINT30/OC2B/ICP1)   | 14 | XYE_ENABLE        |
| PD7 (PCINT31/OC2A)        | 15 | XSTEP             |




have phun..
W.
