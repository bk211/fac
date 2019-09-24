CC=gcc
SRC=puis.c main.c
OBJ=$(SRC:.c=.o)
FLAGS= -Wall

puissance:    $(OBJ) puis.h
	$(CC) -o $@ $(OBJ)

main.o:		main.c
	$(CC) -c main.c $(CFLAGS)
puis.o: 	puis.c
	$(CC) -c puis.c $(CFLAGS)

clean:
	rm *.o puissance
