#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sort.h"
#include "helper_func.h"
#include "color_output.h"
#include "flags.h"
#include "file_to_text.h"


const char* file_with_onegin = "onegin.txt";


int main(const int argc, const char* argv[])
{
    int text_lines_quant = 16;
    const char** text;
    text = file_to_text(file_with_onegin, &text_lines_quant);


    // for (int i = 0; i < 16; i++)
    // {
    //     printf("%s\n", text[i]);
    // }

    text_sort(text, text_lines_quant);

    Call_Flags(argc, argv, text, text_lines_quant);


    free(text);
    return 0;
}

