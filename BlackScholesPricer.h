// =========================================================
// File: BlackScholesPricer.h
// Author: 
// Date: [23:10.2025]
// Description: Header file for BlackScholesPricer class
// =========================================================

class BlackScholesPricer {
private:
    EuropeanVanillaOption* _option;
    double _asset_price;
    double _interest_rate;
    double _volatility;

public:
    // Constructor
    BlackScholesPricer(EuropeanVanillaOption* option, double asset_price, double interest_rate, double volatility) 
        : _option(option), _asset_price(asset_price), _interest_rate(interest_rate), _volatility(volatility) {
        if (asset_price <= 0 || interest_rate < 0 || volatility < 0) {
            throw std::invalid_argument("Invalid input values. Asset price, interest rate, and volatility must be non-negative, and asset price must be positive.");
        }
    }

    // Operator() to calculate the option price using the Black-Scholes formula
    double operator()() const {
        double S = _asset_price;
        double K = _option->getStrike();
        double r = _interest_rate;
        double sigma = _volatility;
        double T = _option->getExpiry();
        double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
        double d2 = d1 - sigma * std::sqrt(T);
        double Nd1 = 0.5 * std::erfc(-d1 / std::sqrt(2));  // Cumulative distribution function for the standard normal
        double Nd2 = 0.5 * std::erfc(-d2 / std::sqrt(2));

        if (_option->GetOptionType() == EuropeanVanillaOption::optionType::call) {
            // Call option price
            return S * Nd1 - K * std::exp(-r * T) * Nd2;
        } else {
            // Put option price
            return K * std::exp(-r * T) * (1 - Nd2) - S * (1 - Nd1);
        }
    }

    // Method to calculate the Delta of the option
    double delta() const {
        double S = _asset_price;
        double K = _option->getStrike();
        double r = _interest_rate;
        double sigma = _volatility;
        double T = _option->getExpiry();
        double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
        double Nd1 = 0.5 * std::erfc(-d1 / std::sqrt(2));

        if (_option->GetOptionType() == EuropeanVanillaOption::optionType::call) {
            // Delta for a call option
            return Nd1;
        } else {
            // Delta for a put option
            return Nd1 - 1;
        }
    }
};

