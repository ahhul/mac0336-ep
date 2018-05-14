/* Criptografia e Segurança de Dados  */
/* Exercício-programa 2018 - K128     */
/* Ludmila Ferreira Vicente e Silva   */

int main (int argc, char *argv[]) {

  char *K; /* Chave que sera derivada da senha */
  /* Checa se existem todos os parametros */
  if (strcmp (argv[1], "-1") == 0 || strcmp (argv[1], "-2") == 0)
    if (exceptions (argv[5])) return 0;
	else if (exceptions (argv[7])) return 0;


  return 0;


}
