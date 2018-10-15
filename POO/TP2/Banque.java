class Banque{
	String nom;
	TableauCompte tous = new TableauCompte(50);
	int prochainNumero = 1000;
	Banque(String n){nom = n;}

	void creerCompte(Titulaire[] tabTitu){
		Compte c = new Compte(prochainNumero);
		prochainNumero ++;
		int i;
		tous.ajouter(c);
		
		for(i = 0; i < tabTitu.length; i++){
			tabTitu[i].ajouterCompteTitulaire(c);
		}
	}
	
		
}