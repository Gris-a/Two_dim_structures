#include <stdio.h>
#include <assert.h>

void print_data(const int* arr, const size_t height, const size_t width);
const int *data_elem(const int *arr, const size_t y, const size_t x, const size_t height, const size_t width);

int main(void)
{
    /**
    struct Matrix matrix = {2, 2, NULL};
    matrix.matrix = make_matrix(matrix.height, matrix.width);
    fget_matrix (&matrix, file);
    print_matrix(&matrix);

    free(matrix.matrix);
    */
   /**
    struct D_symm d_symm = {3, NULL};
    d_symm.data = make_d_symm(d_symm.size);
    fget_d_symm(&d_symm, fopen("input.txt", "r"));
    print_d_symm(&d_symm);
    free(d_symm.data);
    */
    const size_t height = 3;
    const size_t width  = 4;

   int arr[][width] = {{1, 2, 3, 4},
                  {5, 6, 7, 8},
                  {9, 10, 11, 12}};

    print_data((int *)arr, height, width);
}

void print_data(const int *arr, const size_t height, const size_t width)
{
    assert(arr != NULL);

    for(size_t i = 0; i < height; i++)
    {
        for(size_t j = 0; j < width; j++)
        {
            printf("%d\t", *data_elem(arr, i, j, height, width));
        }

        printf("\n");
    }
}

const int *data_elem(const int *arr, const size_t y, const size_t x, const size_t height, const size_t width)
{
    assert(arr != NULL);
    assert(x < width && y < height);

    return arr + y*width + x;
}
