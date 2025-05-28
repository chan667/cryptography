#include <stdio.h>

int main() {
    int n = 3599;  
    int plaintext_block = 59;  
    int p, q;

    p = plaintext_block;  
    q = n / p;  

    int phi = (p - 1) * (q - 1);
    int e = 31;
    int d = 1;

    while ((e * d) % phi != 1) {
        d++;
    }

    printf("Factorized n: p = %d, q = %d\n", p, q);
    printf("Private Key: d = %d\n", d);

    return 0;
}

