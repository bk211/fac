#include <stdio.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
	int x,y;
	char order;
	printf("coordonnee du point?\n");
	scanf("%d%d",&x,&y);
	fflush(stdin);
	printf("order?\n");
	scanf("%c",&order);
	printf("coordonnee:x=%d,y=%d\n",x,y);
	switch((order)){
	case 'H':
	case ('h'):y++;break;
	case 'B':
	case ('b'):y--;break;
	case 'G':
	case ('g'):x--;break;
	case 'D':
	case ('d'):x++;break;
	default:printf("erreur order\n");
	}
	printf("coordonnee:x=%d,y=%d\n",x,y);
	return 0;
}