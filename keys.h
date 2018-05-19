#ifndef H_KEYS
#define H_KEYS

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "utils.h"


#define ConstR 0x10011
#define ConstM 0xCB3725F7
#define K0Const 0x5A827999874AA67D657B7C8EBD070242



/* Gera as subchaves KR5 e KM32*/
void sub_keys (uint128_t inter_key, byte_t KR5[], uint32_t KM32[]);
/* fução f1 do enunciado */
uint32_t f_1(uint32_t X, byte_t KR5, uint32_t KM32);
/* fução f2 do enunciado */
uint32_t f_2(uint32_t X, byte_t KR5, uint32_t KM32);
/* fução f3 do enunciado */
uint32_t f_3(uint32_t X, byte_t KR5, uint32_t KM32);
/* Gera a Chave intermediaria */
uint128_t intermediary_key (uint128_t *K_old, uint128_t *K, int iteration);

uint128_t one_iteration (int iteration, uint128_t int_key, uint128_t value);




#endif
