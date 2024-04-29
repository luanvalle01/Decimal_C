#include "decimal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FORMAT VALUE___________________________________________//
void format_value(char *number){
	for(int i = 1; i < 21; i++){
		number[i] = '0';
	}
	number[20] = '\0';
	number[0] = ' ';
}

//FORMAT NUMBER___________________________________________//
void format_number(Decimal *this) {
    int i = 20;
	char temp[21];
	
	strcpy(temp, this->number);
	
	//Set final decimal part
	while(temp[i - 1] == '0')
		i--;

	temp[i] = '\0';
	
	//Shift integer part
	i = 1;
	while(temp[i] == '0' && temp[i + 1] != '.')
		i++;
	strcpy(&(temp[1]), &(temp[i]));

	strcpy(this->number, temp);
}

//SET NUMBER______________________________________________//
void set_value(Decimal *this, char *number){
	int i = 0;
	int index_final = 0;
	char str_temp[10];
	char str_number[21];
	
	//Get exception
	if(strlen(number) > 19 || number[0] == 'N'){
		strcpy(this->value, "INVALID NUMBER");
		strcpy(this->number, "INVALID NUMBER");
		return;
	}
	
	format_value(str_number);
	
	//Fill temp integer part of string
	while(number[i] != '.' && number[i] != ',' && number[i] != '\0'){
		str_temp[i] = number[i];
		i++;
	}
	str_temp[i] = '\0';

	if(str_temp[0] == '-'){
		str_temp[0] = '0';
		this->number[0] = '-';
	}
	else{
		this->number[0] = ' ';
	}
	
	//Fill final integer part
	index_final = 10 - strlen(str_temp);//Find index
	strcpy(&(str_number[index_final]), str_temp);
	
	//Format decimal part
	strcpy(&(str_number[10]), "000000000");

	//Fill final decimal part
	if(number[i++] != '\0'){
		index_final = 10;
		while(number[i] != '\0')
			str_number[index_final++] = number[i++];
	}

	//Copy to struct Decimal
	strcpy(this->value, str_number);
}

//GET NUMBER______________________________________________//
char *get_number(Decimal *this){
	strcpy(&(this->number[1]), &(this->value[1]));
	this->number[10] = '.';
	strcpy(&(this->number[11]), &(this->value[10]));
	
	format_number(this);
	return this->number;
}

/******************  MATH OPERATIONS  ********************/
//SUPORT OPERATIONS_______________________________________//
unsigned long int ten_pow(short pow){
	unsigned long int res = 10;
	for(int i = 1; i < pow; i++)
		res = res * 10;
	return res;
}

short decimal_len(char *decimals){
	short i = 0;
	short last_number = 0;
	
	while(decimals[i] != '\0'){
		if(decimals[i] != '0')
			last_number = i;
		i++;
	}
	return last_number;
}

//ADD OPERATION___________________________________________//
void decimal_add(Decimal *res, Decimal *n1, Decimal *n2){
	unsigned long long int result;
	unsigned long long int result_integer;
	char res_integer[21];
	char res_decimal[21];
	short integer_len;
	
	result = atoll(&(n1->value[1]));
	result_integer = atoll(&(n2->value[1]));
	
	//-----------------------------//
	//  SIGNAL RULES & OPERATION   //
	//-----------------------------//
	//NORMAL CASE
	if(n1->number[0] == n2->number[0]){
		result = result +  result_integer;

		if(n1->number[0] == '-')
			res->number[0] = '-';
		else
			res->number[0] = ' ';
	}
	else{
		if(result > result_integer){
			result = result - result_integer;
			res->number[0] = n1->number[0];
		}
		else{
			result = result_integer - result;
			res->number[0] = n2->number[0];
		}
		
		if(!result)
			res->number[0] = ' ';
	}

	result_integer = result/1000000000;
	
	//-----------------------------//
	//	FORMATING TO SET NUMBER	   //
	//-----------------------------//
	res_integer[0] = res->number[0];
	sprintf(&(res_integer[1]),"%llu.", result_integer);
	sprintf(res_decimal,"%llu", result);
	
	integer_len = strlen(res_integer) - 2;
	strcat(res_integer, &(res_decimal[integer_len]));

	set_value(res, res_integer);
}

//SUB OPERATION___________________________________________//
void decimal_sub(Decimal *res, Decimal *n1, Decimal *n2){
	unsigned long long int result;
	unsigned long long int result_integer;
	char res_integer[21];
	char res_decimal[21];
	short integer_len;

	result = atoll(&(n1->value[1]));//N1
	result_integer =  atoll(&(n2->value[1]));//N2

	//-----------------------------//
	//  SIGNAL RULES & OPERATION   //
	//-----------------------------//
	if(n1->number[0] == '-' && n2->number[0] == '-'){
		if(result > result_integer){
			result = result - result_integer;
			res->number[0] = '-';
		}
		else{
			result = result_integer - result;
			res->number[0] = ' ';
		}
	}
	//NORMAL CASE
	else if(n1->number[0] == n2->number[0]){
		if(result >= result_integer){
			result = result - result_integer;
			res->number[0] = ' ';
		}
		else{
			result = result_integer - result;
			res->number[0] = '-';
		}
	}
	else{
		result = result + result_integer;
		if(n1->number[0] == '-' && n2->number[0] == ' ')
			res->number[0] = '-';
		else
			res->number[0] = ' ';
	}
	
	result_integer = result/1000000000;
	
	//-----------------------------//
	//	FORMATING TO SET NUMBER	   //
	//-----------------------------//
	res_integer[0] = res->number[0];
	sprintf(&(res_integer[1]),"%llu.", result_integer);
	sprintf(res_decimal,"%llu", result);
	
	integer_len = strlen(res_integer) - 2;
	strcat(res_integer, &(res_decimal[integer_len]));

	set_value(res, res_integer);
}

//MULT OPERATION___________________________________________//
void decimal_mult(Decimal *res, Decimal *n1, Decimal *n2){
	unsigned long long int number1;
	unsigned long long int number2;
	char format_number1[21];
	char format_number2[21];
	char temp[21];
	short decimal_pos, decimal_lenght, n1_decimal_len, n2_decimal_len;
	short pre_value1, pre_value2;
	
	for(int i = 0; i < 21; i++){
		format_number1[i] = '0';
		format_number2[i] = '0';
		temp[i] = '0';
	}
	
	//-----------------------------//
	//		PREFORMATTING          //
	//-----------------------------//
	/* Preformatting is necessary to give more
	   possibilities of operations. have no true
	   float points is so expensive...			*/
	
	//Integer pre format part
	number1 = atoll(n1->value) / 1000000000;//N1 INT
	number2 = atoll(n2->value) / 1000000000;//N2 INT
	
	sprintf(format_number1,"%llu", number1);
	sprintf(format_number2,"%llu", number2);
	
	//INVALID INTEGER NUMBER NUMBER
	if(number1 > 9999 && number2 > 9999){
		set_value(res, "NULL");
		return;
	}
	
	//Decimal pre formart part
	n1_decimal_len = decimal_len(&(n1->value[9]));
	n2_decimal_len = decimal_len(&(n2->value[9]));

	if(n1_decimal_len > n2_decimal_len)
		decimal_lenght = n1_decimal_len;
	else
		decimal_lenght = n2_decimal_len;

	//To preserve all decimals
	pre_value1 = n1->value[9];
	pre_value2 = n2->value[9];
	n1->value[9] = '1';
	n2->value[9] = '1';
	
	/* This reduce the final size of number */
	number1 = atoll(&(n1->value[9])) / ten_pow(9 - decimal_lenght);//N1 DECIMAL
	number2 = atoll(&(n2->value[9])) / ten_pow(9 - decimal_lenght);//N2 DECIMAL

	n1->value[9] = pre_value1;
	n2->value[9] = pre_value2;
	
	//INVALID DECIMAL NUMBER NUMBER
	if(number1 > 199999 || number2 > 199999){
		set_value(res, "NULL");
		return;
	}

	//-----------------------------//
	//		 FINAL FORMATTING      //
	//-----------------------------//
	//Final format N1
	sprintf(temp,"%llu", number1);
	strcat(format_number1, &(temp[1]));
	//Final format N2
	sprintf(temp,"%llu", number2);
	strcat(format_number2, &(temp[1]));
	//Get value
	number1 = atoll(format_number1);
	number2 = atoll(format_number2);
	
	//-----------------------------//
	//	     	 OPERATION	       //
	//-----------------------------//
	number1 = number1 * number2;//RESULT
	//Signal rule
	char signal;
	if(n1->number[0] != n2->number[0])
		signal = '-';
	else
		signal = ' ';
	
	//-----------------------------//
	//	FORMATING TO SET NUMBER	   //
	//-----------------------------//
	sprintf(format_number1,"%llu", number1);
	strcpy(temp, format_number1);
	decimal_pos = strlen(format_number1) - (decimal_lenght * 2);
	if(decimal_pos == 1)
		decimal_pos--;
	
	//Inlcude '.'
	strcpy(&(format_number1[decimal_pos + 1]), &(temp[decimal_pos]));
	format_number1[decimal_pos] = '.';
	
	//Previne overflow
	format_number1[decimal_pos + 9] = '\0';

	set_value(res, format_number1);
	res->number[0] = signal;
}

//CONSTRUCTOR_____________________________________________//
Decimal *new_Decimal(){
	Decimal *this = (Decimal *) malloc(sizeof(Decimal));
	
	this->set_value = &set_value;
	this->get_number = &get_number;
	
	this->number[0] = ' ';
	
	return this;
}
//DESTRUCTOR_____________________________________________//
void destroy_Decimal(Decimal *this){
	format_value(this->number);
	format_value(this->value);
	
	free(this);
}