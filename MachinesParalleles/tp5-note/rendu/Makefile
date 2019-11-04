CC = g++
CFLAGS=-pthread
NBTHREAD = 4

executable: 	count_primes.cpp count_primes.hpp
		$(CC) $(CFLAGS) -o executable $<

		
million:	executable
	./executable 1000000 $(NBTHREAD)
	wc -l Resultat_17812776_*

dix_millions:	executable
	./executable 10000000 $(NBTHREAD)
	wc -l Resultat_17812776_*
cent_millions:	executable
	./executable 100000000 $(NBTHREAD)
	wc -l Resultat_17812776_*
	
milliard:	executable
	./executable 1000000000 $(NBTHREAD)
	wc -l Resultat_17812776_*
	
clean:
	rm -f Resultat_17812776_*

