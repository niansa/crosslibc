#include "ctype.h"



int isdigit(int c) {
    return c >= '0' && c <= '9';
}

int isxdigit(int c) {
    return isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

int isalpha(int c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int isalnum(int c) {
    return isdigit(c) || isalpha(c);
}

int isblank(int c) {
    return c == ' ' || c == '\t';
}

int isspace(int c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r';
}

int iscntrl(int c) {
    return c == '\n' || c == '\b' || c == '\t' || c == '\r';
}
