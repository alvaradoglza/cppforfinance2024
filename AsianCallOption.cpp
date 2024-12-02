// =========================================================
// File: AsianCallOption.cpp
// Author: Emmy
// Date: 23/10/2024
// Description: Implementation of the AsianCallOption class
// =========================================================

#include "AsianCallOption.h"

// Constructor
AsianCallOption::AsianCallOption(const std::vector<double>& timeSteps, double strike)
    : AsianOption(timeSteps), strike(strike) {}

// Payoff function for Asian call option
double AsianCallOption::payoff(double St) const {
    return std::max(St - strike, 0.0); // Call payoff: max(spot - strike, 0)
}

// Function to get the option type
optionType AsianCallOption::getOptionType() const {
    return optionType::call;
}
