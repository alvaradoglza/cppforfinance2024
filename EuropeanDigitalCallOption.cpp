// =========================================================
// File: EuropeanDigitalCallOption.cpp
// Author: Emmy
// Date: 23/10/2024
// Description: Implementation of the EuropeanDigitalCallOption class
// =========================================================

#include "EuropeanDigitalCallOption.h"

// Constructor
EuropeanDigitalCallOption::EuropeanDigitalCallOption(double expiry, double strike)
    : EuropeanDigitalOption(expiry, strike) {}

// Payoff function for European digital call option
double EuropeanDigitalCallOption::payoff(double z) const {
    return (z >= _strike) ? 1.0 : 0.0; // Payoff is 1 if spot >= strike, else 0
}

// Get the option type
optionType EuropeanDigitalCallOption::getOptionType() const {
    return optionType::call; // Return "call" as the option type
}
