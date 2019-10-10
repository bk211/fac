public class Bibliotheque{
    Livre[] Etagere;
    int nbLivre;
    int size;
    public Bibliotheque(int s){
        nbLivre = 0;
        Etagere = new Livre[s];
        size = s;
    }

    public boolean addBook(Livre l){
        if(nbLivre < size){
            Etagere[nbLivre++] = l;
            return true;
        }
        System.out.println("Echec ajout, emplacement maximum atteint");
        return false;

    }

    public void afficherContenue(){
        for (Livre l : Etagere ) {
            l.afficher();
        }

    }
}
