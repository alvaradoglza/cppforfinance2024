// =========================================================
// File: AmericanCallOption.cpp
// Author: Emmy
// Date: 23/10/2024
// Description: Implementation of the AmericanCallOption class
// =========================================================

#include "AmericanCallOption.h"

// Constructor
AmericanCallOption::AmericanCallOption(double expiry, double strike)
    : AmericanOption(expiry), strike(strike) {}

// Payoff function
double AmericanCallOption::payoff(double spotPrice) const {
    return std::max(spotPrice - strike, 0.0);
}

// Getter for strike price
double AmericanCallOption::getStrike() const {
    return strike;
}

// Getter for option type
optionType AmericanCallOption::getOptionType() const {
    return optionType::call;
}
