#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

void fread_data(FILE *file, char *data, size_t max_str_len, size_t max_n_str);

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

   size_t str_len_max = 100;
   size_t str_n_max = 100;

   char *arr = (char *)calloc(str_n_max*(str_len_max + 1), sizeof(char));
   fread_data(fopen("input.txt", "r"), arr, str_len_max, str_n_max);

   for(size_t i = 0; i < str_n_max; i++)
   {
        printf("%s", (arr + i * (str_len_max + 1)));
   }
    free(arr);
}


void fread_data(FILE *file, char *data, size_t max_str_len, size_t max_n_str)
{
    assert(file != NULL);
    assert(data != NULL);
    char * buffer = (char *)calloc(max_str_len+1, sizeof(char));

    while(fgets(buffer, (int)max_str_len, file) != NULL && max_n_str-- > 0)
    {
        strncpy(data, buffer, max_n_str);
        data += max_str_len+1;
    }
    free(buffer);
}
