// Timer.h

#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
public:
    Timer();

    void Reset();
    double GetElapsedTime() const;

private:
    std::chrono::high_resolution_clock::time_point startTime;
};

#endif // TIMER_H
