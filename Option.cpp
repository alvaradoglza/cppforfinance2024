// =========================================================
// File: Option.cpp
// Author: Emmy
// Date: 23/10/2024
// Description: Implementation of Option class methods
// =========================================================

#include "Option.h"

// Constructor with expiry validation
Option::Option(double expiry) : _expiry(expiry) {
    if (expiry < 0) {
        throw std::invalid_argument("Expiry must be non-negative.");
    }
}

// Default constructor
Option::Option() : _expiry(0.0) {}

// Getter for expiry
double Option::getExpiry() const {
    return _expiry;
}

// Default implementation of getStrike
double Option::getStrike() const {
    return 0.0; // Default: no specific strike for generic options
}

// Default implementation of payoffPath
double Option::payoffPath(const std::vector<double>& path) const {
    return payoff(path.back()); // Default behavior for non-path-dependent options
}

// Default implementation of isAsianOption
bool Option::isAsianOption() const {
    return false; // Default: not an Asian option
}

// Default implementation of isAmericanOption
bool Option::isAmericanOption() const {
    return false; // Default: not an American option
}
