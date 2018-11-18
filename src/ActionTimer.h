/***********************************************************************
 * Class:       ActionTimer
 *
 * Author:      Charles McKnight
 *
 * Description:
 *   This class provides a millis()-driven timer that can be used to
 * control object states and actions.
 ***********************************************************************/

#pragma once

#ifndef ACTIONTIMER_H
#define ACTIONTIMER_H

#include <Arduino.h>

class ActionTimer {
  public:
    ActionTimer();
    ~ActionTimer();
    void start(unsigned long duration);
    bool isExpired();
  private:
    bool expirationState;
    unsigned long startTime;
    unsigned long duration;
};

#endif