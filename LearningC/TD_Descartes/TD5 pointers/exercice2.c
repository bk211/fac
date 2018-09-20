#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a=2;int*p=&a;int b=*p;
	printf("1:a=%d, b=%d, *p=%d.\n",a,b,*p );	
// 1 a=2		b=2		p=2	
	a*=5;
	printf("2:a=%d, b=%d, *p=%d.\n",a,b,*p );
// 2 a=10	b=2		p=10
	b+=1;
	printf("3:a=%d, b=%d, *p=%d.\n",a,b,*p );
// 3 a=10	b=3		p=10
	int*q =&b;
	printf("4:a=%d, b=%d, *p=%d, *q=%d .\n",a,b,*p,*q );
// 4 a=10	b=3		p=10	q=3
	p=q;	
	printf("5:a=%d, b=%d, *p=%d, *q=%d .\n",a,b,*p,*q );
//	5 a=10	b=3		p=3		q=3	
	q=&a;
	printf("6:a=%d, b=%d, *p=%d, *q=%d .\n",a,b,*p,*q );
//  6 a=10	b=3		p=3		q=10
	(*q)++;	
	printf("7:a=%d, b=%d, *p=%d, *q=%d .\n",a,b,*p,*q );
//  7 a=11	b=3		p=3		q=11	
	
	printf("8:a=%d, b=%d, *p=%d, *q=%d .\n",a,b,*p,*q );
//  8 a=11	b=3		p=3	q=null

}