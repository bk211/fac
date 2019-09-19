public class PieceEureka{
	public static void main(String[] args) {
		Theatre eureka;
		eureka = new Theatre("EUREKA",7.5,5,60,0,0);
		eureka.afficher();
		eureka.vendrePlaces(20,true);
		eureka.vendrePlaces(10,false);
		System.out.println(eureka.nbPlaceTotal);
		System.out.println(eureka.chiffreAffaires());
		System.out.println(eureka.tauxRemplissage());
		eureka.afficher();
	}
}