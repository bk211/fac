#!/usr/bin/perl 


$entier=2;
$octal=011;
$hexa=0x1F;
$decim=4.5;

$notyp=12;

#Afficher suivant la base d'affectation
printf("entier=%d octal=%o hexa=%x decim=%f \n\n",$entier,$octal,$hexa,$decim);

#Afficher en base 10, sauf le $decim
printf("entier=%d octal=%d hexa=%d decim=%f \n\n",$entier,$octal,$hexa,$decim);

#Afficher "notype" dans les bases 10, 8, 16, decimale
printf("notyp (10)=%d (8)=%o (16)=%x (.E10)=%f \n\n",$notyp,$notyp,$notyp,$notyp);

# voir la différence entre "print" et "printf"

print "entier=$entier,octal=$octal,hexa=$hexa,decim=$decim\n\n";

