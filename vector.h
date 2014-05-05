/* Copyright (c) 2014 Christopher Swenson. */

#include <stdlib.h>
#include <string.h>

#ifndef VECTOR_NAME
#error "Must declare VECTOR_NAME"
#endif

#ifndef VECTOR_TYPE
#error "Must declare VECTOR_TYPE"
#endif

#ifndef VECTOR_PREFIX
#define VECTOR_PREFIX vec
#endif

#define VECTOR_CONCAT(x, y) x ## _ ## y
#define VECTOR_MAKE_STR1(x, y) VECTOR_CONCAT(x,y)
#define VECTOR_MAKE_STR(x) VECTOR_MAKE_STR1(VECTOR_PREFIX, VECTOR_MAKE_STR1(VECTOR_NAME,x))

#define VECTOR_STRUCT  VECTOR_MAKE_STR(struct)
#define VECTOR         VECTOR_MAKE_STR(t)
#define VECTOR_INIT    VECTOR_MAKE_STR(init)
#define VECTOR_GET     VECTOR_MAKE_STR(get)
#define VECTOR_POP     VECTOR_MAKE_STR(pop)
#define VECTOR_DEL     VECTOR_MAKE_STR(del)
#define VECTOR_SIZE    VECTOR_MAKE_STR(size)
#define VECTOR_APPEND  VECTOR_MAKE_STR(append)

typedef struct {
  VECTOR_TYPE *arr;
  size_t size;
  size_t alloc;
} VECTOR_STRUCT;

typedef VECTOR_STRUCT VECTOR[1];

static __inline void VECTOR_INIT(VECTOR vec) {
  vec[0].alloc = 8;
  vec[0].arr = calloc(vec->alloc, sizeof(VECTOR_TYPE));
  vec[0].size = 0;
}

static __inline void VECTOR_APPEND(VECTOR vec, VECTOR_TYPE elt) {
  if (vec[0].size == vec[0].alloc) {
    vec[0].alloc += (vec[0].alloc >> 1); /* Increase size by 50% */
    vec[0].arr = realloc(vec[0].arr, vec[0].alloc * sizeof(VECTOR_TYPE));
  }

  vec[0].arr[vec[0].size++] = elt;
}

static __inline VECTOR_TYPE VECTOR_GET(VECTOR vec, int i) {
  return vec[0].arr[i];
}

static __inline VECTOR_TYPE VECTOR_POP(VECTOR vec) {
  return vec[0].arr[vec[0].size--];
}

static __inline void VECTOR_DEL(VECTOR vec, int i) {
  if (i == vec[0].size) {
    VECTOR_POP(vec);
  } else {
    memmove(&(vec[0].arr[i]), &(vec[0].arr[i + 1]),
            sizeof(VECTOR_TYPE) * vec[0].size - i - 1);
    vec[0].size--;
  }
}

static __inline size_t VECTOR_SIZE(VECTOR vec) {
  return vec[0].size;
}

#undef VECTOR_CONCAT
#undef VECTOR_MAKE_STR1
#undef VECTOR_MAKE_STR
#undef VECTOR_NAME
#undef VECTOR_TYPE
#undef VECTOR_STRUCT
#undef VECTOR
#undef VECTOR_INIT
#undef VECTOR_GET
#undef VECTOR_POP
#undef VECTOR_DEL
#undef VECTOR_SIZE
#undef VECTOR_APPEND
#undef VECTOR_PREFIX
