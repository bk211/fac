class Banque{
	String nom;
	TableauCompte tous = new TableauCompte(50);
	Banque(String n){nom = n;}

	void creerCompte(Titulaire[] tabTitulaire,int nbTitulaire,int numeroCompte){
		int i;
		for(i = 0; i < nbTitulaire; ++i){
			tabTitulaire[i].mesComptes.tab[0]= tous.tab[0];

		}
	}
}