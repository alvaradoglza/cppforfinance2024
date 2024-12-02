// =========================================================
// File: AsianPutOption.h
// Author: Emmy
// Date: 23/10/2024
// Description: Header file for the AsianPutOption class
// =========================================================

#ifndef ASIANPUTOPTION_H
#define ASIANPUTOPTION_H

#include "AsianOption.h"
#include <algorithm> // For std::max

// AsianPutOption class, derived from AsianOption
class AsianPutOption : public AsianOption {
private:
    double strike; // Strike price for the Asian put option

public:
    // Constructor
    AsianPutOption(const std::vector<double>& timeSteps, double strike);

    // Override payoff function
    double payoff(double St) const override;

    // Override getOptionType function
    optionType getOptionType() const override;
};

#endif // ASIANPUTOPTION_H
