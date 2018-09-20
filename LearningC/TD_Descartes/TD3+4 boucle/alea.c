#include <stdlib.h>  
#include <stdio.h>  
#include <time.h>           

double tirage()
{rand();
    return (double)rand()/(RAND_MAX+1);
    //a mettre ds main();
    //srand((unsigned)time(NULL));
}

int main()
{	srand((unsigned)time(NULL));//on utilise le tps comme generateur de seed;
	int total=0;
	double moyenne,variance;
	int i;
	for (i = 0; i < 5; ++i)
    {
    int nombre_sortant=tirage()*20;
    printf("%d,",nombre_sortant);
    total+=nombre_sortant;
    }
    moyenne=total/i;
    variance
    return 0;
}
