// =========================================================
// File: EuropeanDigitalOption.cpp
// Author: Emmy
// Date: 23/10/2024
// Description: Implementation of the EuropeanDigitalOption class
// =========================================================

#include "EuropeanDigitalOption.h"

// Constructor
EuropeanDigitalOption::EuropeanDigitalOption(double expiry, double strike)
    : Option(expiry), _strike(strike) {}

// Getter for _strike
double EuropeanDigitalOption::getStrike() const {
    return _strike;
}
