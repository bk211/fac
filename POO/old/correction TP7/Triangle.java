public class Triangle implements Drawable , Moveable{

private Segment segment1 ;
private Segment segment2 ;
private Segment segment3 ;
private int aColor ;

Triangle( Point p1 , Point p2 , Point p3 , int aColor ){
  this.segment1 = new Segment( p1 , p2 , aColor ) ;
  this.segment2 = new Segment( p2 , p3 , aColor ) ;
  this.segment3 = new Segment( p3 , p1 , aColor ) ;
  this.aColor = aColor ;}

public void setColor( int color){
this.aColor = aColor ; }

public int getColor(){
  return aColor ;}

public void draw(){
  segment1.draw() ;
  segment2.draw() ;
  segment3.draw() ;}

public void translate( int dx , int dy ){
segment1.translate( dx , dy ) ;
segment2.translate( dx , dy ) ;
segment3.translate( dx , dy ) ;}
}
