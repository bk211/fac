import java.util.Scanner;
import java.util.InputMismatchException;
public class Exo2{

	public static int saisirChoix(int n) throws ExcNinf1,ExcExt1N, InputMismatchException{
		Scanner sc = new Scanner(System.in);
		System.out.println("Entrez un nombre compris entre 1 et "+n);
		int input = sc.nextInt();
		System.out.println("vous avez saisi "+input);
		
	
		if (input > 1 && input < n) {return input;}

		else if (input <= 1){ throw new ExcNinf1();}

		else if (input < 1 || input >n){throw new ExcExt1N();}

		else {throw new InputMismatchException();}
	}


    public static void main(String[] args) {
        String[] tab = new String[10];
        for(int i = 0 ; i<10 ;++i){tab[i] = "menu "+i;}

        questionReponse(tab); 
        
		

	}

	public static void afficheMenu(String[] menu){
		for (String choix: menu){
			System.out.println(choix);
		}
	}

	public static int questionReponse(String[] menu){
		afficheMenu(menu);
		int tailleMenu = menu.length;
		try{	
			return saisirChoix(tailleMenu);
		}
		catch(ExcNinf1 ex){
			System.out.println("N inferieur ou egale a 1");
		}
		catch(ExcExt1N ex){
			System.out.println("N non compris entre 1 et N");
		}
		catch(InputMismatchException er){
			System.out.println("N n'est pas un nombre");
		}

		return -1;

 	}


}

class ExcNinf1 extends Exception{}
class ExcExt1N extends Exception{}
class ExcNotNb extends Exception{} 