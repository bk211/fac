public class Poulets extends Volaille{
	int prixKilo;
	int poidsAbattage;


	Poulets(int n1, int n2, int n4,int n5){
		super(n1,n2);
		prixKilo = n4;
		poidsAbattage = n5;
	}

	void tuerPoulet(){
		super.tuerVolaille();
	}

}