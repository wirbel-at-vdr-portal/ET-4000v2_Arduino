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

/* X axis, checked. */
#define XSTEP   /* PD7 */ 15 /* checked.   */
#define XDIR    /* PC5 */ 21 /* checked.   */
#define XENABLE /* PD6 */ 14 /* checked, active low */

/* Y axis */
// #define YSTEP   /* PC4 */ 20 /* WRONG - collides with end switches             */
// #define YDIR    /* PC3 */ 19 /* WRONG - collides with end switches             */
// #define YENABLE /* PC2 */ 18 /* WRONG - collides with end switches, active low */

/* Z axis */
// #define ZSTEP   /* PC1 */ 17 /* collides with J1_SCL             */
// #define ZDIR    /* PC0 */ 16 /* collides with J1_SDA             */
// #define ZENABLE /* PD2 */ 10 /* collides with J1_RX1, active low */

/* Port E, extruder */
// #define ESTEP   /* PD5 */ 13 /* WRONG, this is BEDHEATER */
// #define EDIR    /* PD4 */ 12 /* WRONG, this is HOTEND */
// #define EENABLE /* PD3 */ 11 /* collides with J1_TX1, active low */

/* End switches, in fw as min pos switches.
 * 1. VCC
 * 2. GND
 * 3. contact
 */
#define XMIN    /* PC2 */ 18 /* checked. */
#define YMIN    /* PC3 */ 19 /* checked. */
#define ZMIN    /* PC4 */ 20 /* checked. */


/* The MOSFETs switch to GND (Low-Side Switch):
 *   pinMode(FAN, OUTPUT);
 *   digitalWrite(FAN, HIGH); // turns fan on (and it's LED)
 */
#define BEDHEATER /* PD5 */ 13 /* PWM: yes, checked. */
#define HOTEND    /* PD4 */ 12 /* PWM: yes, checked. */
#define FAN       /* PB4 */  4 /* PWM: yes, checked. */
#define LED       /* PB4 */  4 /* connected to FAN, checked. */

#define TBED      /* PA6 */ A6 /* PWM: no, checked. */
#define THOTEND   /* PA7 */ A7 /* PWM: no, checked. */

/* UART && I2C/Wire:
 *   NOTE: CH340 DTR/RTS is connected to the RESET pin of
 *         the ATmega1284 via 100nF-cap.
 */
#define SERIAL_RX  /* PD0 */ 8  /* via USB, checked. */
#define SERIAL_TX  /* PD1 */ 9  /* via USB, checked. */
#define SERIAL1_RX /* PD2 */ 10 /* on J1, checked.   */
#define SERIAL1_TX /* PD3 */ 11 /* on J1, checked.   */
#define I2C_SCL    /* PC0 */ 16 /* checked.          */
#define I2C_SDA    /* PC1 */ 17 /* checked.          */




/***** J1: 12-pol LCD pin header ****
 * NOTE: J1 Pin1 is marked as square pad.
 *                     12 VCC (+5V)*
 *                     11 GND      */
#define J1_MOSI 5   /* 10 MOSI PB5, checked. */
#define J1_SCK  7   /*  9 SCK  PB7, checked. */
#define J1_RX1  10  /*  8 RX1  PD2, checked. */
#define J1_A4   A4  /*  7 A4   PA4, checked. */
#define J1_TX1  11  /*  6 TX1  PD3, checked. */
#define J1_A3   A3  /*  5 A3   PA3, checked. */
#define J1_SCL  16  /*  4 SCL  PC0, checked. */
#define J1_A2   A2  /*  3 A2   PA0, checked. */
#define J1_SDA  17  /*  2 SDA  PC1, checked. */
#define J1_A1   A1  /*  1 A1   PA1, checked. */

