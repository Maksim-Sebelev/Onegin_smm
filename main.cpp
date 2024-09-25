#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sort.h"
#include "helper_func.h"
#include "color_output.h"
#include "flags.h"
#include "file_text.h"
#include "text_file.h"



int main(const int argc, const char* argv[])
{
    struct Text_param text_par = {};
    struct Inp_Out_files file = {};

    Call_Flags(argc, argv, &text_par, &file);

    make_final_file(text_par, file);

    free(text_par.text);
    return 0;
}
