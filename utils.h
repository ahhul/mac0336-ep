#ifndef H_UTILS
#define H_UTILS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



/* retorna 1 se a senha esta dentro das especificacao */
int password_check (char *password);

/* retorna a nova senha, que é a senha antiga concatenada com ela mesma */
char* password_concat (char *password);

/* retorna os 5 ultimos bits da direita */
__uint32_t five_bits_right (__uint32_t bin);


#endif
