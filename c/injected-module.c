#include "injected-module.h"

#define SWAP_VARS(type, x, y) { \
    type temp = x; \
    x = y; \
    y = temp; \
}

double hypothenuse(double x, double y) {
    if (x < y) SWAP_VARS(double, x, y);
    if (x == 0.0) return 0.0;
    double yx = y/x; // yx is within [0, 1]
    return x*sqrt(1.0+yx*yx);
}
