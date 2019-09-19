
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.Group;
import javafx.scene.shape.Rectangle;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class Main extends Application {
   @Override
public void start(Stage stage) {
Group root = new Group();
Scene scene = new Scene(root, 500, 500, Color.BLACK);
Rectangle r = new Rectangle(25,25,250,250);
Rectangle c = new Rectangle(0,25,250,250);
r.setFill(Color.BLUE);
c.setFill(Color.RED);
root.getChildren().add(r);
root.getChildren().add(c);
stage.setTitle("JavaFX Scene Graph Demo");
stage.setScene(scene);
stage.show();
}
   public static void main(String[] args) {
       launch(args);
   }
}
