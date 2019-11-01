CC = g++
CFLAGS=-pthread


executable: 	count.cpp count.h 
		$(CC) $(CFLAGS) -o executable $<

r:
	./executable test.txt

clean:
	rm -f executable
