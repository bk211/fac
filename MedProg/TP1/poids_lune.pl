#!usr/bin/perl -w
printf("Calcule de votre poids sur la lune\n");
printf("unité utilisé ici est le kilogramme\n");
printf("par souci de lecture, la précision est de 10^-3\n");
printf("entrez votre taille :");
$POIDS= <STDIN>;
chomp($POIDS);

while ($POIDS <= 0){
	printf("veuillez entrez un nombre positif : ");
	$POIDS = <STDIN>;
	chomp($POIDS);
}

$POIDS_LUNE = $POIDS/6;
printf("vous pèsez %.3f kg sur la lune\n",$POIDS_LUNE); 