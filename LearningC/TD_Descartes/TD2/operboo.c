#include <stdio.h>
int main() {
 int a=1, b=1, c=0, d=0;
 printf("a = %d, b = %d, c = %d, d = %d.\n", a, b, c, d);

 printf("a || b && c || d = %d.\n", a || b && c || d);
 printf("(a||b) && c || d) = %d.\n", (a||b) && c || d);
 printf("a || (b&&c) || d = %d.\n", a || (b&&c) || d);
 printf("a || b && (c||d) = %d.\n", a || b && (c||d));
 return (0);
}
/*
a= 1, b=1 , c=0 ,d=0
0 1
0 0
1 1
0 1ju
*/ 