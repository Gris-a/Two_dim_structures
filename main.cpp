#include <stdio.h>
#include <stdlib.h>

#include "matrix/diag_symm.h"

int clean_buff(void);

const size_t SIZE = 3;

int main(void)
{
    struct D_symm diag_matrix = {SIZE, make_diag_symm(SIZE)};
    if(diag_matrix.data == NULL)
    {
        printf("Can not allocate memory for matrix\n");

        return EXIT_FAILURE;
    }

    size_t y  = 0;
    size_t x  = 0;
    int value = 0;

    printf("размер матрицы: %zux%zu\n", SIZE, SIZE);
    while(true)
    {
        printf("Введите расположение числа в матрице: ");

        if(scanf("%zu %zu", &y, &x) != 2)
        {
            printf("Некорректный ввод.\n"
                   "Нужны 2 числа.\n");
            clean_buff();

            continue;
        }

        if(y >= SIZE || x >= SIZE)
        {
            printf("Некорректный ввод.\n"
                   "В матрице %zux%zu нет числа с координатами %zu и %zu\n", SIZE, SIZE,
                                                                             y,    x);
            getchar();

            continue;
        }

        printf("Введите значение: ");

        scanf("%d", &value);
        set_elem(&diag_matrix, y, x, value);

        printf("Хотите ввести ещё?[y/n]: ");

        clean_buff();

        if(getchar() == (int)'y')
        {
            continue;
        }

        break;
    }

    print_diag_symm(&diag_matrix);

    free(diag_matrix.data);

    return EXIT_SUCCESS;
}

int clean_buff(void)
{
    int ch = 0;

    while(ch != '\n' && ch != EOF)
    {
        ch = getchar();
    }

    return ch;
}
