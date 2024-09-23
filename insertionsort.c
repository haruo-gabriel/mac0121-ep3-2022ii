#include "sorting.h"

/* compiling
gcc -Wall -ansi -pedantic -O2 insertionsort.c sorting.c -o a
./a [number of words to read]
*/

int main(int argc, char *argv[]){
    /*Inicialização*/
    char **words;
    FILE *randomwords = fopen(FILENAME, "r");
    int nwords = atoi(argv[1]);

    words = malloc(nwords* sizeof(char *));

    if (!readWords(randomwords, words, nwords))
        return 1;

    printWords(words, nwords);

    /*Ordenação*/
    printf("After insertion sort\n");
    insertionSort(words, nwords);
    printWords(words, nwords);

    /*
    if (imprimeDados("insertion", nwords))
        printf("wrote data succesfully.\n");
    */
    
    freeWords(words, nwords);

    return 0;
}
