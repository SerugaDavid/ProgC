#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dodaj_plus(int num, char * racun, int curr_len) {
    int start = 0;
    if (curr_len != 0) {    
        racun[curr_len + start++] = ' ';
        racun[curr_len + start++] = '+';
        racun[curr_len + start++] = ' ';
    }

    char * str_num = calloc(2, sizeof(char));
    sprintf(str_num, "%d", num);
    int len = strlen(str_num);
    for (int i = 0; i < len; i++) {
        racun[curr_len + start + i] = str_num[i];
    }

    return len + start + curr_len;
}

void vsote (int n, int k, int curr_sum, char * racun, int curr_len) {
    if (curr_sum == n) {
        racun[curr_len] = '\0';
        printf("%s\n", racun);
    }
    if (curr_sum > n)
        return;
    int new_len;
    for (int i = k; i > 0; i--) {
        new_len = dodaj_plus(i, racun, curr_len);
        vsote(n, i, curr_sum + i, racun, new_len);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char * racun = calloc(n + (n-1)*3 + 1, sizeof(char));
    vsote(n, k, 0, racun, 0);
}