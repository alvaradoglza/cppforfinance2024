#include "Option.h"

class EuropeanDigitalOption : public Option {
protected:
    double _strike;

public:
    EuropeanDigitalOption(double expiry, double strike) : Option(expiry), _strike(strike) {}

    virtual double payoff(double z) const = 0;
};



