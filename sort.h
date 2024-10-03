#ifndef A_H
#define A_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include "str_func.h"
#include "color_output.h"
#include "text.h"


/**
 * Функция comp_for_sort есть компаратор для сравнения двух строк.
 * Сравнивание происходит с концов строк (справа налево) по алфавиту
 * (на данный момент предусмотрен только английский, русский язык возможно будет добавлен в следующих обновлениях),
 * пробелы и знаки препинания игнорируются.
 * \param str1 - первая из сравнимаевых
 * \param str2 - вторая из сравниваемых строк 
 */

int back_comp_str(const void* const str1, const void* const str2);


/**
 * функция quick_text_sort совершает сортировку исходного массива text по строкам, согласно условия функции comp_for_str.
 * \param text - сортируемый массив строк
 * \param first_sort_elem - индекс начала подмассива для сортировки (включительно)
 * \param second_sort_elem - индекс конца подмассива для сортироки (НЕвключительно)
 */

void quick_sort(void* text, size_t text_size, size_t text_elem_size, int comp(const void* const, const void* const));



/**
 * функцич text_sort подставляет в фунцию значения 0 и size вместо first_sort_elem и second_sort_elem соотвественно,
 * для ее запуска. Данная функция является сугубо вспомогательной.
 * \param text - сортируемый массив строк
 * \param size - длина сортируемого массива(кол-во строк)
 */

void text_sort(struct Text_param* text_par);


void swap(void* p1, void* p2, size_t size);


#endif

