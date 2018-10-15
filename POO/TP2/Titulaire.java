class Titulaire{
	String nom;
	Titulaire(String n ){nom = n;}
	TableauCompte mesComptes = new TableauCompte(10);
	int nbCompteDetenue = 0;

	void ajouterCompteTitulaire(Compte c){
		mesComptes.ajouter(c);
	}
	
	void afficher(){
		System.out.println("Comptes de "+nom);
		mesComptes.afficher();
	}
	
	void virement(Compte a,int numeroB){
		
	}
}