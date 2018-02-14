/***********************************************************************
 * Program:     ActionTimerExample
 *
 * Author:      Senestone
 *
 * Description:
 *   This program demonstrates the use of the ActionTimer object to
 * change the state of a variable. While simplistic, The non-blocking
 * nature of the millis() method at the heart of the ActionTimer allows
 * the program to continue to run as opposed to using the blocking
 * delay() method which would stop all other program activity until the
 * duration of the delay had elapsed. The use of multiple ActionTimers
 * allows each timer to control an action or set of actions.
 ***********************************************************************/

#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <ActionTimer.h>

ActionTimer myTimer;                  // ActionTimer object declaration

bool myState;                         // state variable declaration

const unsigned long duration = 2000;   // duration value set as constant

/***********************************************************************
 * Method:      logMessage
 * 
 * Arguments:   N/A
 * 
 * Returns:     N/A
 *
 * Description:
 *   This method writes a log message containing the current state of
 * the myState global varialble  to the serial monitor.
 ***********************************************************************/
void logMessage() {
  char msg[32];
  sprintf(msg, "The current state is %s", (myState) ? "true" : "false");
  Serial.println(msg);
}


/***********************************************************************
 * Method:      setup
 * 
 * Arguments:   N/A
 * 
 * Returns:     N/A
 *
 * Description:
 *   This method performs all of the initialization activities associated with the program.
 ***********************************************************************/

void setup() {
  // initialize the state variable to true
  myState = true;

  // configure the serial port for 9600 baud (N-8-1)
  Serial.begin(9600);

  // start the timer
  myTimer.start(duration);

  // log the current state
  logMessage();
}

/***********************************************************************
 * Method:      loop
 * 
 * Arguments:   N/A
 * 
 * Returns:     N/A
 *
 * Description:
 *   This method continuously executes after all of the setup operations
 * have been completed.
 ***********************************************************************/

void loop() {

  // test to see if the timer has expired
  if (myTimer.isExpired()) {

    // toggle the state of the variable
    myState = !myState;

    // log the current state
    logMessage();

    // restart the timer
    myTimer.start(duration);
  }
}