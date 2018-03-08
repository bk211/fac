#include <stdio.h>
int main(int argc, char const *argv[])
{
	int sucre,sale,chaud,cher,s;
	printf("sale  (1/0) ?");
	scanf("%d",&sale);
	printf("sucre (1/0) ?");
	scanf("%d",&sucre);	
	printf("chaud (1/0) ?");
	scanf("%d",&chaud);
	printf("cher  (1/0) ?");
	scanf("%d",&cher);
	printf("%d %d %d %d \n", sale,sucre,chaud,cher);
if (sucre&&!sale&&!chaud&&!cher) printf(":-D\n");
else if(sale && !sucre && chaud) printf(":-)\n");
else if(!sale && !sucre &&!chaud)printf(":-/\n");
else if(sucre && sale && !chaud)printf(":-(\n");
else {printf(":-| check\n");}	
	return 0;
}