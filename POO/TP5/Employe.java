public class Employe{
	String nom;
	int matricule;
	int indiceSalarial;
	int salaire;
	Employe[] inferieurs;//par defaut un employe a au max 10 inferieurs
	int nbInferieurs;

	Employe(String n, int m, int i){
		nom = n;
		matricule = m;
		indiceSalarial = i;
		nbInferieurs = 0;
		salaire = 0;
		inferieurs = new Employe[10];
	}

	void affiche(){
		System.out.println("nom:"+nom);
		System.out.println("matricule:"+matricule);
		System.out.println("indiceSalarial:"+indiceSalarial);
	}

	void calculeSalaire(int valeur){
		salaire = indiceSalarial * valeur;
	}

	void afficheSalaire(){
		System.out.println("salaire:"+salaire);
	}
	void ajouterInferieur(Employe p1){
		inferieurs[nbInferieurs++] = p1;
	}

	void afficheInferieus(){
		int i;
		System.out.println("les inferieurs de "+nom+"sont:\n");
		for(i=0; i < nbInferieurs; ++i){
			inferieurs[i].affiche();
		}
		System.out.println("\n");

	}

}