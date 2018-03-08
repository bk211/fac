#include <stdio.h>
int main(int argc, char const *argv[])
{	int N;
	printf("nombre entier N?=");
	scanf("%d",&N);
	for (int i = 1; i < N/2+1; ++i)
	{
		if(N%i==0)printf("%d,",i);
	}
	return 0;
}