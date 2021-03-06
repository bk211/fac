public class Segment{
    Point start;
    Point stop;
    int length;

    Segment(Point start, Point stop){
        this.start = start;
        this.stop = stop;
        length = (this.stop.getX()- this.start.getX()) *(this.stop.getX()- this.start.getX())
                +(this.stop.getY()- this.start.getY()) *(this.stop.getY()- this.start.getY())

    }

    Segment(int a, int b, int c, int d){
        this.start = new Point(a,b);
        this.stop = new Point(c,d);
        length = (this.stop.getX()- this.start.getX()) *(this.stop.getX()- this.start.getX())
                +(this.stop.getY()- this.start.getY()) *(this.stop.getY()- this.start.getY())

    }

    Point getStart(){
        return start;

    }
    Point getStop(){
        return stop;
    }

    void setStart(Point start){
        this.start = start;
    }

    void setStop(Point stop){
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
            || Point.comparer(t1.getStop(), t2.getStart())
                return true;
        return false;
    }

    public int getLength(){
        return length;
    }
}
