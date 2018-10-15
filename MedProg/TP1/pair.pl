#!usr/bin/perl -w
printf("Ce programme affiche si un nombre donné est pair ou impair\n");
printf("entrez votre nombre :");
$NB= <STDIN>;
chomp($NB);
if(!($NB % 2)){
	printf("Le nombre $NB est pair\n");
	exit(0);
}
printf("Le nombre $NB est impair\n");