public class SegmentT{

    public static void main(String[] args) {
        Point t1 = new Point(9,6);
        System.out.println(t1.getX());
        t1.setY(3);
        System.out.println(t1.toString());

        Point t2 = new Point(5,2);
        Segment s1 = new Segment(t1,t2);

        Segment s2 = new Segment(1, 2, 3, 4);
        System.out.println(s2.toString());
        s2.translate(t1,t2);
        System.out.println(s2.toString());

    }
}
