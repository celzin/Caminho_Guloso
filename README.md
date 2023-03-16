# Contando Instruções

<div style="display: inline-block;">
<img align="center" alt="C" src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" />
<img align="center" height="28px" width="112px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
</a> 
</div>

<p> </p>
<p> </p>

## Problema
<p align="justify">
O objetivo desse trabalho é elaborar um programa para caminhar por um conjunto de matrizes N x N, com o valor de N e as matrizes sendo fornecidas como entrada do programa em formato de arquivo, objetivando encontrar o maior valor final seguindo um conjunto de regras preestabelecidas.

1. Criar um sistema que leia K matrizes quadradas no tamanho NxN.
2. Seu programa deve enumerá-las, de forma a deixa-las organizadas para processamento. 
3. Partindo da primeira matriz, você deve iniciar de um ponto preestabelecido, esse pode ser fornecido pelo usuário ou estar contido em arquivos extras de configuração. Não é permitido definir diretamente no código. 
4. A partir da primeira matriz, você tem como regras: 
   - Avançar para a próxima coluna; 
   - Retroceder para coluna anterior; 
   - Saltar para a linha de baixo; 
   - Ir em diagonal para baixo;
   - Observação: Todas essas regras só se aplicam se a casa (posição i,j da matriz) ainda não tenha sido descoberta ou já processada.
5. Para caminhar você deve sempre optar pelo valor da próxima casa, valor esse que deve ser o maior dentre eles. Caso haja empate entre casas, crie uma regra para adotar sempre uma mesma decisão de caminhamento. 
6. Ao alcançar a última linha e coluna da matriz, selecione a próxima matriz e repita todo o processo novamente. Por fim, apresente ao usuário qual foi o caminho adotado e qual a soma obtida do caminho realizado. 
	
</p>

## Beginning
<p align="justify">
Para o desenvolvimento de uma matriz N x N com números inteiros aleatórios de 0 a 99, utilizei o método de ordenção em bolha para criar um loop, então criei os métodos <code>startMatriz</code> para gerar a matriz randômica e <code>printMatriz</code> para imprimi-la.
</p>



```c
void startMatriz(int n, int A[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            A[i][j] = rand()%99;
        }
    }
}
void printMatriz(int n, int A[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("| %d |\t", A[i][j]);
        }
        printf("\n");
    }
}
```

## Brainstorm
<p align="justify">
Para a lógica do contador de instruções precisei organizar um <code>brainstorm</code> buscando analisar as possíveis condições que o programa deveria seguir para se manter dentro das regras prescritas pelo professor.
</p>

```c
enquanto(i < n e j < n){
	*condicao 1*
	se(j = 0 e i < n-1){
		*condicao 1.1*
		se(direita >= abaixo e direita != -1){
			escolho direita
		}
		*condicao 1.2*
		senao{
			escolho abaixo
		}
	}
	*condicao 2*
	senao se(i = n-1){
		escolho direita
	}
	*condicao 3*
	senao se(j = n-1){
		*condicao 3.1*
		se(esquerda >= abaixo e esquerda != -1){
			escolho esquerda
		}
		*condicao 3.2*
		senao{
			escolho abaixo
		}
	}
	*condicao 4*
	senao{
		*condicao 4.1*
		se(direita = -1){
			*condicao 4.1.1*
			se(abaixo >= esquerda){
				escolho abaixo
			}
			*condicao 4.1.2*
			senao{
				escolho esquerda
			}
		}
		*condicao 4.2*
		senao se(esquerda = -1){
			*condicao 4.2.1*
			se(abaixo >= direita){
				escolho abaixo
			}
			*condicao 4.2.2*
			senao{
				escolho direita
			}
		}
		*condicao 4.3*
		senao{
			*condicao 4.3.1*
			se(abaixo >= direita e direita >= esquerda){
				escolho abaixo
			}
			*condicao 4.3.2*
			senao se(direita >= abaixo e direita >= esquerda){
				escolho direita
			}
			*condicao 4.3.3*
			senao(esquerda >= abaixo e esquerda >= direita){
				escolho esquerda
			}
		}
	}
}
```

## Método de Contar Instruções

<p align="justify">
Partindo do apresentado, busquei criar um loop que trabalha até chegar ao último termo da matriz N x N. Além disso, apliquei as ideias do <code>brainstorm</code>, implementando as condições previstas, ajustando para que o valor da soma fosse guardado e criando um método para atribuir o <code>-1</code> ao valor das posições NxN após serem percorridas, de acordo com as regras do programa, a fim de marcar o caminho percorrido na matriz.
</p>

```c
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
```
## Testando
<p align="justify">
	Criando um exemplo de teste para o método <code>instructCounter</code> para uma matriz com N = 7.
</p>

<p align="center">
	<img src="imgs/matrizN7.png"/> 
</p>

<p align="center">
	28 + 43 + 72 + 79 + 41 + 54 + 79 + 55 + 98 + 76 + 95 + 54 + 51 + 43 + 59 + 20 + 29 = 976
</p>


<!--
## Questionamentos Finais
</p>
1) - Há mais de uma maneira de resolver esse problema ?
</p>
<p align="justify">
Acredito que hajam diversas maneiras para a resolução do problema proposto e possivelmente uma diminuição do custo computacional gerado, porém a maneira apresentada foi a única que consegui implementar.
</p>
2) - Há algoritmos em literatura que resolvam esse problema ?
</p>
<p align="justify">
Presumo que dentro do conteúdo de estrutura de dados há um meio para armazenar e organizar dados com maior facilidade ao acesso e às modificações.
</p>
3) - Pode existir mais de um caminho cujo valor total é o maximo?
</p>
<p align="justify">
Pelo que pude notar sim, uma vez que o caminho seguido pelo programa, através da regra definida previamente pelo professor, mostra que nem sempre ocorre a escolha dos maiores valores dentro da matriz, quando na verdade o algoritmo escolhe os maiores valores "próximos" ao valor escolhido anteriormente, podendo estes serem variados devido ao fator randômico da matriz, e nem sempre os maiores possiveis dentro de toda a matriz gerada.
</p>
-->
