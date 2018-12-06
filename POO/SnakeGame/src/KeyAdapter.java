import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.input.KeyEvent;
import javafx.stage.Stage;

import java.util.EventListener;

public class KeyAdapter extends Application implements EventHandler<KeyEvent> {
    Snake snake;
    snake = new snake();
    @Override
    public  void start(Stage primaryStage) throws Exception{

    }

    @Override
    public void handle(KeyEvent event){

    }
}
