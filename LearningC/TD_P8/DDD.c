#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
void foo(char * str1, char * str2) {
	char * d = str1;
	int i = 0, l = strlen(str2);
	while(*str1) {
		*(str1++) += str2[(i++)%l] - '0';
		printf("%s\n", d);
	}
}
*/


int main(void){	
	unsigned char a = 35;
	int i = 1 <<((sizeof(a) * 8) -1);
	for (; i > 0; --i)
	{
		if(!(a & i))
			putchar('0');
		else
			putchar('1');
		/* code */
		i >> ;
	}
	return 0;
}
