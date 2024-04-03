#include <stdio.h>
#include <string.h>



int putchar(int c) {
    _putchar((char)c);
    return (int)(unsigned char)c;
}
int getchar(void) {
    return (int)_getchar();
}
int puts(const char *s) {
    _puts(s);
    return 1;
}
