public class Segment{
    Point start;
    Point stop;
    float length;

    Segment(Point start, Point stop){
        this.start = start;
        this.stop = stop;

    }

    Segment(float a, float b, float c, float d){
        this.start = new Point(a,b);
        this.stop = new Point(c,d);

    }

    public Point getStart(){
        return start;

    }
    public Point getStop(){
        return stop;
    }

    public void setStart(Point start){
        this.start = start;
    }

    public void setStop(Point stop){
        this.stop = stop;
    }


    public String toString(){
        return "Ce segment est composee des points suivant :\n" + start.toString() +"\n" +stop.toString();
    }

    public void translate(Point start, Point stop){
        this.start.translate(start.getX(),start.getY());
        this.stop.translate(stop.getX(),stop.getY());
    }

    public static boolean commun(Segment t1, Segment t2){
        if (Point.comparer(t1.getStart(), t2.getStart())
            || Point.comparer(t1.getStart(), t2.getStop())
            || Point.comparer(t1.getStop(), t2.getStop())
            || Point.comparer(t1.getStop(), t2.getStart()))
                return true;
        return false;
    }

    public float longueur(){
        length = ((this.stop.getX()- this.start.getX()) * (this.stop.getX()- this.start.getX())
                +(this.stop.getY()- this.start.getY()) * (this.stop.getY()- this.start.getY()));


        return length;
    }

    public Point milieu(Point p1, Point p2){
        return new Point( (p1.getX()+p2.getX())/2, (p1.getY()+p2.getY())/2);
    }
}
