public class Main{
	public static void main(String[] args) {
		Plat p1 = new Plat("ceci est une entree",10,0);
		Plat p2 = new Plat("aaa",11,1);
		Plat p3 = new Plat("bbb",12,2);
		//p1.affiche();
		//p2.affiche();
		//p3.affiche();

		Repas rep = new Repas(p1,p2,p3);
		rep.affiche();

		Repas rep2 = new Repas(p2,p1);
		rep2.affiche();

		Repas rep3 = new Repas(p2,p3);
		rep3.affiche();

		Repas rep4 = new Repas(p2);
		rep4.affiche();

	}


}