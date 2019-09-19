import java.util.ArrayList;
class Biblio{
	Livre[] livres;
	int indice_emplacement_libre;
    
    Biblio(int n){
        livres = new Livre[n];
        indice_emplacement_libre = 0;
    }


	void saisir_livre(Livre livre,int emplacement){
		this.livres[emplacement] = livre;
	}

	String get_nom_livre(int emplacement){
		return this.livres[emplacement].getTitre();

    }

}

