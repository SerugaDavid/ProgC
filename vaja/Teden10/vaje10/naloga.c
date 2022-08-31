
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int vsotaI(Vozlisce* zacetek) {
    int sum = 0;
    Vozlisce* tmp = zacetek;
    while (tmp != NULL) {
        sum += tmp->podatek;
        tmp = tmp->naslednje;
    }
    return sum;
}

int vsotaR(Vozlisce* zacetek) {
    if (zacetek == NULL)
        return 0;
    return zacetek->podatek + vsotaR(zacetek->naslednje);
}

Vozlisce* vstaviUrejenoI(Vozlisce* zacetek, int element) {
    Vozlisce * out = calloc(1, sizeof(Vozlisce));
    out->podatek = element;
    out->naslednje = NULL;
    
    if (zacetek == NULL)
        return out;

    Vozlisce * tmp = zacetek;
    Vozlisce * prev = NULL;

    while (tmp != NULL) {
        if (element < tmp->podatek) {
            if (prev == NULL) {
                out->naslednje = zacetek;
                return out;
            }
            out->naslednje = tmp;
            prev->naslednje = out;
            return zacetek;
        }
        prev = tmp;
        tmp = tmp->naslednje;
    }

    prev->naslednje = out;
    
    return zacetek;
}

Vozlisce* vstaviUrejenoR(Vozlisce* zacetek, int element) {
    if (zacetek == NULL) {
        Vozlisce * out = calloc(1, sizeof(Vozlisce));
        out->naslednje = NULL;
        out->podatek = element;
        return out;
    }
    if (element < zacetek->podatek) {
        Vozlisce * out = calloc(1, sizeof(Vozlisce));
        out->naslednje = zacetek;
        out->podatek = element;
        return out;
    }
    zacetek->naslednje = vstaviUrejenoR(zacetek->naslednje, element);
    return zacetek;
}

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}
