// =========================================================
// File: EuropeanDigitalOption.h
// Author: Emmy
// Date: 23/10/2024
// Description: Header file for the EuropeanDigitalOption abstract class
// =========================================================

#ifndef EUROPEANDIGITALOPTION_H
#define EUROPEANDIGITALOPTION_H

#include "Option.h"

// Abstract base class for European digital options
class EuropeanDigitalOption : public Option {
protected:
    double _strike; // Strike price for the digital option

public:
    // Constructor
    EuropeanDigitalOption(double expiry, double strike);

    // Getter for _strike
    double getStrike() const;

    // Pure virtual method for payoff calculation
    virtual double payoff(double z) const = 0;

    // Pure virtual method to get option type
    virtual optionType getOptionType() const = 0;

    // Virtual destructor
    virtual ~EuropeanDigitalOption() = default;
};

#endif // EUROPEANDIGITALOPTION_H
