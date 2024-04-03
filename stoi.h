#pragma once

#define STOI_IMPL(suffix, type) type strto##suffix(const char *str, char **endptr, int base);
#define STOI_IMPLS \
    STOI_IMPL(i, int) \
    STOI_IMPL(l, long) \
    STOI_IMPL(ul, unsigned long) \
    STOI_IMPL(ll, long long) \
    STOI_IMPL(ull, unsigned long long)
STOI_IMPLS
