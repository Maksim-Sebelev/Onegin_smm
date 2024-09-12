#include "file_to_text.h"

char* make_buffer(const char* file_name, int* buffer_len, int* text_str_quant)
{
    char* buffer = NULL;

    FILE* fp = fopen(file_name, "r");

    if (fp == NULL)
    {
        printf("Error: invalid file name\n");
        return NULL;
    }

    struct stat buf = {};
    stat(file_name, &buf);

    if (stat(file_name, &buf) == -1)
    {
        printf("Error: X3\n");
        return NULL;
    }

    *buffer_len = buf.st_size + 1;

    buffer = (char*) calloc(*buffer_len, sizeof(char));
    fread(buffer, sizeof(char*), *buffer_len, fp);


    buffer[*buffer_len] = '\0';

    // printf("\nqqqq\n");
    // printf("%d\n", *text_str_quant);

    *text_str_quant = arr_str_quant(buffer);
    
    // printf("%d\n", *text_str_quant);
    // printf("\nqqqqq\n");

    for (int buffer_i = 0; buffer_i <= *buffer_len; buffer_i++)
    {
        if (buffer[buffer_i] == '\r' || buffer[buffer_i] == '\n')
        {
            buffer[buffer_i] = '\0';
        }
    }

    fclose(fp);

    return buffer;
}



const char** make_text(char* buffer, int text_str_quant, int buffer_len)
{
    const char** text = (const char**) calloc(text_str_quant + 1, sizeof(const char*));
    text[text_str_quant] = NULL;


    int text_i = 0;
    int buffer_i = 0;
    text[text_i++] = &buffer[buffer_i++];
    // printf("AAA    %s\n", text[0]);


    for (buffer_i = 1; buffer_i < buffer_len; buffer_i++)
    {
        if (buffer[buffer_i] == '\0')
        {
            while (buffer[buffer_i] == '\0' && buffer_i < buffer_len)
            {
                buffer_i++;
            }
            text[text_i++] = &buffer[buffer_i];

            // printf("AAA    %s\n", text[text_i - 1]);
        }
    }
    return text;
}


const char** file_to_text(const char* file_name, int* text_str_quant)
{

    int buffer_len = 0;
    char* buffer = make_buffer(file_name, &buffer_len, text_str_quant);    

    const char** text = make_text(buffer, *text_str_quant, buffer_len);

    // printf("\n\ntttt\n\n");

    // printf("TLQ   %d\n\n", *text_str_quant);
    // for (int i = 0; i < *text_str_quant; i++)
    // {
    //     printf("%s\n", text[i]);
    // }
    // printf("%d   \n", *text_str_quant);
    // printf("%s\n", text[14]);
    // printf("\n\ntttt\n\n");

    return text;
}

