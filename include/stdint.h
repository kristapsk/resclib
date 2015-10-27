#ifndef _STDINT_H
#define _STDINT_H

#include <___int.h>

// Exact-width integer types

typedef signed __int8 int8_t;
typedef unsigned __int8 uint8_t;
typedef signed __int16 int16_t;
typedef unsigned __int16 uint16_t;
typedef signed __int32 int32_t;
typedef unsigned __int32 uint32_t;
typedef signed __int64 int64_t;
typedef unsigned __int64 uint64_t;

#define INT8_MIN _INT8_MIN
#define INT8_MAX _INT8_MAX
#define UINT8_MAX _UINT8_MAX
#define INT16_MIN _INT16_MIN
#define INT16_MAX _INT16_MAX
#define UINT16_MAX _UINT16_MAX
#define INT32_MIN _INT32_MIN
#define INT32_MAX _INT32_MAX
#define UINT32_MAX _UINT32_MAX
#define INT64_MIN _INT64_MIN
#define INT64_MAX _INT64_MAX
#define UINT64_MAX _UINT64_MAX

#endif
