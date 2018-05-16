#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdio.h>
#include <math.h>

void print_vector(double* x);
void vector_sum(double* res, double* x, double* y);
void vector_sub(double* res, double* x, double* y);
void vector_scalar_mul(double* res, double* x, double scalar);
double vector_inner_product(double* x, double* y);
void vector_cross_product(double* res, double* x, double* y);
double vector_abs_val(double* x);
void vector_gso_normalization(double* x0, double* x1, double* x2,double* w0,double* w1,double* w2);


#endif
