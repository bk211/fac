public class Factoriel{
	public static void main(String[] args) {
		int arg = Integer.parseInt(args[0]);
		System.out.println(foo(arg));
	}

	public static int foo(int a){
		if(a < 0){
			return -1;
		}
		int temp = 1;
		while(a>0){
			temp *= a;
			a --;
		}
		return temp;
	}
	
}