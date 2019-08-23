#include "TimeLog.h"
namespace TimeLog
{
void TimeLog::checkForDelay( std::string message )
{
    auto currentTimePoint = myClock.now();

    std::chrono::duration<double> hangTime
        = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(
            currentTimePoint - oldTimePoint );
    oldTimePoint = currentTimePoint;
    if ( hangTime.count() > thresholdTime )
    {
        LOG( ERROR ) << "Program Hung for: " << hangTime.count()
                     << "ms  before: " << message;
    }
}

void TimeLog::setThreshold( double threshold )
{
    thresholdTime = threshold;
}

void TimeLog::initClock()
{
    oldTimePoint = myClock.now();
}

} // namespace TimeLog
