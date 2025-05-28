#include <stdio.h>

int main() {
    int p = 67, q = 71;  
    int n = p * q;  
    int phi = (p - 1) * (q - 1);  
    int e = 31;  
    int d = 1;

    while ((e * d) % phi != 1) {
        d++;
    }

    printf("New Modulus: n = %d\n", n);
    printf("New Public Key: (e = %d, n = %d)\n", e, n);
    printf("New Private Key: d = %d\n", d);

    return 0;
}

