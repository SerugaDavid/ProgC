#include <stdio.h>
#include <stdlib.h>

void switch_positon(int a, int b, int * prostornine, int * cene) {
    int tmpP = prostornine[a];
    int tmpC = cene[a];
    prostornine[a] = prostornine[b];
    cene[a] = cene[b];
    prostornine[b] = tmpP;
    cene[b] = tmpC;
}

void sort_arr(int n, int * prostornine, int * cene) {
    for (int end = n; end > 0; end--) {
        for (int i = 1; i < end; i++) {
            if (cene[i] > cene[i-1])
                switch_positon(i, i-1, prostornine, cene);
        }
    }
}

int max_int(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int max_cena2(int V, int n, int * prostornine, int * cene, int curr_V, int curr_cena, int curr_ind) {
    if (curr_V > V)
        return 0;
    if (curr_V == V)
        return curr_cena;
    int max_price = curr_cena;
    int tmp;
    for (int i = curr_ind + 1; i < n; i++) {
        tmp = max_cena2(V, n, prostornine, cene, curr_V + prostornine[i], curr_cena + cene[i], i);
        max_price = max_int(max_price, tmp);
    }
    return max_price;
}

void print_arr(int * arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d, ", arr[i]);
    printf("\n");
}

int main() {
    /*  ma dela sam na pou
        sam je časovna zahtevnost n^2
        testi 6-10 so super veliki,
        6 - 50  ->  2500
        7 - 100 ->  10000
        8 - 100 ->  10000
        9 - 500 ->  250000
        10- 1000->  1000000
    */
    int V, n, k;
    scanf("%d", &V);
    scanf("%d", &n);
    scanf("%d", &k);

    int * prostornine = calloc(n, sizeof(int));
    int * cene = calloc(n, sizeof(int));
    
    for (int i = 0; i < n; i++)
        scanf("%d", &prostornine[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &cene[i]);
    
    sort_arr(n, prostornine, cene);

    print_arr(prostornine, n);
    print_arr(cene, n);
    
    int cena;
    cena = max_cena2(V, n, prostornine, cene, 0, 0, -1);
    printf("%d\n", cena);
    return 0;
}