#include <stdio.h>
#include <string.h>
#include <user-impl.h>



int putchar(int c) {
    _putchar((char)c);
    return (int)(unsigned char)c;
}
int getchar(void) {
    const char c = _getchar();
    if (c != '\0')
        return (int)c;
    return EOF;
}
int puts(const char *s) {
    _puts(s);
    return 1;
}
