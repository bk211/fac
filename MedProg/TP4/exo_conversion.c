#include <stdio.h>
//CAI Chaolei 17812776
float conv_km2mile(float a){
  return a * 0.621371; 
}

float conv_mile2km(float a){
  return a * 1.60934; 
}

double calcule_interet(double a , float b,int c){
  if(c) return calcule_interet(a + a * b/100 ,b,c-1);
  return a;
}

int main(){
  float entree_user1;
  float entree_user2;
  double entree_user3;
  float entree_user4;
  int entree_user5;

  printf("Entrez la valeur en km :");
  scanf("%f",&entree_user1);
  printf("Entrez la valeur en mile :");
  scanf("%f",&entree_user2);
  printf("Entrez la valeur de base a appliquer l'interet :");
  scanf("%lf",&entree_user3);
  printf("Entrez l'interet par mois a appliquer :");
  scanf("%f",&entree_user4);
  printf("Entrez la duree de mois a appliquer :");
  scanf("%d",&entree_user5);
  
  float resultat_conv_km2mile =conv_km2mile(entree_user1);
  float resultat_conv_mile2km = conv_mile2km(entree_user2);
  float resultat_prix_final = calcule_interet(entree_user3, entree_user4,entree_user5);

  printf("%.3f km = %.3f miles \n",entree_user1,resultat_conv_km2mile );
  printf("%.3f miles = %.3f km\n",entree_user2,resultat_conv_mile2km );
  printf("preter %.3lf pour un interet de %.2f%% pendant %d mois = %f\n",entree_user3,entree_user4,entree_user5,resultat_prix_final);


  return 0;
}
