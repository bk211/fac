public class Main{

    public static void main(String[] args) {

        /*
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
        */

        Matrice Mat1 =new Matrice(2,3);
        Mat1.setValue(0,0, 1);
        Mat1.setValue(0,1, 2);
        Mat1.setValue(0,2, 0);
        Mat1.setValue(1,0, 4);
        Mat1.setValue(1,1, 3);
        Mat1.setValue(1,2,-1);
        Mat1.afficheMatrice();
        Matrice Mat2 = new Matrice(3,2);
        Mat2.setValue(0,0, 5);
        Mat2.setValue(0,1, 1);
        Mat2.setValue(1,0, 2);
        Mat2.setValue(1,1, 3);
        Mat2.setValue(2,0, 3);
        Mat2.setValue(2,1, 4);
        Mat2.afficheMatrice();

        Mat1.produit(Mat2).afficheMatrice();


    }


}
