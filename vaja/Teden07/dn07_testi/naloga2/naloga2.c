#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nizi(int n, char ** besede, int index, char * beseda) {
    if (index == n) {
        printf("%s\n", beseda);
        return;
    }
    int len_besede = strlen(besede[index]);
    for (int i = 0; i < len_besede; i++) {
        beseda[index] = besede[index][i];
        nizi(n, besede, index + 1, beseda);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char ** besede = calloc(n, sizeof(char *));
    for (int i = 0; i < n; i++) {
        besede[i] = calloc(42, sizeof(char));
        scanf("%s", besede[i]);
    }

    char * beseda = calloc(n, sizeof(char) + 1);
    nizi(n, besede, 0, beseda);
}