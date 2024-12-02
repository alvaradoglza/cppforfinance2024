// =========================================================
// File: BlackScholesMCPricer.h
// Author: Emmy
// Date: 23/10/2024
// Description: Header file for the Black-Scholes Monte Carlo Pricer
// =========================================================

#ifndef BLACKSCHOLESMCPRICER_H
#define BLACKSCHOLESMCPRICER_H

#include "Option.h"
#include "MT.h"
#include <vector>
#include <cmath>
#include <stdexcept>

// Class for pricing options using the Black-Scholes Monte Carlo method
class BlackScholesMCPricer {
private:
    Option* option;  // Pointer to the option being priced
    double S0, r, sigma;  // Initial price, interest rate, and volatility
    int nbPaths;  // Number of paths generated
    double currentPrice;  // Current price estimate

public:
    // Constructor
    BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility);

    // Getter for the number of paths
    int getNbPaths() const;

    // Generate paths and update the price estimate
    void generate(int nb_paths);

    // Overloaded operator to retrieve the current price
    double operator()() const;

    // Calculate the confidence interval for the current price estimate
    std::vector<double> confidenceInterval() const;
};

#endif // BLACKSCHOLESMCPRICER_H
