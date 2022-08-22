#include <stdio.h>

long long reverseLong(long long num) {
    if (num == 0)
        return 0;
    long long reverse = 0;
    long long tmp = num;
    while (tmp != 0) {
        reverse *= 10;
        reverse += tmp%10;
        tmp /= 10;
    }
    return reverse;
}

int jePalindrom(long long num) {
    return num == reverseLong(num);
}

int jeDomnevnoLyc(long long num, int k) {
    for (int i = 0; i < k; i++) {
        num += reverseLong(num);
        //printf("%d, ", num);
        if (jePalindrom(num)) {
            //printf("je");
            return 0;
        }
        if (num > 100000000000000000)
            break;
    }
    return 1;
}

int main() {
    int k, a, b;
    scanf("%d %d %d", &k, &a, &b);
    int count = 0;
    for (long long i = a; i <= b; i++) {
        //printf("%d, ", i);
        count += jeDomnevnoLyc(i, k);
        //printf("\n");
    }
    printf("%d\n", count);
    return 0;
}
