// =========================================================
// File: option.h
// Author: Emmy
// Date: 23/10/2024
// Description: Enhanced header file for Option class with American Option support
// =========================================================
#ifndef OPTION_H
#define OPTION_H

#include <vector>
#include <stdexcept>
#include <string>

enum class optionType { call, put };

class Option {
private:
    double _expiry;

public:
    // Constructor
    explicit Option(double expiry) : _expiry(expiry) {
        if (expiry < 0) {
            throw std::invalid_argument("Expiry must be non-negative.");
        }
    }

    Option() : _expiry(0.0) {}

    // Getter for expiry
    double getExpiry() const {
        return _expiry;
    }

    // Pure virtual function for payoff calculation
    virtual double payoff(double spotPrice) const = 0;

    // Virtual function to return strike price (default = 0 for path-dependent options)
    virtual double getStrike() const {
        return 0.0; // Default: no specific strike for generic options
    }

    // Virtual function to return the type of the option (Call or Put)
    virtual optionType getOptionType() const = 0;

    // Virtual function for path-dependent payoff
    virtual double payoffPath(const std::vector<double>& path) const {
        return payoff(path.back()); // Default behavior for non-path-dependent options
    }

    // Virtual function to check if the option is Asian
    virtual bool isAsianOption() const {
        return false; // Default: not an Asian option
    }

    // Virtual function to check if the option is American
    virtual bool isAmericanOption() const {
        return false; // Default: not an American option
    }

    // Virtual destructor
    virtual ~Option() = default;
};

#endif // OPTION_H
