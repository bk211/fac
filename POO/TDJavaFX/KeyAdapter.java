import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.scene.input.KeyEvent;


public class KeyAdapter extends Application implements EventHandler<KeyEvent> {
Rectangle r;
Group root;
public KeyAdapter() {
r = new Rectangle();
root = new Group();
r.setX(50); r.setY(50);
r.setWidth(10); r.setHeight(10);
r.setFill(Color.BLACK);
root.getChildren().add(r);
}
@Override
public void start(Stage primaryStage) throws Exception {
primaryStage.setTitle("KeyAdapter - Johnen");
Scene scene = new Scene(root,200,100);
scene.setOnKeyPressed(this);
primaryStage.setScene(scene);
primaryStage.show(); }
@Override
public void handle(KeyEvent event) {
System.out.println("Handle keypress "+event.getCode());
switch (event.getCode()) {
case UP: r.setY(r.getY()-10); break;
case DOWN: r.setY(r.getY()+10); break;
case LEFT: r.setX(r.getX()-10); break;
case RIGHT: r.setX(r.getX()+10); break;
case P: r.setY(r.getY()-10); break;
case N: r.setY(r.getY()+10); break;
case B: r.setX(r.getX()-10); break;
case F: r.setX(r.getX()+10); break;
default: break;
} }
public static void main(String[] args) { launch(args);}
}