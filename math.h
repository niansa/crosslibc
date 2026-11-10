#pragma once

#if !defined(CLIBC_NO_FLOAT) || !defined(CLIBC_NO_DOUBLE)
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

#ifndef CLIBC_NO_FLOAT
float ceilf(float x);

float copysignf(float x, float y);

float fabsf(float x);

float floorf(float x);

float sqrtf(float x);

float truncf(float x);

float rintf(float x);
#endif

#ifndef CLIBC_NO_DOUBLE
double ceil(double x);
long double ceill(long double x);

double copysign(double x, double y);
long double copysignl(long double x, long double y);

double fabs(double x);

double floor(double x);

double sqrt(double x);

double trunc(double x);

double rint(double x);
#endif

#ifdef __cplusplus
}
#endif
#endif
