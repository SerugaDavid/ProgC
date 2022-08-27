
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

int** ap2pp(int(*kazalec)[N], int izvornoStVrstic, int ciljnoStVrstic) {
    int st_elemenov = N * izvornoStVrstic;
    int len_vrstice = st_elemenov / ciljnoStVrstic;
    // 2d arr v 1d
    int flat[st_elemenov];
    for (int vrstica = 0; vrstica < izvornoStVrstic; vrstica++) {
        for (int stolpec = 0; stolpec < N; stolpec++) {
            flat[vrstica * N + stolpec] = kazalec[vrstica][stolpec];
        }
    }
    // 1d v 2d druge dimenzije
    int ** out = calloc(ciljnoStVrstic, sizeof(int *));
    for (int vrstica = 0; vrstica < ciljnoStVrstic; vrstica++) {
        *(out + vrstica) = calloc(len_vrstice + 1, sizeof(int));
        for (int stolpec = 0; stolpec < len_vrstice; stolpec++) {
            *(*(out + vrstica) + stolpec) = flat[vrstica * len_vrstice + stolpec];
        }
    }
    return out;
}

int prestej_elemente(int** kazalec, int izvornoStVrstic) {
    int count = 0;
    for (int vrstica = 0; vrstica < izvornoStVrstic; vrstica++) {
        for (int stolpec = 0; kazalec[vrstica][stolpec] != 0; stolpec++) {
            count++;
        }
    }
    return count;
}

int (*pp2ap(int** kazalec, int izvornoStVrstic, int* ciljnoStVrstic))[N] {
    int st_elemenov = prestej_elemente(kazalec, izvornoStVrstic); // preštej elemente
    *ciljnoStVrstic = st_elemenov / N; // izračunaj število vrstic
    if (N * (*ciljnoStVrstic) != st_elemenov) // če je vrstic premalo -> dodaj eno
        *ciljnoStVrstic += 1;
    int * flat = calloc((*ciljnoStVrstic) * N, sizeof(int)); // naredi 1d prazen array

    // prepiši vse elemente v ta array
    int index = 0;
    for (int vrstica = 0; vrstica < izvornoStVrstic; vrstica++) {
        for (int stolpec = 0; kazalec[vrstica][stolpec] != 0; stolpec++) {
            flat[index++] = kazalec[vrstica][stolpec];
        }
    }

    // 1d -> 2d prave velikosti
    int (*out)[N] = calloc(*ciljnoStVrstic, sizeof(int*));
    for (int vrstica = 0; vrstica < *ciljnoStVrstic; vrstica++) {
        for (int stolpec = 0; stolpec < N; stolpec++) {
            out[vrstica][stolpec] = flat[vrstica * N + stolpec];
        }
    }
    return out;
}

int __main__() {
    // wtf nevem zakaj mi testa 8 in 10 nedelata
    return 0;
}
