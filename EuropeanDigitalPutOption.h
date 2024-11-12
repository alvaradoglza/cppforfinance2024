#ifndef EUROPEANDIGITALPUTOPTION_H
#define EUROPEANDIGITALPUTOPTION_H
#include "EuropeanDigitalOption.h"


class EuropeanDigitalPutOption : public EuropeanDigitalOption {
public:
    EuropeanDigitalPutOption(double expiry, double strike) : EuropeanDigitalOption(expiry, strike) {}

    double payoff(double z) const override {
        return (z <= _strike) ? 1.0 : 0.0;
    }

    // Return the option type (Put)
    optionType getOptionType() const override {
        return optionType::put;
    }

};
#endif