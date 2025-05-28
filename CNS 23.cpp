#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t plaintext[] = {0b00000001, 0b00000010, 0b00000100};  
    uint8_t key = 0b0111111101;  
    uint8_t counter = 0b00000000;  
    uint8_t ciphertext[3], decrypted[3];

    for (int i = 0; i < 3; i++) {
        uint8_t keystream = (counter ^ key) & 0xFF;  
        ciphertext[i] = plaintext[i] ^ keystream;
        counter++;
    }

    printf("Encrypted: ");
    for (int i = 0; i < 3; i++) printf("%08b ", ciphertext[i]);
    printf("\n");

    counter = 0b00000000;
    for (int i = 0; i < 3; i++) {
        uint8_t keystream = (counter ^ key) & 0xFF;  
        decrypted[i] = ciphertext[i] ^ keystream;
        counter++;
    }

    printf("Decrypted: ");
    for (int i = 0; i < 3; i++) printf("%08b ", decrypted[i]);
    printf("\n");

    return 0;
}

