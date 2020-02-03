import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.Group;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.control.*;
import javafx.geometry.Insets;
import javafx.stage.Stage;
import javafx.scene.shape.Circle;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.scene.Group;
import javafx.scene.control.*;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;

public class Souris extends Application {

  private ComboBox <String> cbColor = new ComboBox <String> ();
  private ComboBox <String> cbShape = new ComboBox <String> ();
  private ComboBox <String> cbSize = new ComboBox <String> ();
  private Color pinceau=Color.GREEN;
  private Button savePicture = new Button("Save image");
  

  public static void main (String[] args){
    launch (args);
  }

  @Override 
  public void start (Stage primaryStage){ 
    primaryStage.setTitle("Hello World!");
    cbColor.getItems().addAll("vert", "bleu","rouge", "jaune", "noir");
    cbColor.setValue("vert");
    cbShape.getItems().addAll("rond", "carre", "étoile", "triangle-bas", "triangle-haut");
    cbShape.setValue("rond");
    cbSize.getItems().addAll("10","20","30", "40", "50","60","70","80","90");
    cbSize.setValue("30");

    // taille du canvas
    int canvasHeight = 400;
    int canvasWidth = 500;

    Canvas canvas = new Canvas(canvasWidth, canvasHeight);
    GraphicsContext gc = canvas.getGraphicsContext2D();
    gc.setFill(Color.GREEN);
    gc.strokeRect(0, 0, canvasWidth, canvasHeight);//dessine le contour de canvas
    
    Image backgroundImage = new Image("/capture.png",canvasWidth, canvasHeight, true, false);
    gc.drawImage(backgroundImage, 0, 0, canvasWidth, canvasHeight);

    canvas.addEventHandler(MouseEvent.MOUSE_PRESSED, 
        new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent e) {   
              int currentSize = Integer.parseInt(cbSize.getValue());
              Color c;
              if (cbColor.getValue () == "vert"){
                gc.setFill(Color.GREEN);
              }
              else if(cbColor.getValue () == "bleu"){
                gc.setFill(Color.BLUE);
              }
              else if(cbColor.getValue () == "rouge"){
                gc.setFill(Color.RED);
              }
              else if(cbColor.getValue () == "jaune"){
                gc.setFill(Color.YELLOW);
              }
              else if(cbColor.getValue () == "noir"){
                gc.setFill(Color.BLACK);
              }

              if(cbShape.getValue() == "rond" ){
                gc.fillOval(e.getX(), e.getY(), currentSize, currentSize);               
              }
              else if(cbShape.getValue() == "carre" ){
                gc.fillRect(e.getX(), e.getY(), currentSize, currentSize);

              }else if(cbShape.getValue() == "étoile"){
                double beginX = e.getX();
                double beginY = e.getY();
                double [] xPoints = { beginX, beginX+ currentSize, beginX + currentSize/5, beginX + currentSize/5 * 3, beginX + currentSize/5 *4 };
                double [] yPoints = { beginY, beginY , beginY + currentSize, beginY - currentSize/5 * 3, beginY + currentSize};
                gc.strokePolygon(xPoints, yPoints, xPoints.length);
              }else if(cbShape.getValue() == "triangle-bas"){
                double beginX = e.getX();
                double beginY = e.getY();
                double [] xPoints = { beginX, beginX+ currentSize, beginX + currentSize/2};
                double [] yPoints = { beginY, beginY , beginY + currentSize};
                gc.fillPolygon(xPoints, yPoints, xPoints.length);
              }else if(cbShape.getValue() == "triangle-haut"){
                double beginX = e.getX();
                double beginY = e.getY();
                double [] xPoints = { beginX, beginX+ currentSize, beginX + currentSize/2};
                double [] yPoints = { beginY, beginY , beginY - currentSize};
                gc.fillPolygon(xPoints, yPoints, xPoints.length);
              }

              }

            
        });
   
    savePicture.setOnAction(new EventHandler<ActionEvent>(){
          @Override
          public void handle(ActionEvent event){
            System.out.println("this is just an placebo button");
          }
      });
    Group root = new Group();
    BorderPane borderPane = new BorderPane();        
    HBox choiceBar = new HBox();
    choiceBar.getChildren().addAll(cbColor,cbShape, cbSize, savePicture);
    
    borderPane.setTop(choiceBar);

    Pane pane = new Pane();
    pane.getChildren().add(canvas);
    borderPane.setCenter(pane);    
    root.getChildren().add(borderPane);
    
    primaryStage.setScene(new Scene(root, 501, 400));
    primaryStage.show();
  }
}

