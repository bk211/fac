public class BoiteMot implements Boite{ String mot;
public BoiteMot(String contenu){ mot = contenu;
}
public int largeur(){
return mot.length(); }
public String toString(){ return mot;
} }
