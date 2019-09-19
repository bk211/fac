public class Rectangle implements Figure{
	Point a;
	Point b;
	Point c;
	Point d;
	int couleur;
	Rectangle(Point x,Point y, Point z, Point w,int color){
		a = x;
		b = y;
		c = z;
		d = w;
		couleur = color;
	}

	public void affiche(){		
		a.affiche();
		b.affiche();
		c.affiche();
		d.affiche();
		System.out.println("couleur:"+couleur);


	}
}