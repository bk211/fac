#include <stdio.h>
void echange1(int*a,int*b){
	*a+=*b;*b=*a-*b;*a-=*b;

}

void echange2(int*a,int*b)
{
	*a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
//    *a^=*b^=*a^=*b;
}
int	main(int argc, char const *argv[])
{
	int a,b;
	a=1,b=2;
	printf("valeurs avant l'echange a=%d,b=%d\n",a,b );
	echange1(&a,&b);
	printf("valeurs apres l'echange1 a=%d,b=%d\n",a,b );
	echange2(&a,&b);
	printf("valeurs apres l'echange2 a=%d,b=%d\n",a,b );
	return 0;
}