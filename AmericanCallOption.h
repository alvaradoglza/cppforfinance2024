#ifndef AMERICANCALLOPTION_H
#define AMERICANCALLOPTION_H
#include "AmericanOption.h"

class AmericanCallOption : public AmericanOption {
private:
    double strike;

public:
    AmericanCallOption(double expiry, double strike)
        : AmericanOption(expiry), strike(strike) {}

    double payoff(double spotPrice) const override {
        return std::max(spotPrice - strike, 0.0);
    }

    double getStrike() const override {
        return strike;
    }

    optionType getOptionType() const override {
        return optionType::call;
    }
};

#endif