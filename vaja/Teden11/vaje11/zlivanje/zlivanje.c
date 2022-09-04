#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int * tabela, int n) {
    int min_num = 1000000000;
    int ind = -1;
    for (int i = 0; i < n; i++) {
        if (tabela[i] != -1 && tabela[i] < min_num) {
            min_num = tabela[i];
            ind = i;
        }
    }
    return ind;
}

int done(int * tabela, int n) {
    for (int i = 0; i < n; i++) {
        if (tabela[i] != -1)
            return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    FILE ** files = calloc(n, sizeof(FILE *));
    char * ime_datoteke = calloc(100, sizeof(char));
    int * naslednji = calloc(n, sizeof(int));

    // odpri datoteke in nastavi naslednje
    for (int i = 0; i < n; i++) {
        scanf("%s", ime_datoteke);
        files[i] = fopen(ime_datoteke, "r");
        if (fscanf(files[i], "%d", &naslednji[i]) != 1) {
            naslednji[i] = -1;
        }
    }
    scanf("%s", ime_datoteke);
    FILE * out;
    out = fopen(ime_datoteke, "w");

    // združevanje in zapisovanje
    int ind;
    while (!done(naslednji, n)) {
        ind = min(naslednji, n);
        fprintf(out, "%d\n", naslednji[ind]);
        if (fscanf(files[ind], "%d", &naslednji[ind]) != 1) {
            naslednji[ind] = -1;
        }
    }

    // zapri datoteke
    for (int i = 0; i < n; i++) {
        fclose(files[i]);
    }
    fclose(out);
    return 0;
}