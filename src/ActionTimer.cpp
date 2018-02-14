/***********************************************************************
 * Class:       ActionTimer
 *
 * Author:      Charles McKnight
 *
 * Description:
 *  This file provides the implemtation for the ActionTimer class.
 ***********************************************************************/

#include "ActionTimer.h"

/***********************************************************************
 * Method:      ActionTimer::ActionTimer
 * 
 * Arguments:   N/A
 * 
 * Returns:     N/A
 *
 * Description:
 *   Constructor
 ***********************************************************************/
ActionTimer::ActionTimer() {
  // set initial expiration state of the ActionTimer object.
  expirationState = false;

  // initialize the end_time to a known value of zero.
  expirationTime = 0UL;
}

/***********************************************************************
 * Method:      ActionTimer::~ActionTimer
 * 
 * Arguments:   N/A
 * 
 * Returns:     N/A
 *
 * Description:
 *   Destructor
 ***********************************************************************/
ActionTimer::~ActionTimer() {
  // Nothing to destroy
}

/***********************************************************************
 * Method:      ActionTimer::start
 * 
 * Arguments:   duration - unsigned long value
 * 
 * Returns:     N/A
 *
 * Description:
 *   This method sets the expiration time for the ActionTimer object and
 * sets the expired state to false.
 ***********************************************************************/
void ActionTimer::start(unsigned long duration) {
  // set the expiration state to false
  expirationState = false;

  // set the expiration time to the current time plus the specified duration
  expirationTime = millis() + duration;
}

/***********************************************************************
 * Method:      isExpired
 * 
 * Arguments:   N/A
 * 
 * Returns:     True if timer has expired; false otherwise
 *
 * Description:
 *   This method reports whether or not the timer has expired.
 ***********************************************************************/
bool ActionTimer::isExpired() {
  // test to see if the timer has expired
  if (millis() > expirationTime) {
    // yes, set the state to true
    expirationState = true;
  }

  // return the value of the expiration state
  return expirationState;
}