public class Triangle implements Figure{
	Point a;
	Point b;
	Point c;
	int couleur;
	Triangle(Point x, Point y, Point z,int color){
		a = x;
		b = y;
		c = z;
		couleur = color;
	}

	public void affiche(){
		a.affiche();
		b.affiche();
		c.affiche();
		System.out.println("couleur:"+couleur);

	}
}