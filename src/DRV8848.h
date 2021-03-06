/*
  DRV8848.h - DRV8848 Motor Driver
  Created by Jaap de Dood, January 9 2020. 
  Based on "TB6612FNG.h" by Gary Hill
*/
#ifndef DRV8848_h      // The #define Guard
#define DRV8848_h

#include "Arduino.h"     // Arduino library files
#include "Configure.h"
#include <Motor.h>

/*
 *  header .h class member definitions
 */

class DRV8848
{
public:
    // Constructor
    DRV8848();

    // Public class 'methods'
    void begin();
    void motors_go(uint8_t*);
    void motors_stop();
    void motors_safe();

private:
    // Private class 'methods'

    // Private class 'properties'

    // Instantiate Motor Classes
    Motor motorA;
    Motor motorB;

}; // end of class definition

#endif

/* DRV8848 Truth Table:
    xIN1    xIN2    xOUT1   xOUT2   Function
    0       0       Z       Z       Coast (fast decay)
    0       1       L       H       Reverse
    1       0       H       L       Forward
    1       1       L       L       Brake (slow decay)

    Note: Pins AIN1 and AIN2 are tri-level, so when they are left Hi-Z, they are not internally pulled to logic low.
    When AIN1 or AIN2 are set to Hi-z and not in parallel mode, the output driver maintains the previous state.
*/

