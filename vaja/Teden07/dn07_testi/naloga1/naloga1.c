#include <stdio.h>
#include <stdlib.h>

int max(int left, int right) {
    if (left > right)
        return left;
    return right;
}

int visina_drevesa(int n, int * vozlisca, int curr_h, int curr_ind) {
    if (curr_ind > n || curr_ind < 0)
        return -1;
    int left = curr_h;
    int right = curr_h;
    if (vozlisca[curr_ind * 2] != 0) {
        left = visina_drevesa(n, vozlisca, curr_h + 1, curr_ind + vozlisca[curr_ind * 2]);
    }
    if (vozlisca[curr_ind * 2 + 1] != 0) {
        right = visina_drevesa(n, vozlisca, curr_h + 1, curr_ind + vozlisca[curr_ind * 2 + 1]);
    }
    return max(left, right);
}

int main() {
    int n;
    scanf("%d", &n);
    int * vozlisca = calloc(n * 2, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &vozlisca[i*2], &vozlisca[i*2 + 1]);
    }

    int height = visina_drevesa(n, vozlisca, 0, 0);
    printf("%d\n", height);
}