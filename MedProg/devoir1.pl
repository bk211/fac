#!usr/bin/perl -w
printf("Entrez le rang Max de recherche\n");
printf("Attention, le nombre doit etre >1\n");
#Supposons qu'on a un utilisateur assez intelligent pour n'entrez que des entiers supérieur à 1
$RANG_MAX = <STDIN>;
chomp($RANG_MAX);
$RACINE_RANG_MAX = int(sqrt($RANG_MAX));
@Tableau_int = 2..$RANG_MAX;

#On affiche les nombres compris dans l'intervalle, c'est pas hyper utile mais bon
printf("Cherchons les nombres premiers dans interval [2,$RANG_MAX]\n");
foreach $Elem (@Tableau_int){
	printf("$Elem ");
}
printf("\n");

#Debut du tri
foreach $Elem (@Tableau_int){
	#parmi les element du tableau d'entier
	foreach $i (2..$RACINE_RANG_MAX){
		#on divise l'element par les nombre allant de 2 à racine de RANG_MAX
		if (!($Elem % $i) and ($i ne $Elem)){	
			$Elem = 0;
			#Si le modulo est nul, et que l'element n'est pas egale à $i 
			#(On doit garder l'element si il vaut $i)
			#sinon on le "supprime" en affectant 0 à l'element
		}
	}
}

printf("Voici les nombres premiers \n");
#seul les elements non nul, c'est à dire tous les nombres premiers après le tri precedent
#seront affichés.
foreach $Elem (@Tableau_int){
	if($Elem){
		printf("$Elem ");
	}
}
printf("\n")
