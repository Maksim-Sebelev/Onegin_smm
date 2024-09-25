#include "color_output.h"

void print_final_text(struct Text_param text_par)
{
    assert(text_par.text != NULL);
    assert(text_par.text_elem_size > 0);
    assert(text_par.text_len >= 0);
    assert(text_par.text_lines_quant >= 0);

    for (size_t text_i = 0; text_i < text_par.text_lines_quant; text_i++)
    {
        printf("%s\n", text_par.text[text_i].str_begin_ptr);
    }
    return;
}

void print_rt_str(const char* str, size_t str_num)
{
    if (strstr(str, "RT") == NULL && strstr(str, "rt") == NULL && strstr(str, "Rt") == NULL && strstr(str, "rT") == NULL)
    {
        return;
    }

    printf("[%1u] ", str_num);
    char* rt = NULL;
    while ((rt = strstr(str, "RT")) || (rt = strstr(str, "rt")) || (rt = strstr(str, "Rt")) || (rt = strstr(str, "rT")))
    {
        while (str < rt)
        {
            printf("%c", *str);
            str++;
        }
        printf(RED "%c" RES, toupper(*str));
        str++;
        printf(RED "%c" RES, toupper(*str));
        str++;
    }
   
    while (*str)
    {
        printf("%c", *str);
        str++;
    }
    printf("\n");
    return;
}

