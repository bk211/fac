CC = gcc
SRC = compilation1.c
OBJ= $(SRC:.c=.o)
LIB=$(SRC:.c=.h)
FLAGS = -Wall
NAME=executable

$(NAME):	$(OBJ) 
	$(CC) -o $@ $(OBJ)

%.o:	%.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o $(NAME)
