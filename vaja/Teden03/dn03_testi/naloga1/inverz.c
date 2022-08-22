#include <stdio.h>
#include <stdbool.h>

#include "inverz.h"

long inverz(long x, long a, long b) {
    for (long i = a; i <= b; i++) {
        if (x == f(i))
            return i;
    }
    return -1;
}
