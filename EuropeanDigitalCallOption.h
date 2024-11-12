#ifndef EUROPEANDIGITALCALLOPTION_H
#define EUROPEANDIGITALCALLOPTION_H
#include "EuropeanDigitalOption.h"

class EuropeanDigitalCallOption : public EuropeanDigitalOption {
public:
    EuropeanDigitalCallOption(double expiry, double strike) : EuropeanDigitalOption(expiry, strike) {}

    double payoff(double z) const override {
        return (z >= _strike) ? 1.0 : 0.0;
    }
    // Return the option type (Put)
    optionType getOptionType() const override {
        return optionType::call;
    }

};
#endif