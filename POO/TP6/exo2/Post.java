public class Post {
private String auteur ;
private int likes; // votes sur ce post
//Constructeur
public Post ( String a ){
auteur = a;
likes = 0; }
public String getAuteur (){ return auteur ; }
public int getLikes (){ return likes ; }
//Incrémente votes "j’aime" sur le post
public void Aime(){ likes++; }
public void AimePas (){
  if (likes > 0) {likes--; }
}
//Affiche les details de ce post 
public void affiche (){
System.out.println ( auteur );
if(likes > 0) {
System.out.println(" − " + likes + " aiment."); }
     } }
