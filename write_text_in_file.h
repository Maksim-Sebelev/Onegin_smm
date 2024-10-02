#ifndef TEXT_TO_FILE_H
#define TEXT_TO_FILE_H

#include <stdio.h>
#include "str_func.h"
#include "read_text_from_file.h"
#include "sort.h"
#include "text.h"


/**
 * Функция text_to_buffer переводит массив указателей на строки в одномерный массив.
 * (Использутеся для упрощения переноса отсортированной поэмы в файл внутри функции text_to_file).
 * \param text - массив указателей, который будет перенес в одномерный массив.
 * \param text_str_quant - количество строк в массиве text.
 * \param buffer_len - количество символов (НЕ строк) в массиве text. (Имеет такое название, так как это будущая длина массива buffer).
 */
char* write_text_in_buffer(struct Text_param text_par);

/**
 * Функция text_to_file записывает массив строк в файл, перенося его построчно (то есть сами строки сохраняются).
 * \param text - записываемый массив.
 * \param text_lines_quant - количество строк в массиве text.
 * \param file_len - количество элементов (НЕ строк) в массиве text (Называется так, потому что text читается из файла).
 * \param file_for_sort_poem - файл, в который записывается массив text (то есть отсортированная поэма).
 */

void write_text_in_file(struct Text_param tex_par, struct Inp_Out_files file);



/**
 * 
 */

void make_final_file(struct Text_param text_par, struct Inp_Out_files file);

/**
 * 
 */
void make_final_text(struct Text_param* text_par, struct Inp_Out_files file);


#endif
