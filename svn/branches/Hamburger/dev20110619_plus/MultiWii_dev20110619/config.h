/*******************************/
/****CONFIGURABLE PARAMETERS****/
/*******************************/

/* Set the minimum throttle command sent to the ESC (Electronic Speed Controller)
   This is the minimum value that allow motors to run at a idle speed  */
//#define MINTHROTTLE 1300 // for Turnigy Plush ESCs 10A
#define MINTHROTTLE 1120 // for Super Simple ESCs 10A
//#define MINTHROTTLE 1220

/* The type of multicopter */
//#define GIMBAL
//#define BI
#define TRI
//#define QUADP
//#define QUADX
//#define Y4
//#define Y6
//#define HEX6
//#define HEX6X
//#define OCTOX8 //beta
//#define OCTOFLATP //beta
//#define OCTOFLATX //beta
//#define FLYING_WING //experimental

#define YAW_DIRECTION 1 // if you want to reverse the yaw correction direction
//#define YAW_DIRECTION -1

#define I2C_SPEED 100000L     //100kHz normal mode, this value must be used for a genuine WMP
//#define I2C_SPEED 400000L   //400kHz fast mode, it works only with some WMP clones

#define PROMINI  //Arduino type
//#define MEGA

//enable internal I2C pull ups
#define INTERNAL_I2C_PULLUPS

//****** advanced users settings   *************

/* Failsave settings - added by MIS
   Failsafe check pulse on THROTTLE channel. If the pulse is OFF (on only THROTTLE or on all channels) the failsafe procedure is initiated.
   After FAILSAVE_DELAY time of pulse absence, the level mode is on (if ACC or nunchuk is avaliable), PITCH, ROLL and YAW is centered
   and THROTTLE is set to FAILSAVE_THR0TTLE value. You must set this value to descending about 1m/s or so for best results. 
   This value is depended from your configuration, AUW and some other params. 
   Next, afrer FAILSAVE_OFF_DELAY the copter is disarmed, and motors is stopped.
   If RC pulse coming back before reached FAILSAVE_OFF_DELAY time, after the small quard time the RC control is returned to normal.
   If you use serial sum PPM, the sum converter must completly turn off the PPM SUM pusles for this FailSafe functionality.*/
#define FAILSAFE                                  // Alex: comment this line if you want to deactivate the failsafe function
#define FAILSAVE_DELAY     10                     // Guard time for failsafe activation after signal lost. 1 step = 0.1sec - 1sec in example
#define FAILSAVE_OFF_DELAY 200                    // Time for Landing before motors stop in 0.1sec. 1 step = 0.1sec - 20sec in example
#define FAILSAVE_THR0TTLE  (MINTHROTTLE + 200)    // Throttle level used for landing - may be relative to MINTHROTTLE - as in this case


/* The following lines apply only for a pitch/roll tilt stabilization system
   On promini board, it is not compatible with config with 6 motors or more
   Uncomment the first line to activate it */
//#define SERVO_TILT
#define TILT_PITCH_MIN    1020    //servo travel min, don't set it below 1020
#define TILT_PITCH_MAX    2000    //servo travel max, max value=2000
#define TILT_PITCH_MIDDLE 1500    //servo neutral value
#define TILT_PITCH_PROP   10      //servo proportional (tied to angle) ; can be negative to invert movement
#define TILT_ROLL_MIN     1020
#define TILT_ROLL_MAX     2000
#define TILT_ROLL_MIDDLE  1500
#define TILT_ROLL_PROP    10

//if you use a specific sensor board:
//please submit any correction to this list.
//   Note from Alex: I only have FFIMUv1 and FFIMUv2 boards
//                   for other boards, I'm not sure, the info was gathered via rc forums, be cautious

//#define FFIMUv1   //first 9DOF+baro board from Jussi, with HMC5843
//#define FFIMUv2   //second version of 9DOF+baro board from Jussi, with HMC5883
//#define FREEIMUv01   //first version of 9DOF board from Fabio
//#define FREEIMU   //later version of 9DOF board from Fabio
//#define PIPO      //6DOF board from erazz
//#define QUADRINO  //full FC board 9DOF+baro board from witespy
//#define ALLINONE  //full FC board or standalone 9DOF+baro board from CSG_EU

//if you use independent sensors
//leave it commented it you already checked a specific board above
/* I2C gyroscope */
//#define ITG3200
//#define L3G4200D

/* I2C accelerometer */
//#define ADXL345
//#define BMA020
//#define BMA180
//#define NUNCHACK  // if you want to use the nunckuk as a standalone I2C ACC without WMP

/* I2C barometer */
//#define BMP085

/* I2C magnetometer */
//#define HMC5843
//#define HMC5883

/* ADC accelerometer */ // for 5DOF from sparkfun, uses analog PIN A1/A2/A3
//#define ADCACC

//if you want to change to orientation of individual sensor
//#define ACC_ORIENTATION(X, Y, Z)  {accADC[ROLL]  =  Y; accADC[PITCH]  = -X; accADC[YAW]  = Z;}
//#define GYRO_ORIENTATION(X, Y, Z) {gyroADC[ROLL] = -Y; gyroADC[PITCH] =  X; gyroADC[YAW] = Z;}
//#define MAG_ORIENTATION(X, Y, Z)  {magADC[ROLL]  = X; magADC[PITCH]  = Y; magADC[YAW]  = Z;}

/* The following lines apply only for specific receiver with only one PPM sum signal, on digital PIN 2
   IF YOUR RECEIVER IS NOT CONCERNED, DON'T UNCOMMENT ANYTHING. Note this is mandatory for a Y6 setup on a promini
   Select the right line depending on your radio brand. Feel free to modify the order in your PPM order is different */
//#define SERIAL_SUM_PPM         PITCH,YAW,THROTTLE,ROLL,AUX1,AUX2,CAMPITCH,CAMROLL //For Graupner/Spektrum
//#define SERIAL_SUM_PPM         ROLL,PITCH,THROTTLE,YAW,AUX1,AUX2,CAMPITCH,CAMROLL //For Robe/Hitec/Futaba
//#define SERIAL_SUM_PPM         PITCH,ROLL,THROTTLE,YAW,AUX1,AUX2,CAMPITCH,CAMROLL //For some Hitec/Sanwa/Others

/* The following lines apply only for Spektrum Satellite Receiver on MEGA boards only */
//#define SPEKTRUM

/* interleaving delay in micro seconds between 2 readings WMP/NK in a WMP+NK config
   if the ACC calibration time is very long (20 or 30s), try to increase this delay up to 4000
   it is relevent only for a conf with NK */
#define INTERLEAVING_DELAY 3000

/* for V BAT monitoring
   after the resistor divisor we should get [0V;5V]->[0;1023] on analog V_BATPIN
   with R1=33k and R2=51k
   vbat = [0;1023]*16/VBATSCALE */
#define VBAT              // comment this line to suppress the vbat code
#define VBATSCALE     131 // change this value if readed Battery voltage is different than real voltage
#define VBATLEVEL1_3S 107 // 10,7V
#define VBATLEVEL2_3S 103 // 10,3V
#define VBATLEVEL3_3S 99  // 9.9V

/* when there is an error on I2C bus, we neutralize the values during a short time. expressed in microseconds
   it is relevent only for a conf with at least a WMP */
#define NEUTRALIZE_DELAY 100000

/* this is the value for the ESCs when they are not armed
   in some cases, this value must be lowered down to 900 for some specific ESCs */
#define MINCOMMAND 1000

/* this is the maximum value for the ESCs at full power
   this value can be increased up to 2000 */
#define MAXTHROTTLE 1850

/* This is the speed of the serial interface. 115200 kbit/s is the best option for a USB connection.*/
#define SERIAL_COM_SPEED 115200

/* In order to save space, it's possibile to desactivate the LCD configuration functions
   comment this line only if you don't plan to used a LCD */
#define LCD_CONF

/* to use Cat's whisker TEXTSTAR LCD, uncomment following line.
   Pleae note this display needs a full 4 wire connection to (+5V, Gnd, RXD, TXD )
   Configure display as follows: 115K baud, and TTL levels for RXD and TXD, terminal mode
   NO rx / tx line reconfiguration, use natural pins */
//#define LCD_TEXTSTAR
/* keys to navigate the LCD menu (preset to TEXTSTAR key-depress codes)*/
#define LCD_MENU_PREV 'a'
#define LCD_MENU_NEXT 'c'
#define LCD_VALUE_UP 'd'
#define LCD_VALUE_DOWN 'b'

/* motors will not spin when the throttle command is in low position
   this is an alternative method to stop immediately the motors */
//#define MOTOR_STOP

/* some radios have not a neutral point centered on 1500. can be changed here */
#define MIDRC 1500

/* experimental
   camera trigger function : activated via Rc Options in the GUI, servo output=A2 on promini */
//#define CAMTRIG
#define CAM_SERVO_HIGH 2000  // the position of HIGH state servo
#define CAM_SERVO_LOW 1020   // the position of LOW state servo
#define CAM_TIME_HIGH 1000   // the duration of HIGH state servo expressed in ms
#define CAM_TIME_LOW 1000    // the duration of LOW state servo expressed in ms

/* you can change the tricopter servo travel here */
#define TRI_YAW_CONSTRAINT_MIN 1020
#define TRI_YAW_CONSTRAINT_MAX 2000
#define TRI_YAW_MIDDLE 1500

/* enable monitoring of the power consumption from battery (think of mAh) */
/* allows to set alarm value in GUI or via LCD */
/* Current first implementation method is pure software. */
/* soft: - (good results +-5% for plush and mystery ESCs @ 2S and 3S, not good with SuperSimple ESC */
/*      00. relies on your combo of battery type (Voltage, cpacity), ESC, ESC settings, motors, props and multiwii cycle time */
/*      01. set POWERMETER soft. Uses PLEVELSCALE = 50, PLEVELDIV = PLEVELDIVSOFT = 10000 */
/*      0. output is a value that linearily scales to power (mAh) */
/*      1. get voltage reading right first */
/*      2. start with freshly charged battery */
/*      3. go fly your typical flight (routine and duration) */
/*      4. at end connect to GUI or LCD and read the power value; write it down (example 4711)*/
/*      5. charge battery, write down amount of energy needed (example 722 mAh) */
/*      6. compute alarm value for desired power threshold (example 750 mAh : alarm = 4711 / 722 * 750) */
/*      7. set alarm value in GUI or LCD */
/*      8. enjoy your new battery alarm - possibly repeat steps 2 .. 7 */
/*      9. if you want the numbers to represent your mAh value, you must change PLEVELDIV */
/* hard: - (uses hardware sensor, after configuration gives reasonable results */
/*      00. uses analog pin 2 to read voltage output from sensor. */
/*      01. set POWERMETER hard. Uses PLEVELSCALE = 50 */
/*      1. compute PLEVELDIV for your sensor (see below for insturctions) */
/*      2. set PLEVELDIVSOFT to 10000 ( to use LOG_VALUES for individual motor comparison) */
/*      3. attach, set PSENSORNULL and  PINT2mA */
/*      4. configure, compile, upload, set alarm value in GUI or LCD */
/*      3. enjoy true readings of mAh consumed */
/* set POWERMETER to "soft" or "hard" depending on sensor you want to utilize */
//#define POWERMETER soft
/* the sum of all powermeters ranges from [0:60000 e4] theoretically. */
/* the alarm level from eeprom is out of [0:255], so we multipy alarm level with PLEVELSCALE and with 1e4 before comparing */
/* PLEVELSCALE is the step size you can use to set alarm */
#define PLEVELSCALE 50 // if you change this value for other granularity, you must search for comments in code to change accordingly 
/* larger PLEVELDIV will get you smaller value for power (mAh equivalent) */
#define PLEVELDIV 10000 // default for soft - if you lower PLEVELDIV, beware of overrun in uint32 pMeter
#define PLEVELDIVSOFT PLEVELDIV // for soft always equal to PLEVELDIV; for hard set to 10000
#define PHARDINTDIV 64 //  doNotChange - must divide the sum of analogRead()*cycleTime over cycles to keep small enough for uint32
//#define PLEVELDIV 271837L // to convert the sum into mAh divide by this value
/* amploc 25A sensor has 37mV/A */
/* arduino analog resolution is 4.9mV per unit; units from [0..1023] */
/* PLEVELDIV = 37 / 4.9  * 10e6 / PHARDINTDIV  * 3600 / 1000  = 424745L */
/* set to analogRead() value for zero current */
#define PSENSORNULL 510 // for I=0A my sensor gives 1/2 Vss; that is approx 2.49Volt
#define PINT2mA 132 // one integer step on arduino analog translates to mA (example 4.9 / 37 * 1000

/* to monitor system values (battery level, loop time etc. with LCD enable this */
/* note: for now you must send single characters 'A', 'B', 'C', 'D' to request 4 different pages */
/* New: the info page on the LCD does get updated automatically - for stop press same button again */
/* easy to use with Textstar LCD - the 4 buttons are preconfigured to send 'A', 'B', 'C', 'D' */
//#define LCD_TELEMETRY
// update interval for telemtry data - every n cycles
#define TELEMETRY_CYCLES 10
/* to enable automatic hopping between 4 telemetry pages uncomment this. */
/* This may be useful if your LCD has no buttons or the sending is broken */
/* hopping is activated and deactivated in unarmed mode with throttle=low & roll=left & pitch=forward */
/* The value represents the hopping interval in cpu time (micro seconds) */
//#define LCD_TELEMETRY_AUTO 2000000
/* on telemetry page B it gives a bar graph which shows how much voltage battery has left. Range from 0 to 12 Volt is not very informative */
/* so we try do define a meaningful part. For a 3S battery we define full=12,6V and calculate how much it is above first warning level */
/* Example: 12.6V - VBATLEVEL1_3S  (for me = 126 - 102 = 24) */
#define VBATREF 24 

/* to log values like max loop time and others to come, we need extra variables */
/* if you do not want the additional computing time or are short on memory, then comment the following */
//#define LOG_VALUES
 
//****** end of advanced users settings *************

/**************************************/
/****END OF CONFIGURABLE PARAMETERS****/
/**************************************/
