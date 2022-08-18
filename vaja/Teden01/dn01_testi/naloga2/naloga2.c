#include <stdio.h>

void writeInt(int out, int depth) {
    if (out == 0) {
        if (depth == 0) {
            putchar('0');
        }
        return;
    }
    if (out < 0) {
        putchar('-');
        out *= -1;
    }
    writeInt(out/10, depth + 1);
    putchar((out%10) + '0');
}

int main() {
    int index = -1;
    int dodatek = 0;
    char curr;
    while((curr = getchar()) == '0' || curr == '1') {
        //printf("%d:'%c'", index, curr);
        if (curr == '1' && !dodatek) {
            if (index != -1){
                dodatek = 1;
            }
            index++;
            continue;
        }
        if (index >= 0)
            index++;
    }
    if (dodatek)
        index++;
    writeInt(index, 0);
    putchar('\n');
    return 0;
}