#!/usr/bin/perl -w
use strict;
print("Le programme suivants vous calcule la mediane, la moyenne et ecart type d'une suite de nombre");
print("merci de séparer vous nombres par un ', '\n");
print("exemple :1, 2, 3\n");
print("la virgule plus espace est obligatoire pour le scan.\n");

my $entre = <STDIN>;
chomp $entre;
#l'entree est d'abord recupere comme une chaine de charactere
my @liste = (split /, /,$entre);
#puis on genere une liste de nombre en splitant la chaine entre via le separateur ", "
@liste = sort {$a <=> $b}@liste;
#les nombres sont alors classés dans l'ordre croissant

print("vous avez entrez les nombres suivants:\n");
print "$_, " for @liste;
my $longeur = scalar @liste;
#pour facilité la suite des calcul, on récupère aussi la taille de la liste
print("\nlongeur de la liste : $longeur\n");

sub mediane {
	my($longeur,@liste) =@_;
	my $mediane = 0;
	if($longeur % 2){
		#si la liste est impair la médiane correspond à l'element au milieux 
		$mediane = ($liste[($longeur-1)/2]);
	}
	else{
		#sinon la liste est pair la médiane correspond à la moyenne des nombres sus et sous-jacent 
		$mediane = ($liste[$longeur / 2 - 1] + $liste[$longeur / 2] ) / 2;	
	}
	return $mediane;
}

sub moyenne {
	my ($longeur,@liste) = @_;
	my $somme = 0;
	foreach my $elem (@liste){
		$somme += $elem;
	}
	
	my $moyenne = $somme / $longeur;
	return $moyenne;
}

sub ecart_type {
	my($moyenne,$longeur,@liste) =@_;
	my $somme_carre = 0;
	foreach my $elem (@liste) {
		$somme_carre += ($elem -$moyenne) * ($elem - $moyenne); 
	}
	my $ecart_type = ($somme_carre) / $longeur;
	return $ecart_type;
}

my $mediane = mediane($longeur,@liste);
my $moyenne = moyenne($longeur,@liste);
my $ecart_type = ecart_type($moyenne, $longeur, @liste);

printf("mediane :%f\n",$mediane);
printf("moyenne :%f\n",$moyenne);
printf("ecart type :%f\n",$ecart_type);

