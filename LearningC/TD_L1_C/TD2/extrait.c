#include <stdio.h>
int main() {
 int a, b;
 printf("a ? "); scanf("%d", &a);
 printf("b ? "); scanf("%d", &b);
 if (a>b) b++; else b = ++a;
 a=0;
 printf("a = %d, b = %d\n", a, b);
 return (0);
}
/*
2 1 
1 1
1 2
0 2*/