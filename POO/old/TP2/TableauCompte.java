class TableauCompte{
	Compte[] tab;
	int longeur ;
	TableauCompte(int n){
		tab = new Compte[n];
		longeur = 0;
	}

	void ajouter(Compte c){
		if (longeur< tab.length){
			tab[longeur]=c;
			longeur++;
		}
	}
	
	void afficher(){
		int i;
		for(i=0;i <longeur;i++){
			tab[i].afficher();
		}
	}
}