public class Disque extends Ouvrage{
    private String [] morceaux;
    private int nbrePages;

    public Disque(String titre, String [] lesAuteurs ,String editeur,int annee, String[] morceaux){
        super(lesAuteurs, titre, editeur, annee);
        this.morceaux = morceaux;
    }

    public String getMorceauxString(){//retourne une string qui contient tous les morceaux
        String resultat = "[";
        for (String morceau : morceaux) {
            resultat += morceau +", ";
        }
        return resultat +"]";

    }


    @Override
    public String toString(){
        String resultat = super.toString();
        resultat += "Il s'agit d'un disque\n";
        resultat += "morceaux: "+getMorceauxString();
        return resultat;
    }

    public void emprunte(Mediatheque m){
        m.emprunte(getCode());
    };
    public void rend(Mediatheque m){
        m.rend(getCode());
    };

}
