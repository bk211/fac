#include <stdio.h>
#include <stdlib.h>
int order;
int _while()
{
	order=1;
	while(order!=0) {
		printf("0:quitter\nautre:continuer\n");
		scanf("%d",&order);}
	printf("order =0 fin du prog while\n");
}
int _do_while()
{
	do{
		printf("0:quitter\nautre:continuer\n");
		scanf("%d",&order);}
	while(order!=0);
	printf("order =0 fin du prog avec do while\n");
}
int _for()
{	order=1;
	for(int i;order!=0;i++){
		printf("0:quitter\nautre:continuer\n");
		scanf("%d",&order);}
	printf("order =0 fin du prog avec for\n");
}



int main(int argc, char const *argv[])
{
	_do_while();
	_while();
	_for();
	return 0;
}