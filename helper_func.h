#ifndef HELPER_FUNC_H
#define HELPER_FUNC_H

#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


/**
 * функция my_swap есть аналог функции swap, но сделанный моими собственными ручками,
 * при поддержке моего любимого ментора - Армана.
 * Сама функция меняет значения двух указатей (требуется для сортировки исходного массива text)
 * \param p1 - указатель на первый меняемый указатель
 * \param p2 - указатель на второй меняемый указатель
 */

void my_swap(const char** p1, const char** p2);


/**
 * функция found_letter позволяте найти первую (справа налево) букву в строке str начиная с иднекса str_i.
 * \param str есть искомая строка
 * \param str_i есть инедкс, начиная с которого идет поиск
 */

void found_letter(const char str[], int* str_i);



/** 
 * Функция arr_str_quant считает количество строк в массиве. (строкой считается набор символов
 * заканчивающийся на "\n" или на "\0")
 * \param arr - указатель на массив, в котом и считается количество строк
*/


int arr_str_quant(char* arr);



#endif



