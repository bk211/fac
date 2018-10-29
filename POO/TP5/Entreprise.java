public class Entreprise{
	Employe[] tabEmploye;
	int tailleEntreprise;
	int nbEmploye;
	int salaireAVerser;

	Entreprise(int taille){
		tailleEntreprise = taille;
		tabEmploye =new Employe[tailleEntreprise];
		nbEmploye = 0;
		int salaireAVerser = 0; 
	}

	void ajouterEmploye(Employe p){
		tabEmploye[nbEmploye++] = p;
	}

	void afficheEntreprise(){
		int i;
		System.out.println("\n");
		for(i =0; i < nbEmploye; ++i){
			tabEmploye[i].affiche();
			System.out.println("\n");
		}
	}

	void calculSalaireAVerser(){//supposant que le salaire des chaq employe est deja instancie
		int i;
		for (i = 0; i< nbEmploye; ++i) {
			salaireAVerser += tabEmploye[i].salaire;
		}
		System.out.println("salaire a verser :"+salaireAVerser);
	}


}