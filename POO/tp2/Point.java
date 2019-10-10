public class Point{
    float x ;
    float y;
    Point(float x, float y){
        this.x = x;
        this.y = y;
    }

    float getX(){
        return x;
    }
    float getY(){
        return y;
    }

    void setX(float x){
        this.x = x;
    }

    void setY(float y){
        this.y = y;
    }

    public String toString(){
        return "x : "+ this.getX() +",\t"+"y : "+this.getY();
    }

    public void translate(float x, float y){
        this.setX(x);
        this.setY(y);
    }

    public static boolean comparer(Point a, Point b){ // methode static qui compare si 2 pts sont identique
        if (a.getX() == b.getX() && a.getY() == b.getY())
            return true;
        return false;
    }
}
