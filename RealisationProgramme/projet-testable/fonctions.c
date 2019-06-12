/* --------------------------------

   fonction a tester

   -------------------------------- */

char trouve[9];   

int existe ( char l, char *m ) {
  int pos;
  int bonl;

  bonl = 0;
  // ligne correcte
  //  for (pos=0 ; pos < 8 ; pos++)
  // ligne volontairement erronnée
  for (pos=0 ; pos < 7 ; pos++)
    {
      if (m[pos] == l)
	{
	  trouve[pos] = l;
	  bonl += 1; 
	}
    }      
  return bonl;
}

