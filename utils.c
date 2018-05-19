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

uint128_t key_creation(char* password){
  byte_t bytes[4];
  uint32_t blocks[4];
  int i, j = 0, k = 0;
  uint128_t key;
  for(i = 0; i < 16; i++){
    bytes[j++] = password[i];
    if( j == 4){
      blocks[k++] = bytes_to_int32(bytes);
      j = 0;
    }
  }
  key.X = blocks[0];
  key.Y = blocks[1];
  key.W = blocks[2];
  key.Z = blocks[3];
  return key;
}

uint32_t five_bits_right (uint32_t num) {
  return num &= 0x000001f;
}

uint32_t bytes_to_int32 (byte_t *num_bytes){
  uint32_t num_int;
  num_int = num_bytes[0] + (num_bytes[1] << 8) + (num_bytes[2] << 16) + (num_bytes[3] << 24);
  return num_int;
}

byte_t* get_bytes (uint32_t uint32){
  byte_t *bytes = malloc (4 * sizeof (byte_t));
  int i, j;
  j = 0;
  for (i = 3; i >= 0; i--){
    bytes[j++] = (uint32 >> (8*i)) & 0xff;
  }
  return bytes;
}


uint128_t* block_creation (byte_t *file_bytes, long file_size) {
  long i, j, k, blocks;
  uint128_t *block;
  byte_t num_bytes[4];
  uint32_t num_int[4];
  i = j = k = blocks = 0;

  block = malloc (sizeof (uint128_t) * ((file_size / 16) + 1));

  for (i = 0; i < file_size; i++) {
    num_bytes[j++] = file_bytes[i];

    if(j == 4){
      j = 0;
      num_int[k++] = bytes_to_int32 (num_bytes);
      if (k == 4) {
        k = 0;
        block[blocks].X = num_int[0];
        block[blocks].Y = num_int[1];
        block[blocks].W = num_int[2];
        block[blocks].Z = num_int[3];
        blocks++;
      }
    }
  }

  if (k != 0){
    while (k < 4) {
      num_bytes[j++] = 0xff;
      if (j == 4) {
        num_int[k++] = bytes_to_int32 (num_bytes);
        j = 0;
      }
    }
    block[blocks].X = num_int[0];
    block[blocks].Y = num_int[1];
    block[blocks].W = num_int[2];
    block[blocks].Z = num_int[3];
    blocks++;
  }
  /* guarda tamanho do bloco */
  block[blocks++].Z = file_size;
  return block;
}

uint128_t xor_block (uint128_t A, uint128_t B) {
  uint128_t xor;
	xor.X = A.X ^ B.X;
  xor.Y = A.Y ^ B.Y;
  xor.W = A.W ^ B.W;
  xor.Z = A.Z ^ B.Z;
  return xor;
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
