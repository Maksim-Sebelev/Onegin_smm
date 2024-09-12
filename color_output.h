#ifndef COLOR_OUTPUT_H
#define OCLOR_OUTPUT_H

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
 * Макрос COLOR_PRINT_ALL_TEXT выводит весь передаваемый ему массив в одном цвете.
 * \param color - цвет, в который будет окрашен весь текст.
 * \param text - окрашиваемый и выводимый текст.
 * \param text_size 
 */

#define COLOR_PRINT_ALL_TEXT(color, text, text_str_quant) do \
{                                                             \
    printf(color);                                             \
    print_final_text(text, text_str_quant);                     \
    printf(RES);                                                 \
} while (0);                                                      \


/**
 * Макрос COLOR_PRINT_ONE_STR выводит одну строку покрашенную в определенный цвет.
 * \param color - цвет, в который будет покрашена строка.
 * \param str - окращиваемая и выводимая строка.
*/

#define COLOR_PRINT_ONE_STR(color, str) do \
{                                           \
    printf(color);                           \
    printf("%s\n", str);                      \
    printf(RES);                               \
} while(0);                                     \



/**
 * функция print_final_text нужна для вывова массива строк построчно
 * \param text - выводимый массив строк
 * \param size - размер выводимого массива
 */

void print_final_text(const char* text[], const int size);


#endif
