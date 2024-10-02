#include <stdio.h>
#include "flags.h"
#include "str_func.h"
#include "text.h"
#include "color_output.h"
#include "write_text_in_file.h"
#include "text_print.h"


const size_t FLAGS_QUANT = 5;

typedef Flag_error_type (*Flag_func_type)(const int, const char**, size_t, struct Text_param*, struct Inp_Out_files*);

const Flag_func_type flags_func[FLAGS_QUANT] = 
{
    print_flag,
    change_input_file_flag,
    change_ouput_file_flag,
    FindRT_flag,
    RUSSIA_flag,
};


void call_flags(const int argc, const char* argv[], struct Text_param* text_par, struct Inp_Out_files* file)
{

    for (size_t argv_i = 1; argv_i < (size_t)argc; argv_i++)
    {
        for (size_t flag_i = 0; flag_i < FLAGS_QUANT; flag_i++)
        {
            (flags_func[flag_i])(argc, argv, argv_i, text_par, file);
        }
    }
    return;
}

 
/**
 * Функция default_no_flags срабатывает если argc = 1 (аргумент функци main()), 
 * то есть когда не поступило ни одного флага.
 * \param text - выводимый массив.
 * \param size - размер массива size.
 */

enum Flag_error_type write_text_in_file_when_no_flags(struct Text_param text_par, struct Inp_Out_files file)
{
    make_final_file(text_par, file);
    return NO_ERR;
}


enum Flag_error_type change_input_file_flag(const int argc, const char* argv[], size_t argv_i, struct Text_param* text_par, struct Inp_Out_files* file)
{
    if ((strcmp(argv[argv_i], "-cif") == 0) || (strcmp(argv[argv_i], "--change_input_file") == 0))
    {
        if ((size_t)argc < argv_i)
        {
            return NO_INPUT;
        }
        file->input_file = argv[argv_i + 1];
        text_par->text_len = count_file_len(file->input_file);
    }

    return NO_ERR;
}


enum Flag_error_type change_ouput_file_flag(const int argc, const char* argv[], size_t argv_i, struct Text_param* text_par, struct Inp_Out_files* file)
{
    if ((strcmp(argv[argv_i], "-cof") == 0) || (strcmp(argv[argv_i], "--change_ouput-file") == 0))
    {
        if ((size_t)argc < argv_i)
        {
            return NO_INPUT;
        }
        file->output_file = argv[argv_i + 1];
    }
    return NO_ERR;
}


enum Flag_error_type print_flag(const int argc, const char* argv[], size_t argv_i, struct Text_param* text_par, struct Inp_Out_files* file)
{
    if ((strcmp(argv[argv_i], "-p") == 0) || (strcmp(argv[argv_i], "--print") == 0))
    {
        make_final_text(text_par, *file);
        print_text(*text_par);
    }
    return NO_ERR;
}



enum Flag_error_type RUSSIA_flag(const int argc, const char* argv[], size_t argv_i, struct Text_param* text_par, struct Inp_Out_files* file)
{
    if ((strcmp(argv[argv_i], "-RUS") == 0) || (strcmp(argv[argv_i], "--RUSSIA") == 0))
    {
        make_final_text(text_par, *file);
        for (size_t text_i = 0; text_i < text_par->text_lines_quant; text_i++)
        {
            size_t text_i_mod_9 = 0;
            text_i_mod_9 = text_i % 9;

            if (0 <= text_i_mod_9 && text_i_mod_9 <= 2)
            {
                COLOR_PRINT(WHITE, "%s\n", text_par->text[text_i].str_begin_ptr);
            }

            else if (3 <= text_i_mod_9 && text_i_mod_9 <= 5)
            {
                COLOR_PRINT(BLUE, "%s\n", text_par->text[text_i].str_begin_ptr);
            }

            else if (6 <= text_i_mod_9 && text_i_mod_9 <= 8)
            {
                COLOR_PRINT(RED, "%s\n", text_par->text[text_i].str_begin_ptr);
                if (text_i_mod_9 == 8)
                {
                    printf("\n");
                }
            }
        }
    }

    return NO_ERR;
}


enum Flag_error_type FindRT_flag(const int argc, const char* argv[], size_t argv_i, struct Text_param* text_par, struct Inp_Out_files* file)
{
    if ((strcmp(argv[argv_i], "-RT") == 0) || (strcmp(argv[argv_i], "--FindRT") == 0))
    {
        text_par->text = read_text_from_file(text_par, *file);
        for (size_t text_i = 0; text_i < text_par->text_lines_quant; text_i++)
        {
            print_rt_str(text_par->text[text_i].str_begin_ptr, text_i);            
        }
    }
    return NO_ERR;
}
