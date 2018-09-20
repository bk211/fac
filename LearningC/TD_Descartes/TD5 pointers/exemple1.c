#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a =1; int*p=&a;int b=*p;
	printf("a=%d, b=%d, *p=%d \n",a,b,*p );
	a=2;
	printf("a=%d, b=%d, *p=%d \n",a,b,*p );
	b=3;
	printf("a=%d, b=%d, *p=%d \n",a,b,*p );
	p=&b;
	printf("a=%d, b=%d, *p=%d \n",a,b,*p );
	a=4;
	printf("a=%d, b=%d, *p=%d \n",a,b,*p );
	b=5;
	printf("a=%d, b=%d, *p=%d \n",a,b,*p );
	return 0;
}

/*
a=1		b=1		*p=1
a=2		b=1		*p=2
a=2		b=3		*p=2
a=2		b=3		*p=3
a=4		b=3		*p=3
a=4     b=5     *p=5
*/