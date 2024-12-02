// =========================================================
// File: BlackScholesMCPricer.cpp
// Author: Emmy
// Date: 23/10/2024
// Description: Implementation of the Black-Scholes Monte Carlo Pricer
// =========================================================

#include "BlackScholesMCPricer.h"

// Constructor
BlackScholesMCPricer::BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility)
    : option(option), S0(initial_price), r(interest_rate), sigma(volatility), nbPaths(0), currentPrice(0.0) {
    if (option->isAsianOption()) {
        throw std::invalid_argument("Asian options not allowed in CRRPricer.");
    }
}

// Getter for the number of paths
int BlackScholesMCPricer::getNbPaths() const {
    return nbPaths;
}

// Generate paths and update the price estimate
void BlackScholesMCPricer::generate(int nb_paths) {
    std::vector<double> path;
    double dt = 1.0 / nb_paths;

    for (int i = 0; i < nb_paths; ++i) {
        path.clear();
        double St = S0;
        for (double t = dt; t <= 1.0; t += dt) {
            double Z = MT::rand_norm();
            St *= std::exp((r - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * Z);
            path.push_back(St);
        }
        currentPrice += option->payoffPath(path);
    }

    nbPaths += nb_paths;
    currentPrice /= nbPaths;
}

// Overloaded operator to retrieve the current price
double BlackScholesMCPricer::operator()() const {
    if (nbPaths == 0) {
        throw std::runtime_error("No paths generated yet.");
    }
    return currentPrice;
}

// Calculate the confidence interval for the current price estimate
std::vector<double> BlackScholesMCPricer::confidenceInterval() const {
    double stddev = std::sqrt(currentPrice / nbPaths);
    double margin = 1.96 * stddev / std::sqrt(nbPaths);
    return {currentPrice - margin, currentPrice + margin};
}
