public class FondDocumentaire{
    private Ouvrage [] ouvr =new Ouvrage [0];

    public void add(Ouvrage o){
        int s= ouvr.length;
        Ouvrage [] tmp =new Ouvrage[s+1];
        for (int i=0; i<s ;i++ ) {
            tmp[i] = ouvr[i];
        }
        tmp[s] = o;
        ouvr = tmp;
        System.out.println("Ajout de l'ouvrage "+ o.getTitre() );
    }

    public Ouvrage get(String code){
        for (Ouvrage o : ouvr ) {
            if(o.getCode().equals(code))
                return o;
        }
        return null;
    }

    public String getAllOuvrageString(){
        String resultat = "";
        for(Ouvrage o: ouvr){
            resultat += o.toString();
        }
        return resultat;
    }
}
