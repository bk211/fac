public class Document{
	String nom;
	int numeroEnregistrement;

	Document(String n){
		nom = n;
		numeroEnregistrement = -1;
	}

	void setNumeroEnregistrement(int n){
		numeroEnregistrement = n;
	}

	void afficher(){
		System.out.println("nom:"+nom);
		System.out.println("numeroEnregistrement:"+numeroEnregistrement);
	}

	int getNumeroEnregistrement(){
		return numeroEnregistrement;
	}

	static Document accesDocument(int n){
		/* je n'ai pas compris, comment on peut retrouver un objet Document a partir d'une methode static?
		l'objet meme si elle existe a sa creation, il doit etre dans un LDE pour etre lu depuis une methode LDE.getDocument non? 
		
		*/
		return null;
	}
}