public class Graphique{
	Figure[] tab;
	int indice;

	Graphique(int i){
		tab = new Figure[20];
		indice = 0;
	}

	void addFigure(Figure elem){
		tab[indice] = elem;
		++indice;
	}

	static void afficherTableau(Graphique grap){
		int i;
		for (i=0; i< grap.indice; ++i){
			System.out.println("Figure "+(i+1));
			grap.tab[i].affiche();
		}
	}
}