public class Segment implements Figure{
	Point a;
	Point b;
	int couleur;
	Segment(Point x, Point y, int c){
		a = x;
		b = y;
		couleur = c;
	}

	public String toString2(){
		return "Un Segment constitué de "+a.toString2()+"et de"+b.toString2();
	}

	public void affiche(){
		a.affiche();
		b.affiche();
		System.out.println("couleur:"+couleur);
	}
}