#include <stdio.h>
int main(int argc, char* argv[]) {

  printf("taille d'un char : %lu bits \n",sizeof(char)*8);
  printf("taille d'un int : %lu bits \n",sizeof(int)*8);
  printf("taille d'un float : %lu bits \n",sizeof(float)*8);
  printf("taille d'un double : %lu bits \n",sizeof(double)*8);
  printf("taille d'un short : %lu bits \n",sizeof(short)*8);
  printf("taille d'un long : %lu bits \n",sizeof(long)*8);
  printf("taille d'un long double : %lu bits \n",sizeof(long double)*8);
  printf("taille d'un unsigned int : %lu bits \n",sizeof(unsigned int)*8);
  printf("taille d'un unsigned char : %lu bits \n",sizeof(unsigned char)*8);
  printf("taille d'un unsigned short : %lu bits \n",sizeof(unsigned short)*8);
  printf("taille d'un unsigned long : %lu bits \n",sizeof(unsigned long)*8);


    return 0;
}
