// Health.h

#pragma once  // Preprocessor directive to prevent multiple inclusions of the header file

// Health class declaration
class Health {
public:
    float maxHealth;  // Maximum health value
    float currentHealth;  // Current health value

    // Constructor with default parameter values
    // If no values are provided, it defaults to zero health
    Health(float maxHealth = 0.0f, float currentHealth = 0.0f);

    // Method to increase current health
    void Heal(float amount);

    // Method to decrease current health
    void TakeDamage(float damage);

};