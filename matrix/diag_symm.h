#ifndef D_SYMMETRIC_DATA_H
#define D_SYMMETRIC_DATA_H

#include <stddef.h>

struct D_symm
{
    size_t size;
    int *data;
};

int *get_elem(struct D_symm *d_symm, size_t x, size_t y);
void set_elem(struct D_symm *d_symm, const size_t x, const size_t y, const int elem);

void print_diag_symm(struct D_symm *d_symm);

void fget_diag_symm(struct D_symm *d_symm, FILE *file);

int *make_diag_symm(const size_t size); //CALLS CALLOC, DON`T FORGET TO FREE MEMORY

#endif //D_SYMMETRIC_DATA_H
