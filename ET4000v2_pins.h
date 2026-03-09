#pragma once
/******************************************************************************
 * These header contains the pin definitions for the ET-4000 v2.
 * Please check any pin if using it and report errors in this file.
 *
 *     Board: ATmega1284
 *     Clock: External 16 MHz
 *     BOD: BOD 2.7V
 *     EEPROM: EEPROM retained
 *     Compiler LTO: LTO enabled
 *     Variant: 1284P            <- important
 *     pinout: Standard pinout
 *     Bootloader: Yes (UART0)   <- important
 *     Baudrate: 115200          <- must fit your firmware from step 5
 *     JTAG pins: JTAG disabled
 *     Port: COM5                <- change here!
 ******************************************************************************/

// NOTE: X,Y,E enable is shared
#define XYE_ENABLE                      14 // PD6, checked, active low

/* X axis, checked. */
#define XSTEP                           15 // PD7, checked.
#define XDIR                            21 // PC5, checked.

/* Y axis */
#define YSTEP                           22 // PC6, checked.
#define YDIR                            23 // PC7, checked.

/* Z axis */
#define ZSTEP                           3  // PB3, checked.
#define ZDIR                            2  // PB2, checked.
#define ZENABLE                         A5 // PA5, active low

/* Port E, extruder */
#define ESTEP                           1  // PB1, checked.
#define EDIR                            0  // PB0, checked.


/* End switches, in fw as min pos switches.
 * 1. VCC
 * 2. GND
 * 3. contact
 */
#define XMIN                            18 // PC2, checked.
#define YMIN                            19 // PC3, checked.
#define ZMIN                            20 // PC4, checked.


/* The MOSFETs switch to GND (Low-Side Switch):
 *   pinMode(FAN, OUTPUT);
 *   digitalWrite(FAN, HIGH); // turns fan on (and it's LED)
 */
#define BEDHEATER                       13 // PD5, PWM: yes, checked.
#define HOTEND                          12 // PD4, PWM: yes, checked.
#define FAN                             4  // PB4, PWM: yes, checked.
#define LED                             4  // PB4, connected to FAN, checked.

#define TBED                            A6 // PWM PA6: no, checked.
#define THOTEND                         A7 // PWM PA7: no, checked.

/* UART && I2C/Wire:
 *   NOTE: CH340 DTR/RTS is connected to the RESET pin of the uC via 100nF.
 */
#define SERIAL_RX                       8  // PD0, UART0 via USB, checked.
#define SERIAL_TX                       9  // PD1, UART0 via USB, checked.
#define SERIAL1_RX                      10 // PD2, UART1 on J1, checked.
#define SERIAL1_TX                      11 // PD3, UART1 on J1, checked.
#define I2C_SCL                         16 // PC0, I2C on J1, checked.
#define I2C_SDA                         17 // PC1, I2C on J1, checked.

/***** J1: 12-pol LCD pin header ****
 * NOTE: J1 Pin1 is marked as square pad.
 */
//                                          //      J1/12, +5V
//                                          //      J1/11, GND
#define J1_MOSI                         5   // PB5, J1/10, MOSI, checked.
#define J1_SCK                          7   // PB7, J1/9 , SCK , checked.
#define J1_RX1                          10  // PD2, J1/8 , RX1 , checked.
#define J1_A4                           A4  // PA4, J1/7 , A4  , checked.
#define J1_TX1                          11  // PD3, J1/6 , TX1 , checked.
#define J1_A3                           A3  // PA3, J1/5 , A3  , checked.
#define J1_SCL                          16  // PC0, J1/4 , SCL , checked.
#define J1_A2                           A2  // PA0, J1/3 , A2  , checked.
#define J1_SDA                          17  // PC1, J1/2 , SDA , checked.
#define J1_A1                           A1  // PA1, J1/1 , A1  , checked.

/***** SDCARD ****/
                                            //      SD/1, GND
                                            //      SD/2, nc
#define SD_MISO                         6   // PB6, SD/3, MISO, checked.
                                            //      SD/4, GND
#define SD_SCK                          7   //      SD/5, 74HC4050/6 <- 74HC4050/6 <- PB7 SCK
                                            //      SD/6, 3V3
#define SD_MOSI                         5   //      SD/7, 74HC4050/4 <- 74HC4050/5 <- PB5 MOSI
#define SD_ENABLE                       A0  //      SD/8, 74HC4050/2 <- 74HC4050/3 <- PA0 
                                            //      SD/9, nc


