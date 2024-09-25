#include "file_text.h"

char* read_buffer_from_file(struct Text_param* text_par, struct Inp_Out_files file)
{
    FILE* fp = fopen(file.input_file, "r");
    if (fp == NULL)
    {
        COLOR_PRINT_ONE_STR(RED, "Error: invalid file name\n");
        return NULL;
    }

    text_par->text_len = count_file_len2(file.input_file);

    char* buffer = NULL;
    buffer = (char*) calloc(text_par->text_len + 1, sizeof(char));
    assert(buffer != NULL);

    fread(buffer, sizeof(char), text_par->text_len + 1, fp);
    assert(buffer != NULL);
    fclose(fp);

    buffer[text_par->text_len] = '\0';

    text_par->text_lines_quant = count_arr_str_quant(buffer);
    assert(text_par->text_lines_quant > 0);

    for (size_t buffer_i = 0; buffer_i <= text_par->text_len; buffer_i++)
    {
        assert(buffer_i >= 0);
        assert(buffer_i < text_par->text_len + 1);

        if (buffer[buffer_i] == '\r' || buffer[buffer_i] == '\n')
        {
            buffer[buffer_i] = '\0';
        }
    }

    assert(buffer != NULL);
    return buffer;
}



struct Line* read_text_from_buffer(char* buffer, struct Text_param text_par)
{
    assert(buffer != NULL);

    struct Line* text = NULL;
    text = (struct Line*) calloc(text_par.text_lines_quant + 1, sizeof(struct Line));
    assert(text != NULL);

    text[text_par.text_lines_quant].str_begin_ptr = NULL;
    text[text_par.text_lines_quant].str_len = 0;

    size_t text_i = 0;
    size_t buffer_i = 0;
    text[text_i].str_begin_ptr = &buffer[buffer_i];
    text[text_i++].str_len = strlen(&buffer[buffer_i]);

    for (buffer_i = 1; buffer_i < text_par.text_len; buffer_i++)
    {
        assert(buffer_i < text_par.text_len);

        if (buffer[buffer_i] == '\0')
        {
            while (buffer[buffer_i] == '\0' && buffer_i < text_par.text_len)
            {
                buffer_i++;
            }
            assert(buffer_i < text_par.text_len + 1);
            assert(text_i < text_par.text_lines_quant + 1);
            assert(buffer_i >= 0);
            assert(text_i >= 0);
            text[text_i].str_begin_ptr = &buffer[buffer_i];
            text[text_i++].str_len = strlen(&buffer[buffer_i]);
        }
    }

    assert(text_par.text_elem_size > 0);
    assert(text_par.text_len >= 0);
    assert(text_par.text_lines_quant >= 0);

    return text;
}

struct Line* read_text_from_file(struct Text_param* text_par, struct Inp_Out_files file)
{
    char* buffer = NULL;
    buffer = read_buffer_from_file(text_par, file);
    assert(buffer != NULL);

    struct Line* text = NULL;
    text = read_text_from_buffer(buffer, *text_par);

    assert(text_par->text_elem_size > 0);
    assert(text_par->text_len >= 0);
    assert(text_par->text_lines_quant >= 0);

    return text;
}

