#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int prva[n];
    int druga[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &prva[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &druga[i]);
    }
    int down_ind = 0;
    int curr_ind = -1;
    for (int i = 0; i < n; i++) {
        if (prva[i] == druga[down_ind]) {
            if (curr_ind == -1)
                curr_ind = i;
            down_ind++;
        } else {
            if (curr_ind == -1)
                continue;
            i = curr_ind;
            down_ind = 0;
            curr_ind = -1;
        }
    }
    printf("%d\n", curr_ind);
    return 0;
}