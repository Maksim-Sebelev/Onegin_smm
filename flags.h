#ifndef FLAGS_H
#define FLAGS_H

#include <string.h>
#include "color_output.h"
#include "helper_func.h"

/** */

/**const 
 * Функция Call_flags вызывает все описанные в программе флаги. 
 * Для каждого элемента argv производится вызов всех флагов.
 * \param argc - кол-во элементов в argv (аргумент функции main)
 * \param argv - массив потенциально содержащий флаги (аргумент функции main)
 * \param text - массив строк, которые и выводятся
 * \param size - размер массив text (количество строк, НЕ элементов)
 */

void Call_Flags(const int argc, const char* argv[], const char* text[], const int size);


/**
 * Функция default_no_flags срабатывает когда в argv (аргумент функции main) 
 * не поступило ни одного флага. Выводит массив без доп обработки.
 * \param text - выводимый массив строк
 * \param size - размер массива text
 */

void default_no_flags(const char* text[], const int size);


/**
 * Функция r_red_flags окрашывает вывод в красный цвет, при наличии флагов -r или --red.
 */

void r_red_flags(const int argc, const char* argv[], const char* text[], const int size, int argv_i);


/**
 * Функция b_blue_flags окрашывает вывод в синий цвет, при наличии флагов -b или --blue.
 */

void b_blue_flags(const int argc, const char* argv[], const char* text[], const int size, int argv_i);


/**
 * Функция g_green_flags окрашывает вывод в зеленый цвет, при наличии флагов -g или --green.
 */

void g_green_flags(const int argc, const char* argv[], const char* text[], const int size, int argv_i);


/**
 * Функция w_white_flags окрашывает вывод в белый цвет цвет, при наличии флагов -w или --white.
 */

void w_white_flags(const int argc, const char* argv[], const char* text[], const int size, int argv_i);


/**
 * Функция RUS_RUSSIA_flags окрашывает вывод в цвета российского триколора, при наличии флагов -RUS или --RUSSIA.
 * ГОЙДА ZA НАШИХ ZA ПУТИНА ZA МАТУШКУ РОССИЮ   ВПЕРЕД РОССИЯ   ПОБЕДА БУДЕТ ZA НАМИ
 */

void RUS_RUSSIA_flags(const int argc, const char* argv[], const char* text[], const int size, int argv_i);

#endif


