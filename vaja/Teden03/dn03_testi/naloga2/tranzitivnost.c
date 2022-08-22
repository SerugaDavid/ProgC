
/*

Prevajanje in poganjanje:

gcc -o test01 test01.c tranzitivnost.c -lm
./test01

*/

#include <stdio.h>
#include <stdbool.h>

#include "tranzitivnost.h"

int tranz(int x, int y, int z) {
    if (f(x, y) && f(y, z))
        return f(x, z);
    return 0;
}

int antiTranz(int x, int y, int z) {
    if (f(x, y) && f(y, z))
        return !f(x, z);
    return 0;
}

int neTranz(int x, int y, int z) {
    return f(x, y) && f(y, z) && !f(x, z);
}

int tranzitivnost(int a, int b) {
    int tr = 0;
    int an = 0;
    int ne = 0;
    
    int br = 0;

    for (int x = a; x <= b; x++) {
        for (int y = a; y <= b; y++) {
            for (int z = a; z <= b; z++) {
                if (!tr && tranz(x, y, z)) {
                    tr = 1;
                }
                if (!an && antiTranz(x, y, z)) {
                    an = 1;
                }
                if (!ne && neTranz(x, y, z)) {
                    ne = 1;
                }
                if (!tr && !an && ne) {
                    br = 1;
                    break;
                }
            }
            if (br)
                break;
        }
        if (br)
            break;
    }

    if (tr && an)
        return 1;
    else if (tr)
        return 2;
    else if (an)
        return 3;
    else if (ne)
        return 4;
    return -1;
}

// Ta datoteka NE SME vsebovati funkcij main in f!
// Funkciji main in f sta definirani v datoteki test01.c.
