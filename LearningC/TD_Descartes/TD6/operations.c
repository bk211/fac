#include <stdio.h>
int resultat;
int addition(int a,int b){
	return resultat=a+b;
}
int soustraction(int a,int b){
	return resultat=a-b;
}
int multiplication(int a,int b){
	return resultat=a*b;
}
int division(int a,int b){
	return resultat=a/b;
}

int main(int argc, char const *argv[])
{
	char operation;
	int x=4,y=2;
	printf("operation?A S M D\n");
	//scanf("%c",&operation);
	operation='A';
	if(operation!='Q'){
	if (operation=='A')printf("resultat=%d\n",addition(x,y));
	else if (operation=='S')printf("resultat=%d\n",soustraction(x,y));
	else if (operation=='M')printf("resultat=%d\n",multiplication(x,y));
	else if (operation=='D')printf("resultat=%d\n",division(x,y));
	else if (operation=='Q')printf("fin de l'algo merci\n");}
	return 0;
}	

