public class Main {
	public static void main(String[] args)
	{
		 Graphique a = new Graphique(3);
		 Point p1 = new Point(1,2);
		 Point p2 = new Point(0,2);
		 Point p3 = new Point(3,2);
		 Point p4 = new Point(8,5);
		 Point p5 = new Point(1,0);

		 Segment s1 = new Segment(p1,p2,0);
		 Triangle t1 = new Triangle(p1,p2,p3,1);
		 Rectangle r1 = new Rectangle(p1,p3,p5,p2,2);

		 a.addFigure(s1);
		 a.addFigure(t1);
		 a.addFigure(r1);
		 p1.affiche();
		 System.out.println("=====");
		 s1.affiche();
		 System.out.println("=====");
		 t1.affiche();
		 System.out.println("=====");
		 r1.affiche();
		 System.out.println("==========");
		 Graphique.afficherTableau(a);
		 System.out.println("==========");
		 System.out.println(p4.toString2());
		 System.out.println("==========");
		 System.out.println(s1.toString2());
		 
	}

	
}