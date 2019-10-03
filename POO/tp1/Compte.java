public class Compte{
	int solde;
	String tit ;
	int num;
	int numcompte;

public Compte(int solde,String tit, int num){
	this.solde = solde;
	this.tit  = tit;
	this.num  = num;
}

public Compte(int solde,String tit, int num, int numcompte){
	this.solde = solde;
	this.tit  = tit;
	this.num  = num;
	this.numcompte = numcompte;
}
void deposer(int montant){
	solde = solde + montant;
}

boolean retirer(int montant){
	if(this.solde >= montant){
		solde = solde -montant;
		return true;
	}
	else{
		System.out.println("solde insuffisant,operation annulé");
		return false;
	}
}

void afficher(){
	System.out.println("titulaire :"+this.tit+" solde:"+this.solde);
}

void virerVers(Compte t2){
	if(this.retirer(75)){
		t2.deposer(75);
	}
}

void virerXVers(Compte t2,int somme){
	this.retirer(somme);
	t2.deposer(somme);

}
}
