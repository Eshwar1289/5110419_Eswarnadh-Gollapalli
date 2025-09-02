GRID CHALLENGES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparison function for qsort
int cmpfunc(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

void gridChallenge(char grid[][101], int n) {
    // Step 1: Sort each row
    for (int i = 0; i < n; i++) {
        qsort(grid[i], strlen(grid[i]), sizeof(char), cmpfunc);
    }

    // Step 2: Check columns
    for (int col = 0; col < n; col++) {
        for (int row = 0; row < n - 1; row++) {
            if (grid[row][col] > grid[row + 1][col]) {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        char grid[101][101]; // assuming max size is 100x100
        for (int i = 0; i < n; i++) {
            scanf("%s", grid[i]);
        }

        gridChallenge(grid, n);
    }

    return 0;
}
