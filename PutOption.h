// =========================================================
// File: PutOption.h
// Author: Emmy
// Date: 23/10/2024
// Description: Header file for the PutOption class
// =========================================================

#ifndef PUTOPTION_H
#define PUTOPTION_H

#include "EuropeanVanillaOption.h"

// PutOption class derived from EuropeanVanillaOption
class PutOption : public EuropeanVanillaOption {
public:
    // Constructor
    PutOption(double expiry, double strike);

    // Implement the payoff function for Put Option
    double payoff(double z) const override;

    // Return the option type (Put)
    optionType getOptionType() const override;
};

#endif // PUTOPTION_H
