#include <stdlib.h>



int atoi(const char *s) {
    int c = 1, a = 0, sign, start, end, base = 1;

    if (s[0] == '-')
        sign = -1;
    else if (s[0] <= '9' && s[0] >= '0')
        sign = 1;
    else if (s[0] == '+')
        sign = 2;
    else
        return 0;

    while (s[c] != '\n' && s[c] <= '9' && s[c] >= '0')
        c++;

    start = c - 1;
    if (sign == -1) {
        end = 1;
    } else if (sign == 1) {
        end = 0;
    } else {
        end = 1;
        sign = 1;
    }

    for (int i = start; i >= end ; i--) {
        a += (s[i] - '0')*base;
        base *= 10;
    }

    return sign*a;
}

