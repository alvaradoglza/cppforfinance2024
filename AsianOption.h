#ifndef ASIANOPTION_H
#define ASIANOPTION_H

#include "Option.h"

class AsianOption : public Option {
private:
    std::vector<double> timeSteps;

public:
    explicit AsianOption(const std::vector<double>& timeSteps) : timeSteps(timeSteps) {}

    const std::vector<double>& getTimeSteps() const {
        return timeSteps;
    }

    double payoffPath(const std::vector<double>& path) const override {
        double sum = 0.0;
        for (double St : path) {
            sum += St;
        }
        double average = sum / path.size();
        return payoff(average);
    }

    bool isAsianOption() const override {
        return true;
    }
};

#endif
