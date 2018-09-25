#include <stdio.h>
int main() {
 int a=1, b=2, c=3, d=4;
 printf("a = %d, b = %d, c = %d, d = %d.\n", a, b, c, d);
 printf("a + b * c = %d.\n", a + b * c);
 printf("a * b + c = %d.\n", a * b + c);
 printf("a + c / b = %d.\n", a + c / b);
 printf("c / a + b = %d.\n", c / a + b);
 printf("a + b * c - d = %d.\n", a + b * c - d );
 printf("(a + b)*c - d = %d.\n", (a + b)*c - d );
 printf("a + (b*c) - d = %d.\n", a + (b*c) - d );
 printf("a + b*(c - d) = %d.\n", a + b*(c - d) );
 return (0);
}