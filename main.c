/* Criptografia e Segurança de Dados  */
/* Exercício-programa 2018 - K128     */
/* Ludmila Ferreira Vicente e Silva   */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

#include "utils.h"
#include "keys.h"
#include "hexdump.h"

int main (int argc, char *argv[]) {

  long file_size;
  uint128_t *block, block_cbc, block_r, key, inter_key, cript_result, *cript_array;
  int blocks, i, j;
  /* vetor do arquivo de entrada */
  byte_t *file_bytes;
  /* Chave que sera derivada da senha */
  char *K;
  /* Checa se existem todos os parametros */
  K = argv[7];

  /* para ler o arquivo  e armazenar em um vetor de bytes*/
  file_size = get_file_size(argv[3]);
  file_bytes = malloc(file_size*sizeof(*file_bytes));
  read_file_to_array(argv[3], file_bytes, file_size);

  /* Checa se a senha está dentro da especificacao */
  if (password_check (K) == 0) {
    printf ("A senha não contém pelo menos 2 algarismos e 2 letras. \nNão foi possível criptrografar o arquivo.\n");
    return 0;
  }

  /* Checa se a se senha tem menos que 16 bits. Se tiver menos, concatena a senha com ela mesma até ter 16 bits */
  if (strlen (K) < 16) K = password_concat (K);
  key = key_creation (K);
  /* Cria os blocos de 128 bits*/
  block = block_creation (file_bytes, file_size);
  block_cbc.X = 0xffffffff;
  block_cbc.Y = 0xffffffff;
  block_cbc.W = 0xffffffff;
  block_cbc.Z = 0xffffffff;

  /* Encriptação */
  for(i = 0; i < blocks; i++){
    uint128_t block_r = xor_block (block[i], block_cbc);

    for(j = 0; j < 12; j++){
      inter_key = intermediary_key (key, j);
      cript_result = one_iteration (j, cript_result, inter_key);
      key = inter_key;
      cript_array[i] = cript_result;
    }

  }

  /* TODO preciso converter pra escrever no arquivo*/
  return 0;
}
