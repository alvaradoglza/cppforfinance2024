// =========================================================
// File: AsianCallOption.h
// Author: Emmy
// Date: 23/10/2024
// Description: Header file for the AsianCallOption class
// =========================================================

#ifndef ASIANCALLOPTION_H
#define ASIANCALLOPTION_H

#include "AsianOption.h"
#include <algorithm> // For std::max

// AsianCallOption class, derived from AsianOption
class AsianCallOption : public AsianOption {
private:
    double strike; // Strike price for the Asian call option

public:
    // Constructor
    AsianCallOption(const std::vector<double>& timeSteps, double strike);

    // Override payoff function
    double payoff(double St) const override;

    // Override getOptionType function
    optionType getOptionType() const override;
};

#endif // ASIANCALLOPTION_H
