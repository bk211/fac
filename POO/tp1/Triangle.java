public class Triangle{
    Point a,b,c;
    Segment s1, s2, s3;

    Point Triangle(Point a, Point b, Point c){
        this.a = a;
        this.b = b;
        this.c = c;
        s1 = new Segment(s1, s2);
        s2 = new Segment(s2, s3);
        s3 = new Segment(s2, s3);

    }
    boolean isRectangle(){//test si un Triangle est Rectangle
        l1=s1.getLength();
        l2=s2.getLength();
        l3=s3.getLength();

        return((l1*l1 == l2*l2 + l3*l3)
            || (l2*l2 == l1*l1 + l3*l3)
            || (l3 *l3 == l1 *l1 + l2*l2));
    }

    boolean isEquilateral(){
        return (s1.getLength() == s2.getLength()) && (s2.getLength() == s3.getLength()));
    }

    boolean isIsocele(){
        return (s1.getLength() == s2.getLength()
            || s2.getLength() == s3.getLength()
            || s3.getLength() == s1.getLength());
    }



}
