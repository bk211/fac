class TableauCompte{
	Compte[] tab;
	int longeur ;
	TableauCompte(int n){
		tab = new Compte[n];
	}

	void ajouter(Compte c){
		if (longeur< tab.length){
			tab[longeur]=c;
			longeur++;
		}
	}
}