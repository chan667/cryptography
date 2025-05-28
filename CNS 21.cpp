#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

int main() {
    AES_KEY key;
    unsigned char plaintext[16] = "YourMessageHere"; 
    unsigned char key_data[16] = "EncryptionKey12"; 
    unsigned char ciphertext[16];
    unsigned char iv[AES_BLOCK_SIZE] = {0}; 
    int num = 0, i;

    AES_set_encrypt_key(key_data, 128, &key);

    unsigned char padded_plaintext[16];
    memcpy(padded_plaintext, plaintext, 16);
    padded_plaintext[15] = 0x80; 

    AES_ecb_encrypt(padded_plaintext, ciphertext, &key, AES_ENCRYPT);
    printf("ECB Ciphertext: ");
    for (i = 0; i < 16; i++) printf("%02x ", ciphertext[i]);
    printf("\n");

    AES_cbc_encrypt(padded_plaintext, ciphertext, 16, &key, iv, AES_ENCRYPT);
    printf("CBC Ciphertext: ");
    for (i = 0; i < 16; i++) printf("%02x ", ciphertext[i]);
    printf("\n");

    AES_cfb128_encrypt(padded_plaintext, ciphertext, 16, &key, iv, &num, AES_ENCRYPT);
    printf("CFB Ciphertext: ");
    for (i = 0; i < 16; i++) printf("%02x ", ciphertext[i]);
    printf("\n");

    return 0;
}

