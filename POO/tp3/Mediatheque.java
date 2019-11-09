public class Mediatheque{
    ///∗Le fond  documentaire  :  on accede a un ouvrage  par  son  code∗/
    private FondDocumentaire lesOuvrages;

    public Mediatheque(){
        lesOuvrages = new FondDocumentaire();
        lesDisquesEmpruntes = new Disque[0];
        lesLivresEmpruntes = new Livre[0];
    }

    public Mediatheque(FondDocumentaire fd){
        lesOuvrages = fd;
        lesDisquesEmpruntes = new Disque[0];
        lesLivresEmpruntes = new Livre[0];

    }

    ///∗∗Les  disques  et  l e s  l i v r e s  empruntes∗/
    private Disque [] lesDisquesEmpruntes ;
    private Livre [] lesLivresEmpruntes ;

    // Ecrire  constructeur  et  accesseurspublic

    public void ajouteLivre (Livre  l){
        lesOuvrages.add(l);
    };

    public void ajouteDisque  ( Disque d ){
        lesOuvrages.add(d);
    };

    public void afficheTousLesOuvrages() {
        System.out.println("La Mediatheque contient les ouvrages suivant:\n");
        System.out.println(lesOuvrages.getAllOuvrageString());
    };
    public boolean estIlEmprunte ( Ouvrage o ){
        if(o instanceof Livre){//si livre
            System.out.println("Recherche dans les Livres...");
            for(Livre l: lesLivresEmpruntes){
                if (l.equals(o)){
                    return true;
                }
            }
            return false;
        }else if(o instanceof Disque){//si disque
            System.out.println("Recherche dans les Disques...");
            for(Disque d: lesDisquesEmpruntes){
                if (d.equals(o)){
                    return true;
                }
            }
            return false;
        }
        return false;//si autre chose que livre ou disque?
    };

    public void emprunte ( String  code ){//
        Ouvrage o = lesOuvrages.get(code);
    };
    public void rend ( String  code ) {
        Ouvrage o = lesOuvrages.get(code);
    };
}
