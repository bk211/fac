/*!\file ratio.h
 * \brief header de la lib ratio
 * \author Farès Belhadj
 * \date September 25, 2013
 */
#ifndef _RATIO_H /* pour éviter les inclusion multiples */
#define _RATIO_H

#define ratio_signe(p, q) ((p) * (q) < 0 ? -1 : 1)
#define ratio_num(r) ((r)->p)
#define ratio_denom(r) ((r)->q)

#ifdef __cplusplus /* pour utiliser la lib en c++, lui indique que ce
		      qui est entre accolades est du C */
extern "C" {
#endif

  extern void quit(void);
  typedef struct ratio_t ratio_t;
  struct  ratio_t {
    int p, q;
  };
  extern int ratio_pgcd(int p, int q);
  extern ratio_t * ratio_new(int p, int q);
  extern void ratio_delete(ratio_t * r);
  extern ratio_t * ratio_neg(ratio_t * r);
  extern ratio_t * ratio_moins(ratio_t * r1, ratio_t * r2);
  extern ratio_t * ratio_plus(ratio_t * r1, ratio_t * r2);
  extern ratio_t * ratio_mul(ratio_t * r1, ratio_t * r2);
  extern ratio_t * ratio_div(ratio_t * r1, ratio_t * r2);
  extern void infixe2postfixe(char * s, char * d);
  extern void conversion_calcul(char *s);
#ifdef __cplusplus
}
#endif

#endif
