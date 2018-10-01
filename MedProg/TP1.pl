#!usr/bin/perl -w
printf("donnez votre nom ");
$NOM = <STDIN>;
chomp $NOM;
$msg1 = "welcome '$NOM' to Perl's world\n";
$msg2 = ("pas le bon user '$NOM' !\n");
$msg3 = "au revoir\n";
if($NOM eq "larry"){
	printf($msg1);
	exit 0;
		}
else {
	printf($msg2);
	}
for (my $i=0; $i < 3; $i++) {
	printf("donnez votre nom ");
	$NOM = <STDIN>;
	chomp $NOM;
	if($NOM eq "larry"){
		printf($msg1);
		exit 0;
		}
	else {
		printf($msg2);
	}
};
printf($msg3);