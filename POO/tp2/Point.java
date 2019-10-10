public class Point{
    int x ;
    int y;
    Point(int x, int y){
        this.x = x;
        this.y = y;
    }

    int getX(){
        return x;
    }
    int getY(){
        return y;
    }

    void setX(int x){
        this.x = x;
    }

    void setY(int y){
        this.y = y;
    }

    public String toString(){
        return "x : "+ this.getX() +",\t"+"y : "+this.getY();
    }

    public void translate(int x, int y){
        this.setX(x);
        this.setY(y);
    }

    public static comparer(Point a, Point b){ // methode static qui compare si 2 pts sont identique
        if (a.getX() == b.getX() && a.getY() == b.getY())
            return true;
        return false;
    }
}
