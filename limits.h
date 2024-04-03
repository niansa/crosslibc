#pragma once

#ifndef INT64_MAX
#define        INT8_MIN  (-128)
#define       INT16_MIN  (-32767-1)
#define       INT32_MIN  (-2147483647-1)
#define       INT64_MIN  (-9223372036854775807LL-1)

#define        INT8_MAX  (127)
#define       INT16_MAX  (32767)
#define       INT32_MAX  (2147483647)
#define       INT64_MAX  (9223372036854775807LL)
#endif

#ifndef UINT64_MAX
#define       UINT8_MAX  (255)
#define      UINT16_MAX  (65535)
#define      UINT32_MAX  (4294967295U)
#define      UINT64_MAX  (18446744073709551615ULL)
#endif

#ifndef INT_LEAST64_MAX
#define  INT_LEAST8_MIN  INT8_MIN
#define INT_LEAST16_MIN  INT16_MIN
#define INT_LEAST32_MIN  INT32_MIN
#define INT_LEAST64_MIN  INT64_MIN

#define  INT_LEAST8_MAX  INT8_MAX
#define INT_LEAST16_MAX  INT16_MAX
#define INT_LEAST32_MAX  INT32_MAX
#define INT_LEAST64_MAX  INT64_MAX
#endif

#ifndef UINT64_MAX
#define  UINT_LEAST8_MAX UINT8_MAX
#define UINT_LEAST16_MAX UINT16_MAX
#define UINT_LEAST32_MAX UINT32_MAX
#define UINT_LEAST64_MAX UINT64_MAX
#endif

#ifndef UINTPTR_MAX
#define SIZE_MAX         ((size_t)(__LONG_MAX__) * 2 + 1)
#define INTPTR_MIN       (-__LONG_MAX__ - 1)
#define INTPTR_MAX       __LONG_MAX__
#define PTRDIFF_MIN      INTPTR_MIN
#define PTRDIFF_MAX      INTPTR_MAX
#define UINTPTR_MAX      SIZE_MAX
#endif

#ifndef INT_FAST64_MAX
#define  INT_FAST8_MIN   INT8_MIN
#define INT_FAST16_MIN   INTPTR_MIN
#define INT_FAST32_MIN   INTPTR_MIN
#define INT_FAST64_MIN   INT64_MIN

#define  INT_FAST8_MAX   INT8_MAX
#define INT_FAST16_MAX   INTPTR_MAX
#define INT_FAST32_MAX   INTPTR_MAX
#define INT_FAST64_MAX   INT64_MAX
#endif

#ifndef UINT_FAST64_MAX
#define  UINT_FAST8_MAX  UINT8_MAX
#define UINT_FAST16_MAX  SIZE_MAX
#define UINT_FAST32_MAX  SIZE_MAX
#define UINT_FAST64_MAX  UINT64_MAX
#endif

#ifndef INT_MIN
#define INT_MIN          (-__INT_MAX__ - 1)
#endif
#ifndef INT_MAX
#define INT_MAX          __INT_MAX__
#endif

#ifndef UINT_MAX
#define UINT_MAX          ((unsigned int)__INT_MAX__)*2+1
#endif

#ifndef LONG_MIN
#define LONG_MIN         (-__LONG_MAX__ - 1)
#endif
#ifndef LONG_MAX
#define LONG_MAX         __LONG_MAX__
#endif

#define CHAR_BIT  __CHAR_BIT__
