public class BoiteComposite implements Boite
{
    Boite boites[];
    int num;
    public BoiteComposite()
    {
        boites = new Boite[10];
        num = 0;
    }

    public int largeur()
    {
        int i;
        int l;
        l = 0;
        for(i = 0; i < num; i++)
            l = l + boites[i].largeur();
        return l;
    }
    public boolean vide()
    {
        return num == 0;
    }
    private void redimensionne(int n)
    {
        Boite[] nboites;
        int i;
        nboites = new Boite[n];
        for(i = 0; i < num; i++)
        {
            nboites[i] = boites[i];
        }
        boites = nboites;
    }
    public void accumule(Boite b)
    {
        if(num >= boites.length)
            redimensionne(2 * num);
        boites[num] = b;
        num = num + 1;
    }
    public String toString()
    {
        int i;
        StringBuffer s;
        s = new StringBuffer();
        for(i = 0; i < num; i++)
            s.append(boites[i].toString());
        return s.toString();
    }
}
