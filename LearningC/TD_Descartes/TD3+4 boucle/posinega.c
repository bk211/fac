#include <stdio.h>
int main(int argc, char const *argv[])
{int N,temp,negatif=0,positif=0;
	printf("nombre N?");scanf("%d",&N);
	for (int i = 1; i <=N ; ++i)
	{	
		printf("%d eme nombre?",i);
		scanf("%d",&temp);
		printf("vous avez tapes %d\n",temp);
		if(temp>=0) positif++;
		else negatif++;
	}
	printf("il y a %d nombre positif 0 inclus\n",positif);
	printf("il y a %d nombre negatif\n",negatif);
	return 0;
}