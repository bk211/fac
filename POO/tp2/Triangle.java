public class Triangle{
    Point a,b,c;
    Segment s1, s2, s3;

    public Triangle(Point a, Point b, Point c){
        this.a = a;
        this.b = b;
        this.c = c;
        s1 = new Segment(a, b);
        s2 = new Segment(b, c);
        s3 = new Segment(c, a);

    }
    public boolean isRectangle(){//test si un Triangle est Rectangle
        float l1=s1.longueur();
        float l2=s2.longueur();
        float l3=s3.longueur();

        return((l1*l1 == l2*l2 + l3*l3)
            || (l2*l2 == l1*l1 + l3*l3)
            || (l3 *l3 == l1 *l1 + l2*l2));
    }

    public boolean isEquilateral(){
        return ((s1.longueur() == s2.longueur()) && (s2.longueur() == s3.longueur()));
    }

    public boolean isIsocele(){
        return (s1.longueur() == s2.longueur()
            || s2.longueur() == s3.longueur()
            || s3.longueur() == s1.longueur());
    }

    //public Point coorCentreCercleCirconscrit(){
        //trop long a faire
    //}

    public float perimetre(){
        return s1.longueur() + s2.longueur() + s3.longueur();
    }

    public float aire(){
        //base ab, sommet oppose c
        float hauteur = Math.abs(c.getY() - a.getY());
        return s1.longueur() * hauteur;
    }
}
