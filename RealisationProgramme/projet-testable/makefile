
pendu: pendu2.o fonctions.o
	gcc -o pendu pendu2.o fonctions.o

pendu2.o: pendu2.c
	gcc -c pendu2.c

fonctions.o: fonctions.c
	gcc -c fonctions.c

testpendu: test_pendu.o fonctions.o
	gcc -o testpendu test_pendu.o fonctions.o 

test_pendu.o: test_pendu.c
	gcc -c test_pendu.c

