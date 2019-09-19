
public class Segment implements Drawable, Moveable
{
    private Point beginning ;
    private Point ending ;
    private int aColor ;
    Segment( Point beginning, Point ending, int aColor)
    {
        this.beginning = new Point( beginning ) ;
        this.ending = new Point( ending ) ;
        this.aColor = aColor ;
    }
    public int getColor()
    {
        return aColor ;
    }
    public void setColor(int aColor)
    {
        this.aColor = aColor ;
    }
    public void translate ( int dx, int dy )
    {
        beginning.translate ( dx, dy ) ;
        ending.translate ( dx, dy ) ;
    }
    public void draw()
    {
        System.out.println( aColor + " debut = " + beginning + " fin = " + ending ) ;
    }
}
