public class Main{

    public static void main(String[] args) {

        String[] auteurs = {"foo", "bar"};
        Livre liv = new Livre("supahotfire",auteurs, "editor",2000, 244);
        String[] aut = {"", "bar"};

        Livre liv2 = new Livre("sup2",aut, "editor",2000, 244);
        System.out.println(liv);
        System.out.println(liv2);

        String[] aut2 = {"Cr","jd","RRR"};
        String[] morceaux = {"f", "b"};
        Disque D = new Disque("DDD", aut2, "edit2",2001, morceaux);
        System.out.println(D);

        System.out.println("=================\n");


        FondDocumentaire f = new FondDocumentaire();
        f.add(liv);
        f.add(D);

        System.out.println("get>>"+f.get("foo1").getTitre());
        System.out.println("get>>"+f.get(""));

        Mediatheque m = new Mediatheque();
        Mediatheque m2 = new Mediatheque(f);
        m2.afficheTousLesOuvrages();

        System.out.println("=================\n");
        m.ajouteLivre(liv);
        m.ajouteDisque(D);

        System.out.println(liv.equals(liv));
        System.out.println(liv.equals(liv2));
        System.out.println(m.estIlEmprunte(liv));
    }
}
