#pragma once

#include <stdint.h>

#ifdef __cplusplus
namespace _stdlib {
extern "C" {
#endif

void exit(int status) __attribute__ ((noreturn));
void abort() __attribute__ ((noreturn));

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

double strtod(const char *nptr, char **endptr);

#ifdef __cplusplus
}
}

namespace std {
using namespace ::_stdlib;
}

using namespace ::_stdlib;
#endif
