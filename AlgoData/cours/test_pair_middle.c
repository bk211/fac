#include <stdio.h>

int main(int argc, char const *argv[])
{
	
	int a = 10;
	int b = 999;
	printf("%d %d %d\n",a, a>>1, a & 1);
	printf("%d %d %d \n",b, b>>1, b&1 );
	return 0;
}