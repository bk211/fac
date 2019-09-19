
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

public class Beeper extends Application implements EventHandler<ActionEvent> {
StackPane root ;
public Beeper() { root = new StackPane(); }
@Override
public void start(Stage primaryStage) {
primaryStage.setTitle("Beeper - Johnen");
Scene scene = new Scene(root,200,100);
primaryStage.setScene(scene);
primaryStage.show(); }
@Override
public void handle(ActionEvent e) {
//Toolkit.getDefaultToolkit().beep();
System.out.println("Aie!!!"); }
@Override
public void init(){
Button btn = new Button("Ding!");
btn.setStyle("-fx-font: 42 arial; -fx-base: #b6e7c9;");
// handle the button clicked event
btn.setOnAction(this);
root.getChildren().add(btn);
}
public static void main(String[] args) {launch(args);}
}


