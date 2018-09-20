#include <stdio.h>
int factorielle(int x);

int main(){
	int MAXINT,resultat;
	printf("MAXINT?");("%d",&MAXINT);
	for (int i = 0; i <MAXINT; ++i)
	{
		printf("factorielle(%d)=%d\n",i,factorielle(i));
	}
}

int factorielle(int x){
	int resultat=1;
	for (int i = 1; i <=x; ++i)
	{
		resultat*=i;
	}return resultat;
}