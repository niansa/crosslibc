#include "math.h"



#ifndef CLIBC_NO_FLOAT
double ceil(double x) {
    return CEILING(x);
}
float ceilf(float x) {
    return CEILING(x);
}
long double ceill(long double x) {
    return CEILING(x);
}

double copysign(double x, double y) {
    return __builtin_copysign(x, y);
}
float copysignf(float x, float y) {
    return __builtin_copysignf(x, y);
}
long double copysignl(long double x, long double y) {
    return __builtin_copysignl(x, y);
}

double fabs(double x) {
    return __builtin_fabs(x);
}
float fabsf(float x) {
    return __builtin_fabsf(x);
}

double floor(double x) {
    return __builtin_floor(x);
}
float floorf(float x) {
    return __builtin_floorf(x);
}

double sqrt(double x) {
    return __builtin_sqrt(x);
}
float sqrtf(float x) {
    return __builtin_sqrtf(x);
}

double trunc(double x) {
    return __builtin_trunc(x);
}
float truncf(float x) {
    return __builtin_truncf(x);
}

double rint(double x) {
    return __builtin_rint(x);
}
float rintf(float x) {
    return __builtin_rintf(x);
}
#endif
