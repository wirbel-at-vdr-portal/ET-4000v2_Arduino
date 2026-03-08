# ET-4000v2_Arduino
Re-use an 3D printer mainboard as Arduino IDE compatible dev board

# ET-4000 v2 features
This board has a lot of interesting features, once usable. As not schematics is known, any connection needs to be found.
* ATmega1284p, 128k flash, 16MHz clock
* USB connector, connected to UART0
* 4 stepper motor drivers
* 3 end switch inputs
* 1 fan connector output with PWM
* 2 strong heater outputs
* 1 12-pol display connector with UART1, SPI, I2C and four analog/digital inputs
* 1 mini sdcard slot
* 1 6-pol ISP programming header

# Getting the board programmable in the Arduino IDE
To access the board in the Arduino IDE, a new bootloader needs to be programmed to the board.
A tiny programmer is needed:
* usbasp or clone
* another Arduino-compat board
* ..
A small howto is given in [bootloader.md](bootloader.md).

# Using the board in a project.
To include this board in your project, include the file ET4000v2_pins.h.
Also, enshure that the MCUdude/MightyCore hardware package is installed and you choose the correct board settings.

Not all pins are known yet, if you find some not given here, do a pull request.


have phun..
