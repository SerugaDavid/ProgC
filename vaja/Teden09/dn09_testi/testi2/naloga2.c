
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "naloga2.h"

int abs(int a) {
    if (a < 0)
        return -a;
    return a;
}

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

Ulomek obrni(Ulomek a) {
    return (Ulomek) {a.im, a.st};
}

Ulomek negiraj(Ulomek a) {
    return (Ulomek) {-a.st, a.im};
}

Ulomek zmnozi(Ulomek a, Ulomek b) {
    return (Ulomek) {a.st * b.st, a.im * b.im};
}

Ulomek deljeno(Ulomek a, Ulomek b) {
    return zmnozi(a, obrni(b));
}

Ulomek sestej(Ulomek a, Ulomek b) {
    int im = a.im * b.im;
    int st = a.st * b.im + b.st * a.im;
    return (Ulomek) {st, im};
}

Ulomek odstej(Ulomek a, Ulomek b) {
    return sestej(a, negiraj(b));
}

int nsd(int a, int b) {
    int min_start = min(abs(a), abs(b));
    for (int i = min_start; i >= 1; i--) {
        if (a%i == 0 && b%i == 0)
            return i;
    }
    return 1;
}

Ulomek okrajsaj(Ulomek a) {
    int delitelj = nsd(a.im, a.st);
    Ulomek out = (Ulomek) {a.st / delitelj, a.im / delitelj};
    if (out.im < 0) {
        out.st = -out.st;
        out.im = -out.im;
    }
    return out;
}


Tocka projekcija(Tocka t, Premica p) {
    if (p.navpicna)
        return (Tocka) {p.n, t.y};
    if (!p.k.st)
        return (Tocka) {t.x, p.n};
    
    // nova premica
    Ulomek k = negiraj(obrni(p.k));
    Ulomek n = sestej(t.y, zmnozi(negiraj(k), t.x));
    
    // nova tocka
    Ulomek x = deljeno(odstej(n, p.n), odstej(p.k, k));
    Ulomek y = sestej(zmnozi(p.k, x), p.n);

    return (Tocka) {okrajsaj(x), okrajsaj(y)};
}

int __main__() {
    return 0;
}
