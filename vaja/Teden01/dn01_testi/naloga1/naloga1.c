#include <stdio.h>

int readInt() {
    int out = 0;
    int negate = 1;
    char curr = getchar();
    if (curr == '-')
        negate = -1;
    else
        out = curr - '0';
    while ((curr = getchar()) >= '0' && curr <= '9') {
        out *= 10;
        out += curr - '0';
    }
    return out * negate;
}

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
    int a = readInt();
    int b = readInt();
    int out = a + b;
    writeInt(out, 0);
    putchar('\n');
    return 0;
}
