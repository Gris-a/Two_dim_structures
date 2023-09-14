#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"

#include "../colors.h"

int *get_matrix_elem(struct Matrix *matrix, const size_t x, const size_t y)
{
    assert(matrix         != NULL);
    assert(matrix->matrix != NULL);
    assert(matrix->width > x && matrix->height > y);

    return matrix->matrix + x * matrix->width + y;
}

void set_matrix_elem(struct Matrix *matrix, const size_t x, const size_t y, int elem)
{
    *get_matrix_elem(matrix, x, y) = elem;
}

void print_matrix(struct Matrix *matrix)
{
    assert(matrix         != NULL);
    assert(matrix->matrix != NULL);

    for(size_t i = 0; i < matrix->height; i++)
    {
        for(size_t j = 0; j < matrix->width; j++)
        {
            printf("[%zu, %zu]"color_red("%d\t"), i, j, *get_matrix_elem(matrix, i, j));
        }
        printf("\n"
               "\n");
    }
}

//TODO return actual size of matrix
void fget_matrix(struct Matrix *matrix, FILE *file)
{
    assert(matrix         != NULL);
    assert(matrix->matrix != NULL);
    if(file == NULL)
    {
        printf(color_red("Can not open file.\n"));

        return;
    }

    for(size_t i = 0; i < matrix->height; i++)
    {
        for(size_t j = 0; j < matrix->width; j++)
        {
            fscanf(file, "%d", get_matrix_elem(matrix, i, j));
        }
    }
}

int *make_matrix(const size_t width, const size_t height)
{
    return (int *)calloc(width * height, sizeof(int));
}
