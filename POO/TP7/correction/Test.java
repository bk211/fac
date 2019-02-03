public class Test
{
    public static void main(String args[])
    {
        int i;
        for(i = 0; i < args.length; i++)
        {
            Formateur f;
            String s;
            f = new Formateur(args[i]);
            f.lit();
            f.imprime();
        }
    }
}
