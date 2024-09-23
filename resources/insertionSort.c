#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort (char **A, int n) {
  int i, j, comparacoes=0;
  char *chave;
  chave = malloc(12 * sizeof(char));
  /* a cada iteração, teremos o vetor A[1..i] ordenado */
  /* começamos de A[i], porque obviamente o vetor em A[0..0] está 
     trivialmente ordenado */
     
  for (i = 1; i < n; i++) {
    strcpy(chave, A[i]);
    j = i - 1;

    /* encontra a posicao correta de chave (A[i]) no vetor A[0..i-1] */
    while (j >= 0 && strcmp(A[j], chave) > 0 /*A[j] > chave*/) {
      strcpy(A[j+1], A[j]); /*A[j + 1] = A[j];*/
      comparacoes++;
      j = j - 1;
    }
	strcpy(A[j+1], chave);
  }
}
