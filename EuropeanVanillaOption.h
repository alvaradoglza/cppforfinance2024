// =========================================================
// File: europeanVanillaOption.h
// Author: [Your Name]
// Date: [Current Date]
// Description: Header file for EuropeanVanillaOption class
// =========================================================
#ifndef EUROPEANVANILLAOPTION_H
#define EUROPEANVANILLAOPTION_H

#include "option.h" // Include the base Option class

typedef enum{call, put} optionType;

class EuropeanVanillaOption : public Option {
private:
    double _strike;

public:

    // Constructor to initialize _expiry and _strike
    EuropeanVanillaOption(double expiry, double strike) : Option(expiry), _strike(strike) {
        if (strike < 0) {
            throw std::invalid_argument("Strike must be non-negative");
        }
    }

    // Getter for _strike
    double getStrike() const {
        return _strike;
    }

    // Pure virtual method to get option type (to be implemented by derived classes)
    virtual optionType GetOptionType(optionType) const = 0;

};

#endif
