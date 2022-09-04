#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int preberi_vrstico(FILE * f, char * line) {
    char c;
    size_t n = 0;

    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') {
            line[n] = '\0';
            return 0;
        }
        line[n++] = (char) c;
    }
    line[n] = '\0';
    return 1;
}

int main(int argc, char ** argv) {
    char * vhod = argv[1];
    char * izhod = argv[2];

    // Preberi file
    FILE * fr;
    fr = fopen(vhod, "r");
    char * vrstica = calloc(1000000, sizeof(char));
    char * najdaljsa = calloc(1000000, sizeof(char));
    int max = 0;
    int tmp = 0;
    int end = 0;

    // preberi vrstice
    do
    {
        end = preberi_vrstico(fr, vrstica);
        tmp = strlen(vrstica);
        if (tmp > max) {
            max = tmp;
            najdaljsa[0] = '\0';
            strcat(najdaljsa, vrstica);
        }
    } while (!end);
    fclose(fr);
    
    // zapisi vrstico
    FILE * fw;
    fw = fopen(izhod, "w");
    fprintf(fw, najdaljsa);
    return 0;
}