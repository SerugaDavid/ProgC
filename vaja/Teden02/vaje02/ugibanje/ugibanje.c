#include <stdio.h>

int main() {
    int spodnja, zgornja, trenutni, vhod;
    int konec = 0;
    scanf("%d %d", &spodnja, &zgornja); // preberemo spodnjo in zogrnjo
    trenutni = (zgornja - spodnja) / 2 + spodnja;
    scanf("%d", &vhod); // preberemo prvi uporabnikov odgovor
    while (vhod != 0) // ponavljamo do 0
    {
        // če sta spodnja in zgornja meja isti brez, da bi uporabnik napisal nič potem je nekaj narobe
        if (spodnja == zgornja) { 
            konec = 1;
            printf("PROTISLOVJE\n");
            break;
        }
        // popravimo meje glede na uporabnikov odgovor
        if (vhod == 1) 
            spodnja = trenutni + 1;
        else
            zgornja = trenutni - 1;
        // nastavimo nov ugib
        trenutni = (zgornja - spodnja) / 2 + spodnja;
        scanf("%d", &vhod); // preberemo nov vnos
    }

    if (!konec) { // če ni bilo napake v zgornji zanki se ta if izvede
        if (trenutni == spodnja || trenutni == zgornja) // preverimo če smo našli število
            printf("%d\n", trenutni);
        else // če nismo izpišemo meje
            printf("%d %d\n", spodnja, zgornja);
    }
    return 0;
}
