#include "matriz.h"

//funcao pelo metodo da bolha que gera uma matriz randomica
void startMatriz(int n, int A[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            A[i][j] = rand()%99;
        }
    }
}
//funcao pelo metodo da bolha que imprime a matriz gerada
void printMatriz(int n, int A[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("| %d |\t", A[i][j]);
        }
        printf("\n");
    }
}
//funcao que percorrera a matriz e contara as instrucoes
int instructCounter(int n, int A[n][n]){
    int sum, i = 0, j = 0;
    sum = A[0][0]; //starta a soma na posição [0][0]
    A[0][0] = -1; //atribui -1 ao valor da posição [0][0]
    //loop enquanto i e j < n
    while(i < n && j < n){
        //*condicao 1*
        if(j == 0 && i < (n-1)){
            //*condicao 1.1*
            if((A[i][j+1] >= A[i+1][j]) && (A[i][j+1] != -1)){
                j++; //j+1
                sum += A[i][j]; //soma = soma + valor escolhido de A[i][j]
                A[i][j] = -1; //atribui -1 a posicao escolhida
                //*condicao 1.1*/ escolho: DIREITA /
            }
            //*condicao 1.2*
            else{
                i++;
                sum += A[i][j]; 
                A[i][j] = -1; 
                //*condicao 1.2*/ escolho: ABAIXO / 
            }
        }
        //*condicao 2*
        else if(i == (n-1)){
            j++;
            sum += A[i][j];
            A[i][j] = -1;
            //*condicao 2*/ DIREITA /
        }
        //*condicao 3*
        else if(j == n-1){
            //*condicao 3.1*/ escolho: ESQUERDA /
            if((A[i][j-1] >= A[i+1][j]) && (A[i][j-1] != -1)){
                j--;
                sum += A[i][j];
                A[i][j] = -1;
            }
            //*condicao 3.2*/ escolho: ABAIXO /
            else{
                i++;
                sum += A[i][j];
                A[i][j] = -1;
            }
        }
        //*condicao 4*
        else{
            //*condicao 4.1*
            if(A[i][j+1] == -1){
                //*condicao 4.1.1*/ escolho: ABAIXO /
                if(A[i+1][j] >= A[i][j-1]){
                    i++; 
                    sum += A[i][j];
                    A[i][j] = -1; 
                }
                //*condicao 4.1.2*/ escolho: ESQUERDA / 
                else{
                    j--;
                    sum += A[i][j];
                    A[i][j] = -1;
                }
            }
            //*condicao 4.2*
            else if(A[i][j-1] == -1){
                //*condicao 4.2.1*/ escolho ABAIXO/
                if(A[i+1][j] >= A[i][j+1]){
                    i++;
                    sum += A[i][j];
                    A[i][j] = -1;
                }
                //*condicao 4.2.2*/ escolho: DIREITA /
                else{
                    j++;
                    sum += A[i][j];
                    A[i][j] = -1;
                }
            }
            //*condicao 4.3*
            else{
                //*condicao 4.3.1*/ escolho: ABAIXO/
                if((A[i+1][j] >=  A[i][j+1]) && (A[i+1][j] >= A[i][j-1])){
                    i++;
                    sum += A[i][j];
                    A[i][j] = -1;
                }
                //*condicao 4.3.2*/ escolho: DIREITA /
                else if((A[i][j+1] >= A[i+1][j]) && (A[i][j+1] >= A[i][j-1])){
                    j++;
                    sum += A[i][j];
                    A[i][j] = -1;
                }
                //*condicao 4.3.3*/ escolho: ESQUERDA /
                else if((A[i][j-1] >= A[i+1][j]) && (A[i][j-1] >= A[i][j+1])){
                    j--;
                    sum += A[i][j];
                    A[i][j] = -1;
                }
            }
        }
    }
    return sum; //retorna o valor final da soma
}