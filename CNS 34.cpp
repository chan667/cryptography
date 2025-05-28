#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

int main() {
    unsigned char key[16] = "encryption_key_";
    unsigned char plaintext[16] = "Hello, World!!!";
    unsigned char ciphertext[16], decrypted[16];

    AES_KEY enc_key, dec_key;
    AES_set_encrypt_key(key, 128, &enc_key);
    AES_set_decrypt_key(key, 128, &dec_key);

    AES_ecb_encrypt(plaintext, ciphertext, &enc_key, AES_ENCRYPT);
    AES_ecb_encrypt(ciphertext, decrypted, &dec_key, AES_DECRYPT);

    printf("ECB Mode:\n");
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted: %s\n", decrypted);

    AES_cbc_encrypt(plaintext, ciphertext, 16, &enc_key, NULL, AES_ENCRYPT);
    AES_cbc_encrypt(ciphertext, decrypted, 16, &dec_key, NULL, AES_DECRYPT);

    printf("\nCBC Mode:\n");
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted: %s\n", decrypted);

    AES_cfb128_encrypt(plaintext, ciphertext, 16, &enc_key, NULL, NULL, AES_ENCRYPT);
    AES_cfb128_encrypt(ciphertext, decrypted, 16, &dec_key, NULL, NULL, AES_DECRYPT);

    printf("\nCFB Mode:\n");
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}

