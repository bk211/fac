public abstract class Ouvrage{
    //un compteur d ’ instances  d ’ ouvrages
    private static  int cptOuvrages = 0 ;
    private String [] lesAuteurs ;
    private String  titre ;//;
    private String  code ;///∗∗l ’ editeur  de  l ’ ouvrage
    private String  editeur ;///∗∗l ’ annee de  p u bl i ca t i o n
    private int anneePublication ;

    Ouvrage(String[] Aut, String ti, String edi, int ann){
        setAuteurs(Aut);
        setTitre(ti);
        setEditeur(edi);
        setAnneePublication(ann);
        increaseCptOuvrages();
        createCode(getCptOuvrages());
    }

    public void increaseCptOuvrages(){
        cptOuvrages++;
    }
    public int getCptOuvrages(){
        return cptOuvrages;
    }

    public String getAuteur(int indice){
        return lesAuteurs[indice];
    }

    public String[] getAuteurs(){
        return lesAuteurs;
    }

    public void setAuteurs(String [] auteurs){
        lesAuteurs = auteurs;
    }

    public String getAuteursString(){//retourne une string qui contient tous les auteurs
        String resultat = "[";
        for (String auteur : lesAuteurs) {
            resultat += auteur +", ";
        }
        return resultat +"]";

    }

    public void setTitre(String t){
        titre = t;
    }

    public String getTitre(){
        return titre;
    }


    public void createCode(int ordreCreation){
        String Code = "";
        String Aut = getAuteur(0);
        if(Aut == ""){//si auteur vide
            Aut = "?"+ ordreCreation;
        }else if (Aut.length()<3){//si sa longeur est < 3
            Aut += ordreCreation;
        }else{//sinon on prends les 3 premiers characters
            Aut = Aut.substring(0,3) + ordreCreation;
        }
        System.out.println("Affectation du code>>"+Aut);
        this.code = Aut;

    }

    public void setCode(String c){
        code = c;
    }
    public String getCode(){
        return code;
    }

    public void setEditeur(String c){
        editeur = c;
    }
    public String getEditeur(){
        return editeur;
    }

    public void setAnneePublication(int a){
        anneePublication = a;
    }
    public int getAnneePublication(){
        return anneePublication;
    }

    public String toString (){
        String resultat = "Cet ouvrage a pour auteurs: "+getAuteursString()+"\n";
        resultat += "titre: "+titre+"\n";
        resultat += "editeur: "+editeur+"\n";
        resultat += "anneePublication: "+ anneePublication+"\n";
        resultat += "code de l'ouvrage: " +getCode();
        return resultat;
    };

    public abstract void emprunte(Mediatheque m);
    public abstract void rend(Mediatheque m);
}
