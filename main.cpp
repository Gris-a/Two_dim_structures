#include <stdio.h>
#include <assert.h>
#include <string.h>

const size_t MAX_N_STR = 100;
const size_t MAX_STR_LEN = 100;
char buffer[MAX_STR_LEN] = "";

void print_data(const int* arr, const size_t height, const size_t width);
const int *data_elem(const int *arr, const size_t y, const size_t x, const size_t height, const size_t width);
void fread_data(FILE *file, char data[][MAX_STR_LEN]);

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

   char arr[MAX_N_STR][MAX_STR_LEN] = {};
   fread_data(fopen("input.txt", "r"), arr);
   for(size_t i = 0; i < MAX_N_STR; i++)
   {
        printf("%s", arr[i]);
   }

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


void fread_data(FILE *file, char data[][MAX_STR_LEN])
{
    assert(file != NULL);
    assert(data != NULL);

    while(fgets(buffer, MAX_STR_LEN, file) != NULL)
    {
        strncpy(*data, buffer, MAX_STR_LEN);
        data++;
    }
}
const int *data_elem(const int *arr, const size_t y, const size_t x, const size_t height, const size_t width)
{
    assert(arr != NULL);
    assert(x < width && y < height);

    return arr + y*width + x;
}
