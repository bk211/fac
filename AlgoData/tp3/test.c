#include "stdio.h"

int main(int argc, char const *argv[])
{
	int ab = 123;
	int ** abc = ab;
  	printf("%p\n",abc );
  	//printf("%p\n",*abc );
	return 0;
}