// =========================================================
// File: PutOption.cpp
// Author: Emmy
// Date: 23/10/2024
// Description: Implementation of the PutOption class
// =========================================================

#include "PutOption.h"

// Constructor
PutOption::PutOption(double expiry, double strike)
    : EuropeanVanillaOption(expiry, strike) {}

// Implement the payoff function for Put Option
double PutOption::payoff(double z) const {
    return (z <= getStrike()) ? (getStrike() - z) : 0;
}

// Return the option type (Put)
optionType PutOption::getOptionType() const {
    return optionType::put;
}
