#pragma once

#include "gimli.h"

#include <stddef.h>
#include <stdint.h>

typedef struct
{
    uint32_t state[GIMLI_WORDS];
    size_t offset;
} gimli_hash_state;

void gimli_hash_init(gimli_hash_state *g);

void gimli_hash_update(gimli_hash_state *g, const unsigned char *input,
                       size_t len);

void gimli_hash_final(gimli_hash_state *g, unsigned char *output, size_t len);

void gimli_hash(unsigned char *output, size_t output_len,
                const unsigned char *input, size_t input_len);
