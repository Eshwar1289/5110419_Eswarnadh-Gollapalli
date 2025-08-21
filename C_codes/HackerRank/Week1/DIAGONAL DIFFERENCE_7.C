DIAGONAL DIFFERENCE

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long primary = 0, secondary = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            if (i == j) primary += x;                // main diagonal
            if (i + j == n - 1) secondary += x;      // anti-diagonal
        }
    }

    long long diff = primary - secondary;
    if (diff < 0) diff = -diff;

    printf("%lld\n", diff);
    return 0;
}
