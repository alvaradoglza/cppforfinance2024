// =========================================================
// File: CallOption.cpp
// Author: Emmy
// Date: 23/10/2024
// Description: Implementation of CallOption class
// =========================================================

#include "CallOption.h"

// Constructor
CallOption::CallOption(double expiry, double strike)
    : EuropeanVanillaOption(expiry, strike) {}

// Implement the payoff function for Call Option
double CallOption::payoff(double z) const {
    return (z >= getStrike()) ? (z - getStrike()) : 0;
}

// Return the option type (Call)
optionType CallOption::getOptionType() const {
    return optionType::call;
}
