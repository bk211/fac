#!usr/bin/perl -w
printf("Calcule de la surface d'une piece de longeur X, largeur Y\n");
printf("unité utilisé ici est le mètre\n");
printf("entrez la longeur X :");
$X = <STDIN>; 
chomp($X);

#Si vous voulez pas de surface nul,
#while ($X <= 0)
while ($X < 0){
	printf("veuillez entrez un nombre positif : ");
	$X = <STDIN>;
	chomp($X);
}

print("entrez la largeur Y :");
$Y = <STDIN>;
chomp($Y);

#while ($Y <= 0)
while ($Y < 0){
	printf("veuillez entrez un nombre positif : ");
	$Y = <STDIN>;
	chomp($Y);
}

$surface = $X * $Y;
printf("la piece de dimension X,Y a une surface de : $surface m^2\n")
