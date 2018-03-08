#include <stdio.h>
#include <stdlib.h>
int order;
int _do_while()
{
	printf("0:quitter\nautre:continuer\n");
	while(order!=0);
	printf("order =0 fin du prog avec do while\n");
}

int main(int argc, char const *argv[])
{
	_do_while();
	return 0;
}