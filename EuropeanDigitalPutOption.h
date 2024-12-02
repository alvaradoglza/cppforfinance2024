// =========================================================
// File: EuropeanDigitalPutOption.h
// Author: Emmy
// Date: 23/10/2024
// Description: Header file for the EuropeanDigitalPutOption class
// =========================================================

#ifndef EUROPEANDIGITALPUTOPTION_H
#define EUROPEANDIGITALPUTOPTION_H

#include "EuropeanDigitalOption.h"

// Concrete class for European Digital Put Option
class EuropeanDigitalPutOption : public EuropeanDigitalOption {
public:
    // Constructor
    EuropeanDigitalPutOption(double expiry, double strike);

    // Override payoff function
    double payoff(double z) const override;

    // Override getOptionType function
    optionType getOptionType() const override;
};

#endif // EUROPEANDIGITALPUTOPTION_H
