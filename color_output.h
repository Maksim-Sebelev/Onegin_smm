#ifndef COLOR_OUTPUT_H
#define OCLOR_OUTPUT_H

#include <stdio.h>
#include <assert.h>
#include "helper_func.h"

#define ANSI_COLOR_WHITE  "\e[0;37m"
#define ANSI_COLOR_BLUE   "\e[0;34m"
#define ANSI_COLOR_RED    "\x1b[31m"
#define ANSI_COLOR_GREEN  "\x1b[32m"
#define ANSI_COLOR_RESET  "\x1b[0m"


#define WHITE ANSI_COLOR_WHITE
#define BLUE ANSI_COLOR_BLUE
#define RED ANSI_COLOR_RED
#define GREEN ANSI_COLOR_GREEN
#define RES ANSI_COLOR_RESET



/**
 * Функция print_final_text нужна для вывова массива строк построчно
 * \param text - выводимый массив строк
 * \param size - размер выводимого массива
 */

void print_final_text(struct Text_param text_par);

/**
 * Макрос COLOR_PRINT_ALL_TEXT выводит весь передаваемый ему массив в одном цвете.
 * \param color - цвет, в который будет окрашен весь текст.
 * \param text - окрашиваемый и выводимый текст.
 * \param text_size 
 */

#define COLOR_PRINT_ALL_TEXT(color, text_par) do   \
{                                                   \
    printf(color);                                   \
    print_final_text(text_par);                       \
    printf(RES);                                       \
} while (0);                                            \

/**
 * Макрос COLOR_PRINT_ONE_STR выводит одну строку покрашенную в определенный цвет.
 * \param color - цвет, в который будет покрашена строка.
 * \param str - окращиваемая и выводимая строка.
*/

#define COLOR_PRINT_ONE_STR(color, str) do                   \
{                                                             \
    if (strcmp(str, "\0") != 0 && strcmp(str, "\n") != 0)      \
    {                                                           \
        printf(color "%s\n" RES, str);                           \
    }                                                             \
} while(0);                                                        \


#define COLOR_PRINT_ONE_SYMBOL(color, symb) do     \
{                                                   \
    printf(color);                                   \
    printf("%c", symb);                               \
    printf(RES);                                       \
} while (0);                                            \



void print_rt_str(const char* str, size_t str_num);

#endif
