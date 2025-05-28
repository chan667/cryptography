#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main() {
    mpz_t prime, subgroup, base, secret, msg, sig1, sig2, rand_num, inverse, hash_val, temp;
    mpz_inits(prime, subgroup, base, secret, msg, sig1, sig2, rand_num, inverse, hash_val, temp, NULL);

    mpz_set_str(prime, "23", 10);
    mpz_set_str(subgroup, "11", 10);
    mpz_set_str(base, "2", 10);
    mpz_set_str(secret, "5", 10);
    mpz_set_str(msg, "9", 10);

    gmp_randstate_t state;
    gmp_randinit_mt(state);
    mpz_urandomm(rand_num, state, subgroup);

    mpz_powm(temp, base, rand_num, prime);
    mpz_mod(sig1, temp, subgroup);

    mpz_invert(inverse, rand_num, subgroup);

    mpz_mod(hash_val, msg, subgroup);

    mpz_mul(temp, secret, sig1);
    mpz_add(temp, temp, hash_val);
    mpz_mul(sig2, inverse, temp);
    mpz_mod(sig2, sig2, subgroup);

    gmp_printf("Signature: %Zd %Zd\n", sig1, sig2);

    mpz_clears(prime, subgroup, base, secret, msg, sig1, sig2, rand_num, inverse, hash_val, temp, NULL);
    return 0;
}

