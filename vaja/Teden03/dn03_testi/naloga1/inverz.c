#include <stdio.h>
#include <stdbool.h>

#include "inverz.h"

long inverz(long x, long a, long b) {
    long sredina;
    long fn;
    do
    {
        sredina = (b - a) / 2 + a;
        fn = f(sredina);
        if (fn > x)
            b = sredina - 1;
        else if (fn < x)
            a = sredina + 1;
    } while (x != fn && a <= b);
    
    return sredina;
    /*
    for (long i = a; i <= b; i++) {
        if (x == f(i))
            return i;
    }
    return -1;
    */
}
