#pragma once
#include "../overlaycontroller.h"
#include <openvr.h>
#include <iostream>
#include <easylogging++.h>
#include <string>
#include <cmath>
#include <chrono>
namespace TimeLog
{
class TimeLog
{
private:
    double thresholdTime = 5000;
    std::chrono::steady_clock myClock;
    std::chrono::time_point<std::chrono::steady_clock,
                            std::chrono::duration<double>>
        oldTimePoint;

public:
    void checkForDelay( std::string message );
    void setThreshold( double threshold );
    void initClock();
};

} // namespace TimeLog
