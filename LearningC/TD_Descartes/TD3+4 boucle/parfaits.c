#include <stdio.h>
#include <math.h>
int check_parfait(int a){
	int somme=0;
	
	for (int i=1;i<a/2+1;i++) {if (a%i==0) somme+=i;}
	if (somme==a) return(1);
	else return(0);
}
int main(int argc, char const *argv[])
{
	int borne_plus,borne_moins,j;
	printf("entrez les bornes sup et inf de recherche?\n");
	printf("bornes inf?\n");scanf("%d",&borne_moins);
	printf("bornes sup?\n");scanf("%d",&borne_plus);
	j=borne_moins;
	for(j;j<=borne_plus;j++) {
		if(check_parfait(j)) printf("%d;",j);}
	
	return 0;
}
