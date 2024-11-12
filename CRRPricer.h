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
    }

    // Compute option price
    void compute() {
        double q = (_interest_rate - _down) / (_up - _down);

        // Fill terminal nodes with payoffs
        for (int i = 0; i <= _depth; ++i) {
            double stock_price = _asset_price * pow(1 + _up, i) * pow(1 + _down, _depth - i);
            _tree.setNode(_depth, i, _option->payoff(stock_price));
        }

        // Backward induction for option price
        for (int n = _depth - 1; n >= 0; --n) {
            for (int i = 0; i <= n; ++i) {
                double H_next = q * _tree.getNode(n + 1, i + 1) + (1 - q) * _tree.getNode(n + 1, i);
                _tree.setNode(n, i, H_next / (1 + _interest_rate));
            }
        }
    }

    // Access specific node in the tree
    double get(int n, int i) const {
        return _tree.getNode(n, i);
    }

    // Operator to calculate option price
    double operator()(bool closed_form = false) {
        if (closed_form) {
            // Closed-form pricing (if applicable)
            double q = (_interest_rate - _down) / (_up - _down);
            double price = 0.0;
            for (int i = 0; i <= _depth; ++i) {
                double stock_price = _asset_price * pow(1 + _up, i) * pow(1 + _down, _depth - i);
                double binomial_coeff = std::tgamma(_depth + 1) / (std::tgamma(i + 1) * std::tgamma(_depth - i + 1));
                price += binomial_coeff * pow(q, i) * pow(1 - q, _depth - i) * _option->payoff(stock_price);
            }
            return price / pow(1 + _interest_rate, _depth);
        } else {
            compute();
            return get(0, 0);
        }
    }
};

#endif // CRRPRICER_H
