#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

struct Matrix
{
    size_t width;
    size_t height;
    int *matrix;
};

void print_matrix(struct Matrix *matrix);

int *matrix_elem(struct Matrix *matrix, const size_t x, const size_t y);

void fget_matrix(struct Matrix *matrix, FILE *file);

int *make_matrix(const size_t width, const size_t height); //CALLS CALLOC, DON`T FORGET TO FREE MEMORY

#endif //MATRIX_H
