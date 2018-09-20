#include <stdio.h>
#include <math.h>
int romain_(int x);
int main(int argc, char const *argv[])
{int racine_2=2;//on se limite ici au puissance de 2 inferieur a 5000
	while (racine_2<5000){
		romain_(racine_2);
		racine_2*=2;
	}
	return 0;
}

int romain_(int y){
	// inf a 5000, donc switch statement pr les milliers sont inutiles
	int x=y;
	printf("resultat de la conversion %d>>\n",x);
	int milles,cents,diz,unit;
	milles=x/1000;
	for (int i = 0; i < milles; ++i)
	{
		printf("M");
	}
	cents=x%1000/100;
	switch(cents){
	case 0:;break;
	case 1:printf("C");break;
	case 2:printf("CC");break;
	case 3:printf("CCC");break;
	case 4:printf("CD");break;
	case 5:printf("D");break;
	case 6:printf("DC");break;
	case 7:printf("DCC");break;
	case 8:printf("DCCC");break;
	case 9:printf("CM");break;}	
	diz=(x%100/10);
	switch(diz){
	case 0:;break;
	case 1:printf("X");break;
	case 2:printf("XX");break;
	case 3:printf("XXX");break;
	case 4:printf("XL");break;
	case 5:printf("L");break;
	case 6:printf("LX");break;
	case 7:printf("LXX");break;
	case 8:printf("LXXX");break;
	case 9:printf("XC");break;}
	unit=x%10;	
	switch(unit){
	case 0:;break;
	case 1:printf("I");break;
	case 2:printf("II");break;
	case 3:printf("III");break;
	case 4:printf("IV");break;
	case 5:printf("V");break;
	case 6:printf("VI");break;
	case 7:printf("VII");break;
	case 8:printf("VIII");break;
	case 9:printf("IX");break;}	
	printf("\n");
	
}