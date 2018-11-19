public class Addition extends Operation{
    Addition(Constant x, Constant y){
        super(x,y);
        operation = "-"
    }

    void calcul(){
        resultat.v = a.v - b.v;
    }

}