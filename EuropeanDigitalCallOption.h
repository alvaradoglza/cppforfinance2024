// =========================================================
// File: EuropeanDigitalCallOption.h
// Author: Emmy
// Date: 23/10/2024
// Description: Header file for the EuropeanDigitalCallOption class
// =========================================================

#ifndef EUROPEANDIGITALCALLOPTION_H
#define EUROPEANDIGITALCALLOPTION_H

#include "EuropeanDigitalOption.h"

// Concrete class for European Digital Call Option
class EuropeanDigitalCallOption : public EuropeanDigitalOption {
public:
    // Constructor
    EuropeanDigitalCallOption(double expiry, double strike);

    // Override payoff function
    double payoff(double z) const override;

    // Override getOptionType function
    optionType getOptionType() const override;
};

#endif // EUROPEANDIGITALCALLOPTION_H
