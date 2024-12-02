// =========================================================
// File: AsianOption.h
// Author: Emmy
// Date: 23/10/2024
// Description: Header file for the AsianOption class
// =========================================================

#ifndef ASIANOPTION_H
#define ASIANOPTION_H

#include "Option.h"
#include <vector>

// AsianOption class, derived from Option
class AsianOption : public Option {
private:
    std::vector<double> timeSteps; // Time steps for the Asian option

public:
    // Constructor
    explicit AsianOption(const std::vector<double>& timeSteps);

    // Getter for time steps
    const std::vector<double>& getTimeSteps() const;

    // Override payoffPath function for path-dependent payoff
    double payoffPath(const std::vector<double>& path) const override;

    // Override isAsianOption function
    bool isAsianOption() const override;
};

#endif // ASIANOPTION_H
