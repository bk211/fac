public class Elevage{
	Poulets[] tabPoulets;
	int nbPoulets;
	Canards[] tabCanards;
	int nbCanards;
	int gain;

	Elevage(int taille1, int taille2){
		tabPoulets = new Poulets[taille1];
		tabCanards = new Canards[taille2];
		nbPoulets = 0;
		nbCanards =0;
		gain = 0;
	}

	void ajouterPoulet(Poulets p){//ajoute un seul poulet
		tabPoulets[nbPoulets++] = p;
	}

	void ajouterPoulets(Poulets[] tabP){//ajoute un tableau de poulets 
		for(Poulets p: tabP){
			ajouterPoulet(p);
		}
	}

	void ajouterCanard(Canards d){
		tabCanards[nbCanards++] = d; 
	}

	void afficheGain(){
		System.out.println("gain actuel:"+gain);
	}

	void abattrePoulets(){
		int i;
		for(i = 0; i < nbPoulets; ++i){
			if(tabPoulets[i].poids >= tabPoulets[i].poidsAbattage){ //poulet pret a abbatre
				gain += tabPoulets[i].prixKilo * tabPoulets[i].poids;
				tabPoulets[i].tuerPoulet();
			}
		}

		afficheGain();
	}

	void Canards(){
		int i;
		for(i = 0; i < nbCanards; ++i){
			if(tabCanards[i].poids >= tabCanards[i].poidsAbattage){ //poulet pret a abbatre
				gain += tabCanards[i].prixKilo * tabCanards[i].poids;
				tabCanards[i].tuerCanards();
			}
		}

		afficheGain();
	}

}

