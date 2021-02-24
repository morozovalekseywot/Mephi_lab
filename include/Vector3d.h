#ifndef Vertex_H
#define Vertex_H

#pragma once
#define func_Complex sum_Complex, diff_Complex, scalar_Complex, cross_Complex, reverse_Complex, mod_Complex, normalize_Complex, \
                     dot_Complex, divide_Complex, scan_Complex

#define func_double sum_double, diff_double, scalar_double, cross_double, reverse_double, mod_double, normalize_double, \
                    dot_double, divide_double, scan_double
#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <stdlib.h>

typedef struct Vertex
{
    void *x;
    void *y;
    void *z;
    void *(*sum)(void *, void *);
    void *(*diff)(void *, void *);
    void *(*scalar)(void *, void *);
    void *(*cross)(void *, void *);
    void *(*reverse)(void *);
    double *(*mod)(void *);
    void *(*normalize)(void *);
    void *(*dot)(void *, double);
    void *(*divide)(void *, double);
    void *(*scan)();
} Vertex;
//Vertex *create();
Vertex *create_Complex();
Vertex *create_double();
void *sum_Complex(void *a, void *b);
void *sum_double(void *a, void *b);
void *diff_Complex(void *a, void *b);
void *diff_double(void *a, void *b);
void *scalar_Complex(void *a, void *b);
void *scalar_double(void *a, void *b);
double *mod_Complex(void *a);
double *mod_double(void *a);
void *normalize_Complex(void *a);
void *normalize_double(void *a);
void *dot_Complex(void *vec, double c);
void *dot_double(void *vec, double c);
void *divide_Complex(void *vec, double c);
void *divide_double(void *vec, double c);
void *reverse_Complex(void *a);
void *reverse_double(void *a);
void *cross_Complex(void *a, void *b);
void *cross_double(void *a, void *b);
void print_Complex(Vertex *a);
void print_double(Vertex *a);
void *scan_Complex();
void *scan_double();
#endif //Vertex_H
