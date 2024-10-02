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
 * функция found_letter позволяте найти первую (справа налево) букву в строке str начиная с иднекса str_i.
 * \param str есть искомая строка
 * \param str_i есть инедкс, начиная с которого идет поиск
 */

void find_last_letter(const char str[], int* str_i);



/**
 * Функция found_str_end ищет первый элемент в строке равный '\0' или '\n' или '\r'.
 * Возвращаемое значение есть целое число, на которое надо сместиться от начала строки,
 * чтобы попасть на нужный элемент ('\0' или '\n' или '\r').
 * \param str - строка, в которой ищется первый требуемый символ.
 */

int find_str_end(const char* str);


/**
 * Функци arr_str_quant считает количество строк содержащихся в массиве.
 * Конкретно здесь строкой считается набор элементов типа char заканчивающихся символом '\n'.
 * \param arr - массив, в котором считается количество строк.
 */

size_t count_arr_str_quant(char* arr);


/**
 * Функция real_str_len считает длину строки не учитывая все '\0' стоящие в ее конце.
 * \param str - строка, длина которой считается.
 * \param str_len - длина строки str с учетом всех '\0' в конце.
 */

size_t count_real_str_len(char* str, size_t str_len);


/**
 * Функция add_str_to_arr добавляет к массиву в определенном месте строку, в конце которой не '\0', а '\0'.
 * \param arr - массив, к которому выполняется добавление.
 * \param arr_i - индекс массива, с которого выполняется прибавление.
 * \param str - прибавляемая строка.
 */

void add_str_to_arr(char* arr, size_t arr_i, const char* str);


#endif



