#include <stdio.h>
int unite(int a){
	int unite=a%10;
	printf("chiffre des unites=%d\n", unite);
	return 0;
}

int dizaine(int a){
int dizaine;
if(a>=10){
	dizaine=a%100;}
else dizaine=0;
	printf("chiffre des dizaine=%d\n", dizaine);
	return 0;
}
int main(int argc, char const *argv[])
{	int nombre;
	printf("nombre?\n");scanf("%d",&nombre);
	unite(nombre);dizaine(nombre);
	return 0;
}