import java.util.LinkedList;

public class Snake {
    int longeur;
    LinkedList<AnneauSnake> snake;
    int direction;
    Snake(){
        Point p = new Point(0,0);
        AnneauSnake anneau = new AnneauSnake(p);
        snake = new LinkedList<>();
        longeur = 1;
        direction = 1;
    }
}
