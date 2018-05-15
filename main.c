/* Criptografia e Segurança de Dados  */
/* Exercício-programa 2018 - K128     */
/* Ludmila Ferreira Vicente e Silva   */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "utils.h"
#include "keys.h"

int main (int argc, char *argv[]) {
  /* Chave que sera derivada da senha */
  char *K;

  /* Checa se existem todos os parametros */
  K = argv[1];

  /* Checa se a senha está dentro da especificacao */
  if (password_check (K) == 0) {
    printf ("A senha não contém pelo menos 2 algarismos e 2 letras. \nNão foi possível criptrografar o arquivo.\n");
    return 0;
  }

  /* Checa se a se senha tem menos que 16 bits. Se tiver menos, concatena a senha com ela mesma até ter 16 bits */
  if (strlen (K) < 16) K = password_concat (K);


  return 0;
}