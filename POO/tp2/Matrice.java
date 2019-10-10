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
            for (int j = 0; i<nbCol ;++i ) {
                coefficients[i][j] = 0;
            }
        }
    }

    

}
