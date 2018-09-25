#include <stdio.h>
int main(int argc, char const *argv[])
{int j=0;
	for (int i = 0; i <=255; ++i)
{	
	printf("%c ",i);
	j++;
	if (j==32)printf("\n");
}
	return 0;
}