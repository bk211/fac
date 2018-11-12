public class PostPhoto extends Post{
	String nomFichier;
	String legende;
	PostPhoto(String a, String n, String l){
		super(a); 
		nomFichier = n;
		legende = l;
	}
	public void affiche(){
		super.affiche();
		System.out.println("nom du Fichier:"+nomFichier);
		System.out.println("legende:"+legende);
	}
}