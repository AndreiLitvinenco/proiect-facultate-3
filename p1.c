#include <stdio.h>
#include <string.h>
#include "STACK.h"

int main(void)
{
  Stack S;
  char str[100];
  char *traverse;

  printf("Introduceti un sir de caractere: ");
  gets(str);

  newStack(S);

  for (traverse = str; *traverse != '\0'; traverse++) {
    push(S, (void*)traverse);
  }

  printf("\Sirul de caractere in ordine inversa este: ");

  while (!isEmpty(S)) {
    printf("%c", *(char*)pop(S));
  }

  deleteStack(S);

  return 0;
}
