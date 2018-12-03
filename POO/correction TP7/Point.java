public class Point implements Moveable {
private int x ;
private int y ;
public Point( int x , int y ){
this.x = x ;
this.y = y ; }
public Point( Point p ){
  this.x = p.x ;
  this.y = p.y ; }
public int getX(){
  return x ;}
public int getY(){
return y ; }
public void setX( int x ){
  this.x = x ;}
public void setY( int y ){
this.y = y ; }
public String toString(){
return( "(" + x + "," + y + ")" ) ;}
public void translate( int dx , int dy ){
x = x + dx ;
y = y + dy ; }
}
