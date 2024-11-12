#ifndef ASIANCALLOPTION_H
#define ASIANCALLOPTION_H
#include "AsianOption.h"

class AsianCallOption : public AsianOption {
private:
    double strike;

public:
    AsianCallOption(const std::vector<double>& timeSteps, double strike)
        : AsianOption(timeSteps), strike(strike) {}

    double payoff(double St) const override {
        return std::max(St - strike, 0.0); // Call payoff
    }

    optionType getOptionType() const override {
        return optionType::call;
    }
};

#endif