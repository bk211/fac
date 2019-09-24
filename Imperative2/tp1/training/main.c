#include <stdio.h>
#include "puis.h"

int main () {
  int n;
  double y;

  for (y=0.0; y < 3.1; y += 0.2) {
	for (n = 0; n < 10; n++)
	  printf ("%3.5lf ^ %d == %6.8lf\n", y, n, puis(y,n));
  }
}
