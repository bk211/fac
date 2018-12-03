public class Formateur_
{
    private Parseur parseur;
    private Boite[] boites;
    private int num;
    private BoiteComposite boite;
    public Formateur(String filename)
    {
        parseur = new Parseur(filename);
        num = 0;
        boites = new Boite[10];
        boite = new BoiteComposite();
    }
    public void lit()
    {
        String s;
        do
        {
            s = parseur.suivant();
            if(s == null || s.equals(""))
            {
                nouveauParagraphe();
                if(s == null)
                    break;
            }
            else
            {
                BoiteMot m;
                m = new BoiteMot(s);

                if(!boite.vide())
                    boite.accumule(new BoiteEspace());
                boite.accumule(m);
            }
        }
        while(s != null);
    }
    public void imprime()
    {
        for(int i = 0; i < num; i++)
        {
            System.out.println(boites[i]) ;
        }
    }
    private void nouveauParagraphe()
    {
        if(!boite.vide())
        {
            accumule(boite);
            boite = new BoiteComposite();
        }
    }
    private void redimensionne(int n)
    {
        Boite[] nboites;
        int i;
        nboites = new BoiteComposite[n];
        for(i = 0; i < num; i++)
        {
            nboites[i] = boites[i];
        }
        boites = nboites;
    }
    private void accumule(Boite b)
    {
        if(num >= boites.length)
            redimensionne(2 * num);
        boites[num] = b;
        num = num + 1;
    }
}
