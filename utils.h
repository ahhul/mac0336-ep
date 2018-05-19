#ifndef H_UTILS
#define H_UTILS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include <ctype.h>
#include "hexdump.h"

typedef struct{
  uint32_t X, Y, Z, W;
} uint128_t;

/* vetores para guardas as sboxes */
uint32_t sbox_1[256], sbox_2[256], sbox_3[256], sbox_4[256];

/* retorna 1 se a senha esta dentro das especificacao */
int password_check (char *password);

/* retorna a nova senha, que é a senha antiga concatenada com ela mesma */
char* password_concat (char *password);

/* Cria a chave principal */
uint128_t key_creation(char* password);

/* retorna os 5 ultimos bits da direita */
uint32_t five_bits_right (uint32_t bin);


/* faz a operação xor entre dois números A e B */
uint128_t xor_block (uint128_t A, uint128_t B);

/* Lê as sboxes */
void sbox_read (char *file, uint32_t sbox[]);

/* faz a rotacao circular do numero com n shifts*/
uint32_t circular_rotation(uint32_t bin, int n);


uint32_t bytes_to_int32 (byte_t *num_bytes);

byte_t* get_bytes (uint32_t uint32);

uint128_t* block_creation (byte_t *file_bytes, long file_size);
#endif
