// =========================================================
// File: CallOption.h
// Author: 
// Date: 23/10/2024
// Description: Header file for CallOption class
// =========================================================
#ifndef CALLOPTION_H
#define CALLOPTION_H

#include "europeanVanillaOption.h" // Include the base class

class CallOption : public EuropeanVanillaOption {
public:

    // Constructor
    CallOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {}

    // Implement the payoff function for Call Option
    double payoff(double z) const override {
        return (z >= getStrike()) ? (z - getStrike()) : 0;
    }

    // Return the option type (Call)
    optionType GetOptionType() const override {
        return optionType::call;
    }
};

#endif
