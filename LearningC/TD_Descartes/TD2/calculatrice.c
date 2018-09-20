#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a,b;char op;
	printf("premiere valeur?");
	scanf("%d",&a);
	fflush(stdin);
	printf("operation?");
	scanf("%c",&op);
	printf("seconde valeur?");
	scanf("%d",&b);
	switch(op){
	case '+':printf("%d%c%d=%d\n",a,op,b,a+b );break;
	case '-':printf("%d%c%d=%d\n",a,op,b,a-b );break;
	case '*':printf("%d%c%d=%d\n",a,op,b,a*b );break;
	case '/':printf("%d%c%d=%d\n",a,op,b,a/b );break;
	default:printf("operation non reconnue\n");}
return 0;
}