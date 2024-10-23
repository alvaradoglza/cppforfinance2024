// =========================================================
// File: main.cpp
// Author: [Your Name]
// Date: [Current Date]
// Description: Main file to test Option classes and Black-Scholes pricer
// =========================================================

#include <iostream>
#include "BlackScholesPricer.h"
#include "PutOption.h"
#include "CallOption.h"

int main() {
    // Test with a Call Option
    double expiry = 5.0;          // 1 year to expiry
    double strike = 101.0;        // Strike price of 100
    double assetPrice = 100.0;    // Current asset price
    double interestRate = 0.01;   // 5% risk-free rate
    double volatility = 0.1;      // 20% volatility

    // Create a CallOption object
    CallOption callOption(expiry, strike);
    std::cout << "Call Option Strike Price: " << callOption.getStrike() << std::endl;

    // Create a BlackScholesPricer for the Call Option
    BlackScholesPricer callPricer(&callOption, assetPrice, interestRate, volatility);
    std::cout << "Call Option Price (Black-Scholes): " << callPricer() << std::endl;
    std::cout << "Call Option Delta: " << callPricer.delta() << std::endl;

    std::cout << "===============================" << std::endl;

    // Test with a Put Option
    double putStrike = 95.0;      // Strike price of 95
    // Create a PutOption object
    PutOption putOption(expiry, putStrike);
    std::cout << "Put Option Strike Price: " << putOption.getStrike() << std::endl;

    // Create a BlackScholesPricer for the Put Option
    BlackScholesPricer putPricer(&putOption, assetPrice, interestRate, volatility);
    std::cout << "Put Option Price (Black-Scholes): " << putPricer() << std::endl;
    std::cout << "Put Option Delta: " << putPricer.delta() << std::endl;

    return 0;
}
