/**
 * @file Timer.h
 * @brief Header file for the Timer class.
 *
 * The Timer class provides utilities for measuring time intervals with high precision.
 * This is especially useful in contexts like game loops, animations, and other time-sensitive operations.
 */

#ifndef TIMER_H  // Preprocessor directive to prevent multiple inclusions of the header file
#define TIMER_H

 // Include necessary header files
#include <chrono>  /**< Include the C++ Standard Library's chrono library for high-resolution time-related functionalities. */

/**
 * @class Timer
 * @brief Timer class to measure elapsed time intervals with high precision.
 */
class Timer {
public:
    /**
     * @brief Default constructor for the Timer class.
     *
     * Initializes the Timer object by setting its start time to the current time.
     */
    Timer();

    /**
     * @brief Resets the timer's start time.
     *
     * This method updates the start time of the Timer object to the current time, effectively
     * resetting the elapsed time.
     */
    void Reset();

    /**
     * @brief Calculates the elapsed time since the Timer was last reset or instantiated.
     *
     * This method computes the duration between the current time and the start time
     * (which is either the time when the Timer object was created or the last time it was reset).
     *
     * @return Elapsed time in seconds as a double.
     */
    double GetElapsedTime() const;

private:
    std::chrono::high_resolution_clock::time_point startTime;  /**< Start time for the timer, stored as a high-resolution time point. */
};

#endif  // TIMER_H
