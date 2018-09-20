#include <stdio.h>
int main(int argc, char const *argv[])
{
	int tab[5];
	//get tab
	for (int i = 0; i < 5; ++i)
	{
		printf("tab[%d]",i);
		scanf("%d",&tab[i]);
	}
	int max,min;
	max=min=tab[0];
	for (int i = 0; i < 5; ++i)
	{
		max=(tab[i]>max)? tab[i]:max;
		min=(tab[i]<max)? tab[i]:min;

	}
	printf("max=%d\n min=%d\n",max,min);
	return 0;
}