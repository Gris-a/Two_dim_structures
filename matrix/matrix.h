#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

struct Matrix
{
    size_t width;
    size_t height;
    int   *matrix;
};

int *get_matrix_elem(struct Matrix *matrix, const size_t x, const size_t y);
void set_matrix_elem(struct Matrix *matrix, const size_t x, const size_t y, int elem);

void print_matrix(struct Matrix *matrix);

void fget_matrix(struct Matrix *matrix, FILE *file);

int *make_matrix(const size_t width, const size_t height); //CALLS CALLOC, DON`T FORGET TO FREE MEMORY

#endif //MATRIX_H
