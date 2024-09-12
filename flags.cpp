#include "flags.h"


const int FLAGS_QUANT = 5;



void (*flags_func[FLAGS_QUANT])(const int, const char**, const char**, const int, int) = 
{
    flags_func[0] = r_red_flags,
    flags_func[1] = b_blue_flags,
    flags_func[2] = g_green_flags,
    flags_func[3] = w_white_flags,
    flags_func[4] = RUS_RUSSIA_flags
};




void Call_Flags(const int argc, const char* argv[], const char* text[], const int size)
{
    if (argc == 1)
    {
        default_no_flags(text, size);
        return;
    }


    for (int argv_i = 1; argv_i < argc; argv_i++)
    {
        for (int flag_i = 0; flag_i < FLAGS_QUANT; flag_i++)
        {
            (flags_func[flag_i])(argc, argv, text, size, argv_i);
        }
    }
}


/**
 * Функция default_no_flags срабатывает если argc = 1 (аргумент функци main()), 
 * то есть когда не поступило ни одного флага.
 * \param text - выводимый массив.
 * \param size - размер массива size.
 */

void default_no_flags(const char* text[], const int size)
{
    print_final_text(text, size);
}


/**
 * Функция r_red_flags окрашивает вывод в красный цвет при вызове флагов -r или --red
 * \param argc - аргумент функции main.
 * \param argv - аргумент функции main.
 * \param text - выводимый массив.
 * \param size - размер массива text.
 * \param argv_o - номер элемента массива argv проверяемый на соотвестcвие флагу.
 */

void r_red_flags(const int argc, const char* argv[], const char* text[], const int size, int argv_i)
{
    if ((strcmp(argv[argv_i], "-r") == 0) || (strcmp(argv[argv_i], "--red") == 0))
    {
        COLOR_PRINT_ALL_TEXT(RED, text, size);
    }
}



void b_blue_flags(const int argc, const char* argv[], const char* text[], const int size, int argv_i)
{
    if ((strcmp(argv[argv_i], "-b") == 0) || (strcmp(argv[argv_i], "--blue") == 0))
    {
        COLOR_PRINT_ALL_TEXT(BLUE, text, size);
    }
}



void g_green_flags(const int argc, const char* argv[], const char* text[], const int size, int argv_i)
{
    if ((strcmp(argv[argv_i], "-g") == 0) || (strcmp(argv[argv_i], "--green") == 0))
    {
        COLOR_PRINT_ALL_TEXT(GREEN, text, size);
    }
}


void w_white_flags(const int argc, const char* argv[], const char* text[], const int size, int argv_i)
{
    if ((strcmp(argv[argv_i], "-w") == 0) || (strcmp(argv[argv_i], "--white") == 0))
    {
        COLOR_PRINT_ALL_TEXT(WHITE, text, size);
        
    }
}



void RUS_RUSSIA_flags(const int argc, const char* argv[], const char* text[], const int size, int argv_i)
{
    if ((strcmp(argv[argv_i], "-RUS") == 0) || (strcmp(argv[argv_i], "--RUSSIA") == 0))
    {
        for (int i = 0; text[i] != '\0'; i++)
        {
            if (i%9 == 0 || i%9 == 1 || i%9 == 2)
            {
                COLOR_PRINT_ONE_STR(WHITE, text[i]);
            }

            else if (i%9 == 3 || i%9 == 4 || i%9 == 5)
            {
                COLOR_PRINT_ONE_STR(BLUE, text[i]);
            }

            else if (i%9 == 6 || i%9 == 7 || i%9 == 8)
            {
                COLOR_PRINT_ONE_STR(RED, text[i]);
            }
        }
    }
}

