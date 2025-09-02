SALES BY MATCH

#include <stdio.h>

int sockMerchant(int n, int ar[]) {
    int count[101] = {0};  // Since 1 <= ar[i] <= 100
    int pairs = 0;

    // Count frequency of each sock color
    for (int i = 0; i < n; i++) {
        count[ar[i]]++;
    }

    // Count pairs
    for (int i = 1; i <= 100; i++) {
        pairs += count[i] / 2;
    }

    return pairs;
}

int main() {
    int n;
    scanf("%d", &n);   // Number of socks
    
    int ar[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);   // Sock colors
    }

    int result = sockMerchant(n, ar);
    printf("%d\n", result);

    return 0;
}