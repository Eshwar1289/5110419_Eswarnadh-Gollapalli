###miniMaxSum###

#include <stdio.h>
#include <limits.h>

int main() {
    int arr[5];
    long long total = 0;
    int min = INT_MAX;
    int max = INT_MIN;

    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
        total += arr[i];
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    printf("%lld %lld", total - max, total - min);
    return 0;
}
