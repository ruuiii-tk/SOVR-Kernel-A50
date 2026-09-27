/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _CRYPTO_CHACHA20_H
#define _CRYPTO_CHACHA20_H

#include <crypto/chacha.h>

#define CHACHA20_IV_SIZE	CHACHA_IV_SIZE
#define CHACHA20_KEY_SIZE	CHACHA_KEY_SIZE
#define CHACHA20_BLOCK_SIZE	CHACHA_BLOCK_SIZE

enum chacha_constants { /* expand 32-byte k */
	CHACHA_CONSTANT_EXPA = 0x61707865U,
	CHACHA_CONSTANT_ND_3 = 0x3320646eU,
	CHACHA_CONSTANT_2_BY = 0x79622d32U,
	CHACHA_CONSTANT_TE_K = 0x6b206574U
};

static inline void chacha_init_consts(u32 *state)
{
	state[0]  = CHACHA_CONSTANT_EXPA;
	state[1]  = CHACHA_CONSTANT_ND_3;
	state[2]  = CHACHA_CONSTANT_2_BY;
	state[3]  = CHACHA_CONSTANT_TE_K;
}

#endif /* _CRYPTO_CHACHA20_H */
