#include "stdio.h"
#include "math.h"

long double puissance(int x, int n){	
	if(n < 0)
		return (1.0/puissance(x, (-1) * n));
	
	else if(!n)
		return 1;
	
	else if(n == 2)
		return x * x;

	else if(!(n % 2))
		return pow(puissance(x, n/2),2);
	
	else
		return pow(puissance(x, (n-1)/2), 2) * x;
	

}

int main()
{	
	int a,b;
	printf("Ce programme calcul la puissance n de x separe d'espace\nx n?:"); 
	scanf("%d %d",&a,&b);
	printf("%Lf\n",puissance(a,b) );
	return 0;
}
