// =========================================================
// File: AmericanCallOption.h
// Author: Emmy
// Date: 23/10/2024
// Description: Header file for the AmericanCallOption class
// =========================================================

#ifndef AMERICANCALLOPTION_H
#define AMERICANCALLOPTION_H

#include "AmericanOption.h"
#include <algorithm> // For std::max

// AmericanCallOption class, derived from AmericanOption
class AmericanCallOption : public AmericanOption {
private:
    double strike;

public:
    // Constructor
    AmericanCallOption(double expiry, double strike);

    // Override payoff function
    double payoff(double spotPrice) const override;

    // Override getStrike function
    double getStrike() const override;

    // Override getOptionType function
    optionType getOptionType() const override;
};

#endif // AMERICANCALLOPTION_H
