#ifndef AMERICANPUTOPTION_H
#define AMERICANPUTOPTION_H
#include "AmericanOption.h"

class AmericanPutOption : public AmericanOption {
private:
    double strike;

public:
    AmericanPutOption(double expiry, double strike)
        : AmericanOption(expiry), strike(strike) {}

    double payoff(double spotPrice) const override {
        return std::max(strike - spotPrice, 0.0);
    }

    double getStrike() const override {
        return strike;
    }

    optionType getOptionType() const override {
        return optionType::put;
    }
};

#endif