#include <sys/stat.h>
#include "str_func.h"

void find_last_letter(const char str[], int* str_i)
{
    while((isalpha(str[*str_i]) == 0) && (str[*str_i] != '\0'))
    {
        (*str_i)--;
    }
    return;
}

size_t count_arr_str_quant(char* arr)
{
    size_t str_quant = 0;
    for (int i = 1; arr[i] != '\0'; i++)
    {   
        if (arr[i] == '\n' && arr[i - 1] != '\n') 
        {
            str_quant++;
        }
    }

    return str_quant;
}

size_t count_real_str_len(char* str, size_t str_len)
{

    while (str[str_len - 1] == '\0')
    {
        str_len--;
    }

    return str_len;
}

void add_str_to_arr(char* arr, size_t arr_i, const char* str)
{
    arr += arr_i;
    while (*str)
    {
        *(arr)++ = *str++;
    }
    *arr = '\n';
    return;
}


