// =========================================================
// File: MT.h
// Author: Emmy
// Date: 23/10/2024
// Description: Header file for the MT class, providing utilities
//              for random number generation.
// =========================================================

#ifndef MT_H
#define MT_H

#include <random>

// Singleton-like class for random number generation
class MT {
private:
    static std::mt19937 rng;  // Random number generator

    // Private constructor to prevent instantiation
    MT();

public:
    // Generate a random uniform number in [0, 1]
    static double rand_unif();

    // Generate a random standard normal number
    static double rand_norm();
};

#endif // MT_H
