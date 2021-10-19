#include <lithium/gimli_aead.h>

#include <tis_builtin.h>

int main(void)
{
    unsigned char m[1024], c[1024], t[32], ad[1024], n[GIMLI_AEAD_NONCE_LEN],
        k[GIMLI_AEAD_KEY_LEN];
    tis_make_unknown(c, sizeof c);
    tis_make_unknown(t, sizeof t);
    tis_make_unknown(ad, sizeof ad);
    tis_make_unknown(n, sizeof n);
    tis_make_unknown(k, sizeof k);
    size_t len = sizeof c; // TODO: try a couple other values // tis_unsigned_long_interval(0, sizeof c);
    size_t tlen = sizeof t; // tis_unsigned_long_interval(0, sizeof t);
    size_t adlen = sizeof ad; // tis_unsigned_long_interval(0, sizeof ad);
    return !gimli_aead_decrypt(m, c, len, t, tlen, ad, adlen, n, k);
}
