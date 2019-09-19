public class PostMessage extends Post{
	String message;

	PostMessage(String a, String m){
		super(a); 
		message = m;
	}
	public void affiche (){
		super.affiche();
		System.out.println("message:"+message);
	}

}