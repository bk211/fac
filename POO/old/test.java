import java.util.Scanner;
public class test{
	public static void main(String[] args) {
	int a = 13;
	System.out.println("Enter a number: ");

	Scanner reader = new Scanner(System.in); 
	
	int n = reader.nextInt(); 
	
	reader.close();
	System.out.println("a="+a);
	System.out.println("n="+n);
	System.out.println("a+n="+(a+n));
	
	}

}