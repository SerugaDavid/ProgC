#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int nums[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    
    int counter = 0;
    for (int i = 0; i < n-1; i++) {
        if (nums[i] >= k)
            continue;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] >= k)
                continue;
            counter += (nums[i] + nums[j]) == k;
        }
    }
    printf("%d\n", counter);
    return 0;
}
