public class Segment{
    Point start;
    Point stop;

    Segment(Point start, Point stop){
        this.start = start;
        this.stop = stop;
    }

    Segment(int a, int b, int c, int d){
        this.start = new Point(a,b);
        this.stop = new Point(c,d);
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


    }
}
