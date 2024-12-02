// =========================================================
// File: AmericanPutOption.cpp
// Author: Emmy
// Date: 23/10/2024
// Description: Implementation of the AmericanPutOption class
// =========================================================

#include "AmericanPutOption.h"

// Constructor
AmericanPutOption::AmericanPutOption(double expiry, double strike)
    : AmericanOption(expiry), strike(strike) {}

// Payoff function
double AmericanPutOption::payoff(double spotPrice) const {
    return std::max(strike - spotPrice, 0.0);
}

// Getter for strike price
double AmericanPutOption::getStrike() const {
    return strike;
}

// Getter for option type
optionType AmericanPutOption::getOptionType() const {
    return optionType::put;
}
