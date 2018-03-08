#include <stdio.h>


// mettre ci-dessous le code de la fonction convert
char convert(int note){
	char noteChar;
		if ((note <= 20) && (note >= 16)) noteChar='A';
		else if ((note <= 15)&&(note >= 13)) noteChar='B';
		else if ((note <= 12)&&(note >= 10)) noteChar='C';
		else if ((note <= 9)&&(note >= 8)) noteChar='D';
		else if ((note <= 7)&&(note >= 6)) noteChar='E';
		else if ((note <= 5) && (note >= 0)) noteChar='F';
		else noteChar='X';
	return noteChar;}

// compléter ci-dessous le main

int main(){
	int note;
	printf("note ?\n");
	scanf("%d",&note);
	printf("la note de l'eleve: %c ",convert(note));

}
