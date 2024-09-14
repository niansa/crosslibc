#include "../heap.h"


#ifndef CLIBC_NO_LL_HEAP
uint8_t heap[2048]; // 2 KB
#endif


int main(int argc, char **argv);
void _start() {
#ifndef CLIBC_NO_LL_HEAP
    mem_base = heap;
    mem_size = sizeof(heap);
    heap_init();
#endif

    main(0, NULL);
}
