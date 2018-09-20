#include <stdio.h>
int main(int argc, char const *argv[])
{int N,temp,somme=0;
	printf("nombre N?");scanf("%d",&N);
	for (int i = 1; i <=N ; ++i)
	{	
		printf("%d eme nombre?",i);
		scanf("%d",&temp);
		printf("vous avez tapes %d\n",temp);
		somme+=temp;
	}printf("somme de %d nombre=%d\n",N,somme );
	return 0;
}