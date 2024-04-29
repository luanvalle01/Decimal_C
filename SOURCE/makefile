CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

SRC = test_decimal.c decimal.c
OBJ = $(SRC:.c=.o)
EXEC = ..\teste_decimal

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(EXEC)
