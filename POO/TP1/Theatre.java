public class Theatre{
	String nomDePiece;
	double prixPlaceTarifNormal;
	double prixPlaceTarifReduit;
	int nbPlaceTotal;
	int nbPlaceTarifNormal;
	int nbPlaceTarifReduit;

	public Theatre(String nomDePiece,double prixPlaceTarifNormal,double prixPlaceTarifReduit,int nbPlaceTotal,int nbPlaceTarifNormal,int nbPlaceTarifReduit){
		this.nomDePiece = nomDePiece;
		this.prixPlaceTarifNormal=prixPlaceTarifNormal;
		this.prixPlaceTarifReduit= prixPlaceTarifReduit;
		this.nbPlaceTotal = nbPlaceTotal;
		this.nbPlaceTarifNormal= nbPlaceTarifNormal;
		this.nbPlaceTarifReduit=nbPlaceTarifReduit;
	}

	public int nbPlaceDispo(){
		return nbPlaceTotal-nbPlaceTarifNormal-nbPlaceTarifReduit;
	}

	public void vendrePlaces(int nbPlace, boolean TarifReduit){
		if(nbPlace > this.nbPlaceDispo())
			System.out.println("Nb de place insuffisant,\n Nb de place restant: "+this.nbPlaceTotal);
		else if(TarifReduit){// applique le tarif reduit
			nbPlaceTarifReduit += nbPlace;
			System.out.println("Pour "+nbPlace+"places tarif reduits, vous devez payer :"+(prixPlaceTarifReduit * nbPlace));
		}
		else{
			nbPlaceTarifNormal += nbPlace;
			System.out.println("Pour "+nbPlace+"places tarif normal, vous devez payer :"+(prixPlaceTarifReduit * nbPlace));
		}
	}
	public void remiseAZero(){
		if (nbPlaceTarifNormal+ nbPlaceTarifReduit == nbPlaceTotal)
			nbPlaceTotal = 0;
	}

	public double chiffreAffaires(){
		return (prixPlaceTarifNormal * nbPlaceTarifNormal + prixPlaceTarifReduit * nbPlaceTarifReduit);
	}

	public double tauxRemplissage(){
		return ((nbPlaceTarifNormal+ nbPlaceTarifReduit)/ nbPlaceTotal*1.0);
	}
	public void afficher(){
		System.out.println("pièce jouée :"+nomDePiece+",Nombre de places:"+nbPlaceTotal);
		System.out.println("Prix d'une place :"+prixPlaceTarifNormal+"€");
		System.out.println("Prix d'une place :"+prixPlaceTarifReduit+"€");
		System.out.println(nbPlaceTarifNormal+" places vendues au tarif normal");
		System.out.println(nbPlaceTarifReduit+" places vendues au tarif reduits");

	}
}