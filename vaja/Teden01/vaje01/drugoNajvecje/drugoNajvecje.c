#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // preberemo n
    // 
    int max = 0;
    int maxSecond = 0;
    int curr;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &curr);
        if (curr >= max)
        {
            maxSecond = max;
            max = curr;
        } else if (curr > maxSecond) {
            maxSecond = curr;
        }
        
    }
    printf("%d\n", maxSecond);
    return 0;
}
