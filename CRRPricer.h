// =========================================================
// File: CRRPricer.h
// Author: Emmy
// Date: 23/10/2024
// Description: Header file for the CRRPricer class
// =========================================================

#ifndef CRRPRICER_H
#define CRRPRICER_H

#include <cmath>
#include <stdexcept>
#include "BinaryTree.h"
#include "Option.h"

// Class for pricing options using the Cox-Ross-Rubinstein (CRR) binomial tree model
class CRRPricer {
private:
    Option* _option;                     // Option being priced
    int _depth;                          // Depth of the binomial tree
    double _asset_price;                 // Initial asset price
    double _up;                          // Up factor
    double _down;                        // Down factor
    double _interest_rate;               // Interest rate
    BinaryTree<double> _tree;            // Binomial tree for option prices
    BinaryTree<bool> _exercise_tree;     // Tree for exercise policy

    // Check for arbitrage-free condition
    void checkForArbitrage();

    // Check if the option is Asian
    void checkForAsianOption();

public:
    // Constructor
    CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate);

    // Alternative constructor for Black-Scholes approximation
    CRRPricer(Option* option, int depth, double asset_price, double r, double sigma);

    // Compute option price
    void compute();

    // Access specific node in the price tree
    double get(int n, int i) const;

    // Access specific node in the exercise tree
    bool getExercise(int n, int i) const;

    // Operator to calculate option price
    double operator()(bool closed_form = false);
};

#endif // CRRPRICER_H
