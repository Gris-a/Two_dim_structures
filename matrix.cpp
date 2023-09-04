#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"

#include "colors.h"

int *matrix_elem(struct Matrix *matrix, const size_t x, const size_t y)
{
    assert(matrix         != NULL);
    assert(matrix->matrix != NULL);
    assert(matrix->width > x && matrix->height > y);

    return matrix->matrix + x * matrix->width + y;
}

void print_matrix(struct Matrix *matrix)
{
    assert(matrix         != NULL);
    assert(matrix->matrix != NULL);

    for(size_t i = 0; i < matrix->height; i++)
    {
        for(size_t j = 0; j < matrix->width; j++)
        {
            printf("[%zu, %zu]"color_red("%d\t"), i, j, *matrix_elem(matrix, i, j));
        }
        printf("\n"
               "\n");
    }
}

void fget_matrix(struct Matrix *matrix, FILE *file)
{
    assert(matrix         != NULL);
    assert(matrix->matrix != NULL);
    assert(file           != NULL);

    for(size_t i = 0; i < matrix->height; i++)
    {
        for(size_t j = 0; j < matrix->width; j++)
        {
            fscanf(file, "%d", matrix_elem(matrix, i, j));
        }
    }
}

int *make_matrix(const size_t width, const size_t height)
{
    return (int *)calloc(width * height, sizeof(int));
}
