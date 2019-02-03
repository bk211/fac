public class Graphique
{
    public static void drawGraph( Drawable[] graph )
    {
        for( int i = 0 ; i < graph.length ; i++ )
        {
            ( graph[i] ).draw() ;
        }
    }

    public static void main(String[] argv )
    {
        Point p1 = new Point(0, 0) ;
        Point p2 = new Point(0, 2) ;
        Point p3 = new Point(1, 1) ;
        Point p4 = new Point(3, 3) ;
        Triangle t = new Triangle(p1, p2, p3, 0) ;
        Segment s = new Segment(p3, p4, 1) ;
        Drawable [] graph = { t, s } ;
        drawGraph(graph) ;
    }
}
