#include <stdio.h>
int fct (int n) {
  int i, v1, v2;

  v1 = 1;
  v2 = 1;
  i = 2;
  while (i <= n) {
	v2 += v1;
	v1 = v2 - v1;
	i++;
  }
  return v2;
}
int ftc (int n) {
  if (n < 2)
	return 1;
  return ftc(n-1) + ftc (n-2);
}

main () {
  int n = 0;
  while (n < 20) {
	printf("f(%3d)\t== %d\n",n, fct(n));
	printf("\t== %d\n", ftc(n));
	n++;
  }
}
