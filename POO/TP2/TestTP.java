public class TestTP{
	public static void main(String[] args){
		Banque BNP = new Banque("BNP");
		
		Titulaire jean = new Titulaire("jean");
		Titulaire[] t1 = new Titulaire[1];
		t1[0] = jean;
		BNP.creerCompte(t1);
		//BNP.tous.tab[0].afficher();
		
		Titulaire paul = new Titulaire("Paul");
		Titulaire pierre = new Titulaire("pierre");
		Titulaire fatima = new Titulaire("fatima");
		
		Titulaire[] tab1= {paul};
		Titulaire[] tab2= {pierre};
		Titulaire[] tab3= {fatima};
		Titulaire[] PFjoint = {paul, fatima};
		
		//BNP.creerCompte(tab1);	
		BNP.creerCompte(tab2);
		BNP.creerCompte(tab3);
		BNP.creerCompte(PFjoint);
		paul.afficher();
		pierre.afficher();
		fatima.afficher();
		
		
		
		
	}
}