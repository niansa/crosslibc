#pragma once

#include <stdint.h>
#include <stddef.h>


#ifdef __cplusplus
extern "C" {
#endif
extern void *mem_base;
extern size_t mem_size;

void heap_init();
void *heap_allocate(size_t *size);
void heap_deallocate(void *memptr, size_t size);

size_t get_mem_used();
size_t get_mem_total();
size_t get_mem_free();
#ifdef __cplusplus
}
#endif
