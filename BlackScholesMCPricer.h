#ifndef BLACKSCHOLESMCPRICER_H
#define BLACKSCHOLESMCPRICER_H
#include "MT.h"



class BlackScholesMCPricer {
private:
    Option* option;
    double S0, r, sigma;
    int nbPaths = 0;
    double currentPrice = 0.0;

public:
    BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility)
        : option(option), S0(initial_price), r(interest_rate), sigma(volatility) {
        if (option->isAsianOption()) {
            throw std::invalid_argument("Asian options not allowed in CRRPricer.");
        }
    }

    int getNbPaths() const {
        return nbPaths;
    }

    void generate(int nb_paths) {
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

    double operator()() const {
        if (nbPaths == 0) {
            throw std::runtime_error("No paths generated yet.");
        }
        return currentPrice;
    }

    std::vector<double> confidenceInterval() const {
        double stddev = std::sqrt(currentPrice / nbPaths);
        double margin = 1.96 * stddev / std::sqrt(nbPaths);
        return {currentPrice - margin, currentPrice + margin};
    }
};

#endif