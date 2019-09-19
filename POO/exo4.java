public class exo4{

	public static void main(String[] args) {
		affiche(10);	
		somme(5);
		factoriel(5);
	}
	public static void affiche(int n){
		for (int i=0;i<=n;i++) {
			System.out.println(i);
		}
	}	

	public static void somme(int n){
		if(n < 0){
			System.out.println("n doit etre positif");	
		}
		
		int somme = 0;
		for (int i=0;i<=n;i++) {
			somme +=i;
		}
		System.out.println(somme);
	}	

	public static void factoriel(int n){
		if(n < 0){
			System.out.println("n doit etre positif");
		}
		int temp = 1;
		while(n>0){
			temp *= n--;
		}
		System.out.println(temp);
	}

}