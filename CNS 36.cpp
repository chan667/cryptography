#include <stdio.h>

int main() {
    char plaintext[] = "HELLO";
    char ciphertext[6], decrypted[6];
    int a = 5, b = 8, a_inv = -1;

    for (int i = 1; i < 26; i++) {
        if ((a * i) % 26 == 1) {
            a_inv = i;
            break;
        }
    }

    for (int i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = ((a * (plaintext[i] - 'A') + b) % 26) + 'A';
    }
    ciphertext[5] = '\0';

    for (int i = 0; ciphertext[i] != '\0'; i++) {
        decrypted[i] = ((a_inv * (ciphertext[i] - 'A' - b + 26)) % 26) + 'A';
    }
    decrypted[5] = '\0';

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}

