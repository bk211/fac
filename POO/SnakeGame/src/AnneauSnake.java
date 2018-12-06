import javafx.scene.shape.Rectangle;

public class AnneauSnake {
    Point position;
    Rectangle anneau;



    AnneauSnake(Point p){
        this.position.setX(p.getX());
        this.position.setY(p.getY());
        anneau = new Rectangle();
        anneau.setX(p.getX());
        anneau.setY(p.getY());
        anneau.setWidth(10);
        anneau.setHeight(10);
        anneau.setFill(color.BLUE);
    }

    void deplacerAnneau(int dir){
        switch (dir) {
            case 1://droite
                this.position.setX(this.position.getX() + 1);break;
            case 2://bas
                this.position.setY(this.position.getY() + 1);break;
            case 3://gauche
                this.position.setX(this.position.getX() - 1);break;
            case 4://haut
                this.position.setY(this.position.getY() - 1);break;
        }
    }

    void deplacerDroite(){
        this.deplacerAnneau(1);
    }
    void deplacerBas(){
        this.deplacerAnneau(2);
    }
    void deplacerGauche(){
        this.deplacerAnneau(3);
    }
    void deplacerHaut(){
        this.deplacerAnneau(4);
    }




}

