class Compte{
	int numero;
	int solde;
	
	void depot(int n){
		solde = solde +n;
	}

	void retrait(int n){
		solde = solde -n;
	}

	void afficher(){
		System.out.println("solde du compte numero"+numero+":");
	}
}