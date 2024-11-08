#include "Option.h"

class EuropeanDigitalOption : public Option {
protected:
    double _strike;

public:
    EuropeanDigitalOption(double expiry, double strike) : Option(expiry), _strike(strike) {}

    virtual double payoff(double z) const = 0;
};

class EuropeanDigitalCallOption : public EuropeanDigitalOption {
public:
    EuropeanDigitalCallOption(double expiry, double strike) : EuropeanDigitalOption(expiry, strike) {}

    double payoff(double z) const override {
        return (z >= _strike) ? 1.0 : 0.0;
    }
};

class EuropeanDigitalPutOption : public EuropeanDigitalOption {
public:
    EuropeanDigitalPutOption(double expiry, double strike) : EuropeanDigitalOption(expiry, strike) {}

    double payoff(double z) const override {
        return (z <= _strike) ? 1.0 : 0.0;
    }
};
