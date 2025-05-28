#include <stdio.h>
#include <stdint.h>

int main() {
    int block_size = 128;
    uint8_t L[16] = {0}, K1[16], K2[16];
    uint8_t R_b = (block_size == 64) ? 0x1B : 0x87;
    
    for (int i = 0; i < 16; i++) {
        K1[i] = (L[i] << 1) | ((i < 15) ? (L[i + 1] >> 7) : 0);
    }
    
    if (L[0] & 0x80) {
        K1[15] ^= R_b;
    }

    for (int i = 0; i < 16; i++) {
        K2[i] = (K1[i] << 1) | ((i < 15) ? (K1[i + 1] >> 7) : 0);
    }

    if (K1[0] & 0x80) {
        K2[15] ^= R_b;
    }

    for (int i = 0; i < 16; i++) {
        printf("%02X ", K1[i]);
    }

    printf("\n");

    for (int i = 0; i < 16; i++) {
        printf("%02X ", K2[i]);
    }

    printf("\n");

    return 0;
}

