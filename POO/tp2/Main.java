public class Main{

    public static void main(String[] args) {
        Point p1 = new Point(8,6);
        Point p2 = new Point(5,2);
        Segment s1 = new Segment(p1,p2);
        Segment s2 = new Segment(1, 2, 3, 4);
        System.out.println(s1.toString());
        System.out.println(s2.toString());

        Point m1 = s1.milieu();
        System.out.println(m1.toString());
        System.out.println(s1.longueur());
        Point p3 = s1.projection(m1);
        System.out.println(p1.toString());

        Triangle t1 = new Triangle(p1,p2,p3);
        System.out.println(t1.perimetre());
        System.out.println(t1.aire());
    }
}
