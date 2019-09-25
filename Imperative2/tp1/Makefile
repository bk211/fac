CC = gcc
SRC = tp1.c suite.c
OBJ= $(SRC:.c=.o)
LIB=$(SRC:.c=.h)
FLAGS = -Wall
NAME=executable

$(NAME):	$(OBJ) $(LIB)
	$(CC) -o $@ $(OBJ)

%.o:	%.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o $(NAME)
