// =========================================================
// File: option.h
// Author: Emmy
// Date: 23/10/2024
// Description: Header file for Option class
// =========================================================
#ifndef OPTION_H
#define OPTION_H

class Option {
private:
    double _expiry;

public:
    // Constructor that initializes _expiry with an argument
    Option(double expiry) : _expiry(expiry) {
    if (expiry < 0) {
            throw std::invalid_argument("Expiry must be non-negative.");
        }
    }


    // Getter method for _expiry
    double getExpiry() const {
        return _expiry;
    }

    // Pure virtual function for payoff
    virtual double payoff(double) const = 0;
};

#endif
