
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

/** TO DO 
 * Naj bodo rekurzivne funkcije, ker ima to smisel
 * 
 * kako gradit tak string?
 * ko napišeš svoje veš kok je dolgo, tk da ko kličeš rekurzivno naprej sam podaj cilj, ki je cilj + dolžina trenutnega stringa
 * in za njim zaključiš zaklepaje
 * 
 * returnaš svojo dolžino + rekurzivno dolžino
 * 
 * funkcije:
 * izpisiA(A* a, char* cilj);
 * izpisiB(B* b, char* cilj);
 * izpisiC(C* c, char* cilj);
 * 
 * done
 * **/

int izpisiA(A* a, char* cilj);
int izpisiB(B* b, char* cilj);
int izpisiC(C* c, char* cilj);

int izpisiA(A* a, char* cilj) {
    if (a == NULL) { // NULL vrednost, recursion stop
        sprintf(cilj, "NULL");
        return 4;
    }
    // convert int to string, get length
    char * p = calloc(13, sizeof(char));
    sprintf(p, "%d", a->p);
    int curr_len = 1 + strlen(p) + 2;
    // izpis
    sprintf(cilj, "{%s, ", p);
    curr_len += izpisiB(a->b, cilj + curr_len); // rekurzivni klic
    sprintf(cilj + curr_len, "}");
    return ++curr_len;
}

int izpisiB(B* b, char* cilj) {
    if (b == NULL) { // NULL vrednost, recursion stop
        sprintf(cilj, "NULL");
        return 4;
    }
    // get len
    int curr_len = 1 + strlen(b->q) + 2;
    // izpis
    sprintf(cilj, "{%s, ", b->q);
    curr_len += izpisiC(b->c, cilj + curr_len); // rekurzivni klic
    sprintf(cilj + curr_len, "}");
    return ++curr_len;
}

int izpisiC(C* c, char* cilj) {
    if (c == NULL) { // NULL vrednost, recursion stop
        sprintf(cilj, "NULL");
        return 4;
    }
    // bool to str, get len
    char * r = calloc(6, sizeof(char));
    if (c->r)
        sprintf(r, "true");
    else
        sprintf(r, "false");
    int curr_len = 1 + strlen(r) + 2;
    // izpis
    sprintf(cilj, "{%s, ", r);
    // A
    curr_len += izpisiA(c->a, cilj + curr_len);
    sprintf(cilj + curr_len, ", ");
    curr_len += 2;
    // B
    curr_len += izpisiB(c->b, cilj + curr_len);
    sprintf(cilj + curr_len, "}");
    return ++curr_len;
}

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}
