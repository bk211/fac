public class Vehicule{
	String marque;
	String dateAchat;
	int prixDAchat;
	int prixCourant;

	Vehicule(String m, String d, int pda, int pc){
		marque = m;
		dateAchat = d;
		prixDAchat = pda;
		prixCourant = pc;
	}

	void affiche(){
		System.out.println("marque:"+marque);
		System.out.println("dateAchat:"+dateAchat);
		System.out.println("prixDAchat:"+prixDAchat);
		System.out.println("prixCourant:"+prixCourant);
	}

}