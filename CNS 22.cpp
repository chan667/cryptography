#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t plaintext[] = {0b00000001, 0b00100011};  
    uint8_t key = 0b0111111101;  
    uint8_t iv = 0b10101010;  
    uint8_t ciphertext[2], decrypted[2];
    uint8_t prev = iv;

    for (int i = 0; i < 2; i++) {
        uint8_t input = plaintext[i] ^ prev;
        ciphertext[i] = (input ^ key) & 0xFF;  
        prev = ciphertext[i];
    }

    printf("Encrypted: ");
    for (int i = 0; i < 2; i++) printf("%08b ", ciphertext[i]);
    printf("\n");

    prev = iv;
    for (int i = 0; i < 2; i++) {
        uint8_t decrypted_block = (ciphertext[i] ^ key) & 0xFF;  
        decrypted[i] = decrypted_block ^ prev;
        prev = ciphertext[i];
    }

    printf("Decrypted: ");
    for (int i = 0; i < 2; i++) printf("%08b ", decrypted[i]);
    printf("\n");

    return 0;
}

