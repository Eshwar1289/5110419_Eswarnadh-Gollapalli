XOR STRINGS2

#include <stdio.h>
#include <string.h>

void strings_xor(char *s, char *t, char *result) {
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i])
            result[i] = '0';   // same bits -> 0
        else
            result[i] = '1';   // different bits -> 1
    }
    result[n] = '\0'; // null terminate string
}

int main() {
    char s[10001], t[10001], result[10001];
    scanf("%s", s);
    scanf("%s", t);
    
    strings_xor(s, t, result);
    printf("%s\n", result);
    
    return 0;
}