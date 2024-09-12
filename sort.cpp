#include "sort.h"
#include "color_output.h"



int comp_for_str(const char* str1, const char* str2)
{
    int str1_i = 0, str2_i = 0;

    while(str1[str1_i] != EOF && str1[str1_i] != '\0' && str1[str1_i] != '\r' && str1[str1_i] != '\n')
    {
        str1_i++;
    } 

    while(str2[str2_i] != EOF && str2[str2_i] != '\0' && str2[str2_i] != '\r' && str2[str2_i] != '\n')
    {
        str2_i++;
    }


    do
    {
        found_letter(--str1, &str1_i);
        found_letter(--str2, &str2_i);
    } 
    while((tolower(str1[str1_i]) == tolower(str2[str2_i])) && (str1_i >= 0) && (str2_i >= 0));
    
    return tolower(str2[str2_i]) - tolower(str1[str1_i]);
}



// сортировка пузырьком
void text_sort(const char** text, const int size)
{   
    for (int max_i = size; max_i > 0; max_i--)
    {
        for (int i = 1; i < max_i; i++)
        {
            if (comp_for_str(text[i], text[i - 1]) > 0)
            {
                my_swap(&text[i], &text[i - 1]);
            }
        }
    }
}


void quick_text_sort(const char* text[], int first_sort_elem, int last_sort_elem)
{
    if (last_sort_elem - first_sort_elem == 1)
    {
        return;
    }   

    char* left_text[last_sort_elem - first_sort_elem];
    char* right_text[last_sort_elem - first_sort_elem];

    int ref_elem = (first_sort_elem + last_sort_elem) / 2;

    for (int i = first_sort_elem; i < last_sort_elem; i++)
    {
        if (comp_for_str(text[ref_elem], text[i]) < 0)
        {
            // my_swap(&text[ref_elem], &text[i]);
            left_text[i] = (char*)text[i];
        }
        else
        {
            right_text[i] = (char*)text[i];
        }
    }
    quick_text_sort((const char**)left_text, first_sort_elem, ref_elem);
    quick_text_sort((const char**)right_text, ref_elem, last_sort_elem);
}


// void text_sort(const char* text[], const int size)
// {
//     quick_text_sort(text, 0, size);
// }

//рабочий вариант !!! но без учета не букв

// // компаратор возращает 0 если строки равны, полож число если первая больше второй и отриц если наоборот

// int comp_for_str(const char str1[], const char str2[])
// {
//     while(str1[++str1_i]);
//     while(str2[++str2_i]);


//     while((tolower(str1[str1_i]) == tolower(str2[str2_i])) && (str1_i >= 0) && (str2_i >= 0))
//     {
//         str1_i--;
//         str2_i--;
//     }

//     // printf("%s XYJ %c    %s XYJ %c\n", str1, str1[str1_i], str2, str2[str2_i]);

//     return tolower(str2[str2_i]) - tolower(str1[str1_i]);
// }


