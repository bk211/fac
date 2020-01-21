#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long int ullint;

struct paire
{
    ullint fun;
    ullint fdeux;
};
typedef struct paire paire;

paire fiblog (int n) {
  paire mi, res;
  ullint fi;
  int i;

  if (n < 2) {
	res.fun = (ullint) 1;
	res.fdeux = (ullint) 1;
	return res;
  }
  i = n >> 1;
  mi = fiblog(i);
  if (n & 0x01) {
	res.fdeux = mi.fun * mi.fun + mi.fdeux * mi.fdeux;
	res.fun = (mi.fun + mi.fdeux + mi.fdeux) * mi.fun;
	return res;
  }
  res.fun = mi.fun * mi.fun + mi.fdeux * mi.fdeux;
  res.fdeux = (mi.fun + mi.fun - mi.fdeux) * mi.fdeux;
  return res;
}

ullint fibo (int n) {
  paire res;
  if (n >= 0 && n < 92) {
	res = fiblog (n);
	return res.fun;
  }
  return (ullint) 0;
}

ullint fiborec(int n){
    if(n < 2){
        return 1;
    }
    return fiborec(n-1) + fiborec(n-2);
}

ullint fiboiter(int n){
    ullint a = 1;
    ullint b =1;
    int c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        b = a;
        a = c;
    }
    return a;
}

int main(int argc, char const *argv[])
{
    int tps_init, tps_crt, dtps;
    int i;
    int max = 82;
    
    tps_init = (int) clock();
    for ( i = 0; i < max ; i++)
    {
        //fiborec(i);
    }
    tps_crt = (int) clock();
    dtps = tps_crt - tps_init;
    printf("Tps pour fiborec %d\n",dtps);


    tps_init = (int) clock();
    for ( i = 0; i < max ; i++)
    {
        fiboiter(i);
    }
    tps_crt = (int) clock();
    dtps = tps_crt - tps_init;
    printf("Tps pour fiboiter %d\n",dtps);    


    tps_init = (int) clock();
    for ( i = 0; i < max ; i++)
    {
        fiblog(i);
    }
    tps_crt = (int) clock();
    dtps = tps_crt - tps_init;
    printf("Tps pour fibolog %d\n",dtps);
    


    return 0;
}
