/* ------------------------------------------------------------
   		AlgoSdec : 		Jeu de pendu

		F. Balmas		Fevrier 2001
   ------------------------------------------------------------
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int existe (char, char *);

char *table_mots[]= { "calculer", "cartable", "pelochon", "classeur" };
extern char trouve[9];

int main(void)
{
  char mot[9]; 
int pos;
char lettre;  
int nbt; 

  srand(getpid());
  for ( ; ; )
  {     
	strcpy (mot, table_mots[( rand() % (sizeof(table_mots)/sizeof(char *))) ]);
	strcpy (trouve, "--------"); 
	printf ("Mot a trouver de 8 lettres : %s\n", trouve);

        nbt = 8;
	while (nbt != 0)
	{
	   printf ("\nProposez une lettre : ");
	   scanf ("%c", &lettre); getchar();

	   if (existe(lettre, mot) >= 1)
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


