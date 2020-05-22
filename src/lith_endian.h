#ifndef LITHIUM_LITH_ENDIAN_H
#define LITHIUM_LITH_ENDIAN_H

#include <limits.h>

#if defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) &&             \
    (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) && (CHAR_BIT == 8)
#define LITH_LITTLE_ENDIAN 1
#else
#define LITH_LITTLE_ENDIAN 0
#endif

#endif /* LITHIUM_LITH_ENDIAN_H */