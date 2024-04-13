#pragma once

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void _putchar(char);
char _getchar();
void _puts(const char*);

#ifndef CLIBC_NO_HEAP
#ifdef CLIBC_NO_LL_HEAP
void heap_init();
void *heap_alloc(size_t *size);
void heap_dealloc(void *memptr, size_t size);

size_t get_mem_used();
size_t get_mem_total();
size_t get_mem_free();
#endif
#else
void *malloc(size_t size);
void free(void *ptr);
#endif

#ifdef __cplusplus
}
#endif
