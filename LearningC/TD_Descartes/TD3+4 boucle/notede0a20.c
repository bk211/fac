#include <stdio.h>
int note;
void _while(){
	note=21;
	while(note>20 || note<0){
	printf("quelle est votre note?\n");
	scanf("%d",&note);
}
printf("felicitation,0<=note<=20\n");

}
void _do_while(){
	do{
		printf("quelle est votre note?");
		scanf("%d",&note);
	}while(note<0 ||note>20);
printf("felicitation,0<=note<=20\n");

}
void _for(){
	note=21;
	for (;note<0||note>20;)
	{printf("quelle est votre note?");
		scanf("%d",&note);
	}
printf("felicitation,0<=note<=20\n");


}

int	main()
{
	_while();printf("while check\n");
	_do_while();printf("do while check\n");
	_for();printf("for check\n");
	return 0;
}