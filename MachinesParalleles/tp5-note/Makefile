CC = g++
CFLAGS=-pthread


executable: 	erasto.cpp
		$(CC) $(CFLAGS) -o executable $<

million:	executable
	./executable 1000000 4

dix_millions:	executable
	./executable 10000000 4

cent_millions:	executable
	./executable 100000000 4

milliard:	executable
	./executable 1000000000 4

clean:
	rm -f executable Resultat_17812776_.txt
