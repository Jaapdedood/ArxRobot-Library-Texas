/*
  DRV8848.cpp - DRV8848 Motor Driver
  Created by Jaap de Dood, January 9 2020. 
  Based on "TB6612FNG.cpp" by Gary Hill
*/

#include "Arduino.h"
#include "Configure.h"
#include "Motor.h"
#include "DRV8848.h"

/*
 *  C++ .cpp member class definitions
 */

// Constructor

DRV8848::DRV8848()
{
}

void DRV8848::begin()
{
    pinMode(NSLEEP,OUTPUT);
    this->motorA.begin(AIN1, AIN2);
    this->motorB.begin(BIN1, BIN2);
    motors_stop();                     // motors off
    digitalWrite(NSLEEP, HIGH);        // DRV8848 enabled
}

void DRV8848::motors_go(uint8_t* motordata)
{
    motorA.go(motordata[3],motordata[4]);  // configure H-bridge & speed for motor A (left)
    motorB.go(motordata[5],motordata[6]);  // configure H-bridge for motor B (right)
}

void DRV8848::motors_stop()        // initialize or stop DRV8848
{
    motorA.brake();
    motorB.brake();
}

void DRV8848::motors_safe()        // initialize or stop DRV8848
{
    motors_stop();                     // motors off
    digitalWrite(NSLEEP, LOW);           // DRV8848 enabled
}
