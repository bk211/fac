public class Volaille{
	int poids;
	int numeroIdentification;
	int age;

	Volaille(int n1, int n2){
		poids = n1;
		numeroIdentification = n2;
		age = 3;//3semaines
	}

	void tuerVolaille(){
		poids = 0;
	}
	
}