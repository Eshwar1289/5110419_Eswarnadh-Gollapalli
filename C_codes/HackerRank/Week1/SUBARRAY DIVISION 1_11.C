SUBARRAY DIVISION 1

#include <stdio.h>

int birthday(int s[], int n, int d, int m) {
    int count = 0;
    // Traverse all possible segments of length m
    for (int i = 0; i <= n - m; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += s[i + j];
        }
        if (sum == d) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);   // number of squares

    int s[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);   // chocolate squares
    }

    int d, m;
    scanf("%d %d", &d, &m);   // d = Ron's birth day, m = Ron's birth month

    int result = birthday(s, n, d, m);
    printf("%d\n", result);

    return 0;
}