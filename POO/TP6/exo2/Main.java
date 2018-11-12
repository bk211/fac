public class Main{
	public static void main(String[] args){
		Post post1 = new Post("jj");
		post1.Aime();
		//post1.affiche();

		PostMessage post2 = new PostMessage("dd","j'ai fini");
		post2.Aime();
		post2.Aime();
		//post2.affiche();
		
		PostPhoto post3 = new PostPhoto("jj","/img/p.jpg","photo de moi");
		//post3.affiche();

		FilActualites fil = new FilActualites(5); 
		fil.ajoutePost(post1);
		fil.ajoutePost(post2);
		fil.ajoutePost(post3);

		fil.affiche();
	}
}