class tryCatch{

	static void methode1(int p) throws Exc1, Exc2{
		System.out.println("Debut d’execution de methode1");
		if (p == 0){
			throw new Exc1 (); }
		System.out.println("Milieu d’execution de methode1"); 
		if(p ==1){
			throw new Exc2 (); }
		System.out.println("Fin d’execution de methode1"); }
	
	static void methode2(int p) throws Exc1, Exc2, Exc3{
		System.out.println("Debut d’execution de methode2");
		if (p == 2){
			throw new Exc3(); }
		System.out.println("Milieu d’execution de methode2");
		methode1(p);
		System.out.println("Fin d’execution de methode2"); }

	static void methode3(int p) throws Exc1, Exc3{
			System.out.println("Debut d’execution de methode3");
		
		try{
			methode2(p); }
		catch(Exc2 ex){
			System.out.println("Debut d’execution de methode3"); }
		System.out.println("Fin d’execution de methode3"); }
	

	public static void main(String[] args) throws Exc1, Exc3{
		System.out.println("Entrez un nombre: ");
		methode3(2);
	}}

class Exc1 extends Exception{}
class Exc2 extends Exception{}
class Exc3 extends Exception{} 