#!usr/bin/perl -w
$NB_SECRET = int(rand 10);

printf("le nombre est compris entre 0 et 9");
printf("\n$NB_SECRET\,");
for (my $i=1;$i<=2; $i++){
	printf("devinez,ceci est votre $i tentative\n");
	$ENTREE = <STDIN>;
	chomp $ENTREE;

	if($ENTREE eq $NB_SECRET){
		printf("correct,le nombre secret est $NB_SECRET\n");
		printf("victoire, fin de jeu\n");	
		exit(0);
	}
}
printf("dommage,le nombre secret est $NB_SECRET");
