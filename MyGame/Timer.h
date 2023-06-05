// Timer.h

#ifndef TIMER_H
#define TIMER_H

#include <chrono> // Include C++ Standard Library's chrono library for time-related functions

// The Timer class provides functionality to measure elapsed time
class Timer {
public:
    // Constructor for the Timer class. When a Timer object is created, the timer is automatically reset
    Timer();

    // Reset the timer by setting the start time to the current time
    void Reset();

    // Get the time elapsed since the timer was last reset
    // Return value is in seconds and it is a floating point number, for higher precision
    double GetElapsedTime() const;

private:
    // Store the start time. This is the time when the timer was last reset.
    // It is a point in time from the system's high resolution clock
    std::chrono::high_resolution_clock::time_point startTime;
};

#endif // TIMER_H
