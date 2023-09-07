#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../colors.h"

//using real two dimensional array

size_t fread_text(FILE *file, char *text);

const size_t MAX_N_STR   =  3;
const size_t MAX_STR_LEN = 32;
char buffer[MAX_STR_LEN] = "";

int main(void)
{
    char text[MAX_N_STR][MAX_STR_LEN] = {};

    FILE *file = fopen("input.txt", "r");
    if(file == NULL)
    {
        printf(color_red("can not open file.\n"));

        return EXIT_FAILURE;
    }

    size_t n_str = fread_text(file, (char *)text);
    fclose(file);

    for(size_t i = 0; i < n_str; i++)
    {
        printf("%s", text[i]);
    }

    return EXIT_SUCCESS;
}

size_t fread_text(FILE *file, char *text)
{
    assert(text != NULL);
    if(file == NULL)
    {
        printf(color_red("can not open file.\n"));

        return 0;
    }

    for(size_t i = 0; i < MAX_N_STR; i++)
    {
        if(fgets(buffer, MAX_STR_LEN, file) == NULL)
        {
            return i;
        }

        strncpy(text, buffer, MAX_STR_LEN);
        text += MAX_STR_LEN;
    }

    return MAX_N_STR;
}
