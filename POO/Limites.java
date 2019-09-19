public class Limites{
	public static void main(String[] args) {
		int i1 = 1000000000;	
		int i2 = 2*i1;
		int i3 = 3*i1;
		int i4 = Integer.MAX_VALUE;
		System.out.println("i1 : " +i1);
		System.out.println("i2 : " +i2);
		System.out.println("i3 : " +i3);
		System.out.println("i4 : " +i4);

	}
}
/*
1. Oui, il compile et s'execute
2.
➜  Desktop javac Limites.java
➜  Desktop java Limites      
i1 : 1000000000
i2 : 2000000000
i3 : -1294967296
i4 : 2147483647 

i1 normal,pas d'anomalie
i2 normal aussi
i3 negatif car il depasse la limite possible d'un [int]qui vaut i4

*/

