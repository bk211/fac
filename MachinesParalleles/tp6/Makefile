CC = g++
CFLAGS=-pthread


executable: 	trafic.cpp
		$(CC) $(CFLAGS) -o executable $<

r:	executable
	./executable

clean:
	rm -f executable
