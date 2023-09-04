#include <stdlib.h>
#include <stdio.h>

#include "d_symm.h"

int main(void)
{
    /**
    struct Matrix matrix = {2, 2, NULL};
    matrix.matrix = make_matrix(matrix.height, matrix.width);
    fget_matrix (&matrix, file);
    print_matrix(&matrix);

    free(matrix.matrix);
    */

    struct D_symm d_symm = {3, NULL};
    d_symm.data = make_d_symm(d_symm.size);
    fget_d_symm(&d_symm, fopen("input.txt", "r"));
    print_d_symm(&d_symm);
    free(d_symm.data);
}
