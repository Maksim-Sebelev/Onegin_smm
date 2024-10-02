#include "write_text_in_file.h"


//----------------------------------------------------------------------------------------------------------------------------------

char* write_text_in_buffer(struct Text_param text_par)
{
    assert(text_par.text != NULL);
    assert(text_par.text_elem_size > 0);
    assert(text_par.text_len >= 0);
    assert(text_par.text_lines_quant >= 0);

    char* buffer = NULL;
    buffer = (char*) calloc(text_par.text_len + 1, sizeof(char));

    assert(buffer != NULL);

    buffer[text_par.text_len] = '\0';

    size_t buffer_i = 0;
    size_t text_i = 0;
    size_t text_lines_quant_copy = text_par.text_lines_quant;

    while ((text_i < text_lines_quant_copy) && (buffer_i < text_par.text_len))
    {
        assert(text_i < text_lines_quant_copy);
        assert(buffer_i < text_par.text_len);

        add_str_to_arr(buffer, buffer_i, text_par.text[text_i].str_begin_ptr);
        buffer_i += strlen(text_par.text[text_i].str_begin_ptr) + 1;
        text_i++;
    }

    assert(buffer != NULL);
    return buffer;
}

//----------------------------------------------------------------------------------------------------------------------------------

void write_text_in_file(struct Text_param text_par, struct Inp_Out_files file)
{
    char* buffer = NULL;
    buffer = write_text_in_buffer(text_par);
    assert(buffer != NULL);

    size_t real_buffer_len = 0;
    real_buffer_len = count_real_str_len(buffer, text_par.text_len + 1);
    assert(real_buffer_len >= 0);

    FILE* fp = fopen(file.output_file, "w");
    if (fp == NULL)
    {
        printf("Error: invalid output file name\n");
        return;
    }
    
    fwrite(buffer, real_buffer_len, sizeof(char), fp);

    free(buffer);
    buffer = NULL;
    return;
}

//----------------------------------------------------------------------------------------------------------------------------------

void make_final_file(struct Text_param text_par, struct Inp_Out_files file)
{

    text_par.text = read_text_from_file(&text_par, file);
    assert(text_par.text != NULL);
    assert(text_par.text_elem_size > 0);
    assert(text_par.text_len >= 0);
    assert(text_par.text_lines_quant >= 0);


    text_sort(&text_par);
    assert(text_par.text != NULL);
    assert(text_par.text_elem_size > 0);
    assert(text_par.text_len >= 0);
    assert(text_par.text_lines_quant >= 0);

    write_text_in_file(text_par, file);

    // free(text_par.text);
    // text_par.text = NULL;
    return;
}

//----------------------------------------------------------------------------------------------------------------------------------

void make_final_text(struct Text_param* text_par, struct Inp_Out_files file)
{
    text_par->text = read_text_from_file(text_par, file);
    assert(text_par->text != NULL);
    assert(text_par->text_elem_size > 0);
    assert(text_par->text_len >= 0);
    assert(text_par->text_lines_quant >= 0);

    text_sort(text_par);
    assert(text_par->text != NULL);
    assert(text_par->text_elem_size > 0);
    assert(text_par->text_len >= 0);
    assert(text_par->text_lines_quant >= 0);
    
    return;
}

//----------------------------------------------------------------------------------------------------------------------------------
