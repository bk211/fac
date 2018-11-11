public class Plat{
    String intitule;
    int prix;
    int categorie;// entree0 plat1 dessert 2

    Plat(String i, int p, int c){
        intitule = i;
        prix = p;
        categorie = c;
    }

    void affiche(){
        System.out.println("Intitule:"+intitule);
        System.out.println("Prix:"+prix);
        System.out.println("Categorie:"+categorie);
    }

    int getPrix(){
        return prix;
    }

    int getCategorie(){
        return categorie;
    }

}
