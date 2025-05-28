#include <stdio.h>
#include <stdint.h>

int main() {
    int lanes = 64;
    uint64_t state_matrix[64] = {0};  
    uint64_t message_block[64];
    int rounds = 0;

    for (int i = 0; i < lanes; i++) {
        message_block[i] = (i + 1) * 0x123456789ABCDEF;
    }

    while (1) {
        int all_nonzero = 1;

        for (int i = 0; i < lanes; i++) {
            state_matrix[i] ^= message_block[i];

            if (state_matrix[i] == 0) {
                all_nonzero = 0;
            }
        }

        rounds++;

        if (all_nonzero) {
            break;
        }
    }

    printf("All lanes have at least one nonzero bit after %d rounds.\n", rounds);

    return 0;
}

