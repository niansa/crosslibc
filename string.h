#pragma once

#include "stoi.h"

#include <stdint.h>

#ifdef __cplusplus
namespace _string {
extern "C" {
#endif

size_t strlen(const char *str);
char *strcpy(char *dst, const char *src);
int strcmp(const char *s1, const char *s2);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
void *memchr(const void *s, unsigned char c, size_t n);

#ifdef __cplusplus
}
}

namespace std {
using namespace ::_string;
}

using namespace ::_string;
#endif
