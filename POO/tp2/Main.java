public class Main{

    public static void main(String[] args) {


        Point p1 = new Point(0,0);
        Point p2 = new Point(0,10);
        Point p3 = new Point(10,10);
        Segment s1 = new Segment(p1,p2);
        Segment s2 = new Segment(10, 10, 0, 10);
        System.out.println(s1);
        System.out.println(s2);

        Point m1 = s1.milieu();

        System.out.println(m1);
        System.out.println(s1.longueur());

        System.out.println(p1.toString());

        Triangle t1 = new Triangle(p1,p2,p3);
        System.out.println(t1.perimetre());
        System.out.println(t1.aire());


        Matrice Mat1 =new Matrice(2,3);
        Mat1.setValue(0,0, 1);
        Mat1.setValue(0,1, 2);
        Mat1.setValue(0,2, 0);
        Mat1.setValue(1,0, 4);
        Mat1.setValue(1,1, 3);
        Mat1.setValue(1,2,-1);
        Mat1.afficheMatrice();
        System.out.println();
        Matrice Mat2 = new Matrice(3,2);
        Mat2.setValue(0,0, 5);
        Mat2.setValue(0,1, 1);
        Mat2.setValue(1,0, 2);
        Mat2.setValue(1,1, 3);
        Mat2.setValue(2,0, 3);
        Mat2.setValue(2,1, 4);
        Mat2.afficheMatrice();
        System.out.println();
        Matrice Mat3 = Mat1.produit(Mat2);
        Mat3.afficheMatrice();
        System.out.println();
        Mat1.transpose().afficheMatrice();
        System.out.println();
        Mat2.transpose().afficheMatrice();
        System.out.println();
        Mat3.transpose().afficheMatrice();

        //Matrice Mat4 = Matrice.litMatrice();

    }


}
