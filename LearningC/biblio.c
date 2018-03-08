// test.c
#include <studio.h>

int main(){
	float ntl,nle;
	//ntl nb tot livre
	//nle nb livre emp 
	printf("nb tot livre?\n",ntl);
	//scanf("%f",&ntl);
	ntl=100;
	if (ntl<0) 
		printf("erreur nb tot livre negatif\n");
	else{
		printf("nb livre emp?\n",nle);
		//scanf("%f",&nle);
		nle=50;
		if (ntl<nle)
			printf("nb livre emprunte >nb livre tot\n");
		else 
			printf("pourcentage restant= %2.f\n",100*(ntl-nle)/ntl);
	}
	return (0);
}