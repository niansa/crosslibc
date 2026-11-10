#include <math.h>



#ifndef CLIBC_NO_FLOAT
float ceilf(float x) {
    return CEILING(x);
}

float copysignf(float x, float y) {
    return __builtin_copysignf(x, y);
}

float fabsf(float x) {
    return __builtin_fabsf(x);
}

float floorf(float x) {
    return __builtin_floorf(x);
}

float sqrtf(float x) {
    return __builtin_sqrtf(x);
}

float truncf(float x) {
    return __builtin_truncf(x);
}

float rintf(float x) {
    return __builtin_rintf(x);
}
#endif

#ifndef CLIBC_NO_DOUBLE
double ceil(double x) {
    return CEILING(x);
}
long double ceill(long double x) {
    return CEILING(x);
}

double copysign(double x, double y) {
    return __builtin_copysign(x, y);
}
long double copysignl(long double x, long double y) {
    return __builtin_copysignl(x, y);
}

double fabs(double x) {
    return __builtin_fabs(x);
}

double floor(double x) {
    return __builtin_floor(x);
}

double sqrt(double x) {
    return __builtin_sqrt(x);
}

double trunc(double x) {
    return __builtin_trunc(x);
}

double rint(double x) {
    return __builtin_rint(x);
}
#endif
