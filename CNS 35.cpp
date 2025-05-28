#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char plaintext[] = "SENDMOREMONEY";
    char ciphertext[15];
    char decrypted[15];
    int key[15];

    srand(time(NULL));

    for (int i = 0; i < 15; i++) {
        key[i] = rand() % 26;
        ciphertext[i] = ((plaintext[i] - 'A' + key[i]) % 26) + 'A';
    }

    for (int i = 0; i < 15; i++) {
        decrypted[i] = ((ciphertext[i] - 'A' - key[i] + 26) % 26) + 'A';
    }

    printf("Plaintext: %s\n", plaintext);
    printf("Key: ");
    for (int i = 0; i < 15; i++) printf("%d ", key[i]);
    printf("\nCiphertext: %s\n", ciphertext);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}

