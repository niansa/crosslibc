#include "heap.h"

#include <stdint.h>
#include <stddef.h>


struct memchunk_free {
    size_t size;
    struct memchunk_free *next;
};



static struct memchunk_free heap;

void *mem_base;
size_t mem_size;
static size_t mem_used;

#define SIZE_ALIGN(num) (((num + sizeof(struct memchunk_free) - 1) / sizeof(struct memchunk_free)) * sizeof(struct memchunk_free))

void heap_init() {
    mem_used = 0;

    heap.next = (struct memchunk_free *)mem_base;
    heap.next->size = mem_size;
    heap.next->next = 0;
    heap.size = 0;
}

void *heap_alloc(size_t *size) {
    // Allocations can't be smaller than this
    if(*size < sizeof(struct memchunk_free))
        *size = sizeof(struct memchunk_free);

    // Force-align size
    *size = SIZE_ALIGN(*size);
    // Find first free space
    struct memchunk_free *nextmatch = heap.next, *baknext = &heap;

    // Get a chunk which fits this size
    while (nextmatch && nextmatch->size < *size) {
        baknext = nextmatch;
        nextmatch = nextmatch->next;
    }

    // If no chunk fits
    if(!nextmatch || nextmatch->size < *size) {
        return NULL;
    }

    // Calculate the remaining size of the chunk
    size_t new_size = nextmatch->size - *size;

    // If there is anything left, place it back in the list
    if(new_size >= sizeof(struct memchunk_free)) {
        struct memchunk_free *bak = baknext->next->next;
        baknext->next = (struct memchunk_free *)((size_t)nextmatch + *size);
        baknext->next->next = bak;
        baknext->next->size = new_size;
    } else {
        *size = nextmatch->size;
        baknext->next = nextmatch->next;
    }

    // Increase counter
    mem_used += *size;

    // Return allocated memory
    return nextmatch;
}

void heap_dealloc(void *memptr, size_t size) {
    // Convert this back into a chunk
    struct memchunk_free *chunk = (struct memchunk_free *)memptr;

    // Reinsert the chunk into the freelist
    chunk->size = size;
    chunk->next = heap.next;
    heap.next = chunk;

    // Decrease counter
    mem_used -= size;
}

size_t get_mem_used() {
    return mem_used;
}
size_t get_mem_total() {
    return mem_size;
}
size_t get_mem_free() {
    return get_mem_total() - get_mem_used();
}


void *malloc(size_t size) {
    // Add space for size
    size += sizeof(uintptr_t);

    size_t *mem = (size_t *)heap_alloc(&size);

    if (!mem)
        return NULL;

    mem[0] = size;
    return mem + 1;
}
void free(void *ptr) {
    if (ptr < mem_base || (char*)ptr > (char*)mem_base + mem_size)
        return;

    size_t *mem = (size_t *)ptr - 1;
    heap_dealloc(mem, mem[0]);
}

void *calloc(size_t nmemb, size_t size) {
    size *= nmemb;
    void *fres = malloc(size);
    for (size_t it = 0; it != size; it++)
        ((char*)fres)[it] = 0;
    return fres;
}

void *realloc(void *ptr, size_t size) {
    if (!ptr)
        return malloc(size);

    size_t old_size = *((size_t *)ptr - 1);
    void *fres = malloc(size);
    if (old_size < size)
        size = old_size;
    for (size_t it = 0; it != size; it++)
        ((char*)fres)[it] = ((char*)ptr)[it];
    free(ptr);
    return fres;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size) {
    if (!ptr)
        return calloc(nmemb, size);

    return realloc(ptr, size*nmemb);
}
