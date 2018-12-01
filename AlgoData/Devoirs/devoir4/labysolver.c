#include <stdlib.h>
#include <stdio.h>

static int * labyParse(void) {
	char buf[1024], * s;
	int *labyrinthe = NULL, w = 0, h = 0, x, y;
	if(fscanf(stdin, "%d\n", &w) != 1 || fscanf(stdin, "%d\n", &h) != 1)
		return NULL;
	/* ... */
	y = 0;
	/* allouer la m´emoire */
	labyrinthe = malloc(sizeof labyrinthe * w * h);

	while(fgets(buf, sizeof buf, stdin)) {//line entiere lue depuis stdin stoké dans buf 
		x = 0;
		for(s = buf, x = 0; *s && *s != '\n'; s++, x++) {
		/* remplir labyrinthe et fixer le point de d´epart et le point d’arriv´ee */
			//printf("%c\n",*s );
			if(*s == '*') //mur 
				labyrinthe[x + y*w]= -1;
			else if(*s == ' ')//ouvert
				labyrinthe[x + y*w]= 0;
			else if(*s == 'D')//depart
				labyrinthe[x + y*w]= -2;
			else if(*s == 'A')//arrive
				labyrinthe[x + y*w]= -3;
		}
		y++;
	}
	return labyrinthe;
}

void printlaby(int * t, int w, int h){
	int i;
	for(i = 0;i < w*h;++i){
		if(i%w ==0 ) printf("\n");
		printf("%d, ",t[i]);
	}
}
//echo "4\n4\n****\n*A *\n* D*\n****" | ./labysolver 


int main(int argc, char const *argv[])
{
	int * temp = labyParse();
	printlaby(temp,4,4);
	free(temp);
	return 0;
}