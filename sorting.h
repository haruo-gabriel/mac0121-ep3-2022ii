#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 11
#define WORDSORT "random"
/*#define WORDSORT "sorted"*/
#define FILENAME "../worddata/randomwords.txt"
/*#define FILENAME "../worddata/sortedwords.txt"*/

extern unsigned long int comparacoes;
extern unsigned long int trocas;

void printWords(char **words, int nwords);
char **copyWords (char **words, int nwords);
void freeWords (char **words, int nwords);
void writeWords (char **words ,int nwords);
int imprimeDados(char sortalgo[], int nwords);
int readWords (FILE *randomwords, char **words, int nwords);
char **remontaWords (char **original, int *indexes, int nwords);

void trocaIndices (int *indexes, int i, int j);

void insertionSort (char **A, int n);

void merge (int ini, int meio, int fim, char **v);
void mergeSort (int meio, int fim, char **v);

int particiona (char **v, int *indexes, int ini, int fim);
void quickSort (char **v, int *indexes, int ini, int fim);

void heapSort (char **v, int *indexes, int n);
void heapfica (char **v, int *indexes, int n, int i);