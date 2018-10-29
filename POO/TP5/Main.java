public class Main {
	public static void main(String[] args) {	
		Vehicule DDD = new Vehicule("D","2711",11,13);
		//DDD.affiche();
		//System.out.println("\n");

		Avion Av = new Avion("air","3111",11,20,"noir","banale",300);
		//Av.affiche();

		//System.out.println("\n");
		Voiture Vo = new Voiture("CC","1111",10,5,"rouge","bidon",500);
		//Vo.affiche();

		Elevage ferme = new Elevage(10,10);
		Poulets p1 = new Poulets(5,1,3,5,5);
		Poulets p2 = new Poulets(4,2,3,5,5);
		Poulets p3 = new Poulets(5,3,3,5,5);

		ferme.ajouterPoulet(p1);
		ferme.ajouterPoulet(p2);
		ferme.ajouterPoulet(p3);

		ferme.afficheGain();
		ferme.abattrePoulets();

		Entreprise ent = new Entreprise(10);
		Employe e1 = new Employe("e1",1,10);
		e1.calculeSalaire(10);
		Employe e2 = new Employe("e2",2,10);
		e2.calculeSalaire(10);
		Employe e3 = new Employe("e3",3,20);
		e3.calculeSalaire(10);

		e1.afficheSalaire();
		e2.afficheSalaire();
		e3.afficheSalaire();
		Commerciaux c1 = new Commerciaux("c1",4,10,5);
		c1.calculeSalaireCommerciaux(10,5);//inclue deja afficheSalaire()

		ent.ajouterEmploye(e1);
		ent.ajouterEmploye(e2);
		ent.ajouterEmploye(e3);
		ent.ajouterEmploye(c1);

		ent.afficheEntreprise();
		ent.calculSalaireAVerser();
	}
}