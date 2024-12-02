// =========================================================
// File: EuropeanDigitalPutOption.cpp
// Author: Emmy
// Date: 23/10/2024
// Description: Implementation of the EuropeanDigitalPutOption class
// =========================================================

#include "EuropeanDigitalPutOption.h"

// Constructor
EuropeanDigitalPutOption::EuropeanDigitalPutOption(double expiry, double strike)
    : EuropeanDigitalOption(expiry, strike) {}

// Payoff function for European digital put option
double EuropeanDigitalPutOption::payoff(double z) const {
    return (z <= _strike) ? 1.0 : 0.0; // Payoff is 1 if spot <= strike, else 0
}

// Get the option type
optionType EuropeanDigitalPutOption::getOptionType() const {
    return optionType::put; // Return "put" as the option type
}
