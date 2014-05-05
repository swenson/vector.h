# vector.h

C header library for typed lists (using macros and "template" C).

Essentially, this is a resizable array of elements of your choosing that
is automatically managed by a few simple functions.

Similar in spirit to [sort.h](https://github.com/swenson/sort).

## Instructions

Download `vector.h` and put it somewhere in your `-I` include path.

Define the `VECTOR_TYPE` macro with the type you want your vector to be of.
Like, `int`, `float`, etc.

Define the `VECTOR_NAME` to be the "name" of the vector type, in that,
all functions will look like `vec_VECTOR_NAME_somefun`. (See below.)

`#include "vector.h"`

For example, if your `VECTOR_NAME` is `int`, then you now have `vec_int_t`
as your type.
You can pass them around normally as value types, but you always need to
`init` them.

```c
vec_int_t myvec;
vec_int_init(myvec);
```

You also have access to all the functions you need, including:

* `init` (initialize an `vec_whatever_t`)
* `get`
* `pop` (remove and return the last element)
* `del` (delete an element anywhere in the vector;
  WARNING: could rewrite the whole list.)
* `size`
* `append`

## Sample usage

```c
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
  vec_int_pop(vec);
  vec_int_del(vec, 0);

  for (i = 0; i < vec_int_size(vec); i++) {
    printf("%d\n", vec_int_get(vec, i));
  }
}
```
