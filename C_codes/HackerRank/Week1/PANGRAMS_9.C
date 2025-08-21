PANGRAMS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1005];
    // read full line including spaces
    fgets(s, sizeof(s), stdin);

    int seen[26] = {0};
    int uniqueCount = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i])) {
            char c = tolower(s[i]);
            int index = c - 'a';
            if (!seen[index]) {
                seen[index] = 1;
                uniqueCount++;
            }
        }
    }

    if (uniqueCount == 26)
        printf("pangram\n");
    else
        printf("not pangram\n");

    return 0;
}
