#include <stdio.h>
int main(int argc, char const *argv[])
{
	int nac,punitaireht;
	float ptotalht,ptotalttc,pfinal;
	printf("rentrez le nombre d'article commandes >");
	scanf("%d",&nac);
	printf("nac = %d",nac);
	printf("rentrez le prix unitaire ht >");
	scanf("%d",&punitaireht);
	ptotalht=nac*punitaireht;
	printf("ptotalht=%.2f\n",ptotalht);
	ptotalttc=ptotalht+ptotalht*0.2;
	printf("ptotalttc=%.2f\n",ptotalht);
	if (ptotalttc>1000) printf("le prix total ttc depasse 1000\n");
	else printf("le prix total ttc ne depasse pas 1000\n");
	/* cas 1 
	printf("pfinal=%.2f\n",ptotalttc ); */

	// cas 2
	pfinal=ptotalttc-ptotalttc*0.05;
	printf("pfinal =%.2f\n",pfinal);


	return 0;
}