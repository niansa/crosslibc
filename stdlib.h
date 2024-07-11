#pragma once

#include <stdint.h>

#ifdef __cplusplus
namespace _stdlib {
extern "C" {
#endif

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#ifndef CLIBC_NO_FLOAT
double strtod(const char *nptr, char **endptr);
#endif

#ifdef __cplusplus
}
}

namespace std {
using namespace ::_stdlib;
}

using namespace ::_stdlib;
#endif
