#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../colors.h"

//using calloc so can have not presetted str_len_max and n_max

char *generate_text(FILE *file, size_t *str_len_max, size_t *str_n_max);

size_t fread_data(FILE *file, char *data, const size_t str_len_max, const size_t str_n_max);
void print_data(char *arr, const size_t n_str, const size_t str_len_max, const size_t str_n_max);

char *str_adr(char *data, const size_t str_len_max, const size_t str_n_max, const size_t n_str);

int main(void)
{
    size_t str_len_max = 0;
    size_t str_n_max   = 0;

    FILE *file = fopen("input.txt", "r");
    if(file == NULL)
    {
        printf(color_red("Can not open file.\n"));

        return EXIT_FAILURE;
    }

    char *arr = generate_text(file, &str_len_max, &str_n_max);
    if(arr == NULL)
    {
        printf(color_red("Can not allocate memory.\n"));

        return EXIT_FAILURE;
    }

    size_t n_str = fread_data(file, arr, str_len_max, str_n_max);
    fclose(file);

    print_data(arr, n_str, str_len_max, str_n_max);

    free(arr);

    return EXIT_SUCCESS;
}

char *generate_text(FILE *file, size_t *str_len_max, size_t *str_n_max)
{
    assert(str_len_max != NULL);
    assert(str_n_max   != NULL);
    if(file == NULL)
    {
        printf(color_red("Can not open file.\n"));

        return NULL;
    }

    fscanf(file, "%zu, %zu\n", str_n_max, str_len_max);
    *str_len_max += 2;    //"...\n\0"

    return (char *)calloc((*str_n_max) * (*str_len_max), sizeof(char));
}

size_t fread_data(FILE *file, char *data, const size_t str_len_max, const size_t str_n_max)
{
    assert(data != NULL);
    if(file == NULL)
    {
        printf(color_red("Can not open file.\n"));

        return 0;
    }

    char *buffer = (char *)calloc(str_len_max, sizeof(char));
    if(buffer == NULL)
    {
        printf(color_red("Can not allocate memory.\n"));
        return 0;
    }

    size_t i = 0;

    while(true)
    {
        if(i == str_n_max || fgets(buffer, (int)str_len_max, file) == NULL)
            break;

        strncpy(data, buffer, str_len_max);

        data += str_len_max;
        i++;
    }

    free(buffer);

    return i;
}

void print_data(char *arr, const size_t n_str, const size_t str_len_max, const size_t str_n_max)
{
    assert(arr != NULL);

    for(size_t i = 0; i < n_str; i++)
    {
        printf("%s", str_adr(arr, str_len_max, str_n_max, i));
    }
}

char *str_adr(char *data, const size_t str_len_max, const size_t str_n_max, const size_t n_str)
{
    assert(data != NULL);
    assert(n_str < str_n_max);

    return data + n_str * str_len_max;
}
