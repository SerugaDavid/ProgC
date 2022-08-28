#include <stdio.h>
#include <stdlib.h>

int max_int(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int max_cena(int V, int n, int * prostornine, int * cene, int curr_V, int curr_cena, int curr_ind) {
    if (curr_V >= V || curr_ind >= n)
        return curr_cena;
    int max_price = curr_cena;
    int tmp;
    for (int i = curr_ind; i < n; i++) {
        tmp = max_cena(V, n, prostornine, cene, prostornine[i] + curr_V, cene[i] + curr_cena, i + 1);
        max_price = max_int(max_price, tmp);
    }
    return max_price;
}

int main() {
    int V, n;
    scanf("%d", &V);
    scanf("%d", &n);

    int * prostornine = calloc(n, sizeof(int));
    int * cene = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &prostornine[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &cene[i]);

    int cena = max_cena(V, n, prostornine, cene, 0, 0, 0);
    printf("%d\n", cena);
    return 0;
}