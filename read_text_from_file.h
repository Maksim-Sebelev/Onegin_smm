#ifndef FILE_TO_TEXT_H
#define FILE_TO_TEXT_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>
#include "str_func.h"
#include "color_output.h"
#include "text.h"

enum Has_str_letter
{   
    STR_HAS_LETTER = 0,
    STR_HAS_NOT_LETTER
};

/**
 * Функция make_buffer создает возвращает указатель на буффер, в который будет скопирован файл.
 * \param file_name - копируемый файл.
 * \param buffer_len - длина буффера (кол-во элементов в файле), которая будет определена по ходу выполнения функции.
 * \param text_str_quant - кол-во строк в читаемом файле, называется text, так как в дальнейшем такую длину будет иметь массив text.
 */

char* read_buffer_from_file(struct Text_param* text_par, struct Inp_Out_files file);

/**
 * Функция make_text возвращает указатель на массив указателей text, в который по строкам передается массив buffer.
 * \param buffer - массив, из которого передаются указатели на его строки в массив text.
 * \param text_str_quant - кол-во строк в массиве text (получается из функции make_buffer).
 * \param buffer_len - кол-во элементов в массиве buffer, из которого и получается массив text.
 */

struct Line* split_buffer_in_str(char* buffer, struct Text_param text_par);

/**
 * Функция file_to_text построчно копирует (делает массив указателей) строки из файла в массив (с помощью функций make_buffer и make_text).
 * \param file_name - читаемый файл.
 * \param text_str_quant - кол-во элементов в массиве text (изменятся по ходу выполнения функции).
 */
 

struct Line* read_text_from_file(struct Text_param* text_par, struct Inp_Out_files file);


size_t count_file_len(const char* file_name);

#endif

