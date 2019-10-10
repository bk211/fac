public class Main{

    public static void main(String[] args) {
        Livre myBook = new Livre("JJJ", "KKK", "EEE");
        Livre Book2 = new Livre("ab", "cd", "ef");

        myBook.afficher();
        Bibliotheque myBibli = new Bibliotheque(2);
        myBibli.addBook(myBook);
        myBibli.addBook(Book2);
        myBibli.addBook(Book2);
        myBibli.afficherContenue();
    }

}
