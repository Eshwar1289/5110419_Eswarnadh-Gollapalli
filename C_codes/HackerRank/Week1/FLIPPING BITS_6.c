FLIPPING BITS

#include <stdio.h>

unsigned int flippingBits(unsigned int n) {
    return n ^ 0xFFFFFFFF; // XOR with all 1's
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        unsigned int n;
        scanf("%u", &n);
        printf("%u\n", flippingBits(n));
    }
    return 0;
}
