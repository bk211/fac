#include <stdio.h>
int i,j,ligne;    

void _while()
{
	printf("entier positif?\n");
	scanf("%d",&ligne);
	i=1;
	while(i<=ligne)
	{
		j=1;
		while(j<i) {printf("*");j++;}
		printf("hello\n");i++;
	}
}
int do_while(){
	printf("entier positif?\n");scanf("%d",&ligne);
	i=1;
	do{
		do{
			printf("*");j++;
		}while(j<i);
		j=0;
		printf("hello\n");i++;
	}while(i<=ligne);
}

int _for(){
	printf("entier positif?\n");//scanf("%d",&ligne);
	ligne=4;
	for (int i = 0; i < ligne; ++i)
	{for (int j = 0; j <i ; ++j)
	{
		printf("*");
	}
		printf("hello\n");
	}



}
int main()
{
	_for();
return 0;
}