#include "EuropeanDigitalOption.h"


class EuropeanDigitalPutOption : public EuropeanDigitalOption {
public:
    EuropeanDigitalPutOption(double expiry, double strike) : EuropeanDigitalOption(expiry, strike) {}

    double payoff(double z) const override {
        return (z <= _strike) ? 1.0 : 0.0;
    }
};