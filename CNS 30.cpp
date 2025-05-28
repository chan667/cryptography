#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t key = 0x5A;  
    uint8_t X = 0x3C;  
    uint8_t T, forged_mac;

    T = X ^ key;  

    uint8_t second_block = X ^ T;  
    forged_mac = second_block ^ key;  

    printf("CBC-MAC of one-block message X: %02X\n", T);
    printf("CBC-MAC of two-block message X || (X ? T): %02X\n", forged_mac);

    return 0;
}

