public class Main{
	public static void main(String[] args) {
		ListeDeDocuments LDE = new ListeDeDocuments(10);
		Document a, b, c;
		a = new Document("pierre");
		b = new Document("papier");
		c = new Document("ciseaux");
		a.afficher();
		b.afficher();
		c.afficher();
		LDE.ajouter(a);
		LDE.ajouter(b);
		LDE.ajouter(c);

		LDE.ajouter(a);
		LDE.ajouter(b);
		LDE.ajouter(c);
		
		LDE.ajouter(a);
		LDE.ajouter(b);
		LDE.ajouter(c);
		
		LDE.ajouter(a);//9
		LDE.ajouter(b);
		LDE.ajouter(c);

		LDE.afficher();
		
		Document d;
		d = LDE.getDocument(9);

		System.out.println("\n"+ 	d.nom);
		System.out.println(d.numeroEnregistrement);
	}
}