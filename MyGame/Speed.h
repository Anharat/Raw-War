// Speed.h

#pragma once

class Speed {
private:
    float value;
public:
    Speed(float value = 0.0f) : value(value) {}
    operator float() const { return value; }  // Overload cast to float
};