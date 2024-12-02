#include <iostream>
#include <vector>
#include "CallOption.h"
#include "PutOption.h"
#include "EuropeanDigitalCallOption.h"
#include "EuropeanDigitalPutOption.h"
#include "AmericanCallOption.h"
#include "AmericanPutOption.h"
#include "CRRPricer.h"

int main() {
    // Input parameters
    double S0 = 95.0;  // Initial stock price
    double K = 100.0;  // Strike price
    double T = 0.5;    // Time to expiry in years
    double r = 0.02;   // Risk-free interest rate
    double sigma = 0.2; // Volatility

    // Vector to hold option pointers
    std::vector<Option*> opt_ptrs;
    opt_ptrs.push_back(new CallOption(T, K));
    opt_ptrs.push_back(new PutOption(T, K));
    opt_ptrs.push_back(new EuropeanDigitalCallOption(T, K));
    opt_ptrs.push_back(new EuropeanDigitalPutOption(T, K));
    opt_ptrs.push_back(new AmericanCallOption(T, K));
    opt_ptrs.push_back(new AmericanPutOption(T, K));

    // Iterate over all options, compute and display prices
    for (auto& opt_ptr : opt_ptrs) {
        // Create the CRR Pricer for the option
        CRRPricer pricer(opt_ptr, 150, S0, r, sigma);

        // Compute the price
        pricer.compute();

        // Display the computed price
        std::cout << "Option type: " 
                  << (opt_ptr->getOptionType() == optionType::call ? "Call" : "Put") 
                  << ", Price: " << pricer() << std::endl;

        // Clean up the dynamically allocated option
        delete opt_ptr;
    }

    return 0;
}
