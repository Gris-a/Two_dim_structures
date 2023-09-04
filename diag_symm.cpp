#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "diag_symm.h"

#include "colors.h"

int *d_symm_elem(struct D_symm *d_symm, const size_t x, const size_t y)//TODO segfault check
{
    assert(d_symm       != NULL);
    assert(d_symm->data != NULL);
    assert(x < d_symm->size && y < d_symm->size);

    if(x == y)
    {
        return d_symm->data;
    }

        return (x < y) ? d_symm->data + y * (y - 1) / 2 + 1 + x : d_symm->data + x * (x - 1) / 2 + 1 + y;
}

void print_d_symm(struct D_symm *d_symm)
{
    assert(d_symm       != NULL);
    assert(d_symm->data != NULL);

    for(size_t y = 0; y < d_symm->size; y++)
    {
        for(size_t x = 0; x < d_symm->size; x++)
        {
            printf("{%zu %zu}", y, x);
            printf(color_red("%d\t"), *d_symm_elem(d_symm, x, y));
        }
        printf("\n"
               "\n");
    }
}

//TODO undef macros
//TODO rename file
//TODO setter func/getter func

void fget_d_symm(struct D_symm *d_symm, FILE *file)
{
    assert(d_symm       != NULL);
    assert(d_symm->data != NULL);
    assert(file         != NULL);

    for(size_t y = 0; y < d_symm->size; y++)
    {
        for(size_t x = 0; x < d_symm->size; x++)
        {
            fscanf(file, "%d", d_symm_elem(d_symm, x, y));
        }
    }
}

int *make_d_symm(const size_t size)
{
    return (int *)calloc(size * (size - 1) / 2 + 1, sizeof(int));
}
