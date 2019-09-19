public class Livre{
	private String titre;
    private String auteur;
    private String editeur;

	public Livre(String nom,String auteur,String editeur){
		this.titre = nom;
		this.auteur = auteur;
		this.editeur = editeur;
	}
    
    public String getTitre(){
        return this.titre;
    }   

    public void setTitre(String t){
    	this.titre = t;
    }
    
    public static Livre saisirLivre(){
    	System.out.println("Titre?");
    	String t = "titre";
    	System.out.println("auteur?");
    	String a = "auteur";
    	System.out.println("editeur?");
    	String e = "editeur";

    	return new Livre(t,a,e);
    }
}

