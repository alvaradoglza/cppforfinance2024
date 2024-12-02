// =========================================================
// File: AmericanPutOption.h
// Author: Emmy
// Date: 23/10/2024
// Description: Header file for the AmericanPutOption class
// =========================================================

#ifndef AMERICANPUTOPTION_H
#define AMERICANPUTOPTION_H

#include "AmericanOption.h"
#include <algorithm> // For std::max

// AmericanPutOption class, derived from AmericanOption
class AmericanPutOption : public AmericanOption {
private:
    double strike;

public:
    // Constructor
    AmericanPutOption(double expiry, double strike);

    // Override payoff function
    double payoff(double spotPrice) const override;

    // Override getStrike function
    double getStrike() const override;

    // Override getOptionType function
    optionType getOptionType() const override;
};

#endif // AMERICANPUTOPTION_H
