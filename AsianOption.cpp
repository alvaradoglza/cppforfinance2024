// =========================================================
// File: AsianOption.cpp
// Author: Emmy
// Date: 23/10/2024
// Description: Implementation of the AsianOption class
// =========================================================

#include "AsianOption.h"

// Constructor
AsianOption::AsianOption(const std::vector<double>& timeSteps) : timeSteps(timeSteps) {}

// Getter for time steps
const std::vector<double>& AsianOption::getTimeSteps() const {
    return timeSteps;
}

// PayoffPath function for path-dependent payoff
double AsianOption::payoffPath(const std::vector<double>& path) const {
    double sum = 0.0;
    for (double St : path) {
        sum += St;
    }
    double average = sum / path.size();
    return payoff(average); // Uses the payoff function for the average price
}

// Function to indicate this is an Asian option
bool AsianOption::isAsianOption() const {
    return true;
}
