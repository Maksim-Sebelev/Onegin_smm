#include "color_output.h"


void print_final_text(const char* text[], const int text_str_quant)
{
    for (int text_i = 0; text_i < text_str_quant; text_i++)
    {
        printf("%s\n", text[text_i]);
    }
    return;
}
