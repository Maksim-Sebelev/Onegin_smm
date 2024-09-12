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
    int text_lines_quant = 0;
    const char** text = NULL;
    // printf("\nQQQQQ\n");
    text = file_to_text(file_with_onegin, &text_lines_quant);



    // printf("%d\n\n", text_lines_quant);
    
    // for (int i = 0; i < text_lines_quant; i++)
    // {
    //     printf("%d    %s\n", i, text[i]);
    // }

    // printf("\n\nAAAA\n\n");
    
    text_sort(text, text_lines_quant);
    // printf("\n\nBBBB\n");
    Call_Flags(argc, argv, text, text_lines_quant);


    free(text);
    return 0;
}

