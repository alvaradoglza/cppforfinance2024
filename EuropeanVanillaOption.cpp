// =========================================================
// File: EuropeanVanillaOption.cpp
// Author: Emmy
// Date: 23/10/2024
// Description: Implementation of the EuropeanVanillaOption class
// =========================================================

#include "EuropeanVanillaOption.h"
#include <stdexcept>

// Constructor
EuropeanVanillaOption::EuropeanVanillaOption(double expiry, double strike)
    : Option(expiry), _strike(strike) {
    if (strike < 0) {
        throw std::invalid_argument("Strike must be non-negative");
    }
}

// Getter for _strike
double EuropeanVanillaOption::getStrike() const {
    return _strike;
}
