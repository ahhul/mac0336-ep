#ifndef H_KEYS
#define H_KEYS

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "utils.h"


#define ConstR 0x10011
#define ConstM 0xCB3725F7
#define K0Const 0x5A827999874AA67D657B7C8EBD070242

/* Gera as subchaves KR5 e KM32*/
void sub_keys (uint32_t **KR5, uint32_t **KM32, uint32_t *K);




#endif
