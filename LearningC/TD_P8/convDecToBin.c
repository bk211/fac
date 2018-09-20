#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
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
    int mask = 1 << ((sizeof(a) * 8) -1); //initiailisation max

    for (; mask > 0; mask >>=1)
	{
		if(!(a & mask))
			putchar('0');
		else
			putchar('1');
	}

	return 0;
}
