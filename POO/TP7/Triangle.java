public class Triangle implements Figure{
	Point a;
	Point b;
	Point c;
	int couleur;
	Triangle(Point x, Point y, Point z,int c){
		a = x;
		b = y;
		c = z;
		couleur = c;
	}

	void(affiche){
		a.affiche();
		b.affiche();
		c.affiche();
		System.out.println("couleur:"+couleur);

	}
}