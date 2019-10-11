# Compilation generique par Bourdin
CC=gcc
SRCDIRECT=miam.c fibiter.c direct.c
OBJDIRECT=$(SRCDIRECT:.c=.o)
FLAGS=-Wall

fool:    $(OBJDIRECT) direct.h
	$(CC) -o $@ $^
	rm fib.dat

%.o:	%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm *.o *~ core

hop:
	for i in 0 1 2 3 4 5 6 7 8 9
	do
		./fool $i ;
	done
