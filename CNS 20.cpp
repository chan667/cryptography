#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 8  
#define NUM_BLOCKS 4  

int main() {
    unsigned char plaintext[NUM_BLOCKS][BLOCK_SIZE] = {
        {0x12, 0x34, 0x56, 0x78, 0xAB, 0xCD, 0xEF, 0x90},  
        {0x23, 0x45, 0x67, 0x89, 0xBC, 0xDE, 0xFA, 0x01},  
        {0x34, 0x56, 0x78, 0x9A, 0xCD, 0xEF, 0x10, 0x23},  
        {0x45, 0x67, 0x89, 0xAB, 0xDE, 0xFA, 0x21, 0x34}  
    };

    unsigned char iv[BLOCK_SIZE] = {0xFF, 0xEE, 0xDD, 0xCC, 0xBB, 0xAA, 0x99, 0x88}; 
    unsigned char ciphertext[NUM_BLOCKS][BLOCK_SIZE];

    memcpy(ciphertext[0], plaintext[0], BLOCK_SIZE);
    for (int i = 0; i < BLOCK_SIZE; i++) {
        ciphertext[0][i] ^= iv[i];  
    }

    for (int b = 1; b < NUM_BLOCKS; b++) {
        memcpy(ciphertext[b], plaintext[b], BLOCK_SIZE);
        for (int i = 0; i < BLOCK_SIZE; i++) {
            ciphertext[b][i] ^= ciphertext[b - 1][i];  
        }
    }

    printf("Ciphertext Blocks:\n");
    for (int b = 0; b < NUM_BLOCKS; b++) {
        printf("Block %d: ", b);
        for (int i = 0; i < BLOCK_SIZE; i++) {
            printf("%02X ", ciphertext[b][i]);
        }
        printf("\n");
    }

    ciphertext[0][2] ^= 0xFF;  

    printf("\nDecryption Result:\n");
    unsigned char decrypted[NUM_BLOCKS][BLOCK_SIZE];

    for (int b = 0; b < NUM_BLOCKS; b++) {
        memcpy(decrypted[b], ciphertext[b], BLOCK_SIZE);
        for (int i = 0; i < BLOCK_SIZE; i++) {
            decrypted[b][i] ^= (b == 0) ? iv[i] : ciphertext[b - 1][i];  
        }
    }

    for (int b = 0; b < NUM_BLOCKS; b++) {
        printf("Block %d: ", b);
        for (int i = 0; i < BLOCK_SIZE; i++) {
            printf("%02X ", decrypted[b][i]);
        }
        printf("\n");
    }

    return 0;
}

