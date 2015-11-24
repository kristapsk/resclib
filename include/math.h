#ifndef _MATH_H
#define _MATH_H

#ifdef __cplusplus
extern "C" {
#endif

double fabs (double x);
float fabsf (float x);
long double fabsl (long double x);
long int lround (double x);
long int lroundf (float x);
long int lroundl (long double x);
long long int llround (double x);
long long int llroundf (float x);
long long int llroundl (long double x);

#ifdef __cplusplus
}
#endif

#endif
