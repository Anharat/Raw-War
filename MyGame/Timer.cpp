// Timer.cpp

#include "Timer.h"

Timer::Timer() {
    Reset();
}

void Timer::Reset() {
    startTime = std::chrono::high_resolution_clock::now();
}

double Timer::GetElapsedTime() const {
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedTime = endTime - startTime;
    return elapsedTime.count();
}
