#include <stdio.h>
int	main(int argc, char const *argv[])
{	int nb_notes;
	printf("nombre de notes? ");scanf("%d",&nb_notes);
	float tableau[nb_notes];
	float somme=0;
	for (int i = 0; i < nb_notes; ++i)
	{
		float temp=-1;
		do{ scanf("%f",&temp);}while ((temp <= 0) && (temp > 20));
		tableau[i]=temp;
		somme += temp;
	}
	float moyenne = somme/nb_notes;
	printf("Moyenne:%f\n",moyenne);

	for (int i = 0; i < nb_notes; ++i)
	{
		printf("%f\n",tableau[i] );
	}
	return 0;
}