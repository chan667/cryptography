#include <stdio.h>
#include <string.h>

int main() {
    char ciphertext[] = "WKH TXLFN EURZQ IRAA";
    char decrypted[25];
    int letter_count[26] = {0};
    int max_index = 0;

    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            letter_count[ciphertext[i] - 'A']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (letter_count[i] > letter_count[max_index]) {
            max_index = i;
        }
    }

    int shift = max_index - ('E' - 'A');

    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            decrypted[i] = ((ciphertext[i] - 'A' - shift + 26) % 26) + 'A';
        } else {
            decrypted[i] = ciphertext[i];
        }
    }
    decrypted[strlen(ciphertext)] = '\0';

    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}

