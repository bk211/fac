CC = g++
CFLAGS=-pthread


1: 	cond_var.cpp
		$(CC) $(CFLAGS) -o executable $<
2: 	producteur_consomateur.cpp
	$(CC) $(CFLAGS) -o executable $<


r:
	./executable

clean:
	rm -f executable
