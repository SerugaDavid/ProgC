#include <stdio.h>

int sum_range(int * nums, int start_index, int end_index) {
    int sum = 0;
    for (int i = start_index; i < end_index; i++)
        sum += *(nums + i);
    return sum;
}

void slow_way() {
    int n;
    scanf("%d", &n);
    int nums[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int max_sum = -1000;
    int curr_sum = 0;
    for (int start = 0; start < n; start++) {
        for (int end = start + 1; end <= n; end++) {
            curr_sum = sum_range(nums, start, end);
            if (curr_sum > max_sum)
                max_sum = curr_sum;
        }
    }

    printf("%d\n", max_sum);
}

int max_int(int * nums, int len) {
    int max = -1000;
    for (int i = 0; i < len; i++) {
        if (*(nums + i) > max)
            max = *(nums + i);
    }
    return max;
}

void print_arr(int * nums, int len) {
    for (int i = 0; i < len; i++)
        printf("%d, ", *(nums + i));
    printf("\n");
}

void fast_way_maybe() {
    int n;
    scanf("%d", &n);
    int nums[n];
    
    int indexs[n][2];
    int current_sum = 0;
    int start_index = -1, end_index = -1;
    int position = 0;
    
    for (int i = 0; i < n; i++) {
        end_index = i;
        scanf("%d", &nums[i]);
        if (nums[i] < 0) {
            if (start_index == -1)
                continue;
            indexs[position][0] = start_index;
            indexs[position++][1] = end_index;
            start_index = -1;
        } else {
            if (start_index == -1)
                start_index = i;
            if (i + 1 == n) {
                indexs[position][0] = start_index;
                indexs[position++][1] = end_index + 1;
                break;
            }
        } 
    }

    if (!position) {
        printf("%d\n", max_int(nums, n));
        return;
    }

    int max_sum = 0;
    int curr_sum = 0;
    for (int start = 0; start < position; start++) {
        for (int end = start; end < position; end++) {
            curr_sum = sum_range(nums, indexs[start][0], indexs[end][1]);
            if (curr_sum > max_sum)
                max_sum = curr_sum;
        }
    }
    printf("%d\n", max_sum);
}

int main() {
    fast_way_maybe();
    return 0;
}