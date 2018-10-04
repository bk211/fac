#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static void stack(const char * str);

int main(void) {
stack("Hello");
stack("Hello world !!!!!!!!!!!!!!!! 123456789 ... c’est pour deborder la pile :)");
return 0;
}
static void stack(const char * str) {
	static char test[1];
	char tmp[10], * ptr = malloc(10 * sizeof *ptr);
	printf("curiosite : main %p, stack %p, tmp %p, test %p, ptr %p\n", main, stack, tmp, test, ptr);
	strcpy(tmp, str);
	printf("Ca marche avec \"%s\" !\n", str);
	free(ptr); /* commentez le free et remarquez la diff´erence */
}