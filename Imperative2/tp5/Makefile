CC =gcc
CFLAGS = -Wall -lm

main:	main.o func.o func.h
	$(CC) $^ $(CFLAGS) -o executable

%.o:	%.c func.h
	$(CC) $< $(CFLAGS) -c

clean:
	rm -f *.o executable
