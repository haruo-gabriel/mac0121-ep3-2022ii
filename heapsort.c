#include "sorting.h"

/* compiling
gcc -Wall -ansi -pedantic -O2 heapsort.c sorting.c -o a
./a [number of words to read]
*/

int main(int argc, char *argv[]){
    /*Inicialização*/
    char **words;
    int i;
    int *indexes;
    FILE *randomwords = fopen(FILENAME, "r");
    int nwords = atoi(argv[1]);

    words = malloc(nwords * sizeof(char *));

    if (!readWords(randomwords, words, nwords))
        return 1;

    printWords(words, nwords);

    /*Alocação do vetor auxiliar de índices*/
    indexes = malloc(nwords * sizeof(int));
    for (i = 0; i < nwords; i++){
        indexes[i] = i;
    }

    /*Ordenação*/
    printf("After heap sort\n");
	heapSort(words, indexes, nwords);
    words = remontaWords(words, indexes, nwords);
    printWords(words, nwords);

    if (imprimeDados("heap", nwords))
        printf("wrote data succesfully.\n");

    /*FREE*/
    freeWords(words, nwords);
    free(indexes);

    return 0;
}
