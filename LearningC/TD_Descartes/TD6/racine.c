#include <stdio.h>
#include <math.h>
int check_racine(int a,int b,int c,int *nb_racine,float *x1,float*x2)
{
	int det;
	if(a==0) {nb_racine=0;return 0;}
	else {det=b*b-4*a*c;
		if (det<0) {*nb_racine=0;return 0;}
		else if (det==0) {*nb_racine=1,*x1=-b/(2*a); return 1;}
		else{*nb_racine=2;
		*x1=(-b+sqrt(det))/(2*a);		
		*x2=(-b-sqrt(det))/(2*a);
		return 1;}
	}	
}

int main(int argc, char const *argv[])
{
int a,b,c,nb_racine;
float x1,x2;
	printf("ax^2 + bx + c\n");
	printf("a?");scanf("%d",&a);
	printf("b?");scanf("%d",&b);
	printf("c?");scanf("%d",&c);
check_racine(a,b,c,&nb_racine,&x1,&x2);
	if(nb_racine>1) printf("deux racine x1=%.2f,x=%.2f\n",x1,x2 );
	else if (nb_racine) printf("une seule racine x=%.2f",x1);
	else printf("pas de racine :(\n");
	
}