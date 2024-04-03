#include "stoi.h"

#include <stdint.h>
#include <stddef.h>


size_t strlen(const char *str) {
    size_t fres = 0;
    while (str[fres]) ++fres;
    return fres;
}

char *strcpy(char *dst, const char *src) {
    size_t it;
    for (it = 0; src[it]; it++)
        dst[it] = src[it];
    dst[it] = '\0';
    return dst;
}

int strcmp(const char *s1, const char *s2) {
    unsigned int c;
    int diff;

    while (!(diff = (unsigned char)*s1++ - (c = (unsigned char)*s2++)) && c);

    return diff;
}

void *memcpy(void *dest, const void *src, size_t n) {
    for (size_t it = 0; it != n; it++)
        ((char*)dest)[it] = ((char*)src)[it];
    return dest;
}

void *memset(void *s, int c, size_t n) {
    for (size_t it = 0; it != n; it++)
        ((char*)s)[it] = (char)c;
    return s;
}

void *memmove(void *dest, const void *src, size_t n) {
    for (size_t it = n; it != 0; it--)
        ((char*)dest)[it-1] = ((char*)src)[it-1];
    return dest;
}

int memcmp(const void *s1, const void *s2, size_t n) {
    if (n == 0)
        return 0;

    while (--n && *(char*)s1 == *(char*)s2) {
        s1 = (char*)s1 + 1;
        s2 = (char*)s2 + 1;
    }

    return(*((unsigned char*)s1) - *((unsigned char*)s2));
}

void *memchr(const void *s, unsigned char c, size_t n) {
    if (n != 0) {
        const unsigned char *p = s;

        do {
            if (*p++ == c)
                return ((void *)(p - 1));
        } while (--n != 0);
    }
    return NULL;
}

#undef STOI_IMPL
#define STOI_IMPL(suffix, type) \
type strto##suffix(const char *str, char **endptr, int base) { \
    type fres = 0; \
    for (const char *c = str; *c && c != *endptr; c++) { \
        fres += *c - '0'; \
        fres *= base; \
    } \
    fres /= base; \
    return fres; \
}
STOI_IMPLS
