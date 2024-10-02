#ifndef FLAGS_H
#define FLAGS_H

#include <string.h>
#include <stdio.h>
#include "color_output.h"
#include "read_text_from_file.h"
#include "write_text_in_file.h"
#include "str_func.h"
#include "sort.h"
#include "text.h"


enum Flag_error_type
{
    NO_INPUT = 0,
    INCORRECT_INPUT,
    NO_ERR
};


/**
 * Функция Call_flags вызывает все описанные в программе флаги. 
 * Для каждого элемента argv производится вызов всех флагов.
 * \param argc - кол-во элементов в argv (аргумент функции main)
 * \param argv - массив потенциально содержащий флаги (аргумент функции main)
 * \param text - массив строк, которые и выводятся
 * \param size - размер массив text (количество строк, НЕ элементов)
 */

void call_flags(const int argc, const char* argv[], struct Text_param* text_par, struct Inp_Out_files* file);


/**
 * Функция default_no_flags срабатывает когда в argv (аргумент функции main) 
 * не поступило ни одного флага. Выводит массив без доп обработки.
 * \param text - выводимый массив строк
 * \param size - размер массива text
 */

Flag_error_type write_text_in_file_when_no_flags(struct Text_param text_par, struct Inp_Out_files file);


Flag_error_type change_input_file_flag(const int argc, const char* argv[], size_t argv_i, struct Text_param* text_par, struct Inp_Out_files* file);


Flag_error_type change_ouput_file_flag(const int argc, const char* argv[], size_t argv_i, struct Text_param* text_par, struct Inp_Out_files* file);


Flag_error_type print_flag(const int argc, const char* argv[], size_t argv_i, struct Text_param* text_par, struct Inp_Out_files* file);


/**
 * Функция RUS_RUSSIA_flags окрашывает вывод в цвета российского триколора, при наличии флагов -RUS или --RUSSIA.
 * ГОЙДА ZA НАШИХ ZA ПУТИНА ZA МАТУШКУ РОССИЮ   VПЕРЕД РОССИЯ   ПОБЕДА БУДЕТ ZA НАМИ
 */

Flag_error_type RUSSIA_flag(const int argc, const char* argv[], size_t argv_i, struct Text_param* text_par, struct Inp_Out_files* file);


enum Flag_error_type FindRT_flag(const int argc, const char* argv[], size_t argv_i, struct Text_param* text_par, struct Inp_Out_files* file);


#endif


