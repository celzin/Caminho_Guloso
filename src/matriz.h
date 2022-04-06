#ifndef MATRIZ_H
#define MATRIZ_H
#include <stdio.h>
#include <stdlib.h>

//funcao que ira criar a matriz randomica
void startMatriz(int n, int A[n][n]);
//funcao que ira imprimir a matriz gerada
void printMatriz(int n, int A[n][n]);
//funcao que contara as instrucoes
int instructCounter(int n, int A[n][n]);

#endif
