RECURSIVE DIGIT SUM

#include <stdio.h>
#include <string.h>

// Recursive function to calculate super digit
int superDigitHelper(long long num) {
    if (num < 10) {
        return num;
    }
    long long sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return superDigitHelper(sum);
}

int superDigit(char n[], int k) {
    long long sum = 0;

    // Step 1: Sum of digits of n
    for (int i = 0; i < strlen(n); i++) {
        sum += n[i] - '0';
    }

    // Step 2: Multiply by k
    sum *= k;

    // Step 3: Find super digit recursively
    return superDigitHelper(sum);
}

int main() {
    char n[100001];  // n can be large, so keep as string
    int k;
    scanf("%s %d", n, &k);

    printf("%d\n", superDigit(n, k));

    return 0;
}
