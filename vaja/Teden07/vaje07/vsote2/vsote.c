#include <stdio.h>

int vsote (int n, int k, int curr_sum) {
    if (curr_sum == n)
        return 1;
    if (curr_sum > n)
        return 0;
    int out = 0;
    for (int i = k; i > 0; i--) {
        out += vsote(n, i, curr_sum + i);
    }
    return out;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int vs = vsote(n, k, 0);
    printf("%d\n", vs);
}