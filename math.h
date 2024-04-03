#pragma once

#include <float.h>

#define CEILING_POS(X) ((X-(long)(X)) > 0 ? (long)(X+1) : (long)(X))
#define CEILING_NEG(X) (long)(X)
#define CEILING(X) ( ((X) > 0) ? CEILING_POS(X) : CEILING_NEG(X) )

#define isnan(x) __builtin_isnan(x)
#define isinf(x) __builtin_isinf(x)
#define signbit(x) __builtin_signbit(x)


#ifdef __cplusplus
extern "C" {
#endif

double ceil(double x);
float ceilf(float x);
long double ceill(long double x);

double copysign(double x, double y);
float copysignf(float x, float y);
long double copysignl(long double x, long double y);

double fabs(double x);
float fabsf(float x);

double floor(double x);
float floorf(float x);

double sqrt(double x);
float sqrtf(float x);

double trunc(double x);
float truncf(float x);

double rint(double x);
float rintf(float x);

#ifdef __cplusplus
}
#endif
