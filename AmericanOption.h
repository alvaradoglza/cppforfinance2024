// =========================================================
// File: AmericanOption.h
// Author: Emmy
// Date: 23/10/2024
// Description: Header file for the AmericanOption class
// =========================================================

#ifndef AMERICANOPTION_H
#define AMERICANOPTION_H

#include "Option.h"

// AmericanOption class, derived from Option
class AmericanOption : public Option {
public:
    // Constructor
    explicit AmericanOption(double expiry);

    // Override to indicate this is an American option
    bool isAmericanOption() const override;
};

#endif // AMERICANOPTION_H
