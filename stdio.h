#pragma once

#include "printf/printf.h"

#define fprintf(file, ...) printf_(__VA_ARGS__)

#ifdef __cplusplus
namespace _stdlib {
extern "C" {
#endif

int putchar(int c);
int getchar(void);
int puts(const char *s);

#ifdef __cplusplus
}
}

namespace std {
using namespace ::_stdlib;
}

using namespace ::_stdlib;
#endif
