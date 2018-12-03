import java.util.Scanner;
public class Menu{
    String[] tab;

    Menu(int taille)
    {
        tab = new String[taille];
        Scanner sc = new Scanner(System.in);
        for (int i=0 ; i< taille; ++i ) {
            System.out.println("Menu numero :"+i);
            tab[i] = sc.nextLine();
        }
    }


}