// =========================================================
// File: AsianPutOption.cpp
// Author: Emmy
// Date: 23/10/2024
// Description: Implementation of the AsianPutOption class
// =========================================================

#include "AsianPutOption.h"

// Constructor
AsianPutOption::AsianPutOption(const std::vector<double>& timeSteps, double strike)
    : AsianOption(timeSteps), strike(strike) {}

// Payoff function for Asian put option
double AsianPutOption::payoff(double St) const {
    return std::max(strike - St, 0.0); // Put payoff: max(strike - spot, 0)
}

// Function to get the option type
optionType AsianPutOption::getOptionType() const {
    return optionType::put; // Return put as the option type
}
