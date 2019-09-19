public class FilActualites {
// Completer avec variables necessaires
	Post[] tab;
	int dernier;
	/**Construit un fil vide */
	public FilActualites (int taille) { 
		tab = new Post[taille];
		dernier = 0;
	}	

	/** Ajoute une publication au fil . */
	public void ajoutePost(Post p) {
		tab[dernier++] = p;
	}


	/** Affiche tous les posts , leur auteur + nb de votes */
	public void affiche () {
		for (Post elem : tab){
			elem.affiche();
		} 
	}

	/** Affiche le nombre de posts publiés par l’auteur de nom a */
	public int nombrePostAuteur(String a) { 
		int resultat = 0;
		for (Post elem :tab){
			if(elem.getAuteur() == a){
				resultat++;
			}
		}
		return resultat;
	}

	/** Totalité des votes pour les publications dans ce fil */
	public int popularite () { 
		int resultat = 0;
		for (Post elem :tab){
			resultat += elem.getLikes();
		}
		return resultat;
	}	 
}
