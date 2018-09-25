#include <stdio.h>
int main()
{	int u,valeur_u;
	printf("U(0)=?\n");
	scanf("%d",&valeur_u);
	printf("U(0)=%d\n",valeur_u);

	for (u = 0;; u++) 
	{
		if (valeur_u==1)
		{printf("Boucle infinie 4-2-1-4 fin de programme");break;}

		else if(valeur_u%2){
			valeur_u=valeur_u*3+1;
			printf("U(%d)=3*U(%d)+1=%d\n",u+1,u,valeur_u);}
		else
			valeur_u=valeur_u/2;
			printf("U(%d)=U(%d)/2=%d\n",u+1,u,valeur_u);};
		
	}
