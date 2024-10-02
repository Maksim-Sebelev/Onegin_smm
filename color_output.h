#ifndef COLOR_OUTPUT_H
#define OCLOR_OUTPUT_H

#include <stdio.h>

#define ANSI_COLOR_WHITE  "\e[0;37m"
#define ANSI_COLOR_BLUE   "\e[0;34m"
#define ANSI_COLOR_RED    "\x1b[31m"
#define ANSI_COLOR_GREEN  "\x1b[32m"
#define ANSI_COLOR_RESET  "\x1b[0m"


#define WHITE  ANSI_COLOR_WHITE
#define BLUE   ANSI_COLOR_BLUE
#define RED    ANSI_COLOR_RED
#define GREEN  ANSI_COLOR_GREEN
#define RESET  ANSI_COLOR_RESET


#define COLOR_PRINT(color, ...) do \
{                                   \
    printf(color);                   \
    printf(__VA_ARGS__);              \
    printf(RESET);                     \
} while (0)                             \

#endif
