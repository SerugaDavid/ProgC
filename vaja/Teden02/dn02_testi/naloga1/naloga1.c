#include <stdio.h>

char * read_word(char out[1000]) {
    //char out[1000];
    char c = getchar();
    for (int i = 0; i < 1000; i++)
    {
        out[i] = c;
        if (c == '\n' || c == ' ')
            break;
        c = getchar();
    }
    return out;
}

int end(char * word) {
    char c;
    for (int i = 0; i < 1000; i++)
    {
        c = *(word + i);
        if (c == '\n')
            return 1;
        if (c == ' ')
            break;
    }
    return 0;    
}

int main() {
    char * word;
    do
    {
        word = read_word(word);
        printf("%s\n", word);
    } while (!end(word));
    
    
    
    return 0;
}