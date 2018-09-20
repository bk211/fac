#include <stdlib.h>  
#include <stdio.h>  
#include <time.h>           
int t;
double tirage()
{rand();
    return (double)rand()/(RAND_MAX+1);
}

int	main(int argc, char const *argv[])
{
	srand((unsigned)time(NULL));
int t,nb_secret,guess=-1;
	printf("maximum t=?");
	scanf("%d",&t);

	printf("le nombre a deviner est compris entre 0 et %d inclus\n",t++);
//t++ permet d'inclure le maximum lors du psg double>int
	nb_secret=tirage()*t;
	while(nb_secret!=guess){
		printf("your guess?");
		scanf("%d",&guess);
		if(nb_secret>guess) printf("trop petit\n");
		else if(nb_secret<guess) printf("trop grand\n");
	}
	printf("felicitation\n");
	printf("le nombre secret est bien %d\n",nb_secret);
	
	return 0;
}