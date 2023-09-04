#include <stdio.h>
#include <assert.h>

void print_data(const int* arr);
const int *data_elem(const int *arr, const int y, const int x);

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
   int arr[] = {3, 4,
                1, 2, 3, 4,
                5, 6, 7, 8,
                9, 10, 11, 12};
    print_data(&arr[2]);
}

void print_data(const int *arr)
{
    assert(arr != NULL);

    int width = arr[-1];
    int height = arr[-2];

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            printf("%d\t", *data_elem(arr, i, j));
        }

        printf("\n");
    }
}

const int *data_elem(const int *arr, const int y, const int x)
{
    return arr + y*arr[-1] + x;
}
