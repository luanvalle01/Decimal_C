#include "decimal.h"

//TEST_____________________________________________//
void test(){
	Decimal *numero1 = new_Decimal();
	Decimal *numero2 = new_Decimal();
	Decimal *resultado = new_Decimal();
	
	/* TEST BY CHAT GPT*/
	//-----------------------------//
	//				ADD	  		   //
	//-----------------------------//
	numero1->set_value(numero1, "123.456");
	numero2->set_value(numero2, "789.012");
	decimal_add(resultado, numero1, numero2);
	printf("\nN1: %s\nN2: %s", get_number(numero1), get_number(numero2));
	printf("\nSUM: %s\n",  get_number(resultado));

	numero1->set_value(numero1, "-123.456");
	numero2->set_value(numero2, "-789.012");
	decimal_add(resultado, numero1, numero2);
	printf("\nN1: %s\nN2: %s", get_number(numero1), get_number(numero2));
	printf("\nSUM: %s\n",  get_number(resultado));
	
	numero1->set_value(numero1, "123.456");
	numero2->set_value(numero2, "-789.012");
	decimal_add(resultado, numero1, numero2);
	printf("\nN1: %s\nN2: %s", get_number(numero1), get_number(numero2));
	printf("\nSUM: %s\n",  get_number(resultado));
	
	numero1->set_value(numero1, "100");
	numero2->set_value(numero2, "0.123");
	decimal_add(resultado, numero1, numero2);
	printf("\nN1: %s\nN2: %s", get_number(numero1), get_number(numero2));
	printf("\nSUM: %s\n",  get_number(resultado));

	// Teste de soma com números menores e dentro do intervalo suportado por long long int
	numero1->set_value(numero1, "123456.789");
	numero2->set_value(numero2, "98765.4321");
	decimal_add(resultado, numero1, numero2);
	printf("\nN1: %s\nN2: %s", get_number(numero1), get_number(numero2));
	printf("\nSUM: %s\n",  get_number(resultado));
	
	numero1->set_value(numero1, "-123456.789");
	numero2->set_value(numero2, "98765.4321");
	decimal_add(resultado, numero1, numero2);
	printf("\nN1: %s\nN2: %s", get_number(numero1), get_number(numero2));
	printf("\nSUM: %s\n",  get_number(resultado));
	
	numero1->set_value(numero1, "123456.789");
	numero2->set_value(numero2, "-98765.4321");
	decimal_add(resultado, numero1, numero2);
	printf("\nN1: %s\nN2: %s", get_number(numero1), get_number(numero2));
	printf("\nSUM: %s\n",  get_number(resultado));
	
	numero1->set_value(numero1, "-123456.789");
	numero2->set_value(numero2, "-98765.4321");
	decimal_add(resultado, numero1, numero2);
	printf("\nN1: %s\nN2: %s", get_number(numero1), get_number(numero2));
	printf("\nSUM: %s\n______\n",  get_number(resultado));

	//-----------------------------//
	//			  SUB	  		   //
	//-----------------------------//
	// Teste 1: Subtração de números positivos menores
	numero1->set_value(numero1, "1234567.890123456");
	numero2->set_value(numero2, "987654.321098765");
	decimal_sub(resultado, numero1, numero2);
	printf("\nN1: %s\nN2: %s", get_number(numero1), get_number(numero2));
	printf("\nSUB: %s\n",  get_number(resultado));
	
	// Teste 2: Subtração de números negativos menores
	numero1->set_value(numero1, "-1234567.890123456");
	numero2->set_value(numero2, "-987654.321098765");
	decimal_sub(resultado, numero1, numero2);
	printf("\nN1: %s\nN2: %s", get_number(numero1), get_number(numero2));
	printf("\nSUB: %s\n",  get_number(resultado));
	
	// Teste 3: Subtração de número positivo por número negativo menores
	numero1->set_value(numero1, "1234567.890123456");
	numero2->set_value(numero2, "-987654.321098765");
	decimal_sub(resultado, numero1, numero2);
	printf("\nN1: %s\nN2: %s", get_number(numero1), get_number(numero2));
	printf("\nSUB: %s\n",  get_number(resultado));
	
	// Teste 4: Subtração de número negativo por número positivo menores
	numero1->set_value(numero1, "-1234567.890123456");
	numero2->set_value(numero2, "987654.321098765");
	decimal_sub(resultado, numero1, numero2);
	printf("\nN1: %s\nN2: %s", get_number(numero1), get_number(numero2));
	printf("\nSUB: %s\n______\n",  get_number(resultado));
	
	//-----------------------------//
	//			 MULT	  		   //
	//-----------------------------//
	// Teste 1
	numero1->set_value(numero1, "-123.456");
	numero2->set_value(numero2, "45.678");
	decimal_mult(resultado, numero1, numero2);
	printf("\nN1: %s\nN2: %s", get_number(numero1), get_number(numero2));
	printf("\nMULT: %s\n", get_number(resultado));
	
	// Teste 2
	numero1->set_value(numero1, "1234.567");
	numero2->set_value(numero2, "89.012");
	decimal_mult(resultado, numero1, numero2);
	printf("\nN1: %s\nN2: %s", get_number(numero1), get_number(numero2));
	printf("\nMULT: %s\n", get_number(resultado));
	
	// Teste 3
	numero1->set_value(numero1, "-98765.432");
	numero2->set_value(numero2, "-0.123");
	decimal_mult(resultado, numero1, numero2);
	printf("\nN1: %s\nN2: %s", get_number(numero1), get_number(numero2));
	printf("\nMULT: %s\n", get_number(resultado));
	
	// Teste 4
	numero1->set_value(numero1, "4567890.123");
	numero2->set_value(numero2, "0.987");
	decimal_mult(resultado, numero1, numero2);
	printf("\nN1: %s\nN2: %s", get_number(numero1), get_number(numero2));
	printf("\nMULT: %s\n", get_number(resultado));

	destroy_Decimal(numero1);
	destroy_Decimal(numero2);
	destroy_Decimal(resultado);
}

void main(){
	test();
}