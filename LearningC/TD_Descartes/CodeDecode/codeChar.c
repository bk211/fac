#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define NBL 26
#define TAILLE 50
#define CLE 19
int codeN(int n,int a);
char codeChar(char c,int a);
void codeChaine(char * c1,char * c2, int a);

int main(int argc, char const *argv[])
{
	//printf("a=%d,z=%d,A=%d,Z=%d\n",'a','z','A','Z');
	char msg[100],msg_code[100];
	printf("votre message?");
	scanf("%s",&msg);
	codeChaine(msg,msg_code,3);
	return 0;
}

int codeN(int n,int a){return n*a % NBL;}

char codeChar(char c,int a){
	int q=int(c);
	char temp=c;
	if((93<int(c))&&(int(c)<123)){return char(codeN(q-97,a)+97);}
	return c;
}

void codeChaine(char * c1,char * c2, int a)
{	
	for (int i = 0;; ++i)
	{
		continue;
	}
}