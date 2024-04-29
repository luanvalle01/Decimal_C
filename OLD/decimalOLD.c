#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TROCAR DOIS LONG INT POR UM ÚNICO LONG LONG INT
//FAZER TODAS AS OPERAÇÕES NORMALMENTE
//APENAS NA HORA DE EXIBIR SEPARAR OS NUMEROS

typedef struct Decimal Decimal;

struct Decimal{
	unsigned long int integers;
	unsigned long int decimals;
	
	char number[20];//INDEX 0 STORE SIGNAL
	void (*set_number)(Decimal *this, char *number);
	char *(*get_number)(Decimal *this);
};

//SET NUMBER______________________________________________//
void set_number(Decimal *this, char *number){
	int i = 0;
	char str_integers[10];
	char str_decimals[10];
	
	for(i ; i < 10; i++){
		str_integers[i] = '\0';
		str_decimals[i] = '\0';
	}
	i = 0;

	while(number[i] != '.' && number[i] != ','){
		str_integers[i] = number[i];
		i++;
		
		if(number[i] == '\0'){
			i = -1;//Red flag
			break;
		}
	}
	
	this->integers = atol(str_integers);
	
	if(i != -1){
		str_decimals[0] = '1'; //Forces presevation of all numbers after;
		strcpy(&(str_decimals[1]) , &(number[i + 1]));
		this->decimals = atol(str_decimals);
	}
	else{
		this->decimals = 0;
	}
}

//GET NUMBER______________________________________________//
char *get_number(Decimal *this){
	char temp_integers[10];
	char temp_decimals[10];
	
	sprintf(temp_integers,"%lu.", this->integers);
	sprintf(temp_decimals,"%lu", this->decimals);
	
	strcpy(&(this->number[1]), temp_integers);
	
	if(!this->decimals){
		temp_decimals[1] = '0';
		temp_decimals[2] = '\0';
	}
	
	strcat(this->number, &(temp_decimals[1]));
	
	return this->number;
}

//DATA ALIGNAMENT_________________________________________//
void resize_decimals(char *decimals, int newsize){
	int i = strlen(decimals);
	
	while(i < newsize){
		decimals[i] = '0';
		i++;
	}
	
	decimals[0] = '1';
	decimals[i] = '\0';
}

void equalize_decimals(char decimals1[10], char decimals2[10]){
	/* Checks qtd digits of values and "trunc" 
	   to same size. It's necessary to decimals operations */
	
	short int len1 = strlen(decimals1);
	short int len2 = strlen(decimals2);
	
	if(len1 == len2)
		return;
	
	if(len1 > len2)
		resize_decimals(decimals2,len1);
	else
		resize_decimals(decimals1,len2);
}

//ADD OPERATION___________________________________________//
void decimal_add(Decimal *res, Decimal *n1, Decimal *n2){
	//Decimal equalization
	char decimals1[10];
	char decimals2[10];
	
	sprintf(decimals1,"%lu", n1->decimals);
	sprintf(decimals2,"%lu", n2->decimals);
	
	equalize_decimals(decimals1, decimals2);
	
	n1->decimals = atol(decimals1);
	n2->decimals = atol(decimals2);
	
	res->integers = n1->integers + n2->integers;
	res->decimals = n1->decimals + n2->decimals;
	
	//In cases whith .5[...] + .5[...]
	sprintf(decimals1,"%lu", res->decimals);
	if(decimals1[0] == '3')
		res->integers += 1;
}

//SUB OPERATION___________________________________________//
void decimal_sub(Decimal *res, Decimal *n1, Decimal *n2){
	//Decimal equalization
	char decimals1[10];
	char decimals2[10];
	
	sprintf(decimals1,"%lu", n1->decimals);
	sprintf(decimals2,"%lu", n2->decimals);
	
	equalize_decimals(decimals1, decimals2);
	
	n1->decimals = atol(decimals1);
	n2->decimals = atol(decimals2);
	
	long unsigned int pow = 1;
	int qtd_digits = strlen(decimals1);
	for(int i = 0; i < qtd_digits; i++)
		pow = pow * 10;
	
	//Decimal operations
	if(n1->decimals > n2->decimals){	
		res->decimals =  n1->decimals - n2->decimals;
	}
	else{
		res->decimals =  pow - (n2->decimals - n1->decimals);
	}
	
	//Integer operations
	if(n1->integers > n2->integers){
		res->integers = n1->integers - n2->integers;
	}
	else{
		res->integers = 0;
		res->decimals = res->decimals =  pow - (n1->decimals - n2->decimals);
	}
	
	if(n2->decimals > n1->decimals && res->integers)
		res->integers -= 1;
	
	//Decimal presevation
	sprintf(decimals1,"%lu", res->decimals);
	if(decimals1[0] != '1'){
		char temp[10];
		for(int i = 1; i < 10; i++){
			temp[i] = decimals1[i - 1];
		}
		temp[0] = '1';
		res->decimals = atol(temp);
	}
	
	
	//Signal check
	if(n2->integers >= n1->integers /*&& n2->decimals >= n1->decimals*/)
		res->number[0] = '-';
	else
		res->number[0] = ' ';
}

//CONSTRUCTOR_____________________________________________//
Decimal *new_Decimal(){
	Decimal *self = (Decimal *) malloc(sizeof(Decimal));
	
	self->integers = 0;
	self->decimals = 0;
	self->number[0] = ' ';
	
	self->set_number = &set_number;
	self->get_number = &get_number;
}

void main(int arc, char *argv[]){
	Decimal *numero1 = new_Decimal();
	numero1->set_number(numero1, argv[1]);

	Decimal *numero2 = new_Decimal();
	numero2->set_number(numero2, argv[2]);
	
	Decimal *numero3 = new_Decimal();
	
	printf("\n%s\n", get_number(numero1));
	printf("%s\n",  get_number(numero2));
	
	decimal_sub(numero3, numero1, numero2);
	
	printf("\n\nRESULTADO: %s",  get_number(numero3));
}