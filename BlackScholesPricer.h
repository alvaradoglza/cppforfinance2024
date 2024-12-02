// =========================================================
// File: BlackScholesPricer.h
// Author: Emmy
// Date: 23/10/2024
// Description: Header file for the BlackScholesPricer class
// =========================================================

#ifndef BLACKSCHOLESPRICER_H
#define BLACKSCHOLESPRICER_H

#include <cmath>
#include <stdexcept>
#include "EuropeanVanillaOption.h"

// Class for pricing European vanilla options using the Black-Scholes formula
class BlackScholesPricer {
private:
    Option* _option;           // Pointer to the option being priced
    double _asset_price;       // Current asset price
    double _interest_rate;     // Risk-free interest rate
    double _volatility;        // Volatility of the asset

public:
    // Constructor
    BlackScholesPricer(Option* option, double asset_price, double interest_rate, double volatility);

    // Operator() to calculate the option price using the Black-Scholes formula
    double operator()() const;

    // Method to calculate the Delta of the option
    double delta() const;
};

#endif // BLACKSCHOLESPRICER_H
