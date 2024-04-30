# **Operações com Decimais**
### **por Luan Valle**
A estrutura Decimal é uma estrutura em C que permite trabalhar com números decimais de **precisão fixa de 9 dígitos inteiros e 9 dígitos decimais**. Para começar a usar, você precisa incluir o arquivo **decimal** no seu código C.	

```C
#include "decimal.h" ou #include "decimal.c"
```
> [!TIP]
> Usar "decimal.c" diretamente tende a funcionar melhor.
> >Ao usar "decimal.h" é necessário compilar o código fonte decimal.c junto de seu código.

> [!IMPORTANT]
> Caso o arquivo não esteja no mesmo diretório de seu código é necessário especificar o caminho em na inclusão

## **Funções Disponíveis**
A estrutura Decimal oferece as seguintes funções:

|**Função**|**Descrição**|
| :-- | :-- |
|set_value(Decimal *this, char *number)|Define o valor do número decimal.|
|get_number(Decimal *this)|Retorna o número decimal como uma string formatada.|
|decimal_add(Decimal *res, Decimal *n1, Decimal *n2)|Adiciona dois números decimais.|
|decimal_sub(Decimal *res, Decimal *n1, Decimal *n2)|Subtrai dois números decimais.|
|decimal_mult(Decimal *res, Decimal *n1, Decimal *n2)|Multiplica dois números decimais.|
## **Exemplo de Uso**
Aqui está um exemplo de como usar a estrutura Decimal e suas funções de operações:
```C
#include "decimal.c"

int main() {

  // Cria novos números decimais
  Decimal *num1 = new_Decimal();
  Decimal *num2 = new_Decimal();
  Decimal *resultado = new_Decimal();

  // Define os valores dos números
  num1->set_value(num1, "123.456");
  num2->set_value(num2, "789.012");

  // Realiza a operação de adição
  decimal_add(resultado, num1, num2);

  // Imprime o resultado
  printf("Resultado da adicao: %s\n", resultado->get_number(resultado));

  // Libera a memória alocada
  destroy_Decimal(num1);
  destroy_Decimal(num2);
  destroy_Decimal(resultado);

  return 0;
}
```
## **Progresso**

![](https://geps.dev/progress/62)

- [x] Estrutura de precisão fixa
- [x] Operação de adição
- [x] Operação de subtração
- [x] Operação de multiplicação
- [x] Testes de adição, subtração e multiplicação
- [ ] Operação de divisão
- [ ] Testes de divisão
**V 1.0 🎉**
- [ ] Identificar operações inválidas com antecedência

## **Considerações Finais**
> [!CAUTION]
>**Certifique-se de gerenciar corretamente a alocação e liberação de memória ao usar esta estrutura.**

> [!WARNING]
> A precisão é fixa, tenha certeza de que as operações não irão exceder o limite da estrutura

> [!NOTE]
> A operação de divisão será implementada posteriormente.
-----
Desenvolvido por [Luan Henrique do Valle](https://github.com/luanvalle01), 2024
