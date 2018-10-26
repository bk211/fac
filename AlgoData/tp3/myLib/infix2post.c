#include <stdio.h>
#include "pile.h"
#include <stdlib.h>
#define MAX 256
static void infixe2postfixe(char * s, char * d) {
while(*s) {
	if(*s >= '0' && *s <= '9') {
		do {
			*d++ = *s++;
		} while( *s >= '0' && *s <= '9');
		*d++ = ' ';
	if(!*s) break;
	}

	if((*s == ')') && !vide()) {
		*d++ = (char)pop();
		*d++ = ' '; }
	else if(*s == '+') push((int) *s);
	else if(*s == '-') push((int) *s);
	else if(*s == '*') push((int) *s);
	else if(*s == '/') push((int) *s);
	s++;
}
while(!vide()) {*d++ = (char)pop(); *d++ = ' '; }
*d = '\0';
}