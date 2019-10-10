public class Livre{
    String title;
    String author;
    String editor;

    public Livre(String t, String a, String e){
        title = t;
        author = a;
        editor = e;
    }

    public void afficher(){
        System.out.printf("Le livre %s a pour auteur %s et editeur %s\n", title, author, editor);
    }
}
