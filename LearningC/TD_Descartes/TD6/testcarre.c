#include <stdio.h>
#include <math.h>
int carre(int n){
	if (sqrt(n)==(int)sqrt(n)) printf("%d carre\n", n);
	else printf("%d pas carre.\n",n );
}
int main(int argc, char const *argv[])
{
	int x;
	printf("x?");scanf("%d",&x);
	carre(x);
	return 0;
}