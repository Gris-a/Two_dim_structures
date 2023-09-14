#include <assert.h>
#include <stdio.h>

//Size of matrix is external constants

void print_data(const int* arr, const size_t height, const size_t width);
const int *data_elem(const int *arr, const size_t height, const size_t width, const size_t y, const size_t x);

int main(void)
{
    const size_t height = 3;
    const size_t width  = 4;

    int arr[] = {1,  2,  3,  4,
                 5,  6,  7,  8,
                 9, 10, 11, 12};

    print_data(arr, height, width);
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

const int *data_elem(const int *arr, const size_t height, const size_t width, const size_t y, const size_t x)
{
    assert(arr != NULL);
    assert(x < width && y < height);

    return arr + y*width + x;
}
