#ifndef POINT_HPP_
#define POINT_HPP_

// #include <random>
#include <cstdlib>
#include <time.h>
#include <random>

using namespace std;

class point {
    public:
        double x;
        double y;
        point() {
            random_device rand_dev;
            mt19937 generator(rand_dev());
            uniform_real_distribution<double>  distr(-10.0, 10.0); // range of plot
            x = distr(generator);
            y = distr(generator);
        }
        point(double xx, double yy) {
            x = xx;
            y = yy;
        }
};

#endif