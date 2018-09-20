#include <stdio.h>
int main(int argc, char const *argv[])
{
	unsigned int jour,mois,annee;
	printf("entrez la date sous format jour mois annee separes d'une espace\n");
	scanf("%u %u %u",&jour,&mois,&annee);
	if (jour<0 || jour>31){printf("erreur jourinvalide\n");}
	else if (mois<0 || mois >12){printf("erreur mois invalide\n");}
	else if (annee<0) {printf("erreur annee invalide\n");}
	else {
		printf("%u/%u/%u date valide\n",jour,mois,annee );
		jour++;
		if (jour>31){jour=1,mois++;};
		if (mois>12){mois=1,annee++;};
		printf("le jour suivant est le %u/%u/%u \n",jour,mois,annee );	


}
	return 0;
}