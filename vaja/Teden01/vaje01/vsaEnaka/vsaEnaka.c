#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // preberemo n
    // nastavimo pomožne spremenljivke
    int prev = -1;
    int curr = -1;
    int done = 1;
    // preberemo vsa števila
    for (int i = 0; i < n; i++) {
        if (prev == -1) { // če nimamo prvega števila ga shranimo in skočimo v novo iteracijo zanke
            scanf("%d", &prev);
            continue;
        }
        scanf("%d", &curr); // shranimo trenutno število
        if (prev != curr) { // če prvo število ni enako trenutnemu končamo zanko
            done = 0;
            break;
        }
    }
    printf("%d\n", done); // izpišemo rešitev
    return 0;
}
