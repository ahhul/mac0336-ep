#include "utils.h"


/* retorna 1 se a senha esta dentro das especificacao */
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

__uint32_t five_bits_right (__uint32_t bin) {
  return (bin &= ((1 << 5) - 1));
}
