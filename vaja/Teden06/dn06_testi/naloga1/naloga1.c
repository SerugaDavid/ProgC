
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

int * dolzina_nizov(char ** nizi) {
    int * out = malloc(sizeof(int) * 2);
    out[0] = 0;
    for (out[1] = 0; nizi[out[1]] != NULL; out[1]++)
        out[0] += strlen(nizi[out[1]]);
    return out;
}

char* zdruzi(char** nizi, char* locilo) {
    int * dolzine = dolzina_nizov(nizi);
    int len_locilo = strlen(locilo);
    char * out_str = (char *)calloc(dolzine[0] + dolzine[1] * len_locilo + 1, sizeof(char));
    for (int i = 0; i < dolzine[1]; i++) {
        strcat(out_str, nizi[i]);
        if (i != dolzine[1]-1)
            strcat(out_str, locilo);
    }
    strcat(out_str, "\0");
    return out_str;
}

int main() {

    
    char * nizi[4] = {"1", "23", "456", NULL};
    int * len = dolzina_nizov(nizi);
    char * joined = zdruzi(nizi, "-");
    printf("len:%d - num:%d\n%s\n", len[0], len[1], joined);
    printf("\n");
    return 0;
}
