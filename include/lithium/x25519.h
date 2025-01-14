#ifndef LITHIUM_X25519_H
#define LITHIUM_X25519_H

/*
 * Part of liblithium, under the Apache License v2.0.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Derived from STROBE's x25519.h, under the MIT license.
 * STROBE is Copyright (c) 2015-2016 Cryptography Research, Inc.
 * SPDX-License-Identifier: MIT
 */

#include <stdbool.h>

#define X25519_BITS 256
#define X25519_LEN (X25519_BITS / 8)

/*
 * Clamp an arbitrary 256 bit value to be a legal x25519 scalar.
 */
void x25519_clamp(unsigned char scalar[X25519_LEN]);

/*
 * x25519 scalar multiplication. Sets out to scalar*point.
 *
 * scalar should be clamped like a Curve25519 secret key.
 */
void x25519(unsigned char out[X25519_LEN],
            const unsigned char scalar[X25519_LEN],
            const unsigned char point[X25519_LEN]);

/*
 * Scalar multiplication of the curve's base point.
 *
 * scalar should be clamped like a Curve25519 secret key.
 */
void x25519_base(unsigned char out[X25519_LEN],
                 const unsigned char scalar[X25519_LEN]);

/*
 * STROBE-compatible Schnorr signatures using curve25519 (not ed25519).
 *
 * The user will call x25519_base(public_nonce, secret_nonce) to schedule a
 * random ephemeral secret key. They then call a Schnorr oracle to get a
 * challenge, and compute the response using this function.
 */
void x25519_sign(unsigned char response[X25519_LEN],
                 const unsigned char challenge[X25519_LEN],
                 const unsigned char secret_nonce[X25519_LEN],
                 const unsigned char secret_key[X25519_LEN]);

/*
 * STROBE-compatible signature verification using curve25519 (not ed25519).
 * This function is the public equivalent x25519_sign, taking the long-term
 * and ephemeral public keys instead of secret ones.
 *
 * Returns true for a matching signature.
 */
bool x25519_verify(const unsigned char response[X25519_LEN],
                   const unsigned char challenge[X25519_LEN],
                   const unsigned char public_nonce[X25519_LEN],
                   const unsigned char public_key[X25519_LEN]);

#endif /* LITHIUM_X25519_H */
