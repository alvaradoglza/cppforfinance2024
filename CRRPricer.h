#ifndef CRRPRICER_H
#define CRRPRICER_H

#include <cmath>
#include <stdexcept>
#include "BinaryTree.h"
#include "Option.h"

class CRRPricer {
private:
    Option* _option;
    int _depth;
    double _asset_price;
    double _up;
    double _down;
    double _interest_rate;
    BinaryTree<double> _tree;
    BinaryTree<bool> _exercise_tree; // To store the exercise policy

    // Check for arbitrage-free condition
    void checkForArbitrage() {
        if (!(_down < _interest_rate && _interest_rate < _up)) {
            throw std::invalid_argument("No arbitrage condition violated: D < R < U");
        }
    }

    // Check if the option is Asian
    void checkForAsianOption() {
        if (_option->isAsianOption()) {
            throw std::invalid_argument("CRRPricer does not support Asian options.");
        }
    }

public:
    // Constructor
    CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate)
        : _option(option), _depth(depth), _asset_price(asset_price), _up(up), _down(down), _interest_rate(interest_rate) {
        checkForArbitrage();
        checkForAsianOption();
        _tree.setDepth(_depth);
        _exercise_tree.setDepth(_depth);
    }

    // Constructor for Black-Scholes Approximation
    CRRPricer(Option* option, int depth, double asset_price, double r, double sigma)
        : _option(option), _depth(depth), _asset_price(asset_price) {
        double h = _option->getExpiry() / depth;
        _up = std::exp((r + 0.5 * sigma * sigma) * h + sigma * std::sqrt(h)) - 1;
        _down = std::exp((r + 0.5 * sigma * sigma) * h - sigma * std::sqrt(h)) - 1;
        _interest_rate = std::exp(r * h) - 1;
        _tree.setDepth(_depth);
        _exercise_tree.setDepth(_depth);
    }

    // Compute option price
    void compute() {
        double q = (_interest_rate - _down) / (_up - _down);

        // Fill terminal nodes with payoffs
        for (int i = 0; i <= _depth; ++i) {
            double stock_price = _asset_price * pow(1 + _up, i) * pow(1 + _down, _depth - i);
            _tree.setNode(_depth, i, _option->payoff(stock_price));
            _exercise_tree.setNode(_depth, i, false); // No early exercise at expiry
        }

        // Backward induction for option price
        for (int n = _depth - 1; n >= 0; --n) {
            for (int i = 0; i <= n; ++i) {
                double continuation_value =
                    (q * _tree.getNode(n + 1, i + 1) + (1 - q) * _tree.getNode(n + 1, i)) / (1 + _interest_rate);
                double stock_price = _asset_price * pow(1 + _up, i) * pow(1 + _down, n - i);
                double intrinsic_value = _option->payoff(stock_price);

                if (_option->isAmericanOption()) {
                    // Choose the maximum of continuation value and intrinsic value
                    if (intrinsic_value >= continuation_value) {
                        _tree.setNode(n, i, intrinsic_value);
                        _exercise_tree.setNode(n, i, true); // Early exercise
                    } else {
                        _tree.setNode(n, i, continuation_value);
                        _exercise_tree.setNode(n, i, false); // Do not exercise
                    }
                } else {
                    // For European options, only the continuation value matters
                    _tree.setNode(n, i, continuation_value);
                }
            }
        }
    }

    // Access specific node in the price tree
    double get(int n, int i) const {
        return _tree.getNode(n, i);
    }

    // Access specific node in the exercise tree
    bool getExercise(int n, int i) const {
        return _exercise_tree.getNode(n, i);
    }

    // Operator to calculate option price
    double operator()() const {
        return _tree.getNode(0, 0);
    }
};

#endif // CRRPRICER_H
