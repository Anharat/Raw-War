// Health.cpp

#include "Health.h"

Health::Health(float maxHealth, float currentHealth) : maxHealth(maxHealth), currentHealth(currentHealth) {
    // Constructor implementation
}

void Health::SetCurrentHealth(float value) {
    currentHealth = value;
    if (currentHealth < 0) {
        currentHealth = 0;
    }
}