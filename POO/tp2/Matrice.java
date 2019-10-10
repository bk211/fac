import java.util.Scanner;

public class Matrice{
    private int nbLignes;
    private int nbCol;
    private int [][] coefficients;

    public Matrice(){}
    public Matrice (int nbL, int nbC){
        nbLignes = nbL;
        nbCol = nbC;

        coefficients = new int[nbLignes][nbCol];
        for (int i =0; i<nbLignes ;++i ) {
            for (int j = 0; j<nbCol ;++j ) {
                coefficients[i][j] = 0;
            }
        }
    }

    public Matrice (int [][] coef){
        coefficients = coef;
    }

    public int getNbLignes(){
        return nbLignes;
    }

    public int getNbCol(){
        return nbCol;
    }

    public void setNbLignes(int nbL){
        nbLignes = nbL;
    }

    public void setNbCol(int nbC){
        nbCol = nbC;
    }

    public static Matrice litMatrice(){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter NbL");
        int l = scan.nextInt();
        System.out.println("Enter NbC");
        int c = scan.nextInt();
        Matrice resultat = new Matrice(l,c);

        resultat.afficheMatrice();

        for (int i =0; i<nbLignes ;++i ) {
            for (int j = 0; j<nbCol ;++j ) {
                coefficients[i][j] = 0;
            }
        }
        return resultat;

    }
    public void afficheMatrice(){
        for (int i = 0; i < nbLignes ;++i ) {
            for (int j = 0; j<nbCol ; ++j ) {
                System.out.print(coefficients[i][j]+", ");
            }
            System.out.print('\n');
        }
    }
    public int getValue(int Lig, int Col){
        return coefficients[Lig][Col];
    }
    public void setValue(int Lig, int Col, int v){
        coefficients[Lig][Col] = v;
    }

    public Matrice addition(Matrice m){
        Matrice resultat = new Matrice(nbLignes, nbCol);

        for (int i = 0; i < nbLignes ;++i ) {
            for (int j = 0; j<nbCol ; ++j ) {
                resultat.setValue(i, j, this.getValue(i,j) + m.getValue(i,j) );
            }
        }
        return resultat;
    }


    public Matrice produit(Matrice m){
        Matrice resultat = new Matrice(nbLignes, m.getNbCol());
        int lig = resultat.getNbLignes();
        int col = resultat.getNbCol();
        int sum;
        for (int i = 0; i < lig ;++i ) {
            for (int j = 0; j< col; ++j ) {
                sum = 0;
                for (int k = 0; k < m.getNbLignes() ; ++k ) {
                    //System.out.printf("Sum<%d> += <%d> <%d>\n",sum, this.getValue(i, k),m.getValue( k, j));
                    sum += this.getValue(i, k) * m.getValue( k, j);
                }
                //System.out.printf("Sum<%d>\n",sum);
                resultat.setValue(i, j, sum);
            }
        }
        return resultat;
    }

    public  Matrice transpose(){
        Matrice resultat = new Matrice(nbCol,nbLignes);
        for (int i = 0; i < nbLignes;++i ) {
            for (int j = 0; j< nbCol ; ++j ) {
                resultat.setValue(j,i, this.getValue(i,j));
            }
        }
        return resultat;
    }

}
