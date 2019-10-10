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
        length = (float)Math.sqrt( Math.pow(this.stop.getX()- this.start.getX(), 2)
                            + Math.pow(this.stop.getY()- this.start.getY(), 2));
        return length;
    }
/*
    public float getDistanceX(){//retourne la distance abscisse absolue entre start et stop
        return Math.abs(start.getX() - stop.getX());
    }

    public float getDistanceY(){//retourne la distance ordonnee absolue entre start et stop
        return Math.abs(start.getY() - stop.getY());
    }
*/
    public Point milieu(){
        return new Point( (start.getX()+stop.getX())/2 , (start.getY()+stop.getY())/2);
    }

    public Point projection (Point p){
        float x = p.getX() + (stop.getX() - start.getX());
        float y = p.getY() + (stop.getY() - start.getY());
        return new Point(x,y);
    }
}
