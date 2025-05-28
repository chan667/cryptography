#include <stdio.h>
#include <stdint.h>

int main() {
    uint64_t plaintext = 0x0123456789ABCDEF;
    uint64_t key = 0x133457799BBCDFF1;
    uint64_t ciphertext, decrypted_text;
    
    uint64_t initial_permutation = 0xF0F0F0F0F0F0F0F0;
    uint64_t final_permutation = 0x0F0F0F0F0F0F0F0F;
    
    ciphertext = plaintext ^ key;
    ciphertext = (ciphertext & initial_permutation) | ((ciphertext & ~initial_permutation) >> 1);
    
    decrypted_text = ciphertext ^ key;
    decrypted_text = (decrypted_text & final_permutation) | ((decrypted_text & ~final_permutation) >> 1);
    
    printf("Plaintext: %016llX\n", plaintext);
    printf("Ciphertext: %016llX\n", ciphertext);
    printf("Decrypted Text: %016llX\n", decrypted_text);

    return 0;
}

