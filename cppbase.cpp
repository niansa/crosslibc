#include <cstdlib>
#include <cstdint>
#include <cstddef>


void *operator new(size_t size) {
    return malloc(size);
}
void *operator new[](size_t size) {
    return malloc(size);
}
void *operator new[](size_t size, const char *, int, unsigned, const char *, int line) {
    return malloc(size);
}
void *operator new[](size_t size, size_t, size_t, char const *, int, unsigned int, char const*, int) {
    return malloc(size);
}

void operator delete(void *ptr, unsigned long) {
    free(ptr);
}
void operator delete[](void *ptr, unsigned long) {
    free(ptr);
}
void operator delete[](void *ptr) {
    free(ptr);
}

void *operator new(std::size_t n, void *ptr) {
    return ptr;
}
void operator delete(void *ptr) {
    free(ptr);
}
