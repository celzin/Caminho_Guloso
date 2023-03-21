#include "matriz.h"

// funcao que imprime no terminal a matriz gerada
void printMatriz(int **mat, int n, int m){
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++)
             printf("%-5d ", mat[i][j]);
        printf("\n");
	}
}

// funcao que imprime a matriz, o caminho percorrido e a soma
void printCaminho(int **mat, int n, int m){
    
    
    printf("\n--------------Inicio Matriz-------------\n");
    printf("\nMatriz Lida: \n");
    printMatriz(mat, n, m);
	int sum = caminharMatriz(mat, n, m);
    printf("\nCaminho Percorrido: \n");
	printMatriz(mat, n, m);
    printf("\nSoma: %d\n", sum);
    printf("\n----------------Fim Matriz--------------\n");
}

// funcao que tokeniza a matriz do arquivo
void tokenizarMatriz(char *str, int cont, int **matrix) {
    int val, col=0;
	const char sep[] = " ";
	char *tokens;
	tokens = strtok(str, sep);

	while (tokens != NULL) {
		val = atoi(tokens);
        matrix[cont][col] = val;
        col++;
		tokens = strtok(NULL, sep);
	}
}

// funcao que tokeniza a primeira linha do arquivo
void tokenizarLinha(char *str, int *n, int *m) {
	const char sep[] = " ";
	char *tokens;
    int aux = 0;
	tokens = strtok(str, sep);

	while (tokens != NULL) {
        if(aux == 0){
            *n = atoi(tokens);
            aux++;
        }else{
            *m = atoi(tokens);
        }
		tokens = strtok(NULL, sep);
	}
}

// funcao que le tamanho e matrizes do aquivo
int **readFile() {
	char *str = (char *)malloc(100);
	strcpy(str, "dataset/input.data");
    int aux = 0;
    int n, m, cont = 0, **mat;

	FILE *file = fopen(str, "r");

	char *result, linha[100];

	if (file == NULL) {
		printf("Nao foi possivel abrir o arquivo\n");
	} else {
		while (!feof(file)) {
			result = fgets(linha, sizeof(linha), file);

			if (result) {
				if(aux == 0){
                    aux = 1;
                    tokenizarLinha(linha, &n, &m);
                    
                    mat = malloc(n*sizeof(int **));

                    for(int i=0; i<m; i++){
                        mat[i] = malloc(m*sizeof(int *));
                    }
                }else if(strlen(linha) > 1){
                    tokenizarMatriz(linha, cont, mat);
                    cont++;
                }else{
                    if(cont == n){
                        printCaminho(mat, n, m);  
                    }
                    cont=0;
                }
            }
		}
	}
    if(cont == n){
      printCaminho(mat, n, m);  
    }
	fclose(file);
    return mat;
}

// funcao que le tamanho e matrizes do aquivo
int readSpace() {
	char *str = (char *)malloc(100);
	strcpy(str, "dataset/input.data");
    int aux = 0;
    int n, m, cont = 1, **mat;

	FILE *file = fopen(str, "r");

	char *result, linha[100];

	if (file == NULL) {
		printf("Nao foi possivel abrir o arquivo\n");
	} else {
		while (!feof(file)) {
			result = fgets(linha, sizeof(linha), file);

			if (result) {
				
                if(strlen(linha) == 1){
                    cont++;
                }
                
            }
		}
	} 
	fclose(file);
    return cont;
}

// funcao que percorre a matriz e busca o caminho guloso
int caminharMatriz(int **mat, int n, int m){
   int i=0, j=0, sum=0;
   // atribui o valor da posicao [0][0] a soma
   sum += mat[0][0];
   // atribui -1 ao valor da posição [0][0]
   mat[0][0] = -1;

   while (i < n && j < m){
    // condicao 1: ( linha(i) atual = linha(máxima) )
    if(i == (n-1)){
        sum += mat[i][j];
        mat[i][j] = -1;
        j++;
    }
    // condicao 2
    else{ 
        // condicao 2.1: ( coluna(j) atual = primeira coluna(j) )
        if(j == 0){
            /* condicao 2.1.1 
               (direita >= abaixo) e (direita >= diagonal_direita) */
            if(mat[i][j+1] >= mat[i+1][j] && mat[i][j+1] >= mat[i+1][j+1]){
                j++;
                sum += mat[i][j];
                mat[i][j] = -1;
            }
            /* condicao 2.1.2 
               (abaixo >= direita) e (abaixo >= diagonal_direita) */
            else if(mat[i+1][j] >= mat[i][j+1] && mat[i+1][j] >= mat[i+1][j+1]){
                i++;
                sum += mat[i][j];
                mat[i][j] = -1;
            }
            /* condicao 2.1.3 
               (diagonal_direita >= abaixo) e (diagonal_direita >= direita) */
            else{
                i++;
                j++;
                sum += mat[i][j];
                mat[i][j] = -1;
            }
        }
        // condicao 2.2: ( coluna(j) atual = coluna(máxima) )
        else if(j == (n-1)){
            /* condicao 2.2.1 
               (abaixo >= esquerda) && (abaixo >= diagonal_esquerda) */
            if(mat[i+1][j] >= mat[i][j-1] && mat[i+1][j] >= mat[i+1][j-1]){
                i++;
                sum += mat[i][j];
                mat[i][j] = -1;
            }
            /* condicao 2.2.2 
               (esquerda >= abaixo) && (esquerda >= diagonal_esquerda)*/
            else if(mat[i][j-1] >= mat[i+1][j] && mat[i][j-1] >= mat[i+1][j-1]){
                j--;
                sum += mat[i][j];
                mat[i][j] = -1;
            }
            /* condicao 2.2.3 
               (diagonal_esquerda >= abaixo) && (diagonal_esquerda >= esquerda) */
            else{
                j--;
                i++;
                sum += mat[i][j];
                mat[i][j] = -1;
            }
        }
        //  condicao 2.3 : caso geral
        else{   
            /* condicao 2.3.1
               (abaixo >= esquerda)  e  (abaixo >= direita) e
               (abaixo >= diagonal_esquerda) e (abaixo >= diagonal_direita) */
             if(mat[i+1][j] >= mat[i][j-1] && mat[i+1][j] >= mat[i][j+1] &&
                mat[i+1][j] >= mat[i+1][j-1] && mat[i+1][j] >= mat[i+1][j+1]){
                i++;
                sum += mat[i][j];
                mat[i][j] = -1;
            }   
            /* condicao 2.3.2
               (esquerda >= abaixo) e (esquerda >= direita) e
               (esquerda >= diadonal_esquerda) e (esquerda >= diagonal_direita) */
            else if(mat[i][j-1] >= mat[i+1][j] && mat[i][j-1] >= mat[i][j+1] &&
                    mat[i][j-1] >= mat[i+1][j-1] && mat[i][j-1] >= mat[i+1][j+1]){
                j--;
                sum += mat[i][j];
                mat[i][j] = -1;
            }
            /* condicao 2.3.3
               (direita >= abaixo) e (direita >= esquerda) e
               (direita >= diagonal_esquerda) e (direita >= diagonal_direita) */
            else if(mat[i][j+1] >= mat[i+1][j] && mat[i][j+1] >= mat[i][j-1] &&
                    mat[i][j+1] >= mat[i+1][j-1] && mat[i][j+1] >= mat[i+1][j+1]){
                j++;
                sum += mat[i][j];
                mat[i][j] = -1;
            }
            /* condicao 2.3.4
               (diagonal_esquerda >= diagonal_direita) */
            else if(mat[i+1][j-1] >= mat[i+1][j+1]){
                j--;
                i++;
                sum += mat[i][j];
                mat[i][j] = -1;
            }
            /*  condicao 2.3.5
               (diagonal_direita >= diagonal_esquerda) */
            else{
                j++;
                i++;
                sum += mat[i][j];
                mat[i][j] = -1;
            }
        }
    }
    /* condicao 3
       ( (linha(i) = linha(máxima)) e (coluna(j) = coluna(máxima)) ) */
    if(i == (n-1) && j == (n-1)){
        sum += mat[i][j];
        mat[i][j] = -1;
        return sum+1;
    }
   }
   //return sum;
}