#include <stdio.h>
#define prix_du_km 60/200
int main(){
	int km;
	printf("nombre de kilometres ?\n");
	scanf("%d",&km);
	printf("prix du billet sans ristourne = %.2f\n",km*prix_du_km );
	printf("prix du billet avec ristourne =%.2f\n", km*prix_du_km*0.85);
}
