#include "matriz.h"

int main(){
    int n = 0, sum = 0;
    printf("Informe N: ");
    scanf("%d", &n);
    int A[n][n];
    //a funcao "startMatriz" recebe os o valor e a matriz passados
    startMatriz(n, A);
    printf("\nMatriz %dx%d: \n", n, n);
    printMatriz(n, A);
    //soma recebe a funcao "instructCounter"
    sum = instructCounter(n, A);
    //reimprimimos a matriz com a mudanca dos "-1"
    printf("\n\nCaminho percorrido: \n");
    printMatriz(n, A);
    //imprimimos a soma final
    printf("\n\nSoma Final: %d\n", sum);
    return 0;
}