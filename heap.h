#pragma once

#include <stdint.h>
#include <stddef.h>


#ifdef __cplusplus
extern "C" {
#endif
#ifndef CLIBC_NO_HEAP
#ifndef CLIBC_NO_LL_HEAP
extern void *mem_base;
extern size_t mem_size;
#endif

void heap_init();
void *heap_alloc(size_t *size);
void heap_dealloc(void *memptr, size_t size);

size_t get_mem_used();
size_t get_mem_total();
size_t get_mem_free();
#endif
#ifdef __cplusplus
}
#endif
