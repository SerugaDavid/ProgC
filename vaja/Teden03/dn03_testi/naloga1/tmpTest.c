#include <stdio.h>
#include <stdbool.h>

long long f(long long x) {
    return 1L << x;
}

int main() {
    for (long long i = 1; i < 100; i++) {
        printf("%ld: %ld\n", i, f(i));
    }
    return 0;
}