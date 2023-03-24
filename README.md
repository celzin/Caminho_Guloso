# Algoritmo Guloso

<div style="display: inline_block">
  <img align="center" alt="C" src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" />
  <img align="center" alt="CMake" src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" />
  <img align="center" alt="VS" src="https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white" />
</div><br/>

<p> </p>
<p> </p>

# Apresentação do Problema
<p align="justify">
O objetivo desse trabalho é elaborar um programa para caminhar por um conjunto de matrizes N x N, com o valor de N e as matrizes sendo fornecidas como entrada do programa em formato de arquivo, objetivando encontrar o maior valor final seguindo um conjunto de regras preestabelecidas.
</p>


<p align="justify">
	1️⃣ Criar um sistema que leia K matrizes quadradas no tamanho NxN.
</p>
<p align="justify">
	2️⃣ Seu programa deve enumerá-las, de forma a deixa-las organizadas para processamento.
</p>
<p align="justify">
	3️⃣ Partindo da primeira matriz, você deve iniciar de um ponto preestabelecido, esse pode ser fornecido pelo usuário ou estar contido em arquivos extras de 		configuração. Não é permitido definir diretamente no código.
</p>	
<p align="justify">
	4️⃣ A partir da primeira matriz, você tem como regras:
	
	➡️ Avançar para a próxima coluna;
	⬅️ Retroceder para coluna anterior;
	⬇️ Saltar para a linha de baixo;
	↙️ Ir em diagonal para baixo; ↘️
	⚠️ Observação: Todas essas regras só se aplicam se a casa (posição [i][j] da matriz) ainda não tenha sido percorrida.
</p>
<p align="justify">
	5️⃣ Para caminhar você deve sempre optar pelo valor da próxima casa, valor esse que deve ser o maior dentre eles. Caso haja empate entre casas, crie uma regra 		para adotar sempre uma mesma decisão de caminhamento.
</p>
<p align="justify">
	6️⃣ Ao alcançar a última linha e coluna da matriz, selecione a próxima matriz e repita todo o processo novamente. Por fim, apresente ao usuário qual foi o 		caminho adotado e qual a soma obtida do caminho realizado	
</p>

# O que seria "Algoritmo Guloso"?
<p align="justify">

O conceito por trás da expressão [<code>Algoritmo Guloso</code>](https://www.ime.usp.br/~pf/analise_de_algoritmos/aulas/guloso.html) em destaque gira em torno da ideia de percorrer uma matriz de <code>NxN</code> elementos, de forma a caminhar ao longo dessa matriz escolhendo os maiores valores possíveis contidos nela, evitando passar por valores já percorridos e voltar linhas, ou seja, subir ou passar por um valor previamente já percorrido não é uma opção. Caso não tenha ficado claro, basta observar a imagem abaixo a fim de se orientar.
	
</p>

<p align="center">
<img src="imgs/esquema.png" width="600"/>
</p>
<p align="center">
<em>Imagem 1: Diagrama esquemático das regras para percorrer a matriz</em>
</p>

# Lógica para Caminhar na Matriz
<p align="justify">
A lógica utilizada de percorrer o caminho seguindo as regras apresentadas pelo professor consistiu em 3 condições maiores e diversas sub-condições dentro delas. Foi necessário organizar um tipo de <code>brainstorm</code> buscando analisar as possíveis condições que o programa deveria seguir para se manter dentro do caminho esperado, assim chegou-se esquema lógico esboçado abaixo. (Obs.: A imagem abaixo não contém trechos de código, sendo apenas um esboço).
</p>

<p align="center">
<img src="imgs/caminhar.png"/> 
</p>
<p align="center">
<em>Imagem 2: Esboço da implementação do método para percorrer a matriz.</em>
</p>

# Solução do Problema

<div align="justify">
	
Partindo do problema apresentado, a ideia principal para sua solução gira em torno do tratamento de arquivos. Desse modo, primeiramente criou-se o método [<code>tokenizarLinha()</code>](https://github.com/zelzo/Caminho_Guloso/blob/main/src/matriz.c#L41) que trabalha fazendo a quebra e leitura da primeira linha apresentada no arquivo, a qual representa o tamanho <code>NxN</code> das matrizes geradas e que será usada ao decorrer do programa para o tratamento do tamanho das matrizes. Logo em seguida gerou-se o método [<code>tokenizarMatriz()</code>](https://github.com/zelzo/Caminho_Guloso/blob/main/src/matriz.c#L26) a fim de fragmentar cada fração do arquivo conforme a regra estabelecida e, nesse caso, asssumir como valores de uma matriz.
	
</div>

<div align="justify">
	
A frente, dando sequência ao tratamento de arquivo foi criado o método [<code>readSpace()</code>](https://github.com/zelzo/Caminho_Guloso/blob/main/src/matriz.c#L105) ao qual faz a leitura do arquivo e conta os espaços em branco entre as matrizes a fim de demarcar e separar as diversas matrizes ao longo do arquivo. Em conjunto, tem-se o método [<code>readFile()</code>](https://github.com/zelzo/Caminho_Guloso/blob/main/src/matriz.c#L59) ao qual de fato faz a leitura do arquivo implementando os métodos [<code>tokenizarLinha()</code>](https://github.com/zelzo/Caminho_Guloso/blob/main/src/matriz.c#L41) e [<code>tokenizarMatriz()</code>](https://github.com/zelzo/Caminho_Guloso/blob/main/src/matriz.c#L26) previamente já exemplificados. 
	
</div>

<div align="justify">
	
Ademais, foram aplicadas as ideias apresentadas previamente no <code>brainstorm</code>, implementando as condições previstas na função [<code>caminharMatriz()</code>](https://github.com/zelzo/Caminho_Guloso/blob/main/src/matriz.c#L135), que basicamente funciona ajustando para que o valor da <code>soma</code> seja guardado e criando um método para atribuir o <code>-1</code> ao valor das posições <code>[i][j]</code> após serem percorridas, de acordo com as regras do programa e a fim de demarcar o caminho percorrido na matriz. Ao final, temos o método [<code>readFile()</code>](https://github.com/zelzo/Caminho_Guloso/blob/main/src/matriz.c#L59) sendo chamado na [<code>main</code>](https://github.com/zelzo/Caminho_Guloso/blob/main/src/main.c), que como já exposto, será de suma importância para o tratamento de arquivos no programa vigente e, por fim, tem-se a função [<code>printCaminho()</code>](https://github.com/zelzo/Caminho_Guloso/blob/main/src/matriz.c#L14) que chama a função [<code>caminharMatriz()</code>](https://github.com/zelzo/Caminho_Guloso/blob/main/src/matriz.c#L135) sempre que uma nova matriz do arquivo é lida e imprime as matrizes, juntamente com o caminho percorrido e a soma de cada uma delas no terminal.
	
</div>

# Testes
<p align="justify">
Criando um exemplo de teste da aplicação para uma matriz 7x7, contendo 3 matrizes no arquivo que será lido, caso o programa funcione como o esperado, teremos o seguinte resultado.
</p>

<p align="center">
<img src="imgs/input7x7.png" width="450"/> 
</p>
<p align="center">
<em>Imagem 3: Entrada em formato de arquivo com 3 matrizes de tamanho 7x7.</em>
</p>

<p align="center">
<img src="imgs/teste3.png"/> 
</p>
<p align="center">
<em>Imagem 4: Saída no terminal após execução da aplicação monstrando as 3 matrizes lidas, o caminho percorrido e a soma deste em cada uma delas.</em>
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

# Compilação e Execução

<p align="justify">
Primeiramente, para o correto funcionamento do programa é necessário incluir um arquivo nomeado preferencialmente de <code>input.data</code> dentro da pasta <code>dataset</code>, devendo seguir o seguinte formato:
	
- Em sua primeira linha: os valores NxN que serão assumidos pelas matrizes geradas
- Logo em seguida as matrizes espaçadas conforme o exemplo abaixo
</p>

<p align="center">
<img src="imgs/input.png" width="250"/> 
</p>
<p align="center">
<em>Imagem 5: Demonstração do formato de arquivo aceito pelo programa.</em>
</p>

<p align="justify">
Por fim, esse programa possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:
</p>

| Comando                |  Função                                                                                               |                     
| -----------------------| ------------------------------------------------------------------------------------------------------|
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                            |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build               |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                     |

## Contatos

<div style="display: inline-block;">
<a href="https://t.me/celso_vsf">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
</a>

</div>
