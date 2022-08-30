
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga.h"

int poisciStudenta(Student** studentje, int stStudentov, int vpisna) {
    for (int i = 0; i < stStudentov; i++) {
        if (vpisna == studentje[i]->vpisna)
            return i;
    }
    return -1;
}

int poisciPO(Student* student, char* predmet) {
    int st_parov = student->stPO;
    for (int i = 0; i < st_parov; i++) {
        if (!strcmp(predmet, student->po[i].predmet))
            return i;
    }
    return -1;
}

int dodaj(Student** studentje, int stStudentov, int vpisna, char* predmet, int ocena) {
    int index_studenta = poisciStudenta(studentje, stStudentov, vpisna);
    Student * tmp;
    if (index_studenta != -1) {
        tmp = studentje[index_studenta];
    } else {
        tmp = malloc(sizeof(Student));
        tmp->vpisna = vpisna;
        tmp->stPO = 0;
        tmp->po = calloc(10, sizeof(PO));
        studentje[stStudentov] = tmp;
        stStudentov++;
    }
    int index_PO = poisciPO(tmp, predmet);
    if (index_PO != -1) {
        tmp->po[index_PO].ocena = ocena;
    } else {
        strcat(tmp->po[tmp->stPO].predmet, predmet);
        tmp->po[tmp->stPO].ocena = ocena;
        tmp->stPO += 1;
    }
    return stStudentov;
}








// testing
/*
void izpisi(Student** studentje, int stStudentov) {
    //printf("stStudentov: %d\n", stStudentov);
    for (int i = 0;  i < stStudentov;  i++) {
        printf("%d: [", studentje[i]->vpisna);
        int stPO = studentje[i]->stPO;
        PO* po = studentje[i]->po;
        for (int j = 0;  j < stPO;  j++) {
            if (j > 0) {
                printf(", ");
            }
            printf("%s/%d", po[j].predmet, po[j].ocena);
        }
        printf("]\n");
    }
    printf("\n");
}

void pocisti(Student* student) {
    free(student->po);
    free(student);
}
*/
int __main__() {
    
    
    // testing
    /*
    Student* studentje[] = {
        (Student[]) {333, (PO[]){{"FIZ", 10}, {"P1", 7}, {"P2", 8}, {"ODV", 9}, {"", 0}}, 4},
        (Student[]) {888, (PO[]){{"", 0}}, 0},
        (Student[]) {555, (PO[]){{"ARS", 6}, {"P2", 8}, {"ODV", 9}, {"", 0}}, 3},
        (Student[]) {111, (PO[]){{"OMA", 9}, {"", 0}}, 1},
        (Student[]) {777, (PO[]){{"P1", 10}, {"P2", 7}, {"", 0}}, 2},
        NULL
    };
    int stStudentov = sizeof(studentje) / sizeof(studentje[0]) - 1;

    izpisi(studentje, stStudentov);
    stStudentov = dodaj(studentje, stStudentov, 444, "ODV", 7);
    izpisi(studentje, stStudentov);

    pocisti(studentje[5]);

    exit(0);


    */
    return 0;
}
