#ifndef ASIANPUTOPTION_H
#define ASIANPUTOPTION_H
#include "AsianOption.h"

class AsianPutOption : public AsianOption {
private:
    double strike;

public:
    AsianPutOption(const std::vector<double>& timeSteps, double strike)
        : AsianOption(timeSteps), strike(strike) {}

    double payoff(double St) const override {
        return std::max(strike - St, 0.0); // Put payoff
    }

    optionType getOptionType() const override {
        return optionType::put; // Return the correct type
    }

};

#endif