public class Canards extends Volaille{
	int prixKilo;
	int poidsAbattage;


	Canards(int n1, int n2,int n4, int n5){
		super(n1,n2);
		prixKilo = n4;
		poidsAbattage = n5;
	}
	

	void tuerCanards(){
		super.tuerVolaille();
	}
}