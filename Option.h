// =========================================================
// File: Option.h
// Author: Emmy
// Date: 23/10/2024
// Description: Header file for Option class with support for various options
// =========================================================
#ifndef OPTION_H
#define OPTION_H

#include <vector>
#include <stdexcept>
#include <string>

// Enum to represent option types (call or put)
enum class optionType { call, put };

// Abstract base class for options
class Option {
private:
    double _expiry;

public:
    // Constructors
    explicit Option(double expiry);
    Option();

    // Getter for expiry
    double getExpiry() const;

    // Pure virtual function for payoff calculation
    virtual double payoff(double spotPrice) const = 0;

    // Virtual function to return strike price (default = 0 for path-dependent options)
    virtual double getStrike() const;

    // Virtual function to return the type of the option (Call or Put)
    virtual optionType getOptionType() const = 0;

    // Virtual function for path-dependent payoff
    virtual double payoffPath(const std::vector<double>& path) const;

    // Virtual function to check if the option is Asian
    virtual bool isAsianOption() const;

    // Virtual function to check if the option is American
    virtual bool isAmericanOption() const;

    // Virtual destructor
    virtual ~Option() = default;
};

#endif // OPTION_H
// =========================================================
// File: Option.h
// Author: Emmy
// Date: 23/10/2024
// Description: Header file for Option class with support for various options
// =========================================================
#ifndef OPTION_H
#define OPTION_H

#include <vector>
#include <stdexcept>
#include <string>

// Enum to represent option types (call or put)
enum class optionType { call, put };

// Abstract base class for options
class Option {
private:
    double _expiry;

public:
    // Constructors
    explicit Option(double expiry);
    Option();

    // Getter for expiry
    double getExpiry() const;

    // Pure virtual function for payoff calculation
    virtual double payoff(double spotPrice) const = 0;

    // Virtual function to return strike price (default = 0 for path-dependent options)
    virtual double getStrike() const;

    // Virtual function to return the type of the option (Call or Put)
    virtual optionType getOptionType() const = 0;

    // Virtual function for path-dependent payoff
    virtual double payoffPath(const std::vector<double>& path) const;

    // Virtual function to check if the option is Asian
    virtual bool isAsianOption() const;

    // Virtual function to check if the option is American
    virtual bool isAmericanOption() const;

    // Virtual destructor
    virtual ~Option() = default;
};

#endif // OPTION_H
