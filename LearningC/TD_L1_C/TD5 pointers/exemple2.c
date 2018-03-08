#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a=1,b=2;
	int*p=&a;
	int*q=p;
	printf("a=%d, b=%d, *p=%d *q=%d\n",a,b,*p,*q );
	a=3;
	printf("a=%d, b=%d, *p=%d *q=%d\n",a,b,*p,*q );
	b=*q+10;
	printf("a=%d, b=%d, *p=%d *q=%d\n",a,b,*p );


/*1 2 1 1
3 2 3 3
3 13 3 3*/

}