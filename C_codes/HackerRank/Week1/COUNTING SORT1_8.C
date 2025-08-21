COUNTING SORT1

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);   // number of items

    int freq[100] = {0};  // frequency array of size 100

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        freq[x]++;   // increase count for value x
    }

    // print the frequency array
    for (int i = 0; i < 100; i++) {
        printf("%d ", freq[i]);
    }
    printf("\n");

    return 0;
}
