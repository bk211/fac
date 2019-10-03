public class Theatre{
	String nomDePiece;
	double prixPlaceTarifNormal;
	double prixPlaceTarifReduit;
	int nbPlaceTotal;
	int VenduTarifNormal;
	int VenduTarifReduit;

	public Theatre(String ndp,double pptn,double pptr,int nbpt){
		nomDePiece = ndp;
		prixPlaceTarifNormal= pptn;
		prixPlaceTarifReduit= pptr;
		nbPlaceTotal = nbpt;
		VenduTarifNormal= 0;
		VenduTarifReduit= 0;
	}

	public int nbPlaceDispo(){
		return nbPlaceTotal - VenduTarifNormal - VenduTarifReduit;
	}

	public void vendrePlaces(int nbre, boolean TarifReduit){
		if(nbre > this.nbPlaceDispo())
			System.out.println("Nb de place insuffisant,\nNb de place restant: "+ this.nbPlaceDispo());
		else if(TarifReduit){// applique le tarif reduit
			VenduTarifReduit += nbre;
			System.out.println("Pour "+nbre+" places tarif reduits, vous devez payer :"+(prixPlaceTarifReduit * nbre)+"€");
		}
		else{
			VenduTarifNormal += nbre;
			System.out.println("Pour "+nbre+" places tarif normal, vous devez payer :"+(prixPlaceTarifReduit * nbre)+"€");
		}
	}

	public void remiseAZero(){
		if (nbPlaceTotal - VenduTarifNormal -VenduTarifReduit == 0){
			VenduTarifNormal = 0;
			VenduTarifReduit = 0;
		}

	}

	public double chiffreAffaires(){
		return (prixPlaceTarifNormal * VenduTarifNormal + prixPlaceTarifReduit * VenduTarifReduit);
	}

	public double tauxRemplissage(){
		return ((double)(VenduTarifNormal+ VenduTarifReduit) / (double)nbPlaceTotal*100);
	}

	public void afficher(){
		System.out.println("pièce jouée :"+nomDePiece+",Nombre de places:"+nbPlaceTotal);
		System.out.println("Prix d'une place :"+prixPlaceTarifNormal+"€");
		System.out.println("Prix d'une place :"+prixPlaceTarifReduit+"€");
		System.out.println(VenduTarifNormal+" places vendues au tarif normal");
		System.out.println(VenduTarifReduit+" places vendues au tarif reduits");

	}

}
