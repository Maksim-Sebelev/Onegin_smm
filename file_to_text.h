#ifndef FILE_TO_TEXT_H
#define FILE_TO_TEXT_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "helper_func.h"


/**
 * Функция make_buffer создает возвращает указатель на буффер, в который будет скопирован файл.
 * \param file_name - копируемый файл.
 * \param buffer_len - длина буффера (кол-во элементов в файле), которая будет определена по ходу выполнения функции.
 * \param text_str_quant - кол-во строк в читаемом файле, называется text, так как в дальнейшем такую длину будет иметь массив text.
 */

char* make_buffer(const char* file_name, int* buffer_len, int* text_str_quant);

/**
 * Функция make_text возвращает указатель на массив указателей text, в который по строкам передается массив buffer.
 * \param buffer - массив, из которого передаются указатели на его строки в массив text.
 * \param text_str_quant - кол-во строк в массиве text (получается из функции make_buffer).
 * \param buffer_len - кол-во элементов в массиве buffer, из которого и получается массив text.
 */

const char** make_text(char* buffer, int text_str_quant, int buffer_len);

/**
 * Функция file_to_text построчно копирует (делает массив указателей) строки из файла в массив (с помощью функций make_buffer и make_text).
 * \param file_name - читаемый файл.
 * \param text_str_quant - кол-во элементов в массиве text (изменятся по ходу выполнения функции).
 */
 

const char** file_to_text(const char* file_name, int* text_str_quant);


#endif

