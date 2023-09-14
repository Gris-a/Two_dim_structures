#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "../colors.h"

//Size of matrix is external constants

void print_data(const int* arr, const size_t height, const size_t width);
size_t fread_data(FILE *file, int *arr, const size_t height, const size_t width);

int *data_elem(int *arr, const size_t height, const size_t width, const size_t y, const size_t x);

int main(void)
{
    size_t height = 0;
    size_t width  = 0;

    FILE *file = fopen("input.txt", "r");
    if(file == NULL)
    {
        printf(color_red("Can not open file.\n"));

        return EXIT_FAILURE;
    }

    fscanf(file, "%zu, %zu\n", &height, &width);

    int *arr = (int *)calloc(height * width, sizeof(int));
    if(arr == NULL)
    {
        printf(color_red("Can not allocate memory.\n"));

        return EXIT_FAILURE;
    }

    height = fread_data(file, arr, height, width);

    print_data(arr, height, width);

    free(arr);

    return EXIT_SUCCESS;
}

void print_data(const int *arr, const size_t height, const size_t width)
{
    assert(arr != NULL);

    for(size_t i = 0; i < height; i++)
    {
        for(size_t j = 0; j < width; j++)
        {
            printf("%d\t", *data_elem(arr, height, width, i, j));
        }

        printf("\n");
    }
}

size_t fread_data(FILE *file, int *arr, const size_t height, const size_t width)
{
    assert(arr != NULL);
    if(file == NULL)
    {
        printf(color_red("Can not open file.\n"));

        return 0;
    }

    for(size_t i = 0; i < height * width; i++)
    {
        if(fscanf(file, "%d", arr++) == EOF)
        {
            return i / width;
        }
    }
    return height;
}

int *data_elem(int *arr, const size_t height, const size_t width, const size_t y, const size_t x)
{
    assert(arr != NULL);
    assert(x < width && y < height);

    return arr + y*width + x;
}
