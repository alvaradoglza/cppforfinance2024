// =========================================================
// File: MT.cpp
// Author: Emmy
// Date: 23/10/2024
// Description: Implementation of the MT class for random number generation
// =========================================================

#include "MT.h"

// Definition of the static member variable
std::mt19937 MT::rng;

// Private constructor
MT::MT() {
    std::random_device rd;
    rng.seed(rd());
}

// Generate a random uniform number in [0, 1]
double MT::rand_unif() {
    static std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(rng);
}

// Generate a random standard normal number
double MT::rand_norm() {
    static std::normal_distribution<double> dist(0.0, 1.0);
    return dist(rng);
}
