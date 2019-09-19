public class Banque{
	public static void main(String[] args) {
		Compte c1;
		Compte c2;
		c1 = new Compte(0,"c1",1,001);
		c2 = new Compte(0,"c2",2);
		c1.deposer(500);
		c2.deposer(1000);
		c2.retirer(10);
		c1.afficher();
		c2.afficher();
		c1.virerVers(c2);
		c1.afficher();
		c2.afficher();
		Compte tableauC4[] = {new Compte(0,"c3",3),new Compte(0,"c4",4),new Compte(0,"c5",5),new Compte(0,"c6",6)};
		//tableauC4[0] = new Compte(0,"c3",3);
		//tableauC4[1] = new Compte(0,"c4",4);
		//tableauC4[2] = new Compte(0,"c5",5);
		//tableauC4[3] = new Compte(0,"c6",6);
		int i;
		for(i = 0; i <4;++i){
			tableauC4[i].afficher();
		}
		
		for(i = 0; i <4;++i){
			tableauC4[i].deposer(200+100*i);
		}
		for(i = 0; i <4;++i){
			tableauC4[i].afficher();
		}

		for(i = 0; i <4;++i){
			int j = i;
			for (;j < 4; ++j) {
				tableauC4[i].virerXVers(tableauC4[j],20);
			}
		}
		for(i = 0; i <4;++i){
			tableauC4[i].afficher();
		}

		c1.retirer(500);
		c1.afficher();
		
	}
}