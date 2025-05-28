#include <stdio.h>

int main() {
    int e = 31, n = 3599;
    int lookup_table[26];

    for (int i = 0; i < 26; i++) {
        int encrypted = 1;
        for (int j = 0; j < e; j++) {
            encrypted = (encrypted * i) % n;
        }
        lookup_table[i] = encrypted;
    }

    printf("Lookup Table:\n");
    for (int i = 0; i < 26; i++) {
        printf("Plaintext %c -> Ciphertext %d\n", 'A' + i, lookup_table[i]);
    }

    return 0;
}

