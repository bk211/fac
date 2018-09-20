#include <stdio.h>
int echange(int *a,int *b);

int main(int argc, char const *argv[])
{
	
	int tab[10],answer,count=0,somme=0;
	double moyenne;
	//get tab
	for (int i = 0; i <4; ++i)
	{	count++;
		printf("tab[%d]",i);
		scanf("%d",&tab[i]);
		printf("continuer? (1/0)");
		scanf("%d",&answer);
		//on suppose que utilisateur entre 1 pour 'oui' 0 pour 'non' et rien d'autre
		if(!answer) break;
	}printf("count =%d\n",count );
	for (int i=0; i < count; ++i)
	{
		printf("tab[%d]=%d,\n",i,tab[i]);
		somme+=tab[i];
	}
	moyenne=somme/count;
	printf("moyenne de %d valeurs=%.2f\n",count,moyenne);

}