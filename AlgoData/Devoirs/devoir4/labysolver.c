/*
* NOM : CHAOLEI
* NUMERO : 17812776
* EMAIL : CHAOLEICAI@GMAIL.COM
*/

#include <stdlib.h>
#include <stdio.h>

static int xd, yd, xf, yf,w = 0,h = 0;

static int * labyParse(void) {
	char buf[1024], * s;
	int *labyrinthe = NULL,x, y;
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
			else if(*s == 'D'){
				//depart}
				xd = x;
				yd = y;	
				labyrinthe[x + y*w]= 0;
			}
			else if(*s == 'A'){
				//arrive
				xf = x;
				yf = y;	
				labyrinthe[x + y*w]= 0;
			}
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


void pcc(int* laby, int w,int x, int y, int xf,int yf,int v){
	v++;
	laby[x + y*w] = v;
	if(x == xf && y == yf)
		return;

	int i, dir[][2] ={ {1,0}, {0,1}, {-1,0},{0,-1}};

	
	for (i = 0; i < 4; ++i)
	{
		if ((v < laby[x+dir[i][0] + (y+dir[i][1])*w]) || (laby[x+dir[i][0] + (y+dir[i][1])*w] ==0))
			pcc(laby, w, x+dir[i][0], y+dir[i][1], xf, yf, v);
	}

}

void affiche_chemin(int *laby, int w, int x, int y){	
	int i, dir[][2] ={ {1,0}, {0,1}, {-1,0},{0,-1}};
/*	if(laby[x + y*w] == 1)
		return;
*/
	for (i = 0; i < 4; ++i)
	{
		if(laby[x + y*w] == laby[x+dir[i][0] + (y+dir[i][1])*w] +1){
			affiche_chemin(laby, w, x+dir[i][0], y+dir[i][1]);
			break;
		}

	}
	printf("(%d,%d)\n",x,y);

}



int main(int argc, char const *argv[])
{
	int * temp = labyParse();
	pcc(temp,w,xd,yd,xf,yf,0);
	affiche_chemin(temp,w,xf,yf);
	free(temp);
	return 0;
}