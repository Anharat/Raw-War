/**
 * @file Timer.cpp
 * @brief Implementation file for the Timer class.
 *
 * The Timer class provides functionalities for measuring time intervals with high precision.
 * This is particularly useful for game loops, animations, and any other time-sensitive operations.
 */

#include "Timer.h"  /**< Include the Timer class header. */

 /**
  * @brief Default constructor for the Timer class.
  *
  * Initializes the Timer object and sets its start time to the current time.
  */
Timer::Timer() {
    Reset(); // Set the start time to the current time
}
/**
 * @brief Resets the start time of the Timer object.
 *
 * This method updates the start time of the Timer object to the current time, effectively
 * resetting the timer. It can be used to restart the timer without creating a new object.
 */

void Timer::Reset() {
    startTime = std::chrono::high_resolution_clock::now();
}

/**
 * @brief Calculates and returns the elapsed time since the Timer object was last reset or created.
 *
 * This method calculates the duration between the current time and the start time
 * (which is either the time when the Timer object was created or the last time it was reset).
 *
 * @return The elapsed time in seconds as a double.
 */

double Timer::GetElapsedTime() const {
    auto endTime = std::chrono::high_resolution_clock::now(); // Get the current time
    std::chrono::duration<double> elapsedTime = endTime - startTime; // Calculate the duration since the start time
    return elapsedTime.count(); // Return the duration in seconds
}
