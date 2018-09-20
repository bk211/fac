#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a,b;
	printf("ax + b\n");
	printf("a?");
	scanf("%d",&a);
	printf("b?");
	scanf("%d",&b);
	if (a==0) printf("probleme a nul\n");
	else printf("x=%d\n",-b/a );
	return 0;
}