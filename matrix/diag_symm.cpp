#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "diag_symm.h"

#include "../colors.h"

int *get_elem(struct D_symm *d_symm, size_t x, size_t y)
{
    assert(d_symm       != NULL);
    assert(d_symm->data != NULL);
    assert(x < d_symm->size && y < d_symm->size);

    if(x == y)
    {
        return d_symm->data;
    }

    if(x > y)
    {
        y = x + y;
        x = y - x;
        y = y - x;
    }

    return d_symm->data + y * (y - 1) / 2 + 1 + x;
}

void set_elem(struct D_symm *d_symm, const size_t x, const size_t y, const int elem)
{
    *get_elem(d_symm, x, y) = elem;
}

void print_diag_symm(struct D_symm *d_symm)
{
    assert(d_symm       != NULL);
    assert(d_symm->data != NULL);

    for(size_t y = 0; y < d_symm->size; y++)
    {
        for(size_t x = 0; x < d_symm->size; x++)
        {
            printf("{%zu %zu}", y, x);
            printf(color_red("%d\t"), *get_elem(d_symm, x, y));
        }
        printf("\n"
               "\n");
    }
}

//TODO return actual size of matrix and optimize fget_d_symm
void fget_diag_symm(struct D_symm *d_symm, FILE *file)
{
    assert(d_symm       != NULL);
    assert(d_symm->data != NULL);
    if(file == NULL)
    {
        printf(color_red("Can not open file.\n"));

        return;
    }

    for(size_t y = 0; y < d_symm->size; y++)
    {
        for(size_t x = 0; x < d_symm->size; x++)
        {
            fscanf(file, "%d", get_elem(d_symm, x, y));
        }
    }
}

int *make_diag_symm(const size_t size)
{
    return (int *)calloc(size * (size - 1) / 2 + 1, sizeof(int));
}

