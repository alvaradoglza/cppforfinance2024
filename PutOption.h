// =========================================================
// File: putOption.h
// Author: 
// Date: 23/10/2024
// Description: Header file for PutOption class
// =========================================================
#ifndef PUTOPTION_H
#define PUTOPTION_H

#include "EuropeanVanillaOption.h" // Include the base class

class PutOption : public EuropeanVanillaOption {
public:

    // Constructor
    PutOption(double expiry, double strike) : EuropeanVanillaOption(expiry, strike) {}

    // Implement the payoff function for Put Option
    double payoff(double z) const override {
        return (z <= getStrike()) ? (getStrike() - z) : 0;
    }

    // Return the option type (Put)
    optionType getOptionType() const override {
        return optionType::put;
    }
};

#endif
