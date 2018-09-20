#include <stdio.h>

int main(int argc, char const *argv[])

{
	int i,rows=4,space,k=0;


	for (i = 1; i <=rows; ++i,k=0)
	{
		for (space = 1; space<=rows-i; ++space)
		{
			printf("  ");
		}
		while(k!=2*i-1)
		{
			printf("* ");++k;
		}printf("\n");
	}
	for (int i = rows; i>1; --i)
	{
		for (space =1;space<=rows-i; ++space)
		{
			printf("XX");
		}
		


		printf("\n");
	}



	return 0;
}
