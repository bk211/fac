public class Rectangle implements Figure{
	Point a;
	Point b;
	Point c;
	Point d;
	int couleur;
	Rectangle(Point x,Point y, Point z, Point w,int c){
		a = x;
		b = y;
		c = z;
		d = w;
		couleur = c;
	}

	void(affiche){		
		a.affiche();
		b.affiche();
		c.affiche();
		d.affiche();
		System.out.println("couleur:"+couleur);


	}
}