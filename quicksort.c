#include "sorting.h"

/* compiling
gcc -Wall -ansi -pedantic -O2 -g quicksort.c sorting.c -o a
./a [number of words to read]
*/

int main(int argc, char *argv[]){
    char **words;
    int i;
    int *indexes;
    int nwords = atoi(argv[1]);
    FILE *randomwords = fopen(FILENAME, "r");    
    words = malloc(nwords * sizeof(char *));

    if (!readWords(randomwords, words, nwords))
        return 1;

    printWords(words, nwords);

    /*Alocação do vetor auxiliar de índices*/
    indexes = malloc(nwords * sizeof(int));
    for (i = 0; i < nwords; i++){
        indexes[i] = i;
    }

    indexes = malloc(nwords * sizeof(int));
    for (i = 0; i < nwords; i++)
        indexes[i] = i;

    /*Ordenação*/
    printf("After quick sort\n");
	quickSort(words, indexes, 0, nwords-1);
    words = remontaWords(words, indexes, nwords); printWords(words, nwords);
    printWords(words, nwords);
   
    
    if (imprimeDados("quick", nwords))
        printf("wrote data succesfully.\n");

    /*FREE*/
    freeWords(words, nwords);
    free(indexes);

    return 0;
}



