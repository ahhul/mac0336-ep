#include "utils.h"


int password_check (char *password) {
  int i, d, a, len;
  len = strlen (password);
  d = a = 0;
  for (i = 0; i < len; i++) {
    if (isdigit (password[i]))  d++;
    else if (isalpha (password[i]))  a++;
  }
  if (d == 2 || a == 2) return 1;
  return 0;
}

char* password_concat (char *password) {
  int i, j, len;
  char *new_pass = malloc (16 * sizeof (char));
  len = strlen (password);
  j = 0;
  for (i = 0; i < 16; i++){
    new_pass[i] = password[j];
    j = i % len;
  }
  return new_pass;
}

uint32_t five_bits_right (uint32_t num) {
  return num &= 0x000001f;
}

uint32_t** alocation (int l, int c) {
	uint32_t **matrix;
	int i;
	matrix = malloc (l * sizeof (uint32_t*));
	for (i = 0; i < l; ++i)  matrix[i] = malloc (c * sizeof (uint32_t));
	return matrix;
}

uint128_t* block_creation (byte_t *file_bytes, long file_size) {
  uint128_t *block;

  block = malloc (sizeof (uint128_t) * (file_size + 1));

  return block;

}

void sbox_read (char *file, uint32_t sbox[]) {
	int i;
	FILE *in;
	in = fopen (file, "r");
	for (i = 0; i < 256; ++i)  fscanf (in, "%x", &sbox[i]);
	fclose (in);
}

uint32_t circular_rotation(uint32_t bin, int n){
  return (bin  << n) | (bin  >> (32 - n));
}
