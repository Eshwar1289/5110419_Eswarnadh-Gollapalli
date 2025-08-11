### SPARSEARRAY ### 

#include <stdio.h>
#include <string.h>

int main() {
    int n, q;
    scanf("%d", &n);

    char strings[n][21];  // each string max 20 chars + 1 for '\0'
    for(int i=0; i<n; i++) {
        scanf("%s", strings[i]);
    }

    scanf("%d", &q);
    char queries[q][21];
    for(int i=0; i<q; i++) {
        scanf("%s", queries[i]);
    }

    // result array
    int results[q];
    for(int i=0; i<q; i++) {
        int count = 0;
        for(int j=0; j<n; j++) {
            if(strcmp(queries[i], strings[j]) == 0) {
                count++;
            }
        }
        results[i] = count;
    }

    for(int i=0; i<q; i++) {
        printf("%d\n", results[i]);
    }
    return 0;
}
