public class Voiture extends Vehicule{
	String couleur;
	String caracteristique;
	int nbPlace;


	Voiture(String m, String d, int pda, int pc,String c1,String c2, int n){
		super(m, d, pda, pc);
		couleur = c1;
		caracteristique = c2;
		nbPlace = n;
	}

	void affiche(){
		super.affiche();
		System.out.println("couleur:"+couleur);
		System.out.println("caracteristique"+caracteristique);
		System.out.println("nbPlace"+nbPlace);
	}
}