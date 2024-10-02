#include "sort.h"
#include "text.h"

int back_comp_str(const void* const str1, const void* const str2)
{
    struct Line str1_copy = *(struct Line*)str1;
    struct Line str2_copy = *(struct Line*)str2;

    int str1_i = 0;
    int str2_i = 0;
    str1_i = str1_copy.str_len;
    str2_i = str2_copy.str_len;

    do
    {
        find_last_letter(--str1_copy.str_begin_ptr, &str1_i);
        find_last_letter(--str2_copy.str_begin_ptr, &str2_i);
    } 
    while((tolower(str1_copy.str_begin_ptr[str1_i]) == tolower(str2_copy.str_begin_ptr[str2_i])) && (str1_i >= 0) && (str2_i >= 0));
    
    return tolower(str1_copy.str_begin_ptr[str1_i]) - tolower(str2_copy.str_begin_ptr[str2_i]);
}


void quick_sort(void* arr, size_t arr_size, size_t size_arr_elem, int compare(const void* const, const void* const))
{
    assert((char*)arr != NULL);
    assert(arr_size >= 0);
    assert(size_arr_elem > 0);
    if (arr_size <= 1)
    {
        return;
    }

    size_t right = arr_size - 1;
    size_t ref = 0;
    
    while (ref < right)
    {
        while (compare((char*)arr + (int)(size_arr_elem * ref), (char*)arr + (int)(size_arr_elem * right)) < 0)
        {
            right--;
        }

        if (ref < right)
        {
            swap(((char*)arr + (int)(size_arr_elem * ref)), ((char*)arr + (int)(size_arr_elem * right)), size_arr_elem);
            ref++;
            swap(((char*)arr + (int)(size_arr_elem * ref)), ((char*)arr + (int)(size_arr_elem * right)), size_arr_elem);
        }
    }

    assert((char*)arr != NULL);
    assert(ref >= 0);

    assert((char*)arr != NULL);
    assert(arr_size - ref - 1 >= 0);

    assert(size_arr_elem > 0);

    quick_sort((char*)arr, ref, size_arr_elem, compare);
    quick_sort((char*)arr + (int)(size_arr_elem * (ref + 1)), arr_size - ref - 1, size_arr_elem, compare);
}


void text_sort(struct Text_param* text_par)
{
    assert(text_par->text != NULL);
    assert(text_par->text_elem_size > 0);
    assert(text_par->text_len >= 0);
    assert(text_par->text_lines_quant >= 0);
    quick_sort(text_par->text, text_par->text_lines_quant, text_par->text_elem_size, back_comp_str);
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
    return;
}

void swap(void* p1, void* p2, size_t size_type)
{
    swap_helper(p1, p2, &size_type, sizeof(uint64_t));
    swap_helper(p1, p2, &size_type, sizeof(uint32_t));
    swap_helper(p1, p2, &size_type, sizeof(uint16_t));
    swap_helper(p1, p2, &size_type, sizeof(uint8_t));
    return;
}