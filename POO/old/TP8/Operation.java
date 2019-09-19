abstract class Operation implements ArithExpr{
    Constant a;
    Constant b;
    Constant resultat;
    char operation;
    Operation(Constant a, Constant b){
        this.a = a;
        this.b = b;
    }

    void calcul();


    Constant eval()
    {
        calcul();
        return resultat
    }

    char getOperation(){
        return operation
    }

    public String toString(){
        return a.toString()+getOperation+b.toString();
    }

    public String prefix(){
        return '('+getOperation+a.toString()+b.toString()+')';
    }
    public String suffix(){
        return '('+a.toString()+getOperation+b.toString()+')';
    }
}