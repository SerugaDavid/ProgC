
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int steviloZnakov(char* niz, char znak) {
    int count = 0;
    char c;
    for (int i = 0; (c = *(niz + i)) != '\0'; i++)
        count += c == znak;
    return count;
}

int dolzina(char * niz, char znak) {
    int count = -1;
    char c;
    while ((c = *(niz + ++count)) != '\0' && c != znak) {}
    return count;
}

char* kopirajDoZnaka(char* niz, char znak) {
    int len = dolzina(niz, znak);
    char *nov = malloc(sizeof(char) * len + 1);
    char c;
    int i;
    for (i = 0; (c = *(niz + i)) != znak && c != '\0'; i++)
        nov[i] = c;
    nov[i] = '\0';
    return nov;
}

char** razcleni(char* niz, char locilo, int* stOdsekov) {
    *stOdsekov = steviloZnakov(niz, locilo) + 1;
    char **razclenjen = malloc(sizeof(char*) * (*stOdsekov));
    char * tmp_word;
    int len = 0;

    for (int i = 0; i < *stOdsekov; i++) {
        tmp_word = kopirajDoZnaka(niz + len, locilo);
        len += dolzina(tmp_word, '\0') + 1;
        razclenjen[i] = tmp_word;
    }
    return razclenjen;
}

int main() {
    char* niz = "prijazen niz z enim samim presledkom med besedami";
    int stOdsekov = 0;
    char** odseki = razcleni(niz, ' ', &stOdsekov);
    for (int i = 0;  i < stOdsekov;  i++) {
        printf("%d: <%s>\n", i + 1, odseki[i]);
        free(odseki[i]);
    }
    free(odseki);
    return 0;
}
