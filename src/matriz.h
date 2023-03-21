#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

void tokenizarMatriz(char *str, int cont, int **matrix);
void tokenizarLinha(char *str, int *n, int *m);
int **readFile();
int caminharMatriz(int **mat, int n, int m);
void printMatriz(int **mat, int n, int m);
void printCaminho(int **mat, int n, int m);

#endif
