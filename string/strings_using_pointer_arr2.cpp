#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../colors.h"

//using pointer array strdup

char **generate_text(FILE *file, size_t *str_len_max, size_t *str_n_max);

size_t fread_text(FILE *file, char *text[], const size_t max_str_len, const size_t str_n_max);
void print_text(char **text, const size_t str_n);

int main(void)
{
    size_t str_len_max = 0;
    size_t str_n_max   = 0;

    FILE *file = fopen("input.txt", "r");
    if(file == NULL)
    {
        printf(color_red("can not open file.\n"));

        return EXIT_FAILURE;
    }

    char **text = generate_text(file, &str_len_max, &str_n_max);
    if(text == NULL)
    {
        printf(color_red("No memory?\n"));

        return EXIT_FAILURE;
    }

    size_t str_n = fread_text(file, text, str_len_max, str_n_max);
    fclose(file);

    print_text(text, str_n);

    for(size_t i = 0; i < str_n; i++)
    {
        free(text[i]);
    }
    free(text);

    return EXIT_SUCCESS;
}

char **generate_text(FILE *file, size_t *str_len_max, size_t *str_n_max)
{
    assert(str_len_max != NULL);
    assert(str_n_max   != NULL);
    if(file == NULL)
    {
        printf(color_red("can not open file.\n"));

        return NULL;
    }

    fscanf(file, "%zu, %zu\n", str_n_max, str_len_max);
    *str_len_max += 2;    //"...\n\0"

    return (char **)calloc(*str_n_max, sizeof(char *));
}

size_t fread_text(FILE *file, char *text[], const size_t max_str_len, const size_t str_n_max)
{
    assert(text != NULL);
    if(file == NULL)
    {
        printf(color_red("can not open file.\n"));

        return 0;
    }

    char *buffer = (char *)calloc(max_str_len, sizeof(char));;
    if(buffer == NULL)
    {
        printf(color_red("No memory?\n"));

        return 0;
    }

    size_t i = 0;

    while(true)
    {
        if(i == str_n_max || fgets(buffer, (int)max_str_len, file) == NULL)
            break;

        *(text) = strdup(buffer);
        if(*(text++) == NULL)
        {
            printf(color_red("No memory?\n"));

            break;
        }

        i++;
    }

    free(buffer);

    return i;
}

void print_text(char **text, const size_t str_n)
{
    assert(text != NULL);

    for(size_t i = 0; i < str_n; i++)
    {
        printf("%s", text[i]);
    }
}
