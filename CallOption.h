// =========================================================
// File: CallOption.h
// Author: Emmy
// Date: 23/10/2024
// Description: Header file for CallOption class
// =========================================================

#ifndef CALLOPTION_H
#define CALLOPTION_H

#include "EuropeanVanillaOption.h"

// CallOption class derived from EuropeanVanillaOption
class CallOption : public EuropeanVanillaOption {
public:
    // Constructor
    CallOption(double expiry, double strike);

    // Implement the payoff function for Call Option
    double payoff(double z) const override;

    // Return the option type (Call)
    optionType getOptionType() const override;
};

#endif // CALLOPTION_H
