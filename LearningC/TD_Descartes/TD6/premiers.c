#include <stdio.h>
int check_premier(int a){
	int check;
	for (int i=2;i<=a/2+1;i++) 
	{
		if(a %i==0) {check=0;break;}
		else check=1;}
	return (check);
	}
int main(int argc, char const *argv[])
{
	int borne_plus,borne_moins,j;
	printf("entrez les bornes sup et inf de recherche?\n");
	printf("bornes inf?");scanf("%d",&borne_moins);
	printf("bornes sup?");scanf("%d",&borne_plus);
	j=borne_moins;
	for (j;j<=borne_plus;j++)
		if(check_premier(j)){printf("%d;",j);}
}
