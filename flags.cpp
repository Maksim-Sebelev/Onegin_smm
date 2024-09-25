#include "flags.h"

const size_t FLAGS_QUANT = 8;

typedef Flag_error_type (*Flag_func_type)(const int, const char**, size_t, struct Text_param*, struct Inp_Out_files*);

const Flag_func_type flags_func[FLAGS_QUANT] = 
{
    red_flag,
    blue_flag,
    green_flag,
    white_flag,
    RUSSIA_flag,
    ChangeInputFile_flag,
    ChangeOuputFile_flag,
    FindRT_flag
};


void Call_Flags(const int argc, const char* argv[], struct Text_param* text_par, struct Inp_Out_files* file)
{
    if (argc == 1)
    {
        write_text_in_file_when_no_flags(*text_par, *file);
        return;
    }

    for (size_t argv_i = 1; argv_i < (size_t)argc; argv_i++)
    {
        for (size_t flag_i = 0; flag_i < FLAGS_QUANT; flag_i++)
        {
            // print_flags_error((flags_func[flag_i])(argc, argv, argv_i, &text_par, &file, &was_cmd_output_flags_used));
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


enum Flag_error_type ChangeInputFile_flag(const int argc, const char* argv[], size_t argv_i, struct Text_param* text_par, struct Inp_Out_files* file)
{
    if ((strcmp(argv[argv_i], "-cif") == 0) || (strcmp(argv[argv_i], "--ChangeInputFile") == 0))
    {
        if ((size_t)argc < argv_i)
        {
            return NO_INPUT;
        }
        file->input_file = argv[argv_i + 1];
        text_par->text_len = count_file_len2(file->input_file);
    }

    return NO_ERR;
}


enum Flag_error_type ChangeOuputFile_flag(const int argc, const char* argv[], size_t argv_i, struct Text_param* text_par, struct Inp_Out_files* file)
{
    if ((strcmp(argv[argv_i], "-cof") == 0) || (strcmp(argv[argv_i], "--ChangeOuputFile") == 0))
    {
        if ((size_t)argc < argv_i)
        {
            return NO_INPUT;
        }
        file->output_file = argv[argv_i + 1];
    }
    return NO_ERR;
}



enum Flag_error_type red_flag(const int argc, const char* argv[], size_t argv_i, struct Text_param* text_par, struct Inp_Out_files* file)
{
    if ((strcmp(argv[argv_i], "-r") == 0) || (strcmp(argv[argv_i], "--red") == 0))
    {
        make_final_text(text_par, *file);
        COLOR_PRINT_ALL_TEXT(RED, *text_par);
    }
    return NO_ERR;
}



enum Flag_error_type blue_flag(const int argc, const char* argv[], size_t argv_i, struct Text_param* text_par, struct Inp_Out_files* file)
{
    if ((strcmp(argv[argv_i], "-b") == 0) || (strcmp(argv[argv_i], "--blue") == 0))
    {
        make_final_text(text_par, *file);
        COLOR_PRINT_ALL_TEXT(BLUE, *text_par);
    }
    return NO_ERR;
}



enum Flag_error_type green_flag(const int argc, const char* argv[], size_t argv_i, struct Text_param* text_par, struct Inp_Out_files* file)
{
    if ((strcmp(argv[argv_i], "-g") == 0) || (strcmp(argv[argv_i], "--green") == 0))
    {
        printf("green\n");
        make_final_text(text_par, *file);
        printf("green 2\n");
        COLOR_PRINT_ALL_TEXT(GREEN, *text_par);
    }
    return NO_ERR;
}


enum Flag_error_type white_flag(const int argc, const char* argv[], size_t argv_i, struct Text_param* text_par, struct Inp_Out_files* file)
{
    if ((strcmp(argv[argv_i], "-w") == 0) || (strcmp(argv[argv_i], "--white") == 0))
    {
        make_final_text(text_par, *file);
        COLOR_PRINT_ALL_TEXT(WHITE, *text_par);
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
                COLOR_PRINT_ONE_STR(WHITE, text_par->text[text_i].str_begin_ptr);
            }

            else if (3 <= text_i_mod_9 && text_i_mod_9 <= 5)
            {
                COLOR_PRINT_ONE_STR(BLUE, text_par->text[text_i].str_begin_ptr);
            }

            else if (6 <= text_i_mod_9 && text_i_mod_9 <= 8)
            {
                COLOR_PRINT_ONE_STR(RED, text_par->text[text_i].str_begin_ptr);
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
