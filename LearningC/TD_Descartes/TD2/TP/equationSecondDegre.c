#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
	int a,b,c,det;
	printf("ax^2 + bx + c\n");
	printf("a?");
	scanf("%d",&a);
	printf("b?");
	scanf("%d",&b);
	printf("c?");
	scanf("%d",&c);
	if (a==0) {printf("probleme a nul\n");}
	else {det=b*b-4*a*c;
		if (det<0) {printf("equation n'a pas de racine dans R\n");}
		else if (det==0) printf("racine unique x0=%d\n",-b/(2*a) );
		else {printf("deux racine possible\n");
		printf("x1=%.2f\n",(-b+sqrt(det))/(2*a));		
		printf("x2=%.2f\n",(-b-sqrt(det))/(2*a));}
}
	return 0;
}
