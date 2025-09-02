ZIG ZAG SEQUENCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void findZigZagSequence(int arr[], int n) {
    qsort(arr, n, sizeof(int), cmpfunc);

    int mid = (n - 1) / 2;
    int tmp = arr[mid];
    arr[mid] = arr[n - 1];
    arr[n - 1] = tmp;

    int st = mid + 1;
    int ed = n - 2; // reverse only up to n-2 (n-1 currently holds the swapped middle)
    while (st <= ed) {
        tmp = arr[st];
        arr[st] = arr[ed];
        arr[ed] = tmp;
        st++; ed--;
    }

    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    // consume rest of line
    int ch = getchar();
    while (ch != '\n' && ch != EOF) ch = getchar();

    while (t--) {
        int n;
        if (scanf("%d", &n) != 1) break;
        // consume rest of line
        ch = getchar();
        while (ch != '\n' && ch != EOF) ch = getchar();

        int *arr = malloc(sizeof(int) * n);
        int read = 0;
        char line[200000];

        while (read < n) {
            if (!fgets(line, sizeof(line), stdin)) break;
            // skip blank lines
            char *p = line;
            while (*p && isspace((unsigned char)*p)) p++;
            if (*p == '\0') continue;

            char *tok = strtok(line, " \t\r\n");
            while (tok != NULL && read < n) {
                size_t len = strlen(tok);
                int allDigits = (strspn(tok, "0123456789") == len);
                // If token is exactly n digits long and contains only digits,
                // interpret it as concatenated single-digit elements (e.g. "1234567").
                if (read == 0 && allDigits && (int)len == n) {
                    for (int i = 0; i < n; ++i) arr[read++] = tok[i] - '0';
                    break; // we've filled the array
                } else {
                    arr[read++] = atoi(tok);
                }
                tok = strtok(NULL, " \t\r\n");
            }
        }

        findZigZagSequence(arr, n);
        free(arr);
    }
    return 0;
}
