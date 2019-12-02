NB = 4

exec:	main.cpp
	mpic++ main.cpp -o $@

run:	exec
	mpirun -n $(NB) $<

clean:
	rm -f exec *.out
