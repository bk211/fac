public class Commerciaux extends Employe{
	int interessement;
	int ventes;

	Commerciaux(String n, int m, int i, int v){
		super(n, m, i);
		ventes = v;
	}

	void setVentes(int v){
		ventes = v;
	}

	void calculeSalaireCommerciaux(int indiceFixe, int indiceVente){
		super.calculeSalaire(indiceFixe);//calcule de la part fixe;
		interessement = ventes * indiceVente; // calcule d'interessement percue
		salaire += interessement; //au salaire fixe on ajoute l'interessement;
		super.afficheSalaire();

	}

}