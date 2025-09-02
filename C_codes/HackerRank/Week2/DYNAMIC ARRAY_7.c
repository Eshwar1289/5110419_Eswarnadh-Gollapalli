DYNAMIC ARRAY

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    // Allocate n sequences
    int **seq = (int **)malloc(n * sizeof(int *));
    int *sizes = (int *)calloc(n, sizeof(int)); // size of each sequence
    int *capacities = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        capacities[i] = 2; // initial capacity
        seq[i] = (int *)malloc(capacities[i] * sizeof(int));
    }

    int lastAnswer = 0;

    for (int i = 0; i < q; i++) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);

        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            // Ensure enough space
            if (sizes[idx] >= capacities[idx]) {
                capacities[idx] *= 2;
                seq[idx] = (int *)realloc(seq[idx], capacities[idx] * sizeof(int));
            }
            seq[idx][sizes[idx]++] = y;
        } else if (type == 2) {
            int value = seq[idx][y % sizes[idx]];
            lastAnswer = value;
            printf("%d\n", lastAnswer);
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(seq[i]);
    }
    free(seq);
    free(sizes);
    free(capacities);

    return 0;
}
