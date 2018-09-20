#include <stdio.h>
int main(int argc, char const *argv[])

|avec if
{
	int a,b,c,grand,moyen,petit;
	a=1,b=2,c=3;
	if (a>b && a>c){
		grand=a;
		if (b>c) moyen=b, petit=c;
		else moyen=c,petit=b;}
	if (b>c && b>a) {grand=b;
		if (a>c) moyen=a,petit=c;
		else moyen=c,petit=a;}
	if (c>a && c>b) {grand=c;
		if (a>b) moyen=a,petit=b;
		else moyen=b,petit=a;}
	printf("grand=%d, moyen=%d, petit=%d\n",grand,moyen,petit );		
	return 0;
}