/** 
* @file Timer.cpp
* @brief Implements the Timer class for the Raw-War game.
* * The Timer class provides the functionalities to measure elapsed time.
* * 
* * This source file provides the actual implementation of the Timer class declared in Timer.h.
* */

#include "Timer.h"

// The Timer class provides the functionalities to measure elapsed time
// The Timer class uses the high-resolution clock from the chrono library

// The Timer constructor resets the timer when a Timer object is created
Timer::Timer() {
    Reset();
}

// The Reset function sets the start time to the current time, effectively resetting the timer
void Timer::Reset() {
    startTime = std::chrono::high_resolution_clock::now();
}

// The GetElapsedTime function calculates and returns the time elapsed since the timer was last reset
// It gets the current time, calculates the duration since the start time, and then returns this duration in seconds
double Timer::GetElapsedTime() const {
    auto endTime = std::chrono::high_resolution_clock::now(); // Get the current time
    std::chrono::duration<double> elapsedTime = endTime - startTime; // Calculate the duration since the start time
    return elapsedTime.count(); // Return the duration in seconds
}
