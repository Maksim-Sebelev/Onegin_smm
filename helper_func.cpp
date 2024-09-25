#include <sys/stat.h>
#include "helper_func.h"


int find_str_end(const char* str)
{
    int str_i = 0;
    while(str[str_i] != '\0' && str[str_i] != '\r' && str[str_i] != '\n')
    {
        str_i++;
    } 

    return str_i;
}




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

size_t count_file_len(const char* file_name)
{
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("Error: invalid file name\n");
    }

    size_t file_elem_quant = 0;

    while(fgetc(fp) != EOF)
    {
        file_elem_quant++;
    }
    return file_elem_quant;
}

size_t count_file_len2(const char* file_name)
{
    struct stat buf = {};
    stat(file_name, &buf);
    return buf.st_size;
}


void swap_helper(void* p1, void* p2, size_t* size_type, size_t size_swap_type)
{
    while (*size_type >= size_swap_type)
    {
        char* buffer[size_swap_type];
        memcpy(buffer, p1, size_swap_type);
        memcpy(p1, p2, size_swap_type);
        memcpy(p2, buffer, size_swap_type);
        *size_type -= size_swap_type;
    }
}


void swap(void* p1, void* p2, size_t size_type)
{
    swap_helper(p1, p2, &size_type, sizeof(uint64_t));
    swap_helper(p1, p2, &size_type, sizeof(uint32_t));
    swap_helper(p1, p2, &size_type, sizeof(uint16_t));
    swap_helper(p1, p2, &size_type, sizeof(uint8_t));
    return;
}
