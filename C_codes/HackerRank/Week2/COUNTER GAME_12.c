COUNTER GAME

#include <stdio.h>
#include <stdbool.h>

// Function to check if n is a power of 2
bool isPowerOfTwo(unsigned long long n) {
    return (n && !(n & (n - 1)));
}

// Function to find the largest power of 2 less than n
unsigned long long largestPowerOfTwo(unsigned long long n) {
    unsigned long long p = 1;
    while (p << 1ULL <= n) {
        p <<= 1ULL;
    }
    return p;
}

const char* counterGame(unsigned long long n) {
    int turn = 0;  // 0 = Louise, 1 = Richard

    while (n > 1) {
        if (isPowerOfTwo(n)) {
            n >>= 1;  // divide by 2
        } else {
            n -= largestPowerOfTwo(n);  // subtract largest power of 2
        }
        turn = 1 - turn;  // switch turns
    }

    return (turn == 1) ? "Louise" : "Richard";
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        unsigned long long n;
        scanf("%llu", &n);
        printf("%s\n", counterGame(n));
    }
    return 0;
}
