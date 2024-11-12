#ifndef AMERICANOPTION_H
#define AMERICANOPTION_H

#include "Option.h"
class AmericanOption : public Option {
public:
    explicit AmericanOption(double expiry) : Option(expiry) {}

    bool isAmericanOption() const override {
        return true; // Indicates this is an American option
    }
};

#endif
