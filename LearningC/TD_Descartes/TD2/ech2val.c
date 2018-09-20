#include <stdio.h>
int main(){
	int a,b,c;
	printf("a?");
	scanf("%d",&a);
	printf("b?");
	scanf("%d",&b);
	printf("avant echange:a=%d,b=%d\n",a,b );
	//c=a;a=b;b=c;
	a=a+b;b=a-b,a=a-b;
	printf("apres echange:a=%d,b=%d\n",a,b );

}