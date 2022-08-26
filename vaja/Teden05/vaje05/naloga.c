
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

int vsota(int* zac, int* kon) {
    int sum = 0;
    for (int i = 0; i <= kon - zac; i++) {
        sum += *(zac + i);
    }
    return sum;
}

void indeksInKazalec(int* t, int* indeks, int** kazalec) {
    if (*indeks == -1)
        *indeks = *kazalec - t;
    else
        *kazalec = t + *indeks;
}

void frekvenceCrk(char* niz, int** frekvence) {
    int * nova = malloc(sizeof(int) * ('z' - 'a' + 1));
    int ind;
    char c;
    
    for (int i = 0; i < 'z' - 'a' + 1; i++)
        *(nova + i) = 0;
    
    *frekvence = nova;

    for (int i = 0; (c = *(niz + i)) != '\0'; i++) {
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
            continue;
        if (c >= 'a')
            ind = c - 'a';
        else 
            ind = c - 'A';
        *(nova + ind) += 1;
    }
}

int main() {
    // meh
    return 0;
}
