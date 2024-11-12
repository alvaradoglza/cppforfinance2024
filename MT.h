#include <random> // Include this header for std::mt19937 and std::random_device

class MT {
private:
    static std::mt19937 rng;

    MT() {
        std::random_device rd;
        rng.seed(rd());
    }

public:
    static double rand_unif() {
        static std::uniform_real_distribution<double> dist(0.0, 1.0);
        return dist(rng);
    }

    static double rand_norm() {
        static std::normal_distribution<double> dist(0.0, 1.0);
        return dist(rng);
    }
};

std::mt19937 MT::rng;
