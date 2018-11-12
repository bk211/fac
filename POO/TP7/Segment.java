public class Segment implements Figure{
	Point a;
	Point b;
	int couleur;
	Segment(Point x, Point y, int c){
		a = x;
		b = y;
		couleur = c;
	}

	void(affiche){
		a.affiche();
		b.affiche();
		System.out.println("couleur:"+couleur);
	}
}