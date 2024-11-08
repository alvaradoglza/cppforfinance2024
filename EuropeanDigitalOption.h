#ifndef EUROPEANDIGITALOPTION_H
#define EUROPEANDIGITALOPTION_H

#include "Option.h"

class EuropeanDigitalOption : public Option {
protected:
    double _strike;

public:
    EuropeanDigitalOption(double expiry, double strike) : Option(expiry), _strike(strike) {}

    virtual double payoff(double z) const = 0;

    // Getter for _strike
    double getStrike() const {
        return _strike;
    }

    // Pure virtual method to get option type (to be implemented by derived classes)
    virtual optionType GetOptionType() const = 0;

};
#endif


