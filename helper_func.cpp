#include "helper_func.h"


void my_swap(const char** s1, const char** s2)
{   
    const char* temp = 0;
    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
    return;
}


void found_letter(const char str[], int* str_i)
{
    while((isalpha(str[*str_i]) == 0) && (str[*str_i] != '\0'))
    {
        (*str_i)--;
    }
    return;
}




int arr_str_quant(char* arr)
{
    int str_quant = 0;
    for (int i = 1; arr[i] != '\0'; i++)
    {   
        if (arr[i] == '\n' && arr[i - 1] != '\n') 
        {

            str_quant++;
        }
    }

    return str_quant;
}
















