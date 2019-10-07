CC=g++
CFLAGS=-pthread


2:	tp2.cpp md5.o
	$(CC) $(CFLAGS) md5.o -o 2 $<

md5.o:	md5.c md5.h
	$(CC) $(CFLAGS) -c $<

1:	tp1.cpp
		$(CC) $(CFLAGS) -o 1 $<

clean:
	rm -f 1 2 *.o
