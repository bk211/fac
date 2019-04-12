/* ------------------------------------------------------------
   		AlgoSdec : 		Jeu de pendu

		F. Balmas		Fevrier 2001
   ------------------------------------------------------------
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *table_mots[]= { "calculer", "cartable", "pelochon", "classeur" };

int main()
{
char mot[9], trouve[9];
int pos;
char lettre;  
int nbt; 
int bonl;

  srand(getpid());
  for ( ; ; )
  {     
	strcpy (mot, table_mots[( rand() % (sizeof(table_mots)/sizeof(char *))) ]);
	strcpy (trouve, "--------"); 
	printf ("Mot a trouver de %d lettres\n", strlen(mot));
        nbt = 8;

	while (nbt != 0)
	{
	   printf ("\nProposez une lettre : ");
	   scanf ("%c", &lettre); getchar();
	   bonl = 0;
 	   for (pos=0 ; pos <= 7 ; pos++)
	   {
		if (mot[pos] == lettre)
		{
		   bonl = 1; 
		   trouve[pos] = lettre;
		}
	   }      
	   if (bonl == 1)
	   {
		printf("%s\n", trouve);
	   }
	   else
	   {
		printf ("Cette lettre ne fait pas partie du mot a trouver\n");
	   }

	   nbt=0;
	   for (pos=0 ; pos <=7 ; pos++)
	   {
		if (trouve[pos] == '-')
		{
		   nbt++;
		}  
	   }
	}
	printf ("Bravo, vous avez trouve\n"); 
  }
}
