public class Repas{
	Plat entree;
	Boolean etatEntree = false;
	Plat plat;
	Boolean etatPlat = false;
	Plat dessert;
	Boolean etatDessert = false;

	Repas(Plat e, Plat p, Plat d){
		if(valide(e, p, d)){
			entree = e;
			plat = p;
			dessert = d;
			etatEntree = true;
			etatPlat = true;
			etatDessert = true;
		}
		else{
			System.out.println("Repas invalide");
		}
	}

	Repas(Plat p1, Plat p2){
		if(p1.categorie ==1 && p2.categorie == 1){
			System.out.println("2 plats?");
		}
		else if(p1.categorie !=1 && p2.categorie != 1){
			System.out.println("Il vous manque le plat");
		}
		else{
			if(p1.categorie == 1){
				plat = p1;
				etatPlat = true;
				if(p2.categorie == 0){
					entree = p2;
					etatEntree = true;
				}
				else{
					dessert = p2;
					etatDessert = true;
				}
			}
		}

	}

	Repas(Plat p){
		plat = p;
		etatPlat = true;
	}

	void affiche(){
		if(etatEntree){
			System.out.println("\nEntree:");
			entree.affiche();
		}
		if(etatPlat){
			System.out.println("\nPlat:");
			plat.affiche();
		}

		if(etatDessert){
			System.out.println("\nDessert:");
			dessert.affiche();
		}
		System.out.println("\nPrix total:"+calcul());

	}

	int calcul(){
		int resultat = 0;
		
		if(etatEntree){
			resultat += entree.getPrix();
		}
		if(etatPlat){
			resultat += plat.getPrix();
		}
		if(etatDessert){
			resultat += dessert.getPrix();
		}
		return resultat;
	}

	static Boolean valide(Plat e, Plat p, Plat d){
		if(e.categorie != 0) {return false;};
		if(p.categorie != 1) {return false;};
		if(d.categorie != 2) {return false;};
		System.out.println("Repas valide\n");
		return true;
	}



}