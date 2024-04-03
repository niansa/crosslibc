#pragma once

#include "user-impl.h"
#include "printf/printf.h"

#define fprintf(file, ...) printf_(__VA_ARGS__)


int putchar(int c);
int getchar(void);
int puts(const char *s);
