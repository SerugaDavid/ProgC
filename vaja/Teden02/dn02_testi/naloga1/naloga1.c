#include <stdio.h>

int main() {
    char c = getchar();
    char prev = ' ';
    char prevPrev = ' ';
    int notFailed = 1;
    while (c != '\n') {
        if (c == ' ') {
            if (prev == '+' || prev == '-')
                notFailed = 0;
            putchar('0' + notFailed);
            prevPrev = prev;
            prev = c;
            c = getchar();
            notFailed = 1;
            continue;
        }
        if (!notFailed) {
            prevPrev = prev;
            prev = c;
            c = getchar();
            continue;
        }
        if (c == '-' || c == '+') {
            if (!(prev == ' '))
                notFailed = 0;
        } else if (c == '0') {
            if (!(prev == ' ' || prev == '-' || prev == '+' || (prev >= '1' && prev <= '9') || (prev == '0' && prevPrev >= '0' && prevPrev <= '9')))
                notFailed = 0;
        } else if (c >= '1' && c <= '9') {
            if (!(prev == ' ' || prev == '-' || prev == '+' || (prev >= '1' && prev <= '9') || (prev == '0' && prevPrev >= '0' && prevPrev <= '9')))
                notFailed = 0;
        } else {
            notFailed = 0;
        }
        prevPrev = prev;
        prev = c;
        c = getchar();
    }
    if (prev == '+' || prev == '-')
        notFailed = 0;
    putchar('0' + notFailed);
    putchar('\n');
    return 0;
}