#ifndef D_SYMMETRIC_DATA_H
#define D_SYMMETRIC_DATA_H

#include <stddef.h>

struct D_symm
{
    size_t size;
    int *data;
};

void print_d_symm(struct D_symm *d_symm);

int *d_symm_elem(struct D_symm *d_symm, const size_t x, const size_t y);

void fget_d_symm(struct D_symm *d_symm, FILE *file);

int *make_d_symm(const size_t size); //CALLS CALLOC, DON`T FORGET TO FREE MEMORY

#endif //D_SYMMETRIC_DATA_H
