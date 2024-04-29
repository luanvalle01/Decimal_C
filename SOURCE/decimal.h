#ifndef DECIMAL_H_INCLUDED
#define DECIMAL_H_INCLUDED

typedef struct Decimal Decimal;

struct Decimal{
	char value[21];//To math
	/* VALUE[0] SIGNAL
	   VALUE[21] '\0' */
	
	char number[21];//To print
	/* NUMBER[0] SIGNAL
	   NUMBER[10] '.'
	   NUMBER[21] '\0' */
	
	void (*set_value)(Decimal *this, char *number);
	char *(*get_number)(Decimal *this);
};

void format_number(Decimal *this);
void set_value(Decimal *this, char *number);
char *get_number(Decimal *this);
void decimal_add(Decimal *res, Decimal *n1, Decimal *n2);
void decimal_sub(Decimal *res, Decimal *n1, Decimal *n2);
void decimal_mult(Decimal *res, Decimal *n1, Decimal *n2);
Decimal *new_Decimal();
void destroy_Decimal(Decimal *this);

#endif
