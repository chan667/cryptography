#include <stdio.h>

int main() {
    int p = 59, q = 61;
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 31;
    int d = 1;

    while ((e * d) % phi != 1) {
        d++;
    }

    printf("Public Key: (e = %d, n = %d)\n", e, n);
    printf("Private Key: d = %d\n", d);

    return 0;
}

