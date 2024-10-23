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
    Option(double expiry) : _expiry(expiry) {}

    // Getter method for _expiry
    double getExpiry() const {
        return _expiry;
    }

    // Pure virtual function for payoff
    virtual double payoff(double price) const = 0;

    // Virtual destructor
    virtual ~Option() {}
};

#endif
