#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

size_t fread_data(FILE *const file, char *data[], const size_t max_str_len, const size_t n_str);

int main(void)
{
    size_t str_len_max = 0;
    size_t str_n       = 0;

    FILE *file = fopen("input.txt", "r");

    fscanf(file, "%zu, %zu\n", &str_n, &str_len_max);
    str_len_max += 2;    //"...\n\0"

    char **arr = (char **)calloc(str_n, sizeof(char *));

    str_n = fread_data(file, arr, str_len_max, str_n);
    fclose(file);

    for(size_t i = 0; i < str_n; i++)
    {
        printf("%s", arr[i]);
    }

    for(size_t i = 0; i < str_n; i++)
    {
        free(arr[i]);
    }
    free(arr);
}

size_t fread_data(FILE *const file, char *data[], const size_t max_str_len, size_t n_str)
{
    assert(file != NULL);
    assert(data != NULL);

    char *buffer = NULL;

    for(size_t i = 0; i < n_str; i++)
    {
        buffer = (char *)calloc(max_str_len, sizeof(char));

        if(buffer == NULL || fgets(buffer, (int)max_str_len, file) == NULL)
        {
            free(buffer);
            printf("error\n");

            return i;
        }

        *(data++) = buffer;
    }

    return n_str;
}
