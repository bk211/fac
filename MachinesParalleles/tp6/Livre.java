public class Livre extends Ouvrage{
    private int nbrePages;

    Livre(String titre, String [] lesAuteurs ,String editeur,int annee ,int nbrePages){
        //int cptOuvrages ;//TODO
        this.lesAuteurs = lesAuteurs;
        this.titre = titre;
        this.editeur =editeur;
        //this.code = code ;
        this.anneePublication = annee;
        this.nbrePages = nbrePages;
    }
    public String toString(){
        return "TODO";
    };
    public void emprunte(Mediatheque m){
        
    };
    public void emprunte(Mediatheque m){

    };

}
