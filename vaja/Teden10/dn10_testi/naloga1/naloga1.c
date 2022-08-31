
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

Vozlisce* zdesetkaj(Vozlisce* zacetek, int k) {
    if (zacetek == NULL)
        return NULL;
    Vozlisce * tmp = zacetek;
    Vozlisce * out = NULL;
    Vozlisce * curr = NULL;
    for (int i = 1; tmp != NULL; i++) {
        if (i%k == 0) {
            if (curr == NULL){
                out = calloc(1, sizeof(Vozlisce));
                curr = calloc(1, sizeof(Vozlisce));
                curr = tmp;
                out = curr;
                tmp = tmp->naslednje;
                continue;
            }
            curr->naslednje = tmp;
            curr = tmp;
        }
        tmp = tmp->naslednje;
    }
    curr->naslednje = NULL;
    return out;
}







// testing
/*
Vozlisce* ustvari(int* t, int n) {
    if (n <= 0) {
        return NULL;
    }
    Vozlisce* v = malloc(sizeof(Vozlisce));
    v->podatek = *t;
    v->naslednje = ustvari(t + 1, n - 1);
    return v;
}

Vozlisce** shrani(int* tabela, Vozlisce* seznam, int n, int k, int* dolzina) {
    *dolzina = n / k;
    Vozlisce** shramba = malloc(*dolzina * sizeof(Vozlisce*));
    Vozlisce* v = seznam;
    Vozlisce** p = shramba;
    int i = 1;
    while (v != NULL) {
        if (i % k == 0) {
            *p++ = v;
        }
        v = v->naslednje;
        i++;
    }
    return shramba;
}

void izpisi(Vozlisce* v) {
    bool prvic = true;
    printf("[");
    while (v != NULL) {
        if (!prvic) {
            printf(", ");
        }
        prvic = false;
        printf("%d", v->podatek);
        v = v->naslednje;
    }
    printf("]\n");
}

void preveri(Vozlisce** tabela, Vozlisce* seznam, int dolzina) {
    int i = 0;
    Vozlisce* v = seznam;
    Vozlisce** t = tabela;
    while (v != NULL && i < dolzina) {
        printf("%d", v == *t);
        v = v->naslednje;
        t++;
        i++;
    }
    printf("\n");
}

void pocisti(Vozlisce* v) {
    if (v != NULL) {
        pocisti(v->naslednje);
        free(v);
    }
}

int main() {
    int tabela[] = {-617};
    int n = sizeof(tabela) / sizeof(int);
    int k = 1;

    Vozlisce* zacetek = ustvari(tabela, n);
    int dolzina = 0;
    Vozlisce** shramba = shrani(tabela, zacetek, n, k, &dolzina);

    zacetek = zdesetkaj(zacetek, k);
    izpisi(zacetek);
    preveri(shramba, zacetek, dolzina);
    pocisti(zacetek);
    free(shramba);

    exit(0);
    return 0;
}

*/


