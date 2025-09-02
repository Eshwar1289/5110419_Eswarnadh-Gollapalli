CAESAR CIPHER

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void caesarCipher(char s[], int k) {
    int n = strlen(s);
    k = k % 26; // rotation factor reduced within alphabet range
    for (int i = 0; i < n; i++) {
        if (isalpha(s[i])) {
            if (islower(s[i])) {
                s[i] = ((s[i] - 'a' + k) % 26) + 'a';
            } else if (isupper(s[i])) {
                s[i] = ((s[i] - 'A' + k) % 26) + 'A';
            }
        }
        // if not a letter, leave unchanged
    }
}

int main() {
    int n, k;
    char s[1000];
    
    scanf("%d", &n);      // length of string (not strictly needed)
    scanf("%s", s);       // input string
    scanf("%d", &k);      // rotation factor
    
    caesarCipher(s, k);
    
    printf("%s\n", s);
    return 0;
}
