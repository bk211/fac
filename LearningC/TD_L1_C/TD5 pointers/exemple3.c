#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a = 1; int b = 2;
 int * p = &a; int * q = &b;
 printf("a = %d, b = %d.\n", a, b);
 printf("*p = %d, *q = %d.\n", *p, *q);
 printf("&a = %p, &b = %p.\n", &a, &b);
 printf(" p = %p, q = %p.\n", p, q);}