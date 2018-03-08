#include <stdio.h>
int main(){
	int a=1;int *p=&a;int b=*p;
	printf("1:a=%d, b=%d, *p=%d.\n",a,b,*p );
// a=1 b=1   p=1
	a*=3;
	printf("2:a=%d, b=%d, *p=%d.\n",a,b,*p );
// a=3 b=1 p=3
	b+=1;	
	printf("3:a=%d, b=%d, *p=%d.\n",a,b,*p );
// a=3 b=2 	p=3	
	int *q=&b;
	printf("4:a=%d, b=%d, *p=%d, *q=%d .\n",a,b,*p,*q );
//4 a=3 b=2 p=3 q=2
	*q *=(*p)++;



	printf("5:a=%d, b=%d, *p=%d, *q=%d .\n",a,b,*p,*q );
// 5 a=4 b=4 p=4 q=6 
//rappel *p=&a donc a++ et a=4
	*q *= ++(*p);   
	printf("6:a=%d, b=%d, *p=%d, *q=%d .\n",a,b,*p,*q );
// 6 a=5 b=30 p=5 q=30


	p=q; 		
	printf("7:a=%d, b=%d, *p=%d, *q=%d .\n",a,b,*p,*q );
// 7 a=5 b=30 p=30 q=30
	q=&a;
	printf("8:a=%d, b=%d, *p=%d, *q=%d .\n",a,b,*p,*q );
// 8 a=5 b=30 p=30 q=5

}