public class ListeDeDocuments{
	private Document[] tableau;
	int tailleTableau;
	int nombreDeDocument;

	ListeDeDocuments(int t){
		tailleTableau = 1;
		tableau = new Document[tailleTableau];
		nombreDeDocument = 0;
	}
	void ajouter(Document d){
		if (nombreDeDocument==tailleTableau){
			tableau[nombreDeDocument] = d;
			tableau[nombreDeDocument].setNumeroEnregistrement(nombreDeDocument);
			nombreDeDocument++;
		}
		else{
			extendsTableau();
			tableau[nombreDeDocument] = d;
			tableau[nombreDeDocument].setNumeroEnregistrement(nombreDeDocument);
			nombreDeDocument++;
			
		}

	}

	void extendsTableau(){
		Document[] temp = new Document[tailleTableau*2];
		tailleTableau *=2;
		int i;
		// recopie le contenue de l'ancient tableau dans un nouveau
		for (i = 0; i<nombreDeDocument;++i ) {
			temp[i] = tableau[i];
		}

		tableau = temp;//on ecrase l'ancient tableau par le tableau plus grand
	}

	Document getDocument(int n){
		if(tableau[n] != null){
			return tableau[n];
		}
		return null;
	}


	void afficher(){
		//error: toString() in ListeDeDocuments cannot override toString() in Object ???

		int i;
		for (i =0; i<nombreDeDocument;++i){
			Document temp = this.getDocument(i);
			temp.afficher();
		}

	}
}