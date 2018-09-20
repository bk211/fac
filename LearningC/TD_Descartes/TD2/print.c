#include <stdio.h>
int main(){
	int a,b,c,d;
	a=-4-3*2-1; 
	//a= -11
	b=1+3*8%3;
	//b= 1
	int n=20;
	c=n++;
	//c=20 n=21
	int m=20;
	d=++m;
	// d=21 m=21
	printf("%d %d %d %d %d %d",a,b,c,n,d,m );
}