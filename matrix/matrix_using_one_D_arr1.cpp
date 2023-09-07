#include <assert.h>
#include <stdio.h>

//Size of matrix is two first elements of matrix

void print_data(const int* arr);
const int *data_elem(const int *arr, const int y, const int x);

int main(void)
{
   int arr[] = {3, 4,
                1,  2,  3,  4,
                5,  6,  7,  8,
                9, 10, 11, 12};
    print_data(arr);
}

void print_data(const int *arr)
{
    assert(arr != NULL);

    int width  = arr[1];
    int height = arr[0];

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
    assert(arr != NULL);
    assert(x < arr[1] && y < arr[0]);

    return arr + y*arr[1] + x + 2;
}
