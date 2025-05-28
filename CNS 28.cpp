#include <stdio.h>

int main() {
    int p = 23, g = 5;  
    int alice_secret = 6, bob_secret = 15;  
    int alice_public, bob_public, shared_key_alice, shared_key_bob;

    alice_public = 1;
    for (int i = 0; i < alice_secret; i++) {
        alice_public = (alice_public * g) % p;
    }

    bob_public = 1;
    for (int i = 0; i < bob_secret; i++) {
        bob_public = (bob_public * g) % p;
    }

    shared_key_alice = 1;
    for (int i = 0; i < alice_secret; i++) {
        shared_key_alice = (shared_key_alice * bob_public) % p;
    }

    shared_key_bob = 1;
    for (int i = 0; i < bob_secret; i++) {
        shared_key_bob = (shared_key_bob * alice_public) % p;
    }

    printf("Alice's Public Key: %d\n", alice_public);
    printf("Bob's Public Key: %d\n", bob_public);
    printf("Shared Key (Alice): %d\n", shared_key_alice);
    printf("Shared Key (Bob): %d\n", shared_key_bob);

    return 0;
}
	
