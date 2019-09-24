#include "puis.h"
double puis (double x, int n) {
  double res = 1.0;

  while (n) {
	if (n & 0x01)
	  res *= x;
	x *= x;
	n >>= 1;
  }
  return res;
}
