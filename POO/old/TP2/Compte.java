class Compte{
	int numero;
	int solde;
	Compte(int numC){
		numero = numC;
		solde = 0;
	}

	void depot(int n){
		solde = solde +n;
	}

	void retrait(int n){
		solde = solde -n;
	}

	void afficher(){
		System.out.println("solde du compte numero "+numero+": "+solde);
	}
}