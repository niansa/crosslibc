#include <stddef.h>
#include <stdint.h>
#include <string.h>



#define SYSCALL0(num) \
({ \
    register long _num  asm("a7") = (num); \
    register long _arg1 asm("a0"); \
     \
    asm volatile ( \
        "ecall\n\t" \
        : "=r"(_arg1) \
        : "r"(_num) \
        : "memory", "cc" \
    ); \
    _arg1; \
})

#define SYSCALL2(num, arg1, arg2) \
({ \
    register long _num  asm("a7") = (num); \
    register long _arg1 asm("a0") = (long)(arg1); \
    register long _arg2 asm("a1") = (long)(arg2); \
     \
    asm volatile ( \
        "ecall\n" \
        : "+r"(_arg1) \
        : "r"(_arg2), \
        "r"(_num) \
        : "memory", "cc" \
    ); \
    _arg1; \
})

#define SYSCALL3(num, arg1, arg2, arg3) \
({ \
    register long _num  asm("a7") = (num); \
    register long _arg1 asm("a0") = (long)(arg1); \
    register long _arg2 asm("a1") = (long)(arg2); \
    register long _arg3 asm("a2") = (long)(arg3); \
      \
    asm volatile ( \
        "ecall\n\t" \
        : "+r"(_arg1) \
        : "r"(_arg2), "r"(_arg3), \
            "r"(_num) \
        : "memory", "cc" \
    ); \
    _arg1; \
})


void _putchar(char c) {
    SYSCALL3(64, 1, &c, 1);
}

char _getchar() {
    char fres;
    SYSCALL3(63, 1, &fres, 1);
    return fres;
}

void _puts(const char *str) {
    SYSCALL3(64, 1, str, strlen(str));
    _putchar('\n');
}


__attribute__((noreturn))
void abort() {
    SYSCALL2(129, SYSCALL0(172), -9);
    __builtin_unreachable();
}
