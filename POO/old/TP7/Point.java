public class Point {
    int x;
    int y;
    Point(int a, int b){
    	x = a;
    	y = b;
    }

    public void affiche()
    {
    	System.out.println("x: "+x+"\ty: "+y);
    }

    public String toString2(){
    	return "Un point de coordonnées x: "+x+"\ty: "+y;
    }


/*
    void SetX(int a)
    {
    	x = a;
    }
    void SetY(int a)
    {
    	x = a;
    }

    int getX()
    {
    	return x;
    }
    
    int getY()
    {
    	return y;
    }
    */
}

