public class Livre extends Ouvrage{
    private int nbrePages;

    public Livre(String titre, String [] lesAuteurs ,String editeur,int annee ,int nbrePages){
        super(lesAuteurs, titre, editeur, annee);
    }

    @Override
    public String toString(){
        String resultat = super.toString();
        resultat += "Il s'agit d'un livre\n";
        resultat += "Nb de pages: "+nbrePages;
        return resultat+"\n";
    }

    public boolean equals(Livre l){
        if(getTitre() == l.getTitre())
            return true;
        return false;
    };

    public void emprunte(Mediatheque m){
        m.emprunte(getCode());
    };
    public void rend(Mediatheque m){
        m.rend(getCode());
    };

}
