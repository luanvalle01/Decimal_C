# **Operações com Decimais**
### `	`**por Luan Valle**
`	`A estrutura Decimal é uma estrutura em C que permite trabalhar com números decimais de precisão fixa (9 dígitos decimais e 9 dígitos inteiros). Para começar a usar, você precisa incluir o arquivo de cabeçalho `decimal.h` no seu código C.	

#include "decimal.h" 

`	`Ou	

#include "decimal.c" 
## **Funções Disponíveis**
`	`A estrutura Decimal oferece as seguintes funções:

|**Função**|**Descrição**|
| :-: | :-: |
|set\_value(Decimal \*this, char \*number)|Define o valor do número decimal.|
|get\_number(Decimal \*this)|Retorna o número decimal como uma string formatada.|
|decimal\_add(Decimal \*res, Decimal \*n1, Decimal \*n2)|Adiciona dois números decimais.|
|decimal\_sub(Decimal \*res, Decimal \*n1, Decimal \*n2)|Subtrai dois números decimais.|
|decimal\_mult(Decimal \*res, Decimal \*n1, Decimal \*n2)|Multiplica dois números decimais.|
## **Exemplo de Uso**
Aqui está um exemplo de como usar a estrutura Decimal e suas funções de operações:

#include "decimal.h"

int main() {

`	`// Cria novos números decimais

`	`Decimal \*num1 = new\_Decimal();

`	`Decimal \*num2 = new\_Decimal();

`	`Decimal \*resultado = new\_Decimal();



`	`// Define os valores dos números

`	`num1->set\_value(num1, "123.456");

`	`num2->set\_value(num2, "789.012");



`	`// Realiza a operação de adição

`	`decimal\_add(resultado, num1, num2);



`	`// Imprime o resultado

`	`printf("Resultado da adição: %s\n", resultado->get\_number(resultado));



`	`// Libera a memória alocada

`	`destroy\_Decimal(num1);

`	`destroy\_Decimal(num2);

`	`destroy\_Decimal(resultado);



`	`return 0;

}
## **Considerações Finais**
1. **Certifique-se de gerenciar corretamente a alocação e liberação de memória ao usar esta estrutura.**
1. A precisão é fixa, tenha certeza de que as operações não irão exceder o limite da estrutura
1. A operação de divisão será implementada posteriormente.
-----
Desenvolvido por [Luan Henrique do Valle](https://github.com/luanvalle01), 2024
