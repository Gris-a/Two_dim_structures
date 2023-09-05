#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

size_t fread_data(FILE *const file, char *data);
char *str_adr(char *const data, const size_t n_str);

const size_t str_len_max = 32;
const size_t str_n_max    = 3;

int main(void)
{

    FILE *file = fopen("input.txt", "r");

    char *arr = (char *)calloc(str_n_max * str_len_max, sizeof(char));

    size_t number_of_str = fread_data(file, arr);
    fclose(file);

    for(size_t i = 0; i < number_of_str; i++)
    {
        printf("%s", str_adr(arr, i));
    }

    free(arr);
}

size_t fread_data(FILE *const file, char *data)
{
    assert(file != NULL);
    assert(data != NULL);

    char *buffer = (char *)calloc(str_len_max, sizeof(char));
    if(buffer == NULL)
    {
        printf("No memory?\n");
        return 0;
    }

    for(size_t i = 0; i < str_n_max; i++)
    {
        if(fgets(buffer, (int)str_len_max, file) == NULL)
        {
            free(buffer);
            printf("error\n");

            return i;
        }

        strcpy(data, buffer);
        data += str_len_max;
    }
    free(buffer);

    return str_n_max;
}

char *str_adr(char *const data, const size_t n_str)
{
    assert(data != NULL);

    return data + n_str * str_len_max;
}
