#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sort.h"
#include "str_func.h"
#include "color_output.h"
#include "flags.h"
#include "read_text_from_file.h"
#include "write_text_in_file.h"
#include "text.h"



int main(const int argc, const char* argv[])
{
    struct Text_param text_par = {};
    struct Inp_Out_files file = {};

    if (argc == 1)
    {
        write_text_in_file_when_no_flags(text_par, file);
        return 0;
    }

    call_flags(argc, argv, &text_par, &file);

    make_final_file(text_par, file);

    free(text_par.text);
    return 0;
}
