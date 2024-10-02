#ifndef TEXT_H
#define TEXT_H

#include <stdio.h>

struct Line
{
    const char* str_begin_ptr = NULL;
    size_t str_len = 0;
};


struct Text_param 
{
    size_t text_lines_quant = 0;
    size_t text_len = 0;
    size_t text_elem_size = sizeof(struct Line);
    struct Line* text = {};
};


struct Inp_Out_files
{
    const char* input_file = "text.txt";
    const char* output_file = "sort_text.txt";
    const char* clean_file = "clean_text.txt";
};


#endif
