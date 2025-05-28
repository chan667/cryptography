#include <stdio.h>

int main() {
    int key[2][2] = {{9, 4}, {5, 7}};
    int plaintext[2] = {7, 4}; 
    int ciphertext[2], decrypted[2];
    int inverse_key[2][2] = {{7, -4}, {-5, 9}};
    int mod = 26;

    for (int i = 0; i < 2; i++) {
        ciphertext[i] = (key[i][0] * plaintext[0] + key[i][1] * plaintext[1]) % mod;
    }

    for (int i = 0; i < 2; i++) {
        decrypted[i] = (inverse_key[i][0] * ciphertext[0] + inverse_key[i][1] * ciphertext[1]) % mod;
        if (decrypted[i] < 0) decrypted[i] += mod;
    }

    printf("Ciphertext: %d %d\n", ciphertext[0], ciphertext[1]);
    printf("Decrypted: %d %d\n", decrypted[0], decrypted[1]);

    return 0;
}

