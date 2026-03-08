# About
This howto explains the Arduino compatible bootloader upload to the ET-4000 v2.

# What you need
* Arduino IDE, tested 1.8.19
* https://github.com/MCUdude/MightyCore
* a programmer, with cable for the 6-pol ISP header
* AVRDUDESS-2.20
* (AccelStepper-1.64.0 later, for testing the motors)

# Install the CH340 UART driver
Install CH340 COM port driver. Use the original chinese driver and check, if the UART is detected.

# Setup MCUdude/MightyCore in the Arduino IDE
The board features an ATmega1284p, something like a newer ATmega16. We need optiboot or urboot on this chip.
Fortunally, in the hardware package MCUdude/MightyCore, we have exactly this.

In Arduino IDEs preferencies, add an additional board path:
- 'https://mcudude.github.io/MightyCore/package_MCUdude_MightyCore_index.json'

Install the package via the board manager.

# Finding the right firmware
The board uses an CH340, so we should restrict the programming baudrate to 115200 or lower.
The USB UART is connected to UART0, and the µC uses 16MHz external quartz. There's no LED at PB0 or PB7 and we want the PROGMEM feature.
* UART0
* 115200 programming baudrate
* 16MHz external clock
* LED at Pin B0

Locate the file atmega1284p_build_info.txt in

   %AppData%\Local\Arduino15\packages\MightyCore\hardware\avr\3.1.0\bootloaders\optiboot_flash\bootloaders\atmega1284p

and lookup the firmware name. As we don't have an LED, you may choose the B0 or B7 variant, no difference.

# Programming the bootloader
Connect the programmer to USB and the ISP header and start AVRDUDESS-2.20.

I use a cheap usbasp clone (fischl.de).

Select the chip, ATmega1284p, note the 'p' variant.

Select our choosen firmware, from folder

   %AppData%\Local\Arduino15\packages\MightyCore\hardware\avr\3.1.0\bootloaders\optiboot_flash\bootloaders\atmega1284p

choose the file

   'optiboot_flash_atmega1284p_UART0_115200_16000000L_B0_BIGBOOT.hex'

Program this file and power cycle the board.

# Check the board in Arduino IDE:
Select the board as

* Board: ATmega1284
* Clock: External 16 MHz
* BOD: BOD .7V
* EEPROM: EEPROM retained
* Compiler LTO: LTO enabled
* Variant: 1284P            <- important
* pinout: Standard pinout
* Bootloader: Yes (UART0)   <- important
* Baudrate: 115200          <- must fit your firmware
* JTAG pins: JTAG disabled
* Port: COM5                <- change here!

Be shure to power cycle the board after bootloader programming, the CH340 is known to be picky.
Load a program to be board. If that doesn't work, re-check and repeat any previous step.
