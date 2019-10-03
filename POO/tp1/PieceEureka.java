public class PieceEureka{
	public static void main(String[] args) {
		Theatre eureka;
		eureka = new Theatre("EUREKA",7.5,5,60);
		System.out.println(eureka.nbPlaceDispo());
		eureka.vendrePlaces(20,true);
		eureka.vendrePlaces(10,false);
		eureka.vendrePlaces(40,false);
		eureka.afficher();
		System.out.println(eureka.chiffreAffaires());
		System.out.println(eureka.tauxRemplissage());
		eureka.vendrePlaces(30,false);
		eureka.remiseAZero();
		eureka.afficher();

	}
}
