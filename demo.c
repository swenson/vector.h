#include <stdio.h>
#define VECTOR_TYPE int
#define VECTOR_NAME int
#include "vector.h"

int main(void) {
  int i;
  vec_int_t vec;
  vec_int_init(vec);
  vec_int_append(vec, 2);
  vec_int_append(vec, 100);
  vec_int_append(vec, 101);
  vec_int_append(vec, 102);
  vec_int_append(vec, 103);
  vec_int_append(vec, 104);
  vec_int_append(vec, 105);
  vec_int_append(vec, 106);
  vec_int_append(vec, 107);
  vec_int_append(vec, 108);
  vec_int_append(vec, 109);
  vec_int_pop(vec);
  vec_int_append(vec, 200);
  vec_int_pop(vec);
  vec_int_pop(vec);
  vec_int_del(vec, 0);
  vec_int_del(vec, 1);

  for (i = 0; i < vec_int_size(vec); i++) {
    printf("%d\n", vec_int_get(vec, i));
  }
}
