#!/usr/bin/perl -w
use strict;

sub puissance{
	my($x,$n) = @_;
	return $x ** $n;
}

print("ce programme calcule la puissance N d'un nombre x\n");
print("merci d'entrez votre nombre X :");
my $x = <STDIN>;
chomp $x;
print("\nmerci d'entrez la puissance N :");
my $n = <STDIN>;
chomp $n;

my $puissance_X_N = puissance($x,$n);
print("la puissance $n du nombre $x vaut :$puissance_X_N");