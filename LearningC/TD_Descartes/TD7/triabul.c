#include <stdio.h>
int echange(int *a,int *b);

int main(int argc, char const *argv[])
{
	int tab[10],tab_ordered[10];
	//get tab
	for (int i = 0; i <10; ++i)
	{
		printf("tab[%d]",i);
		scanf("%d",&tab[i]);
	}
 int max;
 	 	max=tab[0];
 		for (int j = 0; j <10; ++j)
 		{
 			for (int k = j; k <10; ++k)
 			{
 				if(tab[j]<tab[k]) echange(&tab[j],&tab[k]);
 			}
 		}

 
 	for (int l = 0; l < 10; ++l)
 	{
 		printf("tab_ordered[%d]=%d\n",l,tab[l]);
 	}



}
int echange(int *a,int *b){
	return *a^=*b^=*a^=*b;
}


for ...
	ii = random.randint(0,n)
	printf(ii);
	somme += ii