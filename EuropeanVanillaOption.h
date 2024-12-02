// =========================================================
// File: EuropeanVanillaOption.h
// Author: Emmy
// Date: 23/10/2024
// Description: Header file for the EuropeanVanillaOption class
// =========================================================

#ifndef EUROPEANVANILLAOPTION_H
#define EUROPEANVANILLAOPTION_H

#include "Option.h"
#include <stdexcept>

// Abstract base class for European Vanilla Options
class EuropeanVanillaOption : public Option {
private:
    double _strike; // Strike price of the option

public:
    // Constructor
    EuropeanVanillaOption(double expiry, double strike);

    // Getter for _strike
    double getStrike() const;

    // Pure virtual method for option type (to be implemented by derived classes)
    virtual optionType getOptionType() const = 0;

    // Virtual destructor
    virtual ~EuropeanVanillaOption() = default;
};

#endif // EUROPEANVANILLAOPTION_H
