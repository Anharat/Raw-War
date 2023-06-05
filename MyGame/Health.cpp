// Health.cpp

#include "Health.h"  // Include the Health header file

// Constructor implementation
Health::Health(float maxHealth, float currentHealth)
    : maxHealth(maxHealth), currentHealth(currentHealth) {
    // Initialize maxHealth and currentHealth with the provided values
}

void Health::Heal(float amount) {
    // Increase the current health by the specified amount
    currentHealth += amount;

    // Ensure current health does not exceed max health
    if (currentHealth > maxHealth) {
        currentHealth = maxHealth;
    }
}

void Health::TakeDamage(float damage) {
    // Decrease the current health by the specified damage amount
    currentHealth -= damage;

    // Ensure current health does not fall below 0
    if (currentHealth < 0) {
        currentHealth = 0;
    }
}