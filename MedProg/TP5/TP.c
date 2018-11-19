// CAI Chaolei 17812776
#include <stdio.h>
#include <stdlib.h>

typedef struct QetR QetR;
struct QetR
{
	int Q,R;
};


QetR * division_euclidienne(int a, int b){
	int q =0;
	int r = a;
	while (r >= b)
	{
		r -= b;
		q ++;
	}

	QetR * resultat = malloc (sizeof(QetR*));
	resultat->Q = q;
	resultat->R = r;
	return resultat; 
}

int multiplication_egyptienne(int x, int y, int r){
//version recursive
/*
	if(!r) printf("%d * %d = ",x,y);
	else printf("%d * %d + %d =",x, y, r);
	if (y % 2){
		printf("%d * (%d-1) + %d + %d = %d * %d + %d\n",x, y, x, r, x, y-1, x, r+x);
		return multiplication_egyptienne(x, y-1, r+x);
	}
	else if(y){
		printf("(2 * %d) * (%d/2) + %d = %d * %d + %d\n", x, y, r,2*x, y/2,r);
		return multiplication_egyptienne(2*x,y/2,r);
	}
	printf("%d \n",x * y +r);
*/

//version iterative

	printf("%d * %d =\n",x,y );
	while(y)
	{

		if (y % 2)
		{
			printf("%d * (%d-1) + %d + %d = %d * %d + %d\n",x, y, x, r, x, y-1, x, r+x);
			y--;
			r+=x;
		}
		else if(y)
		{
			printf("(2 * %d) * (%d/2) + %d = %d * %d + %d\n", x, y, r,2*x, y/2,r);
			x *= 2;
			y /= 2;
		}
	}
	printf("=%d \n",x * y +r);

}

int main(int argc, char const *argv[])
{
	int a,b;
	printf("Fait la division euclienne de a par b\n"); 
	printf("entrez a: ");
	scanf("%d",&a);
	printf("entrez b: ");
	scanf("%d",&b);
	QetR* resultatEuclid = division_euclidienne(a,b);
	printf("%d = %d * %d + %d\n",a,b,resultatEuclid->Q,resultatEuclid->R );
	printf("q = %d, r = %d\n",resultatEuclid->Q,resultatEuclid->R );
	free(resultatEuclid);
	resultatEuclid = NULL;

	int x,y;
	printf("\nFait la multiplication egyptienne de x * y\n");
	printf("entrez x: ");
	scanf("%d",&x);
	printf("entrez y: ");
	scanf("%d",&y);
	multiplication_egyptienne(x,y,0);
	return 0;
}