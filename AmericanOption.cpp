// =========================================================
// File: AmericanOption.cpp
// Author: Emmy
// Date: 23/10/2024
// Description: Implementation of the AmericanOption class
// =========================================================

#include "AmericanOption.h"

// Constructor
AmericanOption::AmericanOption(double expiry) : Option(expiry) {}

// Override to indicate this is an American option
bool AmericanOption::isAmericanOption() const {
    return true; // Indicates this is an American option
}
