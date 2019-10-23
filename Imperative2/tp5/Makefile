
CC =gcc
CFLAGS = -lm

run: executable
	./executable

executable:	main.o func.o func.h
	$(CC) $^ $(CFLAGS) -o executable

%.o:	%.c
	$(CC) $< $(CFLAGS) -c

clean:
	rm -f *.o executable
