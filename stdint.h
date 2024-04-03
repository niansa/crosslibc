#pragma once

#include <stddef.h> // Workaround for projects expecting stddef.h from stdint.h

#ifdef __cplusplus
namespace _stdint {
#endif

typedef unsigned char       uint8_t;
typedef   signed char        int8_t;
typedef unsigned short     uint16_t;
typedef   signed short      int16_t;
typedef unsigned int       uint32_t;
typedef   signed int        int32_t;
typedef unsigned long long uint64_t;
typedef   signed long long  int64_t;
typedef __SIZE_TYPE__        size_t;
typedef   signed long       ssize_t;
typedef unsigned long     uintptr_t;
typedef   signed long      intptr_t;
typedef   signed long     ptrdiff_t;
typedef   signed long         off_t;

typedef   int8_t       int_least8_t;
typedef  uint8_t      uint_least8_t;
typedef  int16_t      int_least16_t;
typedef uint16_t     uint_least16_t;
typedef  int32_t      int_least32_t;
typedef uint32_t     uint_least32_t;
typedef  int64_t      int_least64_t;
typedef uint64_t     uint_least64_t;

typedef   int8_t        int_fast8_t;
typedef  uint8_t       uint_fast8_t;
typedef  ssize_t       int_fast16_t;
typedef   size_t      uint_fast16_t;
typedef  ssize_t       int_fast32_t;
typedef   size_t      uint_fast32_t;
typedef  int64_t       int_fast64_t;
typedef uint64_t      uint_fast64_t;

typedef  int64_t           intmax_t;
typedef uint64_t          uintmax_t;

#ifdef __cplusplus
}

namespace std {
using namespace ::_stdint;
}

using namespace ::_stdint;
#endif
