// =========================================================
// File: europeanVanillaOption.h
// Author: [Your Name]
// Date: [Current Date]
// Description: Header file for EuropeanVanillaOption class
// =========================================================
#ifndef EUROPEANVANILLAOPTION_H
#define EUROPEANVANILLAOPTION_H

#include "option.h" // Include the base Option class

class EuropeanVanillaOption : public Option {
private:
    double _strike;

public:
    // Enum class for option types
    enum class optionType { call, put };

    // Constructor to initialize _expiry and _strike
    EuropeanVanillaOption(double expiry, double strike) : Option(expiry), _strike(strike) {
        if (expiry < 0 || strike < 0) {
            throw std::invalid_argument("Expiry and strike must be non-negative");
        }
    }

    // Getter for _strike
    double getStrike() const {
        return _strike;
    }

    // Pure virtual method to get option type (to be implemented by derived classes)
    virtual optionType GetOptionType() const = 0;

    // Destructor
    virtual ~EuropeanVanillaOption() {}
};

#endif
