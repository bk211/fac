CC = g++
CFLAGS=-pthread


executable: 	main.cpp
		$(CC) $(CFLAGS) -o executable $<

r:	executable
	./executable 100000 10

clean:
	rm -f executable Resultat_17812776_.txt
