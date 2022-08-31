
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga1.h"

int get_ocena(Student* student, char * predmet) {
    for (int i = 0; i < student->stPO; i++) {
        if (!strcmp(student->po[i].predmet, predmet))
            return student->po[i].ocena;
    }
    return 0;
}

void switch_element(int a, int b, VO ** opravljeni) {
    VO * tmp = opravljeni[a];
    opravljeni[a] = opravljeni[b];
    opravljeni[b] = tmp;
}

void sort_VO(VO ** opravljeni, int st_opravljenih) {
    for (int end = st_opravljenih; end > 0; end--) {
        for (int i = 1; i < end; i++) {
            if (opravljeni[i]->ocena > opravljeni[i-1]->ocena || (opravljeni[i]->ocena == opravljeni[i-1]->ocena && opravljeni[i]->vpisna < opravljeni[i-1]->vpisna))
                switch_element(i-1, i, opravljeni);
        }
    }
}

VO** opravili(Student** studentje, int stStudentov, char* predmet, int* stVO) {
    VO ** out = calloc(stStudentov, sizeof(VO *));
    int st_opravljenih = 0;
    int ocena;

    VO * tmp;
    for (int i = 0; i < stStudentov; i++) {
        if ((ocena = get_ocena(studentje[i], predmet)) >= 6) {
            tmp = malloc(sizeof(VO));
            tmp->ocena = ocena;
            tmp->vpisna = studentje[i]->vpisna;
            out[st_opravljenih++] = tmp;
        }
    }

    *stVO = st_opravljenih;
    sort_VO(out, st_opravljenih);
    return out;
}

int __main__() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}
